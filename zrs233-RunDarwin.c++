// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ Board.c++ Creature.c++ Instruction.c++ Species.c++ RunDarwin.c++ -o RunDarwin
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
				Darwin game(8, 8);
				game.addCreature(Species::food(), EAST, 0, 0);
				game.addCreature(Species::hopper(), NORTH, 3, 3);
				game.addCreature(Species::hopper(), EAST, 3, 4);
				game.addCreature(Species::hopper(), SOUTH, 4, 4);
				game.addCreature(Species::hopper(), WEST, 4, 3);
				game.addCreature(Species::food(), NORTH, 7, 7);
				game.printSimulation(5, true, 1);
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
				Darwin game(7, 9);
				game.addCreature(Species::trap(), SOUTH, 0, 0);
				game.addCreature(Species::hopper(), EAST, 3, 2);
				game.addCreature(Species::rover(), NORTH, 5, 4);
				game.addCreature(Species::trap(), WEST, 6, 8);
				game.printSimulation(5, true, 1);
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
				Darwin game(72, 72);
				bool added;
				int pos;
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::food(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::food(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::rover(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::food(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::trap(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::food(), pos, rand() % 4); 
					}
				}
				game.printSimulation(1000, true, 100);
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
				Darwin game(72, 72);
				bool added;
				int pos;
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::food(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::food(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::rover(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::rover(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::trap(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::trap(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % 5184;
					added = game.addCreature(Species::best(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 5184;
						added = game.addCreature(Species::best(), pos, rand() % 4); 
					} 
				}
				game.printSimulation(1000, true, 100);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


		// Darwin random board (0, 100]*(0, 100] with Best

		try {
        cout << "*** Darwin random board (0, 100]*(0, 100] with Best ***" << endl;
        srand(0);
				int rand1 = rand() % 100 + 1;
				int rand2 = rand() % 100 + 1;
				Darwin game(rand1, rand2);
				bool added;
				int pos;
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % rand1 * rand2;
					added = game.addCreature(Species::food(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % rand1 * rand2;
						added = game.addCreature(Species::food(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % rand1 * rand2;
					added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % rand1 * rand2;
						added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % rand1 * rand2;
					added = game.addCreature(Species::rover(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % rand1 * rand2;
						added = game.addCreature(Species::rover(), pos, rand() % 4); 
					} 
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % rand1 * rand2;
					added = game.addCreature(Species::trap(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % rand1 * rand2;
						added = game.addCreature(Species::trap(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 10; ++i) {
					added = false;
					pos = rand() % rand1 * rand2;
					added = game.addCreature(Species::best(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % rand1 * rand2;
						added = game.addCreature(Species::best(), pos, rand() % 4); 
					}
				}
				game.printSimulation(1000, true, 100);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

		// ------------
    // darwin 7x7
    // with best
    // ------------

    try {
        cout << "*** Darwin 7x7 with Best ***" << endl;
        srand(0);
				Darwin game(7, 7);
				bool added;
				int pos;
				for(int i = 0; i < 2; ++i) {
					added = false;
					pos = rand() % 49;
					added = game.addCreature(Species::food(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 49;
						added = game.addCreature(Species::food(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					pos = rand() % 49;
					added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 49;
						added = game.addCreature(Species::hopper(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					pos = rand() % 49;
					added = game.addCreature(Species::rover(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 49;
						added = game.addCreature(Species::rover(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					pos = rand() % 49;
					added = game.addCreature(Species::trap(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 49;
						added = game.addCreature(Species::trap(), pos, rand() % 4); 
					}
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					pos = rand() % 49;
					added = game.addCreature(Species::best(), pos, rand() % 4); 
					while(!added) {
						pos = rand() % 49;
						added = game.addCreature(Species::best(), pos, rand() % 4); 
					}
				}
				game.printSimulation(5, true, 1);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

		// ------------
    // darwin 8x8
    // with best facing SOUTH
    // ------------

    try {
        cout << "*** Darwin 8x8 with Best all facing SOUTH ***" << endl;
        srand(0);
				Darwin game(8, 8);
				bool added;
				for(int i = 0; i < 2; ++i) {
					added = false;
					added = game.addCreature(Species::food(), rand() % 64, SOUTH); 
					while(!added)
						added = game.addCreature(Species::food(), rand() % 64, SOUTH); 
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					added = game.addCreature(Species::hopper(), rand() % 64, SOUTH); 
					while(!added)
						added = game.addCreature(Species::hopper(), rand() % 64, SOUTH); 
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					added = game.addCreature(Species::rover(), rand() % 64, SOUTH); 
					while(!added)
						added = game.addCreature(Species::rover(), rand() % 64, SOUTH); 
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					added = game.addCreature(Species::trap(), rand() % 64, SOUTH); 
					while(!added)
						added = game.addCreature(Species::trap(), rand() % 64, SOUTH); 
				}
				for(int i = 0; i < 2; ++i) {
					added = false;
					added = game.addCreature(Species::best(), rand() % 64, SOUTH); 
					while(!added)
						added = game.addCreature(Species::best(), rand() % 64, SOUTH); 
				}
				game.printSimulation(10, true, 1);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

		// ------------
    // darwin 1x1
    // with best
    // ------------

    try {
        cout << "*** Darwin 1x1 with Best ***" << endl;
        srand(0);
				Darwin game(1, 1);
				game.addCreature(Species::best(), 0, rand() % 4); 
				game.printSimulation(2, true, 1);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


		// darwin 2x2 with best

		try {
        cout << "*** Darwin 2x2 with Best ***" << endl;
        srand(0);
				Darwin game(2, 2);
				game.addCreature(Species::best(),  0, rand() % 4); 
				game.addCreature(Species::best(),  1, rand() % 4);
				game.addCreature(Species::rover(), 2, rand() % 4); 
				game.addCreature(Species::rover(), 3, rand() % 4);   
				game.printSimulation(5, true, 1);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

		// ----------
    // darwin 100x100 with no one
    // ----------

    try {
        cout << "*** Darwin 100x100 ***" << endl;
        srand(0);
				Darwin game(100, 100);
				game.printSimulation(1, true, 1);
		}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

