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

    Species Food("food");
    Food.push_back(LEFT);
    Food.push_back(go, 0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    Species Hopper("hopper");
    Hopper.push_back(HOP);
    Hopper.push_back(go, 0);

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

    Species Rover("rover");
    Rover.push_back(if_enemy, 9);
    Rover.push_back(if_empty, 7);
    Rover.push_back(if_random, 5);
    Rover.push_back(LEFT);
    Rover.push_back(go, 0);
    Rover.push_back(RIGHT);
    Rover.push_back(go, 0);
    Rover.push_back(HOP);
    Rover.push_back(go, 0);
    Rover.push_back(INFECT);
    Rover.push_back(go, 0);

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

    Species Trap("trap");
    Trap.push_back(if_enemy, 3);
    Trap.push_back(LEFT);
    Trap.push_back(go, 0);
    Trap.push_back(INFECT);
    Trap.push_back(go, 0);


    Species Best("best");
    Best.push_back(if_enemy, 9);
    Best.push_back(if_empty, 7);
    Best.push_back(if_random, 5);
    Best.push_back(LEFT);
    Best.push_back(go, 0);
    Best.push_back(RIGHT);
    Best.push_back(go, 0);
    Best.push_back(HOP);
    Best.push_back(go, 0);
    Best.push_back(INFECT);
    Best.push_back(go, 0);


    // ----------
    // 1: darwin 10x1
    // -----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        /*
        10x1 Darwin
        Rover,   facing north, at (5, 0)
        Simulate 10 moves.
        Print every grid.
        */

        /*
        2x2 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 1)
        Rover,   facing east, at (1, 0)
        Rover,   facing west, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin d(1, 10);
        d.placeCreature(5, 0, Creature(Rover, NORTH));
        d.simulate(10,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 2: darwin 10x10
    // -----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        /*
        10x1 Darwin
        Rover,   facing north, at (5, 0)
        Simulate 10 moves.
        Print every grid.
        */

        /*
        2x2 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 1)
        Rover,   facing east, at (1, 0)
        Rover,   facing west, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin d(10, 10);
        d.placeCreature(5, 0, Creature(Rover, NORTH));
        d.simulate(10,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

   
    // ----------
    // 3: darwin 10x1
    // -----------

    try {
        cout << "*** Darwin 1x10 ***" << endl;
        srand(0);
        /*
        1x10 Darwin
        Rover,   facing north, at (0, 5)
        Simulate 10 moves.
        Print every grid.
        */
        Darwin d(10, 1);
        d.placeCreature(0, 5, Creature (Rover, NORTH));
        d.simulate(10,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 4: darwin 2x2
    // ----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
        Darwin d(2, 2);
        d.placeCreature( 0, 0, Creature(Rover, NORTH));
        d.placeCreature( 0, 1, Creature(Rover, SOUTH));
        d.placeCreature( 1, 0, Creature(Rover, EAST));
        d.simulate(5,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

     // ----------
    // 5: darwin 3x3
    // ----------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
        srand(0);
        /*
        3x3 Darwin
        Rover,   facing north, at (0, 0)
        Rover,   facing south, at (0, 2)
        Rover,   facing east, at (2, 0)
        Rover,   facing west, at (2, 2)
        Simulate 5 moves.
        Print every grid.
        */
        Darwin d(3, 3);
        d.placeCreature(0, 0, Creature(Trap, NORTH));
        d.placeCreature(0, 2, Creature(Trap, SOUTH));
        d.placeCreature(2, 0, Creature(Trap, EAST));
        d.placeCreature(2, 2, Creature(Trap, WEST));
        d.placeCreature(1, 1, Creature(Rover, WEST));
        d.simulate(5,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

//---------------------------------------------MY CODE



    // ----------
    // 6: darwin 8x8
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

        Darwin d(8,8);
        Creature foodE (Food, EAST); 
        Creature foodN (Food, NORTH); 
        Creature HopperE (Hopper, EAST); 
        Creature HopperW (Hopper, WEST); 
        Creature HopperN (Hopper, NORTH); 
        Creature HopperS (Hopper, SOUTH);

        d.placeCreature(0, 0, foodE);
        d.placeCreature(7, 7, foodN);

        d.placeCreature(3, 3, HopperN);
        d.placeCreature(3, 4, HopperE);
        d.placeCreature(4, 4, HopperS);
        d.placeCreature(4, 3, HopperW);

        d.simulate(5,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 7: darwin 7x9
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

          Darwin d(9,7);
          Creature trapS(Trap, SOUTH);
          Creature trapW(Trap, WEST);
          Creature hopperE (Hopper, EAST); 
          Creature roverN (Rover, NORTH); 

          d.placeCreature(0,0, trapS);
          d.placeCreature(6,8, trapW);

          d.placeCreature(3,2, hopperE);

          d.placeCreature(5,4, roverN);
          srand(0);
          d.simulate(5,0);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // 8: darwin 72x72
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
          Darwin d(72,72);

          srand(0);
          
          //add Food Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature food(Food, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, food);

          }
        
          //add Hopper Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature hopper(Hopper, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, hopper);
          }

          //add Rover Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature rover(Rover, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, rover);
          }

          //add Trap Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature trap(Trap, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, trap);
          }
          d.simulate(1000,99);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // 9: darwin 72x72
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

        Darwin d(72,72);

          srand(0);
          
          //add Food Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature food(Food, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, food);

          }
        
          //add Hopper Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature hopper(Hopper, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, hopper);
          }

          //add Rover Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature rover(Rover, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, rover);
          }

          //add Trap Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature trap(Trap, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, trap);
          }

          //add Best Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 5184;
            int dir = rand() % 4;
            Creature trap(Best, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/72, pos%72, trap);
          }
          d.simulate(1000,99);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

     // ------------
    // 10: darwin 100x100
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

        Darwin d(100,100);

          srand(0);
          
          //add Food Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 10000;
            int dir = rand() % 4;
            Creature food(Food, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/100, pos%100, food);

          }
        
          //add Hopper Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 10000;
            int dir = rand() % 4;
            Creature hopper(Hopper, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/100, pos%100, hopper);
          }

          //add Rover Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 10000;
            int dir = rand() % 4;
            Creature rover(Rover, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/100, pos%100, rover);
          }

          //add Trap Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 10000;
            int dir = rand() % 4;
            Creature trap(Trap, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/100, pos%100, trap);
          }

          //add Best Creatures
          for(int i = 1; i <= 10; i++){
            int pos = rand() % 10000;
            int dir = rand() % 4;
            Creature trap(Best, (Direction) ((dir + 3) % 4) );
            d.placeCreature(pos/100, pos%100, trap);
          }
          d.simulate(1000,99);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
