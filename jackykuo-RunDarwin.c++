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
    Specie food ("f");
    food.addStep("left", -1);
    food.addStep("go", 0);
    food.instruction(0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Specie hopper("h");
    hopper.addStep("hop", -1);
    hopper.addStep("go", 0);
    

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
    Specie rover("r");
    rover.addStep("if_enemy", 9);
    rover.addStep("if_empty", 7);
    rover.addStep("if_random", 5);
    rover.addStep("left", -1);
    rover.addStep("go", 0); 
    rover.addStep("right",-1);   
    rover.addStep("go", 0);
    rover.addStep("hop", -1);
    rover.addStep("go", 0);
    rover.addStep("infect", -1);
    rover.addStep("go", 0);
    
    
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
    Specie trap("t");
    trap.addStep("if_enemy",3);
    trap.addStep("left",-1);
    trap.addStep("go",0);
    trap.addStep("infect",-1);
    trap.addStep("go",0);
    
    // ----
    // best
    // ----
 /*
     0:  if_enemy 13
     1:  if_empty 11
     2:  if_random 7
     3:  left
     4:  if_random 6
     5:  go 0
     6:  go 1
     7:  right
     8:  if_random 10
     9:  go 0
     10: go 1
     11: hop
     12: go 0
     13: infect
    14: go 0
  */ 
    Specie best("b");
    best.addStep("if_enemy", 13);
    best.addStep("if_empty", 11);
    best.addStep("if_random", 7);
    best.addStep("left", -1);
    best.addStep("if_random", 6);
    best.addStep("go", 0); 
    best.addStep("go", 1); 
    best.addStep("right",-1);   
    best.addStep("if_random", 10);
    best.addStep("go", 0);
    best.addStep("go", 1); 
    best.addStep("hop", -1);
    best.addStep("go", 0);
    best.addStep("infect", -1);
    best.addStep("go", 0);
   
   
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
	
	World world1(8,8);
	Creature f1(food, 0,0,2);	
	Creature h1(hopper, 3,3,1);
	Creature h2(hopper, 3,4,2);
	Creature h3(hopper, 4,4,3);
	Creature h4(hopper, 4,3,0);
	Creature f2(food, 7,7,1);
	world1.put(f1,0,0);
	world1.put(h1,3,3);
	world1.put(h2,3,4);
	world1.put(h3,4,4);
	world1.put(h4,4,3);
	world1.put(f1,7,7);

        
	world1.simulate(5,1);
	
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 1x8
    // ----------

   try {
        cout << "*** Darwin 1x8 ***" << endl;

	
	World world1(8,1);
	Creature f1(food, 0,0,2);	
	Creature f2(food, 0,7,1);
	
	world1.put(f1,0,0);
	world1.put(f2,0,7);
    
	world1.simulate(2,1);
	
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
          
    // ----------
    // darwin 1x8 specifically infect
    // ----------

   try {
        cout << "*** Darwin 1x8 testing infect ***" << endl;

	
	World world1(8,1);
	Creature f1(food, 0,2,2);	
	Creature r1(rover, 0,3,0);
	
	world1.put(f1,0,2);
	world1.put(r1,0,3);
    
	world1.simulate(5,1);
	
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
       
   // ----------
    // darwin 1x1
    // ----------

   try {
        cout << "*** Darwin 1x1 ***" << endl;

	
	World world1(1,1);
	Creature f1(food, 0,0,2);
	
	world1.put(f1,0,0);
	    
	world1.simulate(2,1);
	
	
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
	World world2(15,7);
	Creature t1(trap, 0,0,3);	
	Creature h1(hopper, 3,2,2);
	Creature r1(rover, 5,4,2);
	Creature t2(trap, 6,8,0);
	//Creature b1(best,4,3,1);
	
	world2.put(t1,0,0);
	world2.put(h1,3,2);
	world2.put(r1,5,4);
	world2.put(t2,6,8);
	//world2.put(b1,4,3);
	

	world2.simulate(5,1);

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
	
	World world72(72,72);
	

	  int p = (rand()%5184);
	  int x = p/72;
	  int y = p-(x*72);
	  
	  Creature f1(food,x,y,rand()%4);
	  world72.put(f1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f2(food,x,y,rand()%4);
	  world72.put(f2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f3(food,x,y,rand()%4);
	  world72.put(f3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f4(food,x,y,rand()%4);
	  world72.put(f4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f5(food,x,y,rand()%4);
	  world72.put(f5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f6(food,x,y,rand()%4);
	  world72.put(f6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f7(food,x,y,rand()%4);
	  world72.put(f7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f8(food,x,y,rand()%4);
	  world72.put(f8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f9(food,x,y,rand()%4);
	  world72.put(f9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f10(food,x,y,rand()%4);
	  world72.put(f10,x,y);
	  
	  
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h1(hopper,x,y,rand()%4);
	  world72.put(h1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h2(hopper,x,y,rand()%4);
	  world72.put(h2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h3(hopper,x,y,rand()%4);
	  world72.put(h3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h4(hopper,x,y,rand()%4);
	  world72.put(h4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h5(hopper,x,y,rand()%4);
	  world72.put(h5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h6(hopper,x,y,rand()%4);
	  world72.put(h6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h7(hopper,x,y,rand()%4);
	  world72.put(h7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h8(hopper,x,y,rand()%4);
	  world72.put(h8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h9(hopper,x,y,rand()%4);
	  world72.put(h9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h10(hopper,x,y,rand()%4);
	  world72.put(h10,x,y);
	  
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r1(rover,x,y,rand()%4);
	  world72.put(r1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r2(rover,x,y,rand()%4);
	  world72.put(r2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r3(rover,x,y,rand()%4);
	  world72.put(r3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r4(rover,x,y,rand()%4);
	  world72.put(r4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r5(rover,x,y,rand()%4);
	  world72.put(r5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r6(rover,x,y,rand()%4);
	  world72.put(r6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r7(rover,x,y,rand()%4);
	  world72.put(r7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r8(rover,x,y,rand()%4);
	  world72.put(r8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r9(rover,x,y,rand()%4);
	  world72.put(r9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r10(rover,x,y,rand()%4);
	  world72.put(r10,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t1(trap,x,y,rand()%4);
	  world72.put(t1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t2(trap,x,y,rand()%4);
	  world72.put(t2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t3(trap,x,y,rand()%4);
	  world72.put(t3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t4(trap,x,y,rand()%4);
	  world72.put(t4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t5(trap,x,y,rand()%4);
	  world72.put(t5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t6(trap,x,y,rand()%4);
	  world72.put(t6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t7(trap,x,y,rand()%4);
	  world72.put(t7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t8(trap,x,y,rand()%4);
	  world72.put(t8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t9(trap,x,y,rand()%4);
	  world72.put(t9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t10(trap,x,y,rand()%4);
	  world72.put(t10,x,y);
	
	
	  world72.simulate(1000,100);
	
	
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
	
	World world72(72,72);
	
	int p = (rand()%5184);
	  int x = p/72;
	  int y = p-(x*72);
	  
	  Creature f1(food,x,y,rand()%4);
	  world72.put(f1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f2(food,x,y,rand()%4);
	  world72.put(f2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f3(food,x,y,rand()%4);
	  world72.put(f3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f4(food,x,y,rand()%4);
	  world72.put(f4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f5(food,x,y,rand()%4);
	  world72.put(f5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f6(food,x,y,rand()%4);
	  world72.put(f6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f7(food,x,y,rand()%4);
	  world72.put(f7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f8(food,x,y,rand()%4);
	  world72.put(f8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f9(food,x,y,rand()%4);
	  world72.put(f9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature f10(food,x,y,rand()%4);
	  world72.put(f10,x,y);
	  
	  
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h1(hopper,x,y,rand()%4);
	  world72.put(h1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h2(hopper,x,y,rand()%4);
	  world72.put(h2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h3(hopper,x,y,rand()%4);
	  world72.put(h3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h4(hopper,x,y,rand()%4);
	  world72.put(h4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h5(hopper,x,y,rand()%4);
	  world72.put(h5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h6(hopper,x,y,rand()%4);
	  world72.put(h6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h7(hopper,x,y,rand()%4);
	  world72.put(h7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h8(hopper,x,y,rand()%4);
	  world72.put(h8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h9(hopper,x,y,rand()%4);
	  world72.put(h9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature h10(hopper,x,y,rand()%4);
	  world72.put(h10,x,y);
	  
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r1(rover,x,y,rand()%4);
	  world72.put(r1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r2(rover,x,y,rand()%4);
	  world72.put(r2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r3(rover,x,y,rand()%4);
	  world72.put(r3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r4(rover,x,y,rand()%4);
	  world72.put(r4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r5(rover,x,y,rand()%4);
	  world72.put(r5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r6(rover,x,y,rand()%4);
	  world72.put(r6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r7(rover,x,y,rand()%4);
	  world72.put(r7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r8(rover,x,y,rand()%4);
	  world72.put(r8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r9(rover,x,y,rand()%4);
	  world72.put(r9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature r10(rover,x,y,rand()%4);
	  world72.put(r10,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t1(trap,x,y,rand()%4);
	  world72.put(t1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t2(trap,x,y,rand()%4);
	  world72.put(t2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t3(trap,x,y,rand()%4);
	  world72.put(t3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t4(trap,x,y,rand()%4);
	  world72.put(t4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t5(trap,x,y,rand()%4);
	  world72.put(t5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t6(trap,x,y,rand()%4);
	  world72.put(t6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t7(trap,x,y,rand()%4);
	  world72.put(t7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t8(trap,x,y,rand()%4);
	  world72.put(t8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t9(trap,x,y,rand()%4);
	  world72.put(t9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature t10(trap,x,y,rand()%4);
	  world72.put(t10,x,y);
	  
	    p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b1(best,x,y,rand()%4);
	  world72.put(b1,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b2(best,x,y,rand()%4);
	  world72.put(b2,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b3(best,x,y,rand()%4);
	  world72.put(b3,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b4(best,x,y,rand()%4);
	  world72.put(b4,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b5(best,x,y,rand()%4);
	  world72.put(b5,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b6(best,x,y,rand()%4);
	  world72.put(b6,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b7(best,x,y,rand()%4);
	  world72.put(b7,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b8(best,x,y,rand()%4);
	  world72.put(b8,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b9(best,x,y,rand()%4);
	  world72.put(b9,x,y);
	  
	  p = (std::rand()%5184);
	  x = p/72;
	  y = p-(x*72);
	  Creature b10(best,x,y,rand()%4);
	  world72.put(b10,x,y);
	  
	  
	  world72.simulate(1000,100);
	  
	
	
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 42x64 without Best
    // ----------
    
    try {
        cout << "*** Darwin 42x64 without Best ***" << endl;
        srand(0);
        

	World world42(64,42);
	

	  int p = (rand()%2688);
	  int x = p/64;
	  int y = p-(x*64);
	  
	  Creature f1(food,x,y,rand()%4);
	  world42.put(f1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f2(food,x,y,rand()%4);
	  world42.put(f2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f3(food,x,y,rand()%4);
	  world42.put(f3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f4(food,x,y,rand()%4);
	  world42.put(f4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f5(food,x,y,rand()%4);
	  world42.put(f5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f6(food,x,y,rand()%4);
	  world42.put(f6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f7(food,x,y,rand()%4);
	  world42.put(f7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f8(food,x,y,rand()%4);
	  world42.put(f8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f9(food,x,y,rand()%4);
	  world42.put(f9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f10(food,x,y,rand()%4);
	  world42.put(f10,x,y);
	  
	 
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h1(hopper,x,y,rand()%4);
	  world42.put(h1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h2(hopper,x,y,rand()%4);
	  world42.put(h2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h3(hopper,x,y,rand()%4);
	  world42.put(h3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h4(hopper,x,y,rand()%4);
	  world42.put(h4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h5(hopper,x,y,rand()%4);
	  world42.put(h5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h6(hopper,x,y,rand()%4);
	  world42.put(h6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h7(hopper,x,y,rand()%4);
	  world42.put(h7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h8(hopper,x,y,rand()%4);
	  world42.put(h8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h9(hopper,x,y,rand()%4);
	  world42.put(h9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h10(hopper,x,y,rand()%4);
	  world42.put(h10,x,y);
	  
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r1(rover,x,y,rand()%4);
	  world42.put(r1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r2(rover,x,y,rand()%4);
	  world42.put(r2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r3(rover,x,y,rand()%4);
	  world42.put(r3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r4(rover,x,y,rand()%4);
	  world42.put(r4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r5(rover,x,y,rand()%4);
	  world42.put(r5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r6(rover,x,y,rand()%4);
	  world42.put(r6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r7(rover,x,y,rand()%4);
	  world42.put(r7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r8(rover,x,y,rand()%4);
	  world42.put(r8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r9(rover,x,y,rand()%4);
	  world42.put(r9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r10(rover,x,y,rand()%4);
	  world42.put(r10,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t1(trap,x,y,rand()%4);
	  world42.put(t1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t2(trap,x,y,rand()%4);
	  world42.put(t2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t3(trap,x,y,rand()%4);
	  world42.put(t3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t4(trap,x,y,rand()%4);
	  world42.put(t4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t5(trap,x,y,rand()%4);
	  world42.put(t5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t6(trap,x,y,rand()%4);
	  world42.put(t6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t7(trap,x,y,rand()%4);
	  world42.put(t7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t8(trap,x,y,rand()%4);
	  world42.put(t8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t9(trap,x,y,rand()%4);
	  world42.put(t9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t10(trap,x,y,rand()%4);
	  world42.put(t10,x,y);
	
	
	  world42.simulate(500,100);
	
	
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // darwin 42x64 with Best
    // ----------
    
    try {
        cout << "*** Darwin 42x64 with Best ***" << endl;
        srand(0);
        
	World world42(64,42);
	

	  int p = (rand()%2688);
	  int x = p/64;
	  int y = p-(x*64);
	  
	  Creature f1(food,x,y,rand()%4);
	  world42.put(f1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f2(food,x,y,rand()%4);
	  world42.put(f2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f3(food,x,y,rand()%4);
	  world42.put(f3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f4(food,x,y,rand()%4);
	  world42.put(f4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f5(food,x,y,rand()%4);
	  world42.put(f5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f6(food,x,y,rand()%4);
	  world42.put(f6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f7(food,x,y,rand()%4);
	  world42.put(f7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f8(food,x,y,rand()%4);
	  world42.put(f8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f9(food,x,y,rand()%4);
	  world42.put(f9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f10(food,x,y,rand()%4);
	  world42.put(f10,x,y);
	  
	 
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h1(hopper,x,y,rand()%4);
	  world42.put(h1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h2(hopper,x,y,rand()%4);
	  world42.put(h2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h3(hopper,x,y,rand()%4);
	  world42.put(h3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h4(hopper,x,y,rand()%4);
	  world42.put(h4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h5(hopper,x,y,rand()%4);
	  world42.put(h5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h6(hopper,x,y,rand()%4);
	  world42.put(h6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h7(hopper,x,y,rand()%4);
	  world42.put(h7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h8(hopper,x,y,rand()%4);
	  world42.put(h8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h9(hopper,x,y,rand()%4);
	  world42.put(h9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h10(hopper,x,y,rand()%4);
	  world42.put(h10,x,y);
	  
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r1(rover,x,y,rand()%4);
	  world42.put(r1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r2(rover,x,y,rand()%4);
	  world42.put(r2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r3(rover,x,y,rand()%4);
	  world42.put(r3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r4(rover,x,y,rand()%4);
	  world42.put(r4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r5(rover,x,y,rand()%4);
	  world42.put(r5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r6(rover,x,y,rand()%4);
	  world42.put(r6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r7(rover,x,y,rand()%4);
	  world42.put(r7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r8(rover,x,y,rand()%4);
	  world42.put(r8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r9(rover,x,y,rand()%4);
	  world42.put(r9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r10(rover,x,y,rand()%4);
	  world42.put(r10,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t1(trap,x,y,rand()%4);
	  world42.put(t1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t2(trap,x,y,rand()%4);
	  world42.put(t2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t3(trap,x,y,rand()%4);
	  world42.put(t3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t4(trap,x,y,rand()%4);
	  world42.put(t4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t5(trap,x,y,rand()%4);
	  world42.put(t5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t6(trap,x,y,rand()%4);
	  world42.put(t6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t7(trap,x,y,rand()%4);
	  world42.put(t7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t8(trap,x,y,rand()%4);
	  world42.put(t8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t9(trap,x,y,rand()%4);
	  world42.put(t9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t10(trap,x,y,rand()%4);
	  world42.put(t10,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b1(best,x,y,rand()%4);
	  world42.put(b1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b2(best,x,y,rand()%4);
	  world42.put(b2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b3(best,x,y,rand()%4);
	  world42.put(b3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b4(best,x,y,rand()%4);
	  world42.put(b4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b5(best,x,y,rand()%4);
	  world42.put(b5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b6(best,x,y,rand()%4);
	  world42.put(b6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b7(best,x,y,rand()%4);
	  world42.put(b7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b8(best,x,y,rand()%4);
	  world42.put(b8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b9(best,x,y,rand()%4);
	  world42.put(b9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b10(best,x,y,rand()%4);
	  world42.put(b10,x,y);
	
	
	  world42.simulate(500,100);
	
	
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
         
    // ----------
    // darwin 42x64 with 20 Best
    // ---------- 
   
   try {
        cout << "*** Darwin 42x64 with 20 Best ***" << endl;
        srand(0);
        

	World world42(64,42);
	

	  int p = (rand()%2688);
	  int x = p/64;
	  int y = p-(x*64);
	  
	  Creature f1(food,x,y,rand()%4);
	  world42.put(f1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f2(food,x,y,rand()%4);
	  world42.put(f2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f3(food,x,y,rand()%4);
	  world42.put(f3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f4(food,x,y,rand()%4);
	  world42.put(f4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f5(food,x,y,rand()%4);
	  world42.put(f5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f6(food,x,y,rand()%4);
	  world42.put(f6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f7(food,x,y,rand()%4);
	  world42.put(f7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f8(food,x,y,rand()%4);
	  world42.put(f8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f9(food,x,y,rand()%4);
	  world42.put(f9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature f10(food,x,y,rand()%4);
	  world42.put(f10,x,y);
	  
	 
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h1(hopper,x,y,rand()%4);
	  world42.put(h1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h2(hopper,x,y,rand()%4);
	  world42.put(h2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h3(hopper,x,y,rand()%4);
	  world42.put(h3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h4(hopper,x,y,rand()%4);
	  world42.put(h4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h5(hopper,x,y,rand()%4);
	  world42.put(h5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h6(hopper,x,y,rand()%4);
	  world42.put(h6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h7(hopper,x,y,rand()%4);
	  world42.put(h7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h8(hopper,x,y,rand()%4);
	  world42.put(h8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h9(hopper,x,y,rand()%4);
	  world42.put(h9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature h10(hopper,x,y,rand()%4);
	  world42.put(h10,x,y);
	  
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r1(rover,x,y,rand()%4);
	  world42.put(r1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r2(rover,x,y,rand()%4);
	  world42.put(r2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r3(rover,x,y,rand()%4);
	  world42.put(r3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r4(rover,x,y,rand()%4);
	  world42.put(r4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r5(rover,x,y,rand()%4);
	  world42.put(r5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r6(rover,x,y,rand()%4);
	  world42.put(r6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r7(rover,x,y,rand()%4);
	  world42.put(r7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r8(rover,x,y,rand()%4);
	  world42.put(r8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r9(rover,x,y,rand()%4);
	  world42.put(r9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature r10(rover,x,y,rand()%4);
	  world42.put(r10,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t1(trap,x,y,rand()%4);
	  world42.put(t1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t2(trap,x,y,rand()%4);
	  world42.put(t2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t3(trap,x,y,rand()%4);
	  world42.put(t3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t4(trap,x,y,rand()%4);
	  world42.put(t4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t5(trap,x,y,rand()%4);
	  world42.put(t5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t6(trap,x,y,rand()%4);
	  world42.put(t6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t7(trap,x,y,rand()%4);
	  world42.put(t7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t8(trap,x,y,rand()%4);
	  world42.put(t8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t9(trap,x,y,rand()%4);
	  world42.put(t9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature t10(trap,x,y,rand()%4);
	  world42.put(t10,x,y);
	  
	  	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b1(best,x,y,rand()%4);
	  world42.put(b1,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b2(best,x,y,rand()%4);
	  world42.put(b2,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b3(best,x,y,rand()%4);
	  world42.put(b3,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b4(best,x,y,rand()%4);
	  world42.put(b4,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b5(best,x,y,rand()%4);
	  world42.put(b5,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b6(best,x,y,rand()%4);
	  world42.put(b6,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b7(best,x,y,rand()%4);
	  world42.put(b7,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b8(best,x,y,rand()%4);
	  world42.put(b8,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b9(best,x,y,rand()%4);
	  world42.put(b9,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b10(best,x,y,rand()%4);
	  world42.put(b10,x,y);
	  	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b11(best,x,y,rand()%4);
	  world42.put(b11,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b12(best,x,y,rand()%4);
	  world42.put(b12,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b13(best,x,y,rand()%4);
	  world42.put(b13,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b14(best,x,y,rand()%4);
	  world42.put(b14,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b15(best,x,y,rand()%4);
	  world42.put(b15,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b16(best,x,y,rand()%4);
	  world42.put(b16,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b17(best,x,y,rand()%4);
	  world42.put(b17,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b18(best,x,y,rand()%4);
	  world42.put(b18,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b19(best,x,y,rand()%4);
	  world42.put(b19,x,y);
	  
	  p = (std::rand()%2688);
	  x = p/64;
	  y = p-(x*64);
	  Creature b20(best,x,y,rand()%4);
	  world42.put(b20,x,y);
	
	
	  world42.simulate(500,100);
	
	
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
        return 0;}