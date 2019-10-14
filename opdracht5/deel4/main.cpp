#define CATCH_CONFIG_MAIN 

#include "../../Catch2/single_include/catch2/catch.hpp"

#include "verzameling.hpp"
#include <string>

TEST_CASE( "Print de (lege)verzameling naar de terminal (chars)" ){
    verzameling<3, char> a;
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "" );     
}

TEST_CASE( "Print de verzameling naar de terminal (chars)" ){
    verzameling<3, char> a;
    a.add('a');
    a.add('b');
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "a,b" );     
}

TEST_CASE( "Add getallen; standaard toevoegen" ){
    verzameling<3, char> a;
    a.add('a');
    a.add('b');
    a.add('c');
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "a,b,c" );     
}

TEST_CASE( "Add getallen; al bestaande waarden" ){
    verzameling<3, char> a;
    a.add('a');
    a.add('b');
    a.add('a');
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "a,b" );     
}

TEST_CASE( "remove getallen; bestaande waarden" ){
    verzameling<10, char> a;
    a.add('a');
    a.add('b');
    a.add('c');
    a.remove('b');
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "a,c" );     
}

TEST_CASE( "remove getallen; niet bestaande waarden" ){
    verzameling<10, char> a;
    a.add('a');
    a.add('b');
    a.add('c');
    a.remove('d');
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "a,b,c" );     
}

TEST_CASE( "contains getallen; bestaande waarden" ){
    verzameling<10, char> a;
    a.add('a');
    a.add('b');
    a.add('c');
    bool f = a.contains('b');
    REQUIRE( f );     
}

TEST_CASE( "contains getallen; niet bestaande waarden" ){
    verzameling<10, char> a;
    a.add('a');
    a.add('b');
    a.add('c');
    bool f = a.contains('d');
    REQUIRE( !f );     
}

TEST_CASE( "max test; ints" ){
    verzameling<10, int> a;
    a.add(4);
    a.add(8);
    a.add(2);
    int f = a.max();
    REQUIRE( f == 8 );     
}

TEST_CASE( "max test; chars" ){
    verzameling<10, char> a;
    a.add('a');
    a.add('c');
    a.add('b');
    char f = a.max();
    std::stringstream s;
    s << f;
    REQUIRE( s.str() == "c" ); 
}

//==========================================================================

TEST_CASE( "Print de (lege)verzameling naar de terminal (std::array)" ){
    verzameling<3, std::array<char, 3>> a;
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "" );     
}

TEST_CASE( "Print de verzameling naar de terminal (std::array)" ){
    verzameling<3, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "hoi,bye" );     
}

TEST_CASE( "Add arrays; standaard toevoegen" ){
    verzameling<3, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'i', 'd', 'k'});
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "hoi,bye,idk" );     
}

TEST_CASE( "Add arrays; al bestaande waarden" ){
    verzameling<3, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'h', 'o', 'i'});
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "hoi,bye" );     
}

TEST_CASE( "remove arrays; bestaande waarden" ){
    verzameling<10, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'i', 'd', 'k'});
    a.remove({'b', 'y', 'e'});
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "hoi,idk" );     
}

TEST_CASE( "remove arrays; niet bestaande waarden" ){
    verzameling<10, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'i', 'd', 'k'});
    a.remove({'d', 'o', 'm'});
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "hoi,bye,idk" );     
}

TEST_CASE( "contains arrays; bestaande waarden" ){
    verzameling<10, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'i', 'd', 'k'});
    bool f = a.contains({'b','y','e'});
    REQUIRE( f );     
}

TEST_CASE( "contains arrays; niet bestaande waarden" ){
    verzameling<10, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'i', 'd', 'k'});
    bool f = a.contains({'d','o','m'});
    REQUIRE( !f );     
}

TEST_CASE( "max test; arrays" ){
    verzameling<10, std::array<char, 3>> a;
    a.add({'h', 'o', 'i'});
    a.add({'b', 'y', 'e'});
    a.add({'i', 'd', 'k'});
    std::array<char,3> f = a.max();
    std::stringstream s;
    s << f;
    REQUIRE( s.str() == "idk" );     
}


