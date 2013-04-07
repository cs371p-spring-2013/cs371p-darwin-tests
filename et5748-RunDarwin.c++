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

   field a(8, 8);
	 a.add('f', 'e', 0, 0);
	 a.add('h', 'n', 3, 3);
	 a.add('h', 'e', 3, 4);
	 a.add('h', 's', 4, 4);
	 a.add('h', 'w', 4, 3);
	 a.add('f', 'n', 7, 7);
  	 a.play(5, 1);
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

	 field a(7, 9);
	 a.add('t', 's', 0, 0);
	 a.add('h', 'e', 3, 2);
	 a.add('r', 'n', 5, 4);
	 a.add('t', 'w', 6, 8);
  	 a.play(5, 1);
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

	 field a(72, 72);
        for(int i = 0; i < 10; ++i){
          int pos = rand() % 5184;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('f', dir, (pos/72), (pos%72));
        } 

        for(int i = 0; i < 10; ++i){
          int pos = rand() % 5184;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('h', dir, (pos/72), (pos%72));
        } 

        for(int i = 0; i < 10; ++i){
          int pos = rand() % 5184;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('r', dir, (pos/72), (pos%72));
        }  

        for(int i = 0; i < 10; ++i){
          int pos = rand() % 5184;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('t', dir, (pos/72), (pos%72));
        } 

     	 a.play(1000, 100);
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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 1
    // ------------------------

	//SHOULD OVERRITE IF PLACING CREATURE ON OCCUPIED SPACE

     try {
        cout << "*** Darwin Acceptance Test 1 ***" << endl; 
      
	 field a(5, 5);
	 a.add('f', 'e', 0, 0);
	 a.add('h', 'e', 0, 0);
	 a.add('t', 'e', 0, 0);
	 a.add('r', 'e', 0, 0);
	
  	 a.play(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------------
    // Darwin Acceptance Test 2
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 2 ***" << endl; 
      
	 field a(1, 1);
	 a.add('f', 'e', 0, 0);
	
  	 a.play(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 3
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 3 ***" << endl; 
      
	 field a(2, 2);
	 a.add('h', 'e', 0, 0);
	 a.add('h', 's', 0, 1);
	 a.add('h', 'w', 1, 1);
	 a.add('h', 'n', 1, 0);
	
  	 a.play(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 4
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 4 ***" << endl; 
	 srand(0);      

	 field a(10, 10);
	 for(int i = 0; i < 10; ++i){
          int pos = rand() % 100;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('r', dir, (pos/10), (pos%10));
        } 
	
  	 a.play(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 5
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 5 ***" << endl;       

	 field a(7, 20);
	 a.add('t', 'e', 0, 0);
	 a.add('t', 's', 0, 19);
	 a.add('t', 'w', 6, 19);
	 a.add('t', 'n', 6, 0);
	
  	 a.play(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 6
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 6 ***" << endl; 
	 srand(0);      

	 field a(10, 10);
	 for(int i = 0; i < 10; ++i){
          int pos = rand() % 100;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('r', dir, (pos/10), (pos%10));
        } 

	 for(int i = 0; i < 10; ++i){
          int pos = rand() % 100;
	   char dir;
          int face = rand() % 4;
	   if (face == 0)
	     dir = 'w';
	   else if (face == 1)
 	     dir = 'n';
	   else if (face == 2)
 	     dir = 'e';
	   else if (face == 3)
 	     dir = 's';
          a.add('f', dir, (pos/10), (pos%10));
        } 	

  	 a.play(5, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 7
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 7 ***" << endl;       

	 field a(4, 10);
	 a.add('h', 'e', 0, 0);
	 a.add('h', 'e', 1, 0);
	 a.add('h', 'e', 2, 0);
	 a.add('h', 'e', 3, 0);
	
  	 a.play(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 8
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 8 ***" << endl;       

	 field a(4, 10);
	 a.add('h', 'w', 0, 9);
	 a.add('h', 'w', 1, 9);
	 a.add('h', 'w', 2, 9);
	 a.add('h', 'w', 3, 9);
	
  	 a.play(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------------
    // Darwin Acceptance Test 9
    // ------------------------

     try {
        cout << "*** Darwin Acceptance Test 9 ***" << endl;       

	 field a(10, 3);
	 a.add('h', 's', 0, 0);
	 a.add('h', 's', 0, 1);
	 a.add('h', 's', 0, 2);
	
  	 a.play(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -------------------------
    // Darwin Acceptance Test 10
    // -------------------------

     try {
        cout << "*** Darwin Acceptance Test 10 ***" << endl;       

	 field a(10, 3);
	 a.add('h', 'n', 9, 0);
	 a.add('h', 'n', 9, 1);
	 a.add('h', 'n', 9, 2);
	
  	 a.play(10, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
