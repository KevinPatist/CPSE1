#ifndef ARM_HPP
#define ARM_HPP

#include "hwlib.hpp"
#include "lookup.hpp"

class arm : public hwlib::drawable {
private:
    const sin_lookup & sines;
    const cos_lookup & cosines;
    int length = 30;
    int stepsize = 1;
    int current = 0;
    hwlib::xy end;

public:
    arm( int length, int stepsize, hwlib::xy start, const sin_lookup &sines, const cos_lookup &cosines):
        drawable( start ),
        sines( sines ),
        cosines( cosines ),
        length( length ),
        stepsize( stepsize ),
        end( static_cast<int>((cosines.get(current)*length)+64), static_cast<int>((sines.get(current)*length)+32) )
    {};

    void draw( hwlib::window &w ) override;
    void increase();
};

#endif //ARM_HPP