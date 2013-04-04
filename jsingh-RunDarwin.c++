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

    Instruction left(instruc::LEFT);
    Instruction go0 (instruc::GO, 0);
    Instruction hop (instruc::HOP);
    Instruction ifenemy9 (instruc::IF_ENEMY, 9);
    Instruction ifenemy11(instruc::IF_ENEMY, 11);
    Instruction go6 (instruc::GO, 6);
    Instruction ifrandom9 (instruc::IF_RANDOM, 9);
    Instruction ifempty7 (instruc::IF_EMPTY, 7);
    Instruction ifempty4 (instruc::IF_EMPTY, 4);
    Instruction ifwall6 (instruc::IF_WALL, 6);
    Instruction ifrandom5 (instruc::IF_RANDOM, 5);
    Instruction right (instruc::RIGHT);
    Instruction infect (instruc::INFECT);
    Instruction ifenemy3 (instruc::IF_ENEMY, 3);
   

    // ----
    // food
    // ----

    /*
     0: left
     1: go 0
    */

    Species food('f',2);
    food.addInstruction(0, left);
    food.addInstruction(1, go0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    Species hopper('h',2);
    hopper.addInstruction(0, hop);
    hopper.addInstruction(1, go0);

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

    Species rover('r',11);
    rover.addInstruction(0, ifenemy9);
    rover.addInstruction(1, ifempty7);
    rover.addInstruction(2, ifrandom5);
    rover.addInstruction(3, left);
    rover.addInstruction(4, go0);
    rover.addInstruction(5, right);
    rover.addInstruction(6, go0);
    rover.addInstruction(7, hop);
    rover.addInstruction(8, go0);
    rover.addInstruction(9, infect);
    rover.addInstruction(10, go0);

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

    Species trap('t',5);
    trap.addInstruction(0, ifenemy3);
    trap.addInstruction(1, left);
    trap.addInstruction(2, go0);
    trap.addInstruction(3, infect);
    trap.addInstruction(4, go0);

    // ---------- 1
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
        Game by8(8,8);
        Creature food1(food, Direction::EAST);
        Creature hopper1(hopper, Direction::NORTH);
        Creature hopper2(hopper, Direction::EAST);
        Creature hopper3(hopper, Direction::SOUTH);
        Creature hopper4(hopper, Direction::WEST);
        Creature food2(food, Direction::NORTH);
        by8.addCreature(food1, Grid(0,0));
        by8.addCreature(hopper1, Grid(3,3));
        by8.addCreature(hopper2, Grid(3,4));
        by8.addCreature(hopper3, Grid(4,4));
        by8.addCreature(hopper4, Grid(4,3));
        by8.addCreature(food2, Grid(7,7));


        
        by8.printBoard(cout);
        for(int i = 0; i < 5; i++){
            by8.simulate();
            by8.printBoard(cout);
       }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------- 2
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

        Game darwin79(7,9);
        Creature trap1(trap, Direction::SOUTH);
        Creature hopper1(hopper, Direction::EAST);
        Creature rover1 (rover, Direction::NORTH);
        Creature trap2 (trap, Direction::WEST);
        darwin79.addCreature(trap1,Grid(0,0));
        darwin79.addCreature(hopper1,Grid(3,2));
        darwin79.addCreature(rover1, Grid(5,4));
        darwin79.addCreature(trap2, Grid(6,8));

        darwin79.printBoard(cout);
        for(int i = 0; i< 5; i++){
            darwin79.simulate();
            darwin79.printBoard(cout);
        }
         
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------ 3
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
        Game darwin7272(72, 72);

        //add food
        for(int i = 0; i < 10; ++i){
            int r = rand() % 5184;
            int x = r / 72;
            int y = r % 72;
            int direction = rand() % 4;

            if(direction == 0){        
                Creature food1(food, Direction::WEST);
                darwin7272.addCreature(food1, Grid(x, y));
            }else if(direction ==1){
                Creature food1(food, Direction::NORTH);
                darwin7272.addCreature(food1, Grid(x,y));
            }else if(direction==2){
                Creature food1(food, Direction::EAST);
                darwin7272.addCreature(food1, Grid(x,y));
            }else if(direction == 3){
                Creature food1(food, Direction::SOUTH);
                darwin7272.addCreature(food1, Grid(x,y));
            }

        }


        //add hopper
        for(int i = 0; i < 10; ++i){
            int r = rand() % 5184;
            int x = r / 72;
            int y = r % 72;
            int direction = rand() % 4;

            if(direction == 0){        
                Creature hopper1(hopper, Direction::WEST);
                darwin7272.addCreature(hopper1, Grid(x, y));
            }else if(direction ==1){
                Creature hopper1(hopper, Direction::NORTH);
                darwin7272.addCreature(hopper1, Grid(x,y));
            }else if(direction==2){
                Creature hopper1(hopper, Direction::EAST);
                darwin7272.addCreature(hopper1, Grid(x,y));
            }else if(direction == 3){
                Creature hopper1(hopper, Direction::SOUTH);
                darwin7272.addCreature(hopper1, Grid(x,y));
            }

        }


        //add rover
        for(int i = 0; i < 10; ++i){
            int r = rand() % 5184;
            int x = r / 72;
            int y = r % 72;
            int direction = rand() % 4;

            if(direction == 0){        
                Creature rover1(rover, Direction::WEST);
                darwin7272.addCreature(rover1, Grid(x, y));
            }else if(direction ==1){
                Creature rover1(rover, Direction::NORTH);
                darwin7272.addCreature(rover1, Grid(x,y));
            }else if(direction==2){
                Creature rover1(rover, Direction::EAST);
                darwin7272.addCreature(rover1, Grid(x,y));
            }else if(direction == 3){
                Creature rover1(rover, Direction::SOUTH);
                darwin7272.addCreature(rover1, Grid(x,y));
            }

        }

        
        //add trap
        for(int i = 0; i < 10; ++i){
            int r = rand() % 5184;
            int x = r / 72;
            int y = r % 72;
            int direction = rand() % 4;

            if(direction == 0){        
                Creature trap1(trap, Direction::WEST);
                darwin7272.addCreature(trap1, Grid(x, y));
            }else if(direction ==1){
                Creature trap1(trap, Direction::NORTH);
                darwin7272.addCreature(trap1, Grid(x,y));
            }else if(direction==2){
                Creature trap1(trap, Direction::EAST);
                darwin7272.addCreature(trap1, Grid(x,y));
            }else if(direction== 3){
                Creature trap1(trap, Direction::SOUTH);
                darwin7272.addCreature(trap1, Grid(x,y));
            }

        }

        darwin7272.printBoard(cout);
        
        for(int i = 0; i<1000; ++i){
            darwin7272.simulate();
            if(i%100 ==99)
              darwin7272.printBoard(cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------ 4
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
        
        //Game darwin7272(72,72);       
 
       //Removed since it contained best 

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------  5
    // darwin 5x5
    // with hoppers
    // -----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);

        Game darwin55(10,5);
        Creature hopper1(hopper, Direction::NORTH);
        Creature hopper2(hopper, Direction::SOUTH);
        Creature hopper3(hopper, Direction::WEST);
        Creature hopper4(hopper, Direction::EAST);

        darwin55.addCreature(hopper1, Grid(9,0));
        darwin55.addCreature(hopper2, Grid(7, 4));
        darwin55.addCreature(hopper3, Grid(4,4));
        darwin55.addCreature(hopper4, Grid(4,0));

        darwin55.printBoard(cout);

        for(int i = 0; i<10; ++i){
            darwin55.simulate();
            darwin55.printBoard(cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------ 6
    // Darwin 10x10
    // traps
    // -----------

    try {
        cout << "*** Darwin 10x10 with trap ***" << endl;
        srand(0);

        Game darwin55(10,10);
        Creature trap1 (trap, Direction::SOUTH);
        Creature food1 (food, Direction::WEST);
        Creature trap2 (trap, Direction::NORTH);

        darwin55.addCreature(trap1, Grid(4, 0));
        darwin55.addCreature(food1, Grid(5,0));
        darwin55.addCreature(trap2, Grid(7,7));


        darwin55.printBoard(cout);
        
        for(int i = 0; i<10; ++i){
            darwin55.simulate();
            darwin55.printBoard(cout);
        }

    }
    catch (const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}


    // ----------- 7
    // Darwin 10x10
    // rovers
    // ------------

    try{
        cout << "*** Darwin 10x10 with rovers ***" << endl;
        srand(0);

        Game darwin1010(10,10);
        Creature rover1(rover, Direction::EAST);
        Creature rover2(rover, Direction::SOUTH);
        Creature rover3(rover, Direction::NORTH);
        Creature food1(food, Direction::SOUTH);
        Creature food2(food, Direction::EAST);
        Creature food3(food, Direction::SOUTH);

        darwin1010.addCreature(rover1, Grid(3,0));
        darwin1010.addCreature(rover2, Grid(5,5));
        darwin1010.addCreature(rover3, Grid(9,9));
        darwin1010.addCreature(food1, Grid(7,7));
        darwin1010.addCreature(food2, Grid(3,3));
        darwin1010.addCreature(food3, Grid(2, 8));
        
        darwin1010.printBoard(cout);

        for (int i =0; i<10; ++i){
            darwin1010.simulate();
            darwin1010.printBoard(cout);
        }

    }
    catch (const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}


    // ----------- 8
    // Darwin 10x10
    // best
    // ------------

    try{
        cout << "*** Darwin 10x10 with best ***" << endl;
        srand(0);

       // Game darwin1010(10,10);

        //Removed since it contains best

    }
    catch (const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}


    // ----------- 9
    // Darwin 10x10
    // best vs trap
    // ------------

    try{
        cout << "*** Darwin 10x10 with best and trap ***" << endl;
        srand(0);

        //Game darwin1010(10,10);
        
        //Removed since it contains best

    }
    catch (const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}


    // ----------- 10
    // Darwin 10x10
    // best vs rover
    // ------------

    try{
        cout << "*** Darwin 10x10 with best and rover***" << endl;
        srand(0);

        //Game darwin1010(10,10);

        //Removed since it contains best

    }
    catch (const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}



    return 0;}
