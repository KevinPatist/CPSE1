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
            switch(n.frequency) {
                case 440:
                    outfile << "      p.play( note{ note::A4,  note::" << n.duration << " } );\n";
                    break;
                case 466:
                    outfile << "      p.play( note{ note::A4s,  note::" << n.duration << " } );\n";
                    break;
                case 494:
                    outfile << "      p.play( note{ note::B4,  note::" << n.duration << " } );\n";
                    break;
                case 523:
                    outfile << "      p.play( note{ note::C5,  note::" << n.duration << " } );\n";
                    break;
                case 554:
                    outfile << "      p.play( note{ note::C5s,  note::" << n.duration << " } );\n";
                    break;
                case 587:
                    outfile << "      p.play( note{ note::D5,  note::" << n.duration << " } );\n";
                    break;
                case 622:
                    outfile << "      p.play( note{ note::D5s,  note::" << n.duration << " } );\n";
                    break;
                case 659:
                    outfile << "      p.play( note{ note::E5,  note::" << n.duration << " } );\n";
                    break;
                case 698:
                    outfile << "      p.play( note{ note::F5,  note::" << n.duration << " } );\n";
                    break;
                case 740:
                    outfile << "      p.play( note{ note::F5s,  note::" << n.duration << " } );\n";
                    break;
                case 784:
                    outfile << "      p.play( note{ note::G5,  note::" << n.duration << " } );\n";
                    break;
                case 830:
                    outfile << "      p.play( note{ note::G5s,  note::" << n.duration << " } );\n";
                    break;
                case 880:
                    outfile << "      p.play( note{ note::A5,  note::" << n.duration << " } );\n";
                    break;
                case 932:
                    outfile << "      p.play( note{ note::A5s,  note::" << n.duration << " } );\n";
                    break;
                case 987:
                    outfile << "      p.play( note{ note::B5s,  note::" << n.duration << " } );\n";
                    break;
                default:
                    outfile << "      p.play( note{ note::" << n.frequency << ",  note::" << n.duration << " } );\n";
                    break;
            }
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