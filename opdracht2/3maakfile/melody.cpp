#include "melody.hpp"

class custom_melody : public melody {
public:
   void play( note_player & p ){
      p.play( note{ 1046,  178571 } );
      p.play( note{ 987,  89285 } );
      p.play( note{ 1046,  89285 } );
      p.play( note{ 987,  89285 } );
      p.play( note{ 1046,  89285 } );
      p.play( note{ 987,  178571 } );
      p.play( note{ 1046,  178571 } );
      p.play( note{ 830,  357142 } );
      p.play( note{ 698,  357142 } );
      p.play( note{ 698,  178571 } );
      p.play( note{ 830,  178571 } );
      p.play( note{ 1046,  178571 } );
      p.play( note{ 1108,  357142 } );
      p.play( note{ 830,  357142 } );
      p.play( note{ 1108,  357142 } );
      p.play( note{ 1244,  357142 } );
      p.play( note{ 1046,  178571 } );
      p.play( note{ 1108,  178571 } );
      p.play( note{ 1046,  178571 } );
      p.play( note{ 1108,  178571 } );
      p.play( note{ 1046,  714285 } );
   }
};
