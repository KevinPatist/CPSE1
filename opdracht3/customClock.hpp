#ifndef CUSTOMCLOCK_HPP
#define CUSTOMCLOCK_HPP

#include "arm.hpp"

class customClock : public hwlib::drawable {
private:
    int time = 0;
    int radius = 30;
    hwlib::circle clockBase;
    const sin_lookup & sines;
    const cos_lookup & cosines;
    due::pin_in hourButton;
    due::pin_in minuteButton;
    arm hourArm;
    arm minuteArm;

public:
    customClock( int clockradius, int arm1length, int arm2length, hwlib::xy start, const sin_lookup &sines, const cos_lookup &cosines, due::pins hourbutton, due::pins minutebutton ):
        drawable( start ),
        radius( clockradius ),
        clockBase( hwlib::circle(start, 30) ),
        sines( sines ),
        cosines( cosines ),
        hourButton( due::pin_in(hourbutton) ),
        minuteButton( due::pin_in(minutebutton) ),
        hourArm( arm( arm1length, 5, start, sines, cosines ) ),
        minuteArm( arm( arm2length, 1, start, sines, cosines ) )
    {};
    
    void clockLoop(hwlib::window &w);
    void draw( hwlib::window &w);
};

#endif // CUSTOMCLOCK_HPP