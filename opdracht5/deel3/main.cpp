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



