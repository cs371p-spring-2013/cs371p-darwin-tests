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

#include "Darwin.h"
#include "GameMap.h"
#include "Creature.h"

struct TestDarwin : CppUnit::TestFixture {


  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST_SUITE_END();
};

struct TestGameMap : CppUnit::TestFixture {

  
  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestGameMap);
  CPPUNIT_TEST_SUITE_END();
};

struct TestCreature : CppUnit::TestFixture {

  
  //--------------------------------
  // Test Suite
  CPPUNIT_TEST_SUITE(TestCreature);
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
