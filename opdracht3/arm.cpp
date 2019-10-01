#include "arm.hpp"

void arm::draw( hwlib::window &w ) {
    hwlib::line(start, end).draw( w );
};

void arm::increase() {
    if(current < 60-stepsize) {
        current += stepsize;
    } else {
        current = 0;
    }
    end.x = (cosines.get(current)*length)+64;
    end.y = (sines.get(current)*length)+32;
};