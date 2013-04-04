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
#include <vector>
#include <string>
#include "Darwin.h"


/*
unsigned int split (const std::string &txt, std::vector<std::string> &strs, char ch) {
    unsigned int pos = txt.find(ch);
    unsigned int initial_pos = 0;
    strs.clear();
    
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initial_pos, pos - initial_pos + 1));
        initial_pos = pos + 1;
        
        pos = txt.find(ch, initial_pos);
    }
    
    strs.push_back(txt.substr(initial_pos,
        std::min(pos, (unsigned int)txt.length()) - initial_pos + 1));
    
    return strs.size();
}*/

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    Creature_Programs programs;
    vector<string> prog;

    // ----
    // food
    // ----

    /*
    0: left
    1: go 0
    */
    
    prog.push_back("left");
    prog.push_back("go 0");
    programs.add_program(prog, 'f');
    
    
    // ------
    // hopper
    // ------

    /*
    0: hop
    1: go 0

    */

    prog.clear();
    prog.push_back("hop");
    prog.push_back("go 0");
    programs.add_program(prog, 'h');


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

    prog.clear();
    prog.push_back("if_enemy 9");
    prog.push_back("if_empty 7");
    prog.push_back("if_rand 5");
    prog.push_back("left");
    prog.push_back("go 0");
    prog.push_back("right");
    prog.push_back("go 0");
    prog.push_back("hop");
    prog.push_back("go 0");
    prog.push_back("infect");
    prog.push_back("go 0");
    programs.add_program(prog, 'r');


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

    prog.clear();
    prog.push_back("if_enemy 3");
    prog.push_back("left");
    prog.push_back("go 0");
    prog.push_back("infect");
    prog.push_back("go 0");
    programs.add_program(prog, 't');

    
    // ----
    // best
    // ----

    /*
    0: if_enemy 3
    1: left
    2: go 0
    3: infect
    4: go 0
    */

    prog.clear();
    prog.push_back("if_enemy 3");
    prog.push_back("left");
    prog.push_back("go 0");
    prog.push_back("infect");
    prog.push_back("go 0");
    programs.add_program(prog, 'b');
    

    // species #:
    //   0 = food
    //   1 = hopper
    //   2 = rover
    //   3 = trap
    //   4 = best (mine)

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
        (NEED TO FLIP THE COORDINATES, IN ROW MAJOR ORDER)
        */
        
        int num_turns = 5;
        Darwin_Game game(8, 8);
        
        // creates the creatures
        Creature creature1(&programs, 0, 2);
        game.add_creature(&creature1, 0, 0);
        
        Creature creature2(&programs, 1, 1);
        game.add_creature(&creature2, 3, 3);
        
        Creature creature3(&programs, 1, 2);
        game.add_creature(&creature3, 4, 3);
        
        Creature creature4(&programs, 1, 3);
        game.add_creature(&creature4, 4, 4);
        
        Creature creature5(&programs, 1, 4);
        game.add_creature(&creature5, 3, 4);
        
        Creature creature6(&programs, 0, 1);
        game.add_creature(&creature6, 7, 7);
        
        // runs the game
        for (int i = 0; i < num_turns; ++i) {
            cout << "Turn = " << i << "." << endl;
            cout << game.print_grid() << endl;
            game.execute_turn();
        }
        cout << "Turn = " << num_turns << "." << endl;
        cout << game.print_grid() << endl;
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }


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
        
        int num_turns = 5;
        Darwin_Game game(7, 9);
        
        // creates the creatures
        Creature creature1(&programs, 3, 3);
        game.add_creature(&creature1, 0, 0);
        
        Creature creature2(&programs, 1, 2);
        game.add_creature(&creature2, 2, 3);
        
        Creature creature3(&programs, 2, 1);
        game.add_creature(&creature3, 4, 5);
        
        Creature creature4(&programs, 3, 4);
        game.add_creature(&creature4, 8, 6);
        
        // runs the game
        for (int i = 0; i < num_turns; ++i) {
            cout << "Turn = " << i << "." << endl;
            cout << game.print_grid() << endl;
            game.execute_turn();
        }
        cout << "Turn = " << num_turns << "." << endl;
        cout << game.print_grid() << endl;
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }


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
        
        int num_turns = 1000;
        int print_frequency = 100;
        Darwin_Game game(72, 72);
        
        // creates the creatures
        vector<Creature> creatures;
        for (int i = 0; i < 10; ++i) {
            creatures.push_back(Creature(&programs, 0, rand() % 4));
            creatures.push_back(Creature(&programs, 1, rand() % 4));
            creatures.push_back(Creature(&programs, 2, rand() % 4));
            creatures.push_back(Creature(&programs, 3, rand() % 4));
        }
        
        // adds creatures to the grid
        for (int i = 0; i < creatures.size(); ++i) {
            bool done = false;
            // loops until can add the creature to the grid
            while(!done) {
                done = game.add_creature(&(creatures[i]), rand() % 72, rand() % 72);
            }
        }
        
        // runs the game
        for (int i = 0; i < num_turns; ++i) {
            game.execute_turn();
            if (i % print_frequency == 0) {
                cout << "Turn = " << i << "." << endl;
                cout << game.print_grid() << endl;
            }
        }
        cout << "Turn = " << num_turns << "." << endl;
        cout << game.print_grid() << endl;
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }


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
            (1:north, 2:east, 3:south, 4:west for this program)
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
        
        int num_turns = 1000;
        int print_frequency = 100;
        Darwin_Game game(72, 72);
        
        // creates the creatures
        vector<Creature> creatures;
        for (int i = 0; i < 10; ++i) {
            creatures.push_back(Creature(&programs, 0, rand() % 4));
            creatures.push_back(Creature(&programs, 1, rand() % 4));
            creatures.push_back(Creature(&programs, 2, rand() % 4));
            creatures.push_back(Creature(&programs, 3, rand() % 4));
            creatures.push_back(Creature(&programs, 4, rand() % 4));
        }
        
        // adds creatures to the grid
        for (int i = 0; i < creatures.size(); ++i) {
            bool done = false;
            // loops until can add the creature to the grid
            while(!done) {
                done = game.add_creature(&(creatures[i]), rand() % 72, rand() % 72);
            }
        }
        
        // runs the game
        for (int i = 0; i < num_turns; ++i) {
            game.execute_turn();
            if (i % print_frequency == 0) {
                cout << "Turn = " << i << "." << endl;
                cout << game.print_grid() << endl;
            }
        }
        cout << "Turn = " << num_turns << "." << endl;
        cout << game.print_grid() << endl;
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }


    return 0;
}
