#ifndef LOOKUP_HPP
#define LOOKUP_HPP
#include <cmath>

class sin_lookup {
private:    
   std::array< float, 60 > values;
public: 
    constexpr sin_lookup():
        values{}
    {   
        for( double i = 360; i > 0; i-=6 ) {
            values[ (i/6)-1 ] = sin( (i*3.14)/180 );
        }
    }
    constexpr float get( int n ) const {
        return values[ n ];    
    }
};

class cos_lookup {
private:    
   std::array< float, 60 > values;
public: 
    constexpr cos_lookup():
        values{}
    {   
        for( double i = 360; i > 0; i-=6 ) {
            values[ (i/6)-1 ] = cos( (i*3.14)/180 );
        }
    }
    constexpr float get( int n ) const {
        return values[ n ];    
    }
};

#endif // LOOKUP_HPP