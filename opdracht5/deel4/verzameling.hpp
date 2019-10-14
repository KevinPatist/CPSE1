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

    T max(){
        if(filled == 1){
            return set[0];
        } else {
            T maximum = set[0];
            for(int check = 1; check<filled; check++){
                if(set[check] > maximum) {
                    maximum = set[check];
                }
            }
            return maximum;
        }
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

template<int N>
bool operator>(std::array<char, N> &lhs, std::array<char, N> &rhs){
    char left = 0;
    char right = 0;
    for( char i : lhs ){
        left += i;
    }
    for( char i : rhs ){
        right += i;
    }
    return left > right;
}

//template<int N>
std::ostream & operator<<( std::ostream &lhs, const std::array<char, 3> &rhs){
    for(int pos = 0; pos<3; pos++){
        lhs << rhs[pos];
    }
    return lhs;
}
#endif //VERZAMELING_HPP