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
#include <stdio.h>
extern vector<Creature> creatureList;
extern int _height;
extern int _width;
extern map<int,char> dir;

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
		Game g(8,8,6,5);
		g.createCreature('f','e',0,0);
		g.createCreature('h','n',3,3);
		g.createCreature('h','e',3,4);
		g.createCreature('h','s',4,4);
		g.createCreature('h','w',4,3);
		g.createCreature('f','n',7,7);
		g.play(true);
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
		Game g(7,9,4,5); // height, width, numCreatures, turns
		g.createCreature('t','s',0,0);
		g.createCreature('h','e',3,2);
		g.createCreature('r','n',5,4);
		// g.createCreature('h','n',5,4);
		g.createCreature('t','w',6,8);
		g.play(true);
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
  
        // /*
        // Randomly place the following creatures facing randomly.
        // Call rand(), mod it with 5184 (72x72), and use that for the position
        // in a row-major order grid.
        // Call rand() again, mod it with 4 and use that for it's direction with
        // the ordering: west, north, east, south.
        // Do that for each kind of creature.
        // 10 Food
        // 10 Hopper
        // 10 Rover
        // 10 Trap
        // Simulate 1000 moves.
        // Print every 100th grid.
        // */
		srand(0);
		Game g(72,72,40,1000);
		
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('f',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("left",-1);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("go",0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('h',dir[d],r,c);
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("hop", -1);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("go", 0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('r',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("if_enemy", 9);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("if_empty", 7);
			creatureList[Game::find(r,c)].creatureProgram[2] = make_pair("if_random", 5);
			creatureList[Game::find(r,c)].creatureProgram[3] = make_pair("left", -1);
			creatureList[Game::find(r,c)].creatureProgram[4] = make_pair("go", 0);
			creatureList[Game::find(r,c)].creatureProgram[5] = make_pair("right", -1);
			creatureList[Game::find(r,c)].creatureProgram[6] = make_pair("go",0);
			creatureList[Game::find(r,c)].creatureProgram[7] = make_pair("hop", -1);
			creatureList[Game::find(r,c)].creatureProgram[8] = make_pair("go",0);
			creatureList[Game::find(r,c)].creatureProgram[9] = make_pair("infect", -1);
			creatureList[Game::find(r,c)].creatureProgram[10] = make_pair("go",0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('t',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("if_enemy",3);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("left",-1);
			creatureList[Game::find(r,c)].creatureProgram[2] = make_pair("go",0);
			creatureList[Game::find(r,c)].creatureProgram[3] = make_pair("infect",-1);
			creatureList[Game::find(r,c)].creatureProgram[4] = make_pair("go",0);
		}
		g.play(false);
		for (int i = 100; i < 1001; i = i + 100){
			g.print(i,true);
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
		Game g(72,72,50,1000);
		
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('f',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("left",-1);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("go",0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('h',dir[d],r,c);
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("hop", -1);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("go", 0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('r',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("if_enemy", 9);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("if_empty", 7);
			creatureList[Game::find(r,c)].creatureProgram[2] = make_pair("if_random", 5);
			creatureList[Game::find(r,c)].creatureProgram[3] = make_pair("left", -1);
			creatureList[Game::find(r,c)].creatureProgram[4] = make_pair("go", 0);
			creatureList[Game::find(r,c)].creatureProgram[5] = make_pair("right", -1);
			creatureList[Game::find(r,c)].creatureProgram[6] = make_pair("go",0);
			creatureList[Game::find(r,c)].creatureProgram[7] = make_pair("hop", -1);
			creatureList[Game::find(r,c)].creatureProgram[8] = make_pair("go",0);
			creatureList[Game::find(r,c)].creatureProgram[9] = make_pair("infect", -1);
			creatureList[Game::find(r,c)].creatureProgram[10] = make_pair("go",0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('t',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("if_enemy",3);
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("left",-1);
			creatureList[Game::find(r,c)].creatureProgram[2] = make_pair("go",0);
			creatureList[Game::find(r,c)].creatureProgram[3] = make_pair("infect",-1);
			creatureList[Game::find(r,c)].creatureProgram[4] = make_pair("go",0);
		}
		for (int i = 0; i < 10; ++i){
			int r = rand() % 5184;
			int c = rand() % 5184;
			int d = rand() % 4;
			g.createCreature('b',dir[d],r,c);
			creatureList[Game::find(r,c)].goneMyTurn = false;
			creatureList[Game::find(r,c)].creatureProgram[0] = make_pair("if_enemy", 11); //shark); moon, carrizo, cakey
			creatureList[Game::find(r,c)].creatureProgram[1] = make_pair("if_empty", 9); //moon);
			creatureList[Game::find(r,c)].creatureProgram[2] = make_pair("if_random", 13);//carrizo)
			creatureList[Game::find(r,c)].creatureProgram[3] = make_pair("if_random", 15);//cakey or rotate
			              
			creatureList[Game::find(r,c)].creatureProgram[4] = make_pair("if_enemy", 7); //rotating
			creatureList[Game::find(r,c)].creatureProgram[5] = make_pair("left", -1);
			creatureList[Game::find(r,c)].creatureProgram[6] = make_pair("go", 4);
			creatureList[Game::find(r,c)].creatureProgram[7] = make_pair("infect", -1); 
			creatureList[Game::find(r,c)].creatureProgram[8] = make_pair("go", 4);
			                 
			creatureList[Game::find(r,c)].creatureProgram[9] = make_pair("hop", -1);//moon
			creatureList[Game::find(r,c)].creatureProgram[10] = make_pair("go", 0);
			                  
			creatureList[Game::find(r,c)].creatureProgram[11] = make_pair("infect", -1); //shark
			creatureList[Game::find(r,c)].creatureProgram[12] = make_pair("go", 0);
			     
			creatureList[Game::find(r,c)].creatureProgram[13] = make_pair("right", -1);//carrizo
			creatureList[Game::find(r,c)].creatureProgram[14] = make_pair("go", 0);
			            
			creatureList[Game::find(r,c)].creatureProgram[15] = make_pair("left", -1);////cakey, going left , if enemy
			creatureList[Game::find(r,c)].creatureProgram[16] = make_pair("go", 0);
		}
		g.play(false);
		for (int i = 100; i < 1001; i = i + 100){
			g.print(i,true);
		}
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
		
		
	// test case 5
	try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        /*
		Battle of rover vs best in a tight space
        Simulate 5 moves.
        Print every grid.
        */
		Game g(10,10,2,5); // height, width, numCreatures, turns
		g.createCreature('r','n',5,4);
		g.createCreature('b','w',6,8);
		g.play(true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
		
	
	// test case 6
	try {
        cout << "*** Darwin 55x55 ***" << endl;
        srand(0);
        /*
        2 rovers vs 2 best
        Simulate 10 moves.
        Print every grid.
        */
		Game g(55,55,4,10); // height, width, numCreatures, turns
		g.createCreature('b','s',0,0);
		g.createCreature('r','e',3,2);
		g.createCreature('r','n',5,4);
		// g.createCreature('h','n',5,4);
		g.createCreature('b','w',6,8);
		g.play(true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
		
		
		
	// test case 7
	try {
        cout << "*** Darwin 15x15 ***" << endl;
        srand(0);
        /*
        15x15 Darwin
		 Best vs rovers (more turns)
        Simulate 55 moves.
        Print every grid.
        */
		Game g(15,15,4,55); // height, width, numCreatures, turns
		g.createCreature('b','w',1,1);
		g.createCreature('r','s',2,2);
		g.createCreature('r','s',5,7);
		g.createCreature('b','e',6,8);
		g.play(true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


	// test case 8
	try {
        cout << "*** Darwin 8x8 ***" << endl;
        /*
        8x8 Darwin
        Test to see if best converts non-rovers
        Simulate 15 moves.
        Print every grid.
        */
		Game g(8,8,6,15);
		g.createCreature('b','e',1,1);
		g.createCreature('h','n',3,3);
		g.createCreature('h','e',3,4);
		g.createCreature('h','s',4,4);
		g.createCreature('h','w',4,3);
		g.createCreature('f','n',7,7);
		g.play(true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}		
		
		
		
	// test case 9
	try {
        cout << "*** Darwin 125x15 ***" << endl;
        srand(0);
        /*
        125x15 Darwin
		 Best vs rovers (more turns)
        Simulate 550 moves.
        Print every grid.
        */
		Game g(125,15,4,550); // height, width, numCreatures, turns
		g.createCreature('b','w',1,1);
		g.createCreature('r','s',2,2);
		g.createCreature('r','s',5,7);
		g.createCreature('b','e',6,8);
		g.play(true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


	// test case 10
	try {
        cout << "*** Darwin 80x8 ***" << endl;
        /*
        80x8 Darwin
        Test to see if best converts non-rovers
        Simulate 15 moves.
        Print every grid.
        */
		Game g(80,8,6,15);
		g.createCreature('b','e',1,1);
		g.createCreature('h','n',3,3);
		g.createCreature('h','e',3,4);
		g.createCreature('h','s',4,4);
		g.createCreature('h','w',4,3);
		g.createCreature('f','n',7,7);
		g.play(true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}		
		
		
		
    return 0;}

