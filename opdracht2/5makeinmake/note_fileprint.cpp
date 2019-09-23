#include "note_fileprint.hpp"
#include <fstream>

void note_fileprint::play( const note &n ) {
    std::ofstream outfile;
    if(!started) {
        outfile.open("melody.cpp");
        outfile << "#include \"melody.hpp\"\n\n";
        outfile << "class custom_melody : public melody {\n";
        outfile << "public:\n";
        outfile << "   void play( note_player & p ){\n";
        outfile.close();
        started = 1;

    } else {
        outfile.open("melody.cpp", std::ofstream::app);
        if(n.frequency >= 1) {
            outfile << "      p.play( note{ " << n.frequency << ",  " << n.duration << " } );\n";
        }
        outfile.close();
    }
};

void note_fileprint::closefile() {
    std::ofstream outfile;
    outfile.open("melody.cpp", std::ofstream::app);
    outfile << "   }\n";
    outfile << "};\n";
    outfile.close();
};