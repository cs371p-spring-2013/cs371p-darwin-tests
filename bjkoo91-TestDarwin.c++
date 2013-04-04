// ------------------------------
// projects/darwin/TestDarwin.c++
// ------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUIT_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {
    // ----------
    // Game::Game
    // ----------

    void test_game_1 () {
        Game x (1, 1, 1);
        CPPUNIT_ASSERT (x.grid.size () == 1);
        CPPUNIT_ASSERT (x.grid[0].size () == 1);
        CPPUNIT_ASSERT (x.num_creatures == 0);
    }

    void test_game_2 () {
        Game x (1000, 1000, 1000);
        CPPUNIT_ASSERT (x.grid.size () == 1000);
        CPPUNIT_ASSERT (x.grid[0].size () == 1000);
        CPPUNIT_ASSERT (x.num_creatures == 0);
    }

    void test_game_3 () {
        Game x (1, 100, 1000);
        CPPUNIT_ASSERT (x.grid.size () == 1);
        CPPUNIT_ASSERT (x.grid[0].size () == 100);
        CPPUNIT_ASSERT (x.num_creatures == 0);
    }

    // -----------------
    // Game::print_board
    // -----------------

    void test_print_board_1 () {
        Game x (1, 1, 0);
        std::ostringstream w;
        x.print_board (w);
        CPPUNIT_ASSERT (w.str () == "Turn = 0.\n  0\n0 .\n\n");
    }

    void test_print_board_2 () {
        Game x (1, 1, 0);
        Creature c (food);
        x.grid[0][0].cr = &c;
        x.turn = 10;
        std::ostringstream w;
        x.print_board (w);
        CPPUNIT_ASSERT (w.str () == "Turn = 10.\n  0\n0 f\n\n");
    }

    void test_print_board_3 () {
        Game x (1, 10, 0);
        Creature c (hopper);
        x.grid[0][5].cr = &c;
        x.turn = 5;
        std::ostringstream w;
        x.print_board (w);
        CPPUNIT_ASSERT (w.str () == "Turn = 5.\n  0123456789\n0 .....h....\n\n");
    }

    // ------------------
    // Game::add_creature
    // ------------------

    void test_add_creature_1 () {
        Game x (1, 1, 1);
        bool added = x.add_creature (food, N, 0, 0);
        CPPUNIT_ASSERT (added);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == food);
        CPPUNIT_ASSERT (x.grid[0][0].dir == N);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 0);
    }

    void test_add_creature_2 () {
        Game x (10, 10, 1);
        bool added = x.add_creature (rover, S, 5, 7);
        CPPUNIT_ASSERT (added);
        CPPUNIT_ASSERT (x.grid[0][0].cr == NULL);
        CPPUNIT_ASSERT (x.grid[5][7].cr->type == rover);
        CPPUNIT_ASSERT (x.grid[5][7].dir == S);
        CPPUNIT_ASSERT (x.grid[5][7].turn == 0);
    }

    void test_add_creature_3 () {
        Game x (1, 10, 10);
        bool added;
        for (int i = 0; i < 10; ++i) {
            added = x.add_creature (trap, W, 0, i);
            CPPUNIT_ASSERT (added);
            CPPUNIT_ASSERT (x.grid[0][i].cr->type == trap);
            CPPUNIT_ASSERT (x.grid[0][i].dir == W);
            CPPUNIT_ASSERT (x.grid[0][i].turn == 0);
        }
    }

    // -----------------
    // Game::take_a_turn
    // -----------------

    void test_take_a_turn_1 () {
        Game x (1, 1, 1);
        x.add_creature (food, N, 0, 0);
        x.take_a_turn ();
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == food);
        CPPUNIT_ASSERT (x.grid[0][0].dir == W);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
    }
    
    void test_take_a_turn_2 () {
        Game x (10, 10, 10);
        for (int i = 0; i < 10; ++i)
            x.add_creature (trap, N, 0, i);
        x.take_a_turn ();
        for (int i = 0; i < 10; ++i) {
            CPPUNIT_ASSERT (x.grid[0][i].cr->type == trap);
            CPPUNIT_ASSERT (x.grid[0][i].dir == W);
            CPPUNIT_ASSERT (x.grid[0][i].turn == 1);
        }
    }

    void test_take_a_turn_3 () {
        Game x (1, 10, 1);
        x.add_creature (hopper, E, 0, 0);
        for (int i = 0; i < 5; ++i)
            x.take_a_turn ();
        CPPUNIT_ASSERT (x.grid[0][0].cr == NULL);
        CPPUNIT_ASSERT (x.grid[0][5].cr->type == hopper);
        CPPUNIT_ASSERT (x.grid[0][5].dir == E);
        CPPUNIT_ASSERT (x.grid[0][5].turn == 5);
    }

    // -------------------------
    // Game::process_instruction
    // -------------------------

    void test_process_instruction_1 () {
        Game x (1, 10, 1);
        x.add_creature (rover, E, 0, 5);
        struct instr_set instr = {if_empty, 5};
        bool done = x.process_instruction (*x.grid[0][5].cr, instr, 0, 5);
        CPPUNIT_ASSERT (!done);
        CPPUNIT_ASSERT (x.grid[0][5].cr->type == rover);
        CPPUNIT_ASSERT (x.grid[0][5].dir == E);
        CPPUNIT_ASSERT (x.grid[0][5].turn == 0);
        CPPUNIT_ASSERT (x.grid[0][5].cr->pc == 5);
    }

    void test_process_instruction_2 () {
        Game x (1, 10, 1);
        x.add_creature (rover, E, 0, 5);
        struct instr_set instr = {hop, 100};
        bool done = x.process_instruction (*x.grid[0][5].cr, instr, 0, 5);
        CPPUNIT_ASSERT (done);
        CPPUNIT_ASSERT (x.grid[0][5].cr == NULL);
        CPPUNIT_ASSERT (x.grid[0][6].cr->type == rover);
        CPPUNIT_ASSERT (x.grid[0][6].dir == E);
        CPPUNIT_ASSERT (x.grid[0][6].turn == 1);
        CPPUNIT_ASSERT (x.grid[0][6].cr->pc == 1);
    }

    void test_process_instruction_3 () {
        Game x (1, 10, 1);
        x.add_creature (rover, E, 0, 5);
        struct instr_set instr = {infect, 100};
        bool done = x.process_instruction (*x.grid[0][5].cr, instr, 0, 5);
        CPPUNIT_ASSERT (done);
        CPPUNIT_ASSERT (x.grid[0][5].cr->type == rover);
        CPPUNIT_ASSERT (x.grid[0][5].dir == E);
        CPPUNIT_ASSERT (x.grid[0][5].turn == 1);
        CPPUNIT_ASSERT (x.grid[0][5].cr->pc == 1);
        CPPUNIT_ASSERT (x.grid[0][6].cr == NULL);
    }

    // ---------------
    // Game::get_front
    // ---------------

    void test_get_front_1 () {
        Game x (1, 2, 0);
        x.grid[0][0].dir = E;
        struct spot* check = x.get_front (0, 0);
        CPPUNIT_ASSERT (check == &x.grid[0][1]);
    }

    void test_get_front_2 () {
        Game x (1, 2, 0);
        x.grid[0][0].dir = N;
        struct spot* check = x.get_front (0, 0);
        CPPUNIT_ASSERT (check == NULL);
    }

    void test_get_front_3 () {
        Game x (1, 5, 0);
        for (int i = 0; i < 5; ++i)
            x.grid[0][i].dir = E;
        struct spot* check;
        for (int i = 0; i < 5; ++i) {
            check = x.get_front (0, i);
            if (i < 4)
                CPPUNIT_ASSERT (check == &x.grid[0][i+1]);
            else
                CPPUNIT_ASSERT (check == NULL);
        }
    }

    // --------------
    // Game::is_enemy
    // --------------

    void test_is_enemy_1 () {
        Game x (1, 1, 0);
        x.add_creature (rover, N, 0, 0);
        bool check = x.is_enemy (0, 0);
        CPPUNIT_ASSERT (!check);
    }

    void test_is_enemy_2 () {
        Game x (1, 2, 2);
        x.add_creature (rover, E, 0, 0);
        x.add_creature (rover, W, 0, 1);
        bool check = x.is_enemy (0, 0);
        CPPUNIT_ASSERT (!check);
        check = x.is_enemy (0, 1);
        CPPUNIT_ASSERT (!check);
    }

    void test_is_enemy_3 () {
        Game x (1, 2, 2);
        x.add_creature (rover, E, 0, 0);
        x.add_creature (trap, W, 0, 1);
        bool check = x.is_enemy (0, 0);
        CPPUNIT_ASSERT (check);
        check = x.is_enemy (0, 1);
        CPPUNIT_ASSERT (check);
    }

    // -------------
    // Game::is_wall
    // -------------

    void test_is_wall_1 () {
        Game x (1, 1, 0);
        x.add_creature (rover, N, 0, 0);
        bool check = x.is_wall (0, 0);
        CPPUNIT_ASSERT (check);
    }

    void test_is_wall_2 () {
        Game x (1, 2, 2);
        x.add_creature (rover, E, 0, 0);
        bool check = x.is_wall (0, 0);
        CPPUNIT_ASSERT (!check);
    }

    void test_is_wall_3 () {
        Game x (1, 2, 2);
        x.add_creature (rover, E, 0, 0);
        x.add_creature (rover, W, 0, 1);
        bool check = x.is_wall (0, 0);
        CPPUNIT_ASSERT (!check);
        check = x.is_wall (0, 1);
        CPPUNIT_ASSERT (!check);
    }

    // --------------
    // Game::is_empty
    // --------------

    void test_is_empty_1 () {
        Game x (1, 1, 0);
        x.add_creature (rover, N, 0, 0);
        bool check = x.is_empty (0, 0);
        CPPUNIT_ASSERT (!check);
    }

    void test_is_empty_2 () {
        Game x (1, 2, 2);
        x.add_creature (rover, E, 0, 0);
        bool check = x.is_empty (0, 0);
        CPPUNIT_ASSERT (check);
    }

    void test_is_empty_3 () {
        Game x (1, 2, 2);
        x.add_creature (rover, E, 0, 0);
        x.add_creature (rover, W, 0, 1);
        bool check = x.is_empty (0, 0);
        CPPUNIT_ASSERT (!check);
        check = x.is_empty (0, 1);
        CPPUNIT_ASSERT (!check);
    }

    // ---------------
    // Game::is_random
    // ---------------

    void test_is_random_1 () {
        srand (0);
        Game x (1, 1, 0);
        int count_true = 0;
        int count_false = 0;
        for (int i = 0; i < 1000; ++i) {
            if (x.is_random ())
                ++count_true;
            else
                ++count_false;
        }
        CPPUNIT_ASSERT (count_true != 0);
        CPPUNIT_ASSERT (count_false != 0);
    }

    void test_is_random_2 () {
        srand (0);
        int count_true_t = 0;
        int count_false_t = 0;
        for (int i = 0; i < 100; ++i) {
            if (rand () % 2 != 0)
                ++count_true_t;
            else
                ++count_false_t;
        }
        srand (0);
        Game x (1, 1, 0);
        int count_true = 0;
        int count_false = 0;
        for (int i = 0; i < 100; ++i) {
            if (x.is_random ())
                ++count_true;
            else
                ++count_false;
        }
        CPPUNIT_ASSERT (count_true == count_true_t);
        CPPUNIT_ASSERT (count_false == count_false_t);
    }

    void test_is_random_3 () {
        srand (0);
        Game x (1, 1, 0);
        int seed;
        bool expected;
        for (int i = 0; i < 100; ++i) {
            seed = rand ();
            srand (seed);
            expected = (rand () % 2 != 0) ? true : false;
            srand (seed);
            CPPUNIT_ASSERT (expected == x.is_random ());
        }
    }

    // ---------
    // Game::hop
    // ---------

    void test_hop_1 () {
        Game x (1, 2, 1);
        x.add_creature (hopper, E, 0, 0);
        x.hop (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr == NULL);
        CPPUNIT_ASSERT (x.grid[0][1].cr->type == hopper);
        CPPUNIT_ASSERT (x.grid[0][1].dir == E);
        CPPUNIT_ASSERT (x.grid[0][1].turn == 1);
    }

    void test_hop_2 () {
        Game x (1, 1, 1);
        x.add_creature (hopper, E, 0, 0);
        x.hop (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == hopper);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
    }

    void test_hop_3 () {
        Game x (1, 10, 1);
        x.add_creature (hopper, E, 0, 0);
        for (int i = 0; i < 100; ++i) {
            if (i < 10)
                x.hop (0, i);
            else
                x.hop (0, 9);
        }
        CPPUNIT_ASSERT (x.grid[0][0].cr == NULL);
        CPPUNIT_ASSERT (x.grid[0][9].cr->type == hopper);
        CPPUNIT_ASSERT (x.grid[0][9].dir == E);
        CPPUNIT_ASSERT (x.grid[0][9].turn == 100);
    }

    // ----------
    // Game::left
    // ----------

    void test_left_1 () {
        Game x (1, 1, 1);
        x.add_creature (trap, N, 0, 0);
        x.left (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][0].dir == W);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
    }

    void test_left_2 () {
        Game x (1, 1, 1);
        x.add_creature (food, E, 0, 0);
        x.left (0, 0);
        x.left (0, 0);
        x.left (0, 0);
        x.left (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == food);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 4);
    }

    void test_left_3 () {
        Game x (1, 1, 1);
        x.add_creature (rover, S, 0, 0);
        for (int i = 0; i < 99; ++i)
            x.left (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == rover);
        CPPUNIT_ASSERT (x.grid[0][0].dir == W);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 99);
    }

    // -----------
    // Game::right
    // -----------

    void test_right_1 () {
        Game x (1, 1, 1);
        x.add_creature (trap, N, 0, 0);
        x.right (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
    }

    void test_right_2 () {
        Game x (1, 1, 1);
        x.add_creature (food, E, 0, 0);
        x.right (0, 0);
        x.right (0, 0);
        x.right (0, 0);
        x.right (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == food);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 4);
    }

    void test_right_3 () {
        Game x (1, 1, 1);
        x.add_creature (rover, S, 0, 0);
        for (int i = 0; i < 99; ++i)
            x.right (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == rover);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 99);
    }

    // ------------
    // Game::infect
    // ------------

    void test_infect_1 () {
        Game x (1, 2, 1);
        x.add_creature (trap, E, 0, 0);
        x.infect (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
        CPPUNIT_ASSERT (x.grid[0][1].cr == NULL);
    }

    void test_infect_2 () {
        Game x (1, 2, 2);
        x.add_creature (trap, E, 0, 0);
        x.add_creature (trap, E, 0, 1);
        x.grid[0][1].cr->pc = 100;
        x.infect (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
        CPPUNIT_ASSERT (x.grid[0][1].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][1].cr->pc == 100);
        CPPUNIT_ASSERT (x.grid[0][1].dir == E);
        CPPUNIT_ASSERT (x.grid[0][1].turn == 0);
    }

    void test_infect_3 () {
        Game x (1, 2, 2);
        x.add_creature (trap, E, 0, 0);
        x.add_creature (rover, E, 0, 1);
        x.grid[0][1].cr->pc = 100;
        x.infect (0, 0);
        CPPUNIT_ASSERT (x.grid[0][0].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][0].dir == E);
        CPPUNIT_ASSERT (x.grid[0][0].turn == 1);
        CPPUNIT_ASSERT (x.grid[0][1].cr->type == trap);
        CPPUNIT_ASSERT (x.grid[0][1].cr->pc == 0);
        CPPUNIT_ASSERT (x.grid[0][1].dir == E);
        CPPUNIT_ASSERT (x.grid[0][1].turn == 0);
    }

    // -------------
    // Species::food
    // -------------

    void test_food_1 () {
        struct instr_set instr = Species::food (0);
        CPPUNIT_ASSERT (instr.instr == left);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    void test_food_2 () {
        struct instr_set instr = Species::food (1);
        CPPUNIT_ASSERT (instr.instr == go);
        CPPUNIT_ASSERT (instr.line_num == 0);
    }

    void test_food_3 () {
        struct instr_set instr = Species::food (100);
        CPPUNIT_ASSERT (instr.instr == reset);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }
    
    // ---------------
    // Species::hopper
    // ---------------

    void test_hopper_1 () {
        struct instr_set instr = Species::hopper (0);
        CPPUNIT_ASSERT (instr.instr == hop);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    void test_hopper_2 () {
        struct instr_set instr = Species::hopper (1);
        CPPUNIT_ASSERT (instr.instr == go);
        CPPUNIT_ASSERT (instr.line_num == 0);
    }

    void test_hopper_3 () {
        struct instr_set instr = Species::hopper (100);
        CPPUNIT_ASSERT (instr.instr == reset);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    // --------------
    // Species::rover
    // --------------

    void test_rover_1 () {
        struct instr_set instr = Species::rover (5);
        CPPUNIT_ASSERT (instr.instr == right);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    void test_rover_2 () {
        struct instr_set instr = Species::rover (7);
        CPPUNIT_ASSERT (instr.instr == hop);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    void test_rover_3 () {
        struct instr_set instr = Species::rover (100);
        CPPUNIT_ASSERT (instr.instr == reset);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    // -------------
    // Species::trap
    // -------------

    void test_trap_1 () {
        struct instr_set instr = Species::trap (3);
        CPPUNIT_ASSERT (instr.instr == infect);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    void test_trap_2 () {
        struct instr_set instr = Species::trap (4);
        CPPUNIT_ASSERT (instr.instr == go);
        CPPUNIT_ASSERT (instr.line_num == 0);
    }

    void test_trap_3 () {
        struct instr_set instr = Species::trap (100);
        CPPUNIT_ASSERT (instr.instr == reset);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    // -------------
    // Species::best
    // -------------
    
    void test_best_1 () {
        struct instr_set instr = Species::best (7);
        CPPUNIT_ASSERT (instr.instr == go);
        CPPUNIT_ASSERT (instr.line_num == 0);
    }

    void test_best_2 () {
        struct instr_set instr = Species::best (19);
        CPPUNIT_ASSERT (instr.instr == if_enemy);
        CPPUNIT_ASSERT (instr.line_num == 27);
    }

    void test_best_3 () {
        struct instr_set instr = Species::best (100);
        CPPUNIT_ASSERT (instr.instr == reset);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    // ----------------
    // Species::program
    // ----------------

    void test_program_1 () {
        struct instr_set instr = Species::program (food, 1);
        CPPUNIT_ASSERT (instr.instr == go);
        CPPUNIT_ASSERT (instr.line_num == 0);
    }

    void test_program_2 () {
        struct instr_set instr = Species::program (rover, 7);
        CPPUNIT_ASSERT (instr.instr == hop);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    void test_program_3 () {
        struct instr_set instr = Species::program (hopper, 100);
        CPPUNIT_ASSERT (instr.instr == reset);
        CPPUNIT_ASSERT (instr.line_num == -1);
    }

    // ------------------
    // Creature::Creature
    // ------------------

    void test_creature_1 () {
        Creature x (food);
        CPPUNIT_ASSERT (x.type == food);
        CPPUNIT_ASSERT (x.pc == 0);
    }

    void test_creature_2 () {
        Creature x (rover);
        CPPUNIT_ASSERT (x.type == rover);
        CPPUNIT_ASSERT (x.pc == 0);   
    }

    void test_creature_3 () {
        Creature x (trap);
        CPPUNIT_ASSERT (x.type == trap);
        CPPUNIT_ASSERT (x.pc == 0);
    }

    // -----------------
    // Creature::getChar
    // -----------------

    void test_getChar_1 () {
        Creature x (food);
        char check = x.getChar ();
        CPPUNIT_ASSERT (check == 'f');
    }

    void test_getChar_2 () {
        Creature x (rover);
        char check = x.getChar ();
        CPPUNIT_ASSERT (check == 'r');
    }

    void test_getChar_3 () {
        Creature x (trap);
        char check = x.getChar ();
        CPPUNIT_ASSERT (check == 't');
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE (TestDarwin);
    CPPUNIT_TEST (test_game_1);
    CPPUNIT_TEST (test_game_2);
    CPPUNIT_TEST (test_game_3);
    CPPUNIT_TEST (test_print_board_1);
    CPPUNIT_TEST (test_print_board_2);
    CPPUNIT_TEST (test_print_board_3);
    CPPUNIT_TEST (test_add_creature_1);
    CPPUNIT_TEST (test_add_creature_2);
    CPPUNIT_TEST (test_add_creature_3);
    CPPUNIT_TEST (test_take_a_turn_1);
    CPPUNIT_TEST (test_take_a_turn_2);
    CPPUNIT_TEST (test_take_a_turn_3);
    CPPUNIT_TEST (test_process_instruction_1);
    CPPUNIT_TEST (test_process_instruction_2);
    CPPUNIT_TEST (test_process_instruction_3);
    CPPUNIT_TEST (test_get_front_1);
    CPPUNIT_TEST (test_get_front_2);
    CPPUNIT_TEST (test_get_front_3);
    CPPUNIT_TEST (test_is_enemy_1);
    CPPUNIT_TEST (test_is_enemy_2);
    CPPUNIT_TEST (test_is_enemy_3);
    CPPUNIT_TEST (test_is_wall_1);
    CPPUNIT_TEST (test_is_wall_2);
    CPPUNIT_TEST (test_is_wall_3);
    CPPUNIT_TEST (test_is_empty_1);
    CPPUNIT_TEST (test_is_empty_2);
    CPPUNIT_TEST (test_is_empty_3);
    CPPUNIT_TEST (test_is_random_1);
    CPPUNIT_TEST (test_is_random_2);
    CPPUNIT_TEST (test_is_random_3);
    CPPUNIT_TEST (test_hop_1);
    CPPUNIT_TEST (test_hop_2);
    CPPUNIT_TEST (test_hop_3);
    CPPUNIT_TEST (test_left_1);
    CPPUNIT_TEST (test_left_2);
    CPPUNIT_TEST (test_left_3);
    CPPUNIT_TEST (test_right_1);
    CPPUNIT_TEST (test_right_2);
    CPPUNIT_TEST (test_right_3);
    CPPUNIT_TEST (test_infect_1);
    CPPUNIT_TEST (test_infect_2);
    CPPUNIT_TEST (test_infect_3);
    CPPUNIT_TEST (test_food_1);
    CPPUNIT_TEST (test_food_2);
    CPPUNIT_TEST (test_food_3);
    CPPUNIT_TEST (test_hopper_1);
    CPPUNIT_TEST (test_hopper_2);
    CPPUNIT_TEST (test_hopper_3);
    CPPUNIT_TEST (test_rover_1);
    CPPUNIT_TEST (test_rover_2);
    CPPUNIT_TEST (test_rover_3);
    CPPUNIT_TEST (test_trap_1);
    CPPUNIT_TEST (test_trap_2);
    CPPUNIT_TEST (test_trap_3);
    CPPUNIT_TEST (test_best_1);
    CPPUNIT_TEST (test_best_2);
    CPPUNIT_TEST (test_best_3);
    CPPUNIT_TEST (test_program_1);
    CPPUNIT_TEST (test_program_2);
    CPPUNIT_TEST (test_program_3);
    CPPUNIT_TEST (test_creature_1);
    CPPUNIT_TEST (test_creature_2);
    CPPUNIT_TEST (test_creature_3);
    CPPUNIT_TEST (test_getChar_1);
    CPPUNIT_TEST (test_getChar_2);
    CPPUNIT_TEST (test_getChar_3);
    CPPUNIT_TEST_SUITE_END ();
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio (false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest (TestDarwin::suite ());
    tr.run ();

    cout << "Done." << endl;
    return 0;
}