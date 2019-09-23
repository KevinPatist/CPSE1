#include "hwlib.hpp"
#include "note_player_print.hpp"

void note_player_print::play( const note & n ){
    if( n.frequency == 0 ){
        hwlib::wait_us( n.duration );
      
    } else {
        switch(n.frequency) {
            case 440:
                std::cout << "note: A4 " << std::endl;
                break;
            case 466:
                std::cout << "note: A4s" << std::endl;
                break;
            case 494:
                std::cout << "note: B4 " << std::endl;
                break;
            case 523:
                std::cout << "note: C5 " << std::endl;
                break;
            case 554:
                std::cout << "note: C5s" << std::endl;
                break;
            case 587:
                std::cout << "note: D5 " << std::endl;
                break;
            case 622:
                std::cout << "note: D5s" << std::endl;
                break;
            case 659:
                std::cout << "note: E5 " << std::endl;
                break;
            case 698:
                std::cout << "note: F5 " << std::endl;
                break;
            case 740:
                std::cout << "note: F5s" << std::endl;
                break;
            case 784:
                std::cout << "note: G5 " << std::endl;
                break;
            case 830:
                std::cout << "note: G5s" << std::endl;
                break;
            case 880:
                std::cout << "note: A5 " << std::endl;
                break;
            case 932:
                std::cout << "note: A5s" << std::endl;
                break;
            case 987:
                std::cout << "note: B5 " << std::endl;
                break;
            default:
                std::cout << "frequency: " << n.frequency << std::endl;
                break;
        }
    }     
}