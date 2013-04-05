// -----------------------------
// Ben Bowley-Bryant
// benbb
// Paul Carroll
// pvc95
// -----------------------------

/*
To run the program:
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ RunDarwin.c++ -o RunDarwin.c++.app
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
    // 1. darwin-small
    // ----------

    try {
        cout << "*** 1. Darwin-small ***" << endl;

		int X = rand() % 10 + 1;
		int Y = rand() % 10 + 1;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 10; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 10 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 2. darwin-small
    // ----------

    try {
        cout << "*** 2. Darwin-small ***" << endl;

		int X = rand() % 10 + 1;
		int Y = rand() % 10 + 1;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 10; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 10 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 3. darwin-small
    // ----------

    try {
        cout << "*** 3. Darwin-small ***" << endl;

		int X = rand() % 10 + 1;
		int Y = rand() % 10 + 1;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 10; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 10 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 4. darwin-small
    // ----------

    try {
        cout << "*** 4. Darwin-small ***" << endl;

		int X = rand() % 10 + 1;
		int Y = rand() % 10 + 1;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 10; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 10 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 5. darwin-small
    // ----------

    try {
        cout << "*** 5. Darwin-small ***" << endl;

		int X = rand() % 10 + 1;
		int Y = rand() % 10 + 1;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 10; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 10 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // 6. darwin-big
    // ----------

    try {
        cout << "*** 6. Darwin-big ***" << endl;

		int X = rand() % 50 + 50;
		int Y = rand() % 50 + 50;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 1000; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 1000 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 7. darwin-big
    // ----------

    try {
        cout << "*** 7. Darwin-big ***" << endl;

		int X = rand() % 50 + 50;
		int Y = rand() % 50 + 50;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 1000; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 1000 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 8. darwin-big
    // ----------

    try {
        cout << "*** 8. Darwin-big ***" << endl;

		int X = rand() % 50 + 50;
		int Y = rand() % 50 + 50;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 1000; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 1000 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 9. darwin-big
    // ----------

    try {
        cout << "*** 9. Darwin-big ***" << endl;

		int X = rand() % 50 + 50;
		int Y = rand() % 50 + 50;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 1000; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 1000 << "." << endl;
		g.printBoard(cout);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 10. darwin-big
    // ----------

    try {
        cout << "*** 10. Darwin-big ***" << endl;

		int X = rand() % 50 + 50;
		int Y = rand() % 50 + 50;
		Game g(X,Y);

		int numCreatures = rand() % X;

		for(int i = 0; i < numCreatures; i++){
			g.add_creature(rand() % 5, rand() % 4, rand() % X, rand() % Y);
		}

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

		for(int i = 1; i <= 1000; i++){
			g.start();
			g.run_turn();
		}
		cout << "Turn = " << 1000 << "." << endl;
		g.printBoard(cout);
		
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
		Game g(8,8);
		g.add_creature(0, 2, 0, 0);
		g.add_creature(1, 1, 3, 3);
		g.add_creature(1, 2, 3, 4);
		g.add_creature(1, 3, 4, 4);
		g.add_creature(1, 0, 4, 3);
		g.add_creature(0, 1, 7, 7);

		cout << "Turn = 0" << "." << endl;
		g.printBoard(cout);

	for(int i = 1; i <= 5; i++){
		g.start();
		g.run_turn();
		cout << "Turn = " << i << "." << endl;
		g.printBoard(cout);
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
		Game g2(7, 9);
		g2.add_creature(3, 3, 0, 0);
		g2.add_creature(1, 2, 3, 2);
		g2.add_creature(2, 1, 5, 4);
		g2.add_creature(3, 0, 6, 8);
		
		cout << "Turn = 0" << "." << endl;
		g2.printBoard(cout);

	for(int i = 1; i <= 5; i++){
		g2.start();
		g2.run_turn();
		cout << "Turn = " << i << "." << endl;
		g2.printBoard(cout);

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
		Game g3(72, 72);
		for(int i = 0; i < 40; ++i){
			int pos = rand() % 5184;
			int x = pos / 72;
			int y = pos % 72;
			g3.add_creature(i / 10, rand() % 4, x, y);
		}
		cout << "Turn = 0" << "." << endl;
		g3.printBoard(cout);

			for(int i = 1; i <= 1000; i++){
				g3.start();
				g3.run_turn();
				if(i % 100 == 0){
					cout << "Turn = " << i << endl;
					g3.printBoard(cout);
				}
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
		Game g4(72, 72);
		for(int i = 0; i < 50; ++i){
			int pos = rand() % 5184;
			int x = pos / 72;
			int y = pos % 72;
			g4.add_creature(i / 10, rand() % 4, x, y);
		}
		cout << "Turn = 0" << endl;
		g4.printBoard(cout);

			for(int i = 1; i <= 1000; i++){
				g4.start();
				g4.run_turn();
				if(i % 100 == 0){
					cout << "Turn = " << i << endl;
					g4.printBoard(cout);
				}
			}
			
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
