// ------------------------------------
// projects/Darwin/TestDarwin.c++
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
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin -lcppunit -ldl
    % valgrind TestDarwin >& TestDarwin.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // Darwin

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#include "Darwin.h"

#define HOP          0
#define LEFT         1
#define RIGHT        2
#define INFECT       3
#define IF_EMPTY     4
#define IF_WALL      5
#define IF_RANDOM    6
#define IF_ENEMY     7
#define GO           8

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {

//test instruction constructor
    void test_instruction_1(){
        Instruction i(HOP);
        CPPUNIT_ASSERT(i.type == HOP);
    }

    void test_instruction_2(){
        Instruction i(IF_WALL,1);
        CPPUNIT_ASSERT(i.type == IF_WALL);
        CPPUNIT_ASSERT(i.next == 1);
    }

    void test_instruction_3(){
        Instruction i(IF_RANDOM,3);
        CPPUNIT_ASSERT(i.type == IF_RANDOM);
        CPPUNIT_ASSERT(i.next == 3);
    }


//test creature constructor
	void test_creature_f(){
		Creature f('f',1,3,3);
		CPPUNIT_ASSERT(f.name == 'f');
		CPPUNIT_ASSERT(f.pc == 0);
		CPPUNIT_ASSERT(f.direction == 1);
		CPPUNIT_ASSERT(f._row == 3); 
		CPPUNIT_ASSERT(f._col == 3);
		CPPUNIT_ASSERT(f.instruction_list[0].type == LEFT);
		CPPUNIT_ASSERT(f.instruction_list[1].type == GO);
		CPPUNIT_ASSERT(f.instruction_list[1].next == 0);
    }
    
	void test_creature_h(){
		Creature h('h',4,2,3);
		CPPUNIT_ASSERT(h.name == 'h');
		CPPUNIT_ASSERT(h.direction == 4);
		CPPUNIT_ASSERT(h._row == 2); 
		CPPUNIT_ASSERT(h._col == 3);
		CPPUNIT_ASSERT(h.instruction_list[0].type == HOP);
		CPPUNIT_ASSERT(h.instruction_list[1].type == GO);
		CPPUNIT_ASSERT(h.instruction_list[1].next == 0);
    }
    
 	void test_creature_r(){
		Creature r('r',3,3,3);
		CPPUNIT_ASSERT(r.name == 'r');
		CPPUNIT_ASSERT(r.direction == 3);
		CPPUNIT_ASSERT(r._row == 3); 
		CPPUNIT_ASSERT(r._col == 3);
		CPPUNIT_ASSERT(r.instruction_list[0].type == IF_ENEMY);
		CPPUNIT_ASSERT(r.instruction_list[0].next == 9);
		CPPUNIT_ASSERT(r.instruction_list[1].type == IF_EMPTY);
		CPPUNIT_ASSERT(r.instruction_list[1].next == 7);
    }

	void test_creature_t(){
		Creature t('t',3,3,3);
		CPPUNIT_ASSERT(t.name == 't');
		CPPUNIT_ASSERT(t.direction == 3);
		CPPUNIT_ASSERT(t._row == 3); 
		CPPUNIT_ASSERT(t._col == 3);
		CPPUNIT_ASSERT(t.instruction_list[0].type == IF_ENEMY);
		CPPUNIT_ASSERT(t.instruction_list[0].next == 3);
		CPPUNIT_ASSERT(t.instruction_list[1].type == LEFT);
		CPPUNIT_ASSERT(t.instruction_list[2].type == GO);
		CPPUNIT_ASSERT(t.instruction_list[2].next == 0);
	}

//test do_hop
	
	void test_do_hop_1(){
		Game g(5,5,3);
		Creature h('h',2,0,0);
		g.add_creature(h);
		g.run_game(-1);
		CPPUNIT_ASSERT(g.board[0][0] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[0][2] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[0][3] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[0][4] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[1][2] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[1][3] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[1][4] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[2][0] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[2][1] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[2][2] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[2][3] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[2][4] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[3][0] == 'h');
		CPPUNIT_ASSERT(g.board[3][1] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[3][2] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[3][3] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[3][4] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[4][0] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[4][1] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[4][2] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[4][3] == EMPTY_CELL);
		CPPUNIT_ASSERT(g.board[4][4] == EMPTY_CELL);
	}

	void test_do_hop_2(){
		Game g(2,2,1);
		Creature h('h',2,0,0);
		Creature f('f',2,1,0);
		g.add_creature(h);
		g.add_creature(f);
		g.run_game(-1);
		CPPUNIT_ASSERT(g.board[0][0] == 'h');
		CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);			
		CPPUNIT_ASSERT(g.board[1][0] =='f');		
		CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);	
	}

	
	void test_do_hop_3(){
		Game g(2,2,1);
		Creature h('h',1,0,0);
		g.add_creature(h);
		g.run_game(-1);
		CPPUNIT_ASSERT(g.board[0][0] == 'h');
		CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);		
		CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);	
		CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);			
	}
	
	// ------------
    // test_do_left
    // ------------
    void test_do_left_1 () {
        Game g(2,2,1);
        Creature f('f',1,0,0);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'f');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.direction == 3);
    }
    
    void test_do_left_2 () {
        Game g(2,2,1);
        Creature f('f',2,0,0);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'f');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.direction == 4);
    }
    
    void test_do_left_3 () {
        Game g(2,2,1);
        Creature f('f',3,0,0);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'f');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.direction == 2);
    }
    
    void test_do_left_4 () {
        Game g(2,2,1);
        Creature f('f',4,0,0);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'f');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.direction == 1);
    }
    
    // -------------
    // test_do_right
    // -------------
    
    void test_do_right_1 () {
        Game g(2, 2, 1);
        Creature r('r',1,0,0);
        r.pc = 5;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.direction == 4);
    }
    
    void test_do_right_2 () {
        Game g(2, 2, 1);
        Creature r('r',2,0,0);
        r.pc = 5;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.direction == 3);
    }
    
    void test_do_right_3 () {
        Game g(2, 2, 1);
        Creature r('r',3,0,0);
        r.pc = 5;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.direction == 1);
    }
    
    void test_do_right_4 () {
        Game g(2, 2, 1);
        Creature r('r',4,0,0);
        r.pc = 5;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.direction == 2);
    }
    
    // --------------
    // test_do_infect
    // --------------
    
    void test_do_infect_1 () {
        Game g(2,2,1);
        Creature t('t',4,0,0);
        t.pc = 3;
        Creature f('f',1,0,1);
        g.add_creature(t);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 't');
        CPPUNIT_ASSERT(g.board[0][1] == 't');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.pc == 2);
        CPPUNIT_ASSERT(f.direction == 3);
    }
    
    void test_do_infect_2 () {
        Game g(2,2,1);
        Creature t('t',4,0,0);
        t.pc = 3;
        Creature f('t',1,0,1);
        f.pc = 2;
        g.add_creature(t);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 't');
        CPPUNIT_ASSERT(g.board[0][1] == 't');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.pc == 2);
        CPPUNIT_ASSERT(f.direction == 3);
    }
    
    void test_do_infect_3 () {
        Game g(2,2,1);
        Creature t('t',4,0,0);
        t.pc = 3;
        g.add_creature(t);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 't');
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
    }
    
    // ----------------
    // test_do_if_empty
    // ----------------
    
    void test_do_if_empty_1 () {
        Game g(2,2,1);
        Creature r('r',4,0,0);
        r.pc = 1;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == 'r');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.pc == 8);
    }
    
    void test_do_if_empty_2 () {
        Game g(2,2,1);
        Creature r('r',4,0,0);
        r.pc = 1;
        Creature f('f',4,0,1);
        g.add_creature(r);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[0][1] == 'f');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.pc == 4 || r.pc == 6);
    }
    
    void test_do_if_empty_3 () {
        Game g(2,2,1);
        Creature r('r',1,0,0);
        r.pc = 1;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.pc == 4 || r.pc == 6);
        CPPUNIT_ASSERT(r.direction == 3 || r.direction == 4);
    }
    
    void test_do_if_empty_4 () {
        Game g(2,2,1);
        Creature r('r',3,0,0);
        r.pc = 1;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'r');
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.pc == 4 || r.pc == 6);
        CPPUNIT_ASSERT(r.direction == 1 || r.direction == 2);
    }
    
    void test_do_if_empty_5 () {
        Game g(2,2,1);
        Creature r('r',2,1,0);
        r.pc = 1;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == 'r');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.pc == 4 || r.pc == 6);
        CPPUNIT_ASSERT(r.direction == 3 || r.direction == 4);
    }
    
    void test_do_if_empty_6 () {
        Game g(2,2,1);
        Creature r('r',4,0,1);
        r.pc = 1;
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][1] == 'r');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(r.pc == 4 || r.pc == 6);
        CPPUNIT_ASSERT(r.direction == 1 || r.direction == 2);
    }
    
    // ----------------
    // test_do_if_enemy
    // ----------------
    
    void test_do_if_enemy_1 () {
        Game g(2,2,1);
        Creature t('t',4,0,0);
        Creature t2('t',2,0,1);
        g.add_creature(t);
        g.add_creature(t2);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 't');
        CPPUNIT_ASSERT(g.board[0][1] == 't');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(t.pc == 2);
        CPPUNIT_ASSERT(t2.pc == 2);
        CPPUNIT_ASSERT(t.direction == 1);
        CPPUNIT_ASSERT(t2.direction == 4);
    }
    
    void test_do_if_enemy_2 () {
        Game g(2,2,1);
        Creature t('t',4,0,0);
        Creature r('r',2,0,1);
        g.add_creature(t);
        g.add_creature(r);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 't');
        CPPUNIT_ASSERT(g.board[0][1] == 't');
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(t.pc == 4);
        CPPUNIT_ASSERT(r.pc == 2);
        CPPUNIT_ASSERT(t.direction == 4);
        CPPUNIT_ASSERT(r.direction == 4);
    }
    
     void test_do_if_enemy_3 () {
        Game g(2,2,1);
        Creature t('t',4,0,0);
        g.add_creature(t);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 't');
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(t.pc == 2);
        CPPUNIT_ASSERT(t.direction == 1);
    }
    
    // ----------
    // test_do_go
    // ----------
    
    void test_do_go_1 () {
        Game g(2,2,1);
        Creature f('f',4,0,0);
        f.pc = 1;
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'f');
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.pc == 1);
        CPPUNIT_ASSERT(f.direction == 1);
    }
    
    // -------------
    // test_run_game
    // -------------
    
    void test_run_game_1 () {
        Game g(4,4,5);
        Creature f('f',4,0,0);
        g.add_creature(f);
        g.run_game(-1);
        CPPUNIT_ASSERT(g.board[0][0] == 'f');
        CPPUNIT_ASSERT(g.board[0][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][2] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[0][3] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][2] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[1][3] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[2][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[2][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[2][2] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[2][3] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[3][0] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[3][1] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[3][2] == EMPTY_CELL);
        CPPUNIT_ASSERT(g.board[3][3] == EMPTY_CELL);
        CPPUNIT_ASSERT(f.direction == 1);
        CPPUNIT_ASSERT(f.pc == 1);
    }
    
    void test_run_game_2 () {
        Game g(8,8,5);
        Creature h1('h',1,3,3);
        Creature h2('h',4,3,4);
        Creature h3('h',2,4,4);
        Creature h4('h',3,4,3);
        g.add_creature(h1);
        g.add_creature(h2);
        g.add_creature(h3);
        g.add_creature(h4);
        g.run_game(1);
        CPPUNIT_ASSERT(g.board[0][3] == 'h');
        CPPUNIT_ASSERT(g.board[3][7] == 'h');
        CPPUNIT_ASSERT(g.board[4][0] == 'h');
        CPPUNIT_ASSERT(g.board[7][4] == 'h');
    }
    
    // -----
    // suite
    // -----

   	CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_instruction_1);
   	CPPUNIT_TEST(test_instruction_2);
   	CPPUNIT_TEST(test_instruction_3);
  	CPPUNIT_TEST(test_creature_f);
  	CPPUNIT_TEST(test_creature_h);
  	CPPUNIT_TEST(test_creature_r);	
  	CPPUNIT_TEST(test_creature_t);
	CPPUNIT_TEST(test_do_hop_1);
	CPPUNIT_TEST(test_do_hop_2);
	CPPUNIT_TEST(test_do_hop_3);
	CPPUNIT_TEST(test_do_left_1);
	CPPUNIT_TEST(test_do_left_2);
	CPPUNIT_TEST(test_do_left_3);
	CPPUNIT_TEST(test_do_left_4);
	CPPUNIT_TEST(test_do_right_1);
	CPPUNIT_TEST(test_do_right_2);
	CPPUNIT_TEST(test_do_right_3);
	CPPUNIT_TEST(test_do_right_4);
	CPPUNIT_TEST(test_do_infect_1);
	CPPUNIT_TEST(test_do_infect_2);
	CPPUNIT_TEST(test_do_infect_3);
	CPPUNIT_TEST(test_do_if_empty_1);
	CPPUNIT_TEST(test_do_if_empty_2);
	CPPUNIT_TEST(test_do_if_empty_3);
	CPPUNIT_TEST(test_do_if_empty_4);
	CPPUNIT_TEST(test_do_if_empty_5);
	CPPUNIT_TEST(test_do_if_empty_6);
	CPPUNIT_TEST(test_do_if_enemy_1);
	CPPUNIT_TEST(test_do_if_enemy_2);
	CPPUNIT_TEST(test_do_if_enemy_3);
	CPPUNIT_TEST(test_do_go_1);
	CPPUNIT_TEST(test_run_game_1);
	CPPUNIT_TEST(test_run_game_2);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

	tr.addTest(TestDarwin::suite()); // uncomment!

    tr.run();

    cout << "Done." << endl;
    return 0;}

