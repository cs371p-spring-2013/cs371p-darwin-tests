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

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private public

#include "Darwin.h"



using namespace std;

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {

	// srand(0)

    // test whole game
/*
    void test_game() {
	int rows = 4;
        int columns = 5;
	Game game = Game(rows, columns);
	
	

	Species spe("food");
	//pair<int,int> loc (2, 2);
	Creature j(spe, 1, 2, 2);
        
    }
*/

    // ----
    // test Instruction class
    // ----

    void test_convert_instruction_1 () {
	Instruction inst("this", 3);
        pair<string, int> q = inst.convert_instruction();
        CPPUNIT_ASSERT((pair<string, int>("this", 3) == q));}

    void test_convert_instruction_2 () {
        Instruction inst = Instruction();
        pair<string, int> q = inst.convert_instruction();
        CPPUNIT_ASSERT((pair<string, int>("", -1) == q));}

    void test_convert_instruction_3 () {
	Instruction inst("this");
        pair<string, int> q = inst.convert_instruction();
        CPPUNIT_ASSERT((pair<string, int>("this", -1) == q));}

    // ------------------
    // test Program class
    // ------------------
    
    void test_curr_instruction_1 () {
	Program prg("food");
        Instruction inst = prg.curr_instruction(0);
        Instruction inst2("left", -1);
        CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_curr_instruction_2 () {
	Program prg("food");
        Instruction inst = prg.curr_instruction(1);
        Instruction inst2("go", 0);
        CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_curr_instruction_3 () {
	Program prg("rover");
        Instruction inst = prg.curr_instruction(2);
        Instruction inst2("if_random", 5);
        CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    // ------------------
    // test Species class
    // ------------------
   
    void test_curr_instr_1 () {
	Species spe("food");
        Instruction inst = spe.curr_instr(0);
        Instruction inst2("left", -1);
        CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_curr_instr_2 () {
	Species spe("rover");
        Instruction inst = spe.curr_instr(1);
        Instruction inst2("if_empty", 7);
        CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_curr_instr_3 () {
	Species spe("trap");
        Instruction inst = spe.curr_instr(3);
        Instruction inst2("infect", -1);
        CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_equals_1 () {
	Species spe("food");
        Species spe2("food");
        CPPUNIT_ASSERT(spe.equals(spe2));
    }

    void test_equals_2 () {
	Species spe("food");
        Species spe2("trap");
        CPPUNIT_ASSERT(!(spe.equals(spe2)));
    }
 
    void test_equals_3 () {
	Species spe = Species();
	Species spe2(".");
	CPPUNIT_ASSERT(spe.equals(spe2));
    }

    void test_species_rep_1 () {
	Species spe = Species();
	char k = spe.species_rep();
        CPPUNIT_ASSERT(k == '.');
    }

    void test_species_rep_2 () {
	Species spe("hopper");
	char k = spe.species_rep();
        CPPUNIT_ASSERT(k == 'h');
    }

    void test_species_rep_3 () {
	Species spe("best");
	char k = spe.species_rep();
        CPPUNIT_ASSERT(k == 'b');
    }

    // -------------------
    // test Creature class
    // -------------------

    void test_is_blank_1 () {
  	Creature c = Creature();
	CPPUNIT_ASSERT(c.is_blank());
    }

    void test_is_blank_2 () {
	Species f("food");
  	Creature c(f, 0, 3, 2);
	CPPUNIT_ASSERT(!c.is_blank());
    }

    void test_is_blank_3 () {
	Species spe = Species();
  	Creature c(spe, 0, 2, 1);
	CPPUNIT_ASSERT(c.is_blank());
    }

    void test_current_instruction_1 () {
	Species spe("food");
	Creature c(spe, 0, 2, 1);
	Instruction inst = c.current_instruction();
	Instruction inst2("left", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_current_instruction_2 () {
	Species spe("food");
	Creature c(spe, 0, 2, 1);
	c.action();
	Instruction inst = c.current_instruction();
	Instruction inst2("go", 0);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_current_instruction_3 () {
	Species spe("rover");
	Creature c(spe, 0, 2, 1);
	c.update_PC(2);
	Instruction inst = c.current_instruction();
	Instruction inst2("if_random", 5);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
    }

    void test_creature_hop_1 () {
	Species spe("hopper");
	Creature c(spe, 0, 2, 1);
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(1, 1) == k));
    }

    void test_creature_hop_2 () {
	Species spe("food");
	Creature c(spe, 1, 2, 1);
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(2, 2) == k));
    }

    void test_creature_hop_3 () {
	Species spe("rover");
	Creature c(spe, 2, 2, 1);
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(3, 1) == k));
    }

    void test_creature_left_1 () {
	Species spe("rover");
	Creature c(spe, 2, 2, 1);
	c.creature_left();
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(2, 2) == k));
    }

    void test_creature_left_2 () {
	Species spe("rover");
	Creature c(spe, 0, 2, 1);
	c.creature_left();
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(2, 0) == k));
    }

    void test_creature_left_3 () {
	Species spe("rover");
	Creature c(spe, 3, 2, 1);
	c.creature_left();
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(3, 1) == k));
    }

    void test_creature_right_1 () {
	Species spe("rover");
	Creature c(spe, 2, 2, 1);
	c.creature_right();
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(2, 0) == k));
    }

    void test_creature_right_2 () {
	Species spe("rover");
	Creature c(spe, 0, 2, 1);
	c.creature_right();
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(2, 2) == k));
    }

    void test_creature_right_3 () {
	Species spe("rover");
	Creature c(spe, 3, 2, 1);
	c.creature_right();
        pair<int, int> k = c.creature_hop();
	CPPUNIT_ASSERT((pair<int, int>(1, 1) == k));
    }

    void test_is_enemy_1 () {
	Species spe("rover");
	Creature c(spe, 1, 1, 1);
	Creature c2 = Creature();
	CPPUNIT_ASSERT(!(c.is_enemy(c2)));
    }

    void test_is_enemy_2 () {
	Species spe("rover");
	Species spe2("rover");
	Creature c(spe, 1, 1, 1);
	Creature c2(spe2, 1, 2, 1);
	CPPUNIT_ASSERT(!(c.is_enemy(c2)));
    }

    void test_is_enemy_3 () {
	Species spe("rover");
	Species spe2("food");
	Creature c(spe, 1, 1, 1);
	Creature c2(spe2, 1, 2, 1);
	CPPUNIT_ASSERT((c.is_enemy(c2)));
    }
	
    void test_update_enemy_1 () {
	Species spe("rover");
	Creature c(spe, 1, 2, 1);
	Species spe2("food");
	Creature c2(spe2, 0, 2, 2);
	Instruction inst = c2.current_instruction();
	Instruction inst2("left", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c2 = c2.update_enemy(c);
	inst = c2.current_instruction();
	Instruction inst3("if_enemy", 9);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_update_enemy_2 () {
	Species spe("food");
	Creature c(spe, 1, 2, 1);
	Species spe2("rover");
	Creature c2(spe2, 0, 2, 2);
	Instruction inst = c2.current_instruction();
	Instruction inst2("if_enemy", 9);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c2 = c2.update_enemy(c);
	inst = c2.current_instruction();
	Instruction inst3("left", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_update_enemy_3 () {
	Species spe("hopper");
	Creature c(spe, 1, 2, 1);
	Species spe2("food");
	Creature c2(spe2, 0, 2, 2);
	Instruction inst = c2.current_instruction();
	Instruction inst2("left", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c2 = c2.update_enemy(c);
	inst = c2.current_instruction();
	Instruction inst3("hop", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_action_1 () {
	Species spe("food");
	Creature c(spe, 1, 2, 1);
	Instruction inst = c.current_instruction();
	Instruction inst2("left", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c.action();
	inst = c.current_instruction();
	Instruction inst3("go", 0);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_action_2 () {
	Species spe("rover");
	Creature c(spe, 1, 2, 1);
	Instruction inst = c.current_instruction();
	Instruction inst2("if_enemy", 9);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c.action();
	inst = c.current_instruction();
	Instruction inst3("if_empty", 7);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_action_3 () {
	Species spe("rover");
	Creature c(spe, 1, 2, 1);
	c.update_PC(2);
	Instruction inst = c.current_instruction();
	Instruction inst2("if_random", 5);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c.action();
	inst = c.current_instruction();
	Instruction inst3("left", -1);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_loc_in_front_1 () {
	Species spe("rover");
	Creature c(spe, 1, 2, 1);
	pair<int, int> k = c.loc_in_front();
	CPPUNIT_ASSERT((k == pair<int,int>(2,2)));
    }

    void test_loc_in_front_2 () {
	Species spe("food");
	Creature c(spe, 0, 0, 0);
	pair<int, int> k = c.loc_in_front();
	CPPUNIT_ASSERT((k == pair<int,int>(-1,0)));
    }

    void test_loc_in_front_3 () {
	Species spe("rover");
	Creature c(spe, 2, 2, 1);
	pair<int, int> k = c.loc_in_front();
	CPPUNIT_ASSERT((k == pair<int,int>(3,1)));
    }

    void test_update_PC_1 () {
	Species spe("trap");
	Creature c(spe, 1, 2, 1);
	Instruction inst = c.current_instruction();
	Instruction inst2("if_enemy", 3);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c.update_PC(3);
	Instruction inst3("infect", -1);
	inst = c.current_instruction();
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_update_PC_2 () {
	Species spe("rover");
	Creature c(spe, 1, 2, 1);
	Instruction inst = c.current_instruction();
	Instruction inst2("if_enemy", 9);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c.update_PC(2);
	Instruction inst3("if_random", 5);
	inst = c.current_instruction();
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_update_PC_3 () {
	Species spe("trap");
	Creature c(spe, 1, 2, 1);
	Instruction inst = c.current_instruction();
	Instruction inst2("if_enemy", 3);
	CPPUNIT_ASSERT(inst.convert_instruction() == inst2.convert_instruction());
	c.update_PC(4);
	Instruction inst3("go", 0);
	inst = c.current_instruction();
	CPPUNIT_ASSERT(inst.convert_instruction() == inst3.convert_instruction());
    }

    void test_update_continue_1 () {
	Species spe("trap");
	Creature c(spe, 1, 2, 1);	// default _continue is true, so will be changing it
	CPPUNIT_ASSERT(c.update_continue(false));
    }

    void test_update_continue_2 () {
	Species spe("hopper");
	Creature c(spe, 1, 2, 1);
	c._continue = false;
	CPPUNIT_ASSERT(!c.update_continue(false));
    }

    void test_update_continue_3 () {
	Species spe("hopper");
	Creature c(spe, 1, 2, 1);
	c.update_continue(false);
	CPPUNIT_ASSERT(c.update_continue(true));
    }

    void test_print_rep_1 () {
	ostringstream out;
	Species spe("hopper");
	Creature c(spe, 1, 2, 1);
	c.print_rep(out);
	CPPUNIT_ASSERT(out.str() == "h");	
    }

    void test_print_rep_2 () {
	ostringstream out;
	Species spe("best");
	Creature c(spe, 1, 2, 1);
	c.print_rep(out);
	CPPUNIT_ASSERT(out.str() == "b");	
    }

    void test_print_rep_3 () {
	ostringstream out;
	Creature c = Creature();
	c.print_rep(out);
	CPPUNIT_ASSERT(out.str() == ".");	
    }


    // ---------------
    // test Game class
    // ---------------

    void test_make_board_1 () {
	Game game(3, 3);	// calls make_board in Game's constructor
	CPPUNIT_ASSERT(game._board.size() == 3);
    }

    void test_make_board_2 () {
	Game game(3, 3);	// calls make_board in Game's constructor
	CPPUNIT_ASSERT(game._board[0].size() == 3);
    }

    void test_make_board_3 () {
	Game game(0, 0);	// calls make_board in Game's constructor
	CPPUNIT_ASSERT(game._board.size() == 0);
    }

    void test_start_game_1 () {
	Game game(2, 2);
	Species sp("food");
	game.add_Creature(sp, 1, 0, 0);
	ostringstream out;
	game.start_game(0, 1, out);
	CPPUNIT_ASSERT(out.str() == "Turn = 0.\n  01\n0 f.\n1 ..\n\n");
    }

    void test_start_game_2 () {
	Game game(2, 1);
	Species sp("trap");
	game.add_Creature(sp, 1, 0, 0);
	ostringstream out;
	game.start_game(1, 1, out);
	CPPUNIT_ASSERT(out.str() == "Turn = 0.\n  0\n0 t\n1 .\n\nTurn = 1.\n  0\n0 t\n1 .\n\n");
    }

    void test_start_game_3 () {
	Game game(2, 1);
	Species sp("hopper");
	game.add_Creature(sp, 0, 1, 0);
	ostringstream out;
	game.start_game(1, 1, out);
	CPPUNIT_ASSERT(out.str() == "Turn = 0.\n  0\n0 .\n1 h\n\nTurn = 1.\n  0\n0 h\n1 .\n\n");
    }

    void test_do_action_1 () {
	Game game(2, 2);
	Species sp("hopper");
	Creature c = game.add_Creature(sp, 1, 0, 0);
	pair<string, int> instr("hop", 1);
	game.do_action(instr, c);
	CPPUNIT_ASSERT(c._continue == false);
    }

    void test_do_action_2 () {
	Game game(2, 2);
	Species sp("food");
	Creature c = game.add_Creature(sp, 1, 0, 0);
	pair<string, int> instr("left", -1);
	game.do_action(instr, c);
	CPPUNIT_ASSERT(c._direction == 0);
    }

    void test_do_action_3 () {
	Game game(2, 2);
	Species sp("trap");
	Creature c = game.add_Creature(sp, 1, 0, 0);
	pair<string, int> instr("if_wall", -1);
	game.do_action(instr, c);
	// Would be true, but it goes to the trap's next instruction, which is left,
	// which sets _continue to false
	CPPUNIT_ASSERT(c._continue == false);
    }

    void test_hop_1 () {
	Game game(2, 2);
	Species sp("trap");
	Creature c = game.add_Creature(sp, 1, 0, 0);
	game.hop(c);
	pair<int, int> loc_actual = c._location;
	pair<int, int> loc_expected(0, 1);
	CPPUNIT_ASSERT(loc_actual == loc_expected);
    }

    void test_hop_2 () {
	Game game(3, 2);
	Species sp("hopper");
	Creature c = game.add_Creature(sp, 3, 1, 0);
	game.hop(c);
	pair<int, int> loc_actual = c._location;
	pair<int, int> loc_expected(1, 0);
	CPPUNIT_ASSERT(loc_actual == loc_expected);
    }

    void test_hop_3 () {
	Game game(2, 2);
	Species sp("hopper");
	Creature c = game.add_Creature(sp, 1, 0, 0);
	Creature c2 = game.add_Creature(sp, 2, 0, 1);
	game.hop(c);
	pair<int, int> loc_actual = c._location;
	pair<int, int> loc_expected(0, 0);
	CPPUNIT_ASSERT(loc_actual == loc_expected);
    }

    void test_infect_1 () {
	Game game(2, 2);
	Species r("rover");
	Species h("hopper");
	Creature c = game.add_Creature(r, 1, 0, 0);	// attacker
	Creature c2 = game.add_Creature(h, 2, 0, 1);	// infected
	game.infect(c);
	Creature infected = game._board[0][1];
	CPPUNIT_ASSERT(infected._species._name == "rover");
    }

    void test_infect_2 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 1, 0, 0);	// attacker
	game.infect(c);
	Creature infected = game._board[0][1];
	CPPUNIT_ASSERT(infected._species._name == ".");
    }

    void test_infect_3 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 1, 0, 0);	// attacker
	Creature c2 = game.add_Creature(r, 2, 0, 1);	// 'infected'
	game.infect(c);
	Creature infected = game._board[0][1];
	CPPUNIT_ASSERT(infected._species._name == "rover");
    }

    void test_if_empty_1 () {
	Game game(2, 2);
	Species h("hopper");
	Creature c = game.add_Creature(h, 1, 0, 0);
	CPPUNIT_ASSERT(game.if_empty(c, -1) == true);
    }

    void test_if_empty_2 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 2, 0, 0);
	game.if_empty(c, 3);
	CPPUNIT_ASSERT(c._program_counter == 3);
    }

    void test_if_empty_3 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 2, 0, 0);
	Creature c2 = game.add_Creature(r, 2, 1, 0);
	bool empty = game.if_empty(c, 3);
	CPPUNIT_ASSERT(c._program_counter == 1 && !empty);
    }

    void test_if_wall_1 () {
	Game game(2, 2);
	Species h("hopper");
	Creature c = game.add_Creature(h, 3, 1, 0);
	CPPUNIT_ASSERT(game.if_wall(c, -1) == true);
    }

    void test_if_wall_2 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 3, 1, 0);
	game.if_wall(c, 4);
	CPPUNIT_ASSERT(c._program_counter == 4);
    }

    void test_if_wall_3 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 0, 1, 1);
	bool wall = game.if_wall(c, 3);
	CPPUNIT_ASSERT(c._program_counter == 1 && !wall);
    }

    void test_if_random_1 () {
	srand(0);
	Game game(2, 2);
	Species sp("rover");
	Creature c = game.add_Creature(sp, 3, 1, 0);
	game.if_random(c, 3);	// first call will give odd random number
	CPPUNIT_ASSERT(c._program_counter == 3);
    }

    void test_if_random_2 () {
	srand(0);
	rand();	// odd number
	Game game(2, 2);
	Species sp("rover");
	Creature c = game.add_Creature(sp, 3, 1, 0);
	game.if_random(c, 3);	// second call gives even random number
	CPPUNIT_ASSERT(c._program_counter == 1);
    }

    void test_if_random_3 () {
	srand(0);
	Game game(2, 2);
	Species sp("hopper");
	Creature c = game.add_Creature(sp, 3, 1, 0);
	game.if_random(c, 0);	// first call will give odd random number
	CPPUNIT_ASSERT(c._program_counter == 0);
    }

    void test_if_enemy_1 () {
	Game game(2, 2);
	Species r("rover");
	Species f("food");
	Creature c = game.add_Creature(r, 2, 0, 0);
	Creature c2 = game.add_Creature(f, 2, 1, 0);
	CPPUNIT_ASSERT(game.if_enemy(c, -1) == true);
    }

    void test_if_enemy_2 () {
	Game game(2, 2);
	Species r("rover");
	Species f("food");
	Creature c = game.add_Creature(r, 2, 0, 0);
	Creature c2 = game.add_Creature(f, 2, 1, 0);
	bool enemy = game.if_enemy(c, 4);
	CPPUNIT_ASSERT(c._program_counter == 4 && enemy);
    }

    void test_if_enemy_3 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 0, 1, 1);
	bool enemy = game.if_enemy(c, 3);
	CPPUNIT_ASSERT(c._program_counter == 1 && !enemy);
    }

    void test_if_go_1 () {
	Game game(2, 2);
	Species f("trap");
	Creature c = game.add_Creature(f, 2, 0, 0);
	game.go(c, 2);
	CPPUNIT_ASSERT(c._program_counter == 2);
    }

    void test_if_go_2 () {
	Game game(2, 2);
	Species f("rover");
	Creature c = game.add_Creature(f, 2, 0, 0);
	game.go(c, 6);
	CPPUNIT_ASSERT(c._program_counter == 6);
    }

    void test_if_go_3 () {
	Game game(2, 2);
	Species f("food");
	Creature c = game.add_Creature(f, 2, 0, 0);
	game.go(c, 0);
	CPPUNIT_ASSERT(c._program_counter == 0);
    }

    void test_add_Creature_1 () {
	Game game(2, 2);
	Species r("rover");
	Creature c = game.add_Creature(r, 0, 1, 1);
	Creature c2 = game._board[1][1];
	bool equal = (c._species.equals(c2._species)) && (c._direction == c2._direction) 
	&& (c._program_counter == c2._program_counter) && (c._continue == c2._continue)
	&& (c._rep == c2._rep) && (c._location == c2._location);
	CPPUNIT_ASSERT(equal);
    }

    void test_add_Creature_2 () {
	Game game(2, 2);
	Species f("food");
	Creature c = game.add_Creature(f, 0, 1, 1);
	Creature c2 = game._board[1][1];
	pair<int, int> loc(1, 1);
	bool equal = (c2._species._name.compare("food") == 0) && (c2._direction == 0) 
	&& (c2._program_counter == 0) && (c2._continue == true)
	&& (c2._rep == 'f') && (c2._location == loc);
	CPPUNIT_ASSERT(equal);
    }

    void test_add_Creature_3 () {
	Game game(1, 2);
	Species f("food");
	Creature c = game.add_Creature(f, 0, 2, 1);
	pair<int, int> loc(0, 0);
	bool equal = (c._species._name.compare(".") == 0) && (c._direction == 0) 
	&& (c._program_counter == 0) && (c._continue == true)
	&& (c._rep == '.') && (c._location == loc);
	CPPUNIT_ASSERT(equal);
    }

void print_board ();

    void test_print_board_1 () {
	Game game(2, 2);
	Species f("food");
	game.add_Creature(f, 1, 0, 0);
	ostringstream out;
	game.print_board(out);
	CPPUNIT_ASSERT(out.str() == "  01\n0 f.\n1 ..\n\n");
    }

    void test_print_board_2 () {
	Game game(2, 1);
	Species t("trap");
	game.add_Creature(t, 1, 0, 0);
	ostringstream out;
	game.print_board(out);
	CPPUNIT_ASSERT(out.str() == "  0\n0 t\n1 .\n\n");
    }

    void test_print_board_3 () {
	Game game(2, 2);
	Species h("hopper");
	Species r("rover");
	game.add_Creature(h, 0, 0, 0);
	game.add_Creature(r, 0, 1, 1);
	ostringstream out;
	game.print_board(out);
	CPPUNIT_ASSERT(out.str() == "  01\n0 h.\n1 .r\n\n");
    }



    // ----
    // print out board
    // ----  
    
/*
    void test_board () {
	cout << "IN TEST BOARD" << endl;
        int rows = 4;
        int columns = 5;
	Species spe("food");
        Game game = Game(rows, columns);
	game.print_board();
	game.add_Creature(spe, 1, 2, 2);
	Creature j(spe, 1, 2, 2);
	game.add_Creature(spe, 1, 2, 3);
	game.print_board();
	cout << "game.if_empty: " << game.if_empty(j, -1) << endl;

//
	game.print_board();
	game.add_Creature(j);
	game.print_board();
	game.hop(j);
	game.print_board();
	game.left(j);
	game.print_board();
	game.hop(j);
	game.print_board();
	game.right(j);
	game.hop(j);
	game.print_board();
	game.hop(j);
	game.print_board();
//
	CPPUNIT_ASSERT(true);}
*/
/*
    void test_board_2 (){
	cout << "test_board_2" << endl;
	int rows = 4;
	int columns = 5;
	Species spe("food");
	//pair<int, int> loc(2, 4);
	Creature j(spe, 1, 2, 4);
	Game game = Game(rows, columns);
	game.print_board();
	game.add_Creature(spe, 1, 2, 4);
	game.print_board();
	game.hop(j);
	game.print_board();
	CPPUNIT_ASSERT(game.if_wall(j, -1));
	}
*/
        
/*
    void test_program_food() {
	Program p = Program("food");
	//p.print();
	cout << endl;
	CPPUNIT_ASSERT(true);
    }

    void test_program_hopper() {
	Program p = Program("hopper");
	//p.print();
	cout << endl;
	CPPUNIT_ASSERT(true);
    }

    void test_program_rover() {
	Program p = Program("rover");
	//p.print();
	cout << endl;
	CPPUNIT_ASSERT(true);
    }

    void test_program_trap() {
	Program p = Program("trap");
	//p.print();
	cout << endl;
	CPPUNIT_ASSERT(true);
    }

    void test_program_best() {
	Program p = Program("best");
	p.print();
	cout << endl;
	CPPUNIT_ASSERT(true);
    }
*/

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_convert_instruction_1);
    CPPUNIT_TEST(test_convert_instruction_2);
    CPPUNIT_TEST(test_convert_instruction_3);
    CPPUNIT_TEST(test_curr_instruction_1);
    CPPUNIT_TEST(test_curr_instruction_2);
    CPPUNIT_TEST(test_curr_instruction_3);
    CPPUNIT_TEST(test_curr_instr_1);
    CPPUNIT_TEST(test_curr_instr_2);
    CPPUNIT_TEST(test_curr_instr_3);
    CPPUNIT_TEST(test_equals_1);
    CPPUNIT_TEST(test_equals_2);
    CPPUNIT_TEST(test_equals_3);
    CPPUNIT_TEST(test_species_rep_1);
    CPPUNIT_TEST(test_species_rep_2);
    CPPUNIT_TEST(test_species_rep_3);
    CPPUNIT_TEST(test_is_blank_1);
    CPPUNIT_TEST(test_is_blank_2);
    CPPUNIT_TEST(test_is_blank_3);
    CPPUNIT_TEST(test_current_instruction_1);
    CPPUNIT_TEST(test_current_instruction_2);
    CPPUNIT_TEST(test_current_instruction_3);
    CPPUNIT_TEST(test_creature_hop_1);
    CPPUNIT_TEST(test_creature_hop_2);
    CPPUNIT_TEST(test_creature_hop_3);
    CPPUNIT_TEST(test_creature_left_1);
    CPPUNIT_TEST(test_creature_left_2);
    CPPUNIT_TEST(test_creature_left_3);
    CPPUNIT_TEST(test_creature_right_1);
    CPPUNIT_TEST(test_creature_right_2);
    CPPUNIT_TEST(test_creature_right_3);
    CPPUNIT_TEST(test_update_enemy_1);
    CPPUNIT_TEST(test_update_enemy_2);
    CPPUNIT_TEST(test_update_enemy_3);
    CPPUNIT_TEST(test_is_enemy_1);
    CPPUNIT_TEST(test_is_enemy_2);
    CPPUNIT_TEST(test_is_enemy_3);
    CPPUNIT_TEST(test_action_1);
    CPPUNIT_TEST(test_action_2);
    CPPUNIT_TEST(test_action_3);
    CPPUNIT_TEST(test_loc_in_front_1);
    CPPUNIT_TEST(test_loc_in_front_2);
    CPPUNIT_TEST(test_loc_in_front_3);
    CPPUNIT_TEST(test_update_PC_1);
    CPPUNIT_TEST(test_update_PC_2);
    CPPUNIT_TEST(test_update_PC_3);
    CPPUNIT_TEST(test_update_continue_1);
    CPPUNIT_TEST(test_update_continue_2);
    CPPUNIT_TEST(test_update_continue_3);
    CPPUNIT_TEST(test_print_rep_1);
    CPPUNIT_TEST(test_print_rep_2);
    CPPUNIT_TEST(test_print_rep_3);
    CPPUNIT_TEST(test_make_board_1);
    CPPUNIT_TEST(test_make_board_2);
    CPPUNIT_TEST(test_make_board_3);
    CPPUNIT_TEST(test_start_game_1);
    CPPUNIT_TEST(test_start_game_2);
    CPPUNIT_TEST(test_start_game_3);
    CPPUNIT_TEST(test_do_action_1);
    CPPUNIT_TEST(test_do_action_2);
    CPPUNIT_TEST(test_do_action_3);
    CPPUNIT_TEST(test_hop_1);
    CPPUNIT_TEST(test_hop_2);
    CPPUNIT_TEST(test_hop_3);
    CPPUNIT_TEST(test_infect_1);
    CPPUNIT_TEST(test_infect_2);
    CPPUNIT_TEST(test_infect_3);
    CPPUNIT_TEST(test_if_empty_1);
    CPPUNIT_TEST(test_if_empty_2);
    CPPUNIT_TEST(test_if_empty_3);
    CPPUNIT_TEST(test_if_wall_1);
    CPPUNIT_TEST(test_if_wall_2);
    CPPUNIT_TEST(test_if_wall_3);
    CPPUNIT_TEST(test_if_random_1);
    CPPUNIT_TEST(test_if_random_2);
    CPPUNIT_TEST(test_if_random_3);
    CPPUNIT_TEST(test_if_enemy_1);
    CPPUNIT_TEST(test_if_enemy_2);
    CPPUNIT_TEST(test_if_enemy_3);
    CPPUNIT_TEST(test_if_go_1);
    CPPUNIT_TEST(test_if_go_2);
    CPPUNIT_TEST(test_if_go_3);
    CPPUNIT_TEST(test_add_Creature_1);
    CPPUNIT_TEST(test_add_Creature_2);
    CPPUNIT_TEST(test_add_Creature_3);
    CPPUNIT_TEST(test_print_board_1);
    CPPUNIT_TEST(test_print_board_2);
    CPPUNIT_TEST(test_print_board_3);

//    CPPUNIT_TEST(test_board);
//    CPPUNIT_TEST(test_board_2);
//    CPPUNIT_TEST(test_program_food);
//    CPPUNIT_TEST(test_program_hopper);
//    CPPUNIT_TEST(test_program_rover);
//    CPPUNIT_TEST(test_program_trap);
// CPPUNIT_TEST(test_program_best);

    CPPUNIT_TEST_SUITE_END();
};

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

