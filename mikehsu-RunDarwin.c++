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
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert> // assert
#include <cstdlib> // rand, srand
#include <iostream> // cout, endl
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
Food, facing east, at (0, 0)
Hopper, facing north, at (3, 3)
Hopper, facing east, at (3, 4)
Hopper, facing south, at (4, 4)
Hopper, facing west, at (4, 3)
Food, facing north, at (7, 7)
Simulate 5 moves.
Print every grid.
*/
        
        
    Game<8,8,5,1> game1;
    Food a = 2; // east
    Food b = 1; // north
    Hopper c = 1; // north
    Hopper d = 2; // east
    Hopper e = 0; // west
    Hopper f = 3; // south
    game1.put(a, 0, 0);
    game1.put(b, 7, 7);
    game1.put(c, 3, 3);
    game1.put(d, 3, 4);
    game1.put(e, 4, 3);
    game1.put(f, 4, 4);
    game1.run(cout);
        
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
Trap, facing south, at (0, 0)
Hopper, facing east, at (3, 2)
Rover, facing north, at (5, 4)
Trap, facing west, at (6, 8)
Simulate 5 moves.
Print every grid.
*/
        
    Game<7,9,5,1> game2;
    Trap tt = 3;
    Hopper hh = 2;
    Rover rr = 1;
    Trap ttt = 0;
    game2.put(tt, 0, 0);
    game2.put(hh, 3, 2);
    game2.put(rr, 5, 4);
    game2.put(ttt, 6, 8);
    game2.run(cout);
       
        
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
Call rand(), mod it with 72 (72x72), and use that for the position
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
        Game<72,72,1000,100> game3;

        int n = 72;
        int mod = n*n;

        // Food f1 = rand() % 4;
        // Food f2 = rand() % 4;
        // Food f3 = rand() % 4;
        // Food f4 = rand() % 4;
        // Food f5 = rand() % 4;
        // Food f6 = rand() % 4;
        // Food f7 = rand() % 4;
        // Food f8 = rand() % 4;
        // Food f9 = rand() % 4;
        // Food f10 = rand() % 4;

        int position = rand() % mod;
        Food f1 = rand() % 4;
        game3.put(f1, position / n , position % n);

        position = rand() % mod;
        Food f2 = rand() % 4;
        game3.put(f2,  position / n , position % n);

        position = rand() % mod;
        Food f3 = rand() % 4;
        game3.put(f3,  position / n , position % n);

        position = rand() % mod;
        Food f4 = rand() % 4;
        game3.put(f4,  position / n , position % n);

        position = rand() % mod;
        Food f5 = rand() % 4;
        game3.put(f5,  position / n , position % n);

        position = rand() % mod;
        Food f6 = rand() % 4;
        game3.put(f6,  position / n , position % n);

        position = rand() % mod;
        Food f7 = rand() % 4;
        game3.put(f7, position / n , position % n);

        position = rand() % mod;
        Food f8 = rand() % 4;
        game3.put(f8, position / n , position % n);

        position = rand() % mod;
        Food f9 = rand() % 4;
        game3.put(f9, position / n , position % n);

        position = rand() % mod;
        Food f10 = rand() % 4;
        game3.put(f10, position / n , position % n);

        // Hopper h1 = rand() % 4;
        // Hopper h2 = rand() % 4;
        // Hopper h3 = rand() % 4;
        // Hopper h4 = rand() % 4;
        // Hopper h5 = rand() % 4;
        // Hopper h6 = rand() % 4;
        // Hopper h7 = rand() % 4;
        // Hopper h8 = rand() % 4;
        // Hopper h9 = rand() % 4;
        // Hopper h10 = rand() % 4;

        position = rand() % mod;
        Hopper h1 = rand() % 4;
        game3.put(h1,  position / n , position % n);

        position = rand() % mod;
        Hopper h2 = rand() % 4;
        game3.put(h2,  position / n , position % n);

        position = rand() % mod;
        Hopper h3 = rand() % 4;
        game3.put(h3,  position / n , position % n);

        position = rand() % mod;
        Hopper h4 = rand() % 4;
        game3.put(h4,  position / n , position % n);

        position = rand() % mod;
        Hopper h5 = rand() % 4;
        game3.put(h5,  position / n , position % n);

        position = rand() % mod;
        Hopper h6 = rand() % 4;
        game3.put(h6,  position / n , position % n);

        position = rand() % mod;
        Hopper h7 = rand() % 4;
        game3.put(h7,  position / n , position % n);

        position = rand() % mod;
        Hopper h8 = rand() % 4;
        game3.put(h8,  position / n , position % n);

        position = rand() % mod;
        Hopper h9 = rand() % 4;
        game3.put(h9,  position / n , position % n);

        position = rand() % mod;
        Hopper h10 = rand() % 4;
        game3.put(h10, position / n , position % n);

        // Rover r1 = rand() % 4;
        // Rover r2 = rand() % 4;
        // Rover r3 = rand() % 4;
        // Rover r4 = rand() % 4;
        // Rover r5 = rand() % 4;
        // Rover r6 = rand() % 4;
        // Rover r7 = rand() % 4;
        // Rover r8 = rand() % 4;
        // Rover r9 = rand() % 4;
        // Rover r10 = rand() % 4;

        position = rand() % mod;
        Rover r1 = rand() % 4;
        game3.put(r1,  position / n , position % n);

        position = rand() % mod;
        Rover r2 = rand() % 4;
        game3.put(r2,  position / n , position % n);

        position = rand() % mod;
        Rover r3 = rand() % 4;
        game3.put(r3,  position / n , position % n);

        position = rand() % mod;
        Rover r4 = rand() % 4;
        game3.put(r4,  position / n , position % n);

        position = rand() % mod;
        Rover r5 = rand() % 4;
        game3.put(r5,  position / n , position % n);

        position = rand() % mod;
        Rover r6 = rand() % 4;
        game3.put(r6,  position / n , position % n);

        position = rand() % mod;
        Rover r7 = rand() % 4;
        game3.put(r7,  position / n , position % n);

        position = rand() % mod;
        Rover r8 = rand() % 4;
        game3.put(r8, position / n , position % n);

        position = rand() % mod;
        Rover r9 = rand() % 4;
        game3.put(r9, position / n , position % n);

        position = rand() % mod;
        Rover r10 = rand() % 4;
        game3.put(r10, position / n , position % n);



        // Trap t1 = rand() % 4;
        // Trap t2 = rand() % 4;
        // Trap t3 = rand() % 4;
        // Trap t4 = rand() % 4;
        // Trap t5 = rand() % 4;
        // Trap t6 = rand() % 4;
        // Trap t7 = rand() % 4;
        // Trap t8 = rand() % 4;
        // Trap t9 = rand() % 4;
        // Trap t10 = rand() % 4;

        
        position = rand() % mod;
        Trap t1 = rand() % 4;
        game3.put(t1,  position / n , position % n);

        position = rand() % mod;
        Trap t2 = rand() % 4;
        game3.put(t2,  position / n , position % n);

        position = rand() % mod;
        Trap t3 = rand() % 4;
        game3.put(t3,  position / n , position % n);

        position = rand() % mod;
        Trap t4 = rand() % 4;
        game3.put(t4,  position / n , position % n);

        position = rand() % mod;
        Trap t5 = rand() % 4;
        game3.put(t5,  position / n , position % n);

        position = rand() % mod;
        Trap t6 = rand() % 4;
        game3.put(t6,  position / n , position % n);

        position = rand() % mod;
        Trap t7 = rand() % 4;
        game3.put(t7,  position / n , position % n);

        position = rand() % mod;
        Trap t8 = rand() % 4;
        game3.put(t8,  position / n , position % n);

        position = rand() % mod;
        Trap t9 = rand() % 4;
        game3.put(t9,  position / n , position % n);

        position = rand() % mod;
        Trap t10 = rand() % 4;
        game3.put(t10,  position / n , position % n);

        game3.run(cout);
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
Call rand(), mod it with 72 (72x72), and use that for the position
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
Call rand(), mod it with 72 (72x72), and use that for the position
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
        
     
        Game<72,72,1000,100> game3;
        
        int n = 72;
        int mod = n*n;

        // Food f1 = rand() % 4;
        // Food f2 = rand() % 4;
        // Food f3 = rand() % 4;
        // Food f4 = rand() % 4;
        // Food f5 = rand() % 4;
        // Food f6 = rand() % 4;
        // Food f7 = rand() % 4;
        // Food f8 = rand() % 4;
        // Food f9 = rand() % 4;
        // Food f10 = rand() % 4;

        int position = rand() % mod;
        Food f1 = rand() % 4;
        game3.put(f1, position / n , position % n);

        position = rand() % mod;
        Food f2 = rand() % 4;
        game3.put(f2,  position / n , position % n);

        position = rand() % mod;
        Food f3 = rand() % 4;
        game3.put(f3,  position / n , position % n);

        position = rand() % mod;
        Food f4 = rand() % 4;
        game3.put(f4,  position / n , position % n);

        position = rand() % mod;
        Food f5 = rand() % 4;
        game3.put(f5,  position / n , position % n);

        position = rand() % mod;
        Food f6 = rand() % 4;
        game3.put(f6,  position / n , position % n);

        position = rand() % mod;
        Food f7 = rand() % 4;
        game3.put(f7, position / n , position % n);

        position = rand() % mod;
        Food f8 = rand() % 4;
        game3.put(f8, position / n , position % n);

        position = rand() % mod;
        Food f9 = rand() % 4;
        game3.put(f9, position / n , position % n);

        position = rand() % mod;
        Food f10 = rand() % 4;
        game3.put(f10, position / n , position % n);

        // Hopper h1 = rand() % 4;
        // Hopper h2 = rand() % 4;
        // Hopper h3 = rand() % 4;
        // Hopper h4 = rand() % 4;
        // Hopper h5 = rand() % 4;
        // Hopper h6 = rand() % 4;
        // Hopper h7 = rand() % 4;
        // Hopper h8 = rand() % 4;
        // Hopper h9 = rand() % 4;
        // Hopper h10 = rand() % 4;

        position = rand() % mod;
        Hopper h1 = rand() % 4;
        game3.put(h1,  position / n , position % n);

        position = rand() % mod;
        Hopper h2 = rand() % 4;
        game3.put(h2,  position / n , position % n);

        position = rand() % mod;
        Hopper h3 = rand() % 4;
        game3.put(h3,  position / n , position % n);

        position = rand() % mod;
        Hopper h4 = rand() % 4;
        game3.put(h4,  position / n , position % n);

        position = rand() % mod;
        Hopper h5 = rand() % 4;
        game3.put(h5,  position / n , position % n);

        position = rand() % mod;
        Hopper h6 = rand() % 4;
        game3.put(h6,  position / n , position % n);

        position = rand() % mod;
        Hopper h7 = rand() % 4;
        game3.put(h7,  position / n , position % n);

        position = rand() % mod;
        Hopper h8 = rand() % 4;
        game3.put(h8,  position / n , position % n);

        position = rand() % mod;
        Hopper h9 = rand() % 4;
        game3.put(h9,  position / n , position % n);

        position = rand() % mod;
        Hopper h10 = rand() % 4;
        game3.put(h10, position / n , position % n);

        // Rover r1 = rand() % 4;
        // Rover r2 = rand() % 4;
        // Rover r3 = rand() % 4;
        // Rover r4 = rand() % 4;
        // Rover r5 = rand() % 4;
        // Rover r6 = rand() % 4;
        // Rover r7 = rand() % 4;
        // Rover r8 = rand() % 4;
        // Rover r9 = rand() % 4;
        // Rover r10 = rand() % 4;

        position = rand() % mod;
        Rover r1 = rand() % 4;
        game3.put(r1,  position / n , position % n);

        position = rand() % mod;
        Rover r2 = rand() % 4;
        game3.put(r2,  position / n , position % n);

        position = rand() % mod;
        Rover r3 = rand() % 4;
        game3.put(r3,  position / n , position % n);

        position = rand() % mod;
        Rover r4 = rand() % 4;
        game3.put(r4,  position / n , position % n);

        position = rand() % mod;
        Rover r5 = rand() % 4;
        game3.put(r5,  position / n , position % n);

        position = rand() % mod;
        Rover r6 = rand() % 4;
        game3.put(r6,  position / n , position % n);

        position = rand() % mod;
        Rover r7 = rand() % 4;
        game3.put(r7,  position / n , position % n);

        position = rand() % mod;
        Rover r8 = rand() % 4;
        game3.put(r8, position / n , position % n);

        position = rand() % mod;
        Rover r9 = rand() % 4;
        game3.put(r9, position / n , position % n);

        position = rand() % mod;
        Rover r10 = rand() % 4;
        game3.put(r10, position / n , position % n);



        // Trap t1 = rand() % 4;
        // Trap t2 = rand() % 4;
        // Trap t3 = rand() % 4;
        // Trap t4 = rand() % 4;
        // Trap t5 = rand() % 4;
        // Trap t6 = rand() % 4;
        // Trap t7 = rand() % 4;
        // Trap t8 = rand() % 4;
        // Trap t9 = rand() % 4;
        // Trap t10 = rand() % 4;

        
        position = rand() % mod;
        Trap t1 = rand() % 4;
        game3.put(t1,  position / n , position % n);

        position = rand() % mod;
        Trap t2 = rand() % 4;
        game3.put(t2,  position / n , position % n);

        position = rand() % mod;
        Trap t3 = rand() % 4;
        game3.put(t3,  position / n , position % n);

        position = rand() % mod;
        Trap t4 = rand() % 4;
        game3.put(t4,  position / n , position % n);

        position = rand() % mod;
        Trap t5 = rand() % 4;
        game3.put(t5,  position / n , position % n);

        position = rand() % mod;
        Trap t6 = rand() % 4;
        game3.put(t6,  position / n , position % n);

        position = rand() % mod;
        Trap t7 = rand() % 4;
        game3.put(t7,  position / n , position % n);

        position = rand() % mod;
        Trap t8 = rand() % 4;
        game3.put(t8,  position / n , position % n);

        position = rand() % mod;
        Trap t9 = rand() % 4;
        game3.put(t9,  position / n , position % n);

        position = rand() % mod;
        Trap t10 = rand() % 4;
        game3.put(t10,  position / n , position % n);

        position = rand() % mod;
        Best b1 = rand() % 4;
        game3.put(b1,  position / n , position % n);

        position = rand() % mod;
        Best b2 = rand() % 4;
        game3.put(b2,  position / n , position % n);

        position = rand() % mod;
        Best b3 = rand() % 4;
        game3.put(b3,  position / n , position % n);

        position = rand() % mod;
        Best b4 = rand() % 4;
        game3.put(b4,  position / n , position % n);

        position = rand() % mod;
        Best b5 = rand() % 4;
        game3.put(b5,  position / n , position % n);

        position = rand() % mod;
        Best b6 = rand() % 4;
        game3.put(b6,  position / n , position % n);

        position = rand() % mod;
        Best b7 = rand() % 4;
        game3.put(b7,  position / n , position % n);

        position = rand() % mod;
        Best b8 = rand() % 4;
        game3.put(b8,  position / n , position % n);

        position = rand() % mod;
        Best b9 = rand() % 4;
        game3.put(b9,  position / n , position % n);

        position = rand() % mod;
        Best b10 = rand() % 4;
        game3.put(b10,  position / n , position % n);

        game3.run(cout);

        }
        
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}       
        
//     //
//     // MY TESTS
//     // Chan-Tang Hsu - hc9757
//     //
//     //
      
        
//     // ----------
//     // darwin 3*3
//     // ----------

    try {
        cout << "*** Darwin 3x3 ***" << endl;    
        
    Game<3,3,5,1> game1;
    Food a = 2; 
    Food b = 1; 
    Hopper c = 1; 
    Hopper d = 2; 
    Hopper e = 0; 
    Hopper f = 3; 
    game1.put(a, 0, 0);
    game1.put(b, 2, 2);
    game1.put(c, 1, 1);
    game1.put(d, 1, 2);
    game1.put(e, 0, 2);
    game1.put(f, 0, 1);
    game1.run(cout);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
//     // ----------
//     // darwin 2*1
//     // ----------

     try {
        cout << "*** Darwin 2x1 ***" << endl;
        srand(0);
        
    Game<2,1,10,1> game2;

    Rover rr = 1;

    game2.put(rr, 0, 0);

    game2.run(cout);
       
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   
   
//     // ----------
//     // darwin 100x2
//     // ----------

     try {
        cout << "*** Darwin 100x2 ***" << endl;
        srand(0);
        
    Game<100,2,10,1> game2;

    Rover r1 = 1;
    Rover r2 = 1;
    Rover r3 = 1;
    Rover r4 = 1;
    Rover r5 = 1;
    Food r6 = 1;
    Trap r7 = 1;
    Trap r8 = 1;
    Hopper r9 = 1;
    Hopper r10 = 1;

    
    game2.put(r1, 0, 0);
    game2.put(r2, 9, 0);
    game2.put(r3, 20, 1);
    game2.put(r4, 30, 0);
    game2.put(r5, 50, 1);
    game2.put(r6, 60, 0);
    game2.put(r7, 70, 0);
    game2.put(r8, 80, 1);
    game2.put(r9, 90, 0);
    game2.put(r10, 99, 1);


    game2.run(cout);
       
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
//     // ----------
//     // darwin 5x5
//     // ----------

try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
    Game<5,5,10,1> game2;

    Food r1 = 1;
    Rover r2 = 1;
    Trap r3 = 1;
    Rover r4 = 1;
    Rover r5 = 1;
    Food r6 = 1;
    Trap r7 = 1;
    Rover r8 = 1;
    Hopper r9 = 1;
    Hopper r10 = 1;

    
    game2.put(r1, 4, 3);
    game2.put(r2, 3, 2);
    game2.put(r3, 2, 3);
    game2.put(r4, 4, 1);
    game2.put(r5, 2, 0);
    game2.put(r6, 0, 0);
    game2.put(r7, 3, 3);
    game2.put(r8, 2, 4);
    game2.put(r9, 0, 4);
    game2.put(r10, 4, 2);


    game2.run(cout);
       
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
//     // ----------
//     // darwin 5x5
//     // ----------

try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
    Game<5,5,100,1> game2;

    Rover r1 = 1;
    Food r2 = 1;
    Food r3 = 1;
    Food r4 = 1;
    Food r5 = 1;
    
    game2.put(r1, 4, 4);
    game2.put(r2, 3, 2);
    game2.put(r3, 2, 3);
    game2.put(r4, 4, 1);
    game2.put(r5, 2, 0);


    game2.run(cout);
       
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

//     // ----------
//     // darwin 1x4
//     // ----------

try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        
    Game<9,17,100,1> game2;

    Rover r1 = 1;
    Trap r2 = 2;
    Trap r3 = 2;
    Trap r4 = 4;
    Trap r5 = 2;
    
    game2.put(r1, 1, 4);
    game2.put(r2, 4, 0);
    game2.put(r3, 8, 3);
    game2.put(r4, 7, 11);
    game2.put(r5, 5, 10);

    game2.run(cout);
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
