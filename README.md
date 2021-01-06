a program that toggles an LED connected to an ESP8266 over TCP on wifi

The program contains :


TCP server written in c that acceps connections from an esp8266 and returns a responce 0 or 1 depending on the initial state

TCP Client running on an esp8266 that connects to the server over wifi at an interval of 5 seconds and actuates the LED depending on the server responce 0 = off, 1 = on


