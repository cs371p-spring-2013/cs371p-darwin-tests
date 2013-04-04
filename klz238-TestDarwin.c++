#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#include "Darwin.h"

struct TestInstruction : CppUnit::TestFixture {
    void test_instr1 () {
        Instruction i(EInstruction::HOP);
        CPPUNIT_ASSERT(i.instruction() == EInstruction::HOP);
        CPPUNIT_ASSERT(i.argument() == -1);
    }
    void test_instr2 () {
        Instruction i(EInstruction::IFEMPTY, 3);
        CPPUNIT_ASSERT(i.instruction() == EInstruction::IFEMPTY);
        CPPUNIT_ASSERT(i.argument() == 3);
    }
    void test_instr3 () {
        Instruction i(EInstruction::IERROR);
        CPPUNIT_ASSERT(i.instruction() == EInstruction::IERROR);
        CPPUNIT_ASSERT(i.argument() == -1);
    }
    CPPUNIT_TEST_SUITE(TestInstruction);
    CPPUNIT_TEST(test_instr1);
    CPPUNIT_TEST(test_instr2);
    CPPUNIT_TEST(test_instr3);
    CPPUNIT_TEST_SUITE_END();
};

struct TestProgram : CppUnit::TestFixture {
    void test_ctor1 () {
        Program p;
        CPPUNIT_ASSERT(p.getInstruction(0).instruction() == EInstruction::IERROR);
    }
    void test_addi1 () {
        Program p;
        p.addInstruction(Instruction(EInstruction::HOP));
        CPPUNIT_ASSERT(p.getInstruction(0).instruction() == EInstruction::HOP);
    }
    void test_addi2 () {
        Program p;
        p.addInstruction(Instruction(EInstruction::GO, 0));
        CPPUNIT_ASSERT(p.getInstruction(0).argument() == 0);
    }
    void test_addi3 () {
        Program p;
        p.addInstruction(Instruction(EInstruction::HOP));
        p.addInstruction(Instruction(EInstruction::GO, 0));
        CPPUNIT_ASSERT(p.getInstruction(0).instruction() == EInstruction::HOP);
        CPPUNIT_ASSERT(p.getInstruction(1).instruction() == EInstruction::GO);
        CPPUNIT_ASSERT(p.getInstruction(1).argument()    == 0);
        CPPUNIT_ASSERT(p.getInstruction(2).instruction() == EInstruction::IERROR);
    }
    void test_addi21 () {
        Program p;
        p.addInstruction(HOP);
        CPPUNIT_ASSERT(p.getInstruction(0).instruction() == HOP);
    }
    void test_addi22 () {
        Program p;
        p.addInstruction(GO, 0);
        CPPUNIT_ASSERT(p.getInstruction(0).argument() == 0);
    }
    void test_addi23 () {
        Program p;
        p.addInstruction(HOP);
        p.addInstruction(GO, 0);
        CPPUNIT_ASSERT(p.getInstruction(0).instruction() == HOP);
        CPPUNIT_ASSERT(p.getInstruction(1).instruction() == GO);
        CPPUNIT_ASSERT(p.getInstruction(1).argument()    == 0);
        CPPUNIT_ASSERT(p.getInstruction(2).instruction() == IERROR);
    }
    void test_cpyctor1 () {
        Program p;
        p.addInstruction(Instruction(EInstruction::HOP));
        p.addInstruction(Instruction(EInstruction::GO, 0));
        Program p2(p);
        CPPUNIT_ASSERT(p == p2);
    }
    CPPUNIT_TEST_SUITE(TestProgram);
    CPPUNIT_TEST(test_ctor1);
    CPPUNIT_TEST(test_addi1);
    CPPUNIT_TEST(test_addi2);
    CPPUNIT_TEST(test_addi3);
    CPPUNIT_TEST(test_addi21);
    CPPUNIT_TEST(test_addi22);
    CPPUNIT_TEST(test_addi23);
    CPPUNIT_TEST(test_cpyctor1);
    CPPUNIT_TEST_SUITE_END();
};

struct TestSpecies : CppUnit::TestFixture {
    // test constructor / name() / id() / program()

    void test_constructor1 () {
        Program p;
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        Species s("food", 'f', p);
        CPPUNIT_ASSERT(s.name() == "food");
        CPPUNIT_ASSERT(s.id()   == 'f');
        CPPUNIT_ASSERT(s.program() == p);
    }

    void test_constructor2 () {
        Program p;
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        Species s("rover", 'r', p);
        CPPUNIT_ASSERT(s.name() == "rover");
        CPPUNIT_ASSERT(s.id()   == 'r');
        CPPUNIT_ASSERT(s.program() == p);
    }

    void test_constructor3 () {
        Program p;
        p.addInstruction(IFENEMY, 3);
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        p.addInstruction(INFECT);
        p.addInstruction(GO, 0);
        Species s("trap", 't', p);
        CPPUNIT_ASSERT(s.name() == "trap");
        CPPUNIT_ASSERT(s.id()   == 't');
        CPPUNIT_ASSERT(s.program() == p);
    }

    CPPUNIT_TEST_SUITE(TestSpecies);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST_SUITE_END();
};


struct TestCreature : CppUnit::TestFixture {
    // test constructor / name() / id()

    void test_constructor1 () {
        Program p;
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        Species s("food", 'f', p);

        Creature food(s);
        CPPUNIT_ASSERT(food.species()    == "food");
        CPPUNIT_ASSERT(food.isSpecies(s) == true);
        CPPUNIT_ASSERT(food.id()         == 'f');
    }

    void test_constructor2 () {
        Program p;
        p.addInstruction(HOP);
        p.addInstruction(GO, 0);
        Species s("hopper", 'h', p);

        Creature hopper(s);
        CPPUNIT_ASSERT(hopper.species()    == "hopper");
        CPPUNIT_ASSERT(hopper.isSpecies(s) == true);
        CPPUNIT_ASSERT(hopper.id()         == 'h');
    }

    void test_constructor3 () {
        Program p;
        p.addInstruction(IFENEMY, 3);
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        p.addInstruction(INFECT);
        p.addInstruction(GO, 0);
        Species s("trap", 't', p);

        Creature trap(s);
        CPPUNIT_ASSERT(trap.species()    == "trap");
        CPPUNIT_ASSERT(trap.isSpecies(s) == true);
        CPPUNIT_ASSERT(trap.id()         == 't');
    }

    // facing() / turnLeft() / turnRight()

    void test_facing1 () {
        Program p;
        p.addInstruction(IFENEMY, 3);
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        p.addInstruction(INFECT);
        p.addInstruction(GO, 0);
        Species s("trap", 't', p);

        Creature trap(s);

        CPPUNIT_ASSERT(trap.facing() == WEST);
    }

    void test_facing2 () {
        Program p;
        p.addInstruction(IFENEMY, 3);
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        p.addInstruction(INFECT);
        p.addInstruction(GO, 0);
        Species s("trap", 't', p);

        Creature trap(s);

        CPPUNIT_ASSERT(trap.facing() == WEST);
        trap.turnRight();
        CPPUNIT_ASSERT(trap.facing() == NORTH);
        trap.turnLeft();
        CPPUNIT_ASSERT(trap.facing() == WEST);
    }

    void test_facing3 () {
        Program p;
        p.addInstruction(IFENEMY, 3);
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        p.addInstruction(INFECT);
        p.addInstruction(GO, 0);
        Species s("trap", 't', p);

        Creature trap(s);

        CPPUNIT_ASSERT(trap.facing() == WEST);
        trap.turnLeft();
        CPPUNIT_ASSERT(trap.facing() == SOUTH);
        trap.turnRight();
        CPPUNIT_ASSERT(trap.facing() == WEST);
    }

    void test_infect1 () {
        Program p;
        p.addInstruction(IFENEMY, 3);
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        p.addInstruction(INFECT);
        p.addInstruction(GO, 0);
        Species s("trap", 't', p);

        Program p2;
        p2.addInstruction(LEFT);
        p2.addInstruction(GO, 0);
        Species s2("food", 'f', p2);

        Creature trap(s);
        Creature food(s2);

        CPPUNIT_ASSERT(food.species() == "food");
        CPPUNIT_ASSERT(trap.species() == "trap");

        food.infectWith(trap.type());
        CPPUNIT_ASSERT(food.species() == "trap");
        CPPUNIT_ASSERT(food.type() == trap.type());
    }

    CPPUNIT_TEST_SUITE(TestCreature);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST(test_facing1);
    CPPUNIT_TEST(test_facing2);
    CPPUNIT_TEST(test_facing3);
    CPPUNIT_TEST(test_infect1);
    CPPUNIT_TEST_SUITE_END();
};

struct TestSquare : CppUnit::TestFixture {
    void test_constructor1 () {
        Square x;
        CPPUNIT_ASSERT(x.creature() == NULL);
        CPPUNIT_ASSERT(x.hasCreature() == false);
    }
    void test_constructor2 () {
		Program p;
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        Species s("food", 'f', p);
        Creature food(s);
		Square x(&food);
		CPPUNIT_ASSERT(x.creature() == &food);
		CPPUNIT_ASSERT(x.hasCreature() == true);

    }
    void test_constructor3 () {
		Program p;
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        Species s("food", 'f', p);
        Creature food(s);
        Square x(&food);
        CPPUNIT_ASSERT(x.creature() == &food);
        CPPUNIT_ASSERT(x.hasCreature() == true);

		x = Square();
		CPPUNIT_ASSERT(x.creature() == NULL);
        CPPUNIT_ASSERT(x.hasCreature() == false);

    }
    CPPUNIT_TEST_SUITE(TestSquare);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructor2);
    CPPUNIT_TEST(test_constructor3);
    CPPUNIT_TEST_SUITE_END();
};

struct TestGrid : CppUnit::TestFixture {
	// test constructor, print, adding creature

    void test_addCreature1 () {
        Program p;
        p.addInstruction(LEFT);
        p.addInstruction(GO, 0);
        Species s("food", 'f', p);
        Creature food(s);

		Grid g(5,5);
		g.addCreature(&food, 3, 3);
		std::ostringstream w;
		w << g;
        CPPUNIT_ASSERT(w.str() == "  01234\n" \
                                  "0 .....\n" \
                                  "1 .....\n" \
                                  "2 .....\n" \
                                  "3 ...f.\n" \
                                  "4 .....");

    }

    void test_addCreature2 () {
        Program p;
        Species s("food", 'f', p);
        Creature food(s);

        Grid g(9,9);
        g.addCreature(&food, 3, 3);
		g.addCreature(&food, 8, 8);
     
        CPPUNIT_ASSERT(g.hasCreature(3,3) == true);
		CPPUNIT_ASSERT(g.hasCreature(8,8) == true);
		CPPUNIT_ASSERT(g.hasCreature(0,0) == false);

		g.addCreature(&food, 0,0);
		CPPUNIT_ASSERT(g.hasCreature(0,0) == true);
		std::ostringstream w;
		w << g;
		std::string expectedOutput  = "  012345678\n" \
					                  "0 f........\n" \
					                  "1 .........\n" \
					                  "2 .........\n" \
					                  "3 ...f.....\n" \
					                  "4 .........\n" \
					                  "5 .........\n" \
					                  "6 .........\n" \
					                  "7 .........\n" \
					                  "8 ........f";
		CPPUNIT_ASSERT(w.str() == expectedOutput);
    }

    void test_addCreature3 () {
        Program p;
        Species f("food", 'f', p);
        Creature food(f);

        Grid g(9,9);
        g.addCreature(&food, 1, 2);
        g.addCreature(&food, 8, 8);
        
        CPPUNIT_ASSERT(g.hasCreature(1,2) == true);
        CPPUNIT_ASSERT(g.hasCreature(8,8) == true);
        CPPUNIT_ASSERT(g.hasCreature(0,0) == false);

        Species h("hopper", 'h', p);
        Creature hopper(h);

		g.addCreature(&hopper, 0, 0);
		g.addCreature(&hopper, 2, 1);
        CPPUNIT_ASSERT(g.hasCreature(0,0) == true);
		CPPUNIT_ASSERT(g.hasCreature(2,1) == true);
		std::ostringstream w;
		w << g;
		std::string expectedOutput  = "  012345678\n" \
					                  "0 h........\n" \
					                  "1 ..f......\n" \
					                  "2 .h.......\n" \
					                  "3 .........\n" \
					                  "4 .........\n" \
					                  "5 .........\n" \
					                  "6 .........\n" \
					                  "7 .........\n" \
					                  "8 ........f";
		CPPUNIT_ASSERT(w.str() == expectedOutput);
    }

	void test_addCreature4 () {
        Program p;
        Species f("food", 'f', p);
        Creature food(f);

        Grid g(20,10);
        g.addCreature(&food, 0, 9);
        g.addCreature(&food, 19, 0);
        
        CPPUNIT_ASSERT(g.hasCreature(0,9) == true);
        CPPUNIT_ASSERT(g.hasCreature(19,0) == true);
        CPPUNIT_ASSERT(g.hasCreature(0,0) == false);

        Species h("hopper", 'h', p);
        Creature hopper(h);

		g.addCreature(&hopper, 0, 0);
		g.addCreature(&hopper, 19, 9);
        CPPUNIT_ASSERT(g.hasCreature(0,0) == true);
		CPPUNIT_ASSERT(g.hasCreature(19,9) == true);
		std::ostringstream w;
		w << g;
		std::string expectedOutput =  "  0123456789\n" \
			   		                  "0 h........f\n" \
			   		                  "1 ..........\n" \
			   		                  "2 ..........\n" \
			  		                  "3 ..........\n" \
			   		                  "4 ..........\n" \
			   		                  "5 ..........\n" \
			   		                  "6 ..........\n" \
			   		                  "7 ..........\n" \
			   		                  "8 ..........\n" \
			   		                  "9 ..........\n" \
			   		                  "0 ..........\n" \
			   		                  "1 ..........\n" \
			   		                  "2 ..........\n" \
			   		                  "3 ..........\n" \
			   		                  "4 ..........\n" \
	 		   		                  "5 ..........\n" \
			   		                  "6 ..........\n" \
			   		                  "7 ..........\n" \
			   		                  "8 ..........\n" \
			   		                  "9 f........h";
       CPPUNIT_ASSERT(w.str() == expectedOutput); 
    }

    void test_addCreature5 () {
        Program p;
        Species f("food", 'f', p);
        Creature food(f);

        Grid g(10,20);
        g.addCreature(&food, 1, 2);
        g.addCreature(&food, 9, 9);
        
        CPPUNIT_ASSERT(g.hasCreature(1,2) == true);
        CPPUNIT_ASSERT(g.hasCreature(9,9) == true);
        CPPUNIT_ASSERT(g.hasCreature(0,0) == false);

        Species h("hopper", 'h', p);
        Creature hopper(h);

		g.addCreature(&hopper, 0, 0);
		g.addCreature(&hopper, 9, 19);
        CPPUNIT_ASSERT(g.hasCreature(0,0) == true);
		CPPUNIT_ASSERT(g.hasCreature(9,19) == true);
		std::ostringstream w;
		w << g;
		std::string expectedOutput =  "  01234567890123456789\n" \
			   		                  "0 h...................\n" \
			   		                  "1 ..f.................\n" \
			   		                  "2 ....................\n" \
			  		                  "3 ....................\n" \
			   		                  "4 ....................\n" \
			   		                  "5 ....................\n" \
			   		                  "6 ....................\n" \
			   		                  "7 ....................\n" \
			   		                  "8 ....................\n" \
			   		                  "9 .........f.........h";
       CPPUNIT_ASSERT(w.str() == expectedOutput);
	}

    void test_removeCreature1 () {
        Program p;
        Species s("food", 'f', p);
        Creature food(s);
        Grid g(5,5);
        g.addCreature(&food, 0, 0);
        CPPUNIT_ASSERT(g.hasCreature(0, 0));
        g.removeCreature(0, 0);
        CPPUNIT_ASSERT(!g.hasCreature(0, 0));
    }

    void test_removeCreature2 () {
        Program p;
        Species s("food", 'f', p);
        Creature food(s);
        Grid g(10, 10);
        g.addCreature(&food, 3, 5);
        g.addCreature(&food, 3, 3);
        CPPUNIT_ASSERT(g.hasCreature(3,3));
        CPPUNIT_ASSERT(g.hasCreature(3,5));
        g.removeCreature(3,3);
        CPPUNIT_ASSERT(g.hasCreature(3,5));
        CPPUNIT_ASSERT(!g.hasCreature(3,3));
    }

    void test_wall () {
        Grid g(10, 10);
        // looking from 0,0 N/W
        CPPUNIT_ASSERT(!g.isWall( 0,  0));
        CPPUNIT_ASSERT( g.isWall(-1,  1));
        CPPUNIT_ASSERT( g.isWall( 1, -1));
        // looking from 0,9 N/E
        CPPUNIT_ASSERT(!g.isWall( 0,  9));
        CPPUNIT_ASSERT( g.isWall(-1, 10));
        CPPUNIT_ASSERT( g.isWall( 0, 10));
        // looking from 9,0 W/S
        CPPUNIT_ASSERT(!g.isWall( 9,  0));
        CPPUNIT_ASSERT( g.isWall( 9, -1));
        CPPUNIT_ASSERT( g.isWall( 10, 0));
        // looking from 9,9 E/S
        CPPUNIT_ASSERT(!g.isWall( 9,  9));
        CPPUNIT_ASSERT( g.isWall( 9, 10));
        CPPUNIT_ASSERT( g.isWall( 10, 9));
    }

    CPPUNIT_TEST_SUITE(TestGrid);
    CPPUNIT_TEST(test_addCreature1);
    CPPUNIT_TEST(test_addCreature2);
    CPPUNIT_TEST(test_addCreature3);
	CPPUNIT_TEST(test_addCreature4);
	CPPUNIT_TEST(test_addCreature5);
    CPPUNIT_TEST(test_removeCreature1);
    CPPUNIT_TEST(test_removeCreature2);
    CPPUNIT_TEST(test_wall);
    CPPUNIT_TEST_SUITE_END();
};

struct TestGame : CppUnit::TestFixture {
    // constructor / addCreature / <<
    void test_game1 () {
		Program p;
		Species h("hopper", 'h', p);
	    Creature hopper(h);
		Game gm (9, 9);
		gm.addCreature(&hopper,1,1);
		std::ostringstream w;
		w << gm;
		std::string expectedOutput  = "Turn = 0.\n"   \
					                  "  012345678\n" \
					                  "0 .........\n" \
					                  "1 .h.......\n" \
					                  "2 .........\n" \
					                  "3 .........\n" \
					                  "4 .........\n" \
					                  "5 .........\n" \
					                  "6 .........\n" \
					                  "7 .........\n" \
					                  "8 .........";
		CPPUNIT_ASSERT(w.str() == expectedOutput);
    }
    void test_game2 () {

    }
    void test_game3 () {

    }

    void test_moveCreature1 () {
        Program p;
        Species h("hopper", 'h', p);
        Creature hopper(h);
        Game g(3,3);
        g.addCreature(&hopper,2,2);
        CreatureInfo ci = {&hopper, 2, 2};
        g.moveCreature(&ci);
        std::ostringstream w;
        w << g;
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n" \
                                  "  012\n" \
                                  "0 ...\n" \
                                  "1 ...\n" \
                                  "2 .h.");
    }

    void test_moveCreature2 () {
        Program p;
        Species h("hopper", 'h', p);
        Creature hopper(h);
        Game g(3,3);
        g.addCreature(&hopper, 1, 1);
        CreatureInfo ci = {&hopper, 1, 1};
        g.moveCreature(&ci);
        CPPUNIT_ASSERT(ci.x == 1);
        CPPUNIT_ASSERT(ci.y == 0);
    }

    void test_checks1 () {
        Program p;
        Species h("hopper", 'h', p);
        Creature hopper(h);
        Creature h2(h);
        Game g(3,3);
        g.addCreature(&hopper,2,2);
        g.addCreature(&h2,2,1);
        CreatureInfo ci = {&hopper, 2, 2};
        CPPUNIT_ASSERT(!g.checkEmptySquare(&ci)); // 2,1 not empty
        CPPUNIT_ASSERT(!g.checkWall(&ci)); // not a wall
        CPPUNIT_ASSERT(!g.checkEnemy(&ci)); // not an enemy
    }

    void test_checks2 () {
        Program p;
        Species h("hopper", 'h', p);
        Species f("food", 'f', p);
        Creature hopper(h);
        Creature food(f);
        Game g(3,3);
        g.addCreature(&hopper,2,2);
        g.addCreature(&food,2,1);
        CreatureInfo ci = {&hopper, 2, 2};
        CPPUNIT_ASSERT(!g.checkEmptySquare(&ci));
        CPPUNIT_ASSERT(!g.checkWall(&ci));
        CPPUNIT_ASSERT(g.checkEnemy(&ci));
    }

    void test_checks3 () {
        Program p;
        Species h("hopper", 'h', p);
        Species f("food", 'f', p);
        Creature hopper(h);
        Creature food(f);
        Game g(3,3);
        g.addCreature(&hopper,0,0);
        g.addCreature(&food,2,1);
        CreatureInfo ci = {&hopper, 0, 0}; // hopper
        CPPUNIT_ASSERT(!g.checkEmptySquare(&ci));
        CPPUNIT_ASSERT(g.checkWall(&ci));
        CPPUNIT_ASSERT(!g.checkEnemy(&ci));
        ci = {&food, 2, 1}; // food
        CPPUNIT_ASSERT(g.checkEmptySquare(&ci));
        CPPUNIT_ASSERT(!g.checkWall(&ci));
        CPPUNIT_ASSERT(!g.checkEnemy(&ci));
    }

    void test_random () {
        srand(0);
        Game g(3,3);
        //for(int i = 0; i < 10; ++i)
        //    std::cout << g.getRandom();
        //srand(0);
        CPPUNIT_ASSERT(g.getRandom());
        CPPUNIT_ASSERT(g.getRandom() == false);
        CPPUNIT_ASSERT(g.getRandom());
    }

    void test_infect () {
        Program p;
        Species h("hopper", 'h', p);
        Species f("food", 'f', p);
        Creature hopper(h);
        Creature food(f);
        Game g(3,3);
        g.addCreature(&hopper, 0, 1);
        g.addCreature(&food,   0, 0);
        CPPUNIT_ASSERT(hopper.species() == "hopper");
        CPPUNIT_ASSERT(food.species() == "food");
        CreatureInfo ci = {&hopper, 0, 1};
        g.sendInfect(&ci);
        CPPUNIT_ASSERT(food.species() == "hopper");
    }

    void test_simulate () {
        srand(0);
        Program pf;
        pf.addInstruction(LEFT);
        pf.addInstruction(GO, 0);
        Species sf("Food", 'f', pf);
        Creature cf(sf);
        Program rv;
        rv.addInstruction(IFENEMY, 9);
        rv.addInstruction(IFEMPTY, 7);
        rv.addInstruction(IFRANDOM, 5);
        rv.addInstruction(LEFT); // even (false)
        rv.addInstruction(GO, 0);
        rv.addInstruction(RIGHT); // odd (true)
        rv.addInstruction(GO, 0);
        rv.addInstruction(HOP);
        rv.addInstruction(GO, 0);
        rv.addInstruction(INFECT);
        rv.addInstruction(GO, 0);
        Species srv("Rover", 'r', rv);
        Creature rvr(srv);
        Game g(5,5);
        std::ostringstream w;
        w << g;
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n" \
                                  "  01234\n" \
                                  "0 .....\n" \
                                  "1 .....\n" \
                                  "2 .....\n" \
                                  "3 .....\n" \
                                  "4 .....");
        g.addCreature(&cf, 0, 0);
        g.addCreature(&rvr, 3, 3);
        w.str("");
        w.clear();
        w << g;
        CPPUNIT_ASSERT(w.str() == "Turn = 0.\n" \
                                  "  01234\n" \
                                  "0 f....\n" \
                                  "1 .....\n" \
                                  "2 .....\n" \
                                  "3 ...r.\n" \
                                  "4 .....");
        g.simulate(1);
        w.str("");
        w.clear();
        w << g;
        CPPUNIT_ASSERT(w.str() == "Turn = 1.\n" \
                                  "  01234\n" \
                                  "0 f....\n" \
                                  "1 .....\n" \
                                  "2 .....\n" \
                                  "3 ..r..\n" \
                                  "4 .....");
        w.str("");
        w.clear();
        g.simulate(4);
        w << g;
        CPPUNIT_ASSERT(w.str() == "Turn = 5.\n" \
                                  "  01234\n" \
                                  "0 f....\n" \
                                  "1 .....\n" \
                                  "2 r....\n" \
                                  "3 .....\n" \
                                  "4 .....");

    }

    CPPUNIT_TEST_SUITE(TestGame);
    CPPUNIT_TEST(test_game1);
    CPPUNIT_TEST(test_game2);
    CPPUNIT_TEST(test_game3);
    CPPUNIT_TEST(test_moveCreature1);
    CPPUNIT_TEST(test_moveCreature2);
    CPPUNIT_TEST(test_checks1);
    CPPUNIT_TEST(test_checks2);
    CPPUNIT_TEST(test_checks3);
    CPPUNIT_TEST(test_random);
    CPPUNIT_TEST(test_infect);
    CPPUNIT_TEST(test_simulate);
    CPPUNIT_TEST_SUITE_END();
};

struct TestGameMessage : CppUnit::TestFixture {
    // GameMessage constructor / Creature::doAction
    void test_ctor () {
        Program pf;
        pf.addInstruction(HOP);
        pf.addInstruction(HOP);
        pf.addInstruction(GO, 0);
        Species sf("Food", 'f', pf);
        Creature cf(sf);
        Game g(5,5);
        g.addCreature(&cf, 4, 4);

        CreatureInfo ci = {&cf, 4, 4};
        CPPUNIT_ASSERT(ci.creature->facing() == WEST);
        GameMessage gm(g, ci); // this is what we're testing
        ci.creature->doAction(gm);
        CPPUNIT_ASSERT(ci.creature->facing() == WEST);
        CPPUNIT_ASSERT(ci.x == 4);
        CPPUNIT_ASSERT(ci.y == 3);
        ci.creature->doAction(gm);
        CPPUNIT_ASSERT(ci.y == 3); // we shouldn't hop again
        gm = {g, ci};
        ci.creature->doAction(gm);
        CPPUNIT_ASSERT(ci.creature->facing() == WEST);
        CPPUNIT_ASSERT(ci.x == 4);
        CPPUNIT_ASSERT(ci.y == 2);
        gm = {g, ci};
        ci.creature->doAction(gm);
        CPPUNIT_ASSERT(ci.creature->facing() == WEST);
        CPPUNIT_ASSERT(ci.x == 4);
        CPPUNIT_ASSERT(ci.y == 1);
    }

    void test_gm1 () {
        srand(0);
        Program pf;
        pf.addInstruction(LEFT);
        pf.addInstruction(GO, 0);
        Species sf("Food", 'f', pf);
        Creature cf(sf);
        Program rv;
        rv.addInstruction(IFENEMY, 9);
        rv.addInstruction(IFEMPTY, 7);
        rv.addInstruction(IFRANDOM, 5);
        rv.addInstruction(LEFT); // even (false)
        rv.addInstruction(GO, 0);
        rv.addInstruction(RIGHT); // odd (true)
        rv.addInstruction(GO, 0);
        rv.addInstruction(HOP);
        rv.addInstruction(GO, 0);
        rv.addInstruction(INFECT);
        rv.addInstruction(GO, 0);
        Species srv("Rover", 'r', rv);
        Creature rvr(srv);
        Game g(5,5);
        g.addCreature(&cf, 0, 0);
        g.addCreature(&rvr, 3, 3);

        CreatureInfo cif = {&cf, 0, 0};
        CreatureInfo cir = {&rvr, 3, 3};
        GameMessage gm(g, cif);
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm);
        gm = {g, cif};
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm);
        gm = {g, cif};
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm);
        gm = {g, cif};
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm); // RIGHT
        CPPUNIT_ASSERT(cir.creature->facing() == NORTH);
        gm = {g, cif};
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm);
        gm = {g, cif};
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm);
        gm = {g, cif};
        cif.creature->doAction(gm);
        gm = {g, cir};
        cir.creature->doAction(gm); // INFECT
        CPPUNIT_ASSERT(cif.creature->species() == "Rover");
    }

    CPPUNIT_TEST_SUITE(TestGameMessage);
    CPPUNIT_TEST(test_ctor);
    CPPUNIT_TEST(test_gm1);
    CPPUNIT_TEST_SUITE_END();
};

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestDarwin.c++\n";

    CppUnit::TextTestRunner tr;
    tr.addTest(TestInstruction::suite());
    tr.addTest(TestProgram::suite());
    tr.addTest(TestSpecies::suite());
    tr.addTest(TestCreature::suite());
    tr.addTest(TestSquare::suite());
    tr.addTest(TestGrid::suite());
    tr.addTest(TestGame::suite());
    tr.addTest(TestGameMessage::suite());
    tr.run();

    cout << "Done.\n";
    return 0;
}
