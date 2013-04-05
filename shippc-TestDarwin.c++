// ------------------------------------
// cs371p-darwin/TestDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
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
    // test_Instruction
    // --------------------

    void test_instruction() {
      Instruction i = Instruction();

      CPPUNIT_ASSERT(i.action == true);
      CPPUNIT_ASSERT(i.name == "left");
      CPPUNIT_ASSERT(i.line == -1);
    }

    // --------------------
    // test_instruction2
    // --------------------

    void test_instruction2() {
      Instruction i = Instruction(true, "hop");

      CPPUNIT_ASSERT(i.action == true);
      CPPUNIT_ASSERT(i.name == "hop");
      CPPUNIT_ASSERT(i.line == -1);
    }

    // --------------------
    // test_instruction3
    // --------------------

    void test_instruction3() {
      Instruction i = Instruction(false, "go", 7);

      CPPUNIT_ASSERT(i.action == false);
      CPPUNIT_ASSERT(i.name == "go");
      CPPUNIT_ASSERT(i.line == 7);
    }

    // --------------------
    // test_is_action
    // --------------------

    void test_is_action() {
      Instruction i = Instruction();

      CPPUNIT_ASSERT(i.is_action() == true);
    }

    // --------------------
    // test_is_action2
    // --------------------

    void test_is_action2() {
      Instruction i = Instruction(true, "hop");

      CPPUNIT_ASSERT(i.is_action() == true);
    }

    // --------------------
    // test_is_action3
    // --------------------

    void test_is_action3() {
      Instruction i = Instruction(false, "go", 7);

      CPPUNIT_ASSERT(i.is_action() == false);
    }

    // --------------------
    // test_get_name
    // --------------------

    void test_get_name() {
      Instruction i = Instruction();

      CPPUNIT_ASSERT(i.get_name() == "left");
    }

    // --------------------
    // test_get_name2
    // --------------------

    void test_get_name2() {
      Instruction i = Instruction(true, "hop");

      CPPUNIT_ASSERT(i.get_name() == "hop");
    }

    // --------------------
    // test_get_name3
    // --------------------

    void test_get_name3() {
      Instruction i = Instruction(false, "go", 7);

      CPPUNIT_ASSERT(i.get_name() == "go");
    }

    // --------------------
    // test_get_line
    // --------------------

    void test_get_line() {
      Instruction i = Instruction();

      CPPUNIT_ASSERT(i.get_line() == -1);
    }

    // --------------------
    // test_get_line2
    // --------------------

    void test_get_line2() {
      Instruction i = Instruction(true, "hop");

      CPPUNIT_ASSERT(i.get_line() == -1);
    }

    // --------------------
    // test_get_line3
    // --------------------

    void test_get_line3() {
      Instruction i = Instruction(false, "go", 7);

      CPPUNIT_ASSERT(i.get_line() == 7);
    }

/*
    // --------------------
    // test_get_character_species
    // --------------------

    void test_get_character_species() {
      Species s = Food();

      CPPUNIT_ASSERT(s.get_character() == 'f');
    }

    // --------------------
    // test_get_character_species2
    // --------------------

    void test_get_character_species2() {
      Species s = Hopper();

      CPPUNIT_ASSERT(s.get_character() == 'h');
    }

    // --------------------
    // test_get_character_species3
    // --------------------

    void test_get_character_species3() {
      Species s = Rover();

      CPPUNIT_ASSERT(s.get_character() == 'r');
    }
*/

    // --------------------
    // test_food
    // --------------------

    void test_food() {
      Food f = Food();

      CPPUNIT_ASSERT((int)f.program.size() == 2);
      CPPUNIT_ASSERT(f.character == 'f');
    }

    // --------------------
    // test_food2
    // --------------------

    void test_food2() {
      Food f = Food();

      f.program[0] = Instruction(true, "right");

      CPPUNIT_ASSERT((int)f.program.size() == 2);
      CPPUNIT_ASSERT(f.character == 'f');
    }

    // --------------------
    // test_food3
    // --------------------

    void test_food3() {
      Food f = Food();

      f.program.push_back(Instruction());

      CPPUNIT_ASSERT((int)f.program.size() == 3);
      CPPUNIT_ASSERT(f.character == 'f');
    }

    // --------------------
    // test_food_get_character
    // --------------------

    void test_food_get_character() {
      Food f = Food();

      CPPUNIT_ASSERT(f.get_character() == 'f');
    }

    // --------------------
    // test_food_get_character2
    // --------------------

    void test_food_get_character2() {
      Food f = Food();

      f.character = 'q';

      CPPUNIT_ASSERT(f.get_character() == 'q');
    }

    // --------------------
    // test_hopper
    // --------------------

    void test_hopper() {
      Hopper h = Hopper();

      CPPUNIT_ASSERT((int)h.program.size() == 2);
      CPPUNIT_ASSERT(h.character == 'h');
    }

    // --------------------
    // test_hopper2
    // --------------------

    void test_hopper2() {
      Hopper h = Hopper();

      h.program[0] = Instruction(false, "go", 1);

      CPPUNIT_ASSERT((int)h.program.size() == 2);
      CPPUNIT_ASSERT(h.character == 'h');
    }

    // --------------------
    // test_hopper3
    // --------------------

    void test_hopper3() {
      Hopper h = Hopper();

      h.program.push_back(Instruction());

      CPPUNIT_ASSERT((int)h.program.size() == 3);
      CPPUNIT_ASSERT(h.character == 'h');
    }

    // --------------------
    // test_hopper_get_character
    // --------------------

    void test_hopper_get_character() {
      Hopper h = Hopper();

      CPPUNIT_ASSERT(h.get_character() == 'h');
    }

    // --------------------
    // test_hopper_get_character2
    // --------------------

    void test_hopper_get_character2() {
      Hopper h = Hopper();

      h.character = 'q';

      CPPUNIT_ASSERT(h.get_character() == 'q');
    }

    // --------------------
    // test_rover
    // --------------------

    void test_rover() {
      Rover r = Rover();

      CPPUNIT_ASSERT((int)r.program.size() == 11);
      CPPUNIT_ASSERT(r.character == 'r');
    }

    // --------------------
    // test_rover2
    // --------------------

    void test_rover2() {
      Rover r = Rover();

      r.program[9] = Instruction(false, "go", 0);

      CPPUNIT_ASSERT((int)r.program.size() == 11);
      CPPUNIT_ASSERT(r.character == 'r');
    }

    // --------------------
    // test_rover3
    // --------------------

    void test_rover3() {
      Rover r = Rover();

      r.program.push_back(Instruction(false, "go", 0));

      CPPUNIT_ASSERT((int)r.program.size() == 12);
      CPPUNIT_ASSERT(r.character == 'r');
    }

    // --------------------
    // test_rover_get_character
    // --------------------

    void test_rover_get_character() {
      Rover r = Rover();

      CPPUNIT_ASSERT(r.get_character() == 'r');
    }

    // --------------------
    // test_rover_get_character2
    // --------------------

    void test_rover_get_character2() {
      Rover r = Rover();

      r.character = 'q';

      CPPUNIT_ASSERT(r.get_character() == 'q');
    }

    // --------------------
    // test_trap
    // --------------------

    void test_trap() {
      Trap t = Trap();

      CPPUNIT_ASSERT((int)t.program.size() == 5);
      CPPUNIT_ASSERT(t.character == 't');
    }

    // --------------------
    // test_trap2
    // --------------------

    void test_trap2() {
      Trap t = Trap();

      t.program[4] = Instruction();

      CPPUNIT_ASSERT((int)t.program.size() == 5);
      CPPUNIT_ASSERT(t.character == 't');
    }

    // --------------------
    // test_trap3
    // --------------------

    void test_trap3() {
      Trap t = Trap();

      t.program.push_back(Instruction());

      CPPUNIT_ASSERT((int)t.program.size() == 6);
      CPPUNIT_ASSERT(t.character == 't');
    }

    // --------------------
    // test_trap_get_character
    // --------------------

    void test_trap_get_character() {
      Trap t = Trap();

      CPPUNIT_ASSERT(t.get_character() == 't');
    }

    // --------------------
    // test_trap_get_character2
    // --------------------

    void test_trap_get_character2() {
      Trap t = Trap();

      t.character = 'q';

      CPPUNIT_ASSERT(t.get_character() == 'q');
    }

    // --------------------
    // test_best
    // --------------------

    void test_best() {
      Best b = Best();

      CPPUNIT_ASSERT((int)b.program.size() == 9);
      CPPUNIT_ASSERT(b.character == 'b');
    }

    // --------------------
    // test_best2
    // --------------------

    void test_best2() {
      Best b = Best();

      b.program[4] = Instruction();

      CPPUNIT_ASSERT((int)b.program.size() == 9);
      CPPUNIT_ASSERT(b.character == 'b');
    }

    // --------------------
    // test_best3
    // --------------------

    void test_best3() {
      Best b = Best();

      b.program.push_back(Instruction());
      CPPUNIT_ASSERT((int)b.program.size() == 10);
      CPPUNIT_ASSERT(b.character == 'b');
    }

    // --------------------
    // test_best_get_character
    // --------------------

    void test_best_get_character() {
      Best b = Best();

      CPPUNIT_ASSERT(b.get_character() == 'b');
    }

    // --------------------
    // test_best_get_character2
    // --------------------

    void test_best_get_character2() {
      Best b = Best();

      b.character = 'q';

      CPPUNIT_ASSERT(b.get_character() == 'q');
    }

    // --------------------
    // test_creature_sp
    // --------------------

    void test_creature_sp() {
      Rover r = Rover();
      Creature c = Creature(&r, 7, 5, WEST);
      std::pair<int, int> cc(7, 5);

      CPPUNIT_ASSERT(c.coordinates.first == cc.first);
      CPPUNIT_ASSERT(c.coordinates.second == cc.second);
      CPPUNIT_ASSERT(c.pc == 0);
      CPPUNIT_ASSERT(c.direction == WEST);
    }

    // --------------------
    // test_creature_copy
    // --------------------

    void test_creature_copy() {
      Rover r = Rover();
      Creature c = Creature(&r, 7, 5, WEST);
      Creature c2 = Creature(c);
      std::pair<int, int> cc(7, 5);

      CPPUNIT_ASSERT(c2.coordinates.first == c.coordinates.first);
      CPPUNIT_ASSERT(c2.coordinates.second == c.coordinates.second);
      CPPUNIT_ASSERT(c2.pc == c.pc);
      CPPUNIT_ASSERT(c2.direction == c.direction);
    }

    // --------------------
    // test_action
    // --------------------

    void test_action() {
      Food food = Food();
      Hopper hopper = Hopper();

      std::vector<std::vector<char> > board;
      board.resize(9);
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 10; ++j) {
          board[i].push_back('.');
        }
      }

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      std::map<std::pair<int, int>, Creature*> coordinates_creatures;
      coordinates_creatures[f1.coordinates] = &f1;
      coordinates_creatures[h1.coordinates] = &h1;
      coordinates_creatures[h2.coordinates] = &h2;
      coordinates_creatures[h3.coordinates] = &h3;
      coordinates_creatures[h4.coordinates] = &h4;
      coordinates_creatures[f2.coordinates] = &f2;

      f1.action(board, coordinates_creatures, &f1);

      CPPUNIT_ASSERT(f1.coordinates.first == 0);
      CPPUNIT_ASSERT(f1.coordinates.second == 0);
      CPPUNIT_ASSERT(f1.direction == 1);
      CPPUNIT_ASSERT(f1.pc == 1);
    }

    // --------------------
    // test_action2
    // --------------------

    void test_action2() {
      Food food = Food();
      Hopper hopper = Hopper();

      std::vector<std::vector<char> > board;
      board.resize(9);
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 10; ++j) {
          board[i].push_back('.');
        }
      }

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      std::map<std::pair<int, int>, Creature*> coordinates_creatures;
      coordinates_creatures[f1.coordinates] = &f1;
      coordinates_creatures[h1.coordinates] = &h1;
      coordinates_creatures[h2.coordinates] = &h2;
      coordinates_creatures[h3.coordinates] = &h3;
      coordinates_creatures[h4.coordinates] = &h4;
      coordinates_creatures[f2.coordinates] = &f2;

      f1.action(board, coordinates_creatures, &f1);
      h1.action(board, coordinates_creatures, &h1);

      CPPUNIT_ASSERT(f1.coordinates.first == 0);
      CPPUNIT_ASSERT(f1.coordinates.second == 0);
      CPPUNIT_ASSERT(f1.direction == 1);
      CPPUNIT_ASSERT(f1.pc == 1);

      CPPUNIT_ASSERT(h1.coordinates.first == 2);
      CPPUNIT_ASSERT(h1.coordinates.second == 3);
      CPPUNIT_ASSERT(h1.direction == NORTH);
      CPPUNIT_ASSERT(h1.pc == 1);
    }

    // --------------------
    // test_action3
    // --------------------

    void test_action3() {
      Food food = Food();
      Hopper hopper = Hopper();

      std::vector<std::vector<char> > board;
      board.resize(9);
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 10; ++j) {
          board[i].push_back('.');
        }
      }

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      std::map<std::pair<int, int>, Creature*> coordinates_creatures;
      coordinates_creatures[f1.coordinates] = &f1;
      coordinates_creatures[h1.coordinates] = &h1;
      coordinates_creatures[h2.coordinates] = &h2;
      coordinates_creatures[h3.coordinates] = &h3;
      coordinates_creatures[h4.coordinates] = &h4;
      coordinates_creatures[f2.coordinates] = &f2;

      f1.action(board, coordinates_creatures, &f1);
      h1.action(board, coordinates_creatures, &h1);
      h2.action(board, coordinates_creatures, &h2);

      CPPUNIT_ASSERT(f1.coordinates.first == 0);
      CPPUNIT_ASSERT(f1.coordinates.second == 0);
      CPPUNIT_ASSERT(f1.direction == 1);
      CPPUNIT_ASSERT(f1.pc == 1);

      CPPUNIT_ASSERT(h1.coordinates.first == 2);
      CPPUNIT_ASSERT(h1.coordinates.second == 3);
      CPPUNIT_ASSERT(h1.direction == NORTH);
      CPPUNIT_ASSERT(h1.pc == 1);

      CPPUNIT_ASSERT(h2.coordinates.first == 3);
      CPPUNIT_ASSERT(h2.coordinates.second == 5);
      CPPUNIT_ASSERT(h2.direction == EAST);
      CPPUNIT_ASSERT(h2.pc == 1);
    }

    // --------------------
    // test_creature_get_character
    // --------------------

    void test_creature_get_character() {
      Food f = Food();
      Creature c = Creature(&f, 0, 0, 0);

      CPPUNIT_ASSERT(c.get_character() == 'f');
    }

    // --------------------
    // test_creature_get_character2
    // --------------------

    void test_creature_get_character2() {
      Rover r = Rover();
      Creature c = Creature(&r, 0, 0, 0);

      CPPUNIT_ASSERT(c.get_character() == 'r');
    }

    // --------------------
    // test_get_coordinates
    // --------------------

    void test_get_coordinates() {
      Rover r = Rover();
      Creature c = Creature(&r, 0, 0, 0);

      std::pair<int, int> cc = c.get_coordinates();

      CPPUNIT_ASSERT(cc.first == 0);
      CPPUNIT_ASSERT(cc.second == 0);
    }

    // --------------------
    // test_get_coordinates2
    // --------------------

    void test_get_coordinates2() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 2, 1);

      std::pair<int, int> cc = c.get_coordinates();

      CPPUNIT_ASSERT(cc.first == 5);
      CPPUNIT_ASSERT(cc.second == 2);
    }

    // --------------------
    // test_get_coordinates3
    // --------------------

    void test_get_coordinates3() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 2, 1);

      c.coordinates.first = 4;
      c.coordinates.second = 1;

      std::pair<int, int> cc = c.get_coordinates();

      CPPUNIT_ASSERT(cc.first == 4);
      CPPUNIT_ASSERT(cc.second == 1);
    }

    // --------------------
    // test_ahead
    // --------------------

    void test_ahead() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, 0);

      std::pair<int, int> a = c.ahead(c.get_coordinates());

      CPPUNIT_ASSERT(a.first == 5);
      CPPUNIT_ASSERT(a.second == 3);
    }

    // --------------------
    // test_ahead2
    // --------------------

    void test_ahead2() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, 1);

      std::pair<int, int> a = c.ahead(c.get_coordinates());

      CPPUNIT_ASSERT(a.first == 4);
      CPPUNIT_ASSERT(a.second == 4);
    }

    // --------------------
    // test_ahead3
    // --------------------

    void test_ahead3() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, 2);

      std::pair<int, int> a = c.ahead(c.get_coordinates());

      CPPUNIT_ASSERT(a.first == 5);
      CPPUNIT_ASSERT(a.second == 5);
    }

    // --------------------
    // test_ahead4
    // --------------------

    void test_ahead4() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, 3);

      std::pair<int, int> a = c.ahead(c.get_coordinates());

      CPPUNIT_ASSERT(a.first == 6);
      CPPUNIT_ASSERT(a.second == 4);
    }

    // --------------------
    // test_get_direction
    // --------------------

    void test_get_direction() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, WEST);

      CPPUNIT_ASSERT(c.get_direction() == 0);
    }

    // --------------------
    // test_get_direction2
    // --------------------

    void test_get_direction2() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, EAST);

      CPPUNIT_ASSERT(c.get_direction() == 2);
    }

    // --------------------
    // test_get_direction3
    // --------------------

    void test_get_direction3() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, WEST);

      c.direction = SOUTH;

      CPPUNIT_ASSERT(c.get_direction() != WEST);
      CPPUNIT_ASSERT(c.get_direction() == SOUTH);
    }

    // --------------------
    // test_mod
    // --------------------

    void test_mod() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, WEST);

      CPPUNIT_ASSERT(c.mod(3, 4) == 3);
    }

    // --------------------
    // test_mod2
    // --------------------

    void test_mod2() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, WEST);

      CPPUNIT_ASSERT(c.mod(5, 4) == 1);
    }

    // --------------------
    // test_mod3
    // --------------------

    void test_mod3() {
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, WEST);

      CPPUNIT_ASSERT(c.mod(-1, 4) == 3);
    }

    // --------------------
    // test_darwin
    // --------------------

    void test_darwin() {
      Darwin d = Darwin(5, 6);

      CPPUNIT_ASSERT(d.rows == 5);
      CPPUNIT_ASSERT(d.cols == 6);
    }

    // --------------------
    // test_darwin2
    // --------------------

    void test_darwin2() {
      Darwin d = Darwin(3, 3);

      d.rows = 2;

      CPPUNIT_ASSERT(d.rows == 2);
      CPPUNIT_ASSERT(d.cols == 3);
    }

    // --------------------
    // test_darwin3
    // --------------------

    void test_darwin3() {
      Darwin d = Darwin(3, 3);

      CPPUNIT_ASSERT((int)d.board.size() == 4);
      CPPUNIT_ASSERT((int)d.board[0].size() == 5);
    }

    // --------------------
    // test_construct_board
    // --------------------

    void test_construct_board() {
      Darwin d = Darwin(8, 8);

      d.construct_board();

      CPPUNIT_ASSERT(d.board[0][0] == ' ');
      CPPUNIT_ASSERT(d.board[0][3] == '1');
    }

    // --------------------
    // test_construct_board2
    // --------------------

    void test_construct_board2() {
      Darwin d = Darwin(8, 8);

      d.construct_board();

      CPPUNIT_ASSERT(d.board[1][0] == '0');
    }

    // --------------------
    // test_construct_board3
    // --------------------

    void test_construct_board3() {
      Darwin d = Darwin(8, 8);

      d.construct_board();

      CPPUNIT_ASSERT(d.board[1][1] == ' ');
    }

    // --------------------
    // test_place_creature
    // --------------------

    void test_place_creature() {
      Darwin d = Darwin(8, 8);
      Rover r = Rover();
      Creature c = Creature(&r, 5, 4, 2);

      d.place_creature(&c, 5, 4);

      CPPUNIT_ASSERT(d.board[6][6] == 'r');
    }

    // --------------------
    // test_place_creature2
    // --------------------

    void test_place_creature2() {
      Darwin d = Darwin(8, 8);
      Food r = Food();
      Creature c = Creature(&r, 5, 4, 2);

      d.place_creature(&c, 5, 4);

      CPPUNIT_ASSERT(d.board[6][6] == 'f');
    }

    // --------------------
    // test_place_creature3
    // --------------------

    void test_place_creature3() {
      Darwin d = Darwin(8, 8);
      Trap r = Trap();
      Creature c = Creature(&r, 5, 4, 2);

      d.place_creature(&c, 5, 4);

      CPPUNIT_ASSERT(d.board[6][6] == 't');
    }

    // --------------------
    // test_step
    // --------------------

    void test_step() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();

      CPPUNIT_ASSERT(h1.coordinates.first == 2);
      CPPUNIT_ASSERT(h1.coordinates.second == 3);
    }

    // --------------------
    // test_step2
    // --------------------

    void test_step2() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();

      CPPUNIT_ASSERT(h1.direction == NORTH);
    }

    // --------------------
    // test_step3
    // --------------------

    void test_step3() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();
      d.step();

      CPPUNIT_ASSERT(f1.direction == WEST);
    }

    // --------------------
    // test_clear_board
    // --------------------

    void test_clear_board() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();

      d.clear_board();

      CPPUNIT_ASSERT(d.board[2][4] == '.');
    }

    // --------------------
    // test_redraw_board
    // --------------------

    void test_redraw_board() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();

      d.clear_board();

      d.redraw_board();

      CPPUNIT_ASSERT(d.board[3][5] == 'h');
    }

    // --------------------
    // test_redraw_board2
    // --------------------

    void test_redraw_board2() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();
      d.step();

      d.clear_board();

      d.redraw_board();

      CPPUNIT_ASSERT(d.board[2][5] == 'h');
    }

    // --------------------
    // test_redraw_board3
    // --------------------

    void test_redraw_board3() {
      Darwin d = Darwin(8, 8);
      Food food = Food();
      Hopper hopper = Hopper();

      Creature f1 = Creature(&food, 0, 0, EAST);
      Creature h1 = Creature(&hopper, 3, 3, NORTH);
      Creature h2 = Creature(&hopper, 3, 4, EAST);
      Creature h3 = Creature(&hopper, 4, 4, SOUTH);
      Creature h4 = Creature(&hopper, 4, 3, WEST);
      Creature f2 = Creature(&food, 7, 7, NORTH);

      d.place_creature(&f1, 0, 0);
      d.place_creature(&h1, 3, 3);
      d.place_creature(&h2, 3, 4);
      d.place_creature(&h3, 4, 4);
      d.place_creature(&h4, 4, 3);
      d.place_creature(&f2, 7, 7);

      d.step();
      d.step();
      d.step();

      d.clear_board();

      d.redraw_board();

      CPPUNIT_ASSERT(d.board[1][2] == 'f');
    }



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);

    CPPUNIT_TEST(test_instruction);
    CPPUNIT_TEST(test_instruction2);
    CPPUNIT_TEST(test_instruction3);

    CPPUNIT_TEST(test_is_action);
    CPPUNIT_TEST(test_is_action2);
    CPPUNIT_TEST(test_is_action3);

    CPPUNIT_TEST(test_get_name);
    CPPUNIT_TEST(test_get_name2);
    CPPUNIT_TEST(test_get_name3);

    CPPUNIT_TEST(test_get_line);
    CPPUNIT_TEST(test_get_line2);
    CPPUNIT_TEST(test_get_line3);


    CPPUNIT_TEST(test_food);
    CPPUNIT_TEST(test_food2);
    CPPUNIT_TEST(test_food3);
    CPPUNIT_TEST(test_food_get_character);
    CPPUNIT_TEST(test_food_get_character2);

    CPPUNIT_TEST(test_hopper);
    CPPUNIT_TEST(test_hopper2);
    CPPUNIT_TEST(test_hopper3);
    CPPUNIT_TEST(test_hopper_get_character);
    CPPUNIT_TEST(test_hopper_get_character2);

    CPPUNIT_TEST(test_rover);
    CPPUNIT_TEST(test_rover2);
    CPPUNIT_TEST(test_rover3);
    CPPUNIT_TEST(test_rover_get_character);
    CPPUNIT_TEST(test_rover_get_character2);

    CPPUNIT_TEST(test_trap);
    CPPUNIT_TEST(test_trap2);
    CPPUNIT_TEST(test_trap3);
    CPPUNIT_TEST(test_trap_get_character);
    CPPUNIT_TEST(test_trap_get_character2);

    CPPUNIT_TEST(test_best);
    CPPUNIT_TEST(test_best2);
    CPPUNIT_TEST(test_best3);
    CPPUNIT_TEST(test_best_get_character);
    CPPUNIT_TEST(test_best_get_character2);

    CPPUNIT_TEST(test_creature_sp);
    CPPUNIT_TEST(test_creature_copy);

    CPPUNIT_TEST(test_action);
    CPPUNIT_TEST(test_action2);
    CPPUNIT_TEST(test_action3);

    CPPUNIT_TEST(test_creature_get_character);
    CPPUNIT_TEST(test_creature_get_character2);

    CPPUNIT_TEST(test_get_coordinates);
    CPPUNIT_TEST(test_get_coordinates2);
    CPPUNIT_TEST(test_get_coordinates3);

    CPPUNIT_TEST(test_ahead);
    CPPUNIT_TEST(test_ahead2);
    CPPUNIT_TEST(test_ahead3);
    CPPUNIT_TEST(test_ahead4);

    CPPUNIT_TEST(test_get_direction);
    CPPUNIT_TEST(test_get_direction2);
    CPPUNIT_TEST(test_get_direction3);

    CPPUNIT_TEST(test_mod);
    CPPUNIT_TEST(test_mod2);
    CPPUNIT_TEST(test_mod3);

    CPPUNIT_TEST(test_darwin);
    CPPUNIT_TEST(test_darwin2);
    CPPUNIT_TEST(test_darwin3);

    CPPUNIT_TEST(test_construct_board);
    CPPUNIT_TEST(test_construct_board2);
    CPPUNIT_TEST(test_construct_board3);

    CPPUNIT_TEST(test_place_creature);
    CPPUNIT_TEST(test_place_creature2);
    CPPUNIT_TEST(test_place_creature3);

    CPPUNIT_TEST(test_step);
    CPPUNIT_TEST(test_step2);
    CPPUNIT_TEST(test_step3);

    CPPUNIT_TEST(test_clear_board);

    CPPUNIT_TEST(test_redraw_board);
    CPPUNIT_TEST(test_redraw_board2);
    CPPUNIT_TEST(test_redraw_board3);

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