#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
};

extern "C" void application();

int main() {
   hwlib::wait_ms(200);
   application();
}

//eerst een buffer
// .skip 40 in bss
// dan dingen erin pleuren
// dan als derde ding in buffer @ is gaan veranderen
// dan dus de @ en de 2 dingen ervoor veranderen in de buffer