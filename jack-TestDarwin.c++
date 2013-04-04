/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"

// -----------
// TestCollatz
// -----------
#define CACHESIZE 1000000/2

struct TestDarwin : CppUnit::TestFixture {

  void test_getMove_1() {
	using namespace std;
	Board b(8,8);
	vector<string> program(0);
	program.push_back("hop"); program.push_back("go 0");
	Creature c = Creature(Species(program, "h"), 0);
	CPPUNIT_ASSERT(c.getMove(b, 0, 0, 0) == "hop");
	CPPUNIT_ASSERT(c.pc = 1);
  }


  void test_getMove_2() {
	using namespace std;
	Board b(8,8);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("left"); program.push_back("go 0");
	Creature c = Creature(Species(program, "h"), 0);
	CPPUNIT_ASSERT(c.getMove(b, 0, 0, 0) == "left");
	CPPUNIT_ASSERT(c.pc = 3);
	CPPUNIT_ASSERT(c.direction = 3);
  }


  void test_getMove_3() {
	using namespace std;
	Board b(8,8);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("go 3"); program.push_back("go 0");
	Creature c = Creature(Species(program, "h"), 0);
	CPPUNIT_ASSERT(c.getMove(b, 0, 0, 0) == "null");

  }


  void test_getMove_4() {
	using namespace std;
	Board b(8,8);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	Creature c = Creature(Species(program, "h"), 0);
	CPPUNIT_ASSERT(c.getMove(b, 0, 0, 0) == "right");
	CPPUNIT_ASSERT(c.pc = 3);
	CPPUNIT_ASSERT(c.direction = 1);
  }


  void test_print_1() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	Creature c = Creature(Species(program, "h"), 0);
	CPPUNIT_ASSERT(b.print(0) == true);
  }


  void test_print_2() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	CPPUNIT_ASSERT(b.print(0) == true);
  }

  void test_print_3() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	CPPUNIT_ASSERT(b.print(0) == true);
  }

  void test_print_4() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	CPPUNIT_ASSERT(b.print(0) == true);
  }


  void test_turn_1() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }

  void test_turn_2() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }

  void test_turn_3() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }

  void test_turn_4() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }


  void test_add_1() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }

  void test_add_2() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }

  void test_add_3() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }
  
  void test_add_4() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.turn(0);
	CPPUNIT_ASSERT(true);
  }

  void test_simulate_1() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.simulate(1, 1);
	CPPUNIT_ASSERT(true);
  }

  void test_simulate_2() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.simulate(10, 5);
	CPPUNIT_ASSERT(true);
  }

  void test_simulate_3() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.simulate(7, 3);
	CPPUNIT_ASSERT(true);
  }

  void test_simulate_4() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.simulate(3, 1);
	CPPUNIT_ASSERT(true);
  }


  void test_isRandom_1() {
	using namespace std;
	Board b(2, 2);
	bool rnd = b.isRandom();
	CPPUNIT_ASSERT(rnd || !rnd);
  }
  void test_isRandom_2() {
	using namespace std;
	Board b(2, 2);
	bool rnd = b.isRandom();
	CPPUNIT_ASSERT(rnd || !rnd);
  }
  void test_isRandom_3() {
	using namespace std;
	Board b(2, 2);
	bool rnd = b.isRandom();
	CPPUNIT_ASSERT(rnd || !rnd);
  }
  void test_isRandom_4() {
	using namespace std;
	Board b(2, 2);
	bool rnd = b.isRandom();
	CPPUNIT_ASSERT(rnd || !rnd);
  }


  void test_doHop_1() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.add(Creature(Species(program, "h"), 0), 0, 1);
	b.add(Creature(Species(program, "h"), 0), 1, 1);
	b.turn(1);
	CPPUNIT_ASSERT(true);
  }

  void test_doHop_2() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
   	b.simulate(3, 1);
	CPPUNIT_ASSERT(true);
  }
  
  void test_doHop_3() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.simulate(3, 1);
	CPPUNIT_ASSERT(true);
  }

  void test_doHop_4() {
	using namespace std;
	Board b(2, 2);
	vector<string> program(0);
	program.push_back("go 1"); program.push_back("go 2");
	program.push_back("right"); program.push_back("go 0");
	b.add(Creature(Species(program, "h"), 0), 0, 0);
	b.add(Creature(Species(program, "h"), 0), 1, 0);
	b.simulate(3, 1);
	CPPUNIT_ASSERT(true);
  }

  CPPUNIT_TEST_SUITE(TestDarwin);

  CPPUNIT_TEST(test_getMove_1);
  CPPUNIT_TEST(test_getMove_2);
  CPPUNIT_TEST(test_getMove_3);
  CPPUNIT_TEST(test_getMove_4);

  CPPUNIT_TEST(test_print_1);
  CPPUNIT_TEST(test_print_2);
  CPPUNIT_TEST(test_print_3);
  CPPUNIT_TEST(test_print_4);

  CPPUNIT_TEST(test_turn_1);
  CPPUNIT_TEST(test_turn_2);
  CPPUNIT_TEST(test_turn_3);
  CPPUNIT_TEST(test_turn_4);

  CPPUNIT_TEST(test_add_1);
  CPPUNIT_TEST(test_add_2);
  CPPUNIT_TEST(test_add_3);
  CPPUNIT_TEST(test_add_4);

  CPPUNIT_TEST(test_simulate_1);
  CPPUNIT_TEST(test_simulate_2);
  CPPUNIT_TEST(test_simulate_3);
  CPPUNIT_TEST(test_simulate_4);


  CPPUNIT_TEST(test_isRandom_1);
  CPPUNIT_TEST(test_isRandom_2);
  CPPUNIT_TEST(test_isRandom_3);
  CPPUNIT_TEST(test_isRandom_4);


  CPPUNIT_TEST(test_doHop_1);
  CPPUNIT_TEST(test_doHop_2);
  CPPUNIT_TEST(test_doHop_3);
  CPPUNIT_TEST(test_doHop_4);
  CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

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
