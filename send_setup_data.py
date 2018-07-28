#!/usr/bin/python
import serial #must install pySerial! not serial!
import time
import datetime


#The following line is for serial over GPIO
port = 'COM6'

ard = serial.Serial(port,115200,timeout=5)
print("Found arduino! Waiting for serial init/reinit...")
time.sleep(2) # wait for Arduino

# ===== Node ID =====
ardMsg = str(ard.readline()).upper()[2:7]
#print(ardMsg)
provideId = (ardMsg == "NO_ID" )

if (provideId):
    id = input("Enter node id (0 - 4096): ")
    ard.write( id.encode() )
    time.sleep(1)
print(ard.readline()) #either way, arduino will print it's id

# ===== RTC sync/setup =====
# wait until we are ~40 seconds from the next minute
while (datetime.datetime.now().second >= 20):
    print("Waiting until we have 40 seconds until the next minute...")
    time.sleep( 60 - datetime.datetime.now().second )

print ("Beginning time set!")

now = datetime.datetime.now()
print("Set year to %d" % now.year)
ard.write( str(now.year).encode() )
time.sleep(1)
print(ard.readline())

print("Set month to %d" % now.month)
ard.write( str(now.month).encode() )
time.sleep(1)
print(ard.readline())

print("Set day to %d" % now.day)
ard.write( str(now.day).encode() )
time.sleep(1)
print(ard.readline())

print("Set hour to %d" % now.hour)
ard.write( str(now.hour).encode() )
time.sleep(1)
print(ard.readline())

print("Set minute to %d" % now.minute)
ard.write( str(now.minute).encode() )
time.sleep(1)
print(ard.readline())

sec = datetime.datetime.now().second
ard.write( str(sec).encode() )
print("Set second to %d" % sec)
print(ard.readline())

print ("Arduino time signature")
print(ard.readline())
