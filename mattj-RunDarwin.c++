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
    //ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

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
        
        
        Hopper h = Hopper();
        Food f = Food();
        
        Creature c1 = Creature(f, EAST);
        Creature c2 = Creature(h, NORTH);
        Creature c3 = Creature(h, EAST);
        Creature c4 = Creature(h, SOUTH);
        Creature c5 = Creature(h, WEST);
        Creature c6 = Creature(f, NORTH);
        
        
        Board board = Board(8, 8);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 3, 3);
        board.placeCreature(&c3, 3, 4);
        board.placeCreature(&c4, 4, 4);
        board.placeCreature(&c5, 4, 3);
        board.placeCreature(&c6, 7, 7);
        
        board.printBoard();
        for(int i = 0; i < 5; i++){
        	board.doTurn(1);
       		board.printBoard();
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
        
        Hopper h = Hopper();
        Trap t = Trap();
        Rover r = Rover();
        
        Creature c1 = Creature(t, SOUTH);
        Creature c2 = Creature(h, EAST);
        Creature c3 = Creature(r, NORTH);
        Creature c4 = Creature(t, WEST);
        
        Board board = Board(7, 9);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 3, 2);
        board.placeCreature(&c3, 5, 4);
        board.placeCreature(&c4, 6, 8);
        
        board.printBoard();
        for(int i = 0; i < 50; i++){
        	board.doTurn(1);
       		board.printBoard();
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
        
        
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Trap t = Trap();
        
        int position[40];
        int direction[40];
        
        for(int i = 0; i < 40; i++){
        	position[i] = rand()%5184;
        	direction[i] = rand()%4 +1;
        }

        Creature c1 = Creature(f, direction[0]);
        Creature c2 = Creature(f, direction[1]);
        Creature c3 = Creature(f, direction[2]);
        Creature c4 = Creature(f, direction[3]);
        Creature c5 = Creature(f, direction[4]);
        Creature c6 = Creature(f, direction[5]);
        Creature c7 = Creature(f, direction[6]);
        Creature c8 = Creature(f, direction[7]);
        Creature c9 = Creature(f, direction[8]);
        Creature c10 = Creature(f, direction[9]);
        
        Creature c11 = Creature(h, direction[10]);
        Creature c12 = Creature(h, direction[11]);
        Creature c13 = Creature(h, direction[12]);
        Creature c14 = Creature(h, direction[13]);
        Creature c15 = Creature(h, direction[14]);
        Creature c16 = Creature(h, direction[15]);
        Creature c17 = Creature(h, direction[16]);
        Creature c18 = Creature(h, direction[17]);
        Creature c19 = Creature(h, direction[18]);
        Creature c20 = Creature(h, direction[19]);
        
        Creature c21 = Creature(r, direction[20]);
        Creature c22 = Creature(r, direction[21]);
        Creature c23 = Creature(r, direction[22]);
        Creature c24 = Creature(r, direction[23]);
        Creature c25 = Creature(r, direction[24]);
        Creature c26 = Creature(r, direction[25]);
        Creature c27 = Creature(r, direction[26]);
        Creature c28 = Creature(r, direction[27]);
        Creature c29 = Creature(r, direction[28]);
        Creature c30 = Creature(r, direction[29]);
        
        Creature c31 = Creature(t, direction[30]);
        Creature c32 = Creature(t, direction[31]);
        Creature c33 = Creature(t, direction[32]);
        Creature c34 = Creature(t, direction[33]);
        Creature c35 = Creature(t, direction[34]);
        Creature c36 = Creature(t, direction[35]);
        Creature c37 = Creature(t, direction[36]);
        Creature c38 = Creature(t, direction[37]);
        Creature c39 = Creature(t, direction[38]);
        Creature c40 = Creature(t, direction[39]);
        
        
        Board board = Board(72, 72);
        board.placeCreature(&c1, position[0]);
        board.placeCreature(&c2, position[1]);
        board.placeCreature(&c3, position[2]);
        board.placeCreature(&c4, position[3]);
        board.placeCreature(&c5, position[4]);
        board.placeCreature(&c6, position[5]);
        board.placeCreature(&c7, position[6]);
        board.placeCreature(&c8, position[7]);
        board.placeCreature(&c9, position[8]);
        board.placeCreature(&c10, position[9]);
        board.placeCreature(&c11, position[10]);
        board.placeCreature(&c12, position[11]);
        board.placeCreature(&c13, position[12]);
        board.placeCreature(&c14, position[13]);
        board.placeCreature(&c15, position[14]);
        board.placeCreature(&c16, position[15]);
        board.placeCreature(&c17, position[16]);
        board.placeCreature(&c18, position[17]);
        board.placeCreature(&c19, position[18]);
        board.placeCreature(&c20, position[19]);
        board.placeCreature(&c21, position[20]);
        board.placeCreature(&c22, position[21]);
        board.placeCreature(&c23, position[22]);
        board.placeCreature(&c24, position[23]);
        board.placeCreature(&c25, position[24]);
        board.placeCreature(&c26, position[25]);
        board.placeCreature(&c27, position[26]);
        board.placeCreature(&c28, position[27]);
        board.placeCreature(&c29, position[28]);
        board.placeCreature(&c30, position[29]);
        board.placeCreature(&c31, position[30]);
        board.placeCreature(&c32, position[31]);
        board.placeCreature(&c33, position[32]);
        board.placeCreature(&c34, position[33]);
        board.placeCreature(&c35, position[34]);
        board.placeCreature(&c36, position[35]);
        board.placeCreature(&c37, position[36]);
        board.placeCreature(&c38, position[37]);
        board.placeCreature(&c39, position[38]);
        board.placeCreature(&c40, position[39]);
        
        
        board.printBoard();
        for(int i = 0; i < 10; i++){
		    board.doTurn(100);
		    board.printBoard();
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
        
     
        Food f = Food();
        Hopper h = Hopper();
        Rover r = Rover();
        Trap t = Trap();
        Best b = Best();
        
        int position[50];
        int direction[50];
        
        for(int i = 0; i < 50; i++){
        	position[i] = rand()%5184;
        	direction[i] = rand()%4 +1;
        }

        Creature c1 = Creature(f, direction[0]);
        Creature c2 = Creature(f, direction[1]);
        Creature c3 = Creature(f, direction[2]);
        Creature c4 = Creature(f, direction[3]);
        Creature c5 = Creature(f, direction[4]);
        Creature c6 = Creature(f, direction[5]);
        Creature c7 = Creature(f, direction[6]);
        Creature c8 = Creature(f, direction[7]);
        Creature c9 = Creature(f, direction[8]);
        Creature c10 = Creature(f, direction[9]);
        
        Creature c11 = Creature(h, direction[10]);
        Creature c12 = Creature(h, direction[11]);
        Creature c13 = Creature(h, direction[12]);
        Creature c14 = Creature(h, direction[13]);
        Creature c15 = Creature(h, direction[14]);
        Creature c16 = Creature(h, direction[15]);
        Creature c17 = Creature(h, direction[16]);
        Creature c18 = Creature(h, direction[17]);
        Creature c19 = Creature(h, direction[18]);
        Creature c20 = Creature(h, direction[19]);
        
        Creature c21 = Creature(r, direction[20]);
        Creature c22 = Creature(r, direction[21]);
        Creature c23 = Creature(r, direction[22]);
        Creature c24 = Creature(r, direction[23]);
        Creature c25 = Creature(r, direction[24]);
        Creature c26 = Creature(r, direction[25]);
        Creature c27 = Creature(r, direction[26]);
        Creature c28 = Creature(r, direction[27]);
        Creature c29 = Creature(r, direction[28]);
        Creature c30 = Creature(r, direction[29]);
        
        Creature c31 = Creature(t, direction[30]);
        Creature c32 = Creature(t, direction[31]);
        Creature c33 = Creature(t, direction[32]);
        Creature c34 = Creature(t, direction[33]);
        Creature c35 = Creature(t, direction[34]);
        Creature c36 = Creature(t, direction[35]);
        Creature c37 = Creature(t, direction[36]);
        Creature c38 = Creature(t, direction[37]);
        Creature c39 = Creature(t, direction[38]);
        Creature c40 = Creature(t, direction[39]);
        
        Creature c41 = Creature(b, direction[40]);
        Creature c42 = Creature(b, direction[41]);
        Creature c43 = Creature(b, direction[42]);
        Creature c44 = Creature(b, direction[43]);
        Creature c45 = Creature(b, direction[44]);
        Creature c46 = Creature(b, direction[45]);
        Creature c47 = Creature(b, direction[46]);
        Creature c48 = Creature(b, direction[47]);
        Creature c49 = Creature(b, direction[48]);
        Creature c50 = Creature(b, direction[49]);
        
        
        Board board = Board(72, 72);
        board.placeCreature(&c1, position[0]);
        board.placeCreature(&c2, position[1]);
        board.placeCreature(&c3, position[2]);
        board.placeCreature(&c4, position[3]);
        board.placeCreature(&c5, position[4]);
        board.placeCreature(&c6, position[5]);
        board.placeCreature(&c7, position[6]);
        board.placeCreature(&c8, position[7]);
        board.placeCreature(&c9, position[8]);
        board.placeCreature(&c10, position[9]);
        board.placeCreature(&c11, position[10]);
        board.placeCreature(&c12, position[11]);
        board.placeCreature(&c13, position[12]);
        board.placeCreature(&c14, position[13]);
        board.placeCreature(&c15, position[14]);
        board.placeCreature(&c16, position[15]);
        board.placeCreature(&c17, position[16]);
        board.placeCreature(&c18, position[17]);
        board.placeCreature(&c19, position[18]);
        board.placeCreature(&c20, position[19]);
        board.placeCreature(&c21, position[20]);
        board.placeCreature(&c22, position[21]);
        board.placeCreature(&c23, position[22]);
        board.placeCreature(&c24, position[23]);
        board.placeCreature(&c25, position[24]);
        board.placeCreature(&c26, position[25]);
        board.placeCreature(&c27, position[26]);
        board.placeCreature(&c28, position[27]);
        board.placeCreature(&c29, position[28]);
        board.placeCreature(&c30, position[29]);
        board.placeCreature(&c31, position[30]);
        board.placeCreature(&c32, position[31]);
        board.placeCreature(&c33, position[32]);
        board.placeCreature(&c34, position[33]);
        board.placeCreature(&c35, position[34]);
        board.placeCreature(&c36, position[35]);
        board.placeCreature(&c37, position[36]);
        board.placeCreature(&c38, position[37]);
        board.placeCreature(&c39, position[38]);
        board.placeCreature(&c40, position[39]);
        board.placeCreature(&c41, position[40]);
        board.placeCreature(&c42, position[41]);
        board.placeCreature(&c43, position[42]);
        board.placeCreature(&c44, position[43]);
        board.placeCreature(&c45, position[44]);
        board.placeCreature(&c46, position[45]);
        board.placeCreature(&c47, position[46]);
        board.placeCreature(&c48, position[47]);
        board.placeCreature(&c49, position[48]);
        board.placeCreature(&c50, position[49]);
        
        
        board.printBoard();
        for(int i = 0; i < 10; i++){
		    board.doTurn(100);
		    board.printBoard();
        }
        
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
        
        
        
    //
    //				MY TESTS    
    //  	Matt Johnson - maj2647
    //  
    //
     
     
     
    
    // ----------
    // darwin 6x6
    // ----------

    try {
        cout << "*** Darwin 6x6 ***" << endl;
        /*
        6x6 Darwin
        Trap,   facing north, at (2, 2)
        Trap, 	facing north, at (2, 3)
        Trap, 	facing north, at (3, 2)
        Trap, 	facing north, at (3, 3)
        Hopper, facing south, at (0, 2)
        Hopper, facing south, at (0, 3)
        Hopper, facing west,  at (2, 5)
        Hopper, facing west,  at (3, 5)
        Hopper, facing north, at (5, 3)
        Hopper, facing north, at (5, 4)
        Hopper, facing east,  at (2, 0)
        Hopper, facing east,  at (3, 0)
        Simulate 5 moves.
        Print every grid.
        */
        
        
        Hopper h = Hopper();
        Trap t = Trap();
        
        Creature c1 = Creature(t, NORTH);
        Creature c2 = Creature(t, NORTH);
        Creature c3 = Creature(t, NORTH);
        Creature c4 = Creature(t, NORTH);
        
        Creature c5 = Creature(h, SOUTH);
        Creature c6 = Creature(h, SOUTH);
        Creature c7 = Creature(h, WEST);
        Creature c8 = Creature(h, WEST);
        Creature c9 = Creature(h, NORTH);
        Creature c10 = Creature(h, NORTH);
        Creature c11 = Creature(h, EAST);
        Creature c12 = Creature(h, EAST);
        
        
        Board board = Board(6, 6);
        board.placeCreature(&c1, 2, 2);
        board.placeCreature(&c2, 2, 3);
        board.placeCreature(&c3, 3, 2);
        board.placeCreature(&c4, 3, 3);
        board.placeCreature(&c5, 0, 2);
        board.placeCreature(&c6, 0, 3);
        board.placeCreature(&c7, 2, 5);
        board.placeCreature(&c8, 3, 5);
        board.placeCreature(&c9, 5, 2);
        board.placeCreature(&c10, 5, 3);
        board.placeCreature(&c11, 2, 0);
        board.placeCreature(&c12, 3, 0);
        
        board.printBoard();
        for(int i = 0; i < 5; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
    // ----------
    // darwin 3x10
    // ----------

    try {
        cout << "*** Darwin 3x10 ***" << endl;
        srand(0);
        
        /*
        10x1 Darwin
        Rover,   facing east, at (1, 0)
        Hopper,	 facing west, at (1, 9)
        Simulate 12 moves.
        Print every grid.
        */
        
        
        Hopper h = Hopper();
        Rover r = Rover();
        
        Creature c1 = Creature(r, EAST);
        Creature c2 = Creature(h, WEST);
        
        
        Board board = Board(3, 10);
        board.placeCreature(&c1, 1, 0);
        board.placeCreature(&c2, 1, 9);
        
        board.printBoard();
        for(int i = 0; i < 12; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
   
   
    // ----------
    // darwin 4x4
    // ----------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
        srand(0);
        
        /*
        4x4 Darwin
        Trap,    facing east, at (0, 0)
        Food,	 facing west, at (0, 1)
        Food,	 facing west, at (0, 2)
        Food,	 facing west, at (0, 3)
        Food,	 facing west, at (1, 0)
        Food,	 facing west, at (1, 1)
        Food,	 facing west, at (1, 2)
        Food,	 facing west, at (1, 3)
        Food,	 facing west, at (2, 0)
        Food,	 facing west, at (2, 1)
        Food,	 facing west, at (2, 2)
        Food,	 facing west, at (2, 3)
        Food,	 facing west, at (3, 0)
        Food,	 facing west, at (3, 1)
        Food,	 facing west, at (3, 2)
        Food,	 facing west, at (3, 3)
        Simulate 7 moves.
        Print every grid.
        */
        
        
        Food f = Food();
        Trap t = Trap();
        
        Creature c1 = Creature(t, EAST);
        Creature c2 = Creature(f, WEST);
        Creature c3 = Creature(f, WEST);
        Creature c4 = Creature(f, WEST);
        Creature c5 = Creature(f, WEST);
        Creature c6 = Creature(f, WEST);
        Creature c7 = Creature(f, WEST);
        Creature c8 = Creature(f, WEST);
        Creature c9 = Creature(f, WEST);
        Creature c10 = Creature(f, WEST);
        Creature c11 = Creature(f, WEST);
        Creature c12 = Creature(f, WEST);
        Creature c13 = Creature(f, WEST);
        Creature c14 = Creature(f, WEST);
        Creature c15 = Creature(f, WEST);
        Creature c16 = Creature(f, WEST);
        
        
        Board board = Board(4, 4);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 0, 1);
        board.placeCreature(&c3, 0, 2);
        board.placeCreature(&c4, 0, 3);
        board.placeCreature(&c5, 1, 0);
        board.placeCreature(&c6, 1, 1);
        board.placeCreature(&c7, 1, 2);
        board.placeCreature(&c8, 1, 3);
        board.placeCreature(&c9, 2, 0);
        board.placeCreature(&c10, 2, 1);
        board.placeCreature(&c11, 2, 2);
        board.placeCreature(&c12, 2, 3);
        board.placeCreature(&c9, 3, 0);
        board.placeCreature(&c10, 3, 1);
        board.placeCreature(&c11, 3, 2);
        board.placeCreature(&c12, 3, 3);
        
        board.printBoard();
        for(int i = 0; i < 7; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
        	
    // ----------
    // darwin 5x5
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
        /*
        5x5 Darwin
        Rover,   facing north, at (2, 2)
        Trap, 	 facing south, at (0, 2)
        Trap, 	 facing east,  at (2, 0)
        Trap, 	 facing west,  at (2, 4)
        Trap, 	 facing north, at (4, 2)
        Simulate 8 moves.
        Print every grid.
        */
        
        
        Rover r = Rover();
        Trap t = Trap();
        
        Creature c1 = Creature(r, NORTH);
        Creature c2 = Creature(t, SOUTH);
        Creature c3 = Creature(t, EAST);
        Creature c4 = Creature(t, WEST);
        Creature c5 = Creature(t, NORTH);
        
        
        Board board = Board(5, 5);
        board.placeCreature(&c1, 2, 2);
        board.placeCreature(&c2, 0, 2);
        board.placeCreature(&c3, 2, 0);
        board.placeCreature(&c4, 2, 4);
        board.placeCreature(&c5, 4, 2);

        
        board.printBoard();
        for(int i = 0; i < 8; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
    // ----------
    // darwin 2x2
    // ----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
        
        /*
        2x2 Darwin
        Rover,   facing south, at (0, 1)
        Food,    facing west,  at (0, 0)
        Simulate 7 moves.
        Print every grid.
        */
        
        Rover r = Rover();
        Food f = Food();
        
        Creature c1 = Creature(r, SOUTH);
        Creature c2 = Creature(f, WEST);
        
        
        Board board = Board(2, 2);
        board.placeCreature(&c1, 0, 1);
        board.placeCreature(&c2, 0, 0);

        
        board.printBoard();
        for(int i = 0; i < 7; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}

    // ----------
    // darwin 1x4
    // ----------

    try {
        cout << "*** Darwin 1x4 ***" << endl;
        srand(0);
        
        /*
        1x4 Darwin
        Trap,   facing west,   at (0, 3)
        Food,   facing north,  at (0, 2)
        Food,   facing east,   at (0, 1)
        Food,   facing south,   at (0, 0)
        Simulate 3 moves.
        Print every grid.
        */
        
        Trap t = Trap();
        Food f = Food();
        
        Creature c1 = Creature(t, WEST);
        Creature c2 = Creature(f, NORTH);
        Creature c3 = Creature(f, EAST);
        Creature c4 = Creature(f, SOUTH);
        
        
        Board board = Board(1, 4);
        board.placeCreature(&c1, 0, 3);
        board.placeCreature(&c2, 0, 2);
        board.placeCreature(&c3, 0, 1);
        board.placeCreature(&c4, 0, 0);

        
        board.printBoard();
        for(int i = 0; i < 3; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
    // ----------
    // darwin 1x3
    // ----------

    try {
        cout << "*** Darwin 1x4 ***" << endl;
        srand(0);
        
        /*
        1x4 Darwin
        Trap,   facing west,   at (0, 2)
        Hopper, facing west,  at (0, 1)
        Rover,  facing east,   at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        
        Trap t = Trap();
        Hopper h = Hopper();
        Rover r = Rover();
        
        Creature c1 = Creature(t, WEST);
        Creature c2 = Creature(h, WEST);
        Creature c3 = Creature(r, EAST);
        
        
        Board board = Board(1, 3);
        board.placeCreature(&c1, 0, 2);
        board.placeCreature(&c2, 0, 1);
        board.placeCreature(&c3, 0, 0);

        
        board.printBoard();
        for(int i = 0; i < 5; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
    // ----------
    // darwin 5x5
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
        /*
        5x5 Darwin
        Hopper, facing east,   at (1, 0)
        Hopper, facing east,   at (2, 0)
        Hopper, facing east,   at (3, 0)
        Rover,  facing west,   at (2, 4)
        Simulate 7 moves.
        Print every grid.
        */
        
        Hopper h = Hopper();
        Rover r = Rover();
        
        Creature c1 = Creature(h, EAST);
        Creature c2 = Creature(h, EAST);
        Creature c3 = Creature(h, EAST);
        Creature c4 = Creature(r, WEST);
        
        
        Board board = Board(5, 5);
        board.placeCreature(&c1, 1, 0);
        board.placeCreature(&c2, 2, 0);
        board.placeCreature(&c3, 3, 0);
        board.placeCreature(&c4, 2, 4);

        
        board.printBoard();
        for(int i = 0; i < 7; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
    // ----------
    // darwin 5x5
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
        /*
        5x5 Darwin
        Hopper, facing east,   at (1, 0)
		Food,   facing west,   at (3, 2)
		Food,   facing west,   at (1, 2)
		Food,   facing west,   at (4, 4)
        Rover,  facing west,   at (2, 4)
        Simulate 7 moves.
        Print every grid.
        */
        
        Hopper h = Hopper();
        Rover r = Rover();
        Food f = Food();
        
        Creature c1 = Creature(h, EAST);
        Creature c2 = Creature(f, WEST);
        Creature c3 = Creature(f, WEST);
        Creature c4 = Creature(f, WEST);
        Creature c5 = Creature(r, WEST);
        
        
        Board board = Board(5, 5);
        board.placeCreature(&c1, 1, 0);
        board.placeCreature(&c2, 3, 2);
        board.placeCreature(&c3, 1, 2);
        board.placeCreature(&c4, 4, 4);
        board.placeCreature(&c5, 2, 4);

        
        board.printBoard();
        for(int i = 0; i < 7; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}
        	
        	
    // ----------
    // darwin 10x10
    // ----------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        
        /*
        5x5 Darwin
        Hopper, facing east,   at (0, 0)
        Hopper, facing north,   at (9, 0)
        Hopper, facing south,  at (0, 9)
        Hopper, facing west,   at (9, 9)
		Trap,   facing south,  at (1, 0)
		Trap,   facing south,  at (0, 8)
		Trap,   facing north,  at (8, 0)
		Trap,   facing north,  at (8, 9)
        Simulate 7 moves.
        Print every grid.
        */
        
        Hopper h = Hopper();
        Trap t = Trap();
        
        Creature c1 = Creature(h, EAST);
        Creature c2 = Creature(h, NORTH);
        Creature c3 = Creature(h, SOUTH);
        Creature c4 = Creature(h, WEST);
        Creature c5 = Creature(t, SOUTH);
        Creature c6 = Creature(t, SOUTH);
        Creature c7 = Creature(t, NORTH);
        Creature c8 = Creature(t, NORTH);
        
        
        Board board = Board(10, 10);
        board.placeCreature(&c1, 0, 0);
        board.placeCreature(&c2, 9, 0);
        board.placeCreature(&c3, 0, 9);
        board.placeCreature(&c4, 9, 9);
        board.placeCreature(&c5, 1, 0);
        board.placeCreature(&c5, 0, 8);
        board.placeCreature(&c5, 9, 1);
        board.placeCreature(&c5, 8, 9);

        
        board.printBoard();
        for(int i = 0; i < 7; i++){
        	board.doTurn(1);
        	board.printBoard();
        }
        
        }
        catch (const invalid_argument&) {
        	assert(false);}
    	catch (const out_of_range&) {
        	assert(false);}

    return 0;}
