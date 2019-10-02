#include "customClock.hpp"

int main() { 
   constexpr sin_lookup sinusses;
   constexpr cos_lookup cosinusses;

   auto scl = hwlib::target::pin_oc{ hwlib::target::pins::scl };
   auto sda = hwlib::target::pin_oc{ hwlib::target::pins::sda };
   
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto oled = hwlib::glcd_oled( i2c_bus );  

   auto midpoint = hwlib::xy(64, 32);
   auto clock = customClock(30, 15, 27, midpoint, sinusses, cosinusses, due::pins::d7, due::pins::d6);

   clock.clockLoop(oled);
}