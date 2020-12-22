# Tcp Led Toggle
a program that toggles an LED connected to an ESP8266 over TCP on wifi

The program contains :

TCP server written in c that acceps connections from an esp8266 and returns a responce 0 or 1 depending on the initial state  
TCP Client running on an esp8266 that connects to the server over wifi at an interval of 5 seconds and actuates the LED depending on the server responce 0 = off, 1 = on

 # setup
 use platformio 
 # clone
 https://github.com/kevindson/TCP-LED-Toggle.git
 # run server
 gcc server.c -o server && ./server
 ### Resources
 # ESP
    -https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi/examples/WiFiClient
    -https://arduino-esp8266.readthedocs.io/en/latest/
    -https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html
    -https://microcontrollerslab.com/led-blinking-using-esp8266-nodemcu/
    -https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
    -https://randomnerdtutorials.com/esp8266-nodemcu-digital-inputs-outputs-arduino/
#others

    -https://www.google.com/
     Version Control
    -https://mohsensy.github.io/programming/2019/09/25/echo-server-and-client-using-sockets-in-c.html
    -http://beej.us/guide/bgnet/html
    -https://www.youtube.com/watch?v=bdIiTxtMaKA
    -https://www.educative.io/edpresso/how-to-implement-tcp-sockets-in-c
    -https://ops.tips/blog/a-tcp-server-in-c/
    -https://notes.shichao.io/unp/ch5/
    -http://www.cs.cmu.edu/afs/cs/academic/class/15213-f00/www/class24code/echoserver.c
    -https://github.com/holmofy/echo-server/blob/master/tcp-echo-server.c
