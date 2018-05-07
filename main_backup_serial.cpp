

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#include <unistd.h> 
#include <fcntl.h> 
#include <termios.h> 
#include <errno.h>
#include <sstream>

#include <thread>
#include <mutex>
#include <boost/asio.hpp>

#include "set_functions.h"




auto g_lock()
{
	static std::mutex m; // a global living mutex
	return std::unique_lock<decltype(m)>(m); // RAII based lock
}


void serial_send() //pattern sending thread. . 
{

/*
     //testing code
     int sfd = open("/dev/serial0", O_RDWR | O_NOCTTY );
     
     
     
      while (1==1)
             {
          for (char a = 1; a<255;a++)
          {
      digitalWrite (0, HIGH) ; delay (15) ;
       
              
     serialPutchar(sfd,a);
   digitalWrite (0,  LOW) ; delay (15) ; 
          }
      }
*/
     
     //write string wise
  
     int sfd = open("/dev/serial0", O_RDWR | O_NOCTTY ); 
             while (1==1)
             {
             char i = 0;
             
              for (i=0;i<8;i++)
               {
               char hexi = 0xf0+i;
               delay (1) ;
               serialPutchar(sfd,hexi);
               for (int sendc= 0; sendc<192;sendc++)
               {
               serialPutchar(sfd,display_array[i][sendc]);
               
               }
               //write(sfd, display_array[i], 192);
               //delay (1) ;
               }
             }
           
           
             
}






int main(int argc, char **argv) {
   wiringPiSetup () ;
   boost::asio::io_service io_service;
     pinMode (0, OUTPUT) ;
     
               digitalWrite (0, HIGH) ; delay (250) ;
               digitalWrite (0,  LOW) ; delay (250) ;
               digitalWrite (0, HIGH) ; delay (250) ;
               digitalWrite (0,  LOW) ; delay (250) ;
    
            /*  
               set_all(0x64);
               for (char x=0;x<192;x++)
               {
                   
                   display_array[1][x]=x;
               }
             
             */
        /*       
         display_array[0][192]=0xf0; 
         display_array[1][192]=0xf1;  
         display_array[2][192]=0xf2;
         display_array[3][192]=0xf3;
         display_array[4][192]=0xf4;
         display_array[5][192]=0xf5;
         display_array[6][192]=0xf6;
         display_array[7][192]=0xf0;
          */         
               
               
               
               
               
               
               
               
               
std::thread t1(serial_send); 
               
int ihue = 0;
  while(1 == 1)
  {

      
      hue_run(100,10);
              
      
     /*
    
      for (int x = 0; x<8;x++)
      {  
      for (int y = 0; y <8;y++)
      {
      for (int z = 0; z <8;z++)
      {
          
          //set(roww, run, 100);
          set_xhue(x,y,z,ihue);
          ihue++;
          if (ihue==360) ihue =0;
          digitalWrite (0, HIGH) ; delay (5) ;
          digitalWrite (0,  LOW) ; delay (5) ;
          
      }
      }
      }
    
      */
      /*
      
      for (int roww = 0; roww<8;roww++)
      {
              
      for (int run = 0; run <192;run++)
      {
          
          set(roww, run, 0);
          digitalWrite (0, HIGH) ; delay (5) ;
          digitalWrite (0,  LOW) ; delay (5) ;
          
      }
      
      }
      
      */
 
      
      /*
      for (int x=0;x<100;x++){
          
                set_all(100);
              	digitalWrite (0, HIGH) ; delay (75) ;
                digitalWrite (0,  LOW) ; delay (75) ;
                set_all(0);
                digitalWrite (0, HIGH) ; delay (75) ;
                digitalWrite (0,  LOW) ; delay (75) ;
      }
      */
      
// patterns go here
      
 	/*
	for (int x = 0; x <8; x++)
	{
		set_rowhue(x, ihue);
		ihue = ihue + 10;
                if (ihue >359) ihue = 0;
		digitalWrite (0, HIGH) ; delay (150) ;
                digitalWrite (0,  LOW) ; delay (150) ;
	}
	*/
	      
         /*
         //basic fill and blank routine
                        for (int row = 0 ; row < 8; row++)
               {
                   for (int chan = 0; chan < 192; chan++)
                   {
                       display_array[row][chan]=0;
                       dum++;
                       if (dum == 100) dum = 0;
                   }
               }
         
         delay (1500) ;
         
         
         
                        for (int row = 0 ; row < 8; row++)
               {
                   for (int chan = 0; chan < 192; chan++)
                   {
                       display_array[row][chan]=dum;
                       dum++;
                       if (dum == 100) dum = 0;
                   }
               }
         
*/
     //    digitalWrite (0, HIGH) ; delay (350) ;
     //    digitalWrite (0,  LOW) ; delay (350) ;



  }
    //close(sfd);
 
 return 0;

 
 
 }

