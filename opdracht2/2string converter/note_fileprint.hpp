#ifndef NOTE_FILEPRINT_HPP
#define NOTE_FILEPRINT_HPP

#include "note_player.hpp"

// ===========================================================================
//
// note_player alternative that creates a new cpp file that can play a given song on a speaker
//
// ===========================================================================

class note_fileprint : public note_player {
private:
    bool started = 0;
public:    
   void play( const note & n ) override;
   void closefile();
   
};

#endif
