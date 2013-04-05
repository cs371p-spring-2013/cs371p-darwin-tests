/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -Wl,--no-as-needed -lcppunit -ldl -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin.c++.app
    % valgrind TestDarwin.c++.app >& TestDarwin.c++.out
*/

#define private public
//--------------------
// includes
//---------------------
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <map>

#include <cppunit/extensions/HelperMacros.h> // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include <cppunit/TestFixture.h>             // TestFixture
#include <cppunit/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>          // TextTestRunner
#include <cppunit/CompilerOutputter.h>

#include "Darwin.h"


// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
    // ----------
    // Species::startTurn
    // ----------

    void test_startTurn_1 () {
		Board darwinBoard(3, 3);

		Food f1('f', &darwinBoard, EAST);
		int posFood [] = {0,0};

		GridElement ge(f1, posFood);
		darwinBoard.addGridElement(ge);

		f1.startTurn();
		    CPPUNIT_ASSERT(f1.programCounter == 1);				
		    CPPUNIT_ASSERT(f1.direction == NORTH);
	}

    void test_startTurn_2 () {
		Board darwinBoard2(8, 8);

		Hopper h1('h', &darwinBoard2, EAST);
		int posHop [] = {0,3};

		GridElement ge1(h1, posHop);
		darwinBoard2.addGridElement(ge1);
		darwinBoard2.currentGridElement = &ge1;

		h1.startTurn();
		    CPPUNIT_ASSERT(ge1.position[0] == 0);	
		    CPPUNIT_ASSERT(ge1.position[1] == 4);				
		    CPPUNIT_ASSERT(h1.programCounter == 1);				
		    CPPUNIT_ASSERT(h1.direction == EAST);
	}


    void test_startTurn_3 () {
		Board darwinBoard(8, 8);

		Trap t1('t', &darwinBoard, EAST);
		int posTrap [] = {0,0};
		GridElement ge1(t1, posTrap);

		Food f1('f', &darwinBoard, EAST);
		int posFood [] = {0,1};
		GridElement ge2(f1, posFood);

		darwinBoard.addGridElement(ge1);
		darwinBoard.addGridElement(ge2);

		darwinBoard.currentGridElement = &ge1;
		t1.startTurn();
		    CPPUNIT_ASSERT(ge1.position[0] == 0);				
		    CPPUNIT_ASSERT(ge1.position[1] == 0);
		CPPUNIT_ASSERT(darwinBoard.grid[0].creature == darwinBoard.grid[1].creature);				
		    CPPUNIT_ASSERT(t1.programCounter == 4);				
		    CPPUNIT_ASSERT(t1.direction == EAST);
	}

    // -----------
    // Species::operator==
    // -----------

    void test_operator_1 () {
		Board darwinBoard(8, 8);

		Trap t1('t', &darwinBoard, EAST);
		Food f1('f', &darwinBoard, EAST);

		bool isTrap = t1.operator==(f1);
		    CPPUNIT_ASSERT(!isTrap);
	}

    void test_operator_2 () {
		Board darwinBoard(8, 8);

		Rover r1('r', &darwinBoard, EAST);
		Rover r2('r', &darwinBoard, WEST);

		bool isRover = r1.operator==(r2);			
		    CPPUNIT_ASSERT(isRover);
	}

    void test_operator_3 () {
		Board darwinBoard(8, 8);

		Hopper h1('h', &darwinBoard, EAST);

		bool isHopper = h1.operator==(h1);			
		    CPPUNIT_ASSERT(isHopper);
	}

    // --------------
    // Species::requestAction
    // --------------

    void test_requestAction_1 () {
		Board darwinBoard(8, 8);

		Instruction go(GO, 1, 0);
		Food f1('f', &darwinBoard, EAST);
		int posFood [] = {0,0};

		GridElement ge(f1, posFood);
		darwinBoard.addGridElement(ge);
		darwinBoard.currentGridElement = &ge;

		    CPPUNIT_ASSERT(f1.programCounter == 0);							
		    CPPUNIT_ASSERT(f1.requestAction(go));
	}

    void test_requestAction_2 () {
		Board darwinBoard(8, 8);

		Instruction empty(IF_EMPTY, 1, 0);
		Hopper h1('h', &darwinBoard, EAST);
		int posHopper [] = {0,0};

		GridElement ge(h1, posHopper);
		darwinBoard.addGridElement(ge);
		darwinBoard.currentGridElement = &ge;

		    CPPUNIT_ASSERT(h1.programCounter == 0);							
		    CPPUNIT_ASSERT(h1.requestAction(empty));
	}

    void test_requestAction_3 () {
		Board darwinBoard(8, 8);

		Instruction enemy(IF_ENEMY, 3, 0);

		Trap t1('t', &darwinBoard, EAST);
		int posTrap [] = {0,0};

		Hopper h1('h', &darwinBoard, EAST);
		int posHopper [] = {0,1};

		GridElement ge1(t1, posTrap);
		darwinBoard.addGridElement(ge1);
		GridElement ge2(h1, posHopper);
		darwinBoard.addGridElement(ge2);
		darwinBoard.currentGridElement = &ge1;

		    CPPUNIT_ASSERT(t1.programCounter == 0);							
		    CPPUNIT_ASSERT(t1.requestAction(enemy));
	}


    // ---------------
    // Board::addGridElement
    // ---------------

    void test_addGridElement_1 () {
		Board darwinBoard(8, 8);

		Food f1('f', &darwinBoard, EAST);
		int posFood [] = {0,0};

		GridElement ge(f1, posFood);
		darwinBoard.addGridElement(ge);
		    CPPUNIT_ASSERT(darwinBoard.creatureCount == 1);							
		    CPPUNIT_ASSERT(darwinBoard.grid.size() == 1);
		    CPPUNIT_ASSERT((darwinBoard.grid[0].creature).name == 'f');
	}

    void test_addGridElement_2 () {
		Board darwinBoard(8, 8);

		Food f1('f', &darwinBoard, EAST);
		int pos1 [] = {0,0};
		GridElement ge1(f1, pos1);
		darwinBoard.addGridElement(ge1);

		Food f2('f', &darwinBoard, EAST);
		int pos2 [] = {0,1};
		GridElement ge2(f2, pos2);
		darwinBoard.addGridElement(ge2);

		    CPPUNIT_ASSERT(darwinBoard.creatureCount == 2);							
		    CPPUNIT_ASSERT(darwinBoard.grid.size() == 2);
		    CPPUNIT_ASSERT((darwinBoard.grid[0].creature).name == 'f');
		    CPPUNIT_ASSERT((darwinBoard.grid[1].creature).name == 'f');
	}

    void test_addGridElement_3 () {
		Board darwinBoard(8, 8);

		Hopper h1('h', &darwinBoard, EAST);
		int pos1 [] = {0,0};
		GridElement ge1(h1, pos1);
		darwinBoard.addGridElement(ge1);

		Rover r1('r', &darwinBoard, EAST);
		int pos2 [] = {0,1};
		GridElement ge2(r1, pos2);
		darwinBoard.addGridElement(ge2);

		Trap t1('t', &darwinBoard, EAST);
		int pos3 [] = {0,2};
		GridElement ge3(t1, pos3);
		darwinBoard.addGridElement(ge3);

		    CPPUNIT_ASSERT(darwinBoard.creatureCount == 3);							
		    CPPUNIT_ASSERT(darwinBoard.grid.size() == 3);
		    CPPUNIT_ASSERT((darwinBoard.grid[0].creature).name == 'h');
		    CPPUNIT_ASSERT((darwinBoard.grid[1].creature).name == 'r');
		    CPPUNIT_ASSERT((darwinBoard.grid[2].creature).name == 't');
	}

    // -----------
    // Board::processTurn
    // -----------

    void test_processTurn_1 () {
		Board darwinBoard(8, 8);

		Food f1('f', &darwinBoard, EAST);
		int posFood [] = {0,0};
		GridElement ge(f1, posFood);
		darwinBoard.currentGridElement = &ge;

		darwinBoard.processTurn(ge);
		CPPUNIT_ASSERT(darwinBoard.lastProcessed == &ge);
	}

    void test_processTurn_2 () {
		Board darwinBoard(8, 8);

		Food f1('f', &darwinBoard, EAST);
		int pos1 [] = {0,0};
		GridElement ge1(f1, pos1);
		darwinBoard.currentGridElement = &ge1;
		darwinBoard.processTurn(ge1);
		CPPUNIT_ASSERT(darwinBoard.lastProcessed == &ge1);

		Food f2('f', &darwinBoard, EAST);
		int pos2 [] = {0,1};
		GridElement ge2(f2, pos2);
		darwinBoard.currentGridElement = &ge2;
		darwinBoard.processTurn(ge2);
		CPPUNIT_ASSERT(darwinBoard.lastProcessed == &ge2);
	}

    void test_processTurn_3 () {
		Board darwinBoard(8, 8);

		Hopper h1('h', &darwinBoard, EAST);
		int pos1 [] = {0,0};
		GridElement ge1(h1, pos1);
		darwinBoard.currentGridElement = &ge1;
		darwinBoard.processTurn(ge1);

		Rover r1('r', &darwinBoard, EAST);
		int pos2 [] = {0,1};
		GridElement ge2(r1, pos2);
		darwinBoard.currentGridElement = &ge2;
		darwinBoard.processTurn(ge2);

		Trap t1('t', &darwinBoard, EAST);
		int pos3 [] = {0,2};
		GridElement ge3(t1, pos3);
		darwinBoard.currentGridElement = &ge3;
		darwinBoard.processTurn(ge3);
		CPPUNIT_ASSERT(darwinBoard.lastProcessed == &ge3);
	}


    // ----
    // Board::run
    // ----

    void test_run_1 () {
		Board b(10, 10);
		int pos[] = {3, 2};
		Rover r('r', &b, WEST);
		GridElement ge(r, pos);
		b.addGridElement(ge);
		b.run(8, 0);
		CPPUNIT_ASSERT(b.currentGridElement == b.lastProcessed);
	}

    void test_run_2 () {
		Board b(3, 7);
		int pos[] = {1, 1};
		Trap t('t', &b, NORTH);
		GridElement ge(t, pos);
		b.addGridElement(ge);
		b.run(8, 0);
		CPPUNIT_ASSERT(b.currentGridElement == b.lastProcessed);
	}

    void test_run_3 () {
		Board b(10, 10);
		int posr[] = {5, 5};
		int post[] = {5, 4};
		Rover r('r', &b, WEST);
		Food f('f', &b, EAST);
		GridElement ge1(r, posr);
		GridElement ge2(f, post);
		b.addGridElement(ge1);
		b.addGridElement(ge2);
		b.run(12, 0);
		CPPUNIT_ASSERT(b.currentGridElement == b.lastProcessed);
	}
	
	// ------
	// Board::infect
	// ------
	
	void test_infect_1 () {
		Board b(5, 5);
		int pos_1[] = {4, 3};
		int pos_2[] = {4, 2};
		Trap t('t', &b, EAST);
		Rover r('r', &b, NORTH);
		GridElement ge1(t, pos_2);
		GridElement ge2(r, pos_1);
		b.addGridElement(ge1);
		b.addGridElement(ge2);
		b.infect(&t, pos_1);
		CPPUNIT_ASSERT(b.grid[0].creature == b.grid[1].creature);
	}
	
	void test_infect_2 () {
		Board b(5, 5);
		int pos_1[] = {4, 3};
		int pos_2[] = {4, 2};
		Rover r('r', &b, EAST);
		Food f('f', &b, NORTH);
		GridElement ge1(r, pos_2);
		GridElement ge2(f, pos_1);
		b.addGridElement(ge1);
		b.addGridElement(ge2);
		b.infect(&r, pos_1);
		CPPUNIT_ASSERT(b.grid[0].creature == b.grid[1].creature);
	}
	
	void test_infect_3 () {
		Board b(5, 5);
		int pos_1[] = {4, 3};
		int pos_2[] = {4, 2};
		Trap r1('r', &b, EAST);
		Rover r2('r', &b, NORTH);
		GridElement ge1(r1, pos_2);
		GridElement ge2(r2, pos_1);
		b.addGridElement(ge1);
		b.addGridElement(ge2);
		b.infect(&r1, pos_1);
		CPPUNIT_ASSERT(b.grid[0].creature == b.grid[1].creature);
		CPPUNIT_ASSERT(b.grid[1].creature.direction == NORTH);
		CPPUNIT_ASSERT(b.grid[1].creature.programCounter == 0);
	}

    // ---------------
    // Board::getGridElement
    // ---------------

    void test_getGridElement_1 () {
		Board darwinBoard(8, 8);

		Food f1('f', &darwinBoard, EAST);
		int posFood [] = {0,0};

		GridElement ge(f1, posFood);
		darwinBoard.addGridElement(ge);
		darwinBoard.currentGridElement = &ge;
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(posFood))->position[0] == 0);
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(posFood))->position[1] == 0);
	}

    void test_getGridElement_2 () {
		Board darwinBoard(8, 8);

		Food f1('f', &darwinBoard, EAST);
		int pos1 [] = {0,0};
		GridElement ge1(f1, pos1);
		darwinBoard.addGridElement(ge1);
		darwinBoard.currentGridElement = &ge1;
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos1))->position[0] == 0);
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos1))->position[1] == 0);

		Food f2('f', &darwinBoard, EAST);
		int pos2 [] = {0,1};
		GridElement ge2(f2, pos2);
		darwinBoard.addGridElement(ge2);
		darwinBoard.currentGridElement = &ge2;
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos2))->position[0] == 0);
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos2))->position[1] == 1);
	}

    void test_getGridElement_3 () {
		Board darwinBoard(8, 8);

		Hopper h1('h', &darwinBoard, EAST);
		int pos1 [] = {0,0};
		GridElement ge1(h1, pos1);
		darwinBoard.addGridElement(ge1);
		darwinBoard.currentGridElement = &ge1;
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos1))->position[0] == 0);
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos1))->position[1] == 0);

		Rover r1('r', &darwinBoard, EAST);
		int pos2 [] = {0,1};
		GridElement ge2(r1, pos2);
		darwinBoard.addGridElement(ge2);
		darwinBoard.currentGridElement = &ge2;
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos2))->position[0] == 0);
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos2))->position[1] == 1);

		Trap t1('t', &darwinBoard, EAST);
		int pos3 [] = {0,2};
		GridElement ge3(t1, pos3);
		darwinBoard.addGridElement(ge3);
		darwinBoard.currentGridElement = &ge3;
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos3))->position[0] == 0);
		    CPPUNIT_ASSERT((darwinBoard.getGridElement(pos3))->position[1] == 2);
	}

    // -----
    // suite
    // -----

	// No test_takeActionRequest since it is basically the only 
	//code in requestAction. It would be redundant.
	
    CPPUNIT_TEST_SUITE(TestDarwin);

    CPPUNIT_TEST(test_startTurn_1);
    CPPUNIT_TEST(test_startTurn_2);
    CPPUNIT_TEST(test_startTurn_3);

    CPPUNIT_TEST(test_operator_1);
    CPPUNIT_TEST(test_operator_2);
    CPPUNIT_TEST(test_operator_3);

    CPPUNIT_TEST(test_requestAction_1);
    CPPUNIT_TEST(test_requestAction_2);
    CPPUNIT_TEST(test_requestAction_3);

    CPPUNIT_TEST(test_addGridElement_1);
    CPPUNIT_TEST(test_addGridElement_2);
    CPPUNIT_TEST(test_addGridElement_3);

    CPPUNIT_TEST(test_processTurn_1);
    CPPUNIT_TEST(test_processTurn_2);
    CPPUNIT_TEST(test_processTurn_3);

    CPPUNIT_TEST(test_run_1);
    CPPUNIT_TEST(test_run_2);
    CPPUNIT_TEST(test_run_3);

    CPPUNIT_TEST(test_infect_1);
    CPPUNIT_TEST(test_infect_2);
    CPPUNIT_TEST(test_infect_3);

    CPPUNIT_TEST(test_getGridElement_1);
    CPPUNIT_TEST(test_getGridElement_2);
    CPPUNIT_TEST(test_getGridElement_3);

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
    return 0;
}
