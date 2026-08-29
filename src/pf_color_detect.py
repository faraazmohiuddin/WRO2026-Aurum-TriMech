import cv2
import numpy as np
import time
import sys  # Native system module for raw terminal stream control
from picamera2 import Picamera2

def main():
    print("Initializing Camera via Native Picamera2 Backend...")
    picam = Picamera2()
    
    # Configure lightweight resolution for lightning-fast tracking loops
    camera_config = picam.create_preview_configuration(main={"size": (640, 480)})
    picam.configure(camera_config)
    picam.start()
    
    time.sleep(0.5)
    print("\n" + "="*50)
    print("SINGLE-TARGET SERIAL OUTPUT STREAM ACTIVE")
    print("Data format -> COLOR,X_COORD,Y_COORD")
    print("Press 'q' inside the video window to quit safely.")
    print("="*50 + "\n")

    # Tracking registry containing color configurations
    color_targets = {
        "Red": {
            "lower": np.array([0, 120, 70]), "upper": np.array([10, 255, 255]),
            "box_color": (0, 0, 255)
        },
        "Blue": {
            "lower": np.array([90, 50, 50]), "upper": np.array([130, 255, 255]),
            "box_color": (255, 0, 0)
        },
        "Green": {
            "lower": np.array([35, 40, 40]), "upper": np.array([85, 255, 255]),
            "box_color": (0, 255, 0)
        },
        "Magenta": {
            "lower": np.array([140, 40, 40]), "upper": np.array([170, 255, 255]),
            "box_color": (255, 0, 255)
        }
    }

    try:
        while True:
            # Grab raw frame data natively from the Pi Camera
            frame_raw = picam.capture_array()
            
            # Map raw array cleanly to standard OpenCV BGR structure 
            frame = cv2.cvtColor(frame_raw, cv2.COLOR_RGBA2BGR)
            
            # Convert the frame to HSV color space for stable color scanning
            hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            
            # Temporary storage to find the single largest target across ALL colors
            best_contour = None
            best_contour_area = 0
            target_name = None
            target_config = None

            for name, config in color_targets.items():
                # Isolate matching pixels for the current color iteration
                mask = cv2.inRange(hsv_frame, config["lower"], config["upper"])
                
                # Clean up noise from the isolated mask
                kernel = np.ones((5, 5), np.uint8)
                mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
                mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
                
                # Extract boundary contours of current color
                contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
                
                if contours:
                    # Find the largest blob for THIS specific color
                    largest_color_contour = max(contours, key=cv2.contourArea)
                    area = cv2.contourArea(largest_color_contour)
                    
                    # NEW SINGLE-TARGET FILTER: Is this blob bigger than any other color we found so far?
                    if area > best_contour_area:
                        best_contour_area = area
                        best_contour = largest_color_contour
                        target_name = name
                        target_config = config

            # Process and draw ONLY if the absolute largest object passes our noise threshold
            if best_contour is not None and best_contour_area > 600:
                x, y, w, h = cv2.boundingRect(best_contour)
                cx, cy = x + (w // 2), y + (h // 2)
                
                # Draw bounding box indicator and crosshair using the winning color profile
                cv2.rectangle(frame, (x, y), (x + w, y + h), target_config["box_color"], 2)
                cv2.circle(frame, (cx, cy), 4, (0, 255, 255), -1)
                
                # Superimpose target tracking tags directly above box
                cv2.putText(frame, f"{target_name}: [{cx}, {cy}]", (x, y - 10), 
                            cv2.FONT_HERSHEY_SIMPLEX, 0.4, target_config["box_color"], 1)

                # STREAM THE SINGLE WINNING OBJECT DATA TO SERIAL MONITOR
                sys.stdout.write(f"{target_name},{cx},{cy}\n")
                sys.stdout.flush() 

            # Display the consolidated tracking feed mapping the single winning overlay
            cv2.imshow("Original Feed", frame)
            
            # Break loop when 'q' key is pressed inside the tracking window
            if cv2.waitKey(1) & 0xFF == ord('q'):
                print("\nQuitting tracker program...")
                break
                
    finally:
        print("Stopping camera sensor...")
        picam.stop()
        cv2.destroyAllWindows()
        print("Assets released cleanly.")

if __name__ == "__main__":
    main()
