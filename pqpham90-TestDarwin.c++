// ------------------------------------
// TestDarwin.c++
// Phillipquang Pham
// pqpham90
// ------------------------------------
using namespace std;
#define private public

/**
 * To test the program:
 *     % g++ -ansi -pedantic -lcppunit -ldl -Wall TestDarwin.c++ -o TestDarwin.app
 *     % valgrind TestDarwin.app >& TestDarwin.c++.out
 */

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Darwin.h"
#include "Darwin.c++"

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {
    // --------
    // instruction_construction
    // --------

    void test_instruction_construction_1() {
        Instruction i1(HOP);
        Instruction i2(LEFT);
        Instruction i3(RIGHT);
        Instruction i4(INFECT);

        CPPUNIT_ASSERT(i1.command == 0);
        CPPUNIT_ASSERT(i2.command == 1);
        CPPUNIT_ASSERT(i3.command == 2);
        CPPUNIT_ASSERT(i4.command == 3);
    }

    void test_instruction_construction_2() {
        Instruction i1(IF_EMPTY, 4);
        Instruction i2(IF_WALL, 5);
        Instruction i3(IF_RANDOM, 6);
        Instruction i4(IF_ENEMY, 7);
        Instruction i5(GO, 8);

        CPPUNIT_ASSERT(i1.command == 4 && i1.destination == 4);
        CPPUNIT_ASSERT(i2.command == 5 && i2.destination == 5);
        CPPUNIT_ASSERT(i3.command == 6 && i3.destination == 6);
        CPPUNIT_ASSERT(i4.command == 7 && i4.destination == 7);
        CPPUNIT_ASSERT(i5.command == 8 && i5.destination == 8);
    }

    void test_instruction_construction_3() {
        Instruction i1(HOP);
        Instruction i2(LEFT);
        Instruction i3(RIGHT);
        Instruction i4(INFECT);
        Instruction i5(IF_EMPTY, 4);
        Instruction i6(IF_WALL, 5);
        Instruction i7(IF_RANDOM, 6);
        Instruction i8(IF_ENEMY, 7);
        Instruction i9(GO, 8);

        CPPUNIT_ASSERT(i1.isAction());
        CPPUNIT_ASSERT(i2.isAction());
        CPPUNIT_ASSERT(i3.isAction());
        CPPUNIT_ASSERT(i4.isAction());
        CPPUNIT_ASSERT(!i5.isAction());
        CPPUNIT_ASSERT(!i6.isAction());
        CPPUNIT_ASSERT(!i7.isAction());
        CPPUNIT_ASSERT(!i8.isAction());
        CPPUNIT_ASSERT(!i9.isAction());
    }

    void test_species_construction_1() {
        Species hylian('h', 12);

        CPPUNIT_ASSERT(hylian.mark == 'h');
    }

    void test_species_construction_2() {
        Species maverick('m', 24);

        CPPUNIT_ASSERT(maverick.mark == 'm');
    }

    void test_species_construction_3() {
        Species creeper('c', 1);

        CPPUNIT_ASSERT(creeper.mark == 'c');
    }
    
        void test_species_addInstruction_1() {
        Species hylian('h', 12);
        hylian.addInstruction(Instruction(LEFT));

        CPPUNIT_ASSERT(hylian.program[0].command == LEFT);
    }

    void test_species_addInstruction_2() {
        Species maverick('m', 24);
        maverick.addInstruction(Instruction(RIGHT));
        maverick.addInstruction(Instruction(GO, 0));

        CPPUNIT_ASSERT(maverick.program[0].command == RIGHT);
        CPPUNIT_ASSERT(maverick.program[1].command == GO);
    }

    void test_species_addInstruction_3() {
        Species creeper('c', 1);
        creeper.addInstruction(Instruction(GO, 0));
        creeper.addInstruction(Instruction(GO, 0));
        creeper.addInstruction(Instruction(GO, 0));

        CPPUNIT_ASSERT(creeper.program[0].command == GO);
        CPPUNIT_ASSERT(creeper.program[1].command == GO);
        CPPUNIT_ASSERT(creeper.program[2].command == GO);
    }
    
    void test_world_construction_1() {
        World hyrule(12,12);
        Species hylian('h', 12);
        hyrule.addCreature(&hylian, 6 ,6, EAST);
        bool empty = hyrule.emptySpot(0 , 0);
        bool inside = hyrule.insideWorld(-1, -1);
        bool same = hyrule.sameSpecies(hylian, 6, 6);
        
        int r = 6;
        int c = 6;
        hyrule.findFront(hyrule.map[6][6].direction, r, c);
        
        CPPUNIT_ASSERT(hyrule.map[6][6].species == &hylian);
        CPPUNIT_ASSERT(empty);
        CPPUNIT_ASSERT(!inside);
        CPPUNIT_ASSERT(same);
        CPPUNIT_ASSERT(r == 6 && c == 7);
    }
    
    void test_world_construction_2() {
        World miramar(24,24);
        Species maverick('m', 24);
        miramar.addCreature(&maverick, 23 ,23, WEST);
        bool empty = miramar.emptySpot(0 , 0);
        bool inside = miramar.insideWorld(24, 24);
        bool same = miramar.sameSpecies(maverick, 23, 23);
        
        int r = 23;
        int c = 23;
        miramar.findFront(miramar.map[23][23].direction, r, c);
        
        CPPUNIT_ASSERT(miramar.map[23][23].species == &maverick);
        CPPUNIT_ASSERT(empty);
        CPPUNIT_ASSERT(!inside);
        CPPUNIT_ASSERT(same);
        CPPUNIT_ASSERT(r == 23 && c == 22);
    }
    
    void test_world_construction_3() {
        World mine(1,1);
        Species creeper('c', 1);
        mine.addCreature(&creeper, 0 ,0, NORTH);
        bool empty = mine.emptySpot(0 , 0);
        bool inside = mine.insideWorld(0, 0);
        bool same = mine.sameSpecies(creeper, 0, 0);
        
        int r = 0;
        int c = 0;
        mine.findFront(mine.map[0][0].direction, r, c);
        
        CPPUNIT_ASSERT(mine.map[0][0].species == &creeper);
        CPPUNIT_ASSERT(!empty);
        CPPUNIT_ASSERT(inside);
        CPPUNIT_ASSERT(same);
        CPPUNIT_ASSERT(r == -1 && c == 0);
    }

    void test_world_emptySpot_1() {
        World hyrule(12,12);
        Species hylian('h', 12);
        hyrule.addCreature(&hylian, 6 ,6, EAST);

        bool empty1 = hyrule.emptySpot(0 , 0);
        bool empty2 = hyrule.emptySpot(11 , 0);
        bool empty3 = hyrule.emptySpot(0 , 11);
        bool empty4 = hyrule.emptySpot(0 , 11);

        CPPUNIT_ASSERT(empty1);
        CPPUNIT_ASSERT(empty2);
        CPPUNIT_ASSERT(empty3);
        CPPUNIT_ASSERT(empty4);
    }
    
    void test_world_emptySpot_2() {
        World miramar(24,24);
        Species maverick('m', 24);
        miramar.addCreature(&maverick, 23 ,23, WEST);

        bool empty1 = miramar.emptySpot(0 , 0);
        bool empty2 = miramar.emptySpot(23 , 0);
        bool empty3 = miramar.emptySpot(0 , 23);
        bool empty4 = miramar.emptySpot(23 , 23);

        CPPUNIT_ASSERT(empty1);
        CPPUNIT_ASSERT(empty2);
        CPPUNIT_ASSERT(empty3);
        CPPUNIT_ASSERT(!empty4);
    }
    
    void test_world_emptySpot_3() {
        World mine(1,1);
        Species creeper('c', 1);
        mine.addCreature(&creeper, 0 ,0, NORTH);
        bool empty = mine.emptySpot(0 , 0);

        CPPUNIT_ASSERT(!empty);
    }

    void test_world_insideWorld_1() {
        World hyrule(12,12);
        Species hylian('h', 12);
        hyrule.addCreature(&hylian, 6 ,6, EAST);

        bool inside1 = hyrule.insideWorld(-1, -1);
        bool inside2 = hyrule.insideWorld(0, 0);
        bool inside3 = hyrule.insideWorld(11, 0);
        bool inside4 = hyrule.insideWorld(0, 11);
        bool inside5 = hyrule.insideWorld(11, 11);
        

        CPPUNIT_ASSERT(!inside1);
        CPPUNIT_ASSERT(inside2);
        CPPUNIT_ASSERT(inside3);
        CPPUNIT_ASSERT(inside4);
        CPPUNIT_ASSERT(inside5);
    }
    
    void test_world_insideWorld_2() {
        World miramar(24,24);
        Species maverick('m', 24);
        miramar.addCreature(&maverick, 23 ,23, WEST);

        bool inside1 = miramar.insideWorld(24, 24);
        bool inside2 = miramar.insideWorld(-4, -4);
        bool inside3 = miramar.insideWorld(1, 1);
        bool inside4 = miramar.insideWorld(12, 16);


        CPPUNIT_ASSERT(!inside1);
        CPPUNIT_ASSERT(!inside2);
        CPPUNIT_ASSERT(inside3);
        CPPUNIT_ASSERT(inside4);
    }
    
    void test_world_insideWorld_3() {
        World mine(1,1);
        Species creeper('c', 1);
        mine.addCreature(&creeper, 0 ,0, NORTH);

        bool inside1 = mine.insideWorld(0, 0);
        bool inside2 = mine.insideWorld(1, 0);
        bool inside3 = mine.insideWorld(0, 1);
        bool inside4 = mine.insideWorld(-1, 0);
        bool inside5 = mine.insideWorld(0, -1);

        CPPUNIT_ASSERT(inside1);
        CPPUNIT_ASSERT(!inside2);
        CPPUNIT_ASSERT(!inside3);
        CPPUNIT_ASSERT(!inside4);
        CPPUNIT_ASSERT(!inside5);
    }

    void test_world_sameSpecies_1() {
        World hyrule(12,12);
        Species hylian('h', 12);
        hyrule.addCreature(&hylian, 6 ,6, EAST);

        bool same1 = hyrule.sameSpecies(hylian, 6, 6);
        bool same2 = hyrule.sameSpecies(hylian, 1, 2);
        bool same3 = hyrule.sameSpecies(hylian, 3, 4);
        bool same4 = hyrule.sameSpecies(hylian, 5, 6);
        
        CPPUNIT_ASSERT(same1);
        CPPUNIT_ASSERT(!same2);
        CPPUNIT_ASSERT(!same3);
        CPPUNIT_ASSERT(!same4);
    }
    
    void test_world_sameSpecies_2() {
        World miramar(24,24);
        Species maverick('m', 24);
        miramar.addCreature(&maverick, 23 ,23, WEST);

        bool same1 = miramar.sameSpecies(maverick, 0, 0);
        bool same2 = miramar.sameSpecies(maverick, 0, 23);
        bool same3 = miramar.sameSpecies(maverick, 23, 0);
        bool same4 = miramar.sameSpecies(maverick, 23, 23);

        CPPUNIT_ASSERT(!same1);
        CPPUNIT_ASSERT(!same2);
        CPPUNIT_ASSERT(!same3);
        CPPUNIT_ASSERT(same4);
    }
    
    void test_world_sameSpecies_3() {
        World mine(1,1);
        Species creeper('c', 1);
        mine.addCreature(&creeper, 0 ,0, NORTH);

        bool same = mine.sameSpecies(creeper, 0, 0);
        
        CPPUNIT_ASSERT(same);
    }

    void test_world_findFront_1() {
        World hyrule(12,12);
        Species hylian('h', 12);
        hyrule.addCreature(&hylian, 6 ,6, EAST);
        
        int r = 6;
        int c = 6;
        hyrule.findFront(hyrule.map[6][6].direction, r, c);
        
        CPPUNIT_ASSERT(r == 6 && c == 7);
    }
    
    void test_world_findFront_2() {
        World miramar(24,24);
        Species maverick('m', 24);
        miramar.addCreature(&maverick, 23 ,23, WEST);
        
        int r = 23;
        int c = 23;
        miramar.findFront(miramar.map[23][23].direction, r, c);

        CPPUNIT_ASSERT(r == 23 && c == 22);
    }
    
    void test_world_findFront_3() {
        World mine(1,1);
        Species creeper('c', 1);
        mine.addCreature(&creeper, 0 ,0, NORTH);
        
        int r = 0;
        int c = 0;
        mine.findFront(mine.map[0][0].direction, r, c);

        CPPUNIT_ASSERT(r == -1 && c == 0);
    }
    
    // -----
    // suite
    // -----
    
    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_instruction_construction_1);
    CPPUNIT_TEST(test_instruction_construction_2);
    CPPUNIT_TEST(test_instruction_construction_3);
    CPPUNIT_TEST(test_species_construction_1);
    CPPUNIT_TEST(test_species_construction_2);
    CPPUNIT_TEST(test_species_construction_3);
    CPPUNIT_TEST(test_species_addInstruction_1);
    CPPUNIT_TEST(test_species_addInstruction_2);
    CPPUNIT_TEST(test_species_addInstruction_3);
    CPPUNIT_TEST(test_world_construction_1);
    CPPUNIT_TEST(test_world_construction_2);
    CPPUNIT_TEST(test_world_construction_3);
    CPPUNIT_TEST(test_world_emptySpot_1);
    CPPUNIT_TEST(test_world_emptySpot_2);
    CPPUNIT_TEST(test_world_emptySpot_3);
    CPPUNIT_TEST(test_world_insideWorld_1);
    CPPUNIT_TEST(test_world_insideWorld_2);
    CPPUNIT_TEST(test_world_insideWorld_3);
    CPPUNIT_TEST(test_world_sameSpecies_1);
    CPPUNIT_TEST(test_world_sameSpecies_2);
    CPPUNIT_TEST(test_world_sameSpecies_3);
    CPPUNIT_TEST(test_world_findFront_1);
    CPPUNIT_TEST(test_world_findFront_2);
    CPPUNIT_TEST(test_world_findFront_3);
    CPPUNIT_TEST_SUITE_END();
};


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O

    // CALL TO SRAND(0)
    srand(0);

    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

