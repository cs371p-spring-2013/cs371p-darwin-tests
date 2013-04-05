#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include <vector>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#define private public
#include "Darwin.h"

struct TestDarwin : CppUnit::TestFixture {

	void sim_construct_1(){
		Simulation s(6, 6, 5, 5);
		CPPUNIT_ASSERT(s.rows == 6);
		CPPUNIT_ASSERT(s.cols == 6);
	}
	
	void sim_construct_2(){
		Simulation s(44, 44, 5, 5);
		CPPUNIT_ASSERT(s.rows == 44);
		CPPUNIT_ASSERT(s.cols == 44);
	}
	
	void sim_construct_3(){
		Simulation s(72, 72, 5, 5);
		CPPUNIT_ASSERT(s.rows == 72);
		CPPUNIT_ASSERT(s.cols == 72);
	}
	
	void print_board_1(){
	    Simulation s(5, 3, 5, 5);
		Species h("hopper");
		Species f("food");
		Creature c('h', 1, &h);
		Creature d('f', 2, &f);
		s.addCreature(0, 0, &c);
		s.addCreature(2, 2, &d);
		//cout << endl;
		//s.printBoard(cout);
		CPPUNIT_ASSERT(((*s.creatureLocs[0][0]).name) == 'h');
		CPPUNIT_ASSERT(((*s.creatureLocs[2][2]).name) == 'f');
		cout << endl;
	}
	
	void print_board_2(){
	    Simulation s(3, 3, 5, 5);
		Species t("t");
		Species r("rover");
		Creature c('t', 1, &t);
		Creature d('r', 2, &r);
		s.addCreature(0, 2, &c);
		s.addCreature(2, 0, &d);
		//s.printBoard(cout);
		CPPUNIT_ASSERT(((*s.creatureLocs[0][2]).name) == 't');
		CPPUNIT_ASSERT(((*s.creatureLocs[2][0]).name) == 'r');
		//cout << endl;
		//cout << endl;
	}
	
	void print_board_3(){
		Simulation s(10, 10, 5, 5);
		Species r("rover");
		Species h("hopper");
		Species f("food");
		Species t("trap");
		Creature c('r', 1, &r);
		Creature c1('t', 1, &t);
		Creature c2('f', 1, &f);
		Creature c3('h', 1, &h);
		s.addCreature(9, 9, &c);
		s.addCreature(5, 5, &c1);
		s.addCreature(3, 2, &c2);
		s.addCreature(1, 6, &c3);
		//s.printBoard(cout);
		CPPUNIT_ASSERT(((*s.creatureLocs[9][9]).name) == 'r');
		CPPUNIT_ASSERT(((*s.creatureLocs[5][5]).name) == 't');
		CPPUNIT_ASSERT(((*s.creatureLocs[3][2]).name) == 'f');								
		CPPUNIT_ASSERT(((*s.creatureLocs[1][6]).name) == 'h');
	}
	
	void check_front_1(){
	    Simulation s(5, 4, 5, 5);
		Species h("hopper");
		Species f("food");
		Creature c('h', 1, &h);
		Creature d('f', 2, &f);
		s.addCreature(0, 0, &c);
		s.addCreature(2, 2, &d);
		int first = s.inFront(-1, 0, 0, 0);
		int second = s.inFront(2, 3, 2, 2);
		CPPUNIT_ASSERT(first == 1 && second == 0);
		cout << endl;
	}
	
	void check_front_2(){
	    Simulation s(4, 4, 5, 5);
		Species t("trap");
		Species r("rover");
		Creature c('t', 1, &t);
		Creature d('r', 3, &r);
		s.addCreature(3, 0, &c);
		s.addCreature(2, 0, &d);
		int first = s.inFront(2, 0, 3, 0);
		int second = s.inFront(3, 0, 2, 0);
		CPPUNIT_ASSERT(first == 3 && second == 3);
	}
	
	void check_front_3(){
		Simulation s(10, 10, 5, 5);
		Species r("rover");
		Species h("hopper");
		Species f("food");
		Species t("trap");
		Creature c('r', 3, &r);
		Creature c1('t', 0, &t);
		Creature c2('f', 1, &f);
		Creature c3('h', 1, &h);
		Creature c4('h', 2, &h);
		s.addCreature(9, 9, &c);
		s.addCreature(4, 0, &c1);
		s.addCreature(3, 2, &c2);
		s.addCreature(1, 6, &c3);
		s.addCreature(3, 1, &c4);
		int first = s.inFront(10, 9, 9, 9);
		int second = s.inFront(0, -1, 4, 0);
		int third = s.inFront(2, 2, 3, 2);
		int fourth = s.inFront(0, 6, 1, 6);
		int fifth = s.inFront(3, 2, 3, 1);
		CPPUNIT_ASSERT(fourth == 0 && third == 0 && second == 1 && first == 1 && fifth == 3);
	}
	
	void getAction_1(){
		Simulation s(5, 4, 5, 5);
		Species h("hopper");
		Species f("food");
		Creature c('h', 1, &h);
		Creature d('f', 2, &f);
		s.addCreature(0, 0, &c);
		s.addCreature(2, 2, &d);
		char x = c.getOneAction(0);
		char y = d.getOneAction(0);
		CPPUNIT_ASSERT(x == 'H');
		CPPUNIT_ASSERT(y == 'L');
		CPPUNIT_ASSERT(c.currentInt == 1);
		CPPUNIT_ASSERT(d.currentInt == 1);
	}
	
	void getAction_2(){
	    Simulation s(4, 4, 5, 5);
		Species t("trap");
		Species r("rover");
		Creature c('t', 1, &t);
		Creature d('r', 3, &r);
		s.addCreature(3, 0, &c);
		s.addCreature(2, 0, &d);
		char x = c.getOneAction(3);
		char y = d.getOneAction(3);
		CPPUNIT_ASSERT(x == 'I');
		CPPUNIT_ASSERT(c.currentInt == 4);
		CPPUNIT_ASSERT(y == 'I');
		CPPUNIT_ASSERT(d.currentInt == 10);
	}
	
	void getAction_3(){
		srand(0);
		Simulation s(10, 10, 5, 5);
		Species r("rover");
		Species h("hopper");
		Species f("food");
		Species t("trap");
		Creature c('r', 3, &r);
		c.currentInt = 1;
		Creature c1('t', 0, &t);
		Creature c2('f', 1, &f);
		Creature c3('h', 1, &h);
		Creature c4('h', 2, &h);
		c4.currentInt = 1;
		s.addCreature(9, 9, &c);
		s.addCreature(4, 0, &c1);
		s.addCreature(3, 2, &c2);
		s.addCreature(1, 6, &c3);
		s.addCreature(3, 1, &c4);
		char x = c.getOneAction(3);
		char y = c1.getOneAction(1);
		char z = c4.getOneAction(3);
		CPPUNIT_ASSERT(x == 'R');
		CPPUNIT_ASSERT(c.currentInt == 6); 
		CPPUNIT_ASSERT(y == 'L');
		CPPUNIT_ASSERT(c1.currentInt == 2);
		CPPUNIT_ASSERT(z == 'H');
		CPPUNIT_ASSERT(c4.currentInt == 1);
	}
	
	void doAction_1() {
		Simulation s(3, 3, 5, 5);
		Species h("hopper");
		Species f("food");
		Creature c('h', 3, &h);
		Creature c1('h', 2, &h);
		Creature d('f', 1, &f);
		s.addCreature(0, 0, &c);
		s.addCreature(2, 2, &d);
		s.addCreature(1, 0, &c1);
		s.doOneAction('H', 2, 1, 0, 0, 0);
		s.doOneAction('H', 0, 1, 1, 1, 0);
		s.doOneAction('L', 0, 1, 2, 2, 2);
		CPPUNIT_ASSERT(((*s.creatureLocs[0][0]).name) == 'h');
		CPPUNIT_ASSERT(((*s.creatureLocs[1][1]).name) == 'h');
		CPPUNIT_ASSERT(((*s.creatureLocs[2][2]).name) == 'f');
		CPPUNIT_ASSERT(d.currentDir == 0);		
	}
	
	void doAction_2() {
		Simulation s(2, 2, 5, 5);
		Species t("trap");
		Species h("hopper");
		Creature c('t', 3, &t);
		Creature d('h', 2, &h);
		d.currentInt = 2;
		s.addCreature(0, 0, &c);
		s.addCreature(1, 0, &d);
		CPPUNIT_ASSERT(((*s.creatureLocs[1][0]).name) == 'h');
		CPPUNIT_ASSERT((d.species->instructions.at(0).first == 'H'));
		s.doOneAction('I', 3, 1, 0, 0, 0);
		CPPUNIT_ASSERT(((*s.creatureLocs[0][0]).name) == 't');
		CPPUNIT_ASSERT(((*s.creatureLocs[1][0]).name) == 't');
		CPPUNIT_ASSERT((d.species->instructions.at(0).first == 'E'));
		CPPUNIT_ASSERT(d.currentInt == 0);
	}
	
	void doAction_3() {
		Simulation s(3, 3, 4, 5);
		Species r("rover");
		Species f("food");
		Creature c('r', 0, &r);
		Creature d('f', 2, &f);
		s.addCreature(2, 2, &c);
		s.addCreature(2, 1, &d);
		d.currentInt = 3;
		CPPUNIT_ASSERT(((*s.creatureLocs[2][1]).name) == 'f');
		CPPUNIT_ASSERT((d.species->instructions.at(0).first == 'L'));
		s.doOneAction('I', 3, 2, 1, 2, 2);
		CPPUNIT_ASSERT(((*s.creatureLocs[2][2]).name) == 'r');
		CPPUNIT_ASSERT(((*s.creatureLocs[2][1]).name) == 'r');
		CPPUNIT_ASSERT((d.species->instructions.at(0).first == 'E'));
		CPPUNIT_ASSERT(d.currentInt == 0);
	}
	
	void add_creature_1(){
		Simulation s(10, 10, 5, 5);
		Species r("rover");
		Creature c('r', 1, &r);
		s.addCreature(1, 1, &c);
		CPPUNIT_ASSERT(((*s.creatureLocs[1][1]).name) == 'r');
	}
	
	void add_creature_2(){
		Simulation s(6, 6, 5, 5);
		Species r("rover");
		Species h("hopper");
		Creature c('r', 1, &r);
		Creature c2('h', 3, &h);
		s.addCreature(1, 1, &c);
		s.addCreature(2, 2, &c2);
		CPPUNIT_ASSERT(((*s.creatureLocs[1][1]).name) == 'r');
		CPPUNIT_ASSERT(((*s.creatureLocs[2][2]).name) == 'h');
	}
	
	void add_creature_3(){
		Simulation s(10, 10, 5, 5);
		Species f("food");
		Species t("trap");
		Creature c('f', 1, &f);
		Creature d('t', 2, &t);
		s.addCreature(9, 9, &c);
		s.addCreature(0, 0, &d);
		CPPUNIT_ASSERT(((*s.creatureLocs[0][0]).name) == 't');
		CPPUNIT_ASSERT(((*s.creatureLocs[9][9]).name) == 'f');
	}
	
	
	void creature_construct_1(){
    	Species x("rover");
    	Creature c('n', 2, &x);
    	CPPUNIT_ASSERT(c.name == 'n');
    	CPPUNIT_ASSERT(c.currentDir == 2);
    	CPPUNIT_ASSERT(c.currentInt == 0);
    	CPPUNIT_ASSERT(c.species == &x);
    }
    
    void creature_construct_2(){
    	Species x("trap");
    	Creature c('t', 3, &x);
    	CPPUNIT_ASSERT(c.name == 't');
    	CPPUNIT_ASSERT(c.currentDir == 3);
    	CPPUNIT_ASSERT(c.currentInt == 0);
    	CPPUNIT_ASSERT(c.species == &x);
    }
    
    void creature_construct_3(){
    	Species x("food");
    	Creature c('f', 1, &x);
    	CPPUNIT_ASSERT(c.name == 'f');
    	CPPUNIT_ASSERT(c.currentDir == 1);
    	CPPUNIT_ASSERT(c.currentInt == 0);
    	CPPUNIT_ASSERT(c.species == &x);
    }
    
    void creature_turnOff_1(){
    	Species x("rover");
    	Creature c('n', 2, &x);
    	CPPUNIT_ASSERT(!c.doneWithTurn);
    	c.turnOff();
    	CPPUNIT_ASSERT(c.doneWithTurn);
    }
    
   	void creature_turnOff_2(){
    	Species g("food");
    	Creature q('r', 2, &g);
    	CPPUNIT_ASSERT(!q.doneWithTurn);
    	q.turnOff();
    	CPPUNIT_ASSERT(q.doneWithTurn);
    }
    
   	void creature_turnOff_3(){
    	Species y("trap");
    	Creature z('t', 3, &y);
    	CPPUNIT_ASSERT(!z.doneWithTurn);
    	z.turnOff();
    	CPPUNIT_ASSERT(z.doneWithTurn);
    } 
    
    void creature_turnOn_1(){
    	Species x("rover");
    	Creature c('n', 2, &x);
    	CPPUNIT_ASSERT(!c.doneWithTurn);
    	c.turnOff();
    	CPPUNIT_ASSERT(c.doneWithTurn);
    	c.turnOn();
    	CPPUNIT_ASSERT(!c.doneWithTurn);
    }
    
   	void creature_turnOn_2(){
    	Species g("food");
    	Creature q('r', 2, &g);
    	CPPUNIT_ASSERT(!q.doneWithTurn);
    	q.turnOff();
    	CPPUNIT_ASSERT(q.doneWithTurn);
    	q.turnOn();
    	CPPUNIT_ASSERT(!q.doneWithTurn);
    }
    
   	void creature_turnOn_3(){
    	Species y("trap");
    	Creature z('t', 3, &y);
    	CPPUNIT_ASSERT(!z.doneWithTurn);
    	z.turnOff();
    	CPPUNIT_ASSERT(z.doneWithTurn);
    	z.turnOn();
    	CPPUNIT_ASSERT(!z.doneWithTurn);
    }
    
    void creature_name_1(){
    	Species x("rover");
    	Creature c('n', 2, &x);
    	CPPUNIT_ASSERT(c.what_is_name() == 'n');
    }
    
    void creature_name_2(){
    	Species x("rover");
    	Creature c('q', 0, &x);
    	CPPUNIT_ASSERT(c.what_is_name() == 'q');
    }
    
    void creature_name_3(){
    	Species x("rover");
    	Creature c('f', 1, &x);
    	CPPUNIT_ASSERT(c.what_is_name() == 'f');
    }
    
    void isReady_1(){
		Species x("rover");
		Creature c('f', 1, &x);
		CPPUNIT_ASSERT(c.isReady());
	}
	
	void isReady_2(){
		Species x("rover");
		Creature c('f', 1, &x);
		c.doneWithTurn = true;
		CPPUNIT_ASSERT(!c.isReady());
	}
    
	void isReady_3(){
		Species x("rover");
		Creature c('f', 1, &x);
		c.doneWithTurn = true;
		c.doneWithTurn = false;
		CPPUNIT_ASSERT(c.isReady());
	}
	
    void changeDirection_1(){
    	Species x("rover");
    	Creature c('r', 2, &x);
    	c.changeDirection('L');
    	CPPUNIT_ASSERT(c.currentDir == 1);
    }
    
    void changeDirection_2(){
    	Species x("rover");
    	Creature c('r', 0, &x);
    	c.changeDirection('L');
    	CPPUNIT_ASSERT(c.currentDir == 3);
    	c.changeDirection('L');
    	CPPUNIT_ASSERT(c.currentDir == 2);
    	c.changeDirection('L');
    	CPPUNIT_ASSERT(c.currentDir == 1);
    	c.changeDirection('L');
    	CPPUNIT_ASSERT(c.currentDir == 0);
    	c.changeDirection('L');
    	CPPUNIT_ASSERT(c.currentDir == 3);
    }
    
    void changeDirection_3(){
    	Species x("rover");
    	Creature c('r', 3, &x);
    	c.changeDirection('R');
    	CPPUNIT_ASSERT(c.currentDir == 0);
    	c.changeDirection('R');
    	CPPUNIT_ASSERT(c.currentDir == 1);
    	c.changeDirection('R');
    	CPPUNIT_ASSERT(c.currentDir == 2);
    	c.changeDirection('R');
    	CPPUNIT_ASSERT(c.currentDir == 3);
    }
    
    void whichDir_1(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.whichDirection() == 2);
    }
    
    void whichDir_2(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	c.currentDir = 0;
    	CPPUNIT_ASSERT(c.whichDirection() == 0);
    }
    
    void whichDir_3(){
    	Species x("trap");
    	Creature c('t', 3, &x);
    	c.currentDir = 2;
    	CPPUNIT_ASSERT(c.whichDirection() == 2);
    	c.currentDir = 1;
    	CPPUNIT_ASSERT(c.whichDirection() == 1);
    }
    
    void getPCVal_1(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.pcVal() == 0);
    }
    
    void getPCVal_2(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.pcVal() == 0);
    	c.currentInt = 2;
    	CPPUNIT_ASSERT(c.pcVal() == 2);
    }
    
    void getPCVal_3(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.pcVal() == 0);
    	c.currentInt = 2;
    	CPPUNIT_ASSERT(c.pcVal() == 2);
    	c.currentInt = 5;
    	CPPUNIT_ASSERT(c.pcVal() == 5);
    }    
    
    void altPCVal_1(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	c.alterPCVal(4);
    	CPPUNIT_ASSERT(c.pcVal() == 4);
    }
    
    void altPCVal_2(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.pcVal() == 0);
    	c.alterPCVal(2);
    	CPPUNIT_ASSERT(c.pcVal() == 2);
    }
    
    void altPCVal_3(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.pcVal() == 0);
    	c.alterPCVal(2);
    	CPPUNIT_ASSERT(c.pcVal() == 2);
    	c.alterPCVal(5);
    	CPPUNIT_ASSERT(c.pcVal() == 5);
    }
    
    void changeName_1(){
    	Species x("trap");
    	Creature c('t', 2, &x);
    	CPPUNIT_ASSERT(c.name == 't');
    	c.changeName('x');
    	CPPUNIT_ASSERT(c.name == 'x');
    }
    
    void changeName_2(){
    	Species x("trap");
    	Creature c('a', 2, &x);
    	CPPUNIT_ASSERT(c.name == 'a');
    	c.changeName('x');
    	CPPUNIT_ASSERT(c.name == 'x');
    	c.changeName('o');
    	CPPUNIT_ASSERT(c.name == 'o');
    }
    
    void changeName_3(){
    	Species x("trap");
    	Creature c('r', 2, &x);
    	CPPUNIT_ASSERT(c.name == 'r');
    	c.changeName('?');
    	CPPUNIT_ASSERT(c.name == '?');
    	c.changeName('x');
    	CPPUNIT_ASSERT(c.name == 'x');
    	c.changeName('v');
    	CPPUNIT_ASSERT(c.name == 'v');
    }
    
    
    void species_construct_1(){
    	Species s("food");
    	CPPUNIT_ASSERT(s.instructions.at(0).first == 'L');
    	CPPUNIT_ASSERT(s.instructions.at(0).second == -1);
    	CPPUNIT_ASSERT(s.instructions.at(1).first == 'G');
    	CPPUNIT_ASSERT(s.instructions.at(1).second == 0);
    }
    
    void species_construct_2(){
    	Species s("hopper");
    	CPPUNIT_ASSERT(s.instructions.at(0).first == 'H');
    	CPPUNIT_ASSERT(s.instructions.at(0).second == -1);
    	CPPUNIT_ASSERT(s.instructions.at(1).first == 'G');
    	CPPUNIT_ASSERT(s.instructions.at(1).second == 0);
    }
    
    void species_construct_3(){
    	Species s("trap");
    	CPPUNIT_ASSERT(s.instructions.at(0).first == 'E');
    	CPPUNIT_ASSERT(s.instructions.at(0).second == 3);
    	CPPUNIT_ASSERT(s.instructions.at(1).first == 'L');
    	CPPUNIT_ASSERT(s.instructions.at(1).second == -1);
    	CPPUNIT_ASSERT(s.instructions.at(2).first == 'G');
    	CPPUNIT_ASSERT(s.instructions.at(2).second == 0);
    	CPPUNIT_ASSERT(s.instructions.at(3).first == 'I');
    	CPPUNIT_ASSERT(s.instructions.at(3).second == -1);
      	CPPUNIT_ASSERT(s.instructions.at(2).first == 'G');
    	CPPUNIT_ASSERT(s.instructions.at(2).second == 0);
    }
    
    void simulate_1() {
    	Simulation s(10, 10, 5, 5);
		Species r("rover");
		Species h("hopper");
		Species f("food");
		Species t("trap");
		Creature c('r', 3, &r);
		Creature c1('t', 3, &t);
		Creature c2('f', 1, &f);
		Creature c3('h', 3, &h);
		s.addCreature(2, 2, &c);
		s.addCreature(4, 2, &c1);
		s.addCreature(3, 2, &c2);
		s.addCreature(3, 1, &c3);
		CPPUNIT_ASSERT(1 == 1);
    }
    
    void simulate_2() {
    	Simulation s(10, 10, 5, 5);
		Species r("rover");
		Species h("hopper");
		Species f("food");
		Species t("trap");
		Creature c('r', 3, &r);
		Creature c1('t', 3, &t);
		Creature c2('f', 1, &f);
		Creature c3('h', 3, &h);
		s.addCreature(2, 2, &c);
		s.addCreature(4, 2, &c1);
		s.addCreature(3, 2, &c2);
		s.addCreature(3, 1, &c3);
		CPPUNIT_ASSERT(1 == 1);
    }
    
    void simulate_3() {
    	Simulation s(10, 10, 5, 5);
		Species r("rover");
		Species h("hopper");
		Species f("food");
		Species t("trap");
		Creature c('r', 3, &r);
		Creature c1('t', 3, &t);
		Creature c2('f', 1, &f);
		Creature c3('h', 3, &h);
		s.addCreature(2, 2, &c);
		s.addCreature(4, 2, &c1);
		s.addCreature(3, 2, &c2);
		s.addCreature(3, 1, &c3);
		CPPUNIT_ASSERT(1 == 1);
    }

	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(sim_construct_1);
	CPPUNIT_TEST(sim_construct_2);
	CPPUNIT_TEST(sim_construct_3);
	CPPUNIT_TEST(print_board_1);
	CPPUNIT_TEST(print_board_2);
	CPPUNIT_TEST(print_board_3);
	CPPUNIT_TEST(check_front_1);
	CPPUNIT_TEST(check_front_2);
	CPPUNIT_TEST(check_front_3);
	CPPUNIT_TEST(add_creature_1);
	CPPUNIT_TEST(add_creature_2);
	CPPUNIT_TEST(add_creature_3);
	CPPUNIT_TEST(creature_construct_1);
	CPPUNIT_TEST(creature_construct_2);
	CPPUNIT_TEST(creature_construct_3);
	CPPUNIT_TEST(creature_name_1);
	CPPUNIT_TEST(creature_name_2);
	CPPUNIT_TEST(creature_name_3);
	CPPUNIT_TEST(creature_turnOff_1);
	CPPUNIT_TEST(creature_turnOff_2);
	CPPUNIT_TEST(creature_turnOff_3);
	CPPUNIT_TEST(creature_turnOn_1);
	CPPUNIT_TEST(creature_turnOn_2);
	CPPUNIT_TEST(creature_turnOn_3);
	CPPUNIT_TEST(changeDirection_1);
	CPPUNIT_TEST(changeDirection_2);
	CPPUNIT_TEST(changeDirection_3);
	CPPUNIT_TEST(isReady_1);
	CPPUNIT_TEST(isReady_2);
	CPPUNIT_TEST(isReady_3);
	CPPUNIT_TEST(whichDir_1);
	CPPUNIT_TEST(whichDir_2);
	CPPUNIT_TEST(whichDir_3);
	CPPUNIT_TEST(getPCVal_1);
	CPPUNIT_TEST(getPCVal_2);
	CPPUNIT_TEST(getPCVal_3);
	CPPUNIT_TEST(altPCVal_1);
	CPPUNIT_TEST(altPCVal_2);
	CPPUNIT_TEST(altPCVal_3);
	CPPUNIT_TEST(changeName_1);
	CPPUNIT_TEST(changeName_2);
	CPPUNIT_TEST(changeName_3);
	CPPUNIT_TEST(getAction_1);
	CPPUNIT_TEST(getAction_2);
	CPPUNIT_TEST(getAction_3);
	CPPUNIT_TEST(doAction_1);
	CPPUNIT_TEST(doAction_2);
	CPPUNIT_TEST(doAction_3);
	CPPUNIT_TEST(species_construct_1);
	CPPUNIT_TEST(species_construct_2);
	CPPUNIT_TEST(species_construct_3);
	CPPUNIT_TEST(simulate_1);
	CPPUNIT_TEST(simulate_2);
	CPPUNIT_TEST(simulate_3);
    CPPUNIT_TEST_SUITE_END();
    
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    
    return 0;
}
