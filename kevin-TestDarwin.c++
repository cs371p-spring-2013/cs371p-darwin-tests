
// --------
// includes
// --------


#define private public

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Darwin.h"
#include "Darwin.c++"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
typedef Game<5, 5> Gameboard;
typedef Hopper<5, 5> StdHopper;
typedef Creature<5, 5> StdCreature;
typedef Food<5, 5> StdFood;
typedef Trap<5, 5> StdTrap;
typedef Rover<5, 5> StdRover;

// -----------
// TestDarwin
// -----------
struct TestDarwin : CppUnit::TestFixture {

	void test_constructor() {
		Gameboard g;
		CPPUNIT_ASSERT(g.N == 0);
		CPPUNIT_ASSERT(g.E == 1);
		CPPUNIT_ASSERT(g.S == 2);
		CPPUNIT_ASSERT(g.W == 3);
		
		CPPUNIT_ASSERT(sizeof(g.board)/sizeof(int) == 25);
		CPPUNIT_ASSERT(sizeof(g.directions)/sizeof(int) == 25);
		CPPUNIT_ASSERT(!g.in_progress);
	}

	void test_creature() {
		StdHopper h;
		CPPUNIT_ASSERT(h.get_character() == 'h');
		Creature<5, 5>* c = &h;
		CPPUNIT_ASSERT(c->get_character() == 'h');
	}

	void test_add_creature() {
		Gameboard g;
		StdHopper h;
		CPPUNIT_ASSERT(g.board[0] == g.EMPTY);
		CPPUNIT_ASSERT(g.directions[0] == 0);
		g.add_creature(&h, 0, 0, g.W);
		CPPUNIT_ASSERT(g.board[0] == 1);
		CPPUNIT_ASSERT(g.directions[0] == g.W);
		CPPUNIT_ASSERT(g.creature_map[1] == &h);
		
	}

	void test_add_creature_2() {
		Gameboard g;
		StdHopper h1;
		StdHopper h2;
		g.add_creature(&h1, 0, 0, g.W);
		g.add_creature(&h2, 1, 0, g.E);
		CPPUNIT_ASSERT(g.board[0] == 1);
		CPPUNIT_ASSERT(g.board[5] == 2);
		CPPUNIT_ASSERT(g.directions[0] == g.W);
		CPPUNIT_ASSERT(g.directions[5] == g.E);
		CPPUNIT_ASSERT(g.creature_map[1] == &h1);
		CPPUNIT_ASSERT(g.creature_map[2] == &h2);
	}

	void test_add_creature_3(){
		Gameboard g;
		StdHopper h;
		StdFood p;
		StdTrap t;
		g.add_creature(&h, 0, 0, g.N);
		g.add_creature(&p, 0, 1, g.W);
		g.add_creature(&t, 1, 0, g.S);
		CPPUNIT_ASSERT(g.board[0] == 1);
		CPPUNIT_ASSERT(g.board[1] == 2);
		CPPUNIT_ASSERT(g.board[5] == 3);
		CPPUNIT_ASSERT(g.directions[0] == g.N);
		CPPUNIT_ASSERT(g.directions[1] == g.W);
		CPPUNIT_ASSERT(g.directions[5] == g.S);
		CPPUNIT_ASSERT(g.creature_map[1] == &h);
		CPPUNIT_ASSERT(g.creature_map[2] == &p);
		CPPUNIT_ASSERT(g.creature_map[3] == &t);
	}
	void test_if_wall() {
		Gameboard g;
		StdHopper h;
		g.current_index = 0;
		
		g.add_creature(&h, 0, 0, g.N);
		CPPUNIT_ASSERT(g.if_wall() == true);
		
		g.add_creature(&h, 0, 0, g.E);
		CPPUNIT_ASSERT(g.if_wall() == false);
		
		g.add_creature(&h, 0, 0, g.S);
		CPPUNIT_ASSERT(g.if_wall() == false);
		
		g.add_creature(&h, 0, 0, g.W);
		CPPUNIT_ASSERT(g.if_wall() == true);
	}

	void test_if_empty() {
		Gameboard g;
		StdHopper h1;
		StdHopper h2;
		
		g.add_creature(&h2, 1, 0, g.N);
		g.current_index = 0;
		
		g.add_creature(&h1, 0, 0, g.N);
		CPPUNIT_ASSERT(g.if_empty() == false);
		
		g.add_creature(&h1, 0, 0, g.E);
		CPPUNIT_ASSERT(g.if_empty() == true);
		
		g.add_creature(&h1, 0, 0, g.S);
		CPPUNIT_ASSERT(g.if_empty() == false);
		
		g.add_creature(&h1, 0, 0, g.W);
		CPPUNIT_ASSERT(g.if_empty() == false);
	}

	void test_if_random() {
		Gameboard g;
		srand(0);
		CPPUNIT_ASSERT( g.if_random() == false);
		CPPUNIT_ASSERT( g.if_random() == true);
		CPPUNIT_ASSERT( g.if_random() == true);
		CPPUNIT_ASSERT( g.if_random() == false);
	}

	void test_if_enemy() {
		Gameboard g;
		StdHopper h;
		StdFood p;
		g.add_creature(&h, 0, 0, g.S);
		g.add_creature(&p, 0, 1, g.N);
		g.current_index = 0;
		g.current_id = 1;
		CPPUNIT_ASSERT(g.if_enemy() == false);
		g.left();
		CPPUNIT_ASSERT(g.if_enemy() == true);
	}

	void test_print_board() {
		Gameboard g;
		StdHopper h1;
		StdHopper h2;
		StdHopper h3;
		g.add_creature(&h1, 0, 0, g.N);
		g.add_creature(&h2, 1, 0, g.N);
		g.add_creature(&h3, 0, 1, g.N);
		
		//g.print_board();
	}

	void test_left() {
		Gameboard g;
		StdHopper h;
		g.add_creature(&h, 0, 0, g.N);
		g.current_index = 0;
		g.left();
		CPPUNIT_ASSERT(g.directions[0] == g.W);
	}

	void test_right() {
		Gameboard g;
		StdHopper h;
		g.add_creature(&h, 0, 0, g.N);
		g.current_index = 0;
		g.right();
		CPPUNIT_ASSERT(g.directions[0] == g.E);
	}

	void test_hop() {
		Gameboard g;
		StdHopper h;
		g.add_creature(&h, 2, 2, g.N);
		g.current_index = 12;
		g.current_id = 1;
		
		CPPUNIT_ASSERT(g.board[12] == 1);
		CPPUNIT_ASSERT(g.board[7] == g.EMPTY);
		CPPUNIT_ASSERT(g.directions[12] == g.N);
		
		g.hop();
		
		CPPUNIT_ASSERT(g.board[12] == g.EMPTY);
		CPPUNIT_ASSERT(g.board[7] == 1);
		CPPUNIT_ASSERT(g.directions[7] == g.N);
	}

	void test_infect() {
		Gameboard g;
		StdFood p;
		StdHopper h;
		g.add_creature(&h, 0, 0, g.S);
		g.add_creature(&p, 1, 0, g.S);
		
		g.current_index = 0;
		g.current_id = 1;
		g.infect();

	}

	void test_play() {
		srand(0);
		Gameboard g;
		StdHopper h;
		StdTrap t;
		StdTrap t1;
		StdFood p;
		StdRover r;
		StdRover r1;
		g.add_creature(&h, 2, 2, g.N);
		g.add_creature(&t, 3, 2, g.S);
		g.add_creature(&t1, 2, 0, g.W);
		g.add_creature(&p, 3, 0, g.N);
		g.add_creature(&r, 4, 4, g.N);
		g.add_creature(&r1, 0, 4, g.N);
		g.play(100, 10);
	}

	void test_play_2(){
		srand(0);
		Game<8, 8> g;
		Food<8, 8> f1;
		Hopper<8, 8> h1;
		Hopper<8, 8> h2;
		Hopper<8, 8> h3;
		Hopper<8, 8> h4;
		Food<8, 8> f2;
		g.add_creature(&f1, 0, 0, g.E);
		g.add_creature(&h1, 3, 3, g.N);
		g.add_creature(&h2, 3, 4, g.E);
		g.add_creature(&h3, 4, 4, g.S);
		g.add_creature(&h4, 4, 3, g.W);
		g.add_creature(&f2, 7, 7, g.N);
		g.play(5, 1);
	}

/* This slows everything down just gonna comment this out.
	void test_play3(){
		Game<72, 72> g;
		Food<72, 72> f1;
		Food<72, 72> f2;
		Food<72, 72> f3;
		Food<72, 72> f4;
		Food<72, 72> f5;
		Food<72, 72> f6;
		Food<72, 72> f7;
		Food<72, 72> f8;
		Food<72, 72> f9;
		Food<72, 72> f10;
		Hopper<72, 72> h1;
		Hopper<72, 72> h2;
		Hopper<72, 72> h3;
		Hopper<72, 72> h4;
		Hopper<72, 72> h5;
		Hopper<72, 72> h6;
		Hopper<72, 72> h7;
		Hopper<72, 72> h8;
		Hopper<72, 72> h9;
		Hopper<72, 72> h10;
		Rover<72, 72> r1;
		Rover<72, 72> r2;
		Rover<72, 72> r3;
		Rover<72, 72> r4;
		Rover<72, 72> r5;
		Rover<72, 72> r6;
		Rover<72, 72> r7;
		Rover<72, 72> r8;
		Rover<72, 72> r9;
		Rover<72, 72> r10;
		Trap<72, 72> t1;
		Trap<72, 72> t2;
		Trap<72, 72> t3;
		Trap<72, 72> t4;
		Trap<72, 72> t5;
		Trap<72, 72> t6;
		Trap<72, 72> t7;
		Trap<72, 72> t8;
		Trap<72, 72> t9;
		Trap<72, 72> t10;
		
		srand(0);
		g.add_creature(&f1, rand()%5184, rand()%4);
		g.add_creature(&f2, rand()%5184, rand()%4);
		g.add_creature(&f3, rand()%5184, rand()%4);
		g.add_creature(&f4, rand()%5184, rand()%4);
		g.add_creature(&f5, rand()%5184, rand()%4);
		g.add_creature(&f6, rand()%5184, rand()%4);
		g.add_creature(&f7, rand()%5184, rand()%4);
		g.add_creature(&f8, rand()%5184, rand()%4);
		g.add_creature(&f9, rand()%5184, rand()%4);
		g.add_creature(&f10, rand()%5184, rand()%4);

		g.add_creature(&h1, rand()%5184, rand()%4);
		g.add_creature(&h2, rand()%5184, rand()%4);
		g.add_creature(&h3, rand()%5184, rand()%4);
		g.add_creature(&h4, rand()%5184, rand()%4);
		g.add_creature(&h5, rand()%5184, rand()%4);
		g.add_creature(&h6, rand()%5184, rand()%4);
		g.add_creature(&h7, rand()%5184, rand()%4);
		g.add_creature(&h8, rand()%5184, rand()%4);
		g.add_creature(&h9, rand()%5184, rand()%4);
		g.add_creature(&h10, rand()%5184, rand()%4);
		
		g.add_creature(&r1, rand()%5184, rand()%4);
		g.add_creature(&r2, rand()%5184, rand()%4);
		g.add_creature(&r3, rand()%5184, rand()%4);
		g.add_creature(&r4, rand()%5184, rand()%4);
		g.add_creature(&r5, rand()%5184, rand()%4);
		g.add_creature(&r6, rand()%5184, rand()%4);
		g.add_creature(&r7, rand()%5184, rand()%4);
		g.add_creature(&r8, rand()%5184, rand()%4);
		g.add_creature(&r9, rand()%5184, rand()%4);
		g.add_creature(&r10, rand()%5184, rand()%4);
		
		g.add_creature(&t1, rand()%5184, rand()%4);
		g.add_creature(&t2, rand()%5184, rand()%4);
		g.add_creature(&t3, rand()%5184, rand()%4);
		g.add_creature(&t4, rand()%5184, rand()%4);
		g.add_creature(&t5, rand()%5184, rand()%4);
		g.add_creature(&t6, rand()%5184, rand()%4);
		g.add_creature(&t7, rand()%5184, rand()%4);
		g.add_creature(&t8, rand()%5184, rand()%4);
		g.add_creature(&t9, rand()%5184, rand()%4);
		g.add_creature(&t10, rand()%5184, rand()%4);
		g.play(1000, 100);
	}*/


	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(test_constructor);
	CPPUNIT_TEST(test_creature);
	CPPUNIT_TEST(test_add_creature);
	CPPUNIT_TEST(test_add_creature_2);
	CPPUNIT_TEST(test_add_creature_3);
	CPPUNIT_TEST(test_if_wall);
	CPPUNIT_TEST(test_if_empty);
	//CPPUNIT_TEST(test_if_random);
	CPPUNIT_TEST(test_if_enemy);
	CPPUNIT_TEST(test_print_board);
	CPPUNIT_TEST(test_left);
	CPPUNIT_TEST(test_right);
	CPPUNIT_TEST(test_hop);
	CPPUNIT_TEST(test_infect);
	//CPPUNIT_TEST(test_play);
	//CPPUNIT_TEST(test_play_2);
	CPPUNIT_TEST_SUITE_END();
};
	
// ----
// main
// ----

int main () {
    cout << "TestDarwin.c++" << endl;
    ios_base::sync_with_stdio(false);
	
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();
    
    cout << "End of Tests" << endl;
    return 0;
}

