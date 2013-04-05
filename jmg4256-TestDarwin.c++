// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define protected public
#define private public

#include "Darwin.h"


// -----------
// TestDarwin
// -----------

Species Hopper("Hopper");
Species MHopper("MHopper");
Species MMHopper("MMHopper");
Species NHopper("NHopper");
Species EnemyChecker("E");
Species Food("F");
Species Infector("I");
struct TestDarwin : CppUnit::TestFixture {

	// -----
	// Block
	// -----
  //testisOccupied
	void test_block_1 (){
		Block b;
        CPPUNIT_ASSERT(!b.is_occupied);
    }

  //test setCreature, testisOccupied
	void test_block_2 (){
		Block b;
		Creature c(Hopper, NORTH);
		b.setCreature(c, 0 , 0);
        CPPUNIT_ASSERT(b.is_occupied);
    }

  //test setCreature/clear, testisOccupied
	void test_block_3 (){
		Block b;
		Creature c (Hopper, NORTH);
		b.setCreature(c, 0, 0);
    CPPUNIT_ASSERT(b.is_occupied);
    b.clear();
    CPPUNIT_ASSERT(!b.is_occupied);
    }

  //test setCreature/clear, testisOccupied
    void test_block_4 (){
        Block b;
        Block b2;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        b2.setCreature(c, 0, 0);
    CPPUNIT_ASSERT(b.is_occupied);
    CPPUNIT_ASSERT(b2.is_occupied);
    b.clear();
    b2.clear();
    CPPUNIT_ASSERT(!b.is_occupied);
    CPPUNIT_ASSERT(!b2.is_occupied);
    }

  //test getCreature/setCreature
    void test_block_5 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }
    

  //test getCreature/setCreature
    void test_block_6 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }


  //test getCreature/setCreature
    void test_block_7 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }


  //test getCreature/setCreature
    void test_block_8 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }


  //test getCreature/setCreature
    void test_block_9 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }


  //test getCreature/setCreature
    void test_block_10 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }


  //test getCreature/setCreature
    void test_block_11 (){
        Block b;
        Creature c (Hopper, EAST);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }


  //test getCreature/setCreature
    void test_block_12 (){
        Block b;
        Creature c (Hopper, NORTH);
        b.setCreature(c, 0, 0);
        CPPUNIT_ASSERT(b.is_occupied);
        Creature c1 = b.getCreature();
        CPPUNIT_ASSERT(c1._x == 0);
        CPPUNIT_ASSERT(c1._y == 0);
        CPPUNIT_ASSERT(c1.facing_dir == c.facing_dir);
        CPPUNIT_ASSERT(c1.program_counter == c.program_counter);
        CPPUNIT_ASSERT(c1._s == c._s);
        CPPUNIT_ASSERT(c1.actionDone == c.actionDone);
    }
    // -----
    // Creature
    // -----

    //test = operator
    void test_creature_1 (){
        Creature c (Hopper, NORTH);
        Creature m (MHopper, EAST);
        c = m;
        CPPUNIT_ASSERT(c.facing_dir == m.facing_dir);
        CPPUNIT_ASSERT(c.program_counter == m.program_counter);
        CPPUNIT_ASSERT(c._s == m._s);
        CPPUNIT_ASSERT(c.actionDone == m.actionDone);
    }

    //test = operator
    void test_creature_2 (){
        Creature c (Hopper, NORTH);
        Creature m (MHopper, EAST);
        m = c;
        CPPUNIT_ASSERT(c.facing_dir == m.facing_dir);
        CPPUNIT_ASSERT(c.program_counter == m.program_counter);
        CPPUNIT_ASSERT(c._s == m._s);
        CPPUNIT_ASSERT(c.actionDone == m.actionDone);
    }

    //test = operator
    void test_creature_3 (){
        Creature c (Hopper, NORTH);
        Creature m (MHopper, EAST);
        m = c;
        CPPUNIT_ASSERT(c.facing_dir == m.facing_dir);
        CPPUNIT_ASSERT(c.program_counter == m.program_counter);
        CPPUNIT_ASSERT(c._s == m._s);
        CPPUNIT_ASSERT(c.actionDone == m.actionDone);
    }

    //test = operator
    void test_creature_4 (){
        Creature c (Hopper, NORTH);
        Creature m (Hopper, EAST);
        m = c;
        CPPUNIT_ASSERT(c.facing_dir == m.facing_dir);
        CPPUNIT_ASSERT(c.program_counter == m.program_counter);
        CPPUNIT_ASSERT(c._s == m._s);
        CPPUNIT_ASSERT(c.actionDone == m.actionDone);
    }

    //test has acted
    void test_creature_5 (){
        Creature c (Hopper, NORTH);
        CPPUNIT_ASSERT(!c.hasActed());
    }

    //test has acted
    void test_creature_6 (){
        Darwin d(5,5);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 0, 0);
        c.doAction(d.grid);
        CPPUNIT_ASSERT(c.hasActed());
    }


    //test has acted
    void test_creature_7 (){
        Darwin d(5,5);
        Creature c (MHopper, EAST);
        d.placeCreature(c, 0, 0);
        c.doAction(d.grid);
        CPPUNIT_ASSERT(c.hasActed());
    }

        //test resetActionDone
    void test_creature_8 (){
        Darwin d(5,5);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 0, 0);
        c.doAction(d.grid);
        c.resetActionDone();
        CPPUNIT_ASSERT(!c.hasActed());
    }


    //test resetActionDone
    void test_creature_9 (){
        Darwin d(5,5);
        Creature c (MHopper, EAST);
        d.placeCreature(c, 0, 0);
        c.doAction(d.grid);
        c.resetActionDone();
        CPPUNIT_ASSERT(!c.hasActed());
    }

    //test resetActionDone
    void test_creature_10 (){
        Darwin d(5,5);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 2, 2);
        c.doAction(d.grid);
        c.resetActionDone();
        CPPUNIT_ASSERT(!c.hasActed());
    }


    //test sameSpecies
    void test_creature_16 (){
        Creature c (Hopper, NORTH);
        Creature c2 (Hopper, NORTH);
        CPPUNIT_ASSERT(c.sameSpecies(c2));
    }

    //test sameSpecies
    void test_creature_11 (){
        Creature c (Hopper, NORTH);
        Creature c2 (Hopper, EAST);
        CPPUNIT_ASSERT(c.sameSpecies(c2));
    }

    //test sameSpecies
    void test_creature_12 (){
        Creature c (Hopper, NORTH);
        Creature c2 (MHopper, EAST);
        CPPUNIT_ASSERT(!c.sameSpecies(c2));
    }

    //test becomeInfected
    void test_creature_13 (){
        Creature c (Hopper, NORTH);
        Creature c2 (MHopper, EAST);
        c2.becomeInfected(c);
        CPPUNIT_ASSERT(c.sameSpecies(c2));
    }

      //test becomeInfected
    void test_creature_14 (){
        Creature c (Hopper, NORTH);
        Creature c2 (Hopper, EAST);
        c2.becomeInfected(c);
        CPPUNIT_ASSERT(c.sameSpecies(c2));
    }

      //test becomeInfected
    void test_creature_15 (){
        Creature c (Hopper, NORTH);
        Creature c2 (Hopper, NORTH);
        c2.becomeInfected(c);
        CPPUNIT_ASSERT(c.sameSpecies(c2));
    }


    // -----
    // Darwin
    // -----

    //test placeCreature
    void test_darwin_1 (){
        Darwin d(8,7);
        CPPUNIT_ASSERT(d.x_size == 8);
        CPPUNIT_ASSERT(d.y_size == 7);
        CPPUNIT_ASSERT(d.curr_turn == 0);
        CPPUNIT_ASSERT(d.grid[0].size()== 8);
        CPPUNIT_ASSERT(d.grid.size()== 7);
        CPPUNIT_ASSERT(d.grid.begin()->begin()->isOccupied() == false);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 0, 0);
    	  CPPUNIT_ASSERT(d.grid[0][0].isOccupied() == true);
    }

    //test printGrid
    void test_darwin_2(){
    	Darwin d(2,1);
        ostringstream w;
        d.printGrid(w);
    	CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  01\n0 ..\n\n");
    }

    //tset prinGrid
    void test_darwin_3(){
        Darwin d(3,2);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 1, 0);
        d.placeCreature(c, 2, 1);
        d.placeCreature(c, 0, 1);
        ostringstream w;
        d.printGrid(w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 .H.\n1 H.H\n\n");
    }

    //test simulate/placeCreature
    void test_darwin_4(){
        Darwin d(3,2);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 1, 0);
        d.placeCreature(c, 2, 1);
        d.placeCreature(c, 0, 1);
        ostringstream w;
        d.simulate(3, 0, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 .H.\n1 H.H\n\nTurn = 1.\n  012\n0 HHH\n1 ...\n\nTurn = 2.\n  012\n0 HHH\n1 ...\n\nTurn = 3.\n  012\n0 HHH\n1 ...\n\n");
    }


    //Test simulate and hop action
     void test_action_1(){
        Darwin d(3,2);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 1, 1);
        ostringstream w;
        d.simulate(1, 0, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 .H.\n\nTurn = 1.\n  012\n0 .H.\n1 ...\n\n");
    }


    //Test simulate and hop action
     void test_action_2(){
        Darwin d(3,2);
        Creature c (Hopper, NORTH);
        d.placeCreature(c, 1, 1);
        ostringstream w;
        d.simulate(2, 0, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 .H.\n\nTurn = 1.\n  012\n0 .H.\n1 ...\n\nTurn = 2.\n  012\n0 .H.\n1 ...\n\n");
    }

     //Test simluate and hop action and left action
     void test_action_3(){
        Darwin d(3,2);
        Species SHopper("Sopper");
        SHopper.push_back(LEFT);
        SHopper.push_back(go, 0);

        Creature c (SHopper, NORTH);
        d.placeCreature(c, 1, 1);
    	  CPPUNIT_ASSERT(d.grid[1][1].getCreature().facing_dir == NORTH);
        ostringstream w;
        d.simulate(2, 0, w);
        //CPPUNIT_ASSERT(d.grid[1][1].getCreature().facing_dir == SOUTH);
    }


//vector< vector <Block> > & grid, int& program_counter, Direction &fdir, int& x, int& y
    //Test Action when MHopper reaches wall
     void test_action_4(){
        Darwin d(3,2);
        Creature c (Hopper, NORTH);
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c, 1, 1);

        for(int i = 1; i <= 20; i ++){
          Hopper.doAction(d.grid, pc, dir, x, y);
          CPPUNIT_ASSERT(pc == 1);
          CPPUNIT_ASSERT(dir == NORTH);
          CPPUNIT_ASSERT(x == 1);
          CPPUNIT_ASSERT(y == 0);
        }
    }

 //Test LEFT/RIGHT actions
     void test_action_5(){
        Darwin d(3,2);
        Species SHopper("Sopper");
        SHopper.push_back(LEFT);
        SHopper.push_back(go, 0);

        Creature c (SHopper, NORTH); 
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c, 1, 1);
        for(int i = 1; i <= 10; i++){
          int old_dir = (int) dir;
          SHopper.doAction(d.grid, pc, dir, x, y);
          old_dir = (old_dir - 1) == -1 ? 3: (old_dir - 1);
          CPPUNIT_ASSERT(pc == 1);
          CPPUNIT_ASSERT(dir == (Direction)(old_dir));
          CPPUNIT_ASSERT(x == 1);
          CPPUNIT_ASSERT(y == 1);
        }
    }


 //Test hopping around
     void test_action_6(){
        Darwin d(3,3);

        Creature c (MHopper, NORTH); 
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c, 2, 2);
        ostringstream w;
        d.simulate(12, 11, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 ...\n2 ..M\n\nTurn = 12.\n  012\n0 ...\n1 ...\n2 ..M\n\n");
        CPPUNIT_ASSERT(c.facing_dir == NORTH);
    }


     void test_action_7(){
        Darwin d(3,3);

        Creature c (NHopper, NORTH); 
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c, 0, 2);
        ostringstream w;
        d.simulate(12, 11, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 ...\n2 N..\n\nTurn = 12.\n  012\n0 ...\n1 ...\n2 N..\n\n");
    }


      void test_action_8(){
         Darwin d(3,3);

        Creature c (MMHopper, NORTH); 
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c, 2, 2);
        ostringstream w;
        d.simulate(12, 11, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 ...\n2 ..M\n\nTurn = 12.\n  012\n0 ...\n1 ...\n2 ..M\n\n");
    }

      //test if enemy
      void test_action_9(){
         Darwin d(3,3);

        Creature c (EnemyChecker, NORTH); 
        Creature c2 (Food, NORTH);
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c2, 2, 1);
        d.placeCreature(c, 2, 2);
        ostringstream w;
        d.simulate(3, 2, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 ..F\n2 ..E\n\nTurn = 3.\n  012\n0 ...\n1 ..F\n2 E..\n\n");
    }

      //test if enemy and infect
      void test_action_10(){
         Darwin d(3,3);

        Creature c (Infector, NORTH); 
        Creature c2 (Food, NORTH);
        int pc = 0;
        Direction dir = NORTH;
        int x = 1;
        int y = 1;
        d.placeCreature(c2, 2, 1);
        d.placeCreature(c, 2, 2);
        ostringstream w;
        d.simulate(4, 3, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 ...\n1 ..F\n2 ..I\n\nTurn = 4.\n  012\n0 ...\n1 I..\n2 I..\n\n");
    }


    void test_species_1(){
    Species s("Hopper");
    s.push_back(LEFT);
    s.push_back(go, 0);

    CPPUNIT_ASSERT(s.species_name == "Hopper");
    CPPUNIT_ASSERT(s.instructions[0].instr == LEFT);
    CPPUNIT_ASSERT(s.instructions[1].instr == go);
    CPPUNIT_ASSERT(s.instructions[0].line_num == -1);
    CPPUNIT_ASSERT(s.instructions[1].line_num == 0);
    }    

    void test_species_2(){
    Species s("Hopper");
    s.push_back(go, 0);
    s.push_back(LEFT);

    CPPUNIT_ASSERT(s.species_name == "Hopper");
    CPPUNIT_ASSERT(s.instructions[1].instr == LEFT);
    CPPUNIT_ASSERT(s.instructions[0].instr == go);
    CPPUNIT_ASSERT(s.instructions[1].line_num == -1);
    CPPUNIT_ASSERT(s.instructions[0].line_num == 0);
    }    

     void test_species_3(){
    Species s("Hopper");
    s.push_back(go, 0);
    s.push_back(LEFT);

    CPPUNIT_ASSERT(s.species_name == "Hopper");
    CPPUNIT_ASSERT(s.instructions[1].instr == LEFT);
    CPPUNIT_ASSERT(s.instructions[0].instr == go);
    CPPUNIT_ASSERT(s.instructions[1].line_num == -1);
    CPPUNIT_ASSERT(s.instructions[0].line_num == 0);
    }    




    
	// -----

	// suite
	// -----

CPPUNIT_TEST_SUITE(TestDarwin);
CPPUNIT_TEST(test_block_1);
CPPUNIT_TEST(test_block_2);
CPPUNIT_TEST(test_block_3);
CPPUNIT_TEST(test_block_4);
CPPUNIT_TEST(test_block_5);
CPPUNIT_TEST(test_block_6);
CPPUNIT_TEST(test_block_7);
CPPUNIT_TEST(test_block_8);
CPPUNIT_TEST(test_block_9);
CPPUNIT_TEST(test_block_10);
CPPUNIT_TEST(test_block_11);
CPPUNIT_TEST(test_block_12);


CPPUNIT_TEST(test_darwin_1); 
CPPUNIT_TEST(test_darwin_2); 
CPPUNIT_TEST(test_darwin_3);
CPPUNIT_TEST(test_darwin_4);  
  CPPUNIT_TEST(test_action_1); 
  CPPUNIT_TEST(test_action_2); 
  CPPUNIT_TEST(test_action_3);
  CPPUNIT_TEST(test_action_4);
  CPPUNIT_TEST(test_action_5);
  CPPUNIT_TEST(test_action_6);
  CPPUNIT_TEST(test_action_7);
  CPPUNIT_TEST(test_action_8);
  CPPUNIT_TEST(test_action_9);
  CPPUNIT_TEST(test_action_10);

  CPPUNIT_TEST(test_species_1);
  CPPUNIT_TEST(test_species_2);
  CPPUNIT_TEST(test_species_3);


  CPPUNIT_TEST(test_creature_1);
  CPPUNIT_TEST(test_creature_2);
  CPPUNIT_TEST(test_creature_3);
  CPPUNIT_TEST(test_creature_4);
  CPPUNIT_TEST(test_creature_5);
  CPPUNIT_TEST(test_creature_6);
  CPPUNIT_TEST(test_creature_7);
  CPPUNIT_TEST(test_creature_8);
  CPPUNIT_TEST(test_creature_9);
  CPPUNIT_TEST(test_creature_10);
  CPPUNIT_TEST(test_creature_11);
  CPPUNIT_TEST(test_creature_12);
  CPPUNIT_TEST(test_creature_13);
  CPPUNIT_TEST(test_creature_14);
  CPPUNIT_TEST(test_creature_15);
  CPPUNIT_TEST(test_creature_16);
  CPPUNIT_TEST_SUITE_END();
};


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    Hopper.push_back(HOP);
    Hopper.push_back(go, 0);

    MHopper.push_back(if_empty, 2);
    MHopper.push_back(LEFT);
    MHopper.push_back(HOP);
    MHopper.push_back(go, 0);


    MMHopper.push_back(if_wall, 3);
    MMHopper.push_back(HOP);
    MMHopper.push_back(go, 0);
    MMHopper.push_back(LEFT);
    MMHopper.push_back(go, 0);

    NHopper.push_back(if_empty, 2);
    NHopper.push_back(RIGHT);
    NHopper.push_back(HOP);
    NHopper.push_back(go, 0);

    EnemyChecker.push_back(if_enemy, 3);
    EnemyChecker.push_back(HOP);
    EnemyChecker.push_back(go, 0);
    EnemyChecker.push_back(LEFT);
    EnemyChecker.push_back(go, 0);

    Infector.push_back(if_enemy, 3);
    Infector.push_back(HOP);
    Infector.push_back(go, 0);
    Infector.push_back(INFECT);
    Infector.push_back(LEFT);
    Infector.push_back(go, 0);

    Food.push_back(LEFT);
    Food.push_back(go, 0);

    cout << "TestDarwin.c++" << endl;
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
