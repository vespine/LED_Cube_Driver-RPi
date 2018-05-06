#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <wiringPi.h>
#include <iostream>

#include <unistd.h> 
#include <fcntl.h> 
#include <termios.h> 
#include <errno.h>
#include <sstream>

#include <thread>
#include <mutex>
#include <boost/asio.hpp>

#include "set_functions.h"


using boost::asio::ip::tcp;

auto g_lock()
{
	static std::mutex m; // a global living mutex
	return std::unique_lock<decltype(m)>(m); // RAII based lock
}


void serial_send() //pattern sending thread. . 
{

try {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));
        for (;;) {
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(display_array), ignored_error);
          delay (1) ;
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    /*
     //serial port write string wise
  
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
     */
          
}



int main(int argc, char **argv) {
int  wiringPiSetup (void) ;
   //boost::asio::io_service io_service;
    

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
               
//rain pattern for testing
{
int ihue = 0;
  while(1 == 1)
  {
      
      
      
int x,y,z;
int r,g,b;
//add h
int h;

int t;
int l=0;
int rain=0;
int drops=0;

int current=0; //current buffer

int ch;
int row;

for (t=0;t<50;t++){

//array[0]=array[0]+buffer[current];

//array[0]=array[0]+buffer[(current+1)%3];

//array[0]=array[0]+buffer[(current+2)%3];

//if (current ==0)
//{current =4;}
//current--;

rain = rand() % (120/10) +20; //between 4 and 16 raindrps

for (drops=0;drops<rain;drops++)
       {
       r = (rand() % 200/100) * 50;
       g = (rand() % 200/100) * 50;
       b = (rand() % 200/100) * 50;

	   x = (rand() % 800/100);
       y = (rand() % 800/100);
       z = (rand() % 800/100);
		//set_rowRGB(7,r,g,b);
//add h
	h = (rand() % 36000)/100;

if (r==50&&g==0&&b==0)
{r=100;}
if (g==50&&b==0&&r==0)
{g=100;}
if (b==50&&g==0&&r==0)
{b=100;}

set_xhue(7,y,z,h); //copy to array

//set buffer  (x,current,z,r,g,b);//copy to buffer
       }
delay (500) ;
for(l=0;l<1;l++){
for (row=0;row<7;row++){
for (ch=0;ch<192;ch++){
	display_array[row][ch]=display_array[row+1][ch];
	}
	}



set_row(7,0);
//set_xr(7,y,z,r,g,b); //copy to array
//DelayMs(delay);
	}
	}


  }
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      

      /*
      for (int row=0;row<8;row++)
      {
          display_array[row][191]=100;
         
      }
      */
              
      
     /*
      //hue run
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
          digitalWrite (0, HIGH) ; delay (2) ;
          digitalWrite (0,  LOW) ; delay (2) ;
          
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

