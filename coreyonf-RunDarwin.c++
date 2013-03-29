// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall RunCollatz.c++ -o RunCollatz.c++.app
    % valgrind RunDarwin.c++.app > RunDarwin.out

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
using namespace std;
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
    
    // ------------------
    // darwin 1x1 failure
	// ------------------
	
	try {
        cout << "*** Darwin 1x1 too many creatures ***" << endl;
				Game darwin(1, 1);
				darwin.addCreature(FOOD, 0,0, RIGHT);
				assert(0 == darwin.addCreature(HOPPER, 0,0, UP));
				cout << "Success." << endl;
        }
    catch (const invalid_argument&) {
    	cout << "!!!!!!!!!!!!!!!!!!!!INVALID ARGUMENT!!!!!!!!!!!!!!!" << endl;
        assert(false);}
    catch (const out_of_range&) {
    	cout << "!!!!!!!!!!!!!!!!!!!OUT OF RANGE!!!!!!!!!!!!!!!!!!!!" << endl;
        assert(false);}
        
    
        
    // ------------------
    // darwin 1x1 failure
	// ------------------
	
	try {
        cout << "*** Darwin 1x1 out of map ***" << endl;
				Game darwin(1, 1);
				assert (0 == darwin.addCreature(FOOD, 0,3, RIGHT));
				cout << "Success." <<endl;
        }
    catch (...) {
    	cout << "Dat's bad, yo" << endl;
    	}
        
          
    // ----------
    // darwin 4x4
    // ----------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
				Game darwin(4, 4);
				darwin.addCreature(FOOD, 0,0, RIGHT);
				darwin.addCreature(HOPPER, 0,3, UP);
				darwin.addCreature(HOPPER, 3, 0, DOWN);
				darwin.addCreature(FOOD, 3,3, UP);
				darwin.run(5, 1);
				
        }
    catch (const invalid_argument&) {
    	cout << "!!!!!!!!!!!!!!!!!!!!INVALID ARGUMENT!!!!!!!!!!!!!!!" << endl;
        assert(false);}
    catch (const out_of_range&) {
    	cout << "!!!!!!!!!!!!!!!!!!!OUT OF RANGE!!!!!!!!!!!!!!!!!!!!" << endl;
        assert(false);}
        
        
        
        try {
        cout << "*** Darwin 4x4 (2) ***" << endl;
				Game darwin(4, 4);
				darwin.addCreature(FOOD, 0,0, RIGHT);
				darwin.addCreature(BEST, 0,3, UP);
				darwin.addCreature(BEST, 3, 0, DOWN);
				darwin.addCreature(FOOD, 3,3, UP);
				darwin.run(5, 1);
				
        }
    catch (const invalid_argument&) {
    	cout << "!!!!!!!!!!!!!!!!!!!!INVALID ARGUMENT!!!!!!!!!!!!!!!" << endl;
        assert(false);}
    catch (const out_of_range&) {
    	cout << "!!!!!!!!!!!!!!!!!!!OUT OF RANGE!!!!!!!!!!!!!!!!!!!!" << endl;
        assert(false);}
        
        
        
        try {
        cout << "*** Darwin 4x4 (3)***" << endl;
				Game darwin(4, 4);
				darwin.addCreature(FOOD, 0,0, RIGHT);
				darwin.addCreature(TRAP, 0,3, UP);
				darwin.addCreature(ROVER, 3, 0, DOWN);
				darwin.addCreature(FOOD, 3,3, UP);
				darwin.run(100, 50);
				
        }
    catch (const invalid_argument&) {
    	cout << "!!!!!!!!!!!!!!!!!!!!INVALID ARGUMENT!!!!!!!!!!!!!!!" << endl;
        assert(false);}
    catch (const out_of_range&) {
    	cout << "!!!!!!!!!!!!!!!!!!!OUT OF RANGE!!!!!!!!!!!!!!!!!!!!" << endl;
        assert(false);}
            
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
				Game darwin(8, 8);
				darwin.addCreature(FOOD, 0,0, RIGHT);
				darwin.addCreature(HOPPER, 3,3, UP);
				darwin.addCreature(HOPPER, 3, 4, RIGHT);
				darwin.addCreature(HOPPER, 4,4, DOWN);
				darwin.addCreature(HOPPER, 4,3, LEFT);
				darwin.addCreature(FOOD, 7,7, UP);
				darwin.run(5, 1);
				
        }
    catch (const invalid_argument&) {
    	cout << "!!!!!!!!!!!!!!!!!!!!INVALID ARGUMENT!!!!!!!!!!!!!!!" << endl;
        assert(false);}
    catch (const out_of_range&) {
    	cout << "!!!!!!!!!!!!!!!!!!!OUT OF RANGE!!!!!!!!!!!!!!!!!!!!" << endl;
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
        
        Game darwin(7, 9);
		darwin.addCreature(TRAP, 0,0, DOWN);
		darwin.addCreature(HOPPER, 3,2, RIGHT);
		darwin.addCreature(ROVER, 5, 4, UP);
		darwin.addCreature(TRAP, 6,8, LEFT);
		darwin.run(5, 1);
        
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
        Game darwin(72,72);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        
        //darwin.run(1000, 100);
    }
    catch (const invalid_argument&) {
    	cout << "Invalid argument" << endl;
        assert(false);}
    catch (const out_of_range&) {
    	cout << "out of range" << endl;
        assert(false);}
        
        try {
        cout << "*** Darwin 72x72 without Best (2) ***" << endl;
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
        Simulate 100 moves.
        Print every 10th grid.
        */
        Game darwin(72,72);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        
        darwin.run(100, 10);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Darwin 72x72 without Best (3)***" << endl;
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
        Simulate 100 moves.
        Print every 10th grid.
        */
        Game darwin(72,72);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        
        darwin.run(100, 10);
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
        Game darwin(72,72);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 50) {
        	darwin.addCreature(BEST, rand()%72, rand()%72, rand()%4);
        }
        darwin.run(1000, 100);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Darwin 72x72 with Best (2)***" << endl;
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
        Game darwin(72,72);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 50) {
        	darwin.addCreature(BEST, rand()%72, rand()%72, rand()%4);
        }
        darwin.run(1000, 100);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Darwin 72x72 with Best (3)***" << endl;
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
        Game darwin(72,72);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 50) {
        	darwin.addCreature(BEST, rand()%72, rand()%72, rand()%4);
        }
        darwin.run(1000, 100);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
		cout << "STRESS TEST!!! Running 500 darwins of size 50x50 with 50 random stuff" <<endl;
	
	for (int i = 0; i < 500; i++) {
	
		try {
			cout << "Stress test #" << i+1 << " commencing...";
		    Game darwin(50,50);
        while (darwin.num_creatures() < 10) {
        	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 20) {
        	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 30) {
        	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 40) {
        	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
        }
        while (darwin.num_creatures() < 50) {
        	darwin.addCreature(BEST, rand()%72, rand()%72, rand()%4);
        }
        darwin.run(1000, -1);
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
		cout << "stress test #" << i+1 << " successful." <<endl;
	}
		
		
        cout << "STRESS TEST PART TWO!!! Running 500 darwins of size 100x100 with 100 random stuff" <<endl;
	
	for (int i = 0; i < 500; i++) {
	
		try {
			cout << "Stress test #" << i+501 << " commencing...";
		    Game darwin(100,100);
		    while (darwin.num_creatures() < 20) {
		    	darwin.addCreature(FOOD, rand()%72, rand()%72, rand()%4);
		    }
		    while (darwin.num_creatures() < 40) {
		    	darwin.addCreature(HOPPER, rand()%72, rand()%72, rand()%4);
		    }
		    while (darwin.num_creatures() < 60) {
		    	darwin.addCreature(ROVER, rand()%72, rand()%72, rand()%4);
		    }
		    while (darwin.num_creatures() < 80) {
		    	darwin.addCreature(TRAP, rand()%72, rand()%72, rand()%4);
		    }
		    while (darwin.num_creatures() < 100) {
        	darwin.addCreature(BEST, rand()%72, rand()%72, rand()%4);
        }
		    darwin.run(1000, -1);
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
		cout << "stress test #" << i+501 << " successful." <<endl;
	} cout << "All stress tests successfull!" << endl;
	
	cout << "Done with RunDarwin.c++"<<endl;
    return 0;}
