import serial
import time
import twitter
import re

from httplib2 import Http
from urllib import urlencode
h = Http()

def receiving(ser):
    regex = re.compile("[0-9]{12,12}_")
    while True:
        keypress = raw_input("Enter key press: ")
        ser.write(keypress)
        time.sleep(0.1)
        read = ser.read(ser.inWaiting())
        print read;
        if regex.match(read):
            params = read.rstrip('\r\n').split("_");
            data = dict(rfidtag=params[0], location=params[1])
            resp, content = h.request("http://tracking-3b.herokuapp.com/main", "POST", urlencode(data))

arduino = serial.Serial('COM3',9600,timeout=10)
receiving(arduino);
