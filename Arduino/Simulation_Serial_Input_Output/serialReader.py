import serial
import time
import twitter
import re

from httplib2 import Http
from urllib import urlencode
h = Http()
data = dict(rfidtag="123456", location="toronto")

def receiving(ser):
    global last_received
    regex = re.compile("[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]_")
    split = re.compile(".*\n")
    buffer = ''
    while True:
        keypress = raw_input("Enter key press: ")
        ser.write(keypress)
        time.sleep(0.1)
        read = ser.read(ser.inWaiting())
        print read;
        if regex.match(read):
            read2 = read.rstrip('\r\n')
            params = read2.split("_");
            data = dict(rfidtag=params[0], location=params[1])
            resp, content = h.request("http://localhost:3000/main", "POST", urlencode(data))

arduino = serial.Serial('COM3',9600,timeout=10)
receiving(arduino);
