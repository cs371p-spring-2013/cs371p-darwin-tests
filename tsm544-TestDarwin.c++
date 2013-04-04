/*
 * TestDarwin.c++
 *
 * @author Taylor Mckinney, tsm544
 */

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"
#include "GameMap.h"
#include "Creature.h"


struct TestCreature : CppUnit::TestFixture {

  void constructor01 () {
    Creature c ("food", North);
    CPPUNIT_ASSERT(c.species == "food");
    CPPUNIT_ASSERT(c.direction == North);
    CPPUNIT_ASSERT(c.instructions[0] == "left");
    CPPUNIT_ASSERT(c.instructions[1] == "go 0");
  }

  void constructor02 () {
    Creature c ("hopper", South);
    CPPUNIT_ASSERT(c.species == "hopper");
    CPPUNIT_ASSERT(c.direction == South);
    CPPUNIT_ASSERT(c.instructions[0] == "hop");
    CPPUNIT_ASSERT(c.instructions[1] == "go 0");
  }

  void constructor03 () {
    Creature c ("rover", East);
    CPPUNIT_ASSERT(c.species == "rover");
    CPPUNIT_ASSERT(c.direction == East);
    CPPUNIT_ASSERT(c.instructions[0] == "if_enemy 9");
    CPPUNIT_ASSERT(c.instructions[1] == "if_empty 7");
    CPPUNIT_ASSERT(c.instructions[2] == "if_random 5");
    CPPUNIT_ASSERT(c.instructions[3] == "left");
    CPPUNIT_ASSERT(c.instructions[4] == "go 0");
    CPPUNIT_ASSERT(c.instructions[5] == "right");
    CPPUNIT_ASSERT(c.instructions[6] == "go 0");
    CPPUNIT_ASSERT(c.instructions[7] == "hop");
    CPPUNIT_ASSERT(c.instructions[8] == "go 0");
    CPPUNIT_ASSERT(c.instructions[9] == "infect");
    CPPUNIT_ASSERT(c.instructions[10] == "go 0");
  }
  
  void constructor04 () {
    Creature c ("trap", West);
    CPPUNIT_ASSERT(c.species == "trap");
    CPPUNIT_ASSERT(c.direction == West);
    CPPUNIT_ASSERT(c.instructions[0] == "if_enemy 3");
    CPPUNIT_ASSERT(c.instructions[1] == "left");
    CPPUNIT_ASSERT(c.instructions[2] == "go 0");
    CPPUNIT_ASSERT(c.instructions[3] == "infect");
    CPPUNIT_ASSERT(c.instructions[4] == "go 0");
  }

  void left01 () {
    Creature c("food", North);
    CPPUNIT_ASSERT(c.direction == North);
    c.left();
    CPPUNIT_ASSERT(c.direction == West);
  }
  
  void left02 () {
    Creature c("food", West);
    CPPUNIT_ASSERT(c.direction == West);
    c.left();
    CPPUNIT_ASSERT(c.direction == South);
  }
  
  void left03 () {
    Creature c("food", South);
    CPPUNIT_ASSERT(c.direction == South);
    c.left();
    CPPUNIT_ASSERT(c.direction == East);
  }
  
  void left04 () {
    Creature c("food", East);
    CPPUNIT_ASSERT(c.direction == East);
    c.left();
    CPPUNIT_ASSERT(c.direction == North);
  }
  
  void right01 () {
    Creature c("food", North);
    CPPUNIT_ASSERT(c.direction == North);
    c.right();
    CPPUNIT_ASSERT(c.direction == East);
  }
  
  void right02 () {
    Creature c("food", East);
    CPPUNIT_ASSERT(c.direction == East);
    c.right();
    CPPUNIT_ASSERT(c.direction == South);
  }
  
  void right03 () {
    Creature c("food", South);
    CPPUNIT_ASSERT(c.direction == South);
    c.right();
    CPPUNIT_ASSERT(c.direction == West);
  }
  
  void right04 () {
    Creature c("food", West);
    CPPUNIT_ASSERT(c.direction == West);
    c.right();
    CPPUNIT_ASSERT(c.direction == North);
  }
   
  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestCreature);

  CPPUNIT_TEST(constructor01);
  CPPUNIT_TEST(constructor02);
  CPPUNIT_TEST(constructor03);
  CPPUNIT_TEST(constructor04);

  CPPUNIT_TEST(left01);
  CPPUNIT_TEST(left02);
  CPPUNIT_TEST(left03);
  CPPUNIT_TEST(left04);

  CPPUNIT_TEST(right01);
  CPPUNIT_TEST(right02);
  CPPUNIT_TEST(right03);
  CPPUNIT_TEST(right04);

  CPPUNIT_TEST_SUITE_END();
};

struct TestGameMap : CppUnit::TestFixture {

  
  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestGameMap);
  CPPUNIT_TEST_SUITE_END();
};

struct TestDarwin : CppUnit::TestFixture {


  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST_SUITE_END();
};

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
  CppUnit::TextTestRunner tr;

  tr.addTest(TestDarwin::suite());
  tr.addTest(TestGameMap::suite());
  tr.addTest(TestCreature::suite());

  tr.run();
  return 0;
}
