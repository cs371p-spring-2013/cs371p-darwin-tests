// --------------------------------
// TestDarwin
// --------------------------------

/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app -lcppunit -ldl
% valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include <vector>
#include <sstream>
#include <stdexcept>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private public

#include "Darwin.h"
#include "Creature.h"

using namespace std;

struct TestDarwin : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_runTurn_1 () {
        Creature c(food, 0);
        CPPUNIT_ASSERT(c.runTurn(empty) == nothing);
    }

    void test_runTurn_2 () {
        Creature c(hopper, 0);
        CPPUNIT_ASSERT(c.runTurn(empty) == step);
    }

    void test_runTurn_3 () {
        Creature c(rover, 0);
        CPPUNIT_ASSERT(c.runTurn(enemy) == bite);
    }

    void test_facing () {
        Creature c(rover, 0);
        Creature d(hopper, 3);
        CPPUNIT_ASSERT(c.facing(0));
        CPPUNIT_ASSERT(d.facing(3));
    }

    void test_become () {
      Creature c(rover, 0);
      Creature d(trap, 3);
      c.become(d);
      CPPUNIT_ASSERT(c.myType == trap);
      CPPUNIT_ASSERT(c.facing(0));
    }

    void test_equality () {
      Creature c(rover, 0);
      Creature d(rover, 1);
      Creature e(best, 2);
      CPPUNIT_ASSERT(c == d);
      CPPUNIT_ASSERT(!(c == e));
    }

    void test_notBlank () {
      Creature c = Creature();
      Creature d(rover, 0);
      CPPUNIT_ASSERT(d.notBlank());
      CPPUNIT_ASSERT(!c.notBlank());
    }

    void test_toChar () {
      Creature c = Creature();
      Creature d(rover, 0);
      Creature e(best, 0);
      Creature f(food, 0);
      CPPUNIT_ASSERT(c.toChar() == '.');
      CPPUNIT_ASSERT(d.toChar() == 'r');
      CPPUNIT_ASSERT(e.toChar() == 'b');
      CPPUNIT_ASSERT(f.toChar() == 'f');
    }

    void test_nextInstruction () {
      Creature c(best, 1);
      c.pc = 9;
      Instruction test = c.nextInstruction();
      CPPUNIT_ASSERT(test.instr == go);
      CPPUNIT_ASSERT(test.line == 3);
    }

    void test_nextInstruction2 () {
      Creature c(best, 1);
      c.pc = 18;
      Instruction test = c.nextInstruction();
      CPPUNIT_ASSERT(test.instr == Instr::right);
      CPPUNIT_ASSERT(test.line == -1);
    }

    void test_nextInstruction3 () {
      Creature c(rover, 1);
      c.pc = 2;
      Instruction test = c.nextInstruction();
      CPPUNIT_ASSERT(test.instr == if_random);
      CPPUNIT_ASSERT(test.line == 5);
    }
  
    void test_add() {
        Board b(3, 3);
        try{
          b.addCreature(food, 4, 4, 1);
        }
        catch (const invalid_argument&){
          return;
        }
        CPPUNIT_ASSERT(false);
    }

    void test_add2() {
      Board b(1, 1);
      b.addCreature(best, 0, 0, 0);
      CPPUNIT_ASSERT(b.creatures[0].toChar() == 'b');
    }

    void test_add3() {
      Board b(3, 3);
      b.addCreature(best, 1, 1, 1);
      CPPUNIT_ASSERT(b.creatures[4].toChar() == 'b');
    }      

    void test_display () {
        Board b(2, 2);
        std::ostringstream s;
        b.display(s);
        CPPUNIT_ASSERT(s.str() == "  01\n0 ..\n1 ..\n");
    }
    void test_display2 () {
        Board b(2, 2);
        b.addCreature(food, 0, 0, 0);
        b.addCreature(rover, 1, 1, 0);
        std::ostringstream s;
        b.display(s);
        CPPUNIT_ASSERT(s.str() == "  01\n0 f.\n1 .r\n");
    }
    void test_display3 () {
        Board b(2, 2);
        b.addCreature(best, 0, 0, 1);
        b.addCreature(best, 1, 0, 1);
        b.addCreature(best, 0, 1, 1);
        b.addCreature(best, 1, 1, 1);
        std::ostringstream s;
        b.display(s);
        CPPUNIT_ASSERT(s.str() == "  01\n0 bb\n1 bb\n");
    }

    void test_run () {
      srand(0);
      Board b(1, 2);
      b.addCreature(food, 0, 0, 0);
      b.addCreature(rover, 0, 1, 0);
      b.run(2);
      std::ostringstream s;
      b.display(s);
      CPPUNIT_ASSERT(s.str() == "  01\n0 rr\n");
    }

    void test_run2 () {
      srand(0);
      Board b(3, 3);
      b.addCreature(hopper, 0, 0, 3);
      b.addCreature(hopper, 1, 1, 0);
      b.addCreature(hopper, 0, 1, 3);
      std::ostringstream s;
      b.display(s);
      CPPUNIT_ASSERT(s.str() == "  012\n0 hh.\n1 .h.\n2 ...\n");
      
      b.run(1);
      s.str(string());
      b.display(s);      
      CPPUNIT_ASSERT(s.str() == "  012\n0 .h.\n1 hh.\n2 ...\n");
    }

    void test_run3 () {
      srand(0);
      Board b(3, 3);
      b.addCreature(hopper, 0, 0, 3);
      b.addCreature(hopper, 1, 1, 0);
      b.addCreature(rover, 0, 1, 3);
      b.run(1);
      std::ostringstream s;
      b.display(s);
      CPPUNIT_ASSERT(s.str() == "  012\n0 .r.\n1 rr.\n2 ...\n");
    }
  
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_runTurn_1);
    CPPUNIT_TEST(test_runTurn_2);
    CPPUNIT_TEST(test_runTurn_3);
    CPPUNIT_TEST(test_facing);
    CPPUNIT_TEST(test_become);
    CPPUNIT_TEST(test_equality);
    CPPUNIT_TEST(test_notBlank);
    CPPUNIT_TEST(test_toChar);
    CPPUNIT_TEST(test_nextInstruction);
    CPPUNIT_TEST(test_nextInstruction2);
    CPPUNIT_TEST(test_nextInstruction3);
    CPPUNIT_TEST(test_add);
    CPPUNIT_TEST(test_add2);
    CPPUNIT_TEST(test_add3);
    CPPUNIT_TEST(test_display);
    CPPUNIT_TEST(test_display2);
    CPPUNIT_TEST(test_display3);
    CPPUNIT_TEST(test_run);
    CPPUNIT_TEST(test_run2);
    CPPUNIT_TEST(test_run3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
