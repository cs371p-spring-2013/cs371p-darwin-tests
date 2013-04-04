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
        Game x (8, 8, 6);
        x.add_creature (food, E, 0, 0);
        x.add_creature (hopper, N, 3, 3);
        x.add_creature (hopper, E, 3, 4);
        x.add_creature (hopper, S, 4, 4);
        x.add_creature (hopper, W, 4, 3);
        x.add_creature (food, N, 7, 7);
        x.print_board (cout);
        for (int i = 0; i < 5; ++i) {
            x.take_a_turn ();
            x.print_board (cout);
        }
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
        Game x (7, 9, 4);
        x.add_creature (trap, S, 0, 0);
        x.add_creature (hopper, E, 3, 2);
        x.add_creature (rover, N, 5, 4);
        x.add_creature (trap, W, 6, 8);
        x.print_board (cout);
        for (int i = 0; i < 5; ++i) {
            x.take_a_turn ();
            x.print_board (cout);
        }
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
        Game x (72, 72, 40);
        int temp, row, col, dir;
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (food, W, row, col);
                    break;
                case 1:
                    x.add_creature (food, N, row, col);
                    break;
                case 2:
                    x.add_creature (food, E, row, col);
                    break;
                case 3:
                    x.add_creature (food, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (hopper, W, row, col);
                    break;
                case 1:
                    x.add_creature (hopper, N, row, col);
                    break;
                case 2:
                    x.add_creature (hopper, E, row, col);
                    break;
                case 3:
                    x.add_creature (hopper, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (rover, W, row, col);
                    break;
                case 1:
                    x.add_creature (rover, N, row, col);
                    break;
                case 2:
                    x.add_creature (rover, E, row, col);
                    break;
                case 3:
                    x.add_creature (rover, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (trap, W, row, col);
                    break;
                case 1:
                    x.add_creature (trap, N, row, col);
                    break;
                case 2:
                    x.add_creature (trap, E, row, col);
                    break;
                case 3:
                    x.add_creature (trap, S, row, col);
                    break;
            }
        }
        x.print_board (cout);
        for (int i = 0; i < 1000; ++i) {
            x.take_a_turn ();
            if (i%100 == 99)
                x.print_board (cout);
        }
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
        Game x (72, 72, 50);
        int temp, row, col, dir;
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (food, W, row, col);
                    break;
                case 1:
                    x.add_creature (food, N, row, col);
                    break;
                case 2:
                    x.add_creature (food, E, row, col);
                    break;
                case 3:
                    x.add_creature (food, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (hopper, W, row, col);
                    break;
                case 1:
                    x.add_creature (hopper, N, row, col);
                    break;
                case 2:
                    x.add_creature (hopper, E, row, col);
                    break;
                case 3:
                    x.add_creature (hopper, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (rover, W, row, col);
                    break;
                case 1:
                    x.add_creature (rover, N, row, col);
                    break;
                case 2:
                    x.add_creature (rover, E, row, col);
                    break;
                case 3:
                    x.add_creature (rover, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (trap, W, row, col);
                    break;
                case 1:
                    x.add_creature (trap, N, row, col);
                    break;
                case 2:
                    x.add_creature (trap, E, row, col);
                    break;
                case 3:
                    x.add_creature (trap, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 5184;
            row = temp/72;
            col = temp%72;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (best, W, row, col);
                    break;
                case 1:
                    x.add_creature (best, N, row, col);
                    break;
                case 2:
                    x.add_creature (best, E, row, col);
                    break;
                case 3:
                    x.add_creature (best, S, row, col);
                    break;
            }
        }
        x.print_board (cout);
        for (int i = 0; i < 1000; ++i) {
            x.take_a_turn ();
            if (i%100 == 99)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // test_1 [1x1]
    // ------------

    try {
        cout << "*** Darwin 1x1 ***" << endl;
        srand(0);
        Game x (1, 1, 1);
        x.add_creature (trap, E, 0, 0);
        x.print_board (cout);
        for (int i = 0; i < 5; ++i) {
            x.take_a_turn ();
            x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // test_2 [1x5]
    // ------------

    try {
        cout << "*** Darwin 1x5 ***" << endl;
        srand(0);
        Game x (1, 5, 1);
        x.add_creature (hopper, E, 0, 0);
        x.print_board (cout);
        for (int i = 0; i < 5; ++i) {
            x.take_a_turn ();
            x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------
    // test_3 [5x5]
    // ------------

    try {
        cout << "*** Darwin 5x5 ***" << endl;
        srand(0);
        Game x (5, 5, 5);
        x.add_creature (best, S, 0, 0);
        x.add_creature (food, S, 0, 1);
        x.add_creature (trap, S, 0, 2);
        x.add_creature (hopper, S, 0, 3);
        x.add_creature (rover, S, 0, 4);
        x.print_board (cout);
        for (int i = 0; i < 100; ++i) {
            x.take_a_turn ();
            if (i%10 == 9)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // test_4 [10x10]
    // --------------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        Game x (10, 10, 10);
        int temp, row, col, dir;
        for (int i = 0; i < 10; ++i) {
            temp = rand () % 100;
            row = temp/10;
            col = temp%10;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (rover, W, row, col);
                    break;
                case 1:
                    x.add_creature (rover, N, row, col);
                    break;
                case 2:
                    x.add_creature (rover, E, row, col);
                    break;
                case 3:
                    x.add_creature (rover, S, row, col);
                    break;
            }
        }
        x.print_board (cout);
        for (int i = 0; i < 100; ++i) {
            x.take_a_turn ();
            if (i%10 == 9)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // test_5 [10x10]
    // --------------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        Game x (10, 10, 100);
        int dir;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 10; ++ j) {
                dir = rand () % 4;
                switch (dir) {
                    case 0:
                        x.add_creature (rover, W, j, i);
                        break;
                    case 1:
                        x.add_creature (rover, N, j, i);
                        break;
                    case 2:
                        x.add_creature (rover, E, j, i);
                        break;
                    case 3:
                        x.add_creature (rover, S, j, i);
                        break;
                }
            }
        }
        for (int i = 5; i < 10; ++i) {
            for (int j = 0; j < 10; ++ j) {
                dir = rand () % 4;
                switch (dir) {
                    case 0:
                        x.add_creature (trap, W, j, i);
                        break;
                    case 1:
                        x.add_creature (trap, N, j, i);
                        break;
                    case 2:
                        x.add_creature (trap, E, j, i);
                        break;
                    case 3:
                        x.add_creature (trap, S, j, i);
                        break;
                }
            }
        }
        x.print_board (cout);
        for (int i = 0; i < 100; ++i) {
            x.take_a_turn ();
            if (i%10 == 9)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}    

    // --------------
    // test_6 [10x10]
    // --------------

    try {
        cout << "*** Darwin 10x10 ***" << endl;
        srand(0);
        Game x (10, 10, 100);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i == 5 && j == 5)
                    x.add_creature (best, N, i, j);
                else
                    x.add_creature (food, N, i, j);
            }
        }
        x.print_board (cout);
        for (int i = 0; i < 30; ++i) {
            x.take_a_turn ();
            if (i%3 == 2)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // test_7 [25x25]
    // --------------
        
    try {
        cout << "*** Darwin 25x25 ***" << endl;
        srand(0);
        Game x (25, 25, 50);
        for (int i = 0; i < 25; ++i)
            x.add_creature (best, W, i, 24);
        for (int i = 0; i < 25; ++i)
            x.add_creature (rover, E, i, 0);
        x.print_board (cout);
        for (int i = 0; i < 100; ++i) {
            x.take_a_turn ();
            if (i%10 == 9)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // test_8 [25x25]
    // --------------

    try {
        cout << "*** Darwin 25x25 ***" << endl;
        srand(0);
        Game x (25, 25, 50);
        for (int i = 0; i < 25; ++i)
            x.add_creature (best, E, i, 24);
        for (int i = 0; i < 25; ++i)
            x.add_creature (rover, W, i, 0);
        x.print_board (cout);
        for (int i = 0; i < 100; ++i) {
            x.take_a_turn ();
            if (i%10 == 9)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // test_9 [50x50]
    // --------------

    try {
        cout << "*** Darwin 50x50 ***" << endl;
        srand(0);
        Game x (50, 50, 30);
        int temp, row, col, dir;
        for (int i = 0; i < 25; ++i) {
            temp = rand () % 2500;
            row = temp / 50;
            col = temp % 50;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (rover, W, row, col);
                    break;
                case 1:
                    x.add_creature (rover, N, row, col);
                    break;
                case 2:
                    x.add_creature (rover, E, row, col);
                    break;
                case 3:
                    x.add_creature (rover, S, row, col);
                    break;
            }
        }
        temp = rand () % 2500;
        row = temp / 50;
        col = temp % 50;
        dir = rand () % 4;
        switch (dir) {
            case 0:
                    x.add_creature (best, W, row, col);
                    break;
                case 1:
                    x.add_creature (best, N, row, col);
                    break;
                case 2:
                    x.add_creature (best, E, row, col);
                    break;
                case 3:
                    x.add_creature (best, S, row, col);
                    break;
        }
        x.print_board (cout);
        for (int i = 0; i < 1000; ++i) {
            x.take_a_turn ();
            if (i%100 == 99)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // test_10 [100x100]
    // -----------------
    
    try {
        cout << "*** Darwin 100x100 ***" << endl;
        srand(0);
        Game x (100, 100, 1000);
        int temp, row, col, dir;
        for (int i = 0; i < 500; ++i) {
            temp = rand () % 10000;
            row = temp/100;
            col = temp%100;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (rover, W, row, col);
                    break;
                case 1:
                    x.add_creature (rover, N, row, col);
                    break;
                case 2:
                    x.add_creature (rover, E, row, col);
                    break;
                case 3:
                    x.add_creature (rover, S, row, col);
                    break;
            }
        }
        for (int i = 0; i < 500; ++i) {
            temp = rand () % 10000;
            row = temp/100;
            col = temp%100;
            dir = rand () % 4;
            switch (dir) {
                case 0:
                    x.add_creature (best, W, row, col);
                    break;
                case 1:
                    x.add_creature (best, N, row, col);
                    break;
                case 2:
                    x.add_creature (best, E, row, col);
                    break;
                case 3:
                    x.add_creature (best, S, row, col);
                    break;
            }
        }
        x.print_board (cout);
        for (int i = 0; i < 5000; ++i) {
            x.take_a_turn ();
            if (i%500 == 499)
                x.print_board (cout);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}