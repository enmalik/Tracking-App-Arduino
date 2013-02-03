import serial
import time
import twitter

from httplib2 import Http
from urllib import urlencode
h = Http()
data = dict(rfidtag="123456", location="toronto")

def receiving(ser):
    global last_received

    buffer = ''
    while True:
        keypress = raw_input("Enter key press: ")
        ser.write(keypress)
        time.sleep(0.1)
        read = ser.read(ser.inWaiting())
        print read;
        if "Legit" in read:
            resp, content = h.request("http://tracking-3b.herokuapp.com/main", "POST", urlencode(data))

arduino = serial.Serial('COM3',9600,timeout=10)
receiving(arduino);