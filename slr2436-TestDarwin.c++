// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <stdio.h>
#include <string.h>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
#include "Darwin.h"

#define protected public
#define private public
#define class struct
struct TestDarwin : CppUnit::TestFixture {


void testcreature1(){
    Food a;
    Creature b(&a, 1, 1, 3);
    CPPUNIT_ASSERT(b.getx() == 1);
    CPPUNIT_ASSERT(b.gety() == 1);
}

void testcreature2(){
    Food a;
    Creature b(&a, 1, 1, 3);
    Creature c(&a, 1, 1, 3);
    CPPUNIT_ASSERT(b.x == c.y);
     CPPUNIT_ASSERT(&b != &c);
}

void testcreature3(){
    Food a;
    Creature b(&a, 1, 1, 3);
    CPPUNIT_ASSERT(b.counter == 0);
    CPPUNIT_ASSERT(b.letter == 'f');
}

void testgame1(){
    Game g(1,1);
    g.setupboard();
    CPPUNIT_ASSERT(g.board.size() == 1);
    CPPUNIT_ASSERT(g.board[0].size() == 1);
}

void testgame2(){
    Game g(1,1);
    g.setupboard();
    Food a;
    g.putcreature(Creature(&a, 0, 0, 2), 0, 0);
    CPPUNIT_ASSERT(g.creatures.size() == 1);
}

void testgame3(){
    Game g(3,1);
    g.setupboard();
    CPPUNIT_ASSERT(g.board.size() == 3);
    CPPUNIT_ASSERT(g.board[0].size() == 1);
}

void testspecies1() {
    Food a;
    Hopper b;
    CPPUNIT_ASSERT(a.getletter() == 'f');
    CPPUNIT_ASSERT(b.getletter() == 'h');
}

void testspecies2() {
    int i = 0;
    Game g(1,1);
    Hopper b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(b.execute(i, a, g.board) == 0);
    
}

void testspecies3() {
    int i = 1;
    Game g(1,1);
    Hopper b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(b.execute(i, a, g.board) == 0);
}

void testrover1() {
    int i = 5;
    Game g(1,1);
    Rover b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(b.execute(i, a, g.board) == 2);

}

void testrover2() {
    int i = 3;
    Game g(1,1);
    Rover b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(b.execute(i, a, g.board) == 1);

}

void testrover3() {
    int i = 9;
    Game g(1,1);
    Rover b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(b.execute(i, a, g.board) == 3);

}

void testnowall1() {
    Game g(1,1);
    g.setupboard();
    Rover b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(a.nowall(g.board) == false);
}
void testnowall2() {
    Game g(10,10);
    g.setupboard();
    Rover b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(a.nowall(g.board) == true);
}

void testifcreature1() {
    Game g(10,10);
    g.setupboard();
    Rover b;
    Creature a(&b, 0, 0, 3);
    CPPUNIT_ASSERT(a.ifcreature(g.board) == '.');

}



CPPUNIT_TEST_SUITE(TestDarwin);
CPPUNIT_TEST(testcreature1);
CPPUNIT_TEST(testcreature2);
CPPUNIT_TEST(testcreature3);
CPPUNIT_TEST(testgame1);
CPPUNIT_TEST(testgame2);
CPPUNIT_TEST(testgame3);
CPPUNIT_TEST(testspecies1);
CPPUNIT_TEST(testspecies2);
CPPUNIT_TEST(testspecies3);
CPPUNIT_TEST(testrover1);
CPPUNIT_TEST(testrover2);
CPPUNIT_TEST(testrover3);
CPPUNIT_TEST(testnowall1);
CPPUNIT_TEST(testnowall2);
CPPUNIT_TEST(testifcreature1);
//CPPUNIT_TEST(testifcreature2);

CPPUNIT_TEST_SUITE_END();

};



int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}