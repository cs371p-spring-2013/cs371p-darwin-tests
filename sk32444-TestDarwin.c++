// --------------------------------
// 
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin.c++.app -lcppunit -ldl
    % valgrind TestDarwin.c++.app >& TestDarwin.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector>
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private   public
#define protected public
#define class     struct

#include "Darwin.h"


// -----------
// TestDarwin
// -----------
static vector<pair<int,int> > food;
static vector<pair<int,int> > hopper;
static vector<pair<int,int> > trap;
static vector<pair<int,int> > rover;
static vector<Species> all_species;

struct TestDarwin: CppUnit::TestFixture {

    void test_species_constructor_1(){
        Species hopper_species('h', hopper);
        CPPUNIT_ASSERT(hopper_species._name == 'h');
    }

    void test_species_constructor_2(){
        Species trap_species('t', trap);
        CPPUNIT_ASSERT(trap_species._name == 't');
        CPPUNIT_ASSERT(sizeof(trap_species) == sizeof(Species));
    }

    void test_species_constructor_3(){
        Species rover_species('r', rover);
        CPPUNIT_ASSERT(rover_species._name == 'r');
        CPPUNIT_ASSERT(sizeof(rover_species) == sizeof(Species));
    }

    void test_species_get_instruction_at_1(){
        Species hopper_species('h', hopper);
        pair<int,int> i = hopper_species.get_instruction_at(0);
        CPPUNIT_ASSERT(i.first == 0);
        CPPUNIT_ASSERT(i.second == 0);
        i = hopper_species.get_instruction_at(1);
        CPPUNIT_ASSERT(hopper_species._instructions[1].first  == 8);
        CPPUNIT_ASSERT(hopper_species._instructions[1].second == 0);
    }

    void test_species_get_instruction_at_2(){
        Species trap_species('t', trap);
        pair<int,int> i = trap_species.get_instruction_at(0);
        CPPUNIT_ASSERT(i.first  == 7);
        CPPUNIT_ASSERT(i.second == 3);
        i = trap_species.get_instruction_at(3);
        CPPUNIT_ASSERT(i.first  == 3);
        CPPUNIT_ASSERT(i.second == 0);
    }

    void test_species_get_instruction_at_3(){
        Species rover_species('r', rover);
        rover_species.get_instruction_at(2);
        CPPUNIT_ASSERT(rover_species._instructions[2].first  == 6);
        CPPUNIT_ASSERT(rover_species._instructions[2].second == 5);
    }

    void test_species_print_name_1(){        
        Species hopper_species('h', hopper);
        std::ostringstream w;
        hopper_species.print_name(w);
        CPPUNIT_ASSERT(w.str() == "h");
    }

    void test_species_print_name_2(){
        Species trap_species('t', trap);
        std::ostringstream w;
        trap_species.print_name(w);
        CPPUNIT_ASSERT(w.str() == "t");    
    }

    void test_species_print_name_3(){
        Species rover_species('r', rover);
        std::ostringstream w;
        rover_species.print_name(w);
        CPPUNIT_ASSERT(w.str() == "r");    
    }

    void test_species_same_species_1(){
       Species hopper_species_1('h', hopper);
       Species hopper_species_2('h', hopper);
       CPPUNIT_ASSERT(hopper_species_1.same_species(hopper_species_2));

    }

    void test_species_same_species_2(){
        Species trap_species_1('t', trap);
        Species trap_species_2('t', trap);
        CPPUNIT_ASSERT(trap_species_1.same_species(trap_species_2));
    }

    void test_species_same_species_3(){
        Species rover_species('r', rover);
        Species trap_species('t', trap);
        CPPUNIT_ASSERT(!(rover_species.same_species(trap_species)));
    }

    // Begin Creature Testing
    void test_creature_constructor_1(){
        Species hopper_species('h', hopper);
        Creature creature(&hopper_species);
        CPPUNIT_ASSERT(creature._program_counter == 0);
        CPPUNIT_ASSERT(creature._species->same_species(hopper_species));
    }

    void test_creature_constructor_2(){
        Species trap_species('t', trap);
        Creature creature(&trap_species);
        CPPUNIT_ASSERT(creature._species->same_species(trap_species));
        CPPUNIT_ASSERT(sizeof(creature) == sizeof(Creature));
    }

    void test_creature_constructor_3(){
        Species rover_species('r', rover);
        Creature creature(&rover_species);
        CPPUNIT_ASSERT(creature._program_counter == 0);        
        CPPUNIT_ASSERT(creature._species->same_species(rover_species));
        CPPUNIT_ASSERT(sizeof(creature) == sizeof(Creature));
    }

    void test_creature_next_instruction_1(){
        Species hopper_species('h', hopper);
        Creature creature(&hopper_species);
        CPPUNIT_ASSERT(creature.next_instruction() == 0);
    }

    void test_creature_next_instruction_2(){
        Species trap_species('t', trap);
        Creature creature(&trap_species);
        CPPUNIT_ASSERT(creature.next_instruction() == 7);    
    }

    void test_creature_next_instruction_3(){
        Species rover_species('r', rover);
        Creature creature(&rover_species);
        creature._program_counter = 2;
        CPPUNIT_ASSERT(creature.next_instruction() == 6);
    }

    void test_creature_receive_reply_1(){
        Species hopper_species('h', hopper);
        Creature creature(&hopper_species);
        creature._program_counter = 1; 
        creature.receive_reply(true);
        CPPUNIT_ASSERT(creature._program_counter == 0);
    }

    void test_creature_receive_reply_2(){
        Species trap_species('t', trap);
        Creature creature(&trap_species);
        creature._program_counter = 3;
        creature.receive_reply(false);
        CPPUNIT_ASSERT(creature._program_counter == 4);   
    }

    void test_creature_receive_reply_3(){
        Species rover_species('r', rover);
        Creature creature(&rover_species);
        creature._program_counter = 0;
        creature.receive_reply(true);
        CPPUNIT_ASSERT(creature._program_counter == 9);
    }

    void test_creature_print_species_name_1(){
        Species hopper_species('h', hopper);
        Creature creature(&hopper_species);
        std::ostringstream w;
        creature.print_species_name(w);
        CPPUNIT_ASSERT(w.str() == "h");
    }

    void test_creature_print_species_name_2(){
        Species trap_species('t', trap);
        Creature creature(&trap_species);
        std::ostringstream w;
        creature.print_species_name(w);
        CPPUNIT_ASSERT(w.str() == "t");
    }

    void test_creature_print_species_name_3(){
        Species rover_species('r', rover);
        Creature creature(&rover_species);
        std::ostringstream w;
        creature.print_species_name(w);
        CPPUNIT_ASSERT(w.str() != "h");
    }

    void test_creature_same_species_1(){
        Species hopper_species('h', hopper);
        Creature creature_1(&hopper_species);
        Creature creature_2(&hopper_species);
        CPPUNIT_ASSERT(creature_1.same_species(creature_2));
        
    }

    void test_creature_same_species_2(){
        Species trap_species('t', trap);
        Creature creature_1(&trap_species);
        Creature creature_2(&trap_species);
        CPPUNIT_ASSERT(creature_1.same_species(creature_2));
    }

    void test_creature_same_species_3(){
        Species rover_species('r', rover);
        Creature creature_1(&rover_species);
        Species hopper_species('h', hopper);
        Creature creature_2(&hopper_species);
        CPPUNIT_ASSERT(! (creature_1.same_species(creature_2)));
    }

    void test_creature_of_species_1(){
        Species hopper_species('h', hopper);
        Creature creature(&hopper_species);
        CPPUNIT_ASSERT(creature.of_species(hopper_species));
        
    }

    void test_creature_of_species_2(){
        Species trap_species('t', trap);
        Creature creature_1(&trap_species);
        CPPUNIT_ASSERT(creature_1.of_species(trap_species));
    }

    void test_creature_of_species_3(){
        Species rover_species('r', rover);
        Creature creature(&rover_species);
        Species trap_species('t', trap);

        CPPUNIT_ASSERT(! (creature.of_species(trap_species)));
    }

    // Begin testing of the World
    void test_world_constructor_1(){
        World world(8, 8, all_species);
        CPPUNIT_ASSERT(world._length == 8);
        CPPUNIT_ASSERT(world._width == 8);
        CPPUNIT_ASSERT(world._grid[0][0] == 0);
    }

    void test_world_constructor_2(){
        World world(3, 7, all_species);
        CPPUNIT_ASSERT(world._species.size() == 4);
        CPPUNIT_ASSERT(world._width != 10);
        CPPUNIT_ASSERT(world._grid[0][0] == 0);        
    }

    void test_world_constructor_3(){
        World world(72, 72, all_species);
        CPPUNIT_ASSERT(world._species.size() == 4);
        CPPUNIT_ASSERT(world._width == 72);
        CPPUNIT_ASSERT(world._length == 72);
        CPPUNIT_ASSERT(world._grid[0][0] == 0);
    }

    void test_world_place_1(){
        World world(8, 8, all_species);
        world.place(1, NORTH, 0, 0);
        CPPUNIT_ASSERT(world._grid[0][0]->creature._species->_name == 'h');
    }

    void test_world_place_2(){
        World world(8, 8, all_species);
        world.place(0, EAST, 5, 1);
        world.place(0, NORTH, 7, 7);
        CPPUNIT_ASSERT(world._grid[5][1]->creature._species->_name == 'f');
        CPPUNIT_ASSERT(world._grid[7][7]->creature._species->_name == 'f');
    }

    void test_world_place_3(){
        World world(72, 72, all_species);
        world.place(0, EAST, 5, 1);
        world.place(2, NORTH, 60, 10);
        CPPUNIT_ASSERT(world._grid[5][1]->creature._species->_name = 'f');
        CPPUNIT_ASSERT(!(world._grid[60][10]->creature._species->_name == 'f'));
    }

    void test_world_box_in_front_1(){
        World world(5, 5, all_species);
        world.place(1, WEST, 4, 1);
        Box* b = world.box_in_front(world._grid[4][1]);
        CPPUNIT_ASSERT(b == NULL);
    }

    void test_world_box_in_front_2(){
        World world(5, 5, all_species);
        world.place(1, NORTH, 4, 1);
        world.place(1, NORTH, 3, 1);
        Box* b = world.box_in_front(world._grid[4][1]);
        CPPUNIT_ASSERT(b->x_pos == 3);
        CPPUNIT_ASSERT(b->y_pos == 1);
        CPPUNIT_ASSERT(b->direction == NORTH);
        CPPUNIT_ASSERT(b->creature.same_species(world._grid[4][1]->creature));
    }

    void test_world_box_in_front_3(){
        World world(5, 5, all_species);
        world.place(1, NORTH, 4, 1);
        world.place(0, EAST,  3, 1);
        Box* b = world.box_in_front(world._grid[4][1]);
        CPPUNIT_ASSERT(b->x_pos == 3);
        CPPUNIT_ASSERT(b->y_pos == 1);
        CPPUNIT_ASSERT(b->direction == EAST);
        CPPUNIT_ASSERT(! (b->creature.same_species(world._grid[4][1]->creature)));
    }

    
    void test_world_make_creature_hop_1(){
        World world(5, 5, all_species);
        world.place(2, WEST, 4, 1);
        world.make_creature_hop(world._grid[4][1]);
        CPPUNIT_ASSERT(world._grid[4][1] == NULL);
        CPPUNIT_ASSERT(world._grid[4][0]->x_pos == 4);
        CPPUNIT_ASSERT(world._grid[4][0]->y_pos == 0);
        CPPUNIT_ASSERT(world._grid[4][0]->direction == WEST); 
        Species s = Species('r', rover);       
        CPPUNIT_ASSERT(world._grid[4][0]->creature.of_species(s));
    }

    void test_world_make_creature_hop_2(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        world.make_creature_hop(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2] == NULL);
        CPPUNIT_ASSERT(world._grid[2][1] != NULL);
        CPPUNIT_ASSERT(world._grid[2][3] == NULL);
        CPPUNIT_ASSERT(world._grid[1][2] == NULL);        
        CPPUNIT_ASSERT(world._grid[3][2] == NULL);
    }

    void test_world_make_creature_hop_3(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        world.make_creature_hop(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2] == NULL);
        CPPUNIT_ASSERT(world._grid[2][1] != NULL);
        CPPUNIT_ASSERT(world._grid[2][1]->x_pos == 2);
        CPPUNIT_ASSERT(world._grid[2][1]->y_pos == 1);
        CPPUNIT_ASSERT(world._grid[2][1]->direction == WEST);
        Species s = Species('r', rover);            
        CPPUNIT_ASSERT(world._grid[2][1]->creature.of_species(s));
    }

    void test_world_turn_left_1(){
        World world(5,5, all_species);
        world.place(2, WEST, 2, 2);
        world.turn_left(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->direction != NORTH);
        CPPUNIT_ASSERT(world._grid[2][2]->direction == SOUTH);
    }

    void test_world_turn_left_2(){
        World world(5,5, all_species);
        world.place(2, EAST, 2, 2);
        world.turn_left(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->direction != SOUTH);
        CPPUNIT_ASSERT(world._grid[2][2]->direction == NORTH);
    }

    void test_world_turn_left_3(){
        World world(5,5, all_species);
        world.place(2, SOUTH, 2, 2);
        world.turn_left(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->direction != WEST);
        CPPUNIT_ASSERT(world._grid[2][2]->direction == EAST);
    }

    void test_world_turn_right_1(){
        World world(5,5, all_species);
        world.place(2, WEST, 2, 2);
        world.turn_right(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->direction != SOUTH);
        CPPUNIT_ASSERT(world._grid[2][2]->direction == NORTH);
    }

    void test_world_turn_right_2(){
        World world(5,5, all_species);
        world.place(2, EAST, 2, 2);
        world.turn_right(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->direction != NORTH);
        CPPUNIT_ASSERT(world._grid[2][2]->direction == SOUTH);
    }

    void test_world_turn_right_3(){
        World world(5,5, all_species);
        world.place(2, SOUTH, 2, 2);
        world.turn_right(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->direction != EAST);
        CPPUNIT_ASSERT(world._grid[2][2]->direction == WEST);
    }

    void test_world_infect_creature_in_front_1(){
        World world(5, 5, all_species);
        world.place(2, WEST, 4, 1);
        world.infect_creature_in_front(world._grid[4][1]);
        CPPUNIT_ASSERT(world._grid[4][0] == NULL);
    }

    void test_world_infect_creature_in_front_2(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        world.place(2, WEST, 2, 1);
        Species s = Species('r', rover);            
        CPPUNIT_ASSERT(world._grid[2][2]->creature.of_species(s));
        CPPUNIT_ASSERT(world._grid[2][1]->creature.of_species(s));
        world.infect_creature_in_front(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->creature.of_species(s));
        CPPUNIT_ASSERT(world._grid[2][1]->creature.of_species(s));
    }

    void test_world_infect_creature_in_front_3(){
        World world(5, 5, all_species);
        world.place(2, WEST,  2, 2);
        world.place(1, NORTH, 2 ,1);
        Species s1 = Species('h', hopper); 
        Species s2 = Species('r', rover); 
        CPPUNIT_ASSERT(world._grid[2][2]->creature.of_species(s2));
        CPPUNIT_ASSERT(world._grid[2][1]->creature.of_species(s1));
        world.infect_creature_in_front(world._grid[2][2]);
        CPPUNIT_ASSERT(world._grid[2][2]->creature.of_species(s2));
        CPPUNIT_ASSERT(world._grid[2][1]->creature.of_species(s2));
    }

    void test_world_box_in_front_empty_1(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        CPPUNIT_ASSERT(world.box_in_front_empty(world._grid[2][2]));
    }

    void test_world_box_in_front_empty_2(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        world.place(1, WEST, 2, 1);
        CPPUNIT_ASSERT(!world.box_in_front_empty(world._grid[2][2]));
    }

    void test_world_box_in_front_empty_3(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        world.place(1, WEST, 1, 1);
        world.place(1, WEST, 1, 2);
        world.place(1, WEST, 1, 3);        
        world.place(1, WEST, 3, 1);
        world.place(1, WEST, 3, 2);
        world.place(1, WEST, 3, 3);
        world.place(1, WEST, 2, 3);
        CPPUNIT_ASSERT(world.box_in_front_empty(world._grid[2][2]));
    }

    void test_world_wall_in_front_1(){
        World world(3, 3, all_species);
        world.place(1, NORTH, 0, 0);
        world.place(1, NORTH, 0, 1);
        world.place(1, NORTH, 0, 2);
        world.place(1, SOUTH, 2, 0);
        world.place(1, SOUTH, 2, 1);
        world.place(1, SOUTH, 2, 2);
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[0][0]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[0][1]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[0][2]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[2][0]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[2][1]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[2][2]));
    }

    void test_world_wall_in_front_2(){
        World world(3, 3, all_species);
        world.place(1, EAST, 0, 2);
        world.place(1, EAST, 1, 2);
        world.place(1, EAST, 2, 2);
        world.place(1, WEST, 0, 0);
        world.place(1, WEST, 1, 0);
        world.place(1, WEST, 2, 0);
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[0][2]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[1][2]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[2][2]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[0][0]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[1][0]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[2][0]));
    }

    void test_world_wall_in_front_3(){
        World world(3, 3, all_species);
        world.place(1, NORTH, 0, 2);
        world.place(1, WEST,  1, 2);
        world.place(1, SOUTH, 2, 2);
        world.place(1, EAST,  0, 0);
        world.place(1, SOUTH, 1, 0);
        world.place(1, NORTH, 2, 0);
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[0][2]));
        CPPUNIT_ASSERT(!world.wall_in_front(world._grid[1][2]));
        CPPUNIT_ASSERT(world.wall_in_front(world._grid[2][2]));
        CPPUNIT_ASSERT(!world.wall_in_front(world._grid[0][0]));
        CPPUNIT_ASSERT(!world.wall_in_front(world._grid[1][0]));
        CPPUNIT_ASSERT(!world.wall_in_front(world._grid[2][0]));
    }

    void test_world_is_random_odd_1(){
        World world(3, 3, all_species);
        srand(0);
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(!world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
    }

    void test_world_is_random_odd_2(){
        World world(4, 9, all_species);
        srand(0);
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(!world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(!world.is_random_odd());
        CPPUNIT_ASSERT(!world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
    }

    void test_world_is_random_odd_3(){
        World world(1, 3, all_species);
        world.place(1, WEST, 0, 0);
        world.place(1, WEST, 0, 1);
        world.place(1, WEST, 0, 2);
        srand(0);
        CPPUNIT_ASSERT(world.is_random_odd());
        CPPUNIT_ASSERT(!world.is_random_odd());
        CPPUNIT_ASSERT(world.is_random_odd());
    }

    void test_world_enemy_in_front_1(){
        World world(5, 5, all_species);
        world.place(2, WEST, 4, 1);
        CPPUNIT_ASSERT(!world.enemy_in_front(world._grid[4][1]));
    }

    void  test_world_enemy_in_front_2(){
        World world(5, 5, all_species);
        world.place(2, WEST, 2, 2);
        world.place(2, EAST, 2, 1);
        Species s = Species('r', rover);            
        CPPUNIT_ASSERT(!world.enemy_in_front(world._grid[2][2]));
        CPPUNIT_ASSERT(!world.enemy_in_front(world._grid[2][1]));
    }

    void test_world_enemy_in_front_3(){
        World world(5, 5, all_species);
        world.place(2, WEST,  2, 2);
        world.place(1, EAST, 2 ,1);
        Species s1 = Species('h', hopper); 
        Species s2 = Species('r', rover); 
        CPPUNIT_ASSERT(world._grid[2][2]->creature.of_species(s2));
        CPPUNIT_ASSERT(world._grid[2][1]->creature.of_species(s1));
        CPPUNIT_ASSERT(world.enemy_in_front(world._grid[2][2]));
        CPPUNIT_ASSERT(world.enemy_in_front(world._grid[2][1]));
        world.infect_creature_in_front(world._grid[2][2]);
        CPPUNIT_ASSERT(!world.enemy_in_front(world._grid[2][2]));
        CPPUNIT_ASSERT(!world.enemy_in_front(world._grid[2][1]));
    }

    void test_world_print_grid_1(){
        World world(5, 5, all_species);
        std::ostringstream w;
        world.print_grid(0, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    }

    void test_world_print_grid_2(){
        World world(3, 3, all_species);
        world.place(1, NORTH, 0, 2);
        world.place(1, WEST,  1, 2);
        world.place(1, SOUTH, 2, 2);
        world.place(1, EAST,  0, 0);
        world.place(1, SOUTH, 1, 0);
        world.place(1, NORTH, 2, 0);
        std::ostringstream w;
        world.print_grid(0, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 h.h\n1 h.h\n2 h.h\n\n");
    }
    void test_world_print_grid_3(){
        World world(3, 3, all_species);
        world.place(2, NORTH, 0, 0);
        world.place(2, NORTH, 0, 1);
        world.place(2, NORTH, 0, 2);
        world.place(2, SOUTH, 2, 0);
        world.place(2, SOUTH, 2, 1);
        world.place(2, SOUTH, 2, 2);
        std::ostringstream w;
        world.print_grid(0, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 rrr\n1 ...\n2 rrr\n\n");
    }

    void test_world_simulate_1(){
        World world(3, 3, all_species);
        world.place(1, NORTH, 0, 0);
        world.place(1, NORTH, 0, 1);
        world.place(1, NORTH, 0, 2);
        world.place(1, SOUTH, 2, 0);
        world.place(1, SOUTH, 2, 1);
        world.place(1, SOUTH, 2, 2);
        std::ostringstream w;
        world.simulate(2, 1, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 hhh\n1 ...\n2 hhh\n\nTurn = 1.\n  012\n0 hhh\n1 ...\n2 hhh\n\nTurn = 2.\n  012\n0 hhh\n1 ...\n2 hhh\n\n");
    }

    void test_world_simulate_2(){
        World world(3, 3, all_species);
        world.place(1, SOUTH, 0, 0);
        world.place(1, SOUTH, 0, 1);
        world.place(1, SOUTH, 0, 2);
        world.place(1, NORTH, 2, 0);
        world.place(1, NORTH, 2, 1);
        world.place(1, NORTH, 2, 2);
        std::ostringstream w;
        world.simulate(2, 1, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 hhh\n1 ...\n2 hhh\n\nTurn = 1.\n  012\n0 ...\n1 hhh\n2 hhh\n\nTurn = 2.\n  012\n0 ...\n1 hhh\n2 hhh\n\n");
    }

    void test_world_simulate_3(){
        World world(3, 3, all_species);
        world.place(1, SOUTH, 0, 0);
        world.place(1, SOUTH, 0, 1);
        world.place(1, SOUTH, 0, 2);
        std::ostringstream w;
        world.simulate(2, 1, w);
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n  012\n0 hhh\n1 ...\n2 ...\n\nTurn = 1.\n  012\n0 ...\n1 hhh\n2 ...\n\nTurn = 2.\n  012\n0 ...\n1 ...\n2 hhh\n\n");
    }
    // -----
    // suite
    // -----
     
    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_constructor_2);
    CPPUNIT_TEST(test_species_constructor_3);

    CPPUNIT_TEST(test_species_get_instruction_at_1);
    CPPUNIT_TEST(test_species_get_instruction_at_2);
    CPPUNIT_TEST(test_species_get_instruction_at_3);

    CPPUNIT_TEST(test_species_print_name_1);
    CPPUNIT_TEST(test_species_print_name_2);
    CPPUNIT_TEST(test_species_print_name_3);

    CPPUNIT_TEST(test_species_same_species_1);
    CPPUNIT_TEST(test_species_same_species_2);
    CPPUNIT_TEST(test_species_same_species_3);

    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);

    CPPUNIT_TEST(test_creature_next_instruction_1);
    CPPUNIT_TEST(test_creature_next_instruction_2);
    CPPUNIT_TEST(test_creature_next_instruction_3);

    CPPUNIT_TEST(test_creature_receive_reply_1);
    CPPUNIT_TEST(test_creature_receive_reply_2);
    CPPUNIT_TEST(test_creature_receive_reply_3);

    CPPUNIT_TEST(test_creature_print_species_name_1);
    CPPUNIT_TEST(test_creature_print_species_name_2);
    CPPUNIT_TEST(test_creature_print_species_name_3);

    CPPUNIT_TEST(test_creature_same_species_1);
    CPPUNIT_TEST(test_creature_same_species_2);
    CPPUNIT_TEST(test_creature_same_species_3);

    CPPUNIT_TEST(test_creature_of_species_1);
    CPPUNIT_TEST(test_creature_of_species_2);
    CPPUNIT_TEST(test_creature_of_species_3);

    CPPUNIT_TEST(test_world_constructor_1);
    CPPUNIT_TEST(test_world_constructor_2);
    CPPUNIT_TEST(test_world_constructor_3);

    CPPUNIT_TEST(test_world_place_1);
    CPPUNIT_TEST(test_world_place_2);    
    CPPUNIT_TEST(test_world_place_3);

    CPPUNIT_TEST(test_world_box_in_front_1);
    CPPUNIT_TEST(test_world_box_in_front_2);
    CPPUNIT_TEST(test_world_box_in_front_3);

    CPPUNIT_TEST(test_world_make_creature_hop_1);
    CPPUNIT_TEST(test_world_make_creature_hop_2);
    CPPUNIT_TEST(test_world_make_creature_hop_3);

    CPPUNIT_TEST(test_world_turn_left_1);
    CPPUNIT_TEST(test_world_turn_left_2);
    CPPUNIT_TEST(test_world_turn_left_3);

    CPPUNIT_TEST(test_world_turn_right_1);
    CPPUNIT_TEST(test_world_turn_right_2);
    CPPUNIT_TEST(test_world_turn_right_3);

    CPPUNIT_TEST(test_world_infect_creature_in_front_1);
    CPPUNIT_TEST(test_world_infect_creature_in_front_2);
    CPPUNIT_TEST(test_world_infect_creature_in_front_3);

    CPPUNIT_TEST(test_world_box_in_front_empty_1);
    CPPUNIT_TEST(test_world_box_in_front_empty_2);
    CPPUNIT_TEST(test_world_box_in_front_empty_3);

    CPPUNIT_TEST(test_world_wall_in_front_1);
    CPPUNIT_TEST(test_world_wall_in_front_2);
    CPPUNIT_TEST(test_world_wall_in_front_3);

    CPPUNIT_TEST(test_world_is_random_odd_1);
    CPPUNIT_TEST(test_world_is_random_odd_2);
    CPPUNIT_TEST(test_world_is_random_odd_3);

    CPPUNIT_TEST(test_world_enemy_in_front_1);
    CPPUNIT_TEST(test_world_enemy_in_front_2);
    CPPUNIT_TEST(test_world_enemy_in_front_3);

    CPPUNIT_TEST(test_world_print_grid_1);
    CPPUNIT_TEST(test_world_print_grid_2);
    CPPUNIT_TEST(test_world_print_grid_3);

    CPPUNIT_TEST(test_world_simulate_1);
    CPPUNIT_TEST(test_world_simulate_2);
    CPPUNIT_TEST(test_world_simulate_3);

    CPPUNIT_TEST_SUITE_END();
    };

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    food.push_back(make_pair(1,0));
    food.push_back(make_pair(8,0));

    hopper.push_back(make_pair(0,0));
    hopper.push_back(make_pair(8,0));

    trap.push_back(make_pair(7,3));
    trap.push_back(make_pair(1,0));
    trap.push_back(make_pair(8,0));
    trap.push_back(make_pair(3,0));
    trap.push_back(make_pair(8,0));

    rover.push_back(make_pair(7,9));
    rover.push_back(make_pair(4,7));
    rover.push_back(make_pair(6,5));
    rover.push_back(make_pair(1,0));
    rover.push_back(make_pair(8,0));
    rover.push_back(make_pair(2,0));
    rover.push_back(make_pair(8,0));
    rover.push_back(make_pair(0,0));
    rover.push_back(make_pair(8,0));
    rover.push_back(make_pair(3,0));
    rover.push_back(make_pair(8,0));

    all_species.push_back(Species('f', food));      // 0
    all_species.push_back(Species('h', hopper));    // 1
    all_species.push_back(Species('r', rover));     // 2
    all_species.push_back(Species('t', trap));      // 3

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
