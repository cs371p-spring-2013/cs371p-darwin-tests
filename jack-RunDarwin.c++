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
#include <cstring>

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


  vector<string> food(0);
  food.push_back("left");
  food.push_back("go 0");
  Species sFood(food, "f");

  // ------
  // hopper
  // ------
  
  /*
	0: hop
	1: go 0
  */

  
  vector<string> hopper(0);
  hopper.push_back("hop");
  hopper.push_back("go 0");
  Species sHopper(hopper, "h");
    
//  const string hopper[] = {"hop", "go 0"};
  
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
  

  vector<string> rover(0);
  rover.push_back("if_enemy 9");   // 0
  rover.push_back("if_empty 7");   // 1
  rover.push_back("if_random 5");  // 2
  rover.push_back("left");         // 3
  rover.push_back("go 0");         // 4
  rover.push_back("right");
  rover.push_back("go 0");         // 6
  rover.push_back("hop");
  rover.push_back("go 0");         // 8
  rover.push_back("infect");
  rover.push_back("go 0");         // 10
  Species sRover(rover, "r");
    
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
  
  vector<string> trap(0);
  trap.push_back("if_enemy 3");
  trap.push_back("left");
  trap.push_back("go 0");
  trap.push_back("infect");
  trap.push_back("go 0");
  Species sTrap(trap, "t");
 
  
  // best 1
  vector<string> best(0);
  best.push_back("if_enemy 9");   // 0
  best.push_back("if_empty 7");   // 1
  best.push_back("if_random 5");  // 2
  best.push_back("right");         // 3
  best.push_back("go 0");         // 4
  best.push_back("left");
  best.push_back("go 0");         // 6
  best.push_back("hop");
  best.push_back("go 0");         // 8
  best.push_back("infect");
  best.push_back("go 0");         // 10
  Species sBest(best, "b");


  // best 2
  vector<string> best2(0);
  best2.push_back("if_random 11"); // 0
  best2.push_back("left");         // 1
  
  best2.push_back("if_enemy 9");   // 2
  best2.push_back("if_wall 6");    // 3
  best2.push_back("hop");          // 4         
  best2.push_back("go 2");         // 5
  best2.push_back("left");         // 6
  best2.push_back("left");         // 7
  best2.push_back("go 2");         // 8
  best2.push_back("infect");       // 9
  best2.push_back("go 2");         // 10

  best2.push_back("if_enemy 18");  // 11
  best2.push_back("if_wall 15");   // 12
  best2.push_back("hop");          // 13        
  best2.push_back("go 11");        // 14
  best2.push_back("left");         // 15
  best2.push_back("left");         // 16
  best2.push_back("go 11");        // 17
  best2.push_back("infect");       // 18
  best2.push_back("go 11");        // 19
  Species sBest2(best2, "B");

  // 1
  try {
	cout << "*** Darwin 30x30 ***" << endl;
	
	
	Board bo(30, 30);

	for (int i = 0; i < 100; i++) {
	  bo.add(Creature(sHopper, i%4), rand()%30, rand()%30);
	}
	
	bo.simulate(200, 40);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }

  
  // 2
  try {
	cout << "*** Darwin 30x1 ***" << endl;
	
	
	Board bo(30, 1);

	bo.add(Creature(sRover, 0), 0, 5);
	
	bo.simulate(10, 2);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }

  // 3
  try {
	cout << "*** Darwin 20x20 ***" << endl;
	
	
	Board bo(20,20);

	for(int i = 0; i < 20; i++) {
	  for (int j = 0; j < 20; j++) {
		bo.add(Creature(sFood, 0), i, j);
	  }
	}

	bo.add(Creature(sTrap, 0), 10, 10);
	
	bo.simulate(10, 2);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }
 
 
  // 4
  try {
	cout << "*** Darwin 21x21 ***" << endl;
	
	
	Board bo(21,21);

	for(int i = 0; i < 20; i++) {
	  bo.add(Creature(sFood, 0), i+1, i);
	  bo.add(Creature(sFood, 0), i, i+1);
	  bo.add(Creature(sFood, 0), i, i);
	}

	bo.add(Creature(sTrap, 0), 20, 20);
	
	bo.simulate(100, 20);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }
 
  // 5
  try {
	cout << "*** Darwin 10x3 ***" << endl;
	
	
	Board bo(10,3);

	bo.add(Creature(sHopper, 3), 0, 0);
	bo.add(Creature(sHopper, 3), 2, 0);
	bo.add(Creature(sFood, 2), 1, 0);
	bo.add(Creature(sFood, 2), 1, 1);
	bo.add(Creature(sFood, 1), 1, 2);
	bo.add(Creature(sFood, 1), 1, 3);
	bo.add(Creature(sFood, 1), 1, 4);
	bo.add(Creature(sTrap, 1), 1, 5);
	bo.add(Creature(sFood, 1), 1, 6);
	bo.add(Creature(sFood, 1), 1, 7);
	bo.add(Creature(sFood, 1), 1, 8);
	bo.add(Creature(sFood, 1), 1, 9);
	
	bo.simulate(10, 2);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }

  // 6
  try {
	cout << "*** Darwin 3x3 ***" << endl;
	
	
	Board bo(3,3);

	bo.add(Creature(sFood, 2), 0, 0);
	bo.add(Creature(sFood, 1), 1, 0);
	bo.add(Creature(sFood, 1), 2, 0);
	bo.add(Creature(sFood, 1), 0, 1);
	bo.add(Creature(sTrap, 1), 1, 1);
	bo.add(Creature(sFood, 1), 2, 1);
	bo.add(Creature(sFood, 1), 0, 2);
	bo.add(Creature(sFood, 1), 1, 2);
	bo.add(Creature(sFood, 1), 2, 2);
	
	bo.simulate(10, 2);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }

   
  // ----------
  // darwin 8x8
  // ----------
  
  // 7
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
	
	
	Board bo(8,8);

	bo.add(Creature(sFood, 2), 0, 0);
	bo.add(Creature(sHopper, 1), 3, 3);
	bo.add(Creature(sHopper, 2), 4, 3);
	bo.add(Creature(sHopper, 3), 4, 4);
	bo.add(Creature(sHopper, 0), 3, 4);
	bo.add(Creature(sFood, 1), 7, 7);
	
	bo.simulate(5, 1);
	
  } catch (const invalid_argument&) {
	cout << "invalid_argument" << endl;
	assert(false);
  } catch (const out_of_range&) {
	cout << "out_of_range" << endl;
	assert(false);
  }


  // ----------
  // darwin 7x9
  // ----------
  
  // 8
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

	Board bo(7,9);

	bo.add(Creature(sTrap, 3), 0, 0);
	bo.add(Creature(sHopper, 2), 2, 3);
	bo.add(Creature(sRover, 1), 4, 5);
	bo.add(Creature(sTrap, 0), 8, 6);
	
	bo.simulate(5, 1);
	
  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  // ------------
  // darwin 72x72
  // without best
  // ------------
  
  // 9
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

	Board b(72, 72);
	
	int position, x, y, direction;
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;
	  cout << x << ", " << y << endl;
	  direction = rand() % 4;
	  if (true) b.add(Creature(sFood, direction), x, y);
	}
	
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sHopper, direction), x, y);
	}
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sRover, direction), x, y);
	}
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sTrap, direction), x, y);
	  }

	b.simulate(1000, 100);

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }
  
  // ------------
  // darwin 72x72
  // with best
  // ------------
  
  // 10
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

	Board b(72, 72);
	
	int position, x, y, direction;
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;
	  cout << x << ", " << y << endl;
	  direction = rand() % 4;
	  if (true) b.add(Creature(sFood, direction), x, y);
	}
	
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sHopper, direction), x, y);
	}
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sRover, direction), x, y);
	}
	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sTrap, direction), x, y);
	}

	for(int i = 0; i < 10; i++) {
	  position = rand() % 5184;
	  x = position % 72;
	  y = position / 72;

	  direction = rand() % 4;
	  b.add(Creature(sBest, direction), x, y);
	}

	b.simulate(1000, 100);

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }
  
  return 0;
}
