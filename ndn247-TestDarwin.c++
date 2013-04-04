/*
    % g++ -ldl -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -lcppunit -o TestDarwin
    % valgrind ./TestDarwin >& TestDarwin.out
*/

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Darwin.h"

struct TestDarwin : CppUnit::TestFixture {

	void test_game_constructor1() {
        map<location_type, Creature*> players; 
		Game<3,3> newGame = Game<3,3> (players);
		int numRows = sizeof(newGame._board)/sizeof(newGame._board[0]);
		int numCols = sizeof(newGame._board[0])/sizeof(newGame._board[0][0]);
		CPPUNIT_ASSERT(numRows == 3);
		CPPUNIT_ASSERT(numCols == 3);
		for(int i=0; i<numRows; i++) {
			for(int j=0; j<numCols; j++) {
				CPPUNIT_ASSERT(newGame._board[i][j].toString() == '.');
			}
		}
	}

	void test_game_constructor2() {
        map<location_type, Creature*> players;

        Best b;
        Creature c0 = Creature (&b, east);
        players[make_pair(0, 0)] = &c0; 

		Game<1,2> newGame = Game<1,2> (players);
		int numRows = sizeof(newGame._board)/sizeof(newGame._board[0]);
		int numCols = sizeof(newGame._board[0])/sizeof(newGame._board[0][0]);
		CPPUNIT_ASSERT(numRows == 1);
		CPPUNIT_ASSERT(numCols == 2);

		CPPUNIT_ASSERT(newGame._board[0][0].toString() == 'b');
		CPPUNIT_ASSERT(newGame._board[0][1].toString() == '.');
	}

	void test_game_play1() {
		Game<8,8> newGame;

        Food f;
        Creature c1 = Creature (&f, east);
        c1.setNext(&newGame._board[0][1]);
		newGame._board[0][0] = c1;

        Hopper h;
        Creature c2 = Creature (&h, north);
        c2.setNext(&newGame._board[2][3]);
		newGame._board[3][3] = c2; 

        Creature c3 = Creature (&h, east);
        c3.setNext(&newGame._board[3][5]);
		newGame._board[3][4] = c3;

        Creature c4 = Creature (&h, south);
        c4.setNext(&newGame._board[5][4]);
		newGame._board[4][4] = c4;

        Creature c5 = Creature (&h, west);
        c5.setNext(&newGame._board[4][2]);
		newGame._board[4][3] = c5;

        Creature c6 = Creature (&f, north);
        c6.setNext(&newGame._board[6][7]);
		newGame._board[7][7] = c6;

        int displayBoardInterval = 1;
        int moves = 3;

        newGame.play(moves, displayBoardInterval);

        CPPUNIT_ASSERT(newGame._board[0][0].toString() == 'f');
        CPPUNIT_ASSERT(newGame._board[0][3].toString() == 'h');  
        CPPUNIT_ASSERT(newGame._board[3][7].toString() == 'h'); 
        CPPUNIT_ASSERT(newGame._board[4][0].toString() == 'h');     
        CPPUNIT_ASSERT(newGame._board[7][4].toString() == 'h');
        CPPUNIT_ASSERT(newGame._board[7][7].toString() == 'f');
        CPPUNIT_ASSERT(newGame._board[3][3].toString() == '.');
        CPPUNIT_ASSERT(newGame._board[3][4].toString() == '.');     
        CPPUNIT_ASSERT(newGame._board[4][4].toString() == '.');  
        CPPUNIT_ASSERT(newGame._board[4][3].toString() == '.'); 
	}

	void test_game_play2() {
		Game<1,1> newGame;
        int displayBoardInterval = 3;
        int moves = 3;

        newGame.play(moves, displayBoardInterval);		
        CPPUNIT_ASSERT(newGame._board[0][0].toString() == '.');
	}

	void test_game_play_round1() {
		Game<5,5> newGame;

		Trap t;
        Creature c0 = Creature (&t, west);
        c0.setNext(0);
		newGame._board[0][0] = c0;

        Creature c1 = Creature (&t, west);
        c1.setNext(&newGame._board[1][0]);
		newGame._board[1][1] = c1;

        Creature c2 = Creature (&t, west);
        c2.setNext(&newGame._board[2][1]);
		newGame._board[2][2] = c2;

        Creature c3 = Creature (&t, west);
        c3.setNext(&newGame._board[3][2]);
		newGame._board[3][3] = c3;

        Creature c4 = Creature (&t, west);
        c4.setNext(&newGame._board[4][3]);
		newGame._board[4][4] = c4;

		Hopper h;
        Creature c5 = Creature (&h, east);
        c5.setNext(0);
		newGame._board[1][4] = c5;

        Creature c6 = Creature (&h, east);
        c6.setNext(&newGame._board[3][3]);
		newGame._board[3][2] = c6;

		newGame.play_round();

        CPPUNIT_ASSERT(newGame._board[0][0].toString() == 't' && newGame._board[0][0].getDirection() == south);
        CPPUNIT_ASSERT(newGame._board[1][1].toString() == 't' && newGame._board[1][1].getDirection() == south);
        CPPUNIT_ASSERT(newGame._board[2][2].toString() == 't' && newGame._board[2][2].getDirection() == south);
        CPPUNIT_ASSERT(newGame._board[3][3].toString() == 't' && newGame._board[3][3].getDirection() == west);
        CPPUNIT_ASSERT(newGame._board[4][4].toString() == 't' && newGame._board[4][4].getDirection() == south);
        CPPUNIT_ASSERT(newGame._board[3][2].toString() == 't' && newGame._board[3][2].getDirection() == east);
        CPPUNIT_ASSERT(newGame._board[1][4].toString() == 'h' && newGame._board[1][4].getDirection() == east);

	}

	void test_game_play_round2() {
		Game<5,5> newGame;

		Trap t;
        Creature c0 = Creature (&t, south);
        c0.setNext(&newGame._board[1][0]);
		newGame._board[0][0] = c0;

        Creature c1 = Creature (&t, south);
        c1.setNext(&newGame._board[2][1]);
		newGame._board[1][1] = c1;

        Creature c2 = Creature (&t, south);
        c2.setNext(&newGame._board[3][2]);
		newGame._board[2][2] = c2;

        Creature c3 = Creature (&t, west);
        c3.setNext(&newGame._board[3][2]);
		newGame._board[3][3] = c3;

        Creature c4 = Creature (&t, south);
        c4.setNext(0);
		newGame._board[4][4] = c4;

        Creature c5 = Creature (&t, east);
        c5.setNext(&newGame._board[3][3]);
		newGame._board[3][2] = c5;

		Hopper h;
        Creature c6 = Creature (&h, east);
        c6.setNext(0);
		newGame._board[1][4] = c6;

		newGame.play_round();

        CPPUNIT_ASSERT(newGame._board[0][0].toString() == 't' && newGame._board[0][0].getDirection() == east);
        CPPUNIT_ASSERT(newGame._board[1][1].toString() == 't' && newGame._board[1][1].getDirection() == east);
        CPPUNIT_ASSERT(newGame._board[2][2].toString() == 't' && newGame._board[2][2].getDirection() == east);
        CPPUNIT_ASSERT(newGame._board[3][3].toString() == 't' && newGame._board[3][3].getDirection() == south);
        CPPUNIT_ASSERT(newGame._board[4][4].toString() == 't' && newGame._board[4][4].getDirection() == east);
        CPPUNIT_ASSERT(newGame._board[3][2].toString() == 't' && newGame._board[3][2].getDirection() == north);
        CPPUNIT_ASSERT(newGame._board[1][4].toString() == 'h' && newGame._board[1][4].getDirection() == east);

	}

	void test_game_play_round3() {
		Game<1,1> newGame;
        newGame.play_round();		
        CPPUNIT_ASSERT(newGame._board[0][0].toString() == '.');
	}

	void test_game_location_of_next1() {
		Game<2,2> g;
		pair<int,int> next = g.location_of_next(west, 0, 0);
		CPPUNIT_ASSERT(next.first == -1);
	}

	void test_game_location_of_next2() {
		Game<2,2> g;
		pair<int,int> next = g.location_of_next(north, 0, 0);
		CPPUNIT_ASSERT(next.first == -1);
	}

	void test_game_location_of_next3() {
		Game<2,2> g;
		pair<int,int> next = g.location_of_next(east, 0, 0);
		CPPUNIT_ASSERT(next.first == 0 && next.second == 1);
	}
	
	void test_game_location_of_next4() {
		Game<2,2> g;
		pair<int,int> next = g.location_of_next(south, 0, 0);
		CPPUNIT_ASSERT(next.first == 1 && next.second == 0);
	}

	void test_creature_defconstructor() {
		Creature c;
		CPPUNIT_ASSERT(c.toString() == '.');
	}

	void test_creature_constructor() {
		Hopper h;
		Creature c = Creature(&h, west);
		CPPUNIT_ASSERT(c._pc == 0);
		CPPUNIT_ASSERT(c._species = &h);
		CPPUNIT_ASSERT(c._dir = west);
		CPPUNIT_ASSERT(c._display == 'h');
		CPPUNIT_ASSERT(c._next == 0);
	}

	void test_creature_convert_species() {
		Hopper h;
		Creature c = Creature(&h, west);
		Trap t;
		c.convert_species(&t);
		CPPUNIT_ASSERT(c._species == &t);
		CPPUNIT_ASSERT(c._pc == 0);
		CPPUNIT_ASSERT(c._display == 't');
	}

	void test_creature_play_turn1() {
		Rover r;
		Creature c = Creature(&r, south);
		Trap t;
		Creature c1 = Creature(&t, north);
		c.setNext(&c1);
		Instruction* i = c.play_turn();
		CPPUNIT_ASSERT(i->getType() == infect);
		CPPUNIT_ASSERT(c._pc == 10);
	}

	void test_creature_play_turn2() {
		Rover r;
		Creature c = Creature(&r, south);
		Creature c1 = Creature(&r, north);
		c.setNext(&c1);
		Instruction* i = c.play_turn();
		CPPUNIT_ASSERT((i->getType() == Action::left) || (i->getType() == Action::right));
		CPPUNIT_ASSERT((c._pc == 4) || (c._pc == 6));
	}

	void test_creature_play_turn3() {
		Rover r;
		Creature c = Creature(&r, south);
		Creature c1 = Creature();
		c.setNext(&c1);
		Instruction* i = c.play_turn();
		CPPUNIT_ASSERT(i->getType() == hop);
		CPPUNIT_ASSERT(c._pc == 8);
	}

	void test_creature_turn_left() {
		Food f;
		Creature c = Creature(&f, south);
		c.turn_left();
		CPPUNIT_ASSERT(c._dir == east);
	}

	void test_creature_turn_right() {
		Food f;
		Creature c = Creature(&f, east);
		c.turn_right();
		CPPUNIT_ASSERT(c._dir == south);
	}	

	void test_species_getAction1() {
		Trap t;
		Creature c = Creature(&t, north);
		c.setNext(0);
		Instruction* i = t.getAction(c);
		CPPUNIT_ASSERT(i->getType() == Action::left);
	}

	void test_species_getAction2() {
		Trap t;
		Creature c = Creature(&t, north);
		Best b;
		Creature c1 = Creature(&b, east);
		c.setNext(&c1);
		Instruction* i = t.getAction(c);
		CPPUNIT_ASSERT(i->getType() == infect);
	}

	void test_instruction_hop1() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0;
		c.setNext(&c0);
		Hop h = Hop(0);
		int hopped = h.execute(c);

		CPPUNIT_ASSERT(hopped == 1);
		CPPUNIT_ASSERT(c0.toString() == 'r');
		CPPUNIT_ASSERT(c.toString() == '.');
	}

	void test_instruction_hop2() {
		Hopper hpr;
		Creature c = Creature(&hpr, south);
		Rover r;
		Creature c0 = Creature(&r, south);
		c.setNext(&c0);
		Hop h = Hop(0);
		int hopped = h.execute(c);

		CPPUNIT_ASSERT(hopped == 0);
		CPPUNIT_ASSERT(c0.toString() == 'r');
		CPPUNIT_ASSERT(c.toString() == 'h');
	}	

	void test_instruction_infect1() {
		Rover r;
		Creature c = Creature (&r, south);
		Trap t;
		Creature c0 = Creature(&t, north);
		c.setNext(&c0);
		Infect i = Infect(0);
		i.execute(c);

		CPPUNIT_ASSERT(c0.toString() == 'r');
	}

	void test_instruction_infect2() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0 = Creature(&r, north);
		c.setNext(&c0);
		Infect i = Infect(0);
		i.execute(c);

		CPPUNIT_ASSERT(c0.toString() == 'r');
	}

	void test_instruction_infect3() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0;
		c.setNext(&c0);
		Infect i = Infect(0);
		i.execute(c);

		CPPUNIT_ASSERT(c0.toString() == '.');
	}


	void test_instruction_if_empty1() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0;
		c.setNext(&c0);
		If_Empty ie = If_Empty(0, 1);
		int b = ie.execute(c);

		CPPUNIT_ASSERT(b == 1);
	}

	void test_instruction_if_empty2() {
		Rover r;
		Creature c = Creature (&r, south);
		c.setNext(0);
		If_Empty ie = If_Empty(0, 1);
		int b = ie.execute(c);

		CPPUNIT_ASSERT(b == 0);
	}

	void test_instruction_if_wall1() {
		Rover r;
		Creature c = Creature (&r, south);
		c.setNext(0);
		If_Wall iw = If_Wall(0, 1);
		int b = iw.execute(c);

		CPPUNIT_ASSERT(b == 1);
	}

	void test_instruction_if_wall2() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0;
		c.setNext(&c0);
		If_Wall iw = If_Wall(0, 1);
		int b = iw.execute(c);

		CPPUNIT_ASSERT(b == 0);
	}

	void test_instruction_if_enemy1() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0;
		c.setNext(&c0);
		If_Enemy ie = If_Enemy(0, 1);
		int b = ie.execute(c);

		CPPUNIT_ASSERT(b == 0);		
	}

	void test_instruction_if_enemy2() {
		Rover r;
		Creature c = Creature (&r, south);
		Creature c0 = Creature(&r, south);
		c.setNext(&c0);
		If_Enemy ie = If_Enemy(0, 1);
		int b = ie.execute(c);

		CPPUNIT_ASSERT(b == 0);		
	}	

	void test_instruction_if_enemy3() {
		Rover r;
		Creature c = Creature (&r, south);
		Food f;
		Creature c0 = Creature(&f, south);
		c.setNext(&c0);
		If_Enemy ie = If_Enemy(0, 1);
		int b = ie.execute(c);

		CPPUNIT_ASSERT(b == 1);		
	}	

	void test_instruction_if_enemy4() {
		Rover r;
		Creature c = Creature (&r, south);
		c.setNext(0);
		If_Enemy ie = If_Enemy(0, 1);
		int b = ie.execute(c);

		CPPUNIT_ASSERT(b == 0);		
	}	

	void test_instruction_go() {
		Food f;
		Creature c = Creature (&f, north);
		Go g = Go(0);
		int n = g.execute(c);

		CPPUNIT_ASSERT(n == 0);
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_game_constructor1);
    CPPUNIT_TEST(test_game_constructor2);
    CPPUNIT_TEST(test_game_play1);
    CPPUNIT_TEST(test_game_play2);
    CPPUNIT_TEST(test_game_play_round1);
    CPPUNIT_TEST(test_game_play_round2); 
    CPPUNIT_TEST(test_game_play_round3); 
    CPPUNIT_TEST(test_game_location_of_next1);
    CPPUNIT_TEST(test_game_location_of_next2);  
    CPPUNIT_TEST(test_game_location_of_next3);
    CPPUNIT_TEST(test_game_location_of_next4);
    CPPUNIT_TEST(test_creature_defconstructor);  
    CPPUNIT_TEST(test_creature_constructor);
    CPPUNIT_TEST(test_creature_convert_species);
    CPPUNIT_TEST(test_creature_play_turn1);
    CPPUNIT_TEST(test_creature_play_turn2);
    CPPUNIT_TEST(test_creature_play_turn3);
    CPPUNIT_TEST(test_creature_turn_left);
    CPPUNIT_TEST(test_creature_turn_right);
    CPPUNIT_TEST(test_species_getAction1);
    CPPUNIT_TEST(test_species_getAction2);
    CPPUNIT_TEST(test_instruction_hop1);
    CPPUNIT_TEST(test_instruction_hop2);
    CPPUNIT_TEST(test_instruction_infect1);
    CPPUNIT_TEST(test_instruction_infect2);
    CPPUNIT_TEST(test_instruction_infect3);
    CPPUNIT_TEST(test_instruction_if_empty1);
    CPPUNIT_TEST(test_instruction_if_empty2);
    CPPUNIT_TEST(test_instruction_if_wall1);
    CPPUNIT_TEST(test_instruction_if_wall2);
    CPPUNIT_TEST(test_instruction_if_enemy1);
    CPPUNIT_TEST(test_instruction_if_enemy2);
    CPPUNIT_TEST(test_instruction_if_enemy3);
    CPPUNIT_TEST(test_instruction_if_enemy4);
    CPPUNIT_TEST(test_instruction_go);
    CPPUNIT_TEST_SUITE_END();
};

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
    return 0;
}