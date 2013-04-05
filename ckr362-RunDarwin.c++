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
   
   // Programs
    Program food_program(2);
    food_program[0] = {LEFT, -1};
    food_program[1] = {GO, 0};
    Species food('f', &food_program);
    // Set up hopper
    Program hopper_program(2);
    hopper_program[0] = {HOP, -1};
    hopper_program[1] = {GO, 0};
    Species hopper('h', &hopper_program);
    // Set up Rover
    Program rover_program(11);
    rover_program[0] = {IF_ENEMY, 9};
    rover_program[1] = {IF_EMPTY, 7};
    rover_program[2] = {IF_RANDOM, 5};
    rover_program[3] = {LEFT, -1};
    rover_program[4] = {GO, 0};
    rover_program[5] = {RIGHT, -1};
    rover_program[6] = {GO, 0};
    rover_program[7] = {HOP, -1};
    rover_program[8] = {GO, 0};
    rover_program[9] = {INFECT, -1};
    rover_program[10] = {GO, 0};
    Species rover('r', &rover_program);
    // Set up Trap
    Program trap_program(5);
    trap_program[0] = {IF_ENEMY, 3};
    trap_program[1] = {LEFT, -1};
    trap_program[2] = {GO, 0};
    trap_program[3] = {INFECT, -1};
    trap_program[4] = {GO, 0};
    Species trap('t', &trap_program);
    // Set up best
    Program best_program(10);
    // Details hidden to protect the innocent :P
    Species best('b', &best_program);
  
    // ----------
    // darwin 1x1
    // ----------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
       
          Darwin darwin(1,1);
          darwin.add_creature({0,0}, food, 1);
          darwin.simulate_turns(5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 1x1
    // ----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
       
          Darwin darwin(10,1);
          darwin.add_creature({5,0}, rover, 2);
          darwin.simulate_turns(5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

// ------------
    // darwin 10x10
    // ------------

    try {
        cout << "*** Darwin 10x10 without best ***" << endl;
        srand(0);
       int n = 10;
       int mod = n*n;
          Darwin darwin(10,10);
          for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, food, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, hopper, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, rover, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, trap, dir);
        } 
     
        darwin.simulate_turns(60, 5);
          
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 10x10
    // ------------

    try {
        cout << "*** Darwin 10x10 with best ***" << endl;
        srand(0);
       int n = 10;
       int mod = n*n;
          Darwin darwin(10,10);
          for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, food, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, hopper, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, rover, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, trap, dir);
        } 
        for ( int i = 0; i < 20; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, best, dir);
        } 
        darwin.simulate_turns(60, 5);
          
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 8x8
    // ----------


    try {
        cout << "*** Darwin 8x8 ***" << endl;
        srand(0);
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
          Darwin darwin(8,8);
          darwin.add_creature({0,0}, food, 2);
          darwin.add_creature({3,3}, hopper, 1);
          darwin.add_creature({3,4}, hopper, 2);
          darwin.add_creature({4,4}, hopper, 3);
          darwin.add_creature({4,3}, hopper, 0);
          darwin.add_creature({7,7}, food, 1);
          darwin.simulate_turns(5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 25x25
    // ----------


    try {
        cout << "*** Darwin 25x25 without best ***" << endl;
        srand(0);
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
        int n = 25;
        int mod = 25*25;
        Darwin darwin(n,n);
        for ( int i = 0; i < 200; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, food, dir);
        } 
        for ( int i = 0; i < 200; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, hopper, dir);
        } 
        for ( int i = 0; i < 1; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, rover, dir);
        } 
        darwin.simulate_turns(60, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        try {
        cout << "*** Darwin 25x25 with best ***" << endl;
        srand(0);
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
        int n = 25;
        int mod = 25*25;
        Darwin darwin(n,n);
        for ( int i = 0; i < 200; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, food, dir);
        } 
        for ( int i = 0; i < 200; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, best, dir);
        } 
        for ( int i = 0; i < 1; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n, pos%n}, trap, dir);
        } 
        darwin.simulate_turns(60, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	try {
		cout << "*** Darwin 5x5 ***" << endl;
		srand(0);
		Darwin darwin(5,5);
		darwin.add_creature({0,2}, rover, 3);
		darwin.add_creature({2,0}, rover, 2);
		darwin.add_creature({2,2}, trap,  1);
		darwin.add_creature({2,4}, rover, 0);
		darwin.add_creature({4,2}, rover, 1);
		darwin.simulate_turns(5);
		

	} catch (...) {
		assert(false);
	}
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
        Darwin darwin(7,9);
        darwin.add_creature({0, 0},trap, 3 );
        darwin.add_creature({3, 2},hopper, 2);
        darwin.add_creature({5, 4},rover, 1 );
        darwin.add_creature({6, 8},trap, 0 );
        darwin.simulate_turns(5);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



        try {
        cout << "*** Darwin 3x3 ***" << endl;
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
        Darwin darwin(3,3);
        darwin.add_creature({0, 0},trap, 3 );
        darwin.add_creature({0, 1},hopper, 2);
        darwin.add_creature({2, 2},rover, 1 );
        darwin.add_creature({1, 2},trap, 0 );
        darwin.simulate_turns(10);

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
        
        Darwin darwin(72,72);
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, food, dir);
        }
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, hopper, dir);
        }
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c},rover, dir);
        }
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, trap, dir);
        }

        darwin.simulate_turns(1000, 100);

       

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& oor) {
        assert(false);}

    // ------------
    // darwin 100x100
    // without best
    // ------------

    try {
        cout << "*** Darwin 100x100 without Best ***" << endl;
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
        int n = 100;
        int mod = n*n;
        Darwin darwin(n,n);
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, food, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, hopper, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;            
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n},rover, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, trap, dir);
        }

        darwin.simulate_turns(1000, 100);
       

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& oor) {
        std::cout << "Out of Range error: " << oor.what() << '\n' << std::endl;
        assert(false);}

        // ------------
    // darwin 100x100
    // without best
    // ------------

    try {
        cout << "*** Darwin 100x100 with Best ***" << endl;
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
        int n = 100;
        int mod = n*n;
        Darwin darwin(n,n);
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, food, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, hopper, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;            
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n},rover, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, trap, dir);
        }
        for(int i = 0; i < n; ++i) {
            int pos = rand() % mod;
            int dir = rand() % 4;
            darwin.add_creature({pos/n,pos%n}, best, dir);
        }
        darwin.simulate_turns(1000, 100);
       

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range& oor) {
        std::cout << "Out of Range error: " << oor.what() << '\n' << std::endl;
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
        Darwin darwin(72,72);
          for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, food, dir);
        }
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, hopper, dir);
        }
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c},rover, dir);
        }
        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, trap, dir);
        }

        for(int i = 0; i < 10; ++i) {
            int pos = rand() % 5184;
            int r = pos / 72;
            int c = pos % 72;
            int dir = rand() % 4;
            darwin.add_creature({r,c}, best, dir);
        }
        darwin.simulate_turns(1000, 100);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
