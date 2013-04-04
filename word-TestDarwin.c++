//Christopher Word
//eid:cword
//csid:word



#include <iostream>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner


#define private public
#include "Darwin.h"

struct TestDarwin : CppUnit::TestFixture {


//board constructor

    void Contest_1 () {
        Board b = Board(1,1);
        CPPUNIT_ASSERT (b.zoo.size()==1);
    }

    void Contest_2 () {
        Board b = Board(10,10);
        CPPUNIT_ASSERT (b.zoo.size()==100);
    }

    void Contest_3 () {
        Board b = Board(10,10);
        CPPUNIT_ASSERT (b.zoo.size()==100);
        for(Creature c : b.zoo){
          CPPUNIT_ASSERT (c.mySpecies == NONE);
        }
    }

//hop
    void hoptest_1 () {
        Board b = Board(1,1);
        Creature c = Creature(0,0,SOUTH,HOPPER);
        b.addCreature(c);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT (b.zoo[0].mySpecies==HOPPER);

        b.left(b.zoo[0]);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT (b.zoo[0].mySpecies==HOPPER);

        b.left(b.zoo[0]);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT (b.zoo[0].mySpecies==HOPPER);

        b.left(b.zoo[0]);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT (b.zoo[0].mySpecies==HOPPER);


    }

    void hoptest_2 () {
        Board b = Board(1,3);
        Creature c1 = Creature(0,0,SOUTH,HOPPER);
        Creature c2 = Creature(0,1,SOUTH,HOPPER);

        b.addCreature(c1);
        b.addCreature(c2);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==NONE);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==NONE);
        b.hop(b.zoo[1]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==HOPPER);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==HOPPER);
        b.hop(b.zoo[1]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==HOPPER);
        b.hop(b.zoo[2]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==HOPPER);
    }

    void hoptest_3 () {
        Board b = Board(1,3);
        Creature c = Creature(0,0,SOUTH,HOPPER);
        b.addCreature(c);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==NONE);
        b.hop(b.zoo[0]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==HOPPER);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==NONE);
        b.hop(b.zoo[1]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==HOPPER);
        b.hop(b.zoo[2]);
        CPPUNIT_ASSERT(b.zoo[0].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[1].mySpecies==NONE);
        CPPUNIT_ASSERT(b.zoo[2].mySpecies==HOPPER);

    }

//infect
    void inftest_1 () {
        Board b = Board(1,2);
        Creature c1 = Creature(0,0,SOUTH,TRAP);
        Creature c2 = Creature(0,1,SOUTH,ROVER);
        b.addCreature(c1);
        b.addCreature(c2);

        b.infect(c1);
        CPPUNIT_ASSERT(b.zoo[0].getmySpecies()==TRAP);

        CPPUNIT_ASSERT(b.zoo[1].getmySpecies()==TRAP);
        CPPUNIT_ASSERT(b.zoo[1].facing==SOUTH);

    }

    void inftest_2 () {
        Board b = Board(3,3);
        Creature c1 = Creature(0,0,SOUTH,TRAP);
        Creature c2 = Creature(2,2,SOUTH,ROVER);
        b.addCreature(c1);
        b.addCreature(c2);
        b.infect(c1);
        b.infect(c2);

        CPPUNIT_ASSERT (b.zoo[0].mySpecies==TRAP);
        for(int i = 1; i < 8; i++){
            CPPUNIT_ASSERT (b.zoo[i].mySpecies==NONE);
        }
        CPPUNIT_ASSERT (b.zoo[8].mySpecies==ROVER);

    }

    void inftest_3 () {
        Board b = Board(1,2);
        Creature c1 = Creature(0,0,SOUTH,TRAP);
        Creature c2 = Creature(0,1,SOUTH,ROVER);
        b.addCreature(c1);
        b.addCreature(c2);
        b.infect(c1);
        b.left(c2);
        b.left(c2);
        b.infect(c2);

        for(int i = 0; i < 2; i++){
          CPPUNIT_ASSERT (b.zoo[i].mySpecies==TRAP);
        }
    }

//canInfect
    void canItest_1 () {
        Board b = Board(1,2);
        Creature c1 = Creature(0,0,SOUTH,TRAP);
        Creature c2 = Creature(0,1,SOUTH,ROVER);
        b.addCreature(c1);
        b.addCreature(c2);

        CPPUNIT_ASSERT (b.canInfect(c1));
        CPPUNIT_ASSERT (!b.canInfect(c2));
    }

    void canItest_2 () {
        Board b = Board(3,3);
        Creature c1 = Creature(0,0,SOUTH,TRAP);
        Creature c2 = Creature(2,2,SOUTH,ROVER);
        b.addCreature(c1);
        b.addCreature(c2);
        CPPUNIT_ASSERT (!b.canInfect(c1));
        CPPUNIT_ASSERT (!b.canInfect(c2));
        b.left(c1);
        b.left(c2);
        CPPUNIT_ASSERT (!b.canInfect(c1));
        CPPUNIT_ASSERT (!b.canInfect(c2));
        b.left(c1);
        b.left(c2);
        CPPUNIT_ASSERT (!b.canInfect(c1));
        CPPUNIT_ASSERT (!b.canInfect(c2));
        b.left(c1);
        b.left(c2);
        CPPUNIT_ASSERT (!b.canInfect(c1));
        CPPUNIT_ASSERT (!b.canInfect(c2));
    }

    void canItest_3 () {
        Board b = Board(1,2);
        Creature c1 = Creature(0,0,SOUTH,TRAP);
        Creature c2 = Creature(0,1,SOUTH,ROVER);
        b.addCreature(c1);
        b.addCreature(c2);

        CPPUNIT_ASSERT (b.canInfect(c1));
        CPPUNIT_ASSERT (!b.canInfect(c2));
        b.left(c2);
        b.left(c2);
        CPPUNIT_ASSERT (b.canInfect(c2));

    }

//isEmpty
    void isEtest_1 () {
        Board b = Board(1,1);
        Creature c = Creature(0,0,NORTH,HOPPER);
        b.addCreature(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
    }

    void isEtest_2 () {
        Board b = Board(1,2);
        Creature c = Creature(0,0,SOUTH,HOPPER);
        b.addCreature(c);

        CPPUNIT_ASSERT (b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
    }

    void isEtest_3 () {
        Board b = Board(3,3);
        Creature c = Creature(0,0,SOUTH,HOPPER);
        b.addCreature(c);

        CPPUNIT_ASSERT (b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
        b.left(c);
        CPPUNIT_ASSERT (!b.isEmpty(c));
    }


    //------
    // suite
    //------

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(Contest_1);
    CPPUNIT_TEST(Contest_2);
    CPPUNIT_TEST(Contest_3);

    CPPUNIT_TEST(hoptest_1);
    CPPUNIT_TEST(hoptest_2);
    CPPUNIT_TEST(hoptest_3);

    CPPUNIT_TEST(inftest_1);
    CPPUNIT_TEST(inftest_2);
    CPPUNIT_TEST(inftest_3);

    CPPUNIT_TEST(canItest_1);
    CPPUNIT_TEST(canItest_2);
    CPPUNIT_TEST(canItest_3);

    CPPUNIT_TEST(isEtest_1);
    CPPUNIT_TEST(isEtest_2);
    CPPUNIT_TEST(isEtest_3);


    CPPUNIT_TEST_SUITE_END();
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}