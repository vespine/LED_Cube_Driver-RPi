#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <wiringPi.h>
#include <iostream>

#include <unistd.h> 
#include <fcntl.h> 
#include <termios.h> 
#include <errno.h>
#include <sstream>gt h

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
}



int main(int argc, char **argv)
{
int  wiringPiSetup (void) ;
std::thread t1(serial_send); 


  while(1 == 1)
  {
//**********************//
//***patterns go here***//
//**********************//     
      
      
      
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
      



     //    digitalWrite (0, HIGH) ; delay (350) ;
     //    digitalWrite (0,  LOW) ; delay (350) ;

  }
 
 return 0;
 }

