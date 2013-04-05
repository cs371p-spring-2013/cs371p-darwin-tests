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

    // ----------
    // darwin 8x8
    // ----------

    try {
        cout << "*** Darwin 8x8 ***" << endl;
        /*
        8x8 Darwin
        Food,   facing east,  at (0, 0)
        Hopper, facing north, at (3, 3)
        Hopper, facing east,  at (3, 4)
        Hopper, facing south, at (4, 4)
        Hopper, facing west,  at (4, 3)
        Food,   facing north, at (7, 7)
        Simulate 5 moves.
        Print every grid.
        */
        	Grid g = Grid(5,1,8,8);
		g.place_creature(EAST, FOOD, 0, 0);
		g.place_creature(NORTH, HOPPER, 3, 3);
		g.place_creature(EAST, HOPPER, 3, 4);
		g.place_creature(SOUTH, HOPPER, 4, 4);
		g.place_creature(WEST, HOPPER, 4, 3);
		g.place_creature(NORTH, FOOD, 7, 7);
		g.executeGrid();
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
        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
        	Grid g = Grid(5,1,7,9);
		g.place_creature(SOUTH, TRAP, 0, 0);
		g.place_creature(EAST, HOPPER, 3, 2);
		g.place_creature(NORTH, ROVER, 5, 4);
		g.place_creature(WEST, TRAP, 6, 8);
		g.executeGrid();
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
        	Grid g = Grid(1000,100,72,72);
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,FOOD,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,HOPPER,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,ROVER,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,TRAP,pos/72,pos%72);
        	}
		g.executeGrid();
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
        //cout << "*** Darwin 72x72 with Best ***" << endl;
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
        	Grid g = Grid(1000,100,72,72);
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,FOOD,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,HOPPER,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,ROVER,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,TRAP,pos/72,pos%72);
        	}
        	for(int i = 0; i < 10; ++i) {
			int pos = rand() % 5184;
			Direction dir = (Direction)(rand() % 4);
			g.place_creature(dir,BEST,pos/72,pos%72);
        	}
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
    try {
        cout << "*** Darwin 8x8 Testing Hoppers ***" << endl;
        	Grid g = Grid(7,1,8,8);
		g.place_creature(SOUTH, HOPPER, 0, 0);        	
		g.place_creature(NORTH, HOPPER, 7, 7);		
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}        
        
    try {
        cout << "*** Darwin 4x4 Testing Rover and Trap ***" << endl;
        	Grid g = Grid(5,1,4,4);
		g.place_creature(SOUTH, ROVER, 0, 0);        	
		g.place_creature(NORTH, TRAP, 3, 0);		
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}  
        
    try {
        cout << "*** Darwin 7x7 Testing Rover and Trap ***" << endl;
        	Grid g = Grid(5,1,7,7);
		g.place_creature(SOUTH, ROVER, 0, 0);        	
		g.place_creature(NORTH, TRAP, 6, 0);		
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}  
        
    try {
        cout << "*** Darwin 8x8 with every Creature ***" << endl;
        	Grid g = Grid(15,1,8,8);
		g.place_creature(SOUTH, HOPPER, 3, 5);        	
		g.place_creature(NORTH, FOOD, 7, 7);		
		g.place_creature(EAST, TRAP, 5, 4);
		g.place_creature(EAST, ROVER, 7,0);		
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}  
        
    try {
        cout << "*** Darwin 4x4 with Hoppers and a single Trap ***" << endl;
        	Grid g = Grid(5,1,4,4);
		g.place_creature(NORTH, HOPPER, 0, 0);		
		g.place_creature(WEST, HOPPER, 0,3);		
		g.place_creature(NORTH, HOPPER, 3,3);		
		g.place_creature(SOUTH, HOPPER, 1, 3);		
		g.place_creature(EAST, HOPPER, 2, 3);		
		g.place_creature(NORTH, TRAP, 3, 3);		
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}  
        
    try {
        cout << "*** Darwin 7x7 with Food and Rovers ***" << endl;
        	Grid g = Grid(7,1,7,7);
		g.place_creature(SOUTH, FOOD, 2, 3);        	
		g.place_creature(NORTH, ROVER, 3, 6);		
		g.place_creature(EAST, ROVER, 0, 0);			
		g.place_creature(EAST, ROVER, 2, 0);			
		g.executeGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}          
       
        
        

    return 0;}

