// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunDarwin.c++ -o RunDarwin
    % valgrind RunDarwin > RunDarwin.out

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ----
    // food
    // ----

    /*
     0: left
     1: go 0
    */

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    // -----
    // rover
    // -----

    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: left
     4: go 0
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */

    // ----
    // trap
    // ----

    /*
     0: if_enemy 3
     1: left
     2: go 0
     3: infect
     4: go 0
    */

	//-----
	// best
	//-----
	/*
     0: if_enemy 13
     1: if_empty 11
     2: if_random 9
     3: left
	 4: if_enemy 13
	 5: left
	 6: if_enemy 13
	 7: left
     8: go 0
     9: right
     10: go 0
     11: hop
     12: go 0
     13: infect
     14: go 0
	*/

    // ----------
    // darwin 8x8
    // ----------
	cout<<"Run Darwin"<<endl;

    try {
		cout << "*** Darwin 8x8 ***" << endl;
		Game x = Game(8,8);		
        x.AddCreature(0,0,'f','e');
        x.AddCreature(3,3,'h','n');
        x.AddCreature(3,4,'h','e');
        x.AddCreature(4,4,'h','s');
        x.AddCreature(4,3,'h','w');
        x.AddCreature(7,7,'f','n');
		x.Simulate(5,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
        cout << "*** Darwin 7x9 ***" << endl;
        srand(0);
        Game y = Game(7,9);	
        y.AddCreature(0,0,'t','s');
        y.AddCreature(3,2,'h','e');
        y.AddCreature(5,4,'r','n');
        y.AddCreature(6,8,'t','w');
        y.Simulate(50,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // without best
    // ------------

    try {
        cout << "*** Darwin 72x72 without Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 5184 (72x72), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: west, north, east, south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        Simulate 1000 moves.
        Print every 100th grid.
        */
		int pos;
		int row;
		int col;
		int dNum;
		char direction;
		char directions[4] = { 'w', 'n', 'e', 's' };
		Game z = Game(72,72);
		//add food
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'f',direction);
		}
		//add hoppers
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'h',direction);
		}
		//add rovers
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'r',direction);
		}
		//add traps
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'t',direction);
		}
		z.Simulate(1000,100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // with best
    // ------------

    try {
        cout << "*** Darwin 72x72 with Best ***" << endl;
        srand(0);
        /*
        Randomly place the following creatures facing randomly.
        Call rand(), mod it with 5184 (72x72), and use that for the position
        in a row-major order grid.
        Call rand() again, mod it with 4 and use that for it's direction with
        the ordering: 0:west, 1:north, 2:east, 3:south.
        Do that for each kind of creature.
        10 Food
        10 Hopper
        10 Rover
        10 Trap
        10 Best
        Simulate 1000 moves.
        Best MUST outnumber ALL other species for the bonus pts.
        Print every 100th grid.
        */
		int pos;
		int row;
		int col;
		int dNum;
		char direction;
		char directions[4] = { 'w', 'n', 'e', 's' };
		Game z = Game(72,72);
		//add food
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'f',direction);
		}
		//add hoppers
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'h',direction);
		}
		//add rovers
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'r',direction);
		}
		//add traps
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'t',direction);
		}
		//add bests
		for(int i = 0; i < 10; i++){
			pos = rand()%5184;
			row = pos/72;
			col = pos%72;
			
			dNum = rand()%4;
			direction = directions[dNum];
			z.AddCreature(row,col,'b',direction);
		}
		z.Simulate(1000,100);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
	//----
	// Acceptance Tests. Random generated by genTest.py, stored in genTest.out
	//----
	try {
        srand(0);
		cout << "*** Darwin 7x3 ***" << endl;
		Game x = Game(7,3);
		x.AddCreature(2,0,'f','s');
		x.AddCreature(4,0,'f','w');
		x.AddCreature(5,2,'t','n');
		x.AddCreature(5,0,'t','s');
		x.AddCreature(0,0,'r','n');
		x.AddCreature(6,0,'r','n');
		x.Simulate(48,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 8x3 ***" << endl;
		Game x = Game(8,3);
		x.AddCreature(3,0,'h','w');
		x.AddCreature(7,1,'r','n');
		x.AddCreature(3,1,'f','e');
		x.AddCreature(3,2,'f','e');
		x.AddCreature(6,2,'r','e');
		x.AddCreature(0,1,'r','n');
		x.Simulate(23,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 9x8 ***" << endl;
		Game x = Game(9,8);
		x.AddCreature(6,2,'r','n');
		x.AddCreature(5,0,'h','s');
		x.AddCreature(1,3,'r','w');
		x.AddCreature(6,4,'h','n');
		x.AddCreature(0,5,'t','s');
		x.AddCreature(7,5,'r','s');
		x.AddCreature(4,4,'f','w');
		x.Simulate(32,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 9x6 ***" << endl;
		Game x = Game(9,6);
		x.AddCreature(8,3,'f','n');
		x.AddCreature(3,2,'h','e');
		x.AddCreature(7,3,'f','n');
		x.AddCreature(5,4,'f','n');
		x.AddCreature(8,4,'f','s');
		x.Simulate(27,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 7x4 ***" << endl;
		Game x = Game(7,4);
		x.AddCreature(4,0,'t','e');
		x.AddCreature(4,3,'f','n');
		x.AddCreature(2,3,'t','w');
		x.AddCreature(5,0,'r','e');
		x.AddCreature(0,3,'t','w');
		x.AddCreature(1,3,'r','s');
		x.AddCreature(5,1,'f','s');
		x.Simulate(26,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 4x9 ***" << endl;
		Game x = Game(4,9);
		x.AddCreature(0,3,'f','s');
		x.AddCreature(2,4,'h','e');
		x.AddCreature(0,4,'t','w');
		x.AddCreature(1,7,'h','e');
		x.Simulate(5,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 8x9 ***" << endl;
		Game x = Game(8,9);
		x.AddCreature(4,0,'t','w');
		x.AddCreature(4,6,'h','e');
		x.AddCreature(3,4,'t','e');
		x.AddCreature(5,2,'r','s');
		x.Simulate(6,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 5x9 ***" << endl;
		Game x = Game(5,9);
		x.AddCreature(1,5,'f','e');
		x.AddCreature(4,2,'r','n');
		x.AddCreature(3,0,'f','n');
		x.Simulate(25,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 3x8 ***" << endl;
		Game x = Game(3,8);
		x.AddCreature(0,3,'h','s');
		x.AddCreature(0,5,'r','s');
		x.AddCreature(0,4,'f','w');
		x.AddCreature(1,0,'h','s');
		x.AddCreature(2,3,'h','w');
		x.Simulate(21,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		srand(0);
		cout << "*** Darwin 3x9 ***" << endl;
		Game x = Game(3,9);
		x.AddCreature(0,5,'h','s');
		x.AddCreature(2,8,'h','w');
		x.AddCreature(1,6,'r','e');
		x.Simulate(9,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

