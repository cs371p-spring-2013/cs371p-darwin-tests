// ------------------------------------
// cs371p-darwin/TestDarwin.c++
// Copyright (C) 2013
// Kartik Hattangadi
// ------------------------------------

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

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {


    // --------------------
    // test_creature_constr
    // --------------------

    void test_creature_constr() {
      Creature c(1, "food");
      CPPUNIT_ASSERT(c.direction == 1);
      CPPUNIT_ASSERT(c.prog_count == 0);
      CPPUNIT_ASSERT(c.creature_char == 'f');
    }


    // --------
    // test_grid_constr
    // --------

    void test_grid_constr() {
      Grid g(8, 9);
      CPPUNIT_ASSERT(g.turn == 0);
      CPPUNIT_ASSERT(g.grid.size() == 8);
      CPPUNIT_ASSERT(g.grid[0].size() == 9);
    }


    // --------
    // test_grid_addcreat_1
    // --------

    void test_grid_addcreat_1() {
      Grid g(8, 9);
      Creature c(1, "food");
      g.add_creature(c, 3, 5);
      CPPUNIT_ASSERT(g.turn == 0);
      CPPUNIT_ASSERT(g.grid.size() == 8);
      CPPUNIT_ASSERT(g.grid[0].size() == 9);
      CPPUNIT_ASSERT(g.grid[3][5] == 0);
      CPPUNIT_ASSERT(g.creatures.size() == 1);
      CPPUNIT_ASSERT(g.completed_move.size() == 1);
    }

    // --------
    // test_grid_addcreat_2
    // --------

    void test_grid_addcreat_2() {
      Grid g(8, 9);
      Creature c(1, "food");
      Creature c1(2, "rover");
      g.add_creature(c, 3, 5);
      g.add_creature(c1, 4, 8);
      CPPUNIT_ASSERT(g.turn == 0);
      CPPUNIT_ASSERT(g.grid.size() == 8);
      CPPUNIT_ASSERT(g.grid[0].size() == 9);
      CPPUNIT_ASSERT(g.grid[3][5] == 0);
      CPPUNIT_ASSERT(g.grid[4][8] == 1);
      CPPUNIT_ASSERT(g.creatures.size() == 2);
      CPPUNIT_ASSERT(g.completed_move.size() == 2);
    }

    // --------
    // test_grid_addcreat_3
    // --------

    void test_grid_addcreat_3() {
      Grid g(8, 9);
      Creature c1(1, "food");
      Creature c2(2, "food");
      Creature c3(3, "food");
      g.add_creature(c1, 1, 2);
      g.add_creature(c2, 5, 3);
      g.add_creature(c3, 3, 6);
      CPPUNIT_ASSERT(g.turn == 0);
      CPPUNIT_ASSERT(g.grid.size() == 8);
      CPPUNIT_ASSERT(g.grid[0].size() == 9);
      CPPUNIT_ASSERT(g.grid[1][2] == 0);
      CPPUNIT_ASSERT(g.grid[5][3] == 1);
      CPPUNIT_ASSERT(g.grid[3][6] == 2);
      CPPUNIT_ASSERT(g.creatures.size() == 3);
      CPPUNIT_ASSERT(g.completed_move.size() == 3);
    }
    
    // ---------------------
    // test_grid_printgrid_1
    // ---------------------

    void test_grid_printgrid_1() {
      Grid g(1, 1);
      std::ostringstream o;
      g.print_grid(o);
      CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 .\n\n");
    }

    // ---------------------
    // test_grid_printgrid_2
    // ---------------------

    void test_grid_printgrid_2() {
      Grid g(1, 1);
      Creature c(Creature::NORTH, "food");
      std::ostringstream o;
      g.add_creature(c, 0, 0);
      g.print_grid(o);
      CPPUNIT_ASSERT(o.str() == "Turn = 0.\n  0\n0 f\n\n");
    }

    // ---------------------
    // test_grid_printgrid_3
    // ---------------------

    void test_grid_printgrid_3() {
      Grid g(1, 1);
      Creature c(Creature::NORTH, "food");
      std::ostringstream o;
      g.add_creature(c, 0, 0);
      g.next_move();
      g.print_grid(o);
      CPPUNIT_ASSERT(o.str() == "Turn = 1.\n  0\n0 f\n\n");
    }

    // --------
    // test_creature_next_space_1
    // --------

    void test_creature_next_space_1() {
      std::pair<int, int> curr_pos(4, 3);
      Creature c(0, "food");
      std::pair<int, int> next_pos = c.next_space(curr_pos);
      CPPUNIT_ASSERT(next_pos.first == 3);
      CPPUNIT_ASSERT(next_pos.second == 3);
    }

    // ----------------------
    // test_creature_next_space_2
    // ----------------------

    void test_creature_next_space_2() {
      std::pair<int, int> curr_pos(4, 3);
      Creature c(1, "food");
      std::pair<int, int> next_pos = c.next_space(curr_pos);
      CPPUNIT_ASSERT(next_pos.first == 4);
      CPPUNIT_ASSERT(next_pos.second == 4);
    }

    // ----------------------
    // test_creature_next_space_3
    // ----------------------

    void test_creature_next_space_3() {
      std::pair<int, int> curr_pos(4, 3);
      Creature c(2, "food");
      std::pair<int, int> next_pos = c.next_space(curr_pos);
      CPPUNIT_ASSERT(next_pos.first == 5);
      CPPUNIT_ASSERT(next_pos.second == 3);
    }

    // ----------------------
    // test_creature_next_space_4
    // ----------------------

    void test_creature_next_space_4() {
      std::pair<int, int> curr_pos(4, 3);
      Creature c(3, "food");
      std::pair<int, int> next_pos = c.next_space(curr_pos);
      CPPUNIT_ASSERT(next_pos.first == 4);
      CPPUNIT_ASSERT(next_pos.second == 2);
    }


    // ----------------------
    // test_grid_wall_1
    // ----------------------

    void test_grid_wall_1() {
      std::pair<int, int> curr_pos(-1, 5);
      Grid g(8, 3);
      CPPUNIT_ASSERT(g.wall(curr_pos) == true);
    }

    // ----------------------
    // test_grid_wall_2
    // ----------------------

    void test_grid_wall_2() {
      std::pair<int, int> curr_pos(0, 5);
      Grid g(8, 3);
      CPPUNIT_ASSERT(g.wall(curr_pos) == true);
    }

    // ----------------------
    // test_grid_wall_3
    // ----------------------

    void test_grid_wall_3() {
      std::pair<int, int> curr_pos(0, 2);
      Grid g(8, 3);
      CPPUNIT_ASSERT(g.wall(curr_pos) == false);
    }

    // ----------------------
    // test_creature_infect_1
    // ----------------------

    void test_creature_infect_1() {
      Creature c(1, "food");
      Creature c1(2, "rover");
      c.infect_creature(c1);
      CPPUNIT_ASSERT(c.prog_count == 0);
      CPPUNIT_ASSERT(c.instructions == c1.instructions);
      CPPUNIT_ASSERT(c.instructions == Rover::instructions);
    }

    // ----------------------
    // test_creature_infect_2
    // ----------------------

    void test_creature_infect_2() {
      Creature c(1, "food");
      Creature c1(2, "trap");
      c.infect_creature(c1);
      CPPUNIT_ASSERT(c.prog_count == 0);
      CPPUNIT_ASSERT(c.instructions == c1.instructions);
      CPPUNIT_ASSERT(c.instructions == Trap::instructions);
    }


    // ----------------------
    // test_creature_infect_3
    // ----------------------

    void test_creature_infect_3() {
      Creature c(1, "rover");
      Creature c1(2, "food");
      c.infect_creature(c1);
      CPPUNIT_ASSERT(c.prog_count == 0);
      CPPUNIT_ASSERT(c.instructions == c1.instructions);
      CPPUNIT_ASSERT(c.instructions == Food::instructions);
    }

    // ------------------------
    // test_creature_makemove_1
    // ------------------------

    void test_creature_makemove_1() {
      Creature c(1, "rover");
      std::pair<int, int> m = c.make_move(Grid::EMPTY);
      CPPUNIT_ASSERT(m.first  == 0);
      CPPUNIT_ASSERT(m.second == 1);
    }

    // ------------------------
    // test_creature_makemove_2
    // ------------------------

    void test_creature_makemove_2() {
      Creature c(1, "trap");
      std::pair<int, int> m = c.make_move(Grid::ENEMY);
      CPPUNIT_ASSERT(m.first  == 3);
      CPPUNIT_ASSERT(m.second == 1);
    }

    // ------------------------
    // test_creature_makemove_3
    // ------------------------

    void test_creature_makemove_3() {
      Creature c(1, "trap");
      std::pair<int, int> m = c.make_move(Grid::WALL);
      CPPUNIT_ASSERT(m.first  == 1);
      CPPUNIT_ASSERT(m.second == 0);
    }

    // ------------------------
    // test_creature_nextmove_1
    // ------------------------

    void test_grid_nextmove_1() {
      Grid g(10, 10);
      Creature c1(Creature::NORTH, "food");
      Creature c2(Creature::WEST, "rover");
      Creature c3(Creature::EAST, "trap");
      g.add_creature(c1, 2, 2);
      g.add_creature(c2, 2, 3);
      g.add_creature(c3, 4, 4);
      g.next_move();
      CPPUNIT_ASSERT(g.turn == 1);
      CPPUNIT_ASSERT(g.creatures[g.grid[2][3]].instructions == Rover::instructions);
      CPPUNIT_ASSERT(g.creatures[g.grid[4][4]].prog_count == 2);
    }
      
    // ------------------------
    // test_creature_nextmove_2
    // ------------------------

    void test_grid_nextmove_2() {
      Grid g(10, 10);
      Creature c1(Creature::NORTH, "food");
      Creature c2(Creature::WEST, "food");
      Creature c3(Creature::EAST, "food");
      g.add_creature(c1, 2, 2);
      g.add_creature(c2, 2, 3);
      g.add_creature(c3, 4, 4);
      g.next_move();
      g.next_move();
      g.next_move();
      CPPUNIT_ASSERT(g.turn == 3);
      CPPUNIT_ASSERT(g.creatures[g.grid[2][2]].prog_count == 1);
      CPPUNIT_ASSERT(g.creatures[g.grid[2][3]].prog_count == 1);
      CPPUNIT_ASSERT(g.creatures[g.grid[4][4]].prog_count == 1);
    }

    // ------------------------
    // test_creature_nextmove_3
    // ------------------------

    void test_grid_nextmove_3() {
      Grid g(10, 10);
      Creature c1(Creature::NORTH, "hopper");
      Creature c2(Creature::WEST, "hopper");
      Creature c3(Creature::EAST, "hopper");
      g.add_creature(c1, 2, 2);
      g.add_creature(c2, 2, 3);
      g.add_creature(c3, 4, 4);
      g.next_move();
      CPPUNIT_ASSERT(g.turn == 1);
      CPPUNIT_ASSERT(g.creatures[g.grid[1][2]].prog_count == 1);
      CPPUNIT_ASSERT(g.creatures[g.grid[2][2]].prog_count == 1);
      CPPUNIT_ASSERT(g.creatures[g.grid[4][5]].prog_count == 1);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_creature_constr);
    CPPUNIT_TEST(test_grid_constr);
    CPPUNIT_TEST(test_grid_addcreat_1);
    CPPUNIT_TEST(test_grid_addcreat_2);
    CPPUNIT_TEST(test_grid_addcreat_3);
    CPPUNIT_TEST(test_grid_printgrid_1);
    CPPUNIT_TEST(test_grid_printgrid_2);
    CPPUNIT_TEST(test_grid_printgrid_3);
    CPPUNIT_TEST(test_creature_next_space_1);
    CPPUNIT_TEST(test_creature_next_space_2);
    CPPUNIT_TEST(test_creature_next_space_3);
    CPPUNIT_TEST(test_creature_next_space_4);
    CPPUNIT_TEST(test_grid_wall_1);
    CPPUNIT_TEST(test_grid_wall_2);
    CPPUNIT_TEST(test_grid_wall_3);
    CPPUNIT_TEST(test_creature_infect_1);
    CPPUNIT_TEST(test_creature_infect_2);
    CPPUNIT_TEST(test_creature_infect_3);
    CPPUNIT_TEST(test_creature_makemove_1);
    CPPUNIT_TEST(test_creature_makemove_2);
    CPPUNIT_TEST(test_creature_makemove_3);
    CPPUNIT_TEST(test_grid_nextmove_1);
    CPPUNIT_TEST(test_grid_nextmove_2);
    CPPUNIT_TEST(test_grid_nextmove_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestDarwin::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
