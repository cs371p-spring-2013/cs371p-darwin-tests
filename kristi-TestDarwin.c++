// --------
// includes
// --------


#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <ostream>
#include <vector>


#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"
#include "Darwin.h"

#define private public
#define protected public


// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {
    // ----
    // convert_to_point
    void test_convert_to_point_1() {
        int x = 0, y = -1;
        vector<int> point = convert_to_point(x, y);
        
        CPPUNIT_ASSERT(point[0] == x && point[1] == y);
    }
    void test_convert_to_point_2() {
        int x = 110000, y = -10000;
        vector<int> point = convert_to_point(x, y);
        
        CPPUNIT_ASSERT(point[0] == x && point[1] == y);
    }
    void test_convert_to_point_3() {
        int x = -1, y = 0;
        vector<int> point = convert_to_point(x, y);
        
        CPPUNIT_ASSERT(point[0] == x && point[1] == y);
    }
    
    
    // ----
    // Creature_Programs
    // ----
    
    // ----
    // add_program
    void test_creature_programs_add_program_1() {
        Creature_Programs programs;
        
        vector<string> prog(4, "test");
        char token = 't';
        int species = programs.add_program(prog, token);
        
        CPPUNIT_ASSERT(species == 0);
        CPPUNIT_ASSERT(programs.species_token[0] == token);
        CPPUNIT_ASSERT(programs.species_offset[0] == 0);
        for (int i = 0; i < 4; ++i) {
            CPPUNIT_ASSERT(programs.programs[i] == prog[i]);
        }
    }
    void test_creature_programs_add_program_2() {
        Creature_Programs programs;
        
        vector<string> prog1(4, "test");
        char token1 = 't';
        int species1 = programs.add_program(prog1, token1);
        
        vector<string> prog2(6, "test2");
        char token2 = 's';
        int species2 = programs.add_program(prog2, token2);
        
        CPPUNIT_ASSERT(species1 == 0);
        CPPUNIT_ASSERT(programs.species_token[0] == token1);
        CPPUNIT_ASSERT(programs.species_offset[0] == 0);
        for (int i = 0; i < 4; ++i) {
            CPPUNIT_ASSERT(programs.programs[i] == prog1[i]);
        }
        
        int offset2 = programs.species_offset[1];
        CPPUNIT_ASSERT(species2 == 1);
        CPPUNIT_ASSERT(programs.species_token[1] == token2);
        CPPUNIT_ASSERT(offset2 == 4);
        for (int i = 0; i < 6; ++i) {
            CPPUNIT_ASSERT(programs.programs[i + offset2] == prog2[i]);
        }
    }
    void test_creature_programs_add_program_3() {
        Creature_Programs programs;
        
        vector<string> prog1;
        prog1.push_back("add0");
        prog1.push_back("add1");
        prog1.push_back("add2");
        prog1.push_back("add3");
        prog1.push_back("add4");
        char token1 = 't';
        int species1 = programs.add_program(prog1, token1);
        vector<string> prog2(6, "test2");
        char token2 = 's';
        int species2 = programs.add_program(prog2, token2);
        
        CPPUNIT_ASSERT(species1 == 0);
        CPPUNIT_ASSERT(programs.species_token[0] == token1);
        CPPUNIT_ASSERT(programs.species_offset[0] == 0);
        for (int i = 0; i < 5; ++i) {
            CPPUNIT_ASSERT(programs.programs[i] == prog1[i]);
        }
        
        int offset2 = programs.species_offset[1];
        CPPUNIT_ASSERT(species2 == 1);
        CPPUNIT_ASSERT(programs.species_token[1] == token2);
        CPPUNIT_ASSERT(offset2 == 5);
        for (int i = 0; i < 6; ++i) {
            CPPUNIT_ASSERT(programs.programs[i + offset2] == prog2[i]);
        }
    }
    
    // ----
    // get_instruction
    void test_creature_programs_get_instruction_1() {
        Creature_Programs programs;
        
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        CPPUNIT_ASSERT(programs.get_instruction(0, 0).compare("test") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 1).compare("test") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 2).compare("test") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 3).compare("test") == 0);
    }
    void test_creature_programs_get_instruction_2() {
        Creature_Programs programs;
        
        vector<string> prog;
        prog.push_back("add0");
        prog.push_back("add1");
        prog.push_back("add2");
        prog.push_back("add3");
        programs.add_program(prog, 't');
        
        CPPUNIT_ASSERT(programs.get_instruction(0, 0).compare("add0") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 1).compare("add1") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 2).compare("add2") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 3).compare("add3") == 0);
    }
    void test_creature_programs_get_instruction_3() {
        Creature_Programs programs;
        
        vector<string> prog1;
        prog1.push_back("add0");
        prog1.push_back("add1");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("add2");
        prog2.push_back("add3");
        programs.add_program(prog2, 's');
        
        CPPUNIT_ASSERT(programs.get_instruction(0, 0).compare("add0") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(0, 1).compare("add1") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(1, 0).compare("add2") == 0);
        CPPUNIT_ASSERT(programs.get_instruction(1, 1).compare("add3") == 0);
    }
    
    // ----
    // get_species_token
    void test_creature_programs_get_species_token_1() {
        Creature_Programs programs;
        
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        CPPUNIT_ASSERT(programs.get_species_token(0) == 't');
    }
    void test_creature_programs_get_species_token_2() {
        Creature_Programs programs;
        
        vector<string> prog;
        prog.push_back("add0");
        prog.push_back("add1");
        prog.push_back("add2");
        programs.add_program(prog, 't');
        
        CPPUNIT_ASSERT(programs.get_species_token(0) == 't');
    }
    void test_creature_programs_get_species_token_3() {
        Creature_Programs programs;
        
        vector<string> prog1;
        prog1.push_back("add0");
        prog1.push_back("add1");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("add2");
        prog2.push_back("add3");
        programs.add_program(prog2, 's');
        
        CPPUNIT_ASSERT(programs.get_species_token(0) == 't');
        CPPUNIT_ASSERT(programs.get_species_token(1) == 's');
    }


    // ----
    // Creature
    // ----
    
    // ----
    // constructor
    void test_creature_constructor_1() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        
        CPPUNIT_ASSERT(creature.species == 0);
        CPPUNIT_ASSERT(creature.counter == 0);
        CPPUNIT_ASSERT(creature.direc == 1);
//        CPPUNIT_ASSERT(creature.program == *prog);
    }
    void test_creature_constructor_2() {
        Creature_Programs programs;
        
        vector<string> prog;
        prog.push_back("add0");
        prog.push_back("add1");
        prog.push_back("add2");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 4);
        
        CPPUNIT_ASSERT(creature.species == 0);
        CPPUNIT_ASSERT(creature.counter == 0);
        CPPUNIT_ASSERT(creature.direc == 4);
//        CPPUNIT_ASSERT(*(creature.program) == *prog);
    }
    void test_creature_constructor_3() {
        Creature_Programs programs;
        
        vector<string> prog1;
        prog1.push_back("add0");
        prog1.push_back("add1");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("add2");
        prog2.push_back("add3");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 1, 3);
        
        CPPUNIT_ASSERT(creature1.species == 0);
        CPPUNIT_ASSERT(creature1.counter == 0);
        CPPUNIT_ASSERT(creature1.direc == 1);
//        CPPUNIT_ASSERT(*(creature1.program) == *prog1);
        
        CPPUNIT_ASSERT(creature2.species == 1);
        CPPUNIT_ASSERT(creature2.counter == 0);
        CPPUNIT_ASSERT(creature2.direc == 3);
//        CPPUNIT_ASSERT(*(creature2.program) == *prog2);
    }
    
    // ----
    // is_same_species
    void test_creature_is_same_species_1() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(4, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 0, 3);
        
        CPPUNIT_ASSERT(creature1.is_same_species(&creature2));
        CPPUNIT_ASSERT(creature2.is_same_species(&creature1));
    }
    void test_creature_is_same_species_2() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(4, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 0, 3);
        Creature creature3(&programs, 1, 3);
        
        CPPUNIT_ASSERT(creature1.is_same_species(&creature2));
        CPPUNIT_ASSERT(!creature3.is_same_species(&creature1));
        CPPUNIT_ASSERT(!creature3.is_same_species(&creature2));
    }
    void test_creature_is_same_species_3() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(4, "test2");
        programs.add_program(prog2, 's');
        vector<string> prog3;
        prog3.push_back("add0");
        prog3.push_back("add1");
        prog3.push_back("add2");
        programs.add_program(prog3, 'r');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 1, 3);
        Creature creature3(&programs, 2, 4);
        Creature creature4(&programs, 2, 2);
        
        CPPUNIT_ASSERT(!creature1.is_same_species(&creature2));
        CPPUNIT_ASSERT(!creature3.is_same_species(&creature1));
        CPPUNIT_ASSERT(!creature3.is_same_species(&creature2));
        CPPUNIT_ASSERT(creature4.is_same_species(&creature3));
    }
    
    // ----
    // get_next_instrc
    void test_creature_get_next_instrc_1() {
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("add0");
        prog.push_back("add1");
        prog.push_back("add2");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        
        CPPUNIT_ASSERT(creature.get_next_instrc().compare("add0") == 0);
        CPPUNIT_ASSERT(creature.get_next_instrc().compare("add1") == 0);
        CPPUNIT_ASSERT(creature.get_next_instrc().compare("add2") == 0);
    }
    void test_creature_get_next_instrc_2() {
        Creature_Programs programs;
        vector<string> prog1;
        prog1.push_back("add0");
        prog1.push_back("add1");
        prog1.push_back("add2");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("add3");
        prog2.push_back("add4");
        prog2.push_back("add5");
        programs.add_program(prog2, 't');
        
        Creature creature(&programs, 1, 1);
        
        CPPUNIT_ASSERT(creature.get_next_instrc().compare("add3") == 0);
        CPPUNIT_ASSERT(creature.get_next_instrc().compare("add4") == 0);
        CPPUNIT_ASSERT(creature.get_next_instrc().compare("add5") == 0);
    }
    void test_creature_get_next_instrc_3() {
        Creature_Programs programs;
        vector<string> prog1;
        prog1.push_back("add0");
        prog1.push_back("add1");
        prog1.push_back("add2");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("add3");
        prog2.push_back("add4");
        prog2.push_back("add5");
        programs.add_program(prog2, 't');
        
        Creature creature1(&programs, 0, 4);
        Creature creature2(&programs, 1, 1);
        
        CPPUNIT_ASSERT(creature2.get_next_instrc().compare("add3") == 0);
        CPPUNIT_ASSERT(creature2.get_next_instrc().compare("add4") == 0);
        CPPUNIT_ASSERT(creature2.get_next_instrc().compare("add5") == 0);
        
        CPPUNIT_ASSERT(creature1.get_next_instrc().compare("add0") == 0);
        CPPUNIT_ASSERT(creature1.get_next_instrc().compare("add1") == 0);
        CPPUNIT_ASSERT(creature1.get_next_instrc().compare("add2") == 0);
    }
    
    // ----
    // get_front
    void test_creature_get_front_1() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        
        CPPUNIT_ASSERT(creature.get_front(0, 0)[0] == 0);
        CPPUNIT_ASSERT(creature.get_front(0, 0)[1] == -1);
        CPPUNIT_ASSERT(creature.get_front(5, 6)[0] == 5);
        CPPUNIT_ASSERT(creature.get_front(5, 6)[1] == 5);
    }
    void test_creature_get_front_2() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 1, 1);
        
        CPPUNIT_ASSERT(creature1.get_front(0, 0)[0] == 0);
        CPPUNIT_ASSERT(creature1.get_front(0, 0)[1] == -1);
        CPPUNIT_ASSERT(creature2.get_front(5, 6)[0] == 5);
        CPPUNIT_ASSERT(creature2.get_front(5, 6)[1] == 5);
    }
    void test_creature_get_front_3() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 2);
        Creature creature2(&programs, 1, 3);
        Creature creature3(&programs, 1, 4);
        
        CPPUNIT_ASSERT(creature1.get_front(0, 0)[0] == 1);
        CPPUNIT_ASSERT(creature1.get_front(0, 0)[1] == 0);
        CPPUNIT_ASSERT(creature2.get_front(0, 0)[0] == 0);
        CPPUNIT_ASSERT(creature2.get_front(0, 0)[1] == 1);
        CPPUNIT_ASSERT(creature3.get_front(0, 0)[0] == -1);
        CPPUNIT_ASSERT(creature3.get_front(0, 0)[1] == 0);
    }
    
    // ----
    // get_token
    void test_creature_get_token_1() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        
        CPPUNIT_ASSERT(creature.get_token() == 't');
    }
    void test_creature_get_token_2() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 1, 1);
        
        CPPUNIT_ASSERT(creature1.get_token() == 't');
        CPPUNIT_ASSERT(creature2.get_token() == 's');
    }
    void test_creature_get_token_3() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 2);
        Creature creature2(&programs, 1, 3);
        Creature creature3(&programs, 1, 4);
        
        CPPUNIT_ASSERT(creature1.get_token() == 't');
        CPPUNIT_ASSERT(creature2.get_token() == 's');
        CPPUNIT_ASSERT(creature3.get_token() == 's');
    }
    
    // ----
    // change_counter
    void test_creature_change_counter_1() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        creature.change_counter(3);
        
        CPPUNIT_ASSERT(creature.counter == 3);
    }
    void test_creature_change_counter_2() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        creature1.change_counter(3);
        creature1.change_counter(2);
        Creature creature2(&programs, 1, 1);
        creature2.change_counter(1);
        
        CPPUNIT_ASSERT(creature1.counter == 2);
        CPPUNIT_ASSERT(creature2.counter == 1);
    }
    void test_creature_change_counter_3() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 2);
        creature1.change_counter(2);
        Creature creature2(&programs, 1, 3);
        creature2.change_counter(3);
        Creature creature3(&programs, 1, 4);
        creature3.change_counter(1);
        
        CPPUNIT_ASSERT(creature1.counter == 2);
        CPPUNIT_ASSERT(creature2.counter == 3);
        CPPUNIT_ASSERT(creature3.counter == 1);
    }
    
    // ----
    // change_species
    void test_creature_change_species_1() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        Creature creature2(&programs, 1, 1);
        creature2.change_species(&creature1);
        
        CPPUNIT_ASSERT(creature1.species == 0);
        CPPUNIT_ASSERT(creature2.species == 0);
        CPPUNIT_ASSERT(creature2.counter == 0);
    }
    void test_creature_change_species_2() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        creature1.change_counter(2);
        Creature creature2(&programs, 1, 1);
        creature2.change_species(&creature1);
        creature1.change_species(&creature2);
        
        CPPUNIT_ASSERT(creature1.species == 0);
        CPPUNIT_ASSERT(creature2.species == 0);
        CPPUNIT_ASSERT(creature1.counter == 2);
        CPPUNIT_ASSERT(creature2.counter == 0);
    }
    void test_creature_change_species_3() {
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(6, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 2);
        creature1.change_counter(2);
        Creature creature2(&programs, 1, 3);
        creature2.change_counter(3);
        Creature creature3(&programs, 1, 4);
        creature3.change_counter(1);
        creature1.change_species(&creature2);
        creature2.change_species(&creature1);
        
        CPPUNIT_ASSERT(creature1.species == 1);
        CPPUNIT_ASSERT(creature2.species == 1);
        CPPUNIT_ASSERT(creature3.species == 1);
        CPPUNIT_ASSERT(creature1.counter == 0);
        CPPUNIT_ASSERT(creature2.counter == 3);
        CPPUNIT_ASSERT(creature3.counter == 1);
    }
    
    // ----
    // left
    void test_creature_left_1() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        creature.left();
        
        CPPUNIT_ASSERT(creature.direc == 4);
    }
    void test_creature_left_2() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 2);
        creature.left();
        
        CPPUNIT_ASSERT(creature.direc == 1);
    }
    void test_creature_left_3() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 4);
        creature.left();
        creature.left();
        
        CPPUNIT_ASSERT(creature.direc == 2);
    }
    
    // ----
    // right
    void test_creature_right_1() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        creature.right();
        
        CPPUNIT_ASSERT(creature.direc == 2);
    }
    void test_creature_right_2() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 2);
        creature.right();
        
        CPPUNIT_ASSERT(creature.direc == 3);
    }
    void test_creature_right_3() {
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 4);
        creature.right();
        creature.right();
        
        CPPUNIT_ASSERT(creature.direc == 2);
    }


    // ----
    // Darwin_Game
    // ----
    
    // ----
    // constructor
    void test_darwin_game_constructor_1() {
        int height = 2, width = 2;
        Darwin_Game game(height, width);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(game.grid[y][x] == NULL);
            }
        }
    }
    void test_darwin_game_constructor_2() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(game.grid[y][x] == NULL);
            }
        }
    }
    void test_darwin_game_constructor_3() {
        int height = 2, width = 20;
        Darwin_Game game(height, width);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(game.grid[y][x] == NULL);
            }
        }
    }
    
    // ----
    // add_creature
    void test_darwin_game_add_creature_1() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 1, 10);
        CPPUNIT_ASSERT(game.grid[10][1] == &creature);
    }
    void test_darwin_game_add_creature_2() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 1, 9);
        Creature creature2(&programs, 0, 2);
        game.add_creature(&creature2, 3, 5);
        
        CPPUNIT_ASSERT(game.grid[9][1] == &creature1);
        CPPUNIT_ASSERT(game.grid[5][3] == &creature2);
    }
    void test_darwin_game_add_creature_3() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 1, 9);
        Creature creature2(&programs, 0, 2);
        Creature creature3(&programs, 0, 2);
        
        CPPUNIT_ASSERT(game.grid[9][1] == &creature1);
        CPPUNIT_ASSERT(!game.add_creature(&creature2, 1, 9));
        CPPUNIT_ASSERT(!game.add_creature(&creature3, -1, 5));
    }
    
    // ----
    // is_empty
    void test_darwin_game_is_empty_1() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(game.is_empty(convert_to_point(x, y)));
            }
        }
    }
    void test_darwin_game_is_empty_2() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 1, 10);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == 1 && y == 10) {
                    CPPUNIT_ASSERT(!game.is_empty(convert_to_point(x, y)));
                    continue;
                }
                CPPUNIT_ASSERT(game.is_empty(convert_to_point(x, y)));
            }
        }
    }
    void test_darwin_game_is_empty_3() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 1, 9);
        Creature creature2(&programs, 0, 2);
        game.add_creature(&creature2, 0, 2);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if ((x == 1 && y == 9) || (x == 0 && y == 2)) {
                    CPPUNIT_ASSERT(!game.is_empty(convert_to_point(x, y)));
                    continue;
                }
                CPPUNIT_ASSERT(game.is_empty(convert_to_point(x, y)));
            }
        }
    }
    
    // ----
    // is_enemy_creature
    void test_darwin_game_is_enemy_creature_1() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(!game.is_enemy_creature(&creature, convert_to_point(x, y)));
            }
        }
    }
    void test_darwin_game_is_enemy_creature_2() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 1, 10);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(!game.is_enemy_creature(&creature, convert_to_point(x, y)));
            }
        }
    }
    void test_darwin_game_is_enemy_creature_3() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog1(4, "test1");
        programs.add_program(prog1, 't');
        vector<string> prog2(4, "test2");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 1, 9);
        Creature creature2(&programs, 1, 2);
        game.add_creature(&creature2, 0, 2);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == 0 && y == 2) {
                    CPPUNIT_ASSERT(game.is_enemy_creature(&creature1, convert_to_point(x, y)));
                    continue;
                }
                CPPUNIT_ASSERT(!game.is_enemy_creature(&creature1, convert_to_point(x, y)));
            }
        }
    }
    
    // ----
    // is_wall
    void test_darwin_game_is_wall_1() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(!game.is_wall(convert_to_point(x, y)));
            }
        }
    }
    void test_darwin_game_is_wall_2() {
        int height = 2, width = 2;
        Darwin_Game game(height, width);
        
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(0, -1)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(1, -1)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(-1, 0)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(-1, 1)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(-1, -1)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(2, 0)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(2, 1)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(0, 2)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(1, 2)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(2, 2)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(-1, 2)));
        CPPUNIT_ASSERT(game.is_wall(convert_to_point(2, -1)));
    }
    void test_darwin_game_is_wall_3() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 1, 9);
        Creature creature2(&programs, 0, 2);
        game.add_creature(&creature2, 0, 2);
        
        for (int y = -1; y < height + 1; ++y) {
            for (int x = -1; x < width + 1; ++x) {
                if (x == -1 || x == width || y == -1 || y == height) {
                    CPPUNIT_ASSERT(game.is_wall(convert_to_point(x, y)));
                    continue;
                }
                CPPUNIT_ASSERT(!game.is_wall(convert_to_point(x, y)));
            }
        }
    }
    
    // ----
    // is_valid
    void test_darwin_game_is_valid_1() {
        int height = 20, width = 2;
        Darwin_Game game(height, width);
        
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                CPPUNIT_ASSERT(game.is_valid(convert_to_point(x, y)));
            }
        }
    }
    void test_darwin_game_is_valid_2() {
        int height = 2, width = 2;
        Darwin_Game game(height, width);
        
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(0, -1)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(1, -1)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(-1, 0)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(-1, 1)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(-1, -1)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(2, 0)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(2, 1)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(0, 2)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(1, 2)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(2, 2)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(-1, 2)));
        CPPUNIT_ASSERT(!game.is_valid(convert_to_point(2, -1)));
    }
    void test_darwin_game_is_valid_3() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog(4, "test");
        programs.add_program(prog, 't');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 1, 9);
        Creature creature2(&programs, 0, 2);
        game.add_creature(&creature2, 0, 2);
        
        for (int y = -1; y < height + 1; ++y) {
            for (int x = -1; x < width + 1; ++x) {
                if (x == -1 || x == width || y == -1 || y == height) {
                    CPPUNIT_ASSERT(!game.is_valid(convert_to_point(x, y)));
                    continue;
                }
                CPPUNIT_ASSERT(game.is_valid(convert_to_point(x, y)));
            }
        }
    }
    
    // ----
    // execute_turn
    void test_darwin_game_execute_turn_1() {
        int height = 5, width = 5;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("hop");
        prog.push_back("go 0");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 3, 3);
        game.execute_turn();
        
        CPPUNIT_ASSERT(game.grid[3][3] == NULL);
        CPPUNIT_ASSERT(game.grid[2][3] == &creature);
        CPPUNIT_ASSERT(creature.counter == 1);
    }
    void test_darwin_game_execute_turn_2() {
        int height = 5, width = 5;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("hop");
        prog.push_back("go 0");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 3, 3);
        game.execute_turn();
        game.execute_turn();
        
        CPPUNIT_ASSERT(game.grid[3][3] == NULL);
        CPPUNIT_ASSERT(game.grid[2][3] == NULL);
        CPPUNIT_ASSERT(game.grid[1][3] == &creature);
        CPPUNIT_ASSERT(creature.counter == 1);
    }
    void test_darwin_game_execute_turn_3() {
        int height = 10, width = 10;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog1;
        prog1.push_back("hop");
        prog1.push_back("go 0");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("left");
        prog2.push_back("go 0");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 2, 9);
        Creature creature2(&programs, 1, 2);
        game.add_creature(&creature2, 0, 2);
        game.execute_turn();
        game.execute_turn();
        
        CPPUNIT_ASSERT(game.grid[9][2] == NULL);
        CPPUNIT_ASSERT(game.grid[8][2] == NULL);
        CPPUNIT_ASSERT(game.grid[7][2] == &creature1);
        CPPUNIT_ASSERT(creature1.counter == 1);
        CPPUNIT_ASSERT(game.grid[2][0] == &creature2);
        CPPUNIT_ASSERT((*game.grid[2][0]).direc == 4);
    }
    
    // ----
    // print_grid
    void test_darwin_game_print_grid_1() {
        int height = 5, width = 5;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("hop");
        prog.push_back("go 0");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 3, 3);
        game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234\n"
                                "0 .....\n"
                                "1 .....\n"
                                "2 ...t.\n"
                                "3 .....\n"
                                "4 .....\n";
        
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_print_grid_2() {
        int height = 5, width = 5;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("hop");
        prog.push_back("go 0");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 3, 3);
        game.execute_turn();
        game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234\n"
                                "0 .....\n"
                                "1 ...t.\n"
                                "2 .....\n"
                                "3 .....\n"
                                "4 .....\n";
        
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_print_grid_3() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog1;
        prog1.push_back("hop");
        prog1.push_back("go 0");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("left");
        prog2.push_back("go 0");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 2, 9);
        Creature creature2(&programs, 1, 2);
        game.add_creature(&creature2, 0, 2);
        game.execute_turn();
        game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 s..........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ..t........\n"
                                "8 ...........\n"
                                "9 ...........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    
    
    // ----
    // Instructions/Game
    // ----
    void test_darwin_game_handle_instr_1() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("hop");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 9);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ..t........\n"
                                "9 ...........\n"
                                "0 ...........\n";
        
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_2() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("left");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 9);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ...........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature.direc == 4);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_3() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("right");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 9);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ...........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature.direc == 2);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_4() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog1;
        prog1.push_back("infect");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("left");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 2, 9);
        Creature creature2(&programs, 0, 1);
        game.add_creature(&creature2, 2, 8);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ..t........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature1.species == 0);
        CPPUNIT_ASSERT(creature2.species == 0);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_5() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("if_empty 2");
        prog.push_back("hop");
        prog.push_back("left");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 9);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ...........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature.direc == 4);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_6() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog1;
        prog1.push_back("if_enemy 2");
        prog1.push_back("left");
        prog1.push_back("infect");
        programs.add_program(prog1, 't');
        vector<string> prog2;
        prog2.push_back("left");
        programs.add_program(prog2, 's');
        
        Creature creature1(&programs, 0, 1);
        game.add_creature(&creature1, 2, 9);
        Creature creature2(&programs, 1, 1);
        game.add_creature(&creature2, 2, 8);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ..t........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature1.species == 0);
        CPPUNIT_ASSERT(creature2.species == 0);
        CPPUNIT_ASSERT(creature1.direc == 1);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_7() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("if_wall 2");
        prog.push_back("hop");
        prog.push_back("left");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 0);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ..t........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ...........\n"
                                "9 ...........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature.direc == 4);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_8() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("if_rand 2");
        prog.push_back("right");
        prog.push_back("left");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 9);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ...........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature.direc == 4 || creature.direc == 2);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_handle_instr_9() {
        int height = 11, width = 11;
        Darwin_Game game(height, width);
        Creature_Programs programs;
        vector<string> prog;
        prog.push_back("go 2");
        prog.push_back("hop");
        prog.push_back("left");
        programs.add_program(prog, 't');
        
        Creature creature(&programs, 0, 1);
        game.add_creature(&creature, 2, 9);
        int completed = game.execute_turn();
        
        string output = game.print_grid();
        string correct_output = "  01234567890\n"
                                "0 ...........\n"
                                "1 ...........\n"
                                "2 ...........\n"
                                "3 ...........\n"
                                "4 ...........\n"
                                "5 ...........\n"
                                "6 ...........\n"
                                "7 ...........\n"
                                "8 ...........\n"
                                "9 ..t........\n"
                                "0 ...........\n";
        
        CPPUNIT_ASSERT(completed == 0);
        CPPUNIT_ASSERT(creature.direc == 4);
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }
    void test_darwin_game_run_1() {
        Creature_Programs programs;
        vector<string> prog;
        // food
        prog.push_back("left");
        prog.push_back("go 0");
        programs.add_program(prog, 'f');
        // hopper
        prog.clear();
        prog.push_back("hop");
        prog.push_back("go 0");
        programs.add_program(prog, 'h');
        // rover
        prog.clear();
        prog.push_back("if_enemy 9");
        prog.push_back("if_empty 7");
        prog.push_back("if_random 5");
        prog.push_back("left");
        prog.push_back("go 0");
        prog.push_back("right");
        prog.push_back("go 0");
        prog.push_back("hop");
        prog.push_back("go 0");
        prog.push_back("infect");
        prog.push_back("go 0");
        programs.add_program(prog, 'r');
        // trap
        prog.clear();
        prog.push_back("if_enemy 3");
        prog.push_back("left");
        prog.push_back("go 0");
        prog.push_back("infect");
        prog.push_back("go 0");
        programs.add_program(prog, 't');
        
        int num_turns = 5;
        Darwin_Game game(8, 8);
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
        
        for (int i = 0; i < num_turns; ++i) {
            game.execute_turn();
        }
        
        string output = game.print_grid();
        string correct_output = "  01234567\n"
                                "0 f..h....\n"
                                "1 ........\n"
                                "2 ........\n"
                                "3 .......h\n"
                                "4 h.......\n"
                                "5 ........\n"
                                "6 ........\n"
                                "7 ....h..f\n";
        
        CPPUNIT_ASSERT(output.compare(correct_output) == 0);
    }


    // ---------
    // TestSuite
    // ---------

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_convert_to_point_1);
    CPPUNIT_TEST(test_convert_to_point_2);
    CPPUNIT_TEST(test_convert_to_point_3);
    CPPUNIT_TEST(test_creature_programs_add_program_1);
    CPPUNIT_TEST(test_creature_programs_add_program_2);
    CPPUNIT_TEST(test_creature_programs_add_program_3);
    CPPUNIT_TEST(test_creature_programs_get_instruction_1);
    CPPUNIT_TEST(test_creature_programs_get_instruction_2);
    CPPUNIT_TEST(test_creature_programs_get_instruction_3);
    CPPUNIT_TEST(test_creature_programs_get_species_token_1);
    CPPUNIT_TEST(test_creature_programs_get_species_token_2);
    CPPUNIT_TEST(test_creature_programs_get_species_token_3);
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_creature_is_same_species_1);
    CPPUNIT_TEST(test_creature_is_same_species_2);
    CPPUNIT_TEST(test_creature_is_same_species_3);
    CPPUNIT_TEST(test_creature_get_next_instrc_1);
    CPPUNIT_TEST(test_creature_get_next_instrc_2);
    CPPUNIT_TEST(test_creature_get_next_instrc_3);
    CPPUNIT_TEST(test_creature_get_front_1);
    CPPUNIT_TEST(test_creature_get_front_2);
    CPPUNIT_TEST(test_creature_get_front_3);
    CPPUNIT_TEST(test_creature_get_token_1);
    CPPUNIT_TEST(test_creature_get_token_2);
    CPPUNIT_TEST(test_creature_get_token_3);
    CPPUNIT_TEST(test_creature_change_counter_1);
    CPPUNIT_TEST(test_creature_change_counter_2);
    CPPUNIT_TEST(test_creature_change_counter_3); 
    CPPUNIT_TEST(test_creature_change_species_1);
    CPPUNIT_TEST(test_creature_change_species_2);
    CPPUNIT_TEST(test_creature_change_species_3);
    CPPUNIT_TEST(test_creature_left_1);
    CPPUNIT_TEST(test_creature_left_2);
    CPPUNIT_TEST(test_creature_left_3);
    CPPUNIT_TEST(test_creature_right_1);
    CPPUNIT_TEST(test_creature_right_2);
    CPPUNIT_TEST(test_creature_right_3);
    CPPUNIT_TEST(test_darwin_game_constructor_1);
    CPPUNIT_TEST(test_darwin_game_constructor_2);
    CPPUNIT_TEST(test_darwin_game_constructor_3);
    CPPUNIT_TEST(test_darwin_game_add_creature_1);
    CPPUNIT_TEST(test_darwin_game_add_creature_2);
    CPPUNIT_TEST(test_darwin_game_add_creature_3);
    CPPUNIT_TEST(test_darwin_game_is_empty_1);
    CPPUNIT_TEST(test_darwin_game_is_empty_2);
    CPPUNIT_TEST(test_darwin_game_is_empty_3);
    CPPUNIT_TEST(test_darwin_game_is_enemy_creature_1);
    CPPUNIT_TEST(test_darwin_game_is_enemy_creature_2);
    CPPUNIT_TEST(test_darwin_game_is_enemy_creature_3);
    CPPUNIT_TEST(test_darwin_game_is_wall_1);
    CPPUNIT_TEST(test_darwin_game_is_wall_2);
    CPPUNIT_TEST(test_darwin_game_is_wall_3);
    CPPUNIT_TEST(test_darwin_game_is_valid_1);
    CPPUNIT_TEST(test_darwin_game_is_valid_2);
    CPPUNIT_TEST(test_darwin_game_is_valid_3);
    CPPUNIT_TEST(test_darwin_game_execute_turn_1);
    CPPUNIT_TEST(test_darwin_game_execute_turn_2);
    CPPUNIT_TEST(test_darwin_game_execute_turn_3);
    CPPUNIT_TEST(test_darwin_game_print_grid_1);
    CPPUNIT_TEST(test_darwin_game_print_grid_2);
    CPPUNIT_TEST(test_darwin_game_print_grid_3);
    CPPUNIT_TEST(test_darwin_game_handle_instr_1);
    CPPUNIT_TEST(test_darwin_game_handle_instr_2);
    CPPUNIT_TEST(test_darwin_game_handle_instr_3);
    CPPUNIT_TEST(test_darwin_game_handle_instr_4);
    CPPUNIT_TEST(test_darwin_game_handle_instr_5);
    CPPUNIT_TEST(test_darwin_game_handle_instr_6);
    CPPUNIT_TEST(test_darwin_game_handle_instr_7);
    CPPUNIT_TEST(test_darwin_game_handle_instr_8);
    CPPUNIT_TEST(test_darwin_game_handle_instr_9);
    CPPUNIT_TEST(test_darwin_game_run_1);
    CPPUNIT_TEST_SUITE_END();
};


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++" << endl;


    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();


    cout << "Done." << endl;
    return 0;
}
