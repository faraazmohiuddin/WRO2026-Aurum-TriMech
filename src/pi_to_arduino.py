import serial
import time

def main():
    print("Connecting to Arduino on /dev/ttyACM0...")
    try:
        # Open the verified serial port at 9600 baud
        ser = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=1)
        
        # CRITICAL: Allow the Arduino 2 seconds to reboot and sync its connection
        time.sleep(2)
        print("Connected! Sending HELLO...")
        
        # Format the text with a newline character and encode it to raw bytes
        message = "HELLO\n"
        ser.write(message.encode('utf-8'))
        
        print("Message sent successfully.")
        
        # Keep the connection open for a second so the hardware completes transmission
        time.sleep(1)
        ser.close()
        
    except Exception as e:
        print(f"Error: Could not communicate with Arduino: {e}")

if __name__ == "__main__":
    main()
