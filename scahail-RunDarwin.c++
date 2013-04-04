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

    // ----
    // food
    // ----
    /*
     0: left
     1: go 0
    */
    Left left;
    Go go(0);

    vector<Instruction*> food_prog;
    food_prog.push_back(&left);
    food_prog.push_back(&go);
    Species s_food('f', food_prog); //s_food == species for food

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Hop hop;
    vector<Instruction*> hopper_prog;
    hopper_prog.push_back(&hop);
    hopper_prog.push_back(&go);
    Species s_hopper('h', hopper_prog);

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
    IfEnemy if_enemy_9(9);
    IfEmpty if_empty_7(7);
    IfEnemy if_random_5(5);
    Infect infect;
    Right right;
    vector<Instruction*> rover_prog;
    rover_prog.push_back(&if_enemy_9); //0: if_enemy 9
    rover_prog.push_back(&if_empty_7); //1: if_empty 7
    rover_prog.push_back(&if_random_5); //2: if_random 5
    rover_prog.push_back(&left); //3: left
    rover_prog.push_back(&go); //4: go 0
    rover_prog.push_back(&right); //5: right
    rover_prog.push_back(&go); //6: go 0
    rover_prog.push_back(&hop); //7: hop
    rover_prog.push_back(&go); //8: go 0
    rover_prog.push_back(&infect); //9: infect
    rover_prog.push_back(&go); //10: go 0
    Species s_rover('r', rover_prog);

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
    IfEnemy if_enemy_3(3);
    vector<Instruction*> trap_prog;
    trap_prog.push_back(&if_enemy_3);
    trap_prog.push_back(&left);
    trap_prog.push_back(&go);
    trap_prog.push_back(&infect);
    trap_prog.push_back(&go);
    Species s_trap('t', trap_prog);

    int mapping[]= {WEST, NORTH, EAST, SOUTH};
    try {
        /*
        4x4 Darwin
        Food,   facing east,  at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        cout << "*** Darwin 4x4 ***" << endl;
        srand(0);
        Creature creature(&s_food);
        CreatureContainer container(NORTH, 5, creature);
        vector<CreatureContainer> c_containers;
        c_containers.push_back(container);
        Game game(c_containers, 4, 4);
        Instruction::setGame(game);
        
        game.play(5, 1, std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        /*
        4x4 Darwin
        Food,   facing east,  at (0, 0)
        Simulate 5 moves.
        Print every grid.
        */
        cout << "*** Darwin 4x4 ***" << endl;
        srand(0);
        Creature food(&s_food);
        Creature trap(&s_trap);
        CreatureContainer food_container(NORTH, 5, food);
        CreatureContainer trap_container(NORTH, 6, trap);
        vector<CreatureContainer> c_containers;
        c_containers.push_back(food_container);
        c_containers.push_back(trap_container);
        Game game(c_containers, 4, 4);
        Instruction::setGame(game);
        
        game.play(5, 1, std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        Creature c1(&s_rover);
        Creature c2(&s_rover);
        Creature c3(&s_rover);
        Creature c4(&s_rover);
        CreatureContainer cc1(SOUTH, 2, c1);
        CreatureContainer cc2(NORTH, 22, c2);
        CreatureContainer cc3(EAST, 10, c3);
        CreatureContainer cc4(WEST, 14, c4);

        vector<CreatureContainer> c_containers;
        c_containers.push_back(cc1);
        c_containers.push_back(cc2);
        c_containers.push_back(cc3);
        c_containers.push_back(cc4);

        Game game(c_containers, 5, 5);
        Instruction::setGame(game);
        
        game.play(5, 1, std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        //Lone hopper in a minefield
        cout << "*** Darwin 45x45 ***" << endl;
        srand(0);

        vector<CreatureContainer> c_containers;
        for(int i=0; i<100; ++i){
          Creature trap(&s_trap);
          CreatureContainer v_container(rand()%4, rand()%(45*45), trap);
          c_containers.push_back(v_container);
        }

        Creature hopper(&s_hopper);
        CreatureContainer h_container(rand()%4, rand()%(45*45), hopper);
        c_containers.push_back(h_container);
        
        Game game(c_containers, 45, 45);
        Instruction::setGame(game);
        
        game.play(10, 1, std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        Creature c1(&s_rover);
        Creature c2(&s_rover);
        Creature c3(&s_rover);
        Creature c4(&s_rover);
        CreatureContainer cc1(SOUTH, 2, c1);
        CreatureContainer cc2(NORTH, 22, c2);
        CreatureContainer cc3(EAST, 10, c3);
        CreatureContainer cc4(WEST, 14, c4);

        vector<CreatureContainer> c_containers;
        c_containers.push_back(cc1);
        c_containers.push_back(cc2);
        c_containers.push_back(cc3);
        c_containers.push_back(cc4);

        Game game(c_containers, 10, 10);
        Instruction::setGame(game);
        
        game.play(5, 1, std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        //Rovers vs Traps
        cout << "*** Darwin 45x45 ***" << endl;
        srand(0);


        vector<CreatureContainer> c_containers;
        
        Creature creature(&s_hopper);
        for(int i=0; i<100; ++i){
          if(rand()%2==0){
            creature = Creature(&s_rover);
          } else {
            creature = Creature(&s_trap);
          }
          CreatureContainer c_container(rand()%4, rand()%(45*45), creature);
          c_containers.push_back(c_container);
        }

        Game game(c_containers, 45, 45);
        Instruction::setGame(game);
        
        game.play(2000, 500, std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        //Rover among food and hoppers
        cout << "*** Darwin 45x45 ***" << endl;
        srand(0);

        Creature patient_zero(&s_rover);
        CreatureContainer cc_zero(SOUTH, 1012, patient_zero);

        vector<CreatureContainer> c_containers;
        c_containers.push_back(cc_zero);
        
        Creature victim(&s_hopper);
        for(int i=0; i<100; ++i){
          if(rand()%2==0){
            victim = Creature(&s_hopper);
          } else {
            victim = Creature(&s_food);
          }
          CreatureContainer v_container(rand()%4, rand()%(45*45), victim);
          c_containers.push_back(v_container);
        }

        Game game(c_containers, 45, 45);
        Instruction::setGame(game);
        
        game.play(500, 100, std::cout);
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
        vector<CreatureContainer> cc_vector;

        Creature c1(&s_food);
        CreatureContainer cc1(EAST, 0, c1);

        Creature c2(&s_hopper);
        CreatureContainer cc2(NORTH, 27, c2);

        Creature c3(&s_hopper);
        CreatureContainer cc3(EAST, 28, c3);

        //Hopper, facing south, at (4, 4)
        Creature c4(&s_hopper);
        CreatureContainer cc4(SOUTH, 36, c4);

        //Hopper, facing west, at (4, 3)
        Creature c5(&s_hopper);
        CreatureContainer cc5(WEST, 35, c5);

        //Food,   facing north, at (7, 7)
        Creature c6(&s_food);
        CreatureContainer cc6(WEST, 63, c6);

        cc_vector.push_back(cc1);
        cc_vector.push_back(cc2);
        cc_vector.push_back(cc3);
        cc_vector.push_back(cc4);
        cc_vector.push_back(cc5);
        cc_vector.push_back(cc6);


        Game game(cc_vector, 8, 8);
        Instruction::setGame(game);

        game.play(5, 1, std::cout);
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

        //Trap,   facing south, at (0, 0)
        Creature c1(&s_trap);
        CreatureContainer cc1(SOUTH, 0, c1); 
        //Hopper, facing east,  at (3, 2)
        Creature c2(&s_hopper);
        CreatureContainer cc2(EAST, 29, c2); 
        //Rover,  facing north, at (5, 4)
        Creature c3(&s_rover);
        CreatureContainer cc3(NORTH, 49, c3); 
        //Trap,   facing west,  at (6, 8)
        Creature c4(&s_trap);
        CreatureContainer cc4(WEST, 62, c4); 

        vector<CreatureContainer> cc_vector;
        cc_vector.push_back(cc1);
        cc_vector.push_back(cc2);
        cc_vector.push_back(cc3);
        cc_vector.push_back(cc4);

        Game game(cc_vector, 7, 9);
        Instruction::setGame(game);

        game.play(5, 1, std::cout);
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
        int pos;
        int dir;
        vector<CreatureContainer> cc_vector;

        for(int i=0; i<10; i++){
          pos = rand()%5184;
          dir = mapping[rand()%4];
          Creature creature (&s_food);
          CreatureContainer cc(dir, pos, creature);
          cc_vector.push_back(cc);

        }
        for(int i=0; i<10; i++){
          pos = rand()%5184;
          dir = mapping[rand()%4];
          Creature creature(&s_hopper);
          CreatureContainer cc(dir, pos, creature);
          cc_vector.push_back(cc);

        }
        for(int i=0; i<10; i++){
          pos = rand()%5184;
          dir = mapping[rand()%4];
          Creature creature(&s_rover);
          CreatureContainer cc(dir, pos, creature);
          cc_vector.push_back(cc);

        }
        for(int i=0; i<10; i++){
          pos = rand()%5184;
          dir = mapping[rand()%4];
          Creature creature(&s_trap);
          CreatureContainer cc(dir, pos, creature);
          cc_vector.push_back(cc);
        }

        Game game(cc_vector, 72, 72);
        Instruction::setGame(game);
        
        //game.print(std::cout);
        game.play(1000,100,std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // darwin 72x72
    // with best
    // ------------

    return 0;}
