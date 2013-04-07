#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"

#include "cppunit/extensions/HelperMacros.h" 
#include "cppunit/TestFixture.h" 
#include "cppunit/TextTestRunner.h" 

#define private public
#include "Darwin.h"

struct TestDarwin : CppUnit::TestFixture {
  void field_1 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.grid[4][4].sid == '.');
  }

  void field_2 () {
    field a(1, 5);
    CPPUNIT_ASSERT (a.grid[0][4].sid == '.');
  }

  void field_3 () {
    field a(75, 1);
    CPPUNIT_ASSERT (a.grid[74][0].sid == '.');
  }

  void food_1 () {
    field a(5, 5);
    a.add('f', 'n', 0, 0);
    CPPUNIT_ASSERT (a.grid[0][0].sid = 'f');
  }

  void food_2 () {
    field a(5, 5);
    a.add('f', 'n', 1, 0);
    CPPUNIT_ASSERT (a.grid[1][0].sid = 'f');
  }

  void food_3 () {
    field a(5, 5);
    a.add('f', 'n', 0, 4);
    CPPUNIT_ASSERT (a.grid[0][4].sid = 'f');
  }

  void hopper_1 () {
    field a(5, 5);
    a.add('h', 'n', 0, 0);
    CPPUNIT_ASSERT (a.grid[0][0].sid = 'h');
  }

  void hopper_2 () {
    field a(5, 5);
    a.add('h', 'n', 0, 4);
    CPPUNIT_ASSERT (a.grid[0][4].sid = 'h');
  }

  void hopper_3 () {
    field a(5, 5);
    a.add('h', 'n', 4, 4);
    CPPUNIT_ASSERT (a.grid[4][4].sid = 'h');
  }

  void rover_1 () {
    field a(5, 5);
    a.add('r', 'n', 4, 4);
    CPPUNIT_ASSERT (a.grid[4][4].sid = 'r');
  }
  void rover_2 () {
    field a(5, 5);
    a.add('r', 'n', 0, 0);
    CPPUNIT_ASSERT (a.grid[0][0].sid = 'r');
  }
  void rover_3 () {
    field a(5, 5);
    a.add('r', 'n', 1, 1);
    CPPUNIT_ASSERT (a.grid[1][1].sid = 'r');
  }

  void trap_1 () {
    field a(5, 5);
    a.add('t', 'n', 4, 4);
    CPPUNIT_ASSERT (a.grid[4][4].sid = 't');
  }

  void trap_2 () {
    field a(5, 5);
    a.add('t', 'n', 0, 0);
    CPPUNIT_ASSERT (a.grid[0][0].sid = 't');
  }

  void trap_3 () {
    field a(5, 5);
    a.add('t', 'n', 1, 1);
    CPPUNIT_ASSERT (a.grid[1][1].sid = 't');
  }

  void left_1 () {
    field a(5, 5);
    a.add('t', 'n', 1, 1);
    a.left(a.grid[1][1].dir);
    CPPUNIT_ASSERT (a.grid[1][1].dir = 'w');
  }

  void left_2 () {
    field a(5, 5);
    a.add('t', 'w', 1, 1);
    a.left(a.grid[1][1].dir);
    CPPUNIT_ASSERT (a.grid[1][1].dir = 's');
  }

  void left_3 () {
    field a(5, 5);
    a.add('t', 'e', 1, 1);
    a.left(a.grid[1][1].dir);
    CPPUNIT_ASSERT (a.grid[1][1].dir = 'n');
  }

  void right_1 () {
    field a(5, 5);
    a.add('t', 'n', 1, 1);
    a.right(a.grid[1][1].dir);
    CPPUNIT_ASSERT (a.grid[1][1].dir = 'e');
  }

  void right_2 () {
    field a(5, 5);
    a.add('t', 'w', 1, 1);
    a.right(a.grid[1][1].dir);
    CPPUNIT_ASSERT (a.grid[1][1].dir = 'n');
  }

  void right_3 () {
    field a(5, 5);
    a.add('t', 'e', 1, 1);
    a.right(a.grid[1][1].dir);
    CPPUNIT_ASSERT (a.grid[1][1].dir = 's');
  }

  void infect_1 () {
    field a(5, 5);
    a.add('h', 'n', 1, 1);
    a.infect(2, 1, 'n', 'r');
    CPPUNIT_ASSERT (a.grid[1][1].sid = 'r');
  }

  void infect_2 () {
    field a(5, 5);
    a.add('f', 'n', 1, 1);
    a.infect(2, 1, 'n', 'h');
    CPPUNIT_ASSERT (a.grid[1][1].sid = 'h');
  }

  void infect_3 () {
    field a(5, 5);
    a.add('h', 'n', 1, 1);
    a.infect(2, 1, 'n', 't');
    CPPUNIT_ASSERT (a.grid[1][1].sid = 't');
  }

  void empty_1 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.isEmpty(2, 2, 'n'));
  }

  void empty_2 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.isEmpty(3, 2, 'n'));
  }

  void empty_3 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.isEmpty(0, 0, 's'));
  }

  void wall_1 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.isWall(0, 2, 'n'));
  }

  void wall_2 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.isWall(0, 2, 'n'));
  }

  void wall_3 () {
    field a(5, 5);
    CPPUNIT_ASSERT (a.isWall(4, 0, 's'));
  }

CPPUNIT_TEST_SUITE(TestDarwin);
  CPPUNIT_TEST(field_1); 
  CPPUNIT_TEST(field_2); 
  CPPUNIT_TEST(field_3);  
  CPPUNIT_TEST(food_1);
  CPPUNIT_TEST(food_2);
  CPPUNIT_TEST(food_3); 
  CPPUNIT_TEST(hopper_1);
  CPPUNIT_TEST(hopper_2);
  CPPUNIT_TEST(hopper_3);
  CPPUNIT_TEST(rover_1);
  CPPUNIT_TEST(rover_2);
  CPPUNIT_TEST(rover_3);
  CPPUNIT_TEST(trap_1);
  CPPUNIT_TEST(trap_2);
  CPPUNIT_TEST(trap_3);
  CPPUNIT_TEST(left_1);
  CPPUNIT_TEST(left_2);
  CPPUNIT_TEST(left_3);
  CPPUNIT_TEST(right_1);
  CPPUNIT_TEST(right_2);
  CPPUNIT_TEST(right_3);
  CPPUNIT_TEST(infect_1);
  CPPUNIT_TEST(infect_2);
  CPPUNIT_TEST(infect_3);
  CPPUNIT_TEST(empty_1);
  CPPUNIT_TEST(empty_2);
  CPPUNIT_TEST(empty_3);
  CPPUNIT_TEST(wall_1);
  CPPUNIT_TEST(wall_2);
  CPPUNIT_TEST(wall_3);
  CPPUNIT_TEST_SUITE_END();
};


int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); 
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
