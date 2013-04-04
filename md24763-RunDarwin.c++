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



//0123 NWSE
//0123 wnes
int directionConvert(int x)
{
    switch(x) {
        case 0:
            return 1;
        break;
        case 1:
            return 0;
        break;
        case 2:
            return 3;
        break;
        case 3:
            return 2;
        default:
        break;
    }
    return 0; 
}

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
    // darwin 3x3
    // ----------
    try {
        cout << "*** Darwin 3x3 1***" << endl;
        srand(0);
        Darwin d(3,3);
        //0123 nwse
        Creature test0('t',0,1,1);
        Creature test3('r',2,2,2);
        Creature test2('h',2,1,2);
        Creature test1('f',2,0,0);

        d.setCreature(test0);
        d.setCreature(test2);
        d.setCreature(test3);
        d.setCreature(test1);
        if(RUN==1)
            d.runGame(10,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try{
        cout << "*** Darwin 3x3 2***" << endl;
        srand(0);
        Darwin d(3,3);
        Creature test0('t',0,0,0);
        Creature test1('t',2,0,2);
        Creature test2('t',3,2,0);
        Creature test3('t',1,2,2);
        Creature test4('r',1,1,1);
        d.setCreature(test0);
        d.setCreature(test1);
        d.setCreature(test2);
        d.setCreature(test3);
        d.setCreature(test4);
        if(RUN==1)
            d.runGame(5,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 10x1
    // ----------
    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        Darwin d(10,1);
        //0123 nwse
        Creature test0('h',0,8,0);
        Creature test1('t',2,0,0);
        d.setCreature(test0);
        d.setCreature(test1);
        if(RUN==1)
            d.runGame(10,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ----------
    // darwin 10x1 with Rover instead of Hopper
    // ----------
    try {
        cout << "*** Darwin 10x1 with Rover ***" << endl;
        srand(0);
        Darwin d(10,1);
        //0123 nwse
        Creature test0('r',0,8,0);
        Creature test1('t',2,0,0);
        d.setCreature(test0);
        d.setCreature(test1);
        if(RUN==1)
            d.runGame(10,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 2x2 with Trap infects Rover
    // ----------
    try {
        cout << "*** Darwin 2x2 Trap infects Rover ***" << endl;
        srand(0);
        Darwin d(2,2);
        //0123 nwse
        Creature test0('r',0,1,1);
        Creature test1('t',2,0,1);
        d.setCreature(test0);
        d.setCreature(test1);
        if(RUN==1)
            d.runGame(3,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 6x3 with Rover instead of Hopper
    // ----------
    try {
        cout << "*** Darwin 6x3 ***" << endl;
        srand(0);
        Darwin d(6,3);
        //0123 nwse
        Creature test0('t',0,2,2);
        Creature test1('t',2,4,1);
        Creature test2('r',2,0,0);
        Creature test3('t',3,3,2);
        Creature test4('h',0,5,2);
        Creature test5('h',3,3,1);
        d.setCreature(test0);
        d.setCreature(test1);
        d.setCreature(test2);
        d.setCreature(test3);
        d.setCreature(test4);
        d.setCreature(test5);
        if(RUN==1)
            d.runGame(10,1);

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
        Darwin d(8,8);
        //0123 nwse
        Creature test0('f',1,0,0);
        Creature test1('h',0,3,3);
        Creature test2('h',3,3,4);
        Creature test3('h',2,4,4);
        Creature test4('h',1,4,3);
        Creature test5('f',0,7,7);
        d.setCreature(test0);
        d.setCreature(test1);
        d.setCreature(test2);
        d.setCreature(test3);
        d.setCreature(test4);
        d.setCreature(test5);
        if(RUN==1)
            d.runGame(5, 1);
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
        Darwin d(7,9);
        //d.printBoard();
        //0123 nwse
        Creature test0('t',2,0,0);
        Creature test1('h',3,3,2);
        Creature test3('t',1,6,8);
        Creature test4('r',0,5,4);

        d.setCreature(test0);
        d.setCreature(test1);
        d.setCreature(test3);
        d.setCreature(test4);
        if(RUN==1)
            d.runGame(5,1);
        /*
        7x9 Darwin
        (row __ col __)
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
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
        Darwin d(72,72);
        int n=72;
        int mod = 72 * 72;
        //add 10 foods
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('f',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 hoppers
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('h',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 rovers
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('r',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 traps
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('t',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //cout<<"should be a rover? "<<d.board[1][19].direction<<endl;
        if(RUN==1)
            d.runGame(1000,100);
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
        Darwin d(72,72);
        int n=72;
        int mod = 72 * 72;
        //add 10 foods
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('f',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 hoppers
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('h',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 rovers
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('r',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 traps
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('t',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        //add 10 bests
        for(int i = 0; i < 10; ++i){
            int pos = rand() % mod;
            int dir = rand() % 4;
            dir = directionConvert(dir);
            Creature c('b',dir,pos/n,pos%n);
            d.setCreature(c);
        }
        if(RUN==1)
            d.runGame(1000,100);
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

    return 0;}