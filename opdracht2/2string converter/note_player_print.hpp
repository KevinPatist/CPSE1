#ifndef _NOTE_PLAYER_PRINT_HPP
#define _NOTE_PLAYER_PRINT_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player that prints the notes to the terminal
//
// ===========================================================================

class note_player_print : public note_player {
// private:
//     note_player_print();
public:    
   void play( const note & n ) override;
};

#endif
