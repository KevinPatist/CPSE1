#define CATCH_CONFIG_MAIN 

#include "../../Catch2/single_include/catch2/catch.hpp"

#include "intverzameling.hpp"

TEST_CASE( "Print de verzameling naar de terminal" ){
    intverzameling a(3);
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "" );     
}

TEST_CASE( "Add getallen; standaard toevoegen" ){
    intverzameling a(3);
    a.add(2);
    a.add(5);
    a.add(7);
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "2,5,7" );     
}

TEST_CASE( "Add getallen; al bestaande waarden" ){
    intverzameling a(3);
    a.add(2);
    a.add(5);
    a.add(2);
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "2,5" );     
}

TEST_CASE( "remove getallen; bestaande waarden" ){
    intverzameling a(10);
    a.add(2);
    a.add(5);
    a.add(7);
    a.remove(5);
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "2,7" );     
}

TEST_CASE( "remove getallen; niet bestaande waarden" ){
    intverzameling a(10);
    a.add(2);
    a.add(5);
    a.add(7);
    a.remove(3);
    std::stringstream s;
    s << a;
    REQUIRE( s.str() == "2,5,7" );     
}

TEST_CASE( "contains getallen; bestaande waarden" ){
    intverzameling a(10);
    a.add(2);
    a.add(5);
    a.add(7);
    bool f = a.contains(5);
    REQUIRE( f );     
}

TEST_CASE( "contains getallen; niet bestaande waarden" ){
    intverzameling a(10);
    a.add(2);
    a.add(5);
    a.add(7);
    bool f = a.contains(3);
    REQUIRE( !f );     
}



