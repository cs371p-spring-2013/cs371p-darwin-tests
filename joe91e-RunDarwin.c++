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
#include <string>
#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include "Darwin.c++"


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
	


    // -----------
    // darwin 10x1
    // -----------

    try {
        cout << "*** Darwin 10x1 ***" << endl;
        srand(0);
        /*
        10x1 Darwin
        Rover, facing north, at (5, 0)
        Simulate 10 moves.
        Print every grid.
        */

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "r";
        listOfCreatureInfo[0][1] = "5";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "n";


        
        Board b(10, 1, 10, listOfCreatureInfo, false);
        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------
    // darwin 1x10
    // -----------

    try {
        cout << "*** Darwin 1x10 ***" << endl;
        srand(0);
        /*
        10x1 Darwin
        Rover, facing north, at (0, 5)
        Simulate 10 moves.
        Print every grid.
        */

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(1);
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "r";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "5";
        listOfCreatureInfo[0][3] = "n";


        
        Board b(1, 10, 10, listOfCreatureInfo, false);
        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------
    // darwin 2x2
    // -----------

    try {
        cout << "*** Darwin 2x2 ***" << endl;
        srand(0);
        /*
        2x2 Darwin
        Rover, facing north, at (0, 0)
        Rover, facing south, at (0, 1)
        Rover, facing east, at (1, 0)
        Rover, facing west, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(4);
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "r";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "n";
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "r";
        listOfCreatureInfo[1][1] = "0";
        listOfCreatureInfo[1][2] = "1";
        listOfCreatureInfo[1][3] = "s";
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "r";
        listOfCreatureInfo[2][1] = "1";
        listOfCreatureInfo[2][2] = "0";
        listOfCreatureInfo[2][3] = "e";
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "r";
        listOfCreatureInfo[3][1] = "1";
        listOfCreatureInfo[3][2] = "1";
        listOfCreatureInfo[3][3] = "w";


        
        Board b(2, 2, 5, listOfCreatureInfo, false);
        b.executeRounds(std::cout);
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
        Food, facing east, at (0, 0)
        Rover, facing north, at (1, 1)
        Simulate 3 moves.
        Print every grid.
        */ 

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "e";
		//Rover, facing north, at (1, 1)
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "r";
        listOfCreatureInfo[1][1] = "1";
        listOfCreatureInfo[1][2] = "1";
        listOfCreatureInfo[1][3] = "n";

        
        Board b(8, 8, 3, listOfCreatureInfo, false);

        b.executeRounds(std::cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 6x6
    // ----------

    try {
        cout << "*** Darwin 6x6 ***" << endl;
        srand(0);
        /*
        6x6 Darwin
        Food, facing east, at (0, 0)
        Rover, facing north, at (1, 1)
        Simulate 5 moves.
        Print every grid.
        */ 

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(2);
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "h";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "e";
		//Rover, facing north, at (1, 1)
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "r";
        listOfCreatureInfo[1][1] = "1";
        listOfCreatureInfo[1][2] = "1";
        listOfCreatureInfo[1][3] = "n";

        
        Board b(6, 6, 5, listOfCreatureInfo, false);

        b.executeRounds(std::cout);
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
        4x4 Darwin
        Trap, facing east, at (0, 0)
        Trap, facing east, at (1, 0)
        Trap, facing south, at (0, 1)
        Rover, facing North at (1, 1)
        Simulate 3 moves.
        Print every grid.
        */ 

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(4);
		//Trap,   facing east,  at (0, 0)
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "e";
		//Trap, facing east, at (1, 0)
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "t";
        listOfCreatureInfo[1][1] = "1";
        listOfCreatureInfo[1][2] = "0";
        listOfCreatureInfo[1][3] = "e";
		//Trap, facing south, at (0, 1)
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "t";
        listOfCreatureInfo[2][1] = "0";
        listOfCreatureInfo[2][2] = "1";
        listOfCreatureInfo[2][3] = "s";
		//Rover, facing North, at (1, 1)
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "r";
        listOfCreatureInfo[3][1] = "1";
        listOfCreatureInfo[3][2] = "1";
        listOfCreatureInfo[3][3] = "n";

        
        Board b(8, 8, 3, listOfCreatureInfo, false);

        b.executeRounds(std::cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 6x3
    // ----------

    try {
        cout << "*** Darwin 6x3 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(3);
		//Trap
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "s";
		//Rover
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "r";
        listOfCreatureInfo[1][1] = "0";
        listOfCreatureInfo[1][2] = "2";
        listOfCreatureInfo[1][3] = "n";
		//Hopper
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "h";
        listOfCreatureInfo[2][1] = "4";
        listOfCreatureInfo[2][2] = "1";
        listOfCreatureInfo[2][3] = "n";
        
        Board b(6, 3, 5, listOfCreatureInfo, false);

        b.executeRounds(std::cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 5x5
    // ----------

    try {
        cout << "*** Darwin 5x5 ***" << endl;

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(6);
		//trap,   facing east,  at (0, 0)
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "e";
		//trap, facing north, at (0, 4)
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "t";
        listOfCreatureInfo[1][1] = "0";
        listOfCreatureInfo[1][2] = "4";
        listOfCreatureInfo[1][3] = "s";
		//Hopper, facing east,  at (1, 1)
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "h";
        listOfCreatureInfo[2][1] = "1";
        listOfCreatureInfo[2][2] = "1";
        listOfCreatureInfo[2][3] = "e";
		//Hopper, facing south, at (3, 3)
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "h";
        listOfCreatureInfo[3][1] = "3";
        listOfCreatureInfo[3][2] = "3";
        listOfCreatureInfo[3][3] = "s";
		//trap, facing west,  at (4, 0)
        listOfCreatureInfo[4].resize(4);
        listOfCreatureInfo[4][0] = "t";
        listOfCreatureInfo[4][1] = "4";
        listOfCreatureInfo[4][2] = "0";
        listOfCreatureInfo[4][3] = "w";
		//trap,   facing north, at (4, 4)
        listOfCreatureInfo[5].resize(4);
        listOfCreatureInfo[5][0] = "t";
        listOfCreatureInfo[5][1] = "4";
        listOfCreatureInfo[5][2] = "4";
        listOfCreatureInfo[5][3] = "n";
        
        Board b(5, 5, 5, listOfCreatureInfo, false);

        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 4x4
    // ----------

    try {
        cout << "*** Darwin 4x4 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(4);
		//Trap
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "e";
		//Rover
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "r";
        listOfCreatureInfo[1][1] = "0";
        listOfCreatureInfo[1][2] = "3";
        listOfCreatureInfo[1][3] = "n";
		//Hopper
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "h";
        listOfCreatureInfo[2][1] = "1";
        listOfCreatureInfo[2][2] = "1";
        listOfCreatureInfo[2][3] = "e";
		//Food
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "f";
        listOfCreatureInfo[3][1] = "3";
        listOfCreatureInfo[3][2] = "3";
        listOfCreatureInfo[3][3] = "s";
        
        Board b(4, 4, 5, listOfCreatureInfo, false);

        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 15x15
    // ----------

    try {
        cout << "*** Darwin 15x15 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(6);
		//trap,   
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "3";
        listOfCreatureInfo[0][2] = "2";
        listOfCreatureInfo[0][3] = "e";
		//best
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "b";
        listOfCreatureInfo[1][1] = "5";
        listOfCreatureInfo[1][2] = "0";
        listOfCreatureInfo[1][3] = "s";
		//Hopper, facing east,  at (1, 1)
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "h";
        listOfCreatureInfo[2][1] = "1";
        listOfCreatureInfo[2][2] = "1";
        listOfCreatureInfo[2][3] = "e";
		//Hopper, facing south, at (3, 3)
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "h";
        listOfCreatureInfo[3][1] = "3";
        listOfCreatureInfo[3][2] = "6";
        listOfCreatureInfo[3][3] = "s";
		//food, facing west,  at (4, 0)
        listOfCreatureInfo[4].resize(4);
        listOfCreatureInfo[4][0] = "f";
        listOfCreatureInfo[4][1] = "4";
        listOfCreatureInfo[4][2] = "0";
        listOfCreatureInfo[4][3] = "w";
		//rover,   facing north, at (4, 4)
        listOfCreatureInfo[5].resize(4);
        listOfCreatureInfo[5][0] = "r";
        listOfCreatureInfo[5][1] = "4";
        listOfCreatureInfo[5][2] = "4";
        listOfCreatureInfo[5][3] = "n";
        
        Board b(15, 15, 10, listOfCreatureInfo, false);

        b.executeRounds(std::cout);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // darwin 10x8
    // ----------

    try {
        cout << "*** Darwin 10x8 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(7);
		//trap
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "s";
		//rover
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "t";
        listOfCreatureInfo[1][1] = "0";
        listOfCreatureInfo[1][2] = "4";
        listOfCreatureInfo[1][3] = "s";
		//best
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "b";
        listOfCreatureInfo[2][1] = "1";
        listOfCreatureInfo[2][2] = "1";
        listOfCreatureInfo[2][3] = "e";
		//rover
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "r";
        listOfCreatureInfo[3][1] = "3";
        listOfCreatureInfo[3][2] = "7";
        listOfCreatureInfo[3][3] = "s";
		//hopper
        listOfCreatureInfo[4].resize(4);
        listOfCreatureInfo[4][0] = "h";
        listOfCreatureInfo[4][1] = "9";
        listOfCreatureInfo[4][2] = "4";
        listOfCreatureInfo[4][3] = "w";
		//trap
        listOfCreatureInfo[5].resize(4);
        listOfCreatureInfo[5][0] = "t";
        listOfCreatureInfo[5][1] = "4";
        listOfCreatureInfo[5][2] = "4";
        listOfCreatureInfo[5][3] = "n";
		//rover
        listOfCreatureInfo[6].resize(4);
        listOfCreatureInfo[6][0] = "r";
        listOfCreatureInfo[6][1] = "8";
        listOfCreatureInfo[6][2] = "2";
        listOfCreatureInfo[6][3] = "n";
        
        Board b(10, 8, 20, listOfCreatureInfo, false);

        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // darwin 9x9
    // ----------

    try {
        cout << "*** Darwin 9x9 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(4);
		//trap
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "2";
        listOfCreatureInfo[0][2] = "3";
        listOfCreatureInfo[0][3] = "n";
		//hopper
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";
        listOfCreatureInfo[1][1] = "1";
        listOfCreatureInfo[1][2] = "4";
        listOfCreatureInfo[1][3] = "w";
		//food
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "f";
        listOfCreatureInfo[2][1] = "3";
        listOfCreatureInfo[2][2] = "3";
        listOfCreatureInfo[2][3] = "e";
		//trap
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "t";
        listOfCreatureInfo[3][1] = "5";
        listOfCreatureInfo[3][2] = "5";
        listOfCreatureInfo[3][3] = "s";

        Board b(9, 9, 3, listOfCreatureInfo, false);

        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}




    // ----------
    // darwin 11x11 
    // ----------

    try {
        cout << "*** Darwin 11x11 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(5);
		//rover
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "r";
        listOfCreatureInfo[0][1] = "6";
        listOfCreatureInfo[0][2] = "7";
        listOfCreatureInfo[0][3] = "n";
		//food
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "f";
        listOfCreatureInfo[1][1] = "1";
        listOfCreatureInfo[1][2] = "4";
        listOfCreatureInfo[1][3] = "w";
		//hopper
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "h";
        listOfCreatureInfo[2][1] = "7";
        listOfCreatureInfo[2][2] = "7";
        listOfCreatureInfo[2][3] = "s";
		//trap
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "t";
        listOfCreatureInfo[3][1] = "5";
        listOfCreatureInfo[3][2] = "5";
        listOfCreatureInfo[3][3] = "s";
		//food
        listOfCreatureInfo[4].resize(4);
        listOfCreatureInfo[4][0] = "f";
        listOfCreatureInfo[4][1] = "3";
        listOfCreatureInfo[4][2] = "4";
        listOfCreatureInfo[4][3] = "n";

        Board b(11, 11, 10, listOfCreatureInfo, false);

        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// ----------
    // darwin 3x3 
    // ----------

    try {
        cout << "*** Darwin 3x3 ***" << endl;
		srand(0);
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(5);
		//rover
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "n";
		//food
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "t";
        listOfCreatureInfo[1][1] = "0";
        listOfCreatureInfo[1][2] = "2";
        listOfCreatureInfo[1][3] = "s";
		//hopper
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "t";
        listOfCreatureInfo[2][1] = "2";
        listOfCreatureInfo[2][2] = "0";
        listOfCreatureInfo[2][3] = "e";
		//trap
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "t";
        listOfCreatureInfo[3][1] = "2";
        listOfCreatureInfo[3][2] = "2";
        listOfCreatureInfo[3][3] = "w";
		//food
        listOfCreatureInfo[4].resize(4);
        listOfCreatureInfo[4][0] = "r";
        listOfCreatureInfo[4][1] = "1";
        listOfCreatureInfo[4][2] = "1";
        listOfCreatureInfo[4][3] = "w";

        Board b(3, 3, 5, listOfCreatureInfo, false);
        b.executeRounds(std::cout);
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

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(6);
		//Food,   facing east,  at (0, 0)
        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "f";
        listOfCreatureInfo[0][1] = "0";
        listOfCreatureInfo[0][2] = "0";
        listOfCreatureInfo[0][3] = "e";
		//Hopper, facing north, at (3, 3)
        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";
        listOfCreatureInfo[1][1] = "3";
        listOfCreatureInfo[1][2] = "3";
        listOfCreatureInfo[1][3] = "n";
		//Hopper, facing east,  at (3, 4)
        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "h";
        listOfCreatureInfo[2][1] = "3";
        listOfCreatureInfo[2][2] = "4";
        listOfCreatureInfo[2][3] = "e";
		//Hopper, facing south, at (4, 4)
        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "h";
        listOfCreatureInfo[3][1] = "4";
        listOfCreatureInfo[3][2] = "4";
        listOfCreatureInfo[3][3] = "s";
		//Hopper, facing west,  at (4, 3)
        listOfCreatureInfo[4].resize(4);
        listOfCreatureInfo[4][0] = "h";
        listOfCreatureInfo[4][1] = "4";
        listOfCreatureInfo[4][2] = "3";
        listOfCreatureInfo[4][3] = "w";
		//Food,   facing north, at (7, 7)
        listOfCreatureInfo[5].resize(4);
        listOfCreatureInfo[5][0] = "f";
        listOfCreatureInfo[5][1] = "7";
        listOfCreatureInfo[5][2] = "7";
        listOfCreatureInfo[5][3] = "n";
        
        Board b(8, 8, 5, listOfCreatureInfo, false);
        b.executeRounds(std::cout);
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

        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(4);

        listOfCreatureInfo[0].resize(4);
        listOfCreatureInfo[0][0] = "t";//species
        listOfCreatureInfo[0][1] = "0";//row
        listOfCreatureInfo[0][2] = "0";//column
        listOfCreatureInfo[0][3] = "s";//direction

        listOfCreatureInfo[1].resize(4);
        listOfCreatureInfo[1][0] = "h";
        listOfCreatureInfo[1][1] = "3";
        listOfCreatureInfo[1][2] = "2";
        listOfCreatureInfo[1][3] = "e";

        listOfCreatureInfo[2].resize(4);
        listOfCreatureInfo[2][0] = "r";
        listOfCreatureInfo[2][1] = "5";
        listOfCreatureInfo[2][2] = "4";
        listOfCreatureInfo[2][3] = "n";

        listOfCreatureInfo[3].resize(4);
        listOfCreatureInfo[3][0] = "t";
        listOfCreatureInfo[3][1] = "6";
        listOfCreatureInfo[3][2] = "8";
        listOfCreatureInfo[3][3] = "w";
        
        Board b(7, 9, 5, listOfCreatureInfo, false);
        b.executeRounds(std::cout);
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
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(40);
		int cnt = 0;

		//generate food randomly
		while(cnt < 10)
		{
		    listOfCreatureInfo[cnt].resize(4);
		    listOfCreatureInfo[cnt][0] = "f";//species
		    listOfCreatureInfo[cnt][1] = "0";//row
		    listOfCreatureInfo[cnt][2] = "0";//column
		    listOfCreatureInfo[cnt][3] = "0";//direction
			cnt++;
		}   
		//generate hopper randomly
		while(cnt < 20)
		{
		    listOfCreatureInfo[cnt].resize(4);
		    listOfCreatureInfo[cnt][0] = "h";//species
		    listOfCreatureInfo[cnt][1] = "0";//row
		    listOfCreatureInfo[cnt][2] = "0";//column
		    listOfCreatureInfo[cnt][3] = "0";//direction
			cnt++;
		}
		//generate rover randomly
		while(cnt < 30)
		{
		    listOfCreatureInfo[cnt].resize(4);
		    listOfCreatureInfo[cnt][0] = "r";//species
		    listOfCreatureInfo[cnt][1] = "0";//row
		    listOfCreatureInfo[cnt][2] = "0";//column
		    listOfCreatureInfo[cnt][3] = "0";//direction
			cnt++;
		}
		//generate trap randomly
		while(cnt < 40)
		{
		    listOfCreatureInfo[cnt].resize(4);
		    listOfCreatureInfo[cnt][0] = "t";//species
		    listOfCreatureInfo[cnt][1] = "0";//row
		    listOfCreatureInfo[cnt][2] = "0";//column
		    listOfCreatureInfo[cnt][3] = "0";//direction
			cnt++;
		}

        Board b(72, 72, 1000, listOfCreatureInfo, true);
        b.executeRounds(std::cout);
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
        std::vector<std::vector<string> > listOfCreatureInfo;
        listOfCreatureInfo.resize(50);
                int cnt = 0;

                //generate food randomly
                while(cnt < 10)
                {
                    listOfCreatureInfo[cnt].resize(4);
                    listOfCreatureInfo[cnt][0] = "f";//species
                    listOfCreatureInfo[cnt][1] = "0";//row
                    listOfCreatureInfo[cnt][2] = "0";//column
                    listOfCreatureInfo[cnt][3] = "0";//direction
                        cnt++;
                }
                //generate hopper randomly
                while(cnt < 20)
                {
                    listOfCreatureInfo[cnt].resize(4);
                    listOfCreatureInfo[cnt][0] = "h";//species
                    listOfCreatureInfo[cnt][1] = "0";//row
                    listOfCreatureInfo[cnt][2] = "0";//column
                    listOfCreatureInfo[cnt][3] = "0";//direction
                        cnt++;
                }
                //generate rover randomly
                while(cnt < 30)
                {
                    listOfCreatureInfo[cnt].resize(4);
                    listOfCreatureInfo[cnt][0] = "r";//species
                    listOfCreatureInfo[cnt][1] = "0";//row
                    listOfCreatureInfo[cnt][2] = "0";//column
                    listOfCreatureInfo[cnt][3] = "0";//direction
                        cnt++;
                }
                //generate trap randomly
                while(cnt < 40)
                {
                    listOfCreatureInfo[cnt].resize(4);
                    listOfCreatureInfo[cnt][0] = "t";//species
                    listOfCreatureInfo[cnt][1] = "0";//row
                    listOfCreatureInfo[cnt][2] = "0";//column
                    listOfCreatureInfo[cnt][3] = "0";//direction
                        cnt++;
                }
                //generate trap randomly
                while(cnt < 50)
                {
                    listOfCreatureInfo[cnt].resize(4);
                    listOfCreatureInfo[cnt][0] = "b";//species
                    listOfCreatureInfo[cnt][1] = "0";//row
                    listOfCreatureInfo[cnt][2] = "0";//column
                    listOfCreatureInfo[cnt][3] = "0";//direction
                        cnt++;
                }

        Board b(72, 72, 1000, listOfCreatureInfo, true);

        b.executeRounds(std::cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
