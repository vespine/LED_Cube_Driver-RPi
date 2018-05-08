# LED_Cube_Pattern_Generator_RPi
LED_Cube_Pattern_Generator_RPi for Raspberry Pi in C++
works with LED_Cube_Simulator

This is a Raspberry Pi application for generating 8x8x8 RGB LED Cube "patterns". 
NOTE: This is not a standalone "driver" for LED cube, it is a pattern generator that can send patterns to existing, real or virtual LED cubes. 


Have you have ever wanted to play with generating LED Cube patterns in software but don't have a real cube? 
This Raspberry Pi pattern generator works with my Windows LED_Cube_simulator.

There's a little bit of setup required to get this working. 

Used this tutorial to set up netbeans to remotely build from my windows comptuer to the RPi
http://www.raspberry-projects.com/pi/programming-in-c/compilers-and-ides/netbeans-windows/installing-netbeans-for-c-remote-development-on-a-raspberry-pi

Need to set up wiringpi.h 
http://wiringpi.com/download-and-install/
This isn't critical but there are some handy things like a delay and you can wire up a real LED to an output for debugging and measuring timings, etc. Also intend to implement an input button or two at some point. 
 
The main thing this program requires is boost asio. I used this guide:
http://osdevlab.blogspot.com.au/2016/02/how-to-install-latest-boost-library-on.html

This was probably the hardest step, but it made the network communication quite simple.

The "heart" of the cube is a data array display_array[8][192] this is what gets sent to the cube / simulator. 

8 represents the horizontal "layers", 192 represents 64 red, 64 green and 64 blue "values" of each layer. Values are 0 - 100. 

Some basic "set functions" are included to get started.

My goal is to make some "fancy" math and geometry based patterns and then put the RPi into my real 8x8x8 RGB LED cube which you can see at vespine.com

