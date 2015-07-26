# heart-rate_keyboard_control
Fork of Pulse Sensor Amped Arduino Code, uses a heart-rate sensor from http://pulsesensor.com and an arduino to shutoff the power to a keyboard when the user's heart rate is too low. (Can be used to enforce exercise while gaming)


Steps: 

1. Solder wires to heart-rate sensor and connect ground to ground, the positive terminal to 5v on the arduino, and the data cable to Analog 0 (A0).

2. Connect an led and resistor between digital port 13 and gnd to see live heartbeat and debug. 

3. Acquire a usb extention cable, cut the sheath open and cut the red +5v power wire. Connect the outgoing half of the split wire (on the side of the female usb head) to digital port 7 on the arduino. The arduino will power the usb device from port 7 when the heart rate is high enough.

4. Connect a low energy drawing keyboard (one with a backlight probably wont work because the arduino can only supply 40mA at 5v, but most standard usb kayboards will work) to the female usb on the extention cable. 

5. Connect the arduino usb cable (to power the arduino) and the male usb on the extention cable to the same pc. Attach the sensor, open and upload the PulseSensorAmped_Arduino_1dot4.ino, and enjoy!


Future Updates: 

1. Support for digital display to show real-time BPM

2. An override switch

3. Further lessen the keyboard power on/off delay

4. Allow for IR/bluetooth remote control of the keyboard power from afar (applicable in a classroom with many students) with the choice to use or not use the heartbeat control
