// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <cstring>   // ==
#include <map>      // map
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner
#include <string.h> 
#define private public
#include "Darwin.h"

// ----------
// TestDarwin
// ----------



// -----------------
// TestDarwinSpecies
// -----------------
struct TestDarwinSpecies : CppUnit::TestFixture {
    
    // ------------------------
    // test_species_constructor
    // ------------------------
    void test_species_constructor_1() {
        Species food;
        CPPUNIT_ASSERT(food._name == '.');
        CPPUNIT_ASSERT(food._program.size() == 0);
    }

    void test_species_constructor_2() {
        Species food1;
        CPPUNIT_ASSERT(food1._name == '.');
        CPPUNIT_ASSERT(food1._program.size() == 0);
    }

   void test_species_constructor_3() {
        Species food2;
        CPPUNIT_ASSERT(food2._name == '.');
        CPPUNIT_ASSERT(food2._program.size() == 0);
    }
     
    // ------------
    // test_species
    // ------------
    void test_species_1() {
        Species food ('f');
        CPPUNIT_ASSERT(food._name == 'f');
    }
    
    void test_species_2() {
        Species hopper('h');
        CPPUNIT_ASSERT(hopper._name == 'h');
    }
    
    void test_species_3() {
        Species trap('t');
        CPPUNIT_ASSERT(trap._name == 't');
    }
    
    // --------------------
    // test_add_instruction
    // --------------------
    void test_operator1(){
  	Species trap('t');
   	trap.add_instruction("hop");
	CPPUNIT_ASSERT(trap._program[0] == "hop");
    }

    void test_operator2(){
  	Species trap('t');
   	trap.add_instruction("lol");
	CPPUNIT_ASSERT(trap._program[0] == "lol");
    }

    void test_operator3(){
  	Species trap('t');
   	trap.add_instruction("h3p");
	CPPUNIT_ASSERT(trap._program[0] == "h3p");
    }
  
    // --------------------
    // test_add_instruction
    // --------------------
    void test_add_instruction_1() {
        Species food('f');
        CPPUNIT_ASSERT(food._program.size() == 0);
        food.add_instruction("hi");
        CPPUNIT_ASSERT(food._program.size() == 1);
   }
    
    void test_add_instruction_2() {
        Species food('f');
        CPPUNIT_ASSERT(food._program.size() == 0);
        food.add_instruction("hi");
        food.add_instruction("bye");
        CPPUNIT_ASSERT(food._program.size() == 2);
        
    }
    
    void test_add_instruction_3() {
        Species food('f');
	CPPUNIT_ASSERT(food._program.size() == 0);
	food.add_instruction("hi");
	food.add_instruction("bye");
	food.add_instruction("hey");
	CPPUNIT_ASSERT(food._program.size() == 3);
    }
    

   //-------------------
   // test_name_function
   //--------------------
    void test_name_function1() {
        Species hopper('h');
        CPPUNIT_ASSERT(hopper.name() == 'h');
    }

     void test_name_function2() {
        Species hopper1('f');
        CPPUNIT_ASSERT(hopper1.name() == 'f');
    }

      void test_name_function3() {
        Species hopper2('t');
        CPPUNIT_ASSERT(hopper2.name() == 't');
    }

    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestDarwinSpecies);
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_constructor_2);
    CPPUNIT_TEST(test_species_constructor_3);
    CPPUNIT_TEST(test_species_1);
    CPPUNIT_TEST(test_species_2);
    CPPUNIT_TEST(test_species_3);
    CPPUNIT_TEST(test_operator1);
    CPPUNIT_TEST(test_operator2);
    CPPUNIT_TEST(test_operator3);
     CPPUNIT_TEST(test_add_instruction_1);
    CPPUNIT_TEST(test_add_instruction_2);
    CPPUNIT_TEST(test_add_instruction_3);
    CPPUNIT_TEST(test_name_function1);
    CPPUNIT_TEST(test_name_function2);
    CPPUNIT_TEST(test_name_function3);
   CPPUNIT_TEST_SUITE_END();
};

struct TestDarwinCreature : CppUnit::TestFixture {
     // ------------------------
    // test_creature_constructor
    // -------------------------
    void test_creature_constructor1(){
	Creature f1;
	CPPUNIT_ASSERT(f1._direction == 0);
	CPPUNIT_ASSERT(f1._turn_done == false);
	CPPUNIT_ASSERT(f1._program_counter == 0);
    }

	void test_creature_constructor2(){
	Creature f2;
	CPPUNIT_ASSERT(f2._direction == 0);
	CPPUNIT_ASSERT(f2._turn_done == false);
	CPPUNIT_ASSERT(f2._program_counter == 0);
    }

	void test_creature_constructor3(){
	Creature f3;
	CPPUNIT_ASSERT(f3._direction == 0);
	CPPUNIT_ASSERT(f3._turn_done == false);
	CPPUNIT_ASSERT(f3._program_counter == 0);
    }

    // --------------
    // test_creature
    // ---------------
    void test_creature1(){
	Species food('f');
	int direction = 2;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1._species._name == 'f');	
	CPPUNIT_ASSERT(f1._direction == 2);
	CPPUNIT_ASSERT(f1._turn_done == false);
	CPPUNIT_ASSERT(f1._program_counter == 0);
    }

    void test_creature2(){
	Species food('f');
	int direction = 1;
	Creature f2(food, direction);
	CPPUNIT_ASSERT(f2._species._name == 'f');	
	CPPUNIT_ASSERT(f2._direction == 1);
	CPPUNIT_ASSERT(f2._turn_done == false);
	CPPUNIT_ASSERT(f2._program_counter == 0);
    }


    void test_creature3(){
	Species food('f');
	int direction = 0;
	Creature f3(food, direction);
	CPPUNIT_ASSERT(f3._species._name == 'f');	
	CPPUNIT_ASSERT(f3._direction == 0);
	CPPUNIT_ASSERT(f3._turn_done == false);
	CPPUNIT_ASSERT(f3._program_counter == 0);
    }


    // ---------------------
    // test_next_instruction
    // ---------------------
    void test_next_instruction1(){
	Species food('f');
	food.add_instruction("hi");
	food.add_instruction("bye");
	food.add_instruction("hey");
	int pc = 2;
	CPPUNIT_ASSERT(food[pc] == "hey");
    }

    void test_next_instruction2(){
	Species food('f');
	food.add_instruction("hi");
	food.add_instruction("bye");
	food.add_instruction("hey");
	int pc = 1;
	CPPUNIT_ASSERT(food[pc] == "bye");
    }

    void test_next_instruction3(){
	Species food('f');
	food.add_instruction("hi");
	food.add_instruction("bye");
	food.add_instruction("hey");
	int pc = 0;
	CPPUNIT_ASSERT(food[pc] == "hi");
    }

     // ---------
    // test_left
    // ----------
     void test_left1() {
	Species food('f');
        int direction = 3;        
	Creature f1('f', direction);
        f1.left();
        CPPUNIT_ASSERT(f1._direction == 2);
    }
 
   
    void test_left2() {
       Species food('f');
        int direction = 1;        
	Creature f1('f', direction);
        f1.left();
        CPPUNIT_ASSERT(f1._direction == 0);
    }

    void test_left3() {
       Species food('f');
        int direction = 2;        
	Creature f1('f', direction);
        f1.left();
        CPPUNIT_ASSERT(f1._direction == 1);
    }

    // ---------
    // test_right
    // ----------
     void test_right1() {
	Species food('f');
        int direction = 3;        
	Creature f1('f', direction);
        f1.right();
        CPPUNIT_ASSERT(f1._direction == 0);
    }
 
    void test_right2() {
	Species food('f');
        int direction = 1;        
	Creature f1('f', direction);
        f1.right();
        CPPUNIT_ASSERT(f1._direction == 2);
    }
 
     void test_right3() {
	Species food('f');
        int direction = 0;        
	Creature f1('f', direction);
        f1.right();
        CPPUNIT_ASSERT(f1._direction == 1);
    }
 
    // ----------------
    // test_get_species
    // ----------------
    void test_get_species1(){
	Species food('f');
	int direction = 1;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1.species()._name == 'f');	

    }

    void test_get_species2(){
	Species food('h');
	int direction = 1;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1.species()._name == 'h');	

    }

    void test_get_species3(){
	Species food('t');
	int direction = 1;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1.species()._name == 't');	

    }


     // ------------------
    // test_assign_species
    // -------------------
    void test_assign_species1(){
	Species food('f');
	Species hopper('h');
	int direction = 1;
	Creature f1(food, direction);
	f1.assign_species(hopper);
	CPPUNIT_ASSERT(f1.species()._name == 'h');	

    }

    void test_assign_species2(){
	Species food('f');
	Species hopper('h');
	int direction = 1;
	Creature f1(hopper, direction);
	f1.assign_species(food);
	CPPUNIT_ASSERT(f1.species()._name == 'f');	

    }

    void test_assign_species3(){
	Species trap('t');
	Species hopper('h');
	int direction = 1;
	Creature f1(hopper, direction);
	f1.assign_species(trap);
	CPPUNIT_ASSERT(f1.species()._name == 't');	

    }

     // -------------
    // test_direction
    // --------------
    void test_direction1(){
	Species food('f');
	int direction = 1;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1.direction() == 1);	
    }

    void test_direction2(){
	Species food('f');
	int direction = 2;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1.direction() == 2);	
    }

    void test_direction3(){
	Species food('f');
	int direction = 3;
	Creature f1(food, direction);
	CPPUNIT_ASSERT(f1.direction() == 3);	
    }

    // -------------
    // test_turn_done
    // --------------
    void test_turn_done1(){
	Species food('f');
	int direction = 1;
	Creature f1(food, direction);
	f1.turn(true);
	CPPUNIT_ASSERT(f1._turn_done == true);	
    }

   void test_turn_done2(){
	Species food('f');
	int direction = 1;
	Creature f1(food, direction);
	f1.turn(false);
	CPPUNIT_ASSERT(f1._turn_done == false);	
    }

   void test_turn_done3(){
	Species food('f');
	int direction = 1;
	Creature f1(food, direction);
	f1.turn(true);
	f1.turn(false);
	CPPUNIT_ASSERT(f1._turn_done == false);	
    }
     // --------
    // test_turn
    // ---------
    void test_turn1(){
	Creature f1;
	f1._turn_done = true;
	bool done = false;
	f1.turn(done);
	CPPUNIT_ASSERT(f1._turn_done == false);	
    }

   void test_turn2(){
	Creature f1;
	f1._turn_done = false;
	bool done = true;
	f1.turn(done);
	CPPUNIT_ASSERT(f1._turn_done == true);	
    }

   void test_turn3(){
	Creature f1;
	bool done = true;
	f1.turn(done);
	CPPUNIT_ASSERT(f1._turn_done == true);	
    }

    // -----------------
    // test_increment_pc
    // -----------------
    void test_increment_pc1(){
	Creature f1;
	CPPUNIT_ASSERT(f1._program_counter == 0);	
	f1.increment_program_counter();
	CPPUNIT_ASSERT(f1._program_counter == 1);	
    }

    void test_increment_pc2(){
	Creature f1;
	CPPUNIT_ASSERT(f1._program_counter == 0);	
	f1.increment_program_counter();
	f1.increment_program_counter();
	CPPUNIT_ASSERT(f1._program_counter == 2);	
    }

    void test_increment_pc3(){
	Creature f1;
	f1._program_counter = 5;
	CPPUNIT_ASSERT(f1._program_counter == 5);	
	f1.increment_program_counter();
	CPPUNIT_ASSERT(f1._program_counter == 6);	
    }
    
     
    // ------------
    // test_pc_goto
    // ------------
    void test_pc_goto1(){
	Creature f1;
	CPPUNIT_ASSERT(f1._program_counter == 0);	
	f1.program_counter_goto(3);
	CPPUNIT_ASSERT(f1._program_counter == 3);	
    }

   void test_pc_goto2(){
	Creature f1;
	CPPUNIT_ASSERT(f1._program_counter == 0);	
	f1.program_counter_goto(2);
	CPPUNIT_ASSERT(f1._program_counter == 2);	
    }

   void test_pc_goto3(){
	Creature f1;
	CPPUNIT_ASSERT(f1._program_counter == 0);	
	f1.program_counter_goto(6);
	CPPUNIT_ASSERT(f1._program_counter == 6);	
    }
    
    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestDarwinCreature);
    CPPUNIT_TEST(test_creature_constructor1);
    CPPUNIT_TEST(test_creature_constructor2);
    CPPUNIT_TEST(test_creature_constructor3);
    CPPUNIT_TEST(test_creature1);
    CPPUNIT_TEST(test_creature2);
    CPPUNIT_TEST(test_creature3);
    CPPUNIT_TEST(test_next_instruction1);
    CPPUNIT_TEST(test_next_instruction2);
    CPPUNIT_TEST(test_next_instruction3);
    CPPUNIT_TEST(test_left1);
    CPPUNIT_TEST(test_left2);
    CPPUNIT_TEST(test_left3);
    CPPUNIT_TEST(test_right1);
    CPPUNIT_TEST(test_right2);
    CPPUNIT_TEST(test_right3);
    CPPUNIT_TEST(test_get_species1);
    CPPUNIT_TEST(test_get_species2);
    CPPUNIT_TEST(test_get_species3);
    CPPUNIT_TEST(test_assign_species1);
    CPPUNIT_TEST(test_assign_species2);
    CPPUNIT_TEST(test_assign_species3);
    CPPUNIT_TEST(test_direction1);
    CPPUNIT_TEST(test_direction2);
    CPPUNIT_TEST(test_direction3);
    CPPUNIT_TEST(test_turn_done1);
    CPPUNIT_TEST(test_turn_done2);
    CPPUNIT_TEST(test_turn_done3);
    CPPUNIT_TEST(test_turn1);
    CPPUNIT_TEST(test_turn2);
    CPPUNIT_TEST(test_turn3);
    CPPUNIT_TEST(test_increment_pc1);
    CPPUNIT_TEST(test_increment_pc2);
    CPPUNIT_TEST(test_increment_pc3);
    CPPUNIT_TEST(test_pc_goto1);
    CPPUNIT_TEST(test_pc_goto2);
    CPPUNIT_TEST(test_pc_goto3);
    CPPUNIT_TEST_SUITE_END();
};


struct TestDarwinGrid : CppUnit::TestFixture {
    
     // -------------------
    // test_grid_constructor
    // --------------------
    void test_grid_constructor1(){
	Grid<8, 8> world;
	CPPUNIT_ASSERT(world._row == 8);
	CPPUNIT_ASSERT(world._col == 8);
    }
      
    void test_grid_constructor2(){
	Grid<8, 2> world;
	CPPUNIT_ASSERT(world._row == 8);
	CPPUNIT_ASSERT(world._col == 2);
    }

    void test_grid_constructor3(){
	Grid<5, 5> world;
	CPPUNIT_ASSERT(world._row == 5);
	CPPUNIT_ASSERT(world._col == 5);
    }


    // -------------
    // test_next_row
    // --------------
    void test_next_row1(){
	int direction = 3;
	Grid<5,5> world;
	world._row = 3;
	int result = world.next_row(world._row, direction);
	CPPUNIT_ASSERT(result == 4);
    }

    void test_next_row2(){
	int direction = 1;
	Grid<5,5> world;
	world._row = 3;
	int result = world.next_row(world._row, direction);
	CPPUNIT_ASSERT(result == 2);
    }

    void test_next_row3(){
	int direction = 2;
	Grid<5,5> world;
	world._row = 3;
	int result = world.next_row(world._row, direction);
	CPPUNIT_ASSERT(result == 3);
    }
    
     // -------------
    // test_next_col
    // --------------
    void test_next_col1(){
	int direction = 2;
	Grid<5,5> world;
	world._col = 3;
	int result = world.next_col(world._col, direction);
	CPPUNIT_ASSERT(result == 4);
    }

    void test_next_col2(){
	int direction = 1;
	Grid<5,5> world;
	world._col = 3;
	int result = world.next_col(world._col, direction);
	CPPUNIT_ASSERT(result == 3);
    }

    void test_next_col3(){
	int direction = 0;
	Grid<5,5> world;
	world._col = 5;
	int result = world.next_col(world._col, direction);
	CPPUNIT_ASSERT(result == 4);
    }
    

    // -----------------
    // test_add_creature
    // -----------------
    void test_add_creature1(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 3);
	world.add_creature(f1, 1, 2);
	CPPUNIT_ASSERT(world._grid[1][2]->species()._name == 'f');
    }

    void test_add_creature2(){
	Grid<10,10> world;
	Species food('f');
	Creature f1 (food, 3);
	world.add_creature(f1, 5, 6);
	CPPUNIT_ASSERT(world._grid[5][6]->species()._name == 'f');
    }

    void test_add_creature3(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 3);
	world.add_creature(f1, 3, 3);
	CPPUNIT_ASSERT(world._grid[3][3]->species()._name == 'f');
    }

    //-----------------
    // test_execute_turn
    //------------------
    void test_execute_turn1(){
	Grid<1,1> world;
	world.execute_turn();
	CPPUNIT_ASSERT(true);
    }

   void test_execute_turn2(){
	Grid<2,3> world;
	world.execute_turn();
	CPPUNIT_ASSERT(true);
    }

   void test_execute_turn3(){
	Grid<1,5> world;
	world.execute_turn();
	CPPUNIT_ASSERT(true);
    }


    //----------
    // test_act
    //----------
    void test_act1(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 3, 3);
	CPPUNIT_ASSERT(world.act("hop", 3, 3) == true);
    }

   void test_act2(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 1, 1);
	CPPUNIT_ASSERT(world.act("left", 1, 1) == true);
    }

   void test_act3(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 1, 1);
	CPPUNIT_ASSERT(world.act("right", 1, 1) == true);
    }


     //----------
    // test_hop
    //----------
    void test_hop1(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 3, 3);
	world.act("hop", 3, 3);
	CPPUNIT_ASSERT(world._grid[2][3]->species()._name == 'f');
    }

    void test_hop2(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 4, 3);
	world.act("hop", 4, 3);
	CPPUNIT_ASSERT(world._grid[3][3]->species()._name == 'f');
    }

    void test_hop3(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 0);
	world.add_creature(f1, 3, 3);
	world.act("hop", 3, 3);
	CPPUNIT_ASSERT(world._grid[3][2]->species()._name == 'f');
    }


    //----------
    // test_infect
    //----------
    void test_infect1(){
	Grid<5,5> world;
	Species food('f');
	Species hopper('h');
	Creature f1 (food, 1);
	Creature h1 (hopper, 1);
	world.add_creature(f1, 2, 3);
	world.add_creature(h1, 3, 3);
	world.act("infect", 3, 3);
	CPPUNIT_ASSERT(world._grid[2][3]->species()._name == 'h');
    }

    void test_infect2(){
	Grid<5,5> world;
	Species food('f');
	Species hopper('h');
	Creature f1 (food, 1);
	Creature h1 (hopper, 1);
	world.add_creature(f1, 3, 3);
	world.add_creature(h1, 4, 3);
	world.act("infect", 4, 3);
	CPPUNIT_ASSERT(world._grid[3][3]->species()._name == 'h');
    }

    void test_infect3(){
	Grid<5,5> world;
	Species food('f');
	Species hopper('h');
	Creature f1 (food, 1);
	Creature h1 (hopper, 2);
	world.add_creature(f1, 3, 4);
	world.add_creature(h1, 3, 3);
	world.act("infect", 3, 3);
	CPPUNIT_ASSERT(world._grid[3][4]->species()._name == 'h');
    }


    //--------------
    // test_if_empty
    //--------------
    void test_if_empty1(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 4, 3);
	CPPUNIT_ASSERT(world.if_empty(4,3) == true);
    }

   void test_if_empty2(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 1, 3);
	CPPUNIT_ASSERT(world.if_empty(1,3) == true);
    }

   void test_if_empty3(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 2, 3);
	CPPUNIT_ASSERT(world.if_empty(2,3) == true);
    }


    //--------------
    // test_if_wall
    //--------------
    void test_if_wall1(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 4, 3);
	CPPUNIT_ASSERT(world.if_wall(4,3) == false);
    }
 
   void test_if_wall2(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 1);
	world.add_creature(f1, 0, 0);
	CPPUNIT_ASSERT(world.if_wall(0,0) == true);
    }

   void test_if_wall3(){
	Grid<5,5> world;
	Species food('f');
	Creature f1 (food, 3);
	world.add_creature(f1, 4, 3);
	CPPUNIT_ASSERT(world.if_wall(4,3) == true);
    }

    //----------------
    // test_if_random()
    //-----------------
    void test_if_random1(){
	Grid<5,5> world;
	bool temp = world.if_random();
	CPPUNIT_ASSERT(temp == true || temp == false);
    }

   void test_if_random2(){
	Grid<5,2> world;
	bool temp = world.if_random();
	CPPUNIT_ASSERT(temp == true || temp == false);
    }

   void test_if_random3(){
	Grid<5,6> world;
	bool temp = world.if_random();
	CPPUNIT_ASSERT(temp == true || temp == false);
    }

    //----------------
    // test_if_enemy
    //-----------------
    void test_if_enemy1(){
	Grid<5,5> world;
	Species food('f');
	Species hopper('h');
	Creature f1 (food, 1);
	Creature h1 (hopper, 2);
	world.add_creature(f1, 3, 4);
	world.add_creature(h1, 3, 3);
	CPPUNIT_ASSERT(world.if_enemy(3, 3) == true) ;
    }

    void test_if_enemy2(){
	Grid<5,5> world;
	Species food('f');
	Species hopper('h');
	Creature f1 (food, 1);
	Creature h1 (hopper, 1);
	world.add_creature(f1, 2, 3);
	world.add_creature(h1, 3, 3);
	CPPUNIT_ASSERT(world.if_enemy(3, 3) == true) ;
    }

    void test_if_enemy3(){
	Grid<5,5> world;
	Species hopper('h');
	Creature h1 (hopper, 1);
	Creature h2 (hopper, 1);
	world.add_creature(h1, 3, 3);
	world.add_creature(h2, 4, 3);
	CPPUNIT_ASSERT(world.if_enemy(4, 3) == false) ;
    }

    //------------
    // test_print
    //------------
    void test_print1(){
	Grid<2,2> world;
        ostringstream s;
        world.print(s);
        CPPUNIT_ASSERT(s.str() == " 01\n0..\n1..\n");
    }
    
    void test_print2(){
	Grid<3,3> world;
        ostringstream s;
        world.print(s);
        CPPUNIT_ASSERT(s.str() == " 012\n0...\n1...\n2...\n");
    }

    void test_print3(){
	Grid<2,1> world;
        ostringstream s;
        world.print(s);
        CPPUNIT_ASSERT(s.str() == " 0\n0.\n1.\n");
    }
     // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestDarwinGrid);
    CPPUNIT_TEST(test_grid_constructor1);
    CPPUNIT_TEST(test_grid_constructor2);
    CPPUNIT_TEST(test_grid_constructor3);
    CPPUNIT_TEST(test_next_row1);
    CPPUNIT_TEST(test_next_row2);
    CPPUNIT_TEST(test_next_row3);
    CPPUNIT_TEST(test_next_col1);
    CPPUNIT_TEST(test_next_col2);
    CPPUNIT_TEST(test_next_col3);
    CPPUNIT_TEST(test_add_creature1);
    CPPUNIT_TEST(test_add_creature2);
    CPPUNIT_TEST(test_add_creature3);
    CPPUNIT_TEST(test_execute_turn1);
    CPPUNIT_TEST(test_execute_turn2);
    CPPUNIT_TEST(test_execute_turn3);
    CPPUNIT_TEST(test_act1);
    CPPUNIT_TEST(test_act2);
    CPPUNIT_TEST(test_act3);
    CPPUNIT_TEST(test_hop1);
    CPPUNIT_TEST(test_hop2);
    CPPUNIT_TEST(test_hop3);
    CPPUNIT_TEST(test_infect1);
    CPPUNIT_TEST(test_infect2);
    CPPUNIT_TEST(test_infect3);
    CPPUNIT_TEST(test_if_empty1);
    CPPUNIT_TEST(test_if_empty2);
    CPPUNIT_TEST(test_if_empty3);
    CPPUNIT_TEST(test_if_wall1);
    CPPUNIT_TEST(test_if_wall2);
    CPPUNIT_TEST(test_if_wall3);
    CPPUNIT_TEST(test_if_random1);
    CPPUNIT_TEST(test_if_random2);
    CPPUNIT_TEST(test_if_random3);
    CPPUNIT_TEST(test_if_enemy1);
    CPPUNIT_TEST(test_if_enemy2);
    CPPUNIT_TEST(test_if_enemy3);
    CPPUNIT_TEST(test_print1);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST_SUITE_END();

};
// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;
    
    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwinSpecies::suite());
    tr.addTest(TestDarwinCreature::suite());
    tr.addTest(TestDarwinGrid::suite());
    tr.run();
    
    cout << "Done." << endl;
    return 0;
}
