// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "Darwin.h"

#define private   public
// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {

    //Tests Food's behavior
    //Test Left/Go to behavior
    void test_acceptence_1 () {
        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Board gameboard(8,8);
        Creature a(food,0);
        gameboard.placeCreature(&a,0,0);
        assert(gameboard.environment.at(0).at(0)!=0);
        assert( (*gameboard.environment.at(0).at(0)).direction == 0 );
        gameboard.Turn();
        assert( (*gameboard.environment.at(0).at(0)).direction == 3 );
        gameboard.Turn();
        assert( (*gameboard.environment.at(0).at(0)).direction == 2 );
        gameboard.Turn();
        assert( (*gameboard.environment.at(0).at(0)).direction == 1 );
        gameboard.Turn();
        assert( (*gameboard.environment.at(0).at(0)).direction == 0 );
    }

    //Tests Hopper
    //Tests IsWall/hop/Go behavior
    void test_acceptence_2 () {
        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Board gameboard(3,3);
        Creature a(hop,1);
        gameboard.placeCreature(&a,1,1);
        assert(gameboard.environment.at(1).at(1)!=0); 
        gameboard.Turn();
        assert(gameboard.environment.at(1).at(1)==0);
        assert(gameboard.environment.at(0).at(1)!=0); 
        gameboard.Turn();
        assert(gameboard.environment.at(0).at(1)!=0); 

    }

    //Tests Trap
    //Tests infect/ifEnemy/left/go
    void test_acceptence_3 () {
        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Board gameboard(3,3);
        Creature a(trap,1);//Trap facing north
        Creature b(food,0);
        gameboard.placeCreature(&a,1,1);
        gameboard.placeCreature(&b,1,0);//Food west of trap
        assert(gameboard.environment.at(1).at(1)!=0); 
        assert(gameboard.environment.at(1).at(0)!=0); 
        assert( (*gameboard.environment.at(1).at(1)).direction == 1 );
        gameboard.Turn();
        gameboard.Turn();
        assert( (*gameboard.environment.at(1).at(1)).direction == 0 ); //Now trap faces west
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        assert((*gameboard.environment.at(1).at(0)).species == (*gameboard.environment.at(1).at(1)).species); 

    }

    void test_acceptence_4 () {
        //[f . . .] [f . . .] 
        //[. . . .] [. . r .] 
        //[. . r .] [. . . .] 
        //[. . . .] [. . . .] 

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

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

        Board gameboard(4,4);
        srand(0);
        Creature a(rover,1);//Rover facing north
        Creature b(food,0);
        gameboard.placeCreature(&a,2,2);
        gameboard.placeCreature(&b,0,3);//food top right
        gameboard.Turn();
        assert(gameboard.environment.at(1).at(2)!=0);
        gameboard.Turn();
        gameboard.Turn();
        assert(gameboard.environment.at(0).at(2)!=0);
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        assert((*gameboard.environment.at(0).at(3)).species == (*gameboard.environment.at(1).at(2)).species); //Infected
        gameboard.Turn();

    }


    // -----
    // Species
    // -----



    void test_species_constructor_1(){
        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

         assert(food.name == "f");
    }

    void test_species_constructor_2(){
        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

         assert(hop.name == "h");
    }

    void test_species_constructor_3(){
        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        CPPUNIT_ASSERT(trap.name == "t");
        CPPUNIT_ASSERT(trap.program.size()==5);
    }

    void test_species_constructor_4(){
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


        CPPUNIT_ASSERT(rover.name == "r");
        CPPUNIT_ASSERT(rover.program.size()==11);
    }

    void test_species_constructor_5(){
        Species food("f");
        CPPUNIT_ASSERT(food.name == "f");
        CPPUNIT_ASSERT(food.program.size()==0);
    }
    


    // -----
    // Board
    // -----


    void test_If_Empty_1() {
        Board gameboard(4,4);
        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 2);
        gameboard.placeCreature(&a, 2, 2);
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(2) != 0);
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(3) !=0);

    }

    void test_If_Empty_2() {
        Board gameboard(4,4);
        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 2);
        gameboard.placeCreature(&a, 1, 1);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
        CPPUNIT_ASSERT(gameboard.If_Empty(1,1) == false);
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(2) !=0);
    }

    void test_If_Empty_3() {
        Board gameboard(4,4);
        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 2);
        gameboard.placeCreature(&a, 2, 2);
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(2) != 0);
        CPPUNIT_ASSERT(gameboard.If_Empty(2, 2) == false);
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(3) !=0);
        CPPUNIT_ASSERT(gameboard.If_Empty(2, 2) == true);
    }


    void test_If_Wall_1(){
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 3);
        gameboard.placeCreature(&a, 3, 3);
        CPPUNIT_ASSERT(gameboard.If_Wall(4, 4, 3) == true);

    }

    void test_If_Wall_2(){
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 3);
        gameboard.placeCreature(&a, 2, 2);
        CPPUNIT_ASSERT(gameboard.If_Wall(1, 2, 1) == false);

    }

    void test_If_Wall_3(){
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 2);
        gameboard.placeCreature(&a, 1, 2);
        CPPUNIT_ASSERT(gameboard.If_Wall(2, 2, 2) == false);

    }

    void test_If_Enemy_1() {
        Board gameboard(4, 4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

            Creature a(hop, 2);
            gameboard.placeCreature(&a, 1, 2);
            Creature b(trap, 1);
            gameboard.placeCreature(&b, 2, 2);
            CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species != (*gameboard.environment.at(2).at(2)).species);
            CPPUNIT_ASSERT(gameboard.If_Enemy(1,2, b.species->name, b.direction) == true);
        
    }

    void test_If_Enemy_2() {
        Board gameboard(4, 4);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature b(trap, 1);
        gameboard.placeCreature(&b, 2, 2);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(2) == 0);
        CPPUNIT_ASSERT(gameboard.If_Enemy(1,2, b.species->name, b.direction) == false);
        
    }

    void test_If_Enemy_3() {
        Board gameboard(4, 4);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature a(trap, 2);
        gameboard.placeCreature(&a, 1, 2);            
        Creature b(trap, 1);
        gameboard.placeCreature(&b, 2, 2);
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species == (*gameboard.environment.at(2).at(2)).species);           
        CPPUNIT_ASSERT(gameboard.If_Enemy(1,2, b.species->name, b.direction) == false);
        
    }

    void test_infect_1() {
        Board gameboard(4, 4);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature a(food, 2);
        gameboard.placeCreature(&a, 1, 2);
        Creature b(trap, 1);
        gameboard.placeCreature(&b, 2, 2);
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species != (*gameboard.environment.at(2).at(2)).species);            
        CPPUNIT_ASSERT(gameboard.If_Enemy(1,2, b.species->name, b.direction) == true);
        gameboard.Turn();
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species == (*gameboard.environment.at(2).at(2)).species);

    }

    void test_infect_2() {
        Board gameboard(4, 4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature a(hop, 2);
        gameboard.placeCreature(&a, 1, 2);
        Creature b(trap, 1);
        gameboard.placeCreature(&b, 2, 2);
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species != (*gameboard.environment.at(2).at(2)).species);            
        CPPUNIT_ASSERT(gameboard.If_Enemy(1,2, b.species->name, b.direction) == true);
        gameboard.Turn();
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(3)).species != (*gameboard.environment.at(2).at(2)).species);

    }

    void test_infect_3() {
        Board gameboard(4, 4);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature a(trap, 2);
        gameboard.placeCreature(&a, 1, 2);
        Creature b(trap, 1);
        gameboard.placeCreature(&b, 2, 2);
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species == (*gameboard.environment.at(2).at(2)).species);            
        CPPUNIT_ASSERT(gameboard.If_Enemy(1,2, b.species->name, b.direction) == false);
        gameboard.Turn();
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(2)).species == (*gameboard.environment.at(2).at(2)).species);

    }

    void test_hop_1() {
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 3);
        gameboard.placeCreature(&a, 0,1);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) == 0);
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
    }

    void test_hop_2() {
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 3);
        gameboard.placeCreature(&a, 0,1);
        gameboard.Hop(0, 1, 1, 1, 3);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
        CPPUNIT_ASSERT(gameboard.environment.at(0).at(1) == 0);
    }

    void test_hop_3() {
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(hop, 3);
        Creature b(food, 1);
        gameboard.placeCreature(&a, 0,1);
        gameboard.placeCreature(&b, 1, 1);
        Species*  h = (*gameboard.environment.at(0).at(1)).species;
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
        gameboard.Hop(0, 1, 1, 2, 3);
        CPPUNIT_ASSERT((*gameboard.environment.at(1).at(1)).species != h);
    }



    void test_placeCreature_1(){
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 3);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) == 0);
        bool b = gameboard.placeCreature(&a, 1, 1);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
        CPPUNIT_ASSERT(b == true);
    }

    void test_placeCreature_2(){
        Board gameboard(4,4);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop, 3);
        Creature c(food, 2);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) == 0);
        bool b = gameboard.placeCreature(&a, 1, 1);
        bool d = gameboard.placeCreature(&c, 1, 1);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(d == false);
    }


    void test_placeCreature_3(){
        Board gameboard(4,4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(hop, 3);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) == 0);
        bool b = gameboard.placeCreature(&a, 1, 1);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) != 0);
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(1) != 0);
        CPPUNIT_ASSERT(gameboard.environment.at(1).at(1) == 0);
        Creature c(food, 2);
        bool d = gameboard.placeCreature(&c, 1, 1);
        CPPUNIT_ASSERT(d == true);
    }

    void test_placeCreature_4(){
        try{
            Board gameboard(4,4);

            Species food("f");
            food.add_insturction("left", -1);
            food.add_insturction("go", 0);

            Creature a(food, 3);
            gameboard.placeCreature(&a, 4, 4);
        }
        catch(const out_of_range&) {
            CPPUNIT_ASSERT(true);
        }

    }


    void test_turn_1(){
        Board gameboard(8,8);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(food,0);
        gameboard.placeCreature(&a,0,0);
        CPPUNIT_ASSERT(gameboard.environment.at(0).at(0)!=0);
        CPPUNIT_ASSERT( (*gameboard.environment.at(0).at(0)).direction == 0 );
        gameboard.Turn();
        CPPUNIT_ASSERT( (*gameboard.environment.at(0).at(0)).direction == 3 );
        gameboard.Turn();
        CPPUNIT_ASSERT( (*gameboard.environment.at(0).at(0)).direction == 2 );
        gameboard.Turn();
        CPPUNIT_ASSERT( (*gameboard.environment.at(0).at(0)).direction == 1 );
        gameboard.Turn();
        CPPUNIT_ASSERT( (*gameboard.environment.at(0).at(0)).direction == 0 );
    }

    void test_turn_2(){
        Board gameboard(8,8);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature a(hop,3);
        Creature b(trap, 1);
        gameboard.placeCreature(&a,2,3);
        gameboard.placeCreature(&b, 5, 3);
        Species*  infect = (*gameboard.environment.at(5).at(3)).species;
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(3)!=0); 
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(2).at(3)==0);
        CPPUNIT_ASSERT(gameboard.environment.at(3).at(3)!=0);
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.environment.at(3).at(3)==0);
        CPPUNIT_ASSERT(gameboard.environment.at(4).at(3)!=0);
        CPPUNIT_ASSERT((*gameboard.environment.at(4).at(3)).species == infect); 
    }

    void test_turn_3() {
        Board gameboard(8,8);

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

        Creature a(rover, 2);
        Creature b(rover, 0);
        gameboard.placeCreature(&a, 0, 0);
        gameboard.placeCreature(&b, 0, 4);
        gameboard.Turn();//a moves east b moves west
        gameboard.Turn();//a moves east b changes direction
        CPPUNIT_ASSERT((*gameboard.environment.at(0).at(3)).direction != 0 );
    }


    void test_displayBoard_1() {
        Board gameboard(1, 1);
        CPPUNIT_ASSERT(gameboard.environment.size() == 1);
        CPPUNIT_ASSERT(gameboard.environment.at(0).size() == 1);
        CPPUNIT_ASSERT(gameboard.environment.at(0).at(0) == 0);
    }

    void test_displayBoard_2() {
        Board gameboard(8, 8);
        CPPUNIT_ASSERT(gameboard.environment.size() == 8);
        CPPUNIT_ASSERT(gameboard.environment.at(0).size() == 8);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(food,3);
        gameboard.placeCreature(&a, 4, 4);
        CPPUNIT_ASSERT(gameboard.environment.at(4).at(4) != 0);

    }

    void test_displayBoard_3() {
                Board gameboard(20, 20);
        CPPUNIT_ASSERT(gameboard.environment.size() == 20);
        CPPUNIT_ASSERT(gameboard.environment.at(0).size() == 20);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(food,3);
        gameboard.placeCreature(&a, 19, 19);
        CPPUNIT_ASSERT(gameboard.environment.at(19).at(19) != 0);

    }

    void test_board_constructor_1(){
        Board gameboard(8, 8);

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

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(rover, 2);
        Creature b(food, 3);
        gameboard.placeCreature(&a, 0, 0);
        gameboard.placeCreature(&b, 0, 4);
        CPPUNIT_ASSERT(gameboard.turnNumber == 0);
        CPPUNIT_ASSERT(gameboard.environment.size() == 8);
        CPPUNIT_ASSERT((gameboard.environment.at(0)).size() == 8);
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.turnNumber == 1);
    }

    void test_board_constructor_2(){
        Board gameboard(4, 5);

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

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(rover, 2);
        Creature b(food, 3);
        Creature c(trap, 1);
        gameboard.placeCreature(&a, 0, 0);
        gameboard.placeCreature(&b, 0, 2);
        gameboard.placeCreature(&c, 2, 0);
        CPPUNIT_ASSERT(gameboard.turnNumber == 0);
        CPPUNIT_ASSERT(gameboard.environment.size() == 4);
        CPPUNIT_ASSERT((gameboard.environment.at(0)).size() == 5);
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.turnNumber == 5);
    }

    void test_board_constructor_3(){
        Board gameboard(4, 5);
        CPPUNIT_ASSERT(gameboard.turnNumber == 0);
        CPPUNIT_ASSERT(gameboard.environment.size() == 4);
        CPPUNIT_ASSERT((gameboard.environment.at(0)).size() == 5);
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        gameboard.Turn();
        CPPUNIT_ASSERT(gameboard.turnNumber == 5);
    }

    // -----
    // Creature
    // -----

    void test_default_creature_constructor(){
        Creature a;
        CPPUNIT_ASSERT(a.species == 0);
        CPPUNIT_ASSERT(a.direction == 0);
        CPPUNIT_ASSERT(a.pc == 0);
        CPPUNIT_ASSERT(a.turnCount == 0);
    }

    void test_creature_constructor_1(){

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(food,0);
        CPPUNIT_ASSERT(a.species != 0);
        CPPUNIT_ASSERT(a.direction == 0);
        CPPUNIT_ASSERT(a.pc == 0);
        CPPUNIT_ASSERT(a.turnCount == 0);

    }
    void test_creature_constructor_2(){
        Board gameboard(4, 4);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);

        Creature a(trap,0);
        CPPUNIT_ASSERT(a.species != 0);
        CPPUNIT_ASSERT(a.direction == 0);
        CPPUNIT_ASSERT(a.pc == 0);
        CPPUNIT_ASSERT(a.turnCount == 0);
        gameboard.placeCreature(&a,0,0);
        gameboard.Turn();
        CPPUNIT_ASSERT(a.direction == 3);
        CPPUNIT_ASSERT(a.pc == 2);
        CPPUNIT_ASSERT(a.turnCount == 1);
        gameboard.Turn();
        CPPUNIT_ASSERT(a.direction == 2);
        CPPUNIT_ASSERT(a.pc == 2);
        CPPUNIT_ASSERT(a.turnCount == 2);

    }
    void test_creature_constructor_3(){
        Board gameboard(8, 8);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop,0);
        CPPUNIT_ASSERT(a.species != 0);
        CPPUNIT_ASSERT(a.direction == 0);
        CPPUNIT_ASSERT(a.pc == 0);
        CPPUNIT_ASSERT(a.turnCount == 0);
        gameboard.placeCreature(&a,0,0);
        gameboard.Turn();
        CPPUNIT_ASSERT(a.direction == 0);
        CPPUNIT_ASSERT(a.pc == 1);
        CPPUNIT_ASSERT(a.turnCount == 1);
    }

    void test_move_1(){
        Board gameboard(4, 4);

        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        Creature a(food,0);
        gameboard.placeCreature(&a,0,0);
        CPPUNIT_ASSERT(a.pc == 0);
        a.move(gameboard, 0, 0);
        CPPUNIT_ASSERT(a.direction == 3);
        


    }
    void test_move_2(){
        Board gameboard(4, 4);

        Species hop("h");
        hop.add_insturction("hop", -1);
        hop.add_insturction("go", 0);

        Creature a(hop,0);
        gameboard.placeCreature(&a,0,0);
        CPPUNIT_ASSERT(a.pc == 0);
        a.move(gameboard, 0, 0);
        CPPUNIT_ASSERT(a.direction == 0);


    }
    void test_move_3(){
        Board gameboard(4, 4);

        Species trap("t");
        trap.add_insturction("if_enemy", 3);
        trap.add_insturction("left", -1);
        trap.add_insturction("go", 0);
        trap.add_insturction("infect", -1);
        trap.add_insturction("go", 0);


        Creature a(trap,0);
        gameboard.placeCreature(&a,0,0);
        CPPUNIT_ASSERT(a.pc == 0);
        CPPUNIT_ASSERT(a.direction == 0);
        a.move(gameboard, 0, 0);
        CPPUNIT_ASSERT(a.direction == 3);
    }

    void test_add_instruction_1(){
        Species food("f");
        food.add_insturction("left", -1);
        food.add_insturction("go", 0);

        CPPUNIT_ASSERT(food.program.size() ==2);
        CPPUNIT_ASSERT(food.program.at(0).first == "left");
        CPPUNIT_ASSERT(food.program.at(0).second == -1);
    }

    void test_add_instruction_2(){
        Species food("f");
        CPPUNIT_ASSERT(food.program.size() ==0);
    }

    void test_add_instruction_3(){
        Species food("f");
        food.add_insturction("right", -1); //right not left
        CPPUNIT_ASSERT(food.program.size() ==1);
        CPPUNIT_ASSERT(food.program.at(0).first == "right");
    }



    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_acceptence_1);
    CPPUNIT_TEST(test_acceptence_2);
    CPPUNIT_TEST(test_acceptence_3);
    CPPUNIT_TEST(test_acceptence_4);
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_constructor_2);
    CPPUNIT_TEST(test_species_constructor_3);
    CPPUNIT_TEST(test_species_constructor_4);
    CPPUNIT_TEST(test_species_constructor_5);

    CPPUNIT_TEST(test_If_Empty_1);
    CPPUNIT_TEST(test_If_Empty_2);
    CPPUNIT_TEST(test_If_Empty_3);
    CPPUNIT_TEST(test_If_Wall_1);
    CPPUNIT_TEST(test_If_Wall_2);
    CPPUNIT_TEST(test_If_Wall_3);
    CPPUNIT_TEST(test_If_Enemy_1);
    CPPUNIT_TEST(test_If_Enemy_2);
    CPPUNIT_TEST(test_If_Enemy_3);
    CPPUNIT_TEST(test_infect_1);
    CPPUNIT_TEST(test_infect_2);
    CPPUNIT_TEST(test_infect_3);
    CPPUNIT_TEST(test_hop_1);
    CPPUNIT_TEST(test_hop_2);
    CPPUNIT_TEST(test_hop_3);
    CPPUNIT_TEST(test_placeCreature_1);
    CPPUNIT_TEST(test_placeCreature_2);
    CPPUNIT_TEST(test_placeCreature_3);
    CPPUNIT_TEST(test_placeCreature_4);
    CPPUNIT_TEST(test_turn_1);
    CPPUNIT_TEST(test_turn_2);
    CPPUNIT_TEST(test_turn_3);
    CPPUNIT_TEST(test_displayBoard_1);
    CPPUNIT_TEST(test_displayBoard_2);
    CPPUNIT_TEST(test_displayBoard_3);
    CPPUNIT_TEST(test_board_constructor_1);
    CPPUNIT_TEST(test_board_constructor_2);
    CPPUNIT_TEST(test_board_constructor_3);
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_default_creature_constructor);
    CPPUNIT_TEST(test_move_1);
    CPPUNIT_TEST(test_move_2);
    CPPUNIT_TEST(test_move_3); 
    CPPUNIT_TEST(test_add_instruction_1);
    CPPUNIT_TEST(test_add_instruction_2);
    CPPUNIT_TEST(test_add_instruction_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
