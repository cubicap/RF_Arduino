Example for controlling relays using cheap RF Arduino modules. 

For this to work, you must first install VirtualWire library. it can be downloaded from http://www.airspayce.com/mikem/arduino/VirtualWire/. To install the library you need to extract it to lib folder in both receiver and transmitter folders.

Transmitter is connected to pin 12 of one Arduino and receiver is connected to pin 11 of second Arduino. 
Buttons connected to pins 2-8 of transmitting Arduino control state of relays connected to pins 2-8 of receiving Arduino respectively.
