# RFTransmit
Read and write through RF between two (or more) Arduino devices.
It SHOULD work with every data type and there is no checksum to see if transmitted data are consistent.
Receiver (transmitter) has to be connected on RX (TX) pin, because it uses Serial.read() and Serial.write().
Suggested baud rate: 4800 or less.

# Example
In the given example there is an LM35 temperature sensor connected to analog pin 0, the transmitter sends A0 value as double. The receiver reads the temperature (as double too, obviously) and prints it on serial monitor.