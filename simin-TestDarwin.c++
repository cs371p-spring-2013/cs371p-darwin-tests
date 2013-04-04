// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

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
#include <map>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"

// -----------
// TestCollatz
// -----------

struct TestDarwin : CppUnit::TestFixture {
    //--------------------
    // Tests for Creature
    //--------------------
    void test_creature_construct_default() {
        Creature c;
        CPPUNIT_ASSERT(c.type == -1);
        CPPUNIT_ASSERT(c.direction == -1);
        CPPUNIT_ASSERT(c.move_counter == -1);
    }
 
    void test_creature_construct_param() {
        Creature c(FOOD, NORTH);
        CPPUNIT_ASSERT(c.type == FOOD);
        CPPUNIT_ASSERT(c.direction == NORTH);
        CPPUNIT_ASSERT(c.move_counter == 1);
    }
   
    void test_valid_move_1() {
        Creature c;
        c.move_counter = 2;
        CPPUNIT_ASSERT(c.valid_move(1) == false);
    }

    void test_valid_move_2() {
        Creature c;
        c.move_counter = 1;
        CPPUNIT_ASSERT(c.valid_move(1) == true);
    }

    void test_is_creature_1() {
        Creature c;
        CPPUNIT_ASSERT(c.is_creature() == false);
    }

    void test_is_creature_2() {
        Creature c(FOOD, NORTH);
        CPPUNIT_ASSERT(c.is_creature() == true);
    }

    void test_is_creature_3() {
        Creature c(FOOD, NORTH);
        c.type = -1;
        CPPUNIT_ASSERT(c.is_creature() == false);
    }
 
    void test_is_enemy_1() {
        Creature c1;
        Creature c2(FOOD, NORTH);
        CPPUNIT_ASSERT(c2.is_enemy(c1) == true);
    }

    void test_is_enemy_2() {
        Creature c1(FOOD, NORTH);
        Creature c2(TRAP, SOUTH);
        CPPUNIT_ASSERT(c2.is_enemy(c1) == true);
    }
  
    void test_is_enemy_3() {
        Creature c1(FOOD, WEST);
        Creature c2(FOOD, EAST);
        CPPUNIT_ASSERT(c2.is_enemy(c1) == false);
    }

    void test_turn_left_N() {
        Creature c1(FOOD, NORTH);
        c1.turn_left();
        CPPUNIT_ASSERT(c1.direction == WEST);
    }
    void test_turn_left_E() {
        Creature c1(FOOD, EAST);
        c1.turn_left();
        CPPUNIT_ASSERT(c1.direction == NORTH);
    }
    void test_turn_left_S() {
        Creature c1(FOOD, SOUTH);
        c1.turn_left();
        CPPUNIT_ASSERT(c1.direction == EAST);
    }
    void test_turn_left_W() {
        Creature c1(FOOD, WEST);
        c1.turn_left();
        CPPUNIT_ASSERT(c1.direction == SOUTH);
    } 
    void test_turn_right_N() {
        Creature c1(FOOD, NORTH);
        c1.turn_right();
        CPPUNIT_ASSERT(c1.direction == EAST);
    }
    void test_turn_right_E() {
        Creature c1(FOOD, EAST);
        c1.turn_right();
        CPPUNIT_ASSERT(c1.direction == SOUTH);
    }
    void test_turn_right_W() {
        Creature c1(FOOD, WEST);
        c1.turn_right();
        CPPUNIT_ASSERT(c1.direction == NORTH);
    }
    void test_turn_right_S() {
        Creature c1(FOOD, SOUTH);
        c1.turn_right();
        CPPUNIT_ASSERT(c1.direction == WEST);
    }

    void test_return_action_1() {
        Creature c1(FOOD, WEST);
        CPPUNIT_ASSERT(c1.return_action(false, false) == LEFT);
        CPPUNIT_ASSERT(c1.move_counter == 2);
    }

    void test_return_action_2() {
        Creature c1(HOPPER, WEST);
        CPPUNIT_ASSERT(c1.return_action(false, false) == -1);
        CPPUNIT_ASSERT(c1.move_counter == 2);
        CPPUNIT_ASSERT(c1.return_action(false, false) == -1);
        CPPUNIT_ASSERT(c1.move_counter == 3);
    }
 
    void test_return_action_3() {
        Creature c1(ROVER, EAST);
        CPPUNIT_ASSERT(c1.return_action(true, false) == INFECT);
        CPPUNIT_ASSERT(c1.move_counter == 2);
    }

    void test_get_infected_1() {
        Creature c1(TRAP, EAST);
        Creature c2(HOPPER, WEST);
        c2.get_infected(c1);
        CPPUNIT_ASSERT(c1.type == TRAP);
        CPPUNIT_ASSERT(c2.type == TRAP);
    }

    void test_convert_1() {
        Creature c;
        CPPUNIT_ASSERT((char) c == '.');
    }
 
    void test_convert_2() {
        Creature c(FOOD, EAST);
        CPPUNIT_ASSERT((char) c == 'f');
    }
    
   
    // ----------------
    // Tests for Board
    // ----------------
    void test_print_board_1() {
        std::ostringstream w;
        Board<1, 1> b;
        b.print_board(w);
//        std::cout << w.str();
        CPPUNIT_ASSERT(w.str() == "  0\n0 .\n\n");

    }

    void test_print_board_2() {
        std::ostringstream w;
        Board<4, 4> b;
        b.print_board(w);
        CPPUNIT_ASSERT(w.str() == "  0123\n0 ....\n1 ....\n2 ....\n3 ....\n\n");
    }

    void test_print_board_3() {
        std::ostringstream w;
        Board<4, 4> b;
        Creature f(FOOD, WEST);
        Creature h(HOPPER, NORTH);
        Creature r(ROVER, EAST);
        Creature t(TRAP, SOUTH);
        b.place_creature(f, 0, 0);
        b.place_creature(h, 1, 1);
        b.place_creature(r, 2, 2);
        b.place_creature(t, 3, 3);
        b.print_board(w);
        CPPUNIT_ASSERT(w.str() == "  0123\n0 f...\n1 .h..\n2 ..r.\n3 ...t\n\n");
    }

    void test_perform_action_1() {
        Board<4, 4> b;
        Creature f(FOOD, WEST);
        b.place_creature(f, 0, 0);
        int action = f.return_action(false, false);
        b.perform_action(f, action, 0, 0, 0, 1);
        CPPUNIT_ASSERT(f.direction == SOUTH);
        CPPUNIT_ASSERT(f.move_counter == 2);
    }

    void test_perform_action_2() {
        Board<4, 4> b;
        Creature h(HOPPER, EAST);
        b.place_creature(h, 0, 0);
        int action = h.return_action(false, true);
        b.perform_action(h, action, 0, 0, 0, 1);
        CPPUNIT_ASSERT((char)b.board[0][0] == '.');
        CPPUNIT_ASSERT((char)b.board[1][0] == 'h');
        CPPUNIT_ASSERT(h.move_counter == 2);
    }


    void test_perform_action_3() {
        Board<4, 4> b;
        Creature h(HOPPER, EAST);
        b.place_creature(h, 0, 0);
        int action = h.return_action(false, false);
        b.perform_action(h, action, 0, 0, 0, 1);
        CPPUNIT_ASSERT((char)b.board[0][0] == 'h');
        CPPUNIT_ASSERT((char)b.board[1][0] == '.');
        CPPUNIT_ASSERT(h.move_counter == 2);
    }

    void test_perform_action_4() {
        Board<4, 4> b;
        Creature t(TRAP, WEST);
        b.place_creature(t, 0, 0);
        int action = t.return_action(true, false);
        b.perform_action(t, action, 0, 0, 0, 1);
        CPPUNIT_ASSERT((char)b.board[0][0] == 't');
        CPPUNIT_ASSERT((char)b.board[1][0] == 't');
        CPPUNIT_ASSERT((char)t.move_counter == 2);
    }
 
    void test_make_move_1() {
        Board<4, 4> b;
        Creature f(FOOD, WEST);
        Creature h(HOPPER, NORTH);
        Creature r(ROVER, EAST);
        Creature t(TRAP, WEST);
        b.place_creature(f, 0, 0);
        b.place_creature(h, 1, 1);
        b.place_creature(r, 2, 2);
        b.place_creature(t, 3, 3);
        //b.print_board(std::cout);
        b.make_move(1);
        //b.print_board(std::cout);
        CPPUNIT_ASSERT(b.board[0][0].direction == SOUTH);
        CPPUNIT_ASSERT(b.board[1][1].is_creature() == false);
        CPPUNIT_ASSERT((char) b.board[0][1] == 'h');
        CPPUNIT_ASSERT(b.board[0][1].move_counter == 2);
        CPPUNIT_ASSERT(b.board[2][2].is_creature() == false);
        CPPUNIT_ASSERT((char) b.board[2][3] == 'r');
        CPPUNIT_ASSERT(b.board[2][3].move_counter == 2);
        CPPUNIT_ASSERT(b.board[3][3].direction == SOUTH);
 
    }

    void test_make_move_2() {
        Board<4, 4> b;
        Creature t1(TRAP, NORTH);
        b.place_creature(t1, 0, 0);
        Creature h1(HOPPER, NORTH);
        b.place_creature(h1, 0, 3);
        //b.print_board(std::cout);
        b.make_move(1);
        b.make_move(2);
        b.make_move(3);
        //std::cout << b.board[0][0].direction << std::endl;
        //b.print_board(std::cout);
        CPPUNIT_ASSERT((char) b.board[0][0] == 't');
        CPPUNIT_ASSERT((char) b.board[1][0] == 't');
        CPPUNIT_ASSERT(b.board[0][0].move_counter == 4);
        CPPUNIT_ASSERT(b.board[1][0].move_counter == 4);
        CPPUNIT_ASSERT(b.board[0][0].direction == SOUTH);
        CPPUNIT_ASSERT(b.board[1][0].direction == WEST);
    }

    void test_make_move_3() {
        Board<4, 4> b;
        Creature h(HOPPER, NORTH);
        b.place_creature(h, 0, 0);
        b.make_move(1);
        b.make_move(2);
        b.make_move(3);
        b.make_move(4);
        CPPUNIT_ASSERT((char) b.board[0][0] == 'h');
        CPPUNIT_ASSERT(b.board[0][0].direction == NORTH);
        CPPUNIT_ASSERT(b.board[0][0].move_counter == 5);
    }

    void test_get_target_x_1() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_x(NORTH, 0) == 0);
    }
    void test_get_target_x_2() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_x(SOUTH, 0) == 0);
    }
    void test_get_target_x_3() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_x(EAST, 0) == 1);
    }
    void test_get_target_x_4() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_x(WEST, 0) == -1);
    }

    void test_get_target_y_1() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_y(NORTH, 0) == -1);
    }
    void test_get_target_y_2() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_y(SOUTH, 0) == 1);
    }
    void test_get_target_y_3() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_y(WEST, 0) == 0);
    }
    void test_get_target_y_4() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.get_target_y(EAST, 0) == 0);
    }
   
    void test_check_enemy_1() {
        Board<3, 3> b;
        Creature f(FOOD, SOUTH);
        Creature r(ROVER, NORTH);
        b.place_creature(f, 0, 0);
        b.place_creature(r, 1, 0);
        CPPUNIT_ASSERT(b.check_enemy(r, b.get_target_x(NORTH, 0), b.get_target_y(NORTH, 1)) == true); 
    }

    void test_check_enemy_2() {
        Board<3, 3> b;
        Creature r0(ROVER, SOUTH);
        Creature r(ROVER, NORTH);
        b.place_creature(r0, 0, 0);
        b.place_creature(r, 1, 0);
        CPPUNIT_ASSERT(b.check_enemy(r, b.get_target_x(NORTH, 0), b.get_target_y(NORTH, 1)) == false); 
    }

    void test_check_enemy_3() {
        Board<3, 3> b;
        Creature c;
        Creature r(ROVER, NORTH);
        b.place_creature(c, 0, 0);
        b.place_creature(r, 1, 0);
        CPPUNIT_ASSERT(b.check_enemy(r, b.get_target_x(NORTH, 0), b.get_target_y(NORTH, 1)) == false); 
    }

    void test_check_empty_1() {
        Board<3, 3> b;
        CPPUNIT_ASSERT(b.check_empty(0, 1) == true);
        CPPUNIT_ASSERT(b.check_empty(-1, 2) == false);
        CPPUNIT_ASSERT(b.check_empty(2, -1) == false); 
    }
    void test_check_empty_2() {
        Board<3, 3> b;
        b.place_creature(Creature(), 0, 1);
        CPPUNIT_ASSERT(b.check_empty(0, 1) == true);
    }
    void test_check_empty_3() {
        Board<3, 3> b;
        b.place_creature(Creature(FOOD, 2), 0, 1);
        CPPUNIT_ASSERT(b.check_empty(0, 1) == false);
    }
    void test_place_creature_1() {
        Board<1,1> b;
        CPPUNIT_ASSERT((char) b.board[0][0] == '.');
        b.place_creature(Creature(FOOD, 0), 0, 0);
        CPPUNIT_ASSERT((char) b.board[0][0] == 'f');
    }

    void test_play_game() {
        

    } 
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_creature_construct_default);
    CPPUNIT_TEST(test_creature_construct_param);
    CPPUNIT_TEST(test_valid_move_1);
    CPPUNIT_TEST(test_valid_move_2);
    CPPUNIT_TEST(test_is_creature_1);
    CPPUNIT_TEST(test_is_creature_2);
    CPPUNIT_TEST(test_is_creature_3);
    CPPUNIT_TEST(test_is_enemy_1);
    CPPUNIT_TEST(test_is_enemy_2);
    CPPUNIT_TEST(test_is_enemy_3);
    CPPUNIT_TEST(test_turn_left_N);
    CPPUNIT_TEST(test_turn_left_E);
    CPPUNIT_TEST(test_turn_left_W);
    CPPUNIT_TEST(test_turn_left_S);
    CPPUNIT_TEST(test_turn_right_N);
    CPPUNIT_TEST(test_turn_right_E);
    CPPUNIT_TEST(test_turn_right_W);
    CPPUNIT_TEST(test_turn_right_S);
    CPPUNIT_TEST(test_return_action_1);
    CPPUNIT_TEST(test_return_action_2);
    CPPUNIT_TEST(test_return_action_3);
    CPPUNIT_TEST(test_get_infected_1);
    CPPUNIT_TEST(test_convert_1);
    CPPUNIT_TEST(test_convert_2);
    CPPUNIT_TEST(test_print_board_1);
    CPPUNIT_TEST(test_print_board_2);
    CPPUNIT_TEST(test_print_board_3);
    CPPUNIT_TEST(test_perform_action_1);
    CPPUNIT_TEST(test_perform_action_2);
    CPPUNIT_TEST(test_perform_action_3);
    CPPUNIT_TEST(test_perform_action_4);
    CPPUNIT_TEST(test_make_move_1);
    CPPUNIT_TEST(test_make_move_2);
    CPPUNIT_TEST(test_make_move_3);
    CPPUNIT_TEST(test_get_target_x_1);
    CPPUNIT_TEST(test_get_target_x_2);
    CPPUNIT_TEST(test_get_target_x_3);
    CPPUNIT_TEST(test_get_target_x_4);
    CPPUNIT_TEST(test_get_target_y_1);
    CPPUNIT_TEST(test_get_target_y_2);
    CPPUNIT_TEST(test_get_target_y_3);
    CPPUNIT_TEST(test_get_target_y_4);
    CPPUNIT_TEST(test_check_enemy_1);
    CPPUNIT_TEST(test_check_enemy_2);
    CPPUNIT_TEST(test_check_enemy_3);
    CPPUNIT_TEST(test_check_empty_1);
    CPPUNIT_TEST(test_check_empty_2);
    CPPUNIT_TEST(test_check_empty_3);
    CPPUNIT_TEST(test_place_creature_1);
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
    return 0;}

