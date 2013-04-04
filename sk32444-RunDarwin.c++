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
#include <map>
#include <utility>
#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // Instruction  Number  Argument    Style: (Number, Argument)             
    // HOP          0       0           (0,0)
    // LEFT         1       0           (1,0)
    // RIGHT        2       0           (2,0)
    // INFECT       3       0           (3,0)
    // IF_EMPTY     4       line# n     (4,n)
    // IF_WALL      5       line# n     (5,n) 
    // IF_RANDOM    6       line# n     (6,n)
    // IF_ENEMY     7       line# n     (7,n)
    // GO           8       line# n     (8,n)


    vector<pair<int,int> > food;
    food.push_back(make_pair(1,0));
    food.push_back(make_pair(8,0));
    
    vector<pair<int,int> > hopper;
    hopper.push_back(make_pair(0,0));
    hopper.push_back(make_pair(8,0));

    vector<pair<int,int> > trap;
    trap.push_back(make_pair(7,3));
    trap.push_back(make_pair(1,0));
    trap.push_back(make_pair(8,0));
    trap.push_back(make_pair(3,0));
    trap.push_back(make_pair(8,0));

    vector<pair<int,int> > rover;
    rover.push_back(make_pair(7,9));
    rover.push_back(make_pair(4,7));
    rover.push_back(make_pair(6,5));
    rover.push_back(make_pair(1,0));
    rover.push_back(make_pair(8,0));
    rover.push_back(make_pair(2,0));
    rover.push_back(make_pair(8,0));
    rover.push_back(make_pair(0,0));
    rover.push_back(make_pair(8,0));
    rover.push_back(make_pair(3,0));
    rover.push_back(make_pair(8,0));

    vector<Species> all_species;
    all_species.push_back(Species('f', food));      // 0
    all_species.push_back(Species('h', hopper));    // 1
    all_species.push_back(Species('r', rover));     // 2
    all_species.push_back(Species('t', trap));      // 3

    // ----------
    // darwin 1x5
    // ----------
    try {
            srand(0);
            cout << "*** Darwin 1x5 ***" << endl;
            
            World world(1, 5, all_species);
            world.place(0, EAST, 0, 0);
            world.place(1, WEST, 0, 4);

            world.simulate(5, 1, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 1x5
    // Use a rover and food
    // ----------
    try {
            srand(0);
            cout << "*** Darwin 1x5 ***" << endl;
     
            World world(1, 5, all_species);
            world.place(0, EAST,  0, 0);
            world.place(2, WEST,  0, 4);

            world.simulate(5, 1, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 5x5
    // Use a rover and hopper
    // ----------
    try {
            srand(0);
            cout << "*** Darwin 5x5 ***" << endl;

            World world(5, 5, all_species);        
            world.place(1, SOUTH, 0, 0);
            world.place(2, WEST,  4, 4);

            world.simulate(5, 1, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 10x10
    // Use many rovers and traps
    // ----------
    try {
            srand(0);
            cout << "*** Darwin 10x10 ***" << endl;
           
            World world(10, 10, all_species);
            world.place(3, SOUTH, 5, 4);
            world.place(3, EAST,  9, 4);
            world.place(3, NORTH, 2, 5);
            world.place(3, SOUTH, 8, 7);
            world.place(3, NORTH, 1, 9);
            world.place(3, WEST,  3, 5);
            world.place(3, WEST,  0, 8);
            world.place(3, SOUTH, 3, 1);
            world.place(3, EAST,  4, 7);
            world.place(3, NORTH, 9, 9);

            world.place(2, EAST,  8, 8);
            world.place(2, NORTH, 6, 5);
            world.place(2, WEST,  4, 1);
            world.place(2, SOUTH, 1, 7);
            world.place(2, EAST,  5, 0);

            world.simulate(10, 2, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 30x30
    // Use many hoppers, foods, and traps that sweep the board
    // ----------
    try {
            srand(0);
            cout << "*** Darwin 30x30 ***" << endl;
    
            World world(30,30, all_species);
            for(int i = 0; i < 30; ++i){
                world.place(1, SOUTH, 0, i);
                world.place(3, NORTH, 6, i);
                world.place(0, WEST,  21, i);                
                world.place(1, NORTH, 29, 29-i);
            }

            world.simulate(30, 5, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 30x30
    // Place 7 hoppers, 7 rovers, and 7 traps randomly on the grid
    // ----------
    try {
            srand(0);
            cout << "*** Darwin 30x30 ***" << endl;
            
            World world(30,30, all_species);
            for(int i = 0; i < 5; ++i){
                int rand_hopper_pos = (rand()%900) - 1;
                Direction rand_hopper_dir = Direction(rand()%4);
                world.place(1, rand_hopper_dir, rand_hopper_pos/30, rand_hopper_pos%30);

                int rand_trap_pos   = (rand()%900) - 1;
                Direction rand_trap_dir = Direction(rand()%4);
                world.place(3, rand_trap_dir, rand_trap_pos/30, rand_trap_pos%30);

                int rand_rover_pos  = (rand()%900) - 1;
                Direction rand_rover_dir = Direction(rand()%4);
                world.place(2, rand_rover_dir, rand_rover_pos/30, rand_rover_pos%30);
            }

            world.simulate(40,10,cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
            cout << "*** Darwin 8x8 ***" << endl;

            World world(8, 8, all_species);
            world.place(0, EAST,  0, 0);
            world.place(1, NORTH, 3, 3);
            world.place(1, EAST,  3, 4);
            world.place(1, SOUTH, 4, 4);
            world.place(1, WEST,  4, 3);
            world.place(0, NORTH, 7, 7);

            world.simulate(5,1,cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 7x9
    // ----------

    try {
            srand(0);
            cout << "*** Darwin 7x9 ***" << endl;
                        
            World world(7, 9, all_species);
            world.place(3, SOUTH,  0, 0);
            world.place(1, EAST,   3, 2);
            world.place(2, NORTH,  5, 4);
            world.place(3, WEST,   6, 8);

            world.simulate(5,1,cout);
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
            srand(0);
            cout << "*** Darwin 72x72 without Best ***" << endl;

            World world(72, 72, all_species);

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

            for(int i = 0; i < 10; ++i){
                int food_random_pos = (rand() % 5184); 
                Direction food_random_dir = Direction(rand() % 4);
                int x = food_random_pos/72;
                world.place(0, food_random_dir, x, food_random_pos-(x*72));
            }

            for(int j = 0; j < 10; ++j){
                int hopper_random_pos = (rand() % 5184);
                Direction hopper_random_dir = Direction(rand() % 4);
                int x = hopper_random_pos/72;
                world.place(1, hopper_random_dir, x, hopper_random_pos-(x*72));  
            }

            for(int k = 0; k < 10; ++k){
                int rover_random_pos = (rand() % 5184);
                Direction rover_random_dir = Direction(rand() % 4);
                int x = rover_random_pos/72;
                world.place(2, rover_random_dir, x, rover_random_pos-(x*72));
            }

            for(int m = 0; m < 10; ++m){
                int trap_random_pos = (rand() % 5184);
                Direction trap_random_dir = Direction(rand() % 4);
                int x = trap_random_pos/72;
                world.place(3, trap_random_dir, x, trap_random_pos-(x*72));           
            }

            world.simulate(1000,100, cout);
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
            srand(0);
            cout << "*** Darwin 72x72 with Best ***" << endl;
            
            World world(72, 72, all_species);

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
            for(int i = 0; i < 10; ++i){
                int food_random_pos = (rand() % 5184); 
                Direction food_random_dir = Direction(rand() % 4);
                int x = food_random_pos/72;
                world.place(0, food_random_dir, x, food_random_pos-(x*72));
            }

            for(int j = 0; j < 10; ++j){
                int hopper_random_pos = (rand() % 5184);
                Direction hopper_random_dir = Direction(rand() % 4);
                int x = hopper_random_pos/72;
                world.place(1, hopper_random_dir, x, hopper_random_pos-(x*72));  
            }

            for(int k = 0; k < 10; ++k){
                int rover_random_pos = (rand() % 5184);
                Direction rover_random_dir = Direction(rand() % 4);
                int x = rover_random_pos/72;
                world.place(2, rover_random_dir, x, rover_random_pos-(x*72));
            }

            for(int m = 0; m < 10; ++m){
                int trap_random_pos = (rand() % 5184);
                Direction trap_random_dir = Direction(rand() % 4);
                int x = trap_random_pos/72;
                world.place(3, trap_random_dir, x, trap_random_pos-(x*72));           
            }

            // for(int m = 0; m < 10; ++m){
            //     int best_random_pos = (rand() % 5184);
            //     Direction best_random_dir = Direction(rand() % 4);
            //     int x = best_random_pos/72;
            //     world.place(4, best_random_dir, x, best_random_pos-(x*72));           
            // }

            world.simulate(1000,100, cout);
            }
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}
    try {
            srand(0);
            cout << "*** Darwin 10x10 ***" << endl;
            
            World world(10, 10, all_species);
            
            for(int i = 0; i < 4; ++i){
                int food_random_pos = (rand() % 100); 
                Direction food_random_dir = Direction(rand() % 4);
                int x = food_random_pos/10;
                world.place(0, food_random_dir, x, food_random_pos-(x*10));
            }

            for(int j = 0; j < 4; ++j){
                int hopper_random_pos = (rand() % 100);
                Direction hopper_random_dir = Direction(rand() % 4);
                int x = hopper_random_pos/10;
                world.place(1, hopper_random_dir, x, hopper_random_pos-(x*10));  
            }

            for(int k = 0; k < 4; ++k){
                int rover_random_pos = (rand() % 100);
                Direction rover_random_dir = Direction(rand() % 4);
                int x = rover_random_pos/10;
                world.place(2, rover_random_dir, x, rover_random_pos-(x*10));
            }

            for(int m = 0; m < 4; ++m){
                int trap_random_pos = (rand() % 10);
                Direction trap_random_dir = Direction(rand() % 4);
                int x = trap_random_pos/10;
                world.place(3, trap_random_dir, x, trap_random_pos-(x*10));           
            }

            world.simulate(10,1, cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
