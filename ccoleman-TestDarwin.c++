// --------------------------------
// projects/voting/TestDarwin.c++
// Copyright (C) 2013
// Clare Dominique Coleman
// Manoj Dhanapal
// --------------------------------

// --------
// includes
// --------

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define class struct
#define private public

#include "Darwin.h"

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
    // -------
    // Species
    // -------

    void test_species_constructor_1 () {
        Species s('t');
        CPPUNIT_ASSERT(s._c == 't');}

    void test_species_constructor_2 () {
        Species s('h');
        CPPUNIT_ASSERT(s.get_type() == 'h');}

    void test_species_constructor_3 () {
        Species s('t');
        CPPUNIT_ASSERT(s._c == 't');
        CPPUNIT_ASSERT(s.program.size() == 0);}

    void test_add_program_1 () {
        Species s('t');
        s.add_program(hop);
        s.add_program(hop);
        s.add_program(hop);
        CPPUNIT_ASSERT(s.program.size() == 3);}

    void test_add_program_2 () {
        Species s('h');
        s.add_program(hop);
        s.add_program(hop);
        s.add_program(hop);
        CPPUNIT_ASSERT(s.program[0].first == hop);
        CPPUNIT_ASSERT(s.program[0].second == 0);}

    void test_add_program_3 () {
        Species s('t');
        s.add_program(if_enemy,2);
        s.add_program(if_wall,14);
        CPPUNIT_ASSERT(s.program[1].first == if_wall);
        CPPUNIT_ASSERT(s.program[1].second == 14);}

    void test_get_instruction_1 () {
        Species s('t');
        s.add_program(hop);
        s.add_program(hop);
        s.add_program(hop);
        instructions i = s.get_instruction(1);
        CPPUNIT_ASSERT(i.first == hop);
        CPPUNIT_ASSERT(i.second == 0);}

    void test_get_instruction_2 () {
        Species s('h');
        s.add_program(if_enemy,2);
        s.add_program(if_wall,14);
        instructions i = s.get_instruction(0);
        CPPUNIT_ASSERT(i.first == if_enemy);
        CPPUNIT_ASSERT(i.second == 2);}

    void test_get_instruction_3 () {
        Species s('t');
        s.add_program(if_enemy,2);
        s.add_program(if_wall,14);
        instructions i = s.get_instruction(1);
        CPPUNIT_ASSERT(i.first == if_wall);
        CPPUNIT_ASSERT(i.second == 14);}

    void test_creature_constructor_1 () {
        Creature c;
        CPPUNIT_ASSERT(c.is_empty());
        CPPUNIT_ASSERT(c.dir == north);
        CPPUNIT_ASSERT(c.pc == 0);
        CPPUNIT_ASSERT(c.has_moved());
        CPPUNIT_ASSERT(c.species_type() == '.');}

    void test_creature_constructor_2 () {
        Creature c1;
        Creature c2(c1);
        c2.update_pc(4);
        CPPUNIT_ASSERT(c2.is_empty());
        CPPUNIT_ASSERT(c2.dir == north);
        CPPUNIT_ASSERT(c2.pc == 4);
        CPPUNIT_ASSERT(c2.had_turn);
        CPPUNIT_ASSERT(c2.species_type() == '.');}

    void test_creature_constructor_3 () {
        Creature c1;
        Species s('t');
        c1._s = &s;
        c1.dir = west;
        Creature c2(c1);
        c2.increment_pc();
        CPPUNIT_ASSERT(!c2.is_empty());
        CPPUNIT_ASSERT(c2._s->_c == 't');
        CPPUNIT_ASSERT(c2.species_type() == 't');
        CPPUNIT_ASSERT(c2.dir == west);
        CPPUNIT_ASSERT(c2.pc == 1);
        CPPUNIT_ASSERT(c2.has_moved());}

    void test_next_instruction_1() {
        Species s('t');
        s.add_program(hop);
        s.add_program(go, 0);

        Creature c1;
        c1._s = &s;
        c1.dir = west;
        Creature c2(c1);

        CPPUNIT_ASSERT(c2.next_instruction().first == hop);
        CPPUNIT_ASSERT(c2.next_instruction().second == 0);}

    void test_next_instruction_2() {
        Species s('t');
        s.add_program(hop);
        s.add_program(go, 0);

        Creature c1;
        c1._s = &s;
        c1.dir = west;
        ++(c1.pc);
        Creature c2(c1);

        CPPUNIT_ASSERT(c2.next_instruction().first == go);
        CPPUNIT_ASSERT(c2.next_instruction().second == 0);}

    void test_initialize_turn_1() {
        Creature c1;
        Creature c2(c1);
        CPPUNIT_ASSERT(c2.had_turn);
        c2.initialize_turn();
        CPPUNIT_ASSERT(c2.had_turn);
        CPPUNIT_ASSERT(c2.species_type() == '.');}

    void test_initialize_turn_2() {
        Creature c1;
        Species s('t');
        c1._s = &s;
        c1.dir = west;
        Creature c2(c1);
        c2.initialize_turn();
        CPPUNIT_ASSERT(!c2.has_moved());}

    void test_creature_add_1() {
        Creature c;
        Species s('t');
        c.add(&s, east);
        
        CPPUNIT_ASSERT(!c.is_empty());
        CPPUNIT_ASSERT(c.species_type() == 't');
        CPPUNIT_ASSERT(c.dir == east);
        CPPUNIT_ASSERT(c.pc == 0);
        CPPUNIT_ASSERT(c.has_moved());}

    void test_creature_add_2() {
        Creature c;
        c.add(NULL, east);
        
        CPPUNIT_ASSERT(c.is_empty());
        CPPUNIT_ASSERT(c.dir == east);}

    void test_update_pc_1() {
        Creature c;
        c.add(NULL, east);
        
        CPPUNIT_ASSERT(c.is_empty());
        CPPUNIT_ASSERT(c.dir == east);}

    void test_get_ahead_1() {
        size_t a, b;
        Creature c;
        c.dir = west;
        c.get_ahead(1, 2, a, b);
        CPPUNIT_ASSERT(a == 1);
        CPPUNIT_ASSERT(b == 1);}

    void test_get_ahead_2() {
        size_t a, b;
        Creature c;
        c.dir = east;
        c.get_ahead(1, 2, a, b);
        CPPUNIT_ASSERT(a == 1);
        CPPUNIT_ASSERT(b == 3);}

    void test_get_ahead_3() {
        size_t a, b;
        Creature c;
        c.dir = south;
        c.get_ahead(1, 2, a, b);
        CPPUNIT_ASSERT(a == 2);
        CPPUNIT_ASSERT(b == 2);}

    void test_get_ahead_4() {
        size_t a, b;
        Creature c;
        c.dir = north;
        c.get_ahead(1, 2, a, b);
        CPPUNIT_ASSERT(a == 0);
        CPPUNIT_ASSERT(b == 2);}

    void test_clook_left_1 () {
        Creature c;
        c.dir = north;
        c.clook_left();
        CPPUNIT_ASSERT(c.dir == west);}

    void test_clook_left_2 () {
        Creature c;
        c.dir = west;
        c.clook_left();
        CPPUNIT_ASSERT(c.dir == south);}

    void test_clook_left_3 () {
        Creature c;
        c.dir = south;
        c.clook_left();
        CPPUNIT_ASSERT(c.dir == east);}

    void test_clook_left_4 () {
        Creature c;
        c.dir = east;
        c.clook_left();
        CPPUNIT_ASSERT(c.dir == north);}

    void test_clook_left_5 () {
        Creature c;
        c.dir = east;
        c.clook_left();
        c.clook_left();
        c.clook_left();
        c.clook_left();
        CPPUNIT_ASSERT(c.dir == east);}

    void test_clook_right_1 () {
        Creature c;
        c.dir = north;
        c.clook_right();
        CPPUNIT_ASSERT(c.dir == east);}

    void test_clook_right_2 () {
        Creature c;
        c.dir = west;
        c.clook_right();
        CPPUNIT_ASSERT(c.dir == north);}

    void test_clook_right_3 () {
        Creature c;
        c.dir = south;
        c.clook_right();
        CPPUNIT_ASSERT(c.dir == west);}

    void test_clook_right_4 () {
        Creature c;
        c.dir = east;
        c.clook_right();
        CPPUNIT_ASSERT(c.dir == south);}

    void test_clook_right_5 () {
        Creature c;
        c.dir = east;
        c.clook_right();
        c.clook_right();
        c.clook_right();
        c.clook_right();
        CPPUNIT_ASSERT(c.dir == east);}

    void test_cgo_1 () {
        Species s('d');
        s.add_program(go,120);
        Creature c;
        c.add(&s,west);
        c.cgo();
        CPPUNIT_ASSERT(c.pc == 120);}

    void test_cgo_2 () {
        Species s('d');
        s.add_program(go,423);
        Creature c;
        c.add(&s,west);
        c.cgo();
        CPPUNIT_ASSERT(c.pc == 423);}

    void test_cif_enemy_1 () {
        Species s('d');
        Creature c1, c2;
        c1.add(&s,west);
        CPPUNIT_ASSERT(!c1.cif_enemy(c2));}

    void test_cif_enemy_2 () {
        Species s('d');
        Creature c1, c2;
        c1.add(&s,west);
        c2.add(&s,west);
        CPPUNIT_ASSERT(!c1.cif_enemy(c2));}

    void test_cif_enemy_3 () {
        Species s1('d');
        Species s2('f');
        Creature c1, c2;
        c1.add(&s1,west);
        c2.add(&s2,west);
        CPPUNIT_ASSERT(c1.cif_enemy(c2));}

    void test_cinfect_1 () {
        Species s1('d');
        Species s2('f');
        Creature c1, c2;
        c1.add(&s1,west);
        c2.add(&s2,east);
        CPPUNIT_ASSERT(c2.had_turn);
        c1.cinfect(c2);
        CPPUNIT_ASSERT(c2.pc == 0);
        CPPUNIT_ASSERT(c2.dir == east);
        CPPUNIT_ASSERT(c2.had_turn);
        CPPUNIT_ASSERT(c1.had_turn);
        CPPUNIT_ASSERT(c2._s == c1._s);}

    void test_chop_1 () {
        Species s1('d');
        Creature c1, c2;
        c1.add(&s1,west);
        c2.add(NULL,east);
        CPPUNIT_ASSERT(c2.had_turn);
        c1.chop(c2);
        CPPUNIT_ASSERT(c1.is_empty());
        CPPUNIT_ASSERT(c2._s == &s1);
        CPPUNIT_ASSERT(c2.pc == 1);
        CPPUNIT_ASSERT(c2.dir == west);
        CPPUNIT_ASSERT(c2.had_turn);
        CPPUNIT_ASSERT(c1.had_turn);}

    void test_chop_2 () {
        Species s1('d');
        Creature c1, c2;
        c1.add(&s1,west);
        c2.add(NULL,east);
        c1.pc = 1;
        c2.pc = 2;
        CPPUNIT_ASSERT(c2.had_turn);
        c1.chop(c2);
        CPPUNIT_ASSERT(c1.is_empty());
        CPPUNIT_ASSERT(c2._s == &s1);
        CPPUNIT_ASSERT(c1.pc == 0);
        CPPUNIT_ASSERT(c2.pc == 2);
        CPPUNIT_ASSERT(c2.dir == west);
        CPPUNIT_ASSERT(c2.had_turn);
        CPPUNIT_ASSERT(c1.had_turn);}

    void test_cif_random_1 () {
        Creature c;
        srand(77);
        c.cif_random(123);
        CPPUNIT_ASSERT(c.pc == 1);
        c.cif_random(123);
        CPPUNIT_ASSERT(c.pc == 2);}

    void test_cif_random_2 () {
        Creature c;
        srand(0);
        c.cif_random(234);
        CPPUNIT_ASSERT(c.pc == 234);
        c.cif_random(234);
        CPPUNIT_ASSERT(c.pc == 235);}

    void test_world_constructor_1() {
        World w(3,4);
        CPPUNIT_ASSERT(w.R == 3);
        CPPUNIT_ASSERT(w.C == 4);
        CPPUNIT_ASSERT(w._c.size() == 3);
        CPPUNIT_ASSERT(w.everybody.size() == 12);}

    void test_world_constructor_2() {
        World w(8,4);
        CPPUNIT_ASSERT(w.R == 8);
        CPPUNIT_ASSERT(w.C == 4);
        CPPUNIT_ASSERT(w._c.size() == 8);
        CPPUNIT_ASSERT(w.everybody.size() == 32);}

    void test_add_creature_1() {
        World w(8,4);
        Species s('e');
        CPPUNIT_ASSERT(w.R == 8);
        CPPUNIT_ASSERT(w.C == 4);
        CPPUNIT_ASSERT(w._c.size() == 8);
        CPPUNIT_ASSERT(w.everybody.size() == 32);
        try {
           w.add_creature(&s,west,2,2);
        } catch (...) {
           CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(w._c[2][2]._s == &s);
        CPPUNIT_ASSERT(w._c[2][2].dir == west);}

    void test_add_creature_2() {
        World w(8,4);
        Species s('e');
        CPPUNIT_ASSERT(w.R == 8);
        CPPUNIT_ASSERT(w.C == 4);
        CPPUNIT_ASSERT(w._c.size() == 8);
        CPPUNIT_ASSERT(w.everybody.size() == 32);
        try {
           w.add_creature(&s,east,4,3);
        } catch (...) {
           CPPUNIT_ASSERT(false);
        }
        CPPUNIT_ASSERT(w._c[4][3]._s == &s);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][3].dir == east);}

    void test_add_creature_3() {
        World w(8,4);
        Species s('e');
        CPPUNIT_ASSERT(w.R == 8);
        CPPUNIT_ASSERT(w.C == 4);
        CPPUNIT_ASSERT(w._c.size() == 8);
        CPPUNIT_ASSERT(w.everybody.size() == 32);
        try {
           w.add_creature(&s,east,4,5);
        } catch (const std::out_of_range&) {
           CPPUNIT_ASSERT(true);
           return;
        }
        CPPUNIT_ASSERT(false);}

   void test_add_creature_4() {
        World w(8,4);
        Species s('e');
        CPPUNIT_ASSERT(w.R == 8);
        CPPUNIT_ASSERT(w.C == 4);
        CPPUNIT_ASSERT(w._c.size() == 8);
        CPPUNIT_ASSERT(w.everybody.size() == 32);
        try {
           w.add_creature(&s, east, 4, 2);
           w.add_creature(&s, east, 4, 2);
        } catch (const std::invalid_argument&) {
           CPPUNIT_ASSERT(true);
           return;
        }
        CPPUNIT_ASSERT(false);}



    void test_wif_empty_1() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        w.wif_empty(4,3,423);
        CPPUNIT_ASSERT(w._c[4][3].pc == 1);}

    void test_wif_empty_2() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_empty(4,2,423);
        CPPUNIT_ASSERT(w._c[4][2].pc == 423);}

    void test_wif_empty_3() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        w.add_creature(&s,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_empty(4,2,423);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);}

    void test_wif_wall_1() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        w.wif_wall(4,3,423);
        CPPUNIT_ASSERT(w._c[4][3].pc == 423);}

    void test_wif_wall_2() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_wall(4,2,423);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);}

    void test_wif_wall_3() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        w.add_creature(&s,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_wall(4,2,423);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);}

    void test_wif_enemy_1() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        w.wif_enemy(4,3,423);
        CPPUNIT_ASSERT(w._c[4][3].pc == 1);}

    void test_wif_enemy_2() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_enemy(4,2,423);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);}

    void test_wif_enemy_3() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        w.add_creature(&s,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_enemy(4,2,423);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);}

    void test_wif_enemy_4() {
        World w(8,4);
        Species s1('e');
        Species s2('e');
        w.add_creature(&s1,east,4,3);
        w.add_creature(&s2,east,4,2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 0);
        w.wif_enemy(4,2,423);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][2].pc == 423);}

    void test_winfect_1() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,2);
        w._c[4][2].initialize_turn();
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        w.winfect(4,2);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);}

    void test_winfect_2() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,2);
        w.add_creature(&s,east,4,3);
        w._c[4][2].initialize_turn();
        w._c[4][3].initialize_turn();
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        w.winfect(4,2);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);}

    void test_winfect_3() {
        World w(8,4);
        Species s1('e');
        Species s2('e');
        w.add_creature(&s1,east,4,2);
        w.add_creature(&s2,east,4,3);
        w._c[4][2].initialize_turn();
        w._c[4][3].initialize_turn();
        w._c[4][3].pc = 5;
        direction d = w._c[4][3].dir;
        CPPUNIT_ASSERT(w._c[4][2].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].pc == 5);
        w.winfect(4,2);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].dir == d);
        CPPUNIT_ASSERT(w._c[4][2]._s == w._c[4][3]._s);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);}

    void test_whop_1() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,3);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        w.whop(4,3);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][3]._s == &s);
        CPPUNIT_ASSERT(w._c[4][3].pc == 1);}

    void test_whop_2() {
        World w(8,4);
        Species s('e');
        w.add_creature(&s,east,4,2);
        w.add_creature(&s,east,4,3);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        w.whop(4,2);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);}

    void test_whop_3() {
        World w(8,4);
        Species s1('e');
        Species s2('e');
        w.add_creature(&s1,east,4,2);
        w.add_creature(&s2,east,4,3);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        w._c[4][3].pc = 5;
        direction d = w._c[4][3].dir;
        CPPUNIT_ASSERT(w._c[4][3].pc == 5);
        w.whop(4,2);
        CPPUNIT_ASSERT(w._c[4][2].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        CPPUNIT_ASSERT(w._c[4][3].dir == d);
        CPPUNIT_ASSERT(w._c[4][2]._s == &s1);
        CPPUNIT_ASSERT(w._c[4][3]._s == &s2);
        CPPUNIT_ASSERT(w._c[4][2].pc == 1);
        CPPUNIT_ASSERT(w._c[4][3].pc == 5);}

    void test_whop_4() {
        World w(8,5);
        Species s('e');
        w.add_creature(&s,east,4,3);
        CPPUNIT_ASSERT(w._c[4][3].pc == 0);
        CPPUNIT_ASSERT(w._c[4][3].had_turn == false);
        w.whop(4,3);
        CPPUNIT_ASSERT(w._c[4][4].had_turn == true);
        CPPUNIT_ASSERT(w._c[4][3]._s == NULL);
        CPPUNIT_ASSERT(w._c[4][4]._s == &s);
        CPPUNIT_ASSERT(w._c[4][4].pc == 1);}

    void test_execute_1() {
        World w(3,3);
        Species trap('t');
        trap.add_program(if_enemy,3);
        trap.add_program(look_left);
        trap.add_program(go,0);
        trap.add_program(infect);
        trap.add_program(go,0);
        w.add_creature(&trap,east,0,0);
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::ostringstream strCout;
        std::cout.rdbuf( strCout.rdbuf() );
        w.execute(1,1);
        std::cout.rdbuf( oldCoutStreamBuf );
        std::stringstream ss1, ss2;
        ss1 << strCout.str();
        ss2 << "Turn = 0.\n  012\n0 t..\n1 ...\n2 ...\n";
        ss2 << "\nTurn = 1.\n  012\n0 t..\n1 ...\n2 ...\n\n";
        CPPUNIT_ASSERT(ss1.str() == ss2.str());}

    void test_execute_2() {
        World w(3,3);
        Species clear('c');
        clear.add_program(if_enemy,3);
        clear.add_program(look_left);
        clear.add_program(go,0);
        clear.add_program(infect);
        clear.add_program(go,0);
        Species likke('l');
        likke.add_program(if_enemy,3);
        likke.add_program(look_right);
        likke.add_program(go,0);
        likke.add_program(infect);
        likke.add_program(go,0);
        w.add_creature(&clear,west,0,0);
        w.add_creature(&likke,west,0,1);
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::ostringstream strCout;
        std::cout.rdbuf( strCout.rdbuf() );
        w.execute(1,1);
        std::cout.rdbuf( oldCoutStreamBuf );
        std::stringstream ss1, ss2;
        ss1 << strCout.str();
        ss2 << "Turn = 0.\n  012\n0 cl.\n1 ...\n2 ...\n";
        ss2 << "\nTurn = 1.\n  012\n0 ll.\n1 ...\n2 ...\n\n";
        CPPUNIT_ASSERT(ss1.str() == ss2.str());}

    void test_next_turn_1() {
        World w(3,3);
        Species clear('c');
        clear.add_program(if_enemy,3);
        clear.add_program(look_left);
        clear.add_program(go,0);
        clear.add_program(infect);
        clear.add_program(go,0);
        Species likke('l');
        likke.add_program(if_enemy,3);
        likke.add_program(look_right);
        likke.add_program(go,0);
        likke.add_program(infect);
        likke.add_program(go,0);
        w.add_creature(&clear,west,0,0);
        w.add_creature(&likke,west,0,1);
        w.next_turn();
        CPPUNIT_ASSERT(w._c[0][0]._s == &likke);
        CPPUNIT_ASSERT(w._c[0][1]._s == &likke);}

    void test_next_turn_2() {
        World w(3,3);
        Species clear('c');
        clear.add_program(if_enemy,3);
        clear.add_program(look_left);
        clear.add_program(go,0);
        clear.add_program(infect);
        clear.add_program(go,0);
        Species likke('l');
        likke.add_program(if_enemy,3);
        likke.add_program(look_right);
        likke.add_program(go,0);
        likke.add_program(infect);
        likke.add_program(go,0);
        w.add_creature(&clear,west,0,0);
        w.add_creature(&likke,west,0,1);
        w.next_turn();
        CPPUNIT_ASSERT(w._c[0][0].had_turn);
        CPPUNIT_ASSERT(w._c[0][1].had_turn);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_constructor_2);
    CPPUNIT_TEST(test_species_constructor_3);
    CPPUNIT_TEST(test_add_program_1);
    CPPUNIT_TEST(test_add_program_2);
    CPPUNIT_TEST(test_add_program_3);
    CPPUNIT_TEST(test_get_instruction_1);
    CPPUNIT_TEST(test_get_instruction_2);
    CPPUNIT_TEST(test_get_instruction_3);
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_next_instruction_1);
    CPPUNIT_TEST(test_next_instruction_2);
    CPPUNIT_TEST(test_initialize_turn_1);
    CPPUNIT_TEST(test_initialize_turn_2);
    CPPUNIT_TEST(test_get_ahead_1);
    CPPUNIT_TEST(test_get_ahead_2);
    CPPUNIT_TEST(test_get_ahead_3);
    CPPUNIT_TEST(test_get_ahead_4);
    CPPUNIT_TEST(test_creature_add_1);
    CPPUNIT_TEST(test_creature_add_2);
    CPPUNIT_TEST(test_clook_left_1);
    CPPUNIT_TEST(test_clook_left_2);
    CPPUNIT_TEST(test_clook_left_3);
    CPPUNIT_TEST(test_clook_left_4);
    CPPUNIT_TEST(test_clook_left_5);
    CPPUNIT_TEST(test_clook_right_1);
    CPPUNIT_TEST(test_clook_right_2);
    CPPUNIT_TEST(test_clook_right_3);
    CPPUNIT_TEST(test_clook_right_4);
    CPPUNIT_TEST(test_clook_right_5);
    CPPUNIT_TEST(test_cgo_1);
    CPPUNIT_TEST(test_cgo_2);
    CPPUNIT_TEST(test_cif_enemy_1);
    CPPUNIT_TEST(test_cif_enemy_2);
    CPPUNIT_TEST(test_cif_enemy_3);
    CPPUNIT_TEST(test_cinfect_1);
    CPPUNIT_TEST(test_chop_1);
    CPPUNIT_TEST(test_chop_2);
    CPPUNIT_TEST(test_cif_random_1);
    CPPUNIT_TEST(test_cif_random_2);
    CPPUNIT_TEST(test_world_constructor_1);
    CPPUNIT_TEST(test_world_constructor_2);
    CPPUNIT_TEST(test_add_creature_1);
    CPPUNIT_TEST(test_add_creature_2);
    CPPUNIT_TEST(test_add_creature_3);
    CPPUNIT_TEST(test_add_creature_4);
    CPPUNIT_TEST(test_wif_empty_1);
    CPPUNIT_TEST(test_wif_empty_2);
    CPPUNIT_TEST(test_wif_empty_3);
    CPPUNIT_TEST(test_wif_wall_1);
    CPPUNIT_TEST(test_wif_wall_2);
    CPPUNIT_TEST(test_wif_wall_3);
    CPPUNIT_TEST(test_wif_enemy_1);
    CPPUNIT_TEST(test_wif_enemy_2);
    CPPUNIT_TEST(test_wif_enemy_3);
    CPPUNIT_TEST(test_wif_enemy_4);
    CPPUNIT_TEST(test_winfect_1);
    CPPUNIT_TEST(test_winfect_2);
    CPPUNIT_TEST(test_winfect_3);
    CPPUNIT_TEST(test_whop_1);
    CPPUNIT_TEST(test_whop_2);
    CPPUNIT_TEST(test_whop_3);
    CPPUNIT_TEST(test_whop_4);
    CPPUNIT_TEST(test_execute_1);
    CPPUNIT_TEST(test_execute_2);
    CPPUNIT_TEST(test_next_turn_1);
    CPPUNIT_TEST(test_next_turn_2);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    //ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

