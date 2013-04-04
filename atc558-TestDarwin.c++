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


#define private public
#define protected public
#include "Darwin.h"


// ----------
// TestDarwin
// ----------

struct TestDarwin : CppUnit::TestFixture {

    // ---------
    // is_action
    // ---------
    void test_is_action_1() {
        CPPUNIT_ASSERT(is_action(HOP));
    }

    void test_is_action_2(){
        CPPUNIT_ASSERT(!is_action(IF_WALL));
    }

    void test_is_action_3(){
        CPPUNIT_ASSERT(is_action(LEFT));
    }

    // --------------------
    // Species::Constructor
    // --------------------
    void test_species_constructor_1() {
        Species s;
        CPPUNIT_ASSERT(s._n == '.');
        CPPUNIT_ASSERT(s._instrs.size() == 0);
    }

    void test_species_constructor_2(){
        Species s('f');
        CPPUNIT_ASSERT(s._n == 'f');
        CPPUNIT_ASSERT(s._instrs.size() == 0);
    }

    void test_species_constructor_3(){
        Species s1('f');
        s1.add_instr(LEFT, 0);
        s1.add_instr(GO, 0);
        Species s2(s1);
        CPPUNIT_ASSERT(s2._n == 'f');
        s1.add_instr(GO, 1);
        CPPUNIT_ASSERT(s2._instrs.size() == 2);
        s2.add_instr(LEFT, 3);
        s2.add_instr(LEFT, 3);
        CPPUNIT_ASSERT(s1._instrs.size() == 3);
        CPPUNIT_ASSERT(s2._instrs.size() == 4);
    }

    void test_species_constructor_4(){
        Species s1('f');
        s1.add_instr(LEFT, 0);
        s1.add_instr(GO, 0);
        Species s2;
        s2 = s1;
        CPPUNIT_ASSERT(s2._n == 'f');
        s1.add_instr(GO, 1);
        CPPUNIT_ASSERT(s2._instrs.size() == 2);
        s2.add_instr(LEFT, 3);
        s2.add_instr(LEFT, 3);
        CPPUNIT_ASSERT(s1._instrs.size() == 3);
        CPPUNIT_ASSERT(s2._instrs.size() == 4);
    }

    // ------------------
    // Species::add_instr
    // ------------------

    void test_species_add_instr_1() {
        Species s;
        CPPUNIT_ASSERT(s._instrs.size() == 0);
        s.add_instr(GO, 0);
        CPPUNIT_ASSERT(s._instrs.size() == 1);
    }

    void test_species_add_instr_2() {
        Species s;
        s.add_instr(GO, 0);
        s.add_instr(GO, 0);
        s.add_instr(GO, 0);
        s.add_instr(GO, 0);
        s.add_instr(GO, 0);
        CPPUNIT_ASSERT(s._instrs.size() == 5);
    }

    void test_species_add_instr_3() {
        Species s;
        s.add_instr(GO, 0);
        s.add_instr(GO, 0);
        s.add_instr(LEFT, 2);
        s.add_instr(GO, 0);
        s.add_instr(IF_RANDOM, 6);
        CPPUNIT_ASSERT(s._instrs.size() == 5);
        CPPUNIT_ASSERT(std::get<0>(s._instrs[2]) == LEFT);
        CPPUNIT_ASSERT(std::get<1>(s._instrs[4]) == 6);
        CPPUNIT_ASSERT(is_action(std::get<0>(s._instrs[2])));
        CPPUNIT_ASSERT(!is_action(std::get<0>(s._instrs[4])));
    }


    // -------------------
    // Species::next_instr
    // -------------------

    void test_species_next_instr_1(){
        Species s;
        s.add_instr(GO, 0);
        s.add_instr(LEFT, 0);
        s.add_instr(IF_RANDOM, 0);
        CPPUNIT_ASSERT(s.next_instr(0) == GO);
        CPPUNIT_ASSERT(s.next_instr(1) == LEFT);
        CPPUNIT_ASSERT(s.next_instr(2) == IF_RANDOM);
    }

    void test_species_next_instr_2() {
        Species s;
        try {
            s.next_instr(0);
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e){
            CPPUNIT_ASSERT(strcmp(e.what(),"Species::next_instr") == 0);
        }
    }

    void test_species_next_instr_3() {
        Species s;
        s.add_instr(GO, 3);
        s.add_instr(GO, 3);
        s.add_instr(GO, 3);
        try {
            s.next_instr(-5);
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e){
            CPPUNIT_ASSERT(strcmp(e.what(),"Species::next_instr") == 0);
        }
    }


    // ----------------
    // Species::next_pc
    // ----------------

    void test_species_next_pc_1(){
        Species s;
        s.add_instr(GO, 5);
        s.add_instr(LEFT, 0);
        s.add_instr(IF_RANDOM, 0);
        CPPUNIT_ASSERT(s.next_pc(0) == 5);
        CPPUNIT_ASSERT(s.next_pc(2) == 0);
    }

    void test_species_next_pc_2() {
        Species s;
        try {
            s.next_pc(0);
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e){
            CPPUNIT_ASSERT(strcmp(e.what(),"Species::next_pc") == 0);
        }
    }

    void test_species_next_pc_3() {
        Species s;
        s.add_instr(GO, 3);
        s.add_instr(GO, 3);
        s.add_instr(GO, 3);
        try {
            s.next_pc(5);
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e){
            CPPUNIT_ASSERT(strcmp(e.what(),"Species::next_pc") == 0);
        }
    }

    void test_species_next_pc_4() {
        Species s;
        s.add_instr(LEFT, 5);
        try {
            s.next_pc(0);
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Species::next_pc") == 0);
        }
    }

    // -------------
    // Species::draw
    // -------------

    void test_species_draw_1() {
        std::ostringstream w;
        Species s;
        s.draw(w);
        CPPUNIT_ASSERT(w.str() == ".");
        w << s;
        CPPUNIT_ASSERT(w.str() == "..");
    }

    void test_species_draw_2() {
        std::ostringstream w;
        Species s('f');
        s.draw(w);
        CPPUNIT_ASSERT(w.str() == "f");
        w << s;
        CPPUNIT_ASSERT(w.str() == "ff");
    }

    void test_species_draw_3() {
        std::ostringstream w;
        std::vector<Species> sv(3);
        sv[0] = Species('f');
        sv[2] = Species('h');
        for(size_t i = 0; i < 3; ++i)
            w << sv[i];
        CPPUNIT_ASSERT(w.str() == "f.h");
    }


    // ---------------------
    // Creature::constructor
    // ---------------------

    void test_creature_constructor_1() {
        Creature c;
        CPPUNIT_ASSERT(c._s._n == '.');
        CPPUNIT_ASSERT(c._d == -1);
    }

    void test_creature_constructor_2() {
        Species s1('f');
        s1.add_instr(LEFT, 3);
        Creature c(s1, NORTH);
        CPPUNIT_ASSERT(c._pc == 0);
        CPPUNIT_ASSERT(c._d == NORTH);
        CPPUNIT_ASSERT(c._s._n == s1._n);
        CPPUNIT_ASSERT(c.active == false);
    }

    void test_creature_constructor_3() {
        Species s1('h');
        s1.add_instr(LEFT, 0);
        Creature c1(s1, WEST);
        c1._pc = 7;
        Creature c2(c1);
        CPPUNIT_ASSERT(c1._pc == 7);
        CPPUNIT_ASSERT(c2._pc == 7);
        CPPUNIT_ASSERT(c1._s._n == c2._s._n);
        CPPUNIT_ASSERT(c1._s.next_instr(0) == c2._s.next_instr(0));
    }

    void test_creature_constructor_4() {
        Species s1('h');
        s1.add_instr(LEFT, 0);
        Species s2('f');
        s2.add_instr(GO, 5);
        Creature c1(s1, WEST);
        c1._pc = 7;
        Creature c2(s2, NORTH);
        c2._pc = 9;
        c2 = c1;
        CPPUNIT_ASSERT(c1._pc == 7);
        CPPUNIT_ASSERT(c2._pc == 0);
        CPPUNIT_ASSERT(c1._s._n == c2._s._n);
        CPPUNIT_ASSERT(c1._s.next_instr(0) == c2._s.next_instr(0));
        CPPUNIT_ASSERT(c2._d == NORTH);
    }

    void test_creature_constructor_5() {
        Species s1('f');
        try {
            Creature c1(s1, 5);
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Creature::Creature(Species&, const unsigned int)") == 0);
        }
        try {
            Creature c2(s1, -1);
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Creature::Creature(Species&, const unsigned int)") == 0);
        }
        Creature c3(s1, 2);
        CPPUNIT_ASSERT(c3._d == EAST);
    }

    // ---------------
    // Creature::Valid
    // ---------------

    void test_creature_valid_1() {
        Creature c;
        CPPUNIT_ASSERT(!c.valid());
    }

    void test_creature_valid_2() {
        Species s('f');
        Creature c(s, NORTH);
        CPPUNIT_ASSERT(c.valid());
    }

    void test_creature_valid_3() {
        Species s('f');
        Creature c1(s, NORTH);
        Creature c2(c1);
        CPPUNIT_ASSERT(c1.valid());
        CPPUNIT_ASSERT(c2.valid());
    }

    void test_creature_valid_4() {
        Species s('f');
        Creature c1(s, NORTH);
        Creature c2;
        CPPUNIT_ASSERT(!c2.valid());
        c2 = c1;
        CPPUNIT_ASSERT(c1.valid());
        CPPUNIT_ASSERT(c2.valid());
    }

    // --------------
    // Creature::Draw
    // --------------

    void test_creature_draw_1() {
        Creature c;
        std::ostringstream w;
        c.draw(w);
        CPPUNIT_ASSERT(w.str() == ".");
        w << c;
        CPPUNIT_ASSERT(w.str() == "..");
    }

    void test_creature_draw_2(){
        Species s('f');
        Creature c(s, NORTH);
        std::ostringstream w;
        c.draw(w);
        CPPUNIT_ASSERT(w.str() == "f");
        w << c;
        CPPUNIT_ASSERT(w.str() == "ff");
    }

    void test_creature_draw_3() {
        Species s1('f');
        Species s2('h');
        std::vector<Creature> cv(3);
        cv[0] = Creature(s1, NORTH);
        cv[2] = Creature(s2, EAST);
        std::ostringstream w;
        for(size_t i = 0; i < 3; ++i)
            w << cv[i];
        CPPUNIT_ASSERT(w.str() == "f.h");

    }

    // ------------------
    // Creature::get_next
    // ------------------

    void test_creature_get_next_1() {
        Species s('f');
        Creature c(s, NORTH);
        try {
            c.get_next();
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Species::next_instr") == 0);
        }
    }

    void test_creature_get_next_2() {
        Species s('f');
        s.add_instr(GO, 2);
        s.add_instr(LEFT, 1);
        Creature c(s, NORTH);
        CPPUNIT_ASSERT(c.get_next() == GO);
        c._pc = 1;
        c.active = false;
        CPPUNIT_ASSERT(c.get_next() == LEFT);
    }

    void test_creature_get_next_3() {
        Species s('f');
        s.add_instr(GO, 2);
        s.add_instr(LEFT, 1);
        Creature c(s, NORTH);
        CPPUNIT_ASSERT(c.get_next() == GO);
        c._pc = 4;
        c.active = false;
        try {
            c.get_next();
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Species::next_instr") == 0);
        } 
    }

    // -------------------
    // Creature::opdate_pc
    // -------------------

    void test_creature_update_pc_1() {
        Species s('f');
        s.add_instr(HOP, 8);
        s.add_instr(GO, 0);
        Creature c(s, NORTH);
        CPPUNIT_ASSERT(c._pc == 0);
        c.update_pc(true);
        CPPUNIT_ASSERT(c._pc == 1);
        c.update_pc(true);
        CPPUNIT_ASSERT(c._pc == 0);
    }

    void test_creature_update_pc_2() {
        Species s('f');
        s.add_instr(HOP, 8);
        s.add_instr(GO, 0);
        Creature c(s, NORTH);
        c.update_pc(true);
        c.update_pc(false);
        CPPUNIT_ASSERT(c._pc == 2);
    }

    void test_creature_update_pc_3() {
        Species s('f');
        Creature c(s, NORTH);
        try {
            c.update_pc(true);
            CPPUNIT_ASSERT(false);
        } catch(std::out_of_range& e){
            CPPUNIT_ASSERT(strcmp(e.what(), "Species::next_instr") == 0);
        }
    }

    // -------------------
    // Creature::turn_left
    // -------------------

    void test_creature_turn_left_1() {
        Species s('f');
        s.add_instr(LEFT, 0);
        Creature c(s, WEST);
        c.get_next();
        c.turn_left();
        CPPUNIT_ASSERT(c._d == SOUTH);
    }

    void test_creature_turn_left_2() {
        Species s('f');
        s.add_instr(LEFT, 0);
        Creature c(s, SOUTH);
        c.get_next();
        c.turn_left();
        CPPUNIT_ASSERT(c._d == EAST);
    }

    void test_creature_turn_left_3() {
        Species s('f');
        s.add_instr(LEFT, 0);
        Creature c(s, EAST);
        c.get_next();
        c.turn_left();
        CPPUNIT_ASSERT(c._d == NORTH);
    }

    void test_creature_turn_left_4() {
        Species s('f');
        s.add_instr(LEFT, 0);
        Creature c(s, NORTH);
        c.get_next();
        c.turn_left();
        CPPUNIT_ASSERT(c._d == WEST);
    }

    void test_creature_turn_left_5() {
        Species s('f');
        s.add_instr(LEFT, 0);
        Creature c(s, NORTH);
        c.turn_left();
        CPPUNIT_ASSERT(c._d == NORTH);
    }


    // --------------------
    // Creature::turn_right
    // --------------------

    void test_creature_turn_right_1() {
        Species s('f');
        s.add_instr(RIGHT, 0);
        Creature c(s, WEST);
        c.get_next();
        c.turn_right();
        CPPUNIT_ASSERT(c._d == NORTH);
    }

    void test_creature_turn_right_2() {
        Species s('f');
        s.add_instr(RIGHT, 0);
        Creature c(s, NORTH);
        c.get_next();
        c.turn_right();
        CPPUNIT_ASSERT(c._d == EAST);
    }

    void test_creature_turn_right_3() {
        Species s('f');
        s.add_instr(RIGHT, 0);
        Creature c(s, EAST);
        c.get_next();
        c.turn_right();
        CPPUNIT_ASSERT(c._d == SOUTH);
    }

    void test_creature_turn_right_4() {
        Species s('f');
        s.add_instr(RIGHT, 0);
        Creature c(s, SOUTH);
        c.get_next();
        c.turn_right();
        CPPUNIT_ASSERT(c._d == WEST);
    }

    void test_creature_turn_right_5() {
        Species s('f');
        s.add_instr(RIGHT, 0);
        Creature c(s, SOUTH);
        c.turn_right();
        CPPUNIT_ASSERT(c._d == SOUTH);
    }


    // -----------------
    // Board::Contructor
    // -----------------

    void test_board_constructor_1() {
        Board b(1, 1);
        CPPUNIT_ASSERT(b._r == 1);
        CPPUNIT_ASSERT(b._c == 1);
        Creature& c = std::get<0>(b._b[0][0]);
        size_t& round = std::get<1>(b._b[0][0]);
        CPPUNIT_ASSERT(round == 0);
        CPPUNIT_ASSERT(c._s._n == '.');
        CPPUNIT_ASSERT(!c.valid());
    }

    void test_board_constructor_2() {
        Board b(100, 100);
        size_t& r = std::get<1>(b._b[99][99]);
        r = 15;
        Creature& c = std::get<0>(b._b[37][82]);
        c = Creature('f', NORTH);
        CPPUNIT_ASSERT(b._b[0][0].first._s._n == '.');
        CPPUNIT_ASSERT(b._b[37][82].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[99][99].second == 15);
    }

    void test_board_constructor_3() {
        Board b(10, 10);
        CPPUNIT_ASSERT(b._r == 10);
        CPPUNIT_ASSERT(b._r == 10);
        CPPUNIT_ASSERT(b._cur_round == 0);
        Creature* cp = &std::get<0>(b._b[5][5]);
        CPPUNIT_ASSERT(!b._b[5][5].first.valid());
        *cp = Creature('f', NORTH);
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        std::swap(b._b[5][5], b._b[3][8]);
        CPPUNIT_ASSERT(!b._b[5][5].first.valid());
        CPPUNIT_ASSERT(b._b[3][8].first.valid());
        CPPUNIT_ASSERT(b._b[5][5].first._s._n == '.');
        CPPUNIT_ASSERT(b._b[3][8].first._s._n == 'f');
    }


    // -----------
    // Board::draw
    // -----------

    void test_board_draw_1() {
        Board b(1, 1);
        std::ostringstream w1, w2;
        b.draw(w1);
        w2 << b;
        CPPUNIT_ASSERT(w1.str() == w2.str());
        CPPUNIT_ASSERT(w1.str() == "  0\n0 .\n\n");
    }

    void test_board_draw_2() {
        Board b(3, 3);
        std::ostringstream w;
        std::get<0>(b._b[1][1]) = Creature('f',NORTH);
        w << b;
        CPPUNIT_ASSERT(w.str() == "  012\n0 ...\n1 .f.\n2 ...\n\n");
    }

    void test_board_draw_3() {
        Board b(3, 3);
        std::ostringstream w;
        std::get<0>(b._b[1][1]) = Creature('f',NORTH);
        std::swap(b._b[2][1], b._b[1][1]);
        b._cur_round = 3;
        w << b;
        CPPUNIT_ASSERT(w.str() == "  012\n0 ...\n1 ...\n2 .f.\n\n");
    }


    // -------------------
    // Board::add_creature
    // -------------------

    void test_board_add_creature_1() {
        Species s('f');
        Creature c(s, NORTH);
        Board b(1,1);
        b.add_creature(c, 0, 0);
        CPPUNIT_ASSERT(b._b[0][0].first._s._n == 'f');
    }

    void test_board_add_creature_2(){
        Species s('f');
        Creature c(s, NORTH);
        Board b(3,3);
        b.add_creature(c, 0, 0);
        b.add_creature(c, 1, 1);
        b.add_creature(c, 2, 2);
        CPPUNIT_ASSERT(b._b[0][0].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[1][1].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[2][2].first._s._n == 'f');

    }

    void test_board_add_creature_3() {
        Species s('f');
        Creature c(s, NORTH);
        Board b(3, 3);
        try {
            b.add_creature(c, 5, 5);
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& e) {
            CPPUNIT_ASSERT(strcmp(e.what(), "Board::add_creature") == 0);
        }
    }

    // ------------------------
    // Board::has_next_creature
    // ------------------------

    void test_board_has_next_creature_1(){
        Board b(10, 10);
        b._cur_round = 1;
        CPPUNIT_ASSERT(!b.has_next_creature());
    }

    void test_board_has_next_creature_2() {
        Board b(10, 10);
        b._cur_round = 1;
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 5, 5);
        Creature* cp = &std::get<0>(b._b[5][5]);
        CPPUNIT_ASSERT(cp->_s._n == 'f');
        CPPUNIT_ASSERT(cp->valid());
        CPPUNIT_ASSERT(std::get<0>(b._b[5][5]).valid());
        CPPUNIT_ASSERT(b.has_next_creature());
    }

    void test_board_has_next_creature_3() {
        Board b(10, 10);
        b._cur_round = 1;
        Creature c(Species('f'), EAST);
        b.add_creature(c, 2, 3);
        b.add_creature(c, 5, 5);
        b.add_creature(c, 6, 7);
        CPPUNIT_ASSERT(b.has_next_creature());
        std::get<1>(b._b[2][3]) = 1;
        CPPUNIT_ASSERT(b.has_next_creature());
        std::get<1>(b._b[5][5]) = 1;
        CPPUNIT_ASSERT(b.has_next_creature());
        std::get<1>(b._b[6][7]) = 1;
        CPPUNIT_ASSERT(!b.has_next_creature());
    }

    // -----------------------------
    // Board::test_get_next_creature
    // -----------------------------

    void test_board_get_next_creature_1(){
        Board b(1, 1);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 0, 0);
        b._cur_round = 1;
        CPPUNIT_ASSERT(b.has_next_creature());
        CPPUNIT_ASSERT(b.get_next_creature()->valid());
    }

    void test_board_get_next_creature_2(){
        Board b(10, 10);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        CPPUNIT_ASSERT(b.has_next_creature());
        CPPUNIT_ASSERT(b.get_next_creature()->valid());
        CPPUNIT_ASSERT(!b.has_next_creature());
    }

    void test_board_get_next_creature_3(){
        Board b(10, 10);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 0, 0);
        b.add_creature(c, 5, 5);
        b.add_creature(c, 9, 9);
        b._cur_round = 1;
        CPPUNIT_ASSERT(b.has_next_creature());
        CPPUNIT_ASSERT(b.get_next_creature()->valid());
        CPPUNIT_ASSERT(b.has_next_creature());
        CPPUNIT_ASSERT(b.get_next_creature()->valid());
        CPPUNIT_ASSERT(b.has_next_creature());
        CPPUNIT_ASSERT(b.get_next_creature()->valid());
        CPPUNIT_ASSERT(!b.has_next_creature());
    }


    // --------------
    // Board::if_wall
    // --------------

    void test_board_if_wall_1(){
        Board b(10, 10);
        Creature c1(Species('f'), EAST);
        b.add_creature(c1, 5, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(!b.if_wall());
    }

    void test_board_if_wall_2(){
        Board b(10, 10);
        Creature c1(Species('f'), EAST);
        b.add_creature(c1, 5, 9);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b.if_wall());
    }

    void test_board_if_wall_3(){
        Board b(10, 10);
        Creature c1(Species('f'), SOUTH);
        b.add_creature(c1, 9, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b.if_wall());
    }

    // ---------------
    // Board::if_enemy
    // ---------------

    void test_board_if_enemy_1(){
        Board b(10, 10);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(!b.if_enemy());
    }

    void test_board_if_enemy_2(){
        Board b(10, 10);
        Creature c1(Species('f'), SOUTH);
        Creature c2(Species('h'), EAST);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b.if_enemy());
    }

    void test_board_if_enemy_3(){
        Board b(10, 10);
        Creature c1(Species('f'), SOUTH);
        Creature c2(Species('f'), EAST);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(!b.if_enemy());
    }


    // ----------------
    // Board::if_enmpty
    // ----------------

    void test_board_if_empty_1(){
        Board b(10, 10);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b.if_empty());
    }

    void test_board_if_empty_2(){
        Board b(10, 10);
        Creature c1(Species('f'), SOUTH);
        Creature c2(Species('h'), EAST);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(!b.if_empty());
    }

    void test_board_if_empty_3(){
        Board b(10, 10);
        Creature c1(Species('f'), SOUTH);
        Creature c2(Species('f'), EAST);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(!b.if_empty());
    }

    // ----------
    // Board::hop
    // ----------

    void test_board_hop_1(){
        Board b(10, 10);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        b.hop();
        CPPUNIT_ASSERT(!b._b[5][5].first.valid());
        CPPUNIT_ASSERT(b._b[4][5].first.valid());
    }

    void test_board_hop_2(){
        Board b(10, 10);
        Creature c(Species('f'), EAST);
        b.add_creature(c, 5, 9);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][9].first.valid());
        b.hop();
        CPPUNIT_ASSERT(b._b[5][9].first.valid());

    }

    void test_board_hop_3(){
        Board b(10, 10);
        Creature c(Species('f'), SOUTH);
        b.add_creature(c, 5, 5);
        b.add_creature(c, 6, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        b.hop();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());

    }

    // -------------
    // Board::infect
    // -------------

    void test_board_infect_1(){
        Board b(10, 10);
        Creature c(Species('f'), NORTH);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        b.infect();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        CPPUNIT_ASSERT(!b._b[4][5].first.valid());
    }

    void test_board_infect_2(){
        Board b(10, 10);
        Creature c(Species('f'), EAST);
        b.add_creature(c, 5, 9);
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][9].first.valid());
        b.infect();
        CPPUNIT_ASSERT(b._b[5][9].first.valid());

    }

    void test_board_infect_3(){
        Board b(10, 10);
        Creature c(Species('f'), SOUTH);
        b.add_creature(c, 5, 5);
        b.add_creature(c, 6, 5);
        b._cur_round = 1;
        Creature& c2 = std::get<0>(b._b[6][5]);
        c2._pc = 4;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        b.infect();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        CPPUNIT_ASSERT(b._b[6][5].first.valid());
        CPPUNIT_ASSERT(b._b[6][5].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[6][5].first._pc == 4);

    }

    void test_board_infect_4(){
        Board b(10, 10);
        Creature c1(Species('f'), SOUTH);
        Creature c2(Species('h'), SOUTH);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        Creature& c = std::get<0>(b._b[6][5]);
        c._pc = 4;
        b._cur_round = 1;
        b.has_next_creature();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        CPPUNIT_ASSERT(b._b[5][5].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[6][5].first.valid());
        CPPUNIT_ASSERT(b._b[6][5].first._s._n == 'h');
        b.infect();
        CPPUNIT_ASSERT(b._b[5][5].first.valid());
        CPPUNIT_ASSERT(b._b[5][5].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[6][5].first.valid());
        CPPUNIT_ASSERT(b._b[6][5].first._s._n == 'f');
        CPPUNIT_ASSERT(b._b[6][5].first._pc == 0);
    }

    // ----
    // Game
    // ----

    void test_game_constructor_1() {
        std::ostringstream w;
        Board b(5, 5);
        Game g(b, w);
        CPPUNIT_ASSERT(true);
    }

    void test_game_constructor_2() {
        std::ostringstream w;
        Board b(10, 10);
        Game g(b, w);
        CPPUNIT_ASSERT(g._b._r == 10);
    }

    void test_game_constructor_3() {
        std::ostringstream w;
        Board b(5, 5);
        Game g(b, w);
        CPPUNIT_ASSERT(g._b._r == 5);
    }

    // ------------------
    // Game::handle_instr
    // ------------------

    void test_game_handle_instr_1() {
        Species s('f');
        s.add_instr(HOP, 0);
        Creature c(s, SOUTH);
        Board b(10, 10);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* c1 = b.get_next_creature();
        Instr i = c1->get_next();
        bool act = g.handle_instr(c1, i);
        CPPUNIT_ASSERT(act);
        CPPUNIT_ASSERT(!b._b[5][5].first.valid());
        CPPUNIT_ASSERT(b._b[6][5].first.valid());
    }

    void test_game_handle_instr_2() {
        Species s('f');
        s.add_instr(LEFT, 0);
        Creature c(s, SOUTH);
        Board b(10, 10);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* c1 = b.get_next_creature();
        Instr i = c1->get_next();
        bool act = g.handle_instr(c1, i);
        CPPUNIT_ASSERT(act);
        CPPUNIT_ASSERT(std::get<0>(b._b[5][5])._d == EAST);
    }

    void test_game_handle_instr_3() {
        Species s('f');
        s.add_instr(RIGHT, 0);
        Creature c(s, SOUTH);
        Board b(10, 10);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* c1 = b.get_next_creature();
        Instr i = c1->get_next();
        CPPUNIT_ASSERT(c1->active);
        bool act = g.handle_instr(c1, i);
        CPPUNIT_ASSERT(act);
        CPPUNIT_ASSERT(std::get<0>(b._b[5][5])._d == WEST);
    }


    void test_game_handle_instr_4() {
        Species s('f');
        s.add_instr(INFECT, 0);
        Creature c1(s, SOUTH);
        Creature c2(Species('h'), NORTH);
        Board b(10, 10);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* cp1 = b.get_next_creature();
        Instr i = cp1->get_next();
        CPPUNIT_ASSERT(cp1->active);
        CPPUNIT_ASSERT(std::get<0>(b._b[6][5])._s._n == 'h');
        bool act = g.handle_instr(cp1, i);
        CPPUNIT_ASSERT(act);
        CPPUNIT_ASSERT(std::get<0>(b._b[6][5])._s._n == 'f');
    }


    void test_game_handle_instr_5() {
        Species s('f');
        s.add_instr(IF_EMPTY, 5);
        Creature c1(s, SOUTH);
        Creature c2(Species('f'), NORTH);
        Board b(10, 10);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* cp1 = b.get_next_creature();
        Instr i = cp1->get_next();
        CPPUNIT_ASSERT(cp1->active);
        bool act = g.handle_instr(cp1, i);
        CPPUNIT_ASSERT(!act);
        CPPUNIT_ASSERT(std::get<0>(b._b[5][5])._pc == 1);
    }


    void test_game_handle_instr_6() {
        Species s('f');
        s.add_instr(IF_ENEMY, 5);
        Creature c1(s, SOUTH);
        Creature c2(Species('h'), NORTH);
        Board b(10, 10);
        b.add_creature(c1, 5, 5);
        b.add_creature(c2, 6, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* cp1 = b.get_next_creature();
        Instr i = cp1->get_next();
        CPPUNIT_ASSERT(cp1->active);
        bool act = g.handle_instr(cp1, i);
        CPPUNIT_ASSERT(!act);
        CPPUNIT_ASSERT(!cp1->active);
        CPPUNIT_ASSERT(std::get<0>(b._b[5][5])._pc == 5);
    }


    void test_game_handle_instr_7() {
        Species s('f');
        s.add_instr(IF_WALL, 5);
        Creature c(s, SOUTH);
        Board b(10, 10);
        b.add_creature(c, 9, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* c1 = b.get_next_creature();
        Instr i = c1->get_next();
        CPPUNIT_ASSERT(c1->active);
        bool act = g.handle_instr(c1, i);
        CPPUNIT_ASSERT(!act);
        CPPUNIT_ASSERT(std::get<0>(b._b[9][5])._pc == 5);
    }


    void test_game_handle_instr_8() {
        Species s('f');
        srand(0);
        s.add_instr(IF_RANDOM, 5);
        Creature c(s, SOUTH);
        Board b(10, 10);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* c1 = b.get_next_creature();
        Instr i = c1->get_next();
        CPPUNIT_ASSERT(c1->active);
        bool act = g.handle_instr(c1, i);
        CPPUNIT_ASSERT(!act);
    }


    void test_game_handle_instr_9() {
        Species s('f');
        s.add_instr(GO, 5);
        Creature c(s, SOUTH);
        Board b(10, 10);
        b.add_creature(c, 5, 5);
        b._cur_round = 1;
        std::ostringstream w;
        Game g(b, w);
        bool has = b.has_next_creature();
        CPPUNIT_ASSERT(has);
        Creature* c1 = b.get_next_creature();
        Instr i = c1->get_next();
        CPPUNIT_ASSERT(c1->active);
        bool act = g.handle_instr(c1, i);
        CPPUNIT_ASSERT(!act);
        CPPUNIT_ASSERT(std::get<0>(b._b[5][5])._pc == 5);
    }


    // ---------------
    // Game::take_turn
    // ---------------

    void test_game_take_turn_1(){
        Species FOOD('f');
        FOOD.add_instr(LEFT, 0);
        FOOD.add_instr(GO, 0);

        Species HOPPER('h');
        HOPPER.add_instr(HOP, 0);
        HOPPER.add_instr(GO, 0);

        Board b(8, 8);
        b.add_creature(Creature(FOOD, EAST), 0, 0);
        b.add_creature(Creature(HOPPER, NORTH), 3, 3);
        b.add_creature(Creature(HOPPER, EAST), 3, 4);
        b.add_creature(Creature(HOPPER, SOUTH), 4, 4);
        b.add_creature(Creature(HOPPER, WEST), 4, 3);
        b.add_creature(Creature(FOOD, NORTH), 7, 7);
        Game g(b, std::cout);
        g.take_turn();
        CPPUNIT_ASSERT(b._cur_round == 1);
    }

    void test_game_take_turn_2(){
        Species FOOD('f');
        FOOD.add_instr(LEFT, 0);
        FOOD.add_instr(GO, 0);

        Species HOPPER('h');
        HOPPER.add_instr(HOP, 0);
        HOPPER.add_instr(GO, 0);

        Board b(8, 8);
        b.add_creature(Creature(FOOD, EAST), 0, 0);
        b.add_creature(Creature(HOPPER, NORTH), 3, 3);
        b.add_creature(Creature(HOPPER, EAST), 3, 4);
        b.add_creature(Creature(HOPPER, SOUTH), 4, 4);
        b.add_creature(Creature(HOPPER, WEST), 4, 3);
        b.add_creature(Creature(FOOD, NORTH), 7, 7);
        Game g(b, std::cout);
        g.take_turn();
        g.take_turn();
        CPPUNIT_ASSERT(b._cur_round == 2);
        CPPUNIT_ASSERT(b._b[1][3].first == b._b[4][1].first);
    }

    void test_game_take_turn_3(){
        Species FOOD('f');
        FOOD.add_instr(LEFT, 0);
        FOOD.add_instr(GO, 0);

        Species HOPPER('h');
        HOPPER.add_instr(HOP, 0);
        HOPPER.add_instr(GO, 0);

        Board b(8, 8);
        b.add_creature(Creature(FOOD, EAST), 0, 0);
        b.add_creature(Creature(HOPPER, NORTH), 3, 3);
        b.add_creature(Creature(HOPPER, EAST), 3, 4);
        b.add_creature(Creature(HOPPER, SOUTH), 4, 4);
        b.add_creature(Creature(HOPPER, WEST), 4, 3);
        b.add_creature(Creature(FOOD, NORTH), 7, 7);
        Game g(b, std::cout);
        g.take_turn();
        CPPUNIT_ASSERT(b._cur_round == 1);
    }


    // ---------
    // Game::run
    // ---------

    void test_game_run_1(){
        Species FOOD('f');
        FOOD.add_instr(LEFT, 0);
        FOOD.add_instr(GO, 0);

        Species HOPPER('h');
        HOPPER.add_instr(HOP, 0);
        HOPPER.add_instr(GO, 0);

        std::ostringstream w;

        Board b(8, 8);
        b.add_creature(Creature(FOOD, EAST), 0, 0);
        b.add_creature(Creature(HOPPER, NORTH), 3, 3);
        b.add_creature(Creature(HOPPER, EAST), 3, 4);
        b.add_creature(Creature(HOPPER, SOUTH), 4, 4);
        b.add_creature(Creature(HOPPER, WEST), 4, 3);
        b.add_creature(Creature(FOOD, NORTH), 7, 7);
        Game g(b, w);
        g.run(5, 1);
        CPPUNIT_ASSERT(b._b[0][0].first == b._b[7][7].first);
        CPPUNIT_ASSERT(b._b[0][3].first == b._b[3][7].first);
        CPPUNIT_ASSERT(b._b[4][0].first == b._b[3][7].first);
        CPPUNIT_ASSERT(b._b[7][4].first == b._b[3][7].first);

    }

    void test_game_run_2(){
        srand(0);
        Species FOOD('f');
        FOOD.add_instr(LEFT, 0);
        FOOD.add_instr(GO, 0);

        Species HOPPER('h');
        HOPPER.add_instr(HOP, 0);
        HOPPER.add_instr(GO, 0);

        Species ROVER('r');
        ROVER.add_instr(IF_ENEMY, 9);
        ROVER.add_instr(IF_EMPTY, 7);
        ROVER.add_instr(IF_RANDOM, 5);
        ROVER.add_instr(LEFT, 0);
        ROVER.add_instr(GO, 0);
        ROVER.add_instr(RIGHT, 0);
        ROVER.add_instr(GO, 0);
        ROVER.add_instr(HOP, 0);
        ROVER.add_instr(GO, 0);
        ROVER.add_instr(INFECT, 0);
        ROVER.add_instr(GO, 0);

        Species TRAP('t');
        TRAP.add_instr(IF_ENEMY, 3);
        TRAP.add_instr(LEFT, 0);
        TRAP.add_instr(GO, 0);
        TRAP.add_instr(INFECT, 0);
        TRAP.add_instr(GO, 0);

        std::ostringstream w;

        Board b(7, 9);
        b.add_creature(Creature(TRAP, SOUTH), 0, 0);
        b.add_creature(Creature(HOPPER, EAST), 3, 2);
        b.add_creature(Creature(ROVER, NORTH), 5, 4);
        b.add_creature(Creature(TRAP, WEST), 6, 8);
        Game g(b, w);
        g.run(5, 1);
        CPPUNIT_ASSERT(b._b[0][0].first == b._b[6][8].first);
        CPPUNIT_ASSERT(b._b[1][4].first == b._b[3][7].first);
    }

    void test_game_run_3(){

    }




    // ---------
    // TestSuite
    // ---------

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_is_action_1);
    CPPUNIT_TEST(test_is_action_2);
    CPPUNIT_TEST(test_is_action_3);
    CPPUNIT_TEST(test_species_constructor_1);
    CPPUNIT_TEST(test_species_constructor_2);
    CPPUNIT_TEST(test_species_constructor_3);
    CPPUNIT_TEST(test_species_constructor_4);
    CPPUNIT_TEST(test_species_add_instr_1);
    CPPUNIT_TEST(test_species_add_instr_2);
    CPPUNIT_TEST(test_species_add_instr_3);
    CPPUNIT_TEST(test_species_next_instr_1);
    CPPUNIT_TEST(test_species_next_instr_2);
    CPPUNIT_TEST(test_species_next_instr_3);
    CPPUNIT_TEST(test_species_next_pc_1);
    CPPUNIT_TEST(test_species_next_pc_2);
    CPPUNIT_TEST(test_species_next_pc_3);
    CPPUNIT_TEST(test_species_next_pc_4);
    CPPUNIT_TEST(test_species_draw_1);
    CPPUNIT_TEST(test_species_draw_2);
    CPPUNIT_TEST(test_species_draw_3);
    CPPUNIT_TEST(test_creature_constructor_1);
    CPPUNIT_TEST(test_creature_constructor_2);
    CPPUNIT_TEST(test_creature_constructor_3);
    CPPUNIT_TEST(test_creature_constructor_4);
    CPPUNIT_TEST(test_creature_constructor_5);
    CPPUNIT_TEST(test_creature_valid_1);
    CPPUNIT_TEST(test_creature_valid_2);
    CPPUNIT_TEST(test_creature_valid_3);
    CPPUNIT_TEST(test_creature_valid_4);
    CPPUNIT_TEST(test_creature_draw_1);
    CPPUNIT_TEST(test_creature_draw_2);
    CPPUNIT_TEST(test_creature_draw_3); 
    CPPUNIT_TEST(test_creature_get_next_1);
    CPPUNIT_TEST(test_creature_get_next_2);
    CPPUNIT_TEST(test_creature_get_next_3);
    CPPUNIT_TEST(test_creature_update_pc_1);
    CPPUNIT_TEST(test_creature_update_pc_2);
    CPPUNIT_TEST(test_creature_update_pc_3);
    CPPUNIT_TEST(test_creature_turn_left_1);
    CPPUNIT_TEST(test_creature_turn_left_2);
    CPPUNIT_TEST(test_creature_turn_left_3);
    CPPUNIT_TEST(test_creature_turn_left_4);
    CPPUNIT_TEST(test_creature_turn_left_5);
    CPPUNIT_TEST(test_creature_turn_right_1);
    CPPUNIT_TEST(test_creature_turn_right_2);
    CPPUNIT_TEST(test_creature_turn_right_3);
    CPPUNIT_TEST(test_creature_turn_right_4);
    CPPUNIT_TEST(test_creature_turn_right_5);
    CPPUNIT_TEST(test_board_constructor_1);
    CPPUNIT_TEST(test_board_constructor_2);
    CPPUNIT_TEST(test_board_constructor_3);
    CPPUNIT_TEST(test_board_draw_1);
    CPPUNIT_TEST(test_board_draw_2);
    CPPUNIT_TEST(test_board_draw_3);
    CPPUNIT_TEST(test_board_add_creature_1);
    CPPUNIT_TEST(test_board_add_creature_2);
    CPPUNIT_TEST(test_board_add_creature_3);
    CPPUNIT_TEST(test_board_has_next_creature_1);
    CPPUNIT_TEST(test_board_has_next_creature_2);
    CPPUNIT_TEST(test_board_has_next_creature_3);
    CPPUNIT_TEST(test_board_get_next_creature_1);
    CPPUNIT_TEST(test_board_get_next_creature_2);
    CPPUNIT_TEST(test_board_get_next_creature_3);
    CPPUNIT_TEST(test_board_if_wall_1);
    CPPUNIT_TEST(test_board_if_wall_2);
    CPPUNIT_TEST(test_board_if_wall_3);
    CPPUNIT_TEST(test_board_if_enemy_1);
    CPPUNIT_TEST(test_board_if_enemy_2);
    CPPUNIT_TEST(test_board_if_enemy_3);
    CPPUNIT_TEST(test_board_if_empty_1);
    CPPUNIT_TEST(test_board_if_empty_2);
    CPPUNIT_TEST(test_board_if_empty_3);
    CPPUNIT_TEST(test_board_hop_1);
    CPPUNIT_TEST(test_board_hop_2);
    CPPUNIT_TEST(test_board_hop_3);
    CPPUNIT_TEST(test_board_infect_1);
    CPPUNIT_TEST(test_board_infect_2);
    CPPUNIT_TEST(test_board_infect_3);
    CPPUNIT_TEST(test_board_infect_4);
    CPPUNIT_TEST(test_game_constructor_1);
    CPPUNIT_TEST(test_game_constructor_2);
    CPPUNIT_TEST(test_game_constructor_3);
    CPPUNIT_TEST(test_game_handle_instr_1);
    CPPUNIT_TEST(test_game_handle_instr_2);
    CPPUNIT_TEST(test_game_handle_instr_3);
    CPPUNIT_TEST(test_game_handle_instr_4);
    CPPUNIT_TEST(test_game_handle_instr_5);
    CPPUNIT_TEST(test_game_handle_instr_6);
    CPPUNIT_TEST(test_game_handle_instr_7);
    CPPUNIT_TEST(test_game_handle_instr_8);
    CPPUNIT_TEST(test_game_handle_instr_9);
    CPPUNIT_TEST(test_game_take_turn_1);
    CPPUNIT_TEST(test_game_take_turn_2);
    CPPUNIT_TEST(test_game_take_turn_3);
    CPPUNIT_TEST(test_game_run_1);
    CPPUNIT_TEST(test_game_run_2);
    CPPUNIT_TEST(test_game_run_3);
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
