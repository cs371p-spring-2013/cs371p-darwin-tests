
// --------
// includes
// --------

#include <algorithm> //count
#include <iostream> // ios_base
#include <memory> //allocator
#include <sstream> //string stream
#include <stdexcept> //exceptions

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner



#define protected public
#define private public

#include "Darwin.h"

// -------------
// TestDarwin
// -------------

struct TestDarwin : CppUnit::TestFixture {
    void testis_empty1() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, FOOD, 0, 0);
	CPPUNIT_ASSERT(g.is_empty(1,0));
    }
	
    void testis_empty2() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, FOOD, 0, 0);
	CPPUNIT_ASSERT(!g.is_empty(0,0));
    }
    
    void testis_empty3() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, FOOD, 3, 3);
	CPPUNIT_ASSERT(!g.is_empty(3,3));
    }
    
    void testis_wall1() {
    	Grid g = Grid(5,1,8,8);
	CPPUNIT_ASSERT(!g.is_wall(3,3));
    }
    
    void testis_wall2() {
    	Grid g = Grid(5,1,8,8);
	CPPUNIT_ASSERT(!g.is_wall(0,0));
    }
    
    void testis_wall3() {
    	Grid g = Grid(5,1,8,8);
	CPPUNIT_ASSERT(g.is_wall(-1,3));
    }
    
    void testis_creature1() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, ROVER, 5, 0);
	Creature c = Creature(NORTH,FOOD,0,0,&g);
	CPPUNIT_ASSERT(typeid(g.is_creature(0,0)) == typeid(c));
    }
    
    void testis_creature2() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, ROVER, 5, 0);
	CPPUNIT_ASSERT(typeid(g.is_creature(4,0)) != typeid(Grid));
    }
    
    void testis_creature3() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, ROVER, 5, 0);
	Creature c = Creature(NORTH,FOOD,0,0,&g);
	CPPUNIT_ASSERT(typeid(g.is_creature(5,0)) == typeid(c));
    }
    
    void testGrid1() {
    	Grid g = Grid(5,1,8,8);
    	CPPUNIT_ASSERT(g._turns==5);
    	CPPUNIT_ASSERT(g._freq==1);
	CPPUNIT_ASSERT(g._x==8);
	CPPUNIT_ASSERT(g._y==8);
	CPPUNIT_ASSERT(g._count==1);
    }
    
    void testGrid2() {
    	Grid g = Grid(5,2,4,7);
    	CPPUNIT_ASSERT(g._turns==5);
    	CPPUNIT_ASSERT(g._freq==2);
	CPPUNIT_ASSERT(g._x==4);
	CPPUNIT_ASSERT(g._y==7);
	CPPUNIT_ASSERT(g._count==1);
    }
    
    void testGrid3() {
    	Grid g = Grid(1000,100,8,8);
    	CPPUNIT_ASSERT(g._turns==1000);
    	CPPUNIT_ASSERT(g._freq==100);
	CPPUNIT_ASSERT(g._x==8);
	CPPUNIT_ASSERT(g._y==8);
	CPPUNIT_ASSERT(g._count==1);
    }
    
    void testmove_creature1() {
    	Grid g = Grid(5,1,8,8);
    	int c1 = g.locations[1][1];
    	g.move_creature(1,1,2,2);
    	CPPUNIT_ASSERT(g.locations[2][2] == c1);
    	CPPUNIT_ASSERT(g.locations[1][1] == 0);    	
    }
    
    void testmove_creature2() {
    	Grid g = Grid(5,1,8,8);
    	int c1 = g.locations[3][4];
    	g.move_creature(3,4,5,6);
    	CPPUNIT_ASSERT(g.locations[5][6] == c1);
    	CPPUNIT_ASSERT(g.locations[3][4] == 0);
    }
    
    void testmove_creature3() {
    	Grid g = Grid(5,1,8,8);
    	int c1 = g.locations[1][1];
    	g.move_creature(1,1,2,2);
    	g.move_creature(2,2,1,1);
    	CPPUNIT_ASSERT(g.locations[1][1] == c1);
    	CPPUNIT_ASSERT(g.locations[2][2] == 0);
    }
    
    
    void testplace_creature1() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, ROVER, 5, 0);	
	CPPUNIT_ASSERT(g.locations[0][5] != 0);
    } 
    
    void testplace_creature2() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, ROVER, 5, 0);	
	CPPUNIT_ASSERT(g.grid[g.locations[5][0]]._species == ROVER);
    } 
    
    void testplace_creature3() {
    	Grid g = Grid(5,1,8,8);
	g.place_creature(EAST, ROVER, 5, 0);	
	CPPUNIT_ASSERT(g.locations[0][5]);
    } 
    
    void testexecuteGrid1() {
    	Grid g = Grid(10,-1111,8,8);
	g.place_creature(EAST, ROVER, 5, 0);
	g.executeGrid();
	CPPUNIT_ASSERT(g.locations[7][7] != 0);
    }
    
    void testexecuteGrid2() {
    	Grid g = Grid(10,-1111,8,8);
	g.place_creature(EAST, ROVER, 5, 0);
	g.executeGrid();
	CPPUNIT_ASSERT(g.locations[7][7]);
    }
    
    void testexecuteGrid3() {
    	Grid g = Grid(7,-1111,8,8);
	g.place_creature(EAST, ROVER, 5, 0);
	g.executeGrid();
	CPPUNIT_ASSERT(g.locations[7][5]);
    }
    
    void testCreature1() {
    	Grid g = Grid(5,1,8,8);
    	Creature c = Creature(NORTH, HOPPER, 1, 1, &g);
    	CPPUNIT_ASSERT(c._pc == 0);
    	CPPUNIT_ASSERT(c._dir == NORTH);
    	CPPUNIT_ASSERT(c._species == HOPPER);
    	CPPUNIT_ASSERT(c._xPos == 1);
    	CPPUNIT_ASSERT(c._yPos == 1);
	CPPUNIT_ASSERT(c._turnsTaken == 0);    	
    	
    }
    
    void testCreature2() {
    	Grid g = Grid(5,1,4,8);
    	Creature c = Creature(SOUTH, HOPPER, 0, 3, &g);
    	CPPUNIT_ASSERT(c._pc == 0);
    	CPPUNIT_ASSERT(c._dir == SOUTH);
    	CPPUNIT_ASSERT(c._species == HOPPER);
    	CPPUNIT_ASSERT(c._xPos == 0);
    	CPPUNIT_ASSERT(c._yPos == 3);
	CPPUNIT_ASSERT(c._turnsTaken == 0);    
    }
    
    void testCreature3() {
    	Grid g = Grid(50,10,8,8);
    	Creature c = Creature(WEST, FOOD, 4, 4, &g);
    	CPPUNIT_ASSERT(c._pc == 0);
    	CPPUNIT_ASSERT(c._dir == WEST);
    	CPPUNIT_ASSERT(c._species == FOOD);
    	CPPUNIT_ASSERT(c._xPos == 4);
    	CPPUNIT_ASSERT(c._yPos == 4);
	CPPUNIT_ASSERT(c._turnsTaken == 0);    
    }
    
    void testexecuteTurn1() {
    	Grid g = Grid(5,1,8,8);
    	Creature c = Creature(NORTH, HOPPER, 1, 1, &g);
    	CPPUNIT_ASSERT(c._pc == 0);
    	CPPUNIT_ASSERT(c._dir == NORTH);
    	CPPUNIT_ASSERT(c._species == HOPPER);
    	CPPUNIT_ASSERT(c._xPos == 1);
    	CPPUNIT_ASSERT(c._yPos == 1);
	CPPUNIT_ASSERT(c._turnsTaken == 0);  
	c.executeTurn();
	CPPUNIT_ASSERT(c._done == 1);  
	CPPUNIT_ASSERT(c._pc == 1);
    	CPPUNIT_ASSERT(c._dir == NORTH);
    	CPPUNIT_ASSERT(c._species == HOPPER);
    	CPPUNIT_ASSERT(c._xPos == 1);
    	CPPUNIT_ASSERT(c._yPos == 0);
	CPPUNIT_ASSERT(c._turnsTaken == 1);  
    }
    
    void testexecuteTurn2() {
    	Grid g = Grid(5,1,4,8);
    	Creature c = Creature(NORTH, TRAP, 3, 4, &g);
    	CPPUNIT_ASSERT(c._pc == 0);
    	CPPUNIT_ASSERT(c._dir == NORTH);
    	CPPUNIT_ASSERT(c._species == TRAP);
    	CPPUNIT_ASSERT(c._xPos == 3);
    	CPPUNIT_ASSERT(c._yPos == 4);
	CPPUNIT_ASSERT(c._turnsTaken == 0);  
	c.executeTurn();
	CPPUNIT_ASSERT(c._done == 1);  
	CPPUNIT_ASSERT(c._pc == 2);
    	CPPUNIT_ASSERT(c._dir == WEST);
    	CPPUNIT_ASSERT(c._species == TRAP);
    	CPPUNIT_ASSERT(c._xPos == 3);
    	CPPUNIT_ASSERT(c._yPos == 4);
	CPPUNIT_ASSERT(c._turnsTaken == 1);  
    }
    
    void testexecuteTurn3() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
    	CPPUNIT_ASSERT(c._pc == 0);
    	CPPUNIT_ASSERT(c._dir == SOUTH);
    	CPPUNIT_ASSERT(c._species == HOPPER);
    	CPPUNIT_ASSERT(c._xPos == 0);
    	CPPUNIT_ASSERT(c._yPos == 0);
	CPPUNIT_ASSERT(c._turnsTaken == 0);  
	c.executeTurn();
	c.executeTurn();
	c.executeTurn();
	c.executeTurn();
	c.executeTurn();
	CPPUNIT_ASSERT(c._done == 1);  
	CPPUNIT_ASSERT(c._pc == 1);
    	CPPUNIT_ASSERT(c._dir == SOUTH);
    	CPPUNIT_ASSERT(c._species == HOPPER);
    	CPPUNIT_ASSERT(c._xPos == 0);
    	CPPUNIT_ASSERT(c._yPos == 5);
	CPPUNIT_ASSERT(c._turnsTaken == 5);  
    }
    
    void testcanMove1() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
    	CPPUNIT_ASSERT(c.canMove() == 0);
    }
    
    void testcanMove2() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
    	c.executeTurn();
    	CPPUNIT_ASSERT(c.canMove() == 1);
    }
    
    void testcanMove3() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	c.executeTurn();
 	c.executeTurn();
    	CPPUNIT_ASSERT(c.canMove() == 2);
    }
    
    void testhop1() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	c.hop();
 	CPPUNIT_ASSERT(c._xPos == 0);
 	CPPUNIT_ASSERT(c._yPos == 1); 	
    }
    
    void testhop2() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	c.hop();
 	CPPUNIT_ASSERT(c._xPos == 0);
 	CPPUNIT_ASSERT(c._yPos == 1);
    }
    
    void testhop3() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	c.hop();
 	c.hop();
 	c.hop(); 	
 	CPPUNIT_ASSERT(c._xPos == 0);
 	CPPUNIT_ASSERT(c._yPos == 3);
    }
    
    void testlookingX1() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	CPPUNIT_ASSERT(c.lookingX() == 0);
 	
    }
    
    void testlookingX2() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(EAST, HOPPER, 0, 0, &g);
 	CPPUNIT_ASSERT(c.lookingX() == 1);
    }
    
    void testlookingX3() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(WEST, HOPPER, 0, 0, &g);
 	CPPUNIT_ASSERT(c.lookingX() == -1);
    }
    
    void testlookingY1() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	CPPUNIT_ASSERT(c.lookingY() == 1);
    }
    
    void testlookingY2() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(NORTH, HOPPER, 0, 0, &g);
 	CPPUNIT_ASSERT(c.lookingY() == -1);
    }
    
    void testlookingY3() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(EAST, HOPPER, 0, 0, &g);
 	CPPUNIT_ASSERT(c.lookingY() == 0);
    }
    
    void testleft1() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(EAST, HOPPER, 0, 0, &g);
 	c.left();
 	CPPUNIT_ASSERT(c._dir == NORTH);
    }
    
    void testleft2() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(SOUTH, HOPPER, 0, 0, &g);
 	c.left();
 	CPPUNIT_ASSERT(c._dir == EAST);
    }
    
    void testleft3() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(WEST, HOPPER, 0, 0, &g);
 	c.left();
 	CPPUNIT_ASSERT(c._dir == SOUTH);
    }

    void testright1() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(EAST, HOPPER, 0, 0, &g);
 	c.right();
 	CPPUNIT_ASSERT(c._dir == SOUTH);
    }
    
    void testright2() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(NORTH, HOPPER, 0, 0, &g);
 	c.right();
 	CPPUNIT_ASSERT(c._dir == EAST);
    }
    
    void testright3() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(WEST, HOPPER, 0, 0, &g);
 	c.right();
 	CPPUNIT_ASSERT(c._dir == NORTH);
    }
    
    void testinfect1() {
    	Grid g = Grid(50,1,100,100);
 	Creature c = Creature(NORTH, HOPPER, 0, 0, &g);
 	Creature v = Creature(NORTH, HOPPER, 0, 0, &g); 	
 	c.infect(v);
	CPPUNIT_ASSERT(c._species == HOPPER);
    }
    
    void testinfect2() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, ROVER, 0, 0, &g);
 	Creature v = Creature(NORTH, HOPPER, 0, 0, &g); 	
 	c.infect(v);
	CPPUNIT_ASSERT(c._species == ROVER);
    }
    
    void testinfect3() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
 	Creature v = Creature(NORTH, FOOD, 0, 0, &g); 	
 	c.infect(v);
	CPPUNIT_ASSERT(c._species == TRAP);
    }
    
    void testchangePC1() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
    	c.changePC(3);
    	CPPUNIT_ASSERT(c._pc == 3);
    }
    
    void testchangePC2() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
    	c.changePC(5);
    	CPPUNIT_ASSERT(c._pc == 5);
    }
    
    void testchangePC3() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
    	c.changePC(3);
    	c.changePC(0);
    	CPPUNIT_ASSERT(c._pc == 0);
    }
    
    void testif_random1() {
   	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
    	CPPUNIT_ASSERT(c.if_random() != 3);
    }
    
    void testif_random2() {
   	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
    	int res = c.if_random();
    	CPPUNIT_ASSERT(res == 0 || res == 1);   
    }
    
    void testif_random3() {
   	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
    	CPPUNIT_ASSERT(c.if_random() != 2);   
    }
    
    void testis_enemy1() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, HOPPER, 0, 0, &g);
 	Creature v = Creature(NORTH, ROVER, 0, 0, &g); 	
	CPPUNIT_ASSERT(c.is_enemy(v));
    }
    
    void testis_enemy2() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, FOOD, 0, 0, &g);
 	Creature v = Creature(NORTH, FOOD, 0, 0, &g); 	
	CPPUNIT_ASSERT(!c.is_enemy(v));
    }
    
    void testis_enemy3() {
    	Grid g = Grid(50,1,100,100);
    	Creature c = Creature(NORTH, TRAP, 0, 0, &g);
 	Creature v = Creature(NORTH, FOOD, 0, 0, &g); 	
	CPPUNIT_ASSERT(c.is_enemy(v));
    }
    
    void testdoFood1() {
    	Grid g = Grid(50,1,100,100);
 	Creature v = Creature(NORTH, FOOD, 0, 0, &g);
 	v.doFood();
 	CPPUNIT_ASSERT(v._pc == 1); 	    	
    }
    
    void testdoFood2() {
    	Grid g = Grid(50,1,100,100);
 	Creature v = Creature(NORTH, FOOD, 0, 0, &g); 	    	
	v.doFood();
 	CPPUNIT_ASSERT(v._dir == WEST);
    }
    
    void testdoFood3() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, FOOD, 0, 0, &g); 	
    	v.doFood();
    	CPPUNIT_ASSERT(v._xPos == 0 && v._yPos == 0);
    }
    
    void testdoHopper1() {
    	Grid g = Grid(50,1,100,100);
 	Creature v = Creature(NORTH, HOPPER, 0, 0, &g);
 	v.doHopper();
 	CPPUNIT_ASSERT(v._pc == 1); 
    }
    
    void testdoHopper2() {
    	Grid g = Grid(50,1,100,100);
 	Creature v = Creature(NORTH, HOPPER, 0, 0, &g);
 	v.doHopper();
 	CPPUNIT_ASSERT(v._dir == NORTH); 
    }
    
    void testdoHopper3() {
    	Grid g = Grid(50,1,100,100);
 	Creature v = Creature(SOUTH, HOPPER, 0, 0, &g);
 	v.doHopper();
 	CPPUNIT_ASSERT(v._yPos == 1); 
    }
    
    void testdoRover1() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, ROVER, 0, 0, &g);
 	v.doRover();
 	CPPUNIT_ASSERT(v._pc == 1);
    }
    
    void testdoRover2() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, ROVER, 0, 0, &g);
 	v.doRover();
 	CPPUNIT_ASSERT(v._dir == NORTH);
    }
    
    void testdoRover3() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, ROVER, 0, 0, &g);
 	v.doRover();
 	CPPUNIT_ASSERT(v._xPos == 0);
    }
    
    void testdoTrap1() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, TRAP, 0, 0, &g);
 	v.doTrap();
 	CPPUNIT_ASSERT(v._pc == 1);
    }
    
    void testdoTrap2() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, TRAP, 0, 0, &g);
 	v.doTrap();
 	CPPUNIT_ASSERT(v._dir == NORTH);
    }
    
    void testdoTrap3() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, TRAP, 0, 0, &g);
 	v.doTrap();
 	CPPUNIT_ASSERT(v._xPos == 0);
    }
    
    void testdoBest1() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, BEST, 0, 0, &g);
 	v.doBest();
 	CPPUNIT_ASSERT(v._pc == 1);
    }
    
    void testdoBest2() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, BEST, 0, 0, &g);
 	v.doBest();
 	CPPUNIT_ASSERT(v._dir == NORTH);
    }
    
    void testdoBest3() {
    	Grid g = Grid(50,1,100,100);
    	Creature v = Creature(NORTH, BEST, 0, 0, &g);
 	v.doBest();
 	CPPUNIT_ASSERT(v._xPos == 0);
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(testis_empty1);
    CPPUNIT_TEST(testis_empty2);
    CPPUNIT_TEST(testis_empty3);
    CPPUNIT_TEST(testis_wall1);
    CPPUNIT_TEST(testis_wall2);
    CPPUNIT_TEST(testis_wall3);
    CPPUNIT_TEST(testis_creature1);
    CPPUNIT_TEST(testis_creature2);
    CPPUNIT_TEST(testis_creature3);
    CPPUNIT_TEST(testGrid1); 
    CPPUNIT_TEST(testGrid2);
    CPPUNIT_TEST(testGrid3);
    CPPUNIT_TEST(testmove_creature1);
    CPPUNIT_TEST(testmove_creature2);
    CPPUNIT_TEST(testmove_creature3);
    CPPUNIT_TEST(testplace_creature1); 
    CPPUNIT_TEST(testplace_creature2);
    CPPUNIT_TEST(testplace_creature3);
    CPPUNIT_TEST(testexecuteGrid1); 
    CPPUNIT_TEST(testexecuteGrid2);
    CPPUNIT_TEST(testexecuteGrid3);
    CPPUNIT_TEST(testCreature1); 
    CPPUNIT_TEST(testCreature2);
    CPPUNIT_TEST(testCreature3);
    CPPUNIT_TEST(testexecuteTurn1); 
    CPPUNIT_TEST(testexecuteTurn2);
    CPPUNIT_TEST(testexecuteTurn3);
    CPPUNIT_TEST(testcanMove1); 
    CPPUNIT_TEST(testcanMove2);
    CPPUNIT_TEST(testcanMove3);
    CPPUNIT_TEST(testhop1); 
    CPPUNIT_TEST(testhop2);
    CPPUNIT_TEST(testhop3);
    CPPUNIT_TEST(testlookingX1); 
    CPPUNIT_TEST(testlookingX2);
    CPPUNIT_TEST(testlookingX3);
    CPPUNIT_TEST(testlookingY1);
    CPPUNIT_TEST(testlookingY2);
    CPPUNIT_TEST(testlookingY3);
    CPPUNIT_TEST(testleft1); 
    CPPUNIT_TEST(testleft2);
    CPPUNIT_TEST(testleft3);
    CPPUNIT_TEST(testright1); 
    CPPUNIT_TEST(testright2);
    CPPUNIT_TEST(testright3);
    CPPUNIT_TEST(testinfect1); 
    CPPUNIT_TEST(testinfect2);
    CPPUNIT_TEST(testinfect3);
    CPPUNIT_TEST(testchangePC1); 
    CPPUNIT_TEST(testchangePC2);
    CPPUNIT_TEST(testchangePC3);
    CPPUNIT_TEST(testif_random1); 
    CPPUNIT_TEST(testif_random2);
    CPPUNIT_TEST(testif_random3);
    CPPUNIT_TEST(testis_enemy1); 
    CPPUNIT_TEST(testis_enemy2);
    CPPUNIT_TEST(testis_enemy3);
    CPPUNIT_TEST(testdoFood1); 
    CPPUNIT_TEST(testdoFood2);
    CPPUNIT_TEST(testdoFood3);
    CPPUNIT_TEST(testdoHopper1); 
    CPPUNIT_TEST(testdoHopper2);
    CPPUNIT_TEST(testdoHopper3);
    CPPUNIT_TEST(testdoRover1); 
    CPPUNIT_TEST(testdoRover2);
    CPPUNIT_TEST(testdoRover3);
    CPPUNIT_TEST(testdoTrap1);
    CPPUNIT_TEST(testdoTrap2);
    CPPUNIT_TEST(testdoTrap3);
    CPPUNIT_TEST(testdoBest1);
    CPPUNIT_TEST(testdoBest2);
    CPPUNIT_TEST(testdoBest3);
    CPPUNIT_TEST_SUITE_END();
};


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestDarwin::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}

