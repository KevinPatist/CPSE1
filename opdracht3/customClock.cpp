#include "customClock.hpp"

void customClock::draw( hwlib::window &w) {
    w.clear();
    clockBase.draw( w );
    w.write( hwlib::xy( (cosines.get(0)*(radius-3))+64, (sines.get(0)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(4)*(radius-3))+64, (sines.get(4)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(9)*(radius-3))+64, (sines.get(9)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(14)*(radius-3))+64, (sines.get(14)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(19)*(radius-3))+64, (sines.get(19)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(24)*(radius-3))+64, (sines.get(24)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(29)*(radius-3))+64, (sines.get(29)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(34)*(radius-3))+64, (sines.get(34)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(39)*(radius-3))+64, (sines.get(39)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(44)*(radius-3))+64, (sines.get(44)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(49)*(radius-3))+64, (sines.get(49)*(radius-3))+32 ) );
    w.write( hwlib::xy( (cosines.get(54)*(radius-3))+64, (sines.get(54)*(radius-3))+32 ) );
    hourArm.draw( w );
    minuteArm.draw( w );
    w.flush();
};

void customClock::clockLoop(hwlib::window &w) {
    uint_fast64_t previousTime = hwlib::now_us();
    for(;;) {
        hourButton.refresh();
        minuteButton.refresh();
        if(hourButton.read()){
            time += 60;
            hourArm.increase();
        };
    
        if(minuteButton.read()){
            time++;
            minuteArm.increase();
        };

        if(hwlib::now_us() >= previousTime+60000000) {
            previousTime = hwlib::now_us();
            time++;
            minuteArm.increase();
            if(time % 60 == 0) {
                hourArm.increase();
            };
        };
        customClock::draw( w );
    };
};