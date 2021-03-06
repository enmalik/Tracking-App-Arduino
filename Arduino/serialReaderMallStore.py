import serial
import time
import datetime
import re

from httplib2 import Http
from urllib import urlencode
h = Http()

def receiving(ser):
    regex = re.compile("[a-zA-Z0-9]{12,12}_")
    while True:
        time.sleep(0.1)
        read = ser.read(ser.inWaiting())
        #print read;
        if regex.match(read):
            params = read.rstrip('\r\n').split("_");
            readTime = str(datetime.datetime.now().strftime("%I:%M%p"))
            data = dict(rfidtag=params[0], location='Store', readtime=readTime)
            print params[0],params[1],readTime
            resp, content = h.request("http://tracking-3b.herokuapp.com/main", "POST", urlencode(data))

arduino = serial.Serial('COM3',9600,timeout=10)
receiving(arduino);
