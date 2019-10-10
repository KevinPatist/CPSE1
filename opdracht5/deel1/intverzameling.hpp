#ifndef VERZAMELING_HPP
#define VERZAMELING_HPP

#include <iostream>

class intverzameling {
protected:
    std::array< int, 10 > set;
    int size = 10;
    int filled = 0;

public:
    intverzameling( int size ):
        size( size )
    {
        set[0] = 0;  // setting the first item to 0 to init
    }

    void add( int item ){
        for(int check = 0; check < filled; check++) {
            if(set[check] == item){
                return;
            }
        }
        if(filled < size){
            set[filled] = item;
            filled++;
        }
    }

    void remove( int item ){
        for(int check = 0; check < filled; check++) {
            if(set[check] == item){
                for(int change = check; change<filled; change++) {
                    if(change<size-1){
                        set[change] = set[change+1];
                    }
                    filled--;
                }
            }
        }
    }

    bool contains( int item ){
        for(int check = 0; check < filled; check++) {
            if(set[check] == item){
                return true;
            }
        }
        return false;
    }

    friend std::ostream & operator<<( std::ostream & lhs, const intverzameling & rhs ){
        for(int pos = 0; pos<rhs.filled-1; pos++){
            lhs << rhs.set[pos];
            lhs << ",";
        }
        if(rhs.filled > 0){
            lhs << rhs.set[rhs.filled-1];
        }
        return lhs;
    } 
};

#endif //VERZAMELING_HPP