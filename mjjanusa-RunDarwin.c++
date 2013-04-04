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
#include <string>
#include <map>
#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    	map<std::string, species> SpeciesTable;
	string foodProgram [2] = {"left",
							  "go 0"};
	std::vector<std::string> foodProgram_v(std::begin(foodProgram), std::end(foodProgram));
	string hopperProgram [2] = {"hop",
							    "go 0"};
	std::vector<std::string> hopperProgram_v(std::begin(hopperProgram), std::end(hopperProgram));
	string roverProgram [11] = {"if_enemy 9",
								"if_empty 7",
								"if_random 5",
								"left",
								"go 0",
								"right",
								"go 0",
								"hop",
								"go 0",
								"infect",
								"go 0"};
	std::vector<std::string> roverProgram_v(std::begin(roverProgram), std::end(roverProgram));
	//same as rover for class repo
	string bestProgram [11] = {"if_enemy 9",
								"if_empty 7",
								"if_random 5",
								"left",
								"go 0",
								"right",
								"go 0",
								"hop",
								"go 0",
								"infect",
								"go 0"};
	std::vector<std::string> bestProgram_v(std::begin(bestProgram), std::end(bestProgram));
	string trapProgram [5] = {"if_enemy 3",
							  "left",
							  "go 0",
							  "infect",
						   	  "go 0"};
	std::vector<std::string> trapProgram_v(std::begin(trapProgram), std::end(trapProgram));
	SpeciesTable.insert( pair<string, species>( string("f"), species( string("f"), foodProgram_v ) ) );
	SpeciesTable.insert( pair<string, species>( string("h"), species( string("h"), hopperProgram_v ) ) );
	SpeciesTable.insert( pair<string, species>( string("r"), species( string("r"), roverProgram_v ) ) );
	SpeciesTable.insert( pair<string, species>( string("b"), species( string("b"), bestProgram_v ) ) );
	SpeciesTable.insert( pair<string, species>( string("t"), species( string("t"), trapProgram_v ) ) );

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
        */
		game world( 8, 8, SpeciesTable );
		world.addCreature(SpeciesTable.find(string("f"))->second, 1, 0, 0);
		world.addCreature(SpeciesTable.find(string("h"))->second, 0, 3, 3);
		world.addCreature(SpeciesTable.find(string("h"))->second, 1, 4, 3);
		world.addCreature(SpeciesTable.find(string("h"))->second, 2, 4, 4);
		world.addCreature(SpeciesTable.find(string("h"))->second, 3, 3, 4);
		world.addCreature(SpeciesTable.find(string("f"))->second, 0, 7, 7);
		world.sortBoard();
		cout << "Turn = 0." << endl;
		world.printGrid();
		for ( int i = 1; i < 6; ++i ){
			cout << "Turn = " << i << "." << endl;
			world.step();
			world.printGrid();
		}

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
	game world( 9, 7, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 0, 0);
	world.addCreature(SpeciesTable.find(string("h"))->second, 1, 2, 3);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 4, 5);
	world.addCreature(SpeciesTable.find(string("t"))->second, 3, 8, 6);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 6; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
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
        game world( 72, 72, SpeciesTable );
        //add food
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("f"))->second, direction, position);  
		}		
        }
        //add hopper
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4; 
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("h"))->second, direction, position);  
		}		
        }
        //add rover
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("r"))->second, direction, position);  
		}		
        }
        //add trap
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("t"))->second, direction, position); 
		}		
        }
        world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 1001; ++i ){
		world.step();
		if(i % 100 == 0){
			cout << "Turn = " << i << "." << endl;
			world.printGrid();
		}
	}
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
        game world( 72, 72, SpeciesTable );
        //add food
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("f"))->second, direction, position);  
		}		
        }
        //add hopper
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4; 
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("h"))->second, direction, position);  
		}		
        }
        //add rover
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("r"))->second, direction, position);  
		}		
        }
        //add trap
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("t"))->second, direction, position); 
		}		
        }
        //add best
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 5184;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("b"))->second, direction, position); 
		}		
        }
        world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 1001; ++i ){
		world.step();
		if(i % 100 == 0){
			cout << "Turn = " << i << "." << endl;
			world.printGrid();
		}
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        
    
    // ----------
    // darwin 10x10 -- Acceptance Test 1
    // ----------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);

	game world( 10, 10, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 3, 6);
	world.addCreature(SpeciesTable.find(string("r"))->second, 1, 5, 3);
	world.addCreature(SpeciesTable.find(string("r"))->second, 2, 8, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 3, 9, 1);
	world.addCreature(SpeciesTable.find(string("b"))->second, 0, 5, 2);
	world.addCreature(SpeciesTable.find(string("b"))->second, 1, 9, 4);
	world.addCreature(SpeciesTable.find(string("b"))->second, 2, 3, 1);
	world.addCreature(SpeciesTable.find(string("b"))->second, 3, 0, 0);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 10; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 2x2 -- Acceptance Test 2
    // ----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);

	game world( 2, 2, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 0, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 0, 1);
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 1, 0);
	world.addCreature(SpeciesTable.find(string("r"))->second, 3, 1, 1);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 10; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    
    // ----------
    // darwin 3x3 -- Acceptance Test 3
    // ----------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);

	game world( 3, 3, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 0, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 0, 2);
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 2, 0);
	world.addCreature(SpeciesTable.find(string("r"))->second, 3, 2, 2);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 10; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 4x4 -- Acceptance Test 4
    // ----------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
        srand(0);

	game world( 4, 4, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("r"))->second, 1, 0, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 0, 2);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 2, 0);
	world.addCreature(SpeciesTable.find(string("r"))->second, 1, 2, 2);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 10; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------
    // darwin 15x12 -- Acceptance Test 5
    // ------------

    try {
        cout << "*** Darwin 15x12 ***" << endl;
        srand(0);
        game world( 15, 12, SpeciesTable );
        //add food
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 180;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("f"))->second, direction, position);  
		}		
        }
        //add rover
        for(int i = 0; i < 5; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 180;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("r"))->second, direction, position);  
		}		
        }
        //add trap
        for(int i = 0; i < 5; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 180;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("t"))->second, direction, position); 
		}		
        }
        world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 11; ++i ){
		world.step();
		cout << "Turn = " << i << "." << endl;
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------
    // darwin 6x5 -- Acceptance Test 6
    // ------------

    try {
        cout << "*** Darwin 6 x 5 ***" << endl;
        srand(0);
        game world( 6, 5, SpeciesTable );
        //add food
        for(int i = 0; i < 2; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 30;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("f"))->second, direction, position);  
		}		
        }
        //add rover
        for(int i = 0; i < 2; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 30;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("r"))->second, direction, position);  
		}		
        }
        //add trap
        for(int i = 0; i < 3; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 30;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("t"))->second, direction, position); 
		}		
        }
        world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 11; ++i ){
		world.step();
		cout << "Turn = " << i << "." << endl;
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        // ------------
    // darwin 6x7 -- Acceptance Test 7
    // ------------

    try {
        cout << "*** Darwin 6 x 7 ***" << endl;
        srand(0);
        game world( 6, 7, SpeciesTable );
        //add food
        for(int i = 0; i < 10; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 42;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("f"))->second, direction, position);  
		}		
        }
        //add rover
        for(int i = 0; i < 3; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 42;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("r"))->second, direction, position);  
		}		
        }
        //add trap
        for(int i = 0; i < 2; i++) { 
        	bool success = false; 
		while(!success){
			int position = rand() % 42;
			int direction = rand() % 4;
			//switch direction to match our definition 
			direction = direction - 1;
			if(direction == -1)
				direction = 3;
			success = world.addCreature(SpeciesTable.find(string("t"))->second, direction, position); 
		}		
        }
        world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 11; ++i ){
		world.step();
		cout << "Turn = " << i << "." << endl;
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        // ----------
    // darwin 4x5 -- Acceptance Test 8
    // ----------

    try {
        cout << "*** Darwin 4x5 Rovers Take out the Hoppers ***" << endl;
        srand(0);

	game world( 4, 5, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("h"))->second, 2, 0, 0);
	world.addCreature(SpeciesTable.find(string("h"))->second, 2, 1, 0);
	world.addCreature(SpeciesTable.find(string("h"))->second, 2, 2, 0);
	world.addCreature(SpeciesTable.find(string("h"))->second, 2, 3, 0);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 0, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 1, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 2, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 3, 4);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 4; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
     // ----------
    // darwin 4x5 -- Acceptance Test 9
    // ----------

    try {
        cout << "*** Darwin 4x5 Traps Win ***" << endl;
        srand(0);

	game world( 4, 5, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 0, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 1, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 2, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 1, 3, 0);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 0, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 1, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 2, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 3, 4);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 5; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
     // ----------
    // darwin 4x5 -- Acceptance Test 10
    // ----------

    try {
        cout << "*** Darwin 4x5 Rovers Win ***" << endl;
        srand(0);

	game world( 4, 5, SpeciesTable );
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 0, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 1, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 2, 0);
	world.addCreature(SpeciesTable.find(string("t"))->second, 2, 3, 0);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 0, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 1, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 2, 4);
	world.addCreature(SpeciesTable.find(string("r"))->second, 0, 3, 4);
	world.sortBoard();
	cout << "Turn = 0." << endl;
	world.printGrid();
	for ( int i = 1; i < 5; ++i ){
		cout << "Turn = " << i << "." << endl;
		world.step();
		world.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



return 0;}

    

