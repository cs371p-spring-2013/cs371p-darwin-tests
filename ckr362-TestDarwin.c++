// ------------------------------------
// projects/allocator/TestAllocator.c++
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
#include <cassert>
#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <vector>	// vector
#include <map>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

// DOWNING TRICK

#define private public
#define class struct 

#include "Darwin.h"

using namespace std;

struct TestDarwin : CppUnit::TestFixture {
	
	void test_species_constructor_1() {
        // Programs
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        CPPUNIT_ASSERT(food._name == 'f');
        CPPUNIT_ASSERT(food._program == &food_program);
       
	}
    void test_species_constructor_2() {
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        CPPUNIT_ASSERT(rover._name == 'r');
        CPPUNIT_ASSERT(rover._program == &rover_program);
    }
    void test_species_constructor_3() {
        Species t('.', NULL);
        CPPUNIT_ASSERT(t._name == '.');
        CPPUNIT_ASSERT(t._program == NULL);
    }
    void test_species_infect_1() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);

        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        food.infect(hopper);
        CPPUNIT_ASSERT(food._name == 'h');
        CPPUNIT_ASSERT(hopper._program == food._program);
    }
    void test_species_infect_2() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);

        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        food.infect(food);
        CPPUNIT_ASSERT(food._name == 'f');
        CPPUNIT_ASSERT(food._program == food._program);
        CPPUNIT_ASSERT(hopper._program != food._program);
    }
    void test_species_infect_3() {
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);

        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);

        food.infect(rover);
        CPPUNIT_ASSERT(food._name == 'r');
        CPPUNIT_ASSERT(food._program == rover._program);
    }
    void test_species_query_1() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        pair<Instruction, int> temp = {LEFT, -1};
        CPPUNIT_ASSERT(food.query(0) == temp);
        temp = {GO, 0};
        CPPUNIT_ASSERT(food.query(1) == temp);


    }
    void test_species_query_2() {
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        pair<Instruction, int> temp = {IF_ENEMY, 9};
        CPPUNIT_ASSERT(rover.query(0) == temp);
        temp = {IF_EMPTY, 7};
        CPPUNIT_ASSERT(rover.query(1) == temp);
        temp = {IF_RANDOM, 5};
        CPPUNIT_ASSERT(rover.query(2) == temp);
        temp = {LEFT, -1};
        CPPUNIT_ASSERT(rover.query(3) == temp);
        temp = {GO, 0};
        CPPUNIT_ASSERT(rover.query(4) == temp);
        temp = {RIGHT, -1};
        CPPUNIT_ASSERT(rover.query(5) == temp);
        temp = {GO, 0};
        CPPUNIT_ASSERT(rover.query(6) == temp);
        temp = {HOP, -1};
        CPPUNIT_ASSERT(rover.query(7) == temp);
        temp = {GO, 0};
        CPPUNIT_ASSERT(rover.query(8) == temp);
        temp = {INFECT, -1};
        CPPUNIT_ASSERT(rover.query(9) == temp);
        temp = {GO, 0};
        CPPUNIT_ASSERT(rover.query(10) == temp);


        
    }
    void test_species_query_3() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);
        pair<Instruction, int> temp = {HOP, -1};
        CPPUNIT_ASSERT(hopper.query(0) == temp);
        temp = {GO, 0};
        CPPUNIT_ASSERT(hopper.query(1) == temp);
        
    }
    void test_species_name_1() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);
        CPPUNIT_ASSERT(hopper.species_name() == 'h');
    }
    void test_species_name_2() {
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        CPPUNIT_ASSERT(rover.species_name() == 'r');
        
    }
    void test_species_name_3() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        CPPUNIT_ASSERT(food.species_name() == 'f');
        
    }
    void test_creature_constructor_1() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        Creature c(food, 0);
        CPPUNIT_ASSERT(c._program_counter == 0);
        CPPUNIT_ASSERT(c._direction == 0);
        CPPUNIT_ASSERT(c._species._name == 'f');
        CPPUNIT_ASSERT(c._species._program == &food_program);
        CPPUNIT_ASSERT(c._turn == 0);

    }
    void test_creature_constructor_2() {
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        Creature c(rover, 0);
        CPPUNIT_ASSERT(c._program_counter == 0);
        CPPUNIT_ASSERT(c._direction == 0);
        CPPUNIT_ASSERT(c._species._name == 'r');
        CPPUNIT_ASSERT(c._species._program == &rover_program);
        CPPUNIT_ASSERT(c._turn == 0);
        
    }
    void test_creature_constructor_3() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);
        Creature c(hopper, 0);
        CPPUNIT_ASSERT(c._program_counter == 0);
        CPPUNIT_ASSERT(c._direction == 0);
        CPPUNIT_ASSERT(c._species._name == 'h');
        CPPUNIT_ASSERT(c._species._program == &hopper_program);
        CPPUNIT_ASSERT(c._turn == 0);
    }

    void test_creature_act_1() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);
        Creature c(hopper, 0);
        Instruction it = c.act(c, false, true, 0);
        CPPUNIT_ASSERT (it == HOP);
        it = c.act(c, false, true, 0);
        CPPUNIT_ASSERT(it == DO_NOTHING);
        it = c.act(c, false, true, 1);
        CPPUNIT_ASSERT(it == HOP);


    }
    void test_creature_act_2() {
        Program hopper_program(2);
        hopper_program[0] = {HOP, -1};
        hopper_program[1] = {GO, 0};
        Species hopper('h', &hopper_program);
        Creature h(hopper, 0);
        
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        Creature r(rover, 0);
        Instruction it = r.act(h, false, false, 0);
        CPPUNIT_ASSERT(it == INFECT);
        CPPUNIT_ASSERT(h.name() == 'r'); // infected
    }
    void test_creature_act_3() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature c(trap, 1);
        Instruction it = c.act(c, true, true, 0);
        CPPUNIT_ASSERT(it == LEFT);
        it = c.act(c, false, true, 1);
        CPPUNIT_ASSERT(it == LEFT);
        it = c.act(c, true, false, 2);
        CPPUNIT_ASSERT(it == LEFT);
        it = c.act(c, false, false, 3);
        CPPUNIT_ASSERT(it == LEFT);
    }
    void test_creature_infect_1() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature c(trap, 1);

        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        Creature r(rover, 0);

        c.infect(r._species);
        CPPUNIT_ASSERT(c._program_counter == 0);
        CPPUNIT_ASSERT(c._species._name == r._species._name);
        CPPUNIT_ASSERT(c._species._program == r._species._program);
    }
    void test_creature_infect_2() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature c(trap, 1);

        c.infect(c._species);
        CPPUNIT_ASSERT(c._program_counter == 0);
        CPPUNIT_ASSERT(c._species._name == c._species._name);
        CPPUNIT_ASSERT(c._species._program == c._species._program);
    }
    void test_creature_infect_3() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature t(trap, 1);

        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        Creature f(food, 0);

        f.infect(t._species);
        CPPUNIT_ASSERT(f._program_counter == 0);
        CPPUNIT_ASSERT(f._species._name == t._species._name);
        CPPUNIT_ASSERT(f._species._program == t._species._program);
    }
    void test_creature_my_direction_1() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature t(trap, 1);
        CPPUNIT_ASSERT(t.my_direction() == 1);

    }
    void test_creature_my_direction_2() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        Creature f(food, 0);
        CPPUNIT_ASSERT(f.my_direction() == 0);
    }
    void test_creature_my_direction_3() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature t(trap, 1);
        Instruction it = t.act(t, true, true, 0);
        CPPUNIT_ASSERT(it == LEFT);
        CPPUNIT_ASSERT(t.my_direction() == 0);
    }
    void test_creature_name_1() {
        Program trap_program(5);
        trap_program[0] = {IF_ENEMY, 3};
        trap_program[1] = {LEFT, -1};
        trap_program[2] = {GO, 0};
        trap_program[3] = {INFECT, -1};
        trap_program[4] = {GO, 0};
        Species trap('t', &trap_program);
        Creature t(trap, 1);
        CPPUNIT_ASSERT(t.name() == 't');
    }
    void test_creature_name_2() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        Creature f(food, 0);
        CPPUNIT_ASSERT(f.name() == 'f');
        
    }
    void test_creature_name_3() {
        Program rover_program(11);
        rover_program[0] = {IF_ENEMY, 9};
        rover_program[1] = {IF_EMPTY, 7};
        rover_program[2] = {IF_RANDOM, 5};
        rover_program[3] = {LEFT, -1};
        rover_program[4] = {GO, 0};
        rover_program[5] = {RIGHT, -1};
        rover_program[6] = {GO, 0};
        rover_program[7] = {HOP, -1};
        rover_program[8] = {GO, 0};
        rover_program[9] = {INFECT, -1};
        rover_program[10] = {GO, 0};
        Species rover('r', &rover_program);
        Creature r(rover, 0);
        CPPUNIT_ASSERT(r.name() == 'r');
        
    }
    void test_darwin_constructor_1() {
        Darwin d(1,1);
        CPPUNIT_ASSERT(d.board.size() == 1);
        CPPUNIT_ASSERT(d.creatures.size() == 0);
        CPPUNIT_ASSERT(d._r == 1 );
        CPPUNIT_ASSERT(d._c == 1);
        CPPUNIT_ASSERT(d.turn == 0);
    }
    void test_darwin_constructor_2() {
        Darwin d(1000,1000);
        CPPUNIT_ASSERT(d.board.size() == 1000000);
        CPPUNIT_ASSERT(d.creatures.size() == 0);
        CPPUNIT_ASSERT(d._r == 1000 );
        CPPUNIT_ASSERT(d._c == 1000);
        CPPUNIT_ASSERT(d.turn == 0);
    }
    void test_darwin_constructor_3() {
        Darwin d(1,1000);
        CPPUNIT_ASSERT(d.board.size() == 1000);
        CPPUNIT_ASSERT(d.creatures.size() == 0);
        CPPUNIT_ASSERT(d._r == 1 );
        CPPUNIT_ASSERT(d._c == 1000);
        CPPUNIT_ASSERT(d.turn == 0);
    }
    void test_darwin_add_creature_1() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(1,1);
        d.add_creature({0,0}, food, 0);
        CPPUNIT_ASSERT(d.board[0] == 'f');
        CPPUNIT_ASSERT(d.creatures[0].first.first == 0 &&
                d.creatures[0].first.second == 0);
        CPPUNIT_ASSERT(d.creatures.size() == 1);
        CPPUNIT_ASSERT(d.creatures[0].second._species._name == 'f');
        CPPUNIT_ASSERT(d.creatures[0].second._turn == 0);
    }
    void test_darwin_add_creature_2() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(10,1);
        CPPUNIT_ASSERT(d.board.size() == 10);
        d.add_creature({0,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[0].first.first == 0 &&
                d.creatures[0].first.second == 0);
        d.add_creature({2,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[1].first.first == 2 &&
                d.creatures[0].first.second == 0);
        d.add_creature({4,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[2].first.first == 4 &&
                d.creatures[0].first.second == 0);
        d.add_creature({5,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[3].first.first == 5 &&
                d.creatures[0].first.second == 0);
        d.add_creature({6,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[4].first.first == 6 &&
                d.creatures[0].first.second == 0);
        d.add_creature({8,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[5].first.first == 8 &&
                d.creatures[0].first.second == 0);
        d.add_creature({9,0}, food, 0);
        CPPUNIT_ASSERT(d.creatures[6].first.first == 9 &&
                d.creatures[0].first.second == 0);
        CPPUNIT_ASSERT(d.board[0] == 'f');
        CPPUNIT_ASSERT(d.board[2] == 'f');
        CPPUNIT_ASSERT(d.board[4] == 'f');
        CPPUNIT_ASSERT(d.board[5] == 'f');
        CPPUNIT_ASSERT(d.board[6] == 'f');
        CPPUNIT_ASSERT(d.board[8] == 'f');
        CPPUNIT_ASSERT(d.board[9] == 'f');
        CPPUNIT_ASSERT(d.creatures.size() == 7);
        CPPUNIT_ASSERT(d.creatures[0].second._turn == 0);
        CPPUNIT_ASSERT(d.creatures[1].second._turn == 0);
        CPPUNIT_ASSERT(d.creatures[2].second._turn == 0);
        CPPUNIT_ASSERT(d.creatures[3].second._turn == 0);
        CPPUNIT_ASSERT(d.creatures[4].second._turn == 0);
        CPPUNIT_ASSERT(d.creatures[5].second._turn == 0);
        CPPUNIT_ASSERT(d.creatures[6].second._turn == 0);



    }
    void test_darwin_add_creature_3() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        Darwin d(3,3);
        d.add_creature({0,0}, food, 1);
         CPPUNIT_ASSERT(d.creatures[0].first.first == 0 &&
                d.creatures[0].first.second == 0);
        d.add_creature({2,0}, food, 2);
         CPPUNIT_ASSERT(d.creatures[1].first.first == 2 &&
                d.creatures[1].first.second == 0);
        d.add_creature({0,2}, food, 3);
         CPPUNIT_ASSERT(d.creatures[2].first.first == 0 &&
                d.creatures[2].first.second == 2);
        d.add_creature({2,2}, food, 0);
         CPPUNIT_ASSERT(d.creatures[3].first.first == 2 &&
                d.creatures[3].first.second == 2);
        CPPUNIT_ASSERT(d.board.size() == 9);
        CPPUNIT_ASSERT(d.creatures.size() == 4);

    }
    void test_darwin_simulate_turn_1() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(1,1);
        d.add_creature({0,0}, food, 0);
    }
    void test_darwin_simulate_turn_2() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(10,1);
    }
    void test_darwin_simulate_turn_3() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        Darwin d(3,3);
    }
    void test_darwin_simulate_turns_1() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(1,1);
        d.add_creature({0,0}, food, 0);
    }
    void test_darwin_simulate_turns_2() {
        
    }
    void test_darwin_simulate_turns_3() {
        
    }
    void test_darwin_print_grid_1() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(1,1);
        d.add_creature({0,0}, food, 0);
        std::ostringstream curr;
        d.print_grid(curr);
        CPPUNIT_ASSERT(curr.str().compare("Turn = 0.\n  0\n0 f\n\n") == 0);
    }
    void test_darwin_print_grid_2() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(10,1);
        d.add_creature({0,0}, food, 0);
        d.add_creature({2,0}, food, 0);
        d.add_creature({4,0}, food, 0);
        d.add_creature({6,0}, food, 0);
        d.add_creature({8,0}, food, 0);
        std::ostringstream curr;
        d.print_grid(curr);
        CPPUNIT_ASSERT(curr.str().compare("Turn = 0.\n  0\n0 f\n1 .\n2 f\n3 .\n4 f\n5 .\n6 f\n7 .\n8 f\n9 .\n\n") == 0);
    }
    void test_darwin_print_grid_3() {
        Program food_program(2);
        food_program[0] = {LEFT, -1};
        food_program[1] = {GO, 0};
        Species food('f', &food_program);
        
        Darwin d(3,3);
        d.add_creature({0,0}, food, 0);
        d.add_creature({1,0}, food, 0);
        d.add_creature({2,0}, food, 0);
        d.add_creature({0,1}, food, 0);
        d.add_creature({1,1}, food, 0);
        d.add_creature({2,1}, food, 0);
        d.add_creature({0,2}, food, 0);
        d.add_creature({1,2}, food, 0);
        d.add_creature({2,2}, food, 0);
        std::ostringstream curr;
        d.print_grid(curr);
        CPPUNIT_ASSERT(curr.str().compare("Turn = 0.\n  012\n0 fff\n1 fff\n2 fff\n\n") == 0);
    }
	CPPUNIT_TEST_SUITE(TestDarwin);
    
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_constructor_2);
    CPPUNIT_TEST(test_species_constructor_3);
    CPPUNIT_TEST(test_species_infect_1);
    CPPUNIT_TEST(test_species_infect_2);
    CPPUNIT_TEST(test_species_infect_3);
    CPPUNIT_TEST(test_species_query_1);
    CPPUNIT_TEST(test_species_query_2);
    CPPUNIT_TEST(test_species_query_3);
    CPPUNIT_TEST(test_species_name_1);
    CPPUNIT_TEST(test_species_name_2);
    CPPUNIT_TEST(test_species_name_3);
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_creature_act_1);
    CPPUNIT_TEST(test_creature_act_2);
    CPPUNIT_TEST(test_creature_act_3);
    CPPUNIT_TEST(test_creature_infect_1);
    CPPUNIT_TEST(test_creature_infect_2);
    CPPUNIT_TEST(test_creature_infect_3);
    CPPUNIT_TEST(test_creature_my_direction_1);
    CPPUNIT_TEST(test_creature_my_direction_2);
    CPPUNIT_TEST(test_creature_my_direction_3);
    CPPUNIT_TEST(test_creature_name_1);
    CPPUNIT_TEST(test_creature_name_2);
    CPPUNIT_TEST(test_creature_name_3);
    CPPUNIT_TEST(test_darwin_constructor_1);
    CPPUNIT_TEST(test_darwin_constructor_2);
    CPPUNIT_TEST(test_darwin_constructor_3);
    CPPUNIT_TEST(test_darwin_add_creature_1);
    CPPUNIT_TEST(test_darwin_add_creature_2);
    CPPUNIT_TEST(test_darwin_add_creature_3);
    CPPUNIT_TEST(test_darwin_simulate_turn_1);
    CPPUNIT_TEST(test_darwin_simulate_turn_2);
    CPPUNIT_TEST(test_darwin_simulate_turn_3);
    CPPUNIT_TEST(test_darwin_simulate_turns_1);
    CPPUNIT_TEST(test_darwin_simulate_turns_2);
    CPPUNIT_TEST(test_darwin_simulate_turns_3);
    CPPUNIT_TEST(test_darwin_print_grid_1);
    CPPUNIT_TEST(test_darwin_print_grid_2);
    CPPUNIT_TEST(test_darwin_print_grid_3);

	CPPUNIT_TEST_SUITE_END();
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}