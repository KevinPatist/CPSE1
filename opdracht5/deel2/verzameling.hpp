#ifndef VERZAMELING_HPP
#define VERZAMELING_HPP

#include <iostream>
template< int N, typename T > 
class verzameling {
protected:
    std::array< T, N > set;
    int filled = 0;

public:
    void add( T item ){
        for(int check = 0; check < filled; check++) {
            if(set[check] == item){
                return;
            }
        }
        if(filled < N){
            set[filled] = item;
            filled++;
        }
    }

    void remove( T item ){
        for(int check = 0; check < filled; check++) {
            if(set[check] == item){
                for(int change = check; change<N; change++) {
                    if(change<N-1){
                        set[change] = set[change+1];
                    }
                }
                filled--;
            }
        }
    }

    bool contains( T item ){
        for(int check = 0; check < filled; check++) {
            if(set[check] == item){
                return true;
            }
        }
        return false;
    }

    friend std::ostream & operator<<( std::ostream & lhs, const verzameling & rhs ){
        for(int pos = 0; pos<rhs.filled; pos++){
            lhs << rhs.set[pos];
            if(pos != rhs.filled-1){
                lhs << ",";
            }
        }
        return lhs;
    } 
};

#endif //VERZAMELING_HPP