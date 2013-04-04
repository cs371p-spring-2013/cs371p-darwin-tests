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

// ---
// run
// ---

void runSimmulation(Board& gameboard, int totalRuns, int printEvery){
    gameboard.displayBoard();
    for(int i=0; i<totalRuns; i++){
        gameboard.Turn();
        if((i+1)%printEvery ==0)
            gameboard.displayBoard();
   }
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

    //Food food;
    Species food("f");
    food.add_insturction("left", -1);
    food.add_insturction("go", 0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    //Hopper hopper;
    Species hopper("h");
    hopper.add_insturction("hop", -1);
    hopper.add_insturction("go", 0);


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

    //Rover rover;
    Species rover("r");
    rover.add_insturction("if_enemy", 9);
    rover.add_insturction("if_empty", 7);
    rover.add_insturction("if_random", 5);
    rover.add_insturction("left", -1);
    rover.add_insturction("go", 0);
    rover.add_insturction("right", -1);
    rover.add_insturction("go", 0);
    rover.add_insturction("hop", -1);
    rover.add_insturction("go", 0);
    rover.add_insturction("infect", -1);
    rover.add_insturction("go", 0);


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
    Species trap("t");
    trap.add_insturction("if_enemy", 3);
    trap.add_insturction("left", -1);
    trap.add_insturction("go", 0);
    trap.add_insturction("infect", -1);
    trap.add_insturction("go", 0);

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
            srand(0);
            Board gameboard(8,8);
            Creature a(food,2);
            gameboard.placeCreature(&a,0,0);
            Creature b(hopper,1);
            gameboard.placeCreature(&b,3,3);
            Creature c(hopper,2);
            gameboard.placeCreature(&c,3,4);
            Creature d(hopper,3);
            gameboard.placeCreature(&d,4,4);
            Creature e(hopper,0);
            gameboard.placeCreature(&e,4,3);
            Creature f(food,1);
            gameboard.placeCreature(&f,7,7);

            runSimmulation(gameboard,5,1);
           
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
        /*
        7x9 Darwin
        Trap,   facing south, at (0, 0)
        Hopper, facing east,  at (3, 2)
        Rover,  facing north, at (5, 4)
        Trap,   facing west,  at (6, 8)
        Simulate 5 moves.
        Print every grid.
        */
        srand(0);
        Board gameboard(7,9);
        Creature a(trap,3);
        gameboard.placeCreature(&a,0,0);
        Creature b(hopper,2);
        gameboard.placeCreature(&b,3,2);
        Creature c(rover,1);
        gameboard.placeCreature(&c,5,4);
        Creature d(trap,0);
        gameboard.placeCreature(&d,6,8);

        runSimmulation(gameboard,5,1);

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

            Board gameboard(72,72);
            //Construct vectors to hold food, hoppers, rovers, and traps
            vector<Creature> foodies;
            foodies.resize(10);
            
             for(int i=0; i<10; i++){
                int position = rand()%5184;
                foodies.at(i).species = &food;
                foodies.at(i).direction = rand()%4;
                gameboard.placeCreature(&foodies.at(i),position/72,position%72);
            }

            vector<Creature> hoppers;
            hoppers.resize(10);
            
             for(int i=0; i<10; i++){
                int position = rand()%5184;
                hoppers.at(i).species = &hopper;
                hoppers.at(i).direction = rand()%4;
                gameboard.placeCreature(&hoppers.at(i),position/72,position%72);
            }

            vector<Creature> rovers;
            rovers.resize(10);
            
             for(int i=0; i<10; i++){
                int position = rand()%5184;
                rovers.at(i).species = &rover;
                rovers.at(i).direction = rand()%4;
                gameboard.placeCreature(&rovers.at(i),position/72,position%72);
            }

            vector<Creature> trapers;
            trapers.resize(10);
            
             for(int i=0; i<10; i++){
                int position = rand()%5184;
                trapers.at(i).species = &trap;
                trapers.at(i).direction = rand()%4;
                gameboard.placeCreature(&trapers.at(i),position/72,position%72);
            }

            runSimmulation(gameboard,1000,100);

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

        //-------------------------------------------------------------------------------------------------------
        //OUR ACCEPTANCE TESTS:
        

        // ----------1
        // darwin 2x6
        //-----------

        try{
        cout << "*** Darwin 2x6 ***" << endl;
            srand(0);

            Board gameboard(2,6);

            Creature a(food,3);
            Creature b(food,3);
            gameboard.placeCreature(&a,0,0);
            gameboard.placeCreature(&b,1,0);
            Creature c(rover,1);
            gameboard.placeCreature(&c,1,5);

            runSimmulation(gameboard,12,1);

           //Endpoint:
          // 0 f.....
          // 1 rr....
        }
        catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

        //----------------2
        // Dominoe darwin
        // ---------------
        try{
        cout << "*** Darwin Dominoe 1x20 ***" << endl;
            srand(0);

            Board gameboard(1,20);

            vector<Creature> foodies;
            foodies.resize(19);
            
             for(int i=0; i<19; i++){
                foodies.at(i).species = &food;
                foodies.at(i).direction = (19-i)%4;
                gameboard.placeCreature(&foodies.at(i),0,i);
            }

            Creature a(trap,0);
            gameboard.placeCreature(&a,0,19);

            runSimmulation(gameboard,20,1);

           //Endpoint:
          // 0 tttttttttttttttttttt
        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}


        // -----------------3
        // Hopper wave WOOSH
        // -----------------

        try{
        cout << "*** Darwin Hop Wave 20x20 ***" << endl;
            srand(0);

            Board gameboard(20,20);

            vector<Creature> hoppers;
            hoppers.resize(20);
            
             for(int i=0; i<20; i++){
                hoppers.at(i).species = &hopper;
                hoppers.at(i).direction = 1;
                gameboard.placeCreature(&hoppers.at(i),19,i);
            }

            gameboard.displayBoard();

            runSimmulation(gameboard,20,4);


           //Endpoint:
          // hoppers moved from bottom of screen to top.
        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}


        // --------------4
        // darwin elevator
        // --------------

        try{
        cout << "*** Darwin elevator 8x8 ***" << endl;
            srand(0);

            Board gameboard(8,8);

            vector<Creature> foodies;
            foodies.resize(8);
            
             for(int i=0; i<8; i++){
                foodies.at(i).species = &food;
                foodies.at(i).direction = 1;
                gameboard.placeCreature(&foodies.at(i),i,5);
            }

            Creature a(rover, 1);
            gameboard.placeCreature(&a,7,4);

            runSimmulation(gameboard,19,1);
  

           //Endpoint:
          // r's move up and down the separation
        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

        // --------------------------5
        // cornerCase - no wall check
        // --------------------------
        
    try{
        cout << "*** cornerCase no wall check 1x1 ***" << endl;
            srand(0);

            Board gameboard(1,1);

            Creature a(food, 1);
            gameboard.placeCreature(&a,0,0);

            runSimmulation(gameboard,5,1);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

        // --------------------------6
        // cornerCase - wallcheck
        // --------------------------
        
    try{
        cout << "*** cornerCase no wall check 1x1 ***" << endl;
            srand(0);

            Board gameboard(1,1);

            Creature a(rover, 1);
            gameboard.placeCreature(&a,0,0);

            runSimmulation(gameboard,5,1);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

        // --------------------------7
        // Tests Food
        // --------------------------

  try{
        cout << "*** Food ***" << endl;
            srand(0);

            Board gameboard(8,8);

            Creature a(food, 0);
            gameboard.placeCreature(&a,0,0);

            runSimmulation(gameboard,5,1);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}


        // --------------------------8
        // Tests Hopper
        // --------------------------

        try{
        cout << "*** Hopper ***" << endl;
            srand(0);

            Board gameboard(4,4);

            Creature a(hopper, 1);
            gameboard.placeCreature(&a,1,1);

            runSimmulation(gameboard,4,1);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

        // --------------------------9
        // Tests Trap and Food
        // --------------------------

        try{
        cout << "*** Trap and Food ***" << endl;
            srand(0);

            Board gameboard(4,4);

            Creature a(trap, 1);
            Creature b(food,0);
            gameboard.placeCreature(&a,1,1);
            gameboard.placeCreature(&b,1,0);

            runSimmulation(gameboard,4,1);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}


        // --------------------------10
        // Tests Rover and Food
        // --------------------------


        try{
        cout << "*** Rover and Food ***" << endl;
            srand(0);

            Board gameboard(4,4);

            Creature a(rover, 1);
            Creature b(food,0);
            gameboard.placeCreature(&a,2,2);
        gameboard.placeCreature(&b,0,3);

            runSimmulation(gameboard,7,1);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}

        //------------------------------11
        // Stress test
        //------------------------------

        try{
        cout << "*** Stress Test  ***" << endl;
            srand(0);

            Board gameboard(30,30);

            vector<Creature> foodies;
            foodies.resize(70);
            vector<Creature> hoppers;
            hoppers.resize(70);
            vector<Creature> roverer;
            roverer.resize(70);

            for(int i=0; i<70;i++){
                int position = rand()%600;
                foodies.at(i).species = &food;
                foodies.at(i).direction = rand()%4;
                gameboard.placeCreature(&foodies.at(i),position/30,position%30);
                position = rand()%600;
                hoppers.at(i).species=&hopper;
                hoppers.at(i).direction = rand()%4;
                gameboard.placeCreature(&hoppers.at(i),position/30,position%30);
                position = rand()%600;
                roverer.at(i).species=&rover;
                roverer.at(i).direction = rand()%4;
                gameboard.placeCreature(&roverer.at(i),position/30,position%30);
            }
            

            runSimmulation(gameboard,20,4);
  

           //Endpoint:

        }catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
        assert(false);}


    return 0;}

