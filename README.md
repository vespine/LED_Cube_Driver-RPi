# LED_Cube_Driver-RPi
LED_Cube_Driver for RPi in C++ works with LED_Cube_Simulator

Used this tutorial to set up netbeans to remotely build from my windows comptuer to the RPi
http://www.raspberry-projects.com/pi/programming-in-c/compilers-and-ides/netbeans-windows/installing-netbeans-for-c-remote-development-on-a-raspberry-pi

Need to set up wiringpi.h 
http://wiringpi.com/download-and-install/
This isn't critical but there are some handy things like a delay and you can wire up a real LED to an output for debugging and measuring timings, etc. Also intend to implement an input button or two at some point. 
 
The main thing this program requires is boost asio. I used this guide:
http://osdevlab.blogspot.com.au/2016/02/how-to-install-latest-boost-library-on.html

This was probably the hardest step, but it made the network communication quite simple. 


The "heart" of the cube is a data array display_array[8][192]

8 represents the horizontal "layers", 192 represents 64 red, 64 green and 64 blue "values". My cube is configured to accept a value of 0 - 100. 

Some basic "set functions" are included to get started the user started.

My goal is to make some "fancy" math and geometry based patterns. 

