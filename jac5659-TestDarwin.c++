#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define protected public
#define private public
#define class struct

#include "Darwin.h"

// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
    // -----------------
    // Game::constructor
    // -----------------
    void test_game1(){
        Game g(0,0);
        CPPUNIT_ASSERT(g._rows == 0);
        CPPUNIT_ASSERT(g._cols == 0);
        CPPUNIT_ASSERT(g._num_creatures == 0);
        CPPUNIT_ASSERT(g._turn == 0);
        CPPUNIT_ASSERT(g._grid.size() == 0);
    }
    void test_game2(){
        Game g(1,1);
        CPPUNIT_ASSERT(g._rows == 1);
        CPPUNIT_ASSERT(g._cols == 1);
        CPPUNIT_ASSERT(g._num_creatures == 0);
        CPPUNIT_ASSERT(g._turn == 0);
        CPPUNIT_ASSERT(g._grid[0][0] == NULL);
    }
    void test_game3(){
        Game g(8,7);
        CPPUNIT_ASSERT(g._rows == 8);
        CPPUNIT_ASSERT(g._cols == 7);
        CPPUNIT_ASSERT(g._num_creatures == 0);
        CPPUNIT_ASSERT(g._turn == 0);
        for(int r = 0; r < 8; r++){
            for(int c = 0; c < 7; c++){
                CPPUNIT_ASSERT(g._grid[r][c] == NULL);
            }
        }
    }
    
    // ----------------
    // Game::print_grid
    // ----------------
    void test_print1(){
        Game g(1,1);
        std::ostringstream o;
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  0\n"
            "0 .\n\n");
    }
    void test_print2(){
        Game g(3,2);
        std::ostringstream o;
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 ..\n"
            "1 ..\n"
            "2 ..\n\n");
    }
    void test_print3(){
        Game g(11,11);
        std::ostringstream o;
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01234567890\n"
            "0 ...........\n"
            "1 ...........\n"
            "2 ...........\n"
            "3 ...........\n"
            "4 ...........\n"
            "5 ...........\n"
            "6 ...........\n"
            "7 ...........\n"
            "8 ...........\n"
            "9 ...........\n"
            "0 ...........\n\n");
    }
    
    // ------------------
    // Game::add_creature
    // ------------------
    void test_add1(){
        Game g(1,1);
        std::ostringstream o;
        Food f(0);
        g.add_creature(f,0,0);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  0\n"
            "0 f\n\n");
    }
    void test_add2(){
        Game g(0,0);
        std::ostringstream o;
        Food f(0);
        try{
            g.add_creature(f,0,0);
            CPPUNIT_ASSERT(false);
        }
        catch(std::out_of_range& e){
            CPPUNIT_ASSERT(true);
        }
    }
    void test_add3(){
        Game g(2,2);
        std::ostringstream o;
        Food f(0);
        Hopper h(0);
        g.add_creature(f,0,0);
        g.add_creature(h,1,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 f.\n"
            "1 .h\n\n");
    }
    
    void test_creature_equals1(){
    	Food f1(0);
    	Food f2(0);
    	CPPUNIT_ASSERT(f1 == f2);
    }
    
    void test_creature_equals2(){
    	Food f(0);
    	Hopper h(0);
    	CPPUNIT_ASSERT(!(f == h));
    }
    
    void test_if_enemy1(){
    	Game g(9,9);
    	Food f(1);
        Hopper h(0);
        g.add_creature(f,3,3);
        g.add_creature(h,3,2);
        CPPUNIT_ASSERT(!g.if_enemy(3,3));
    }
    void test_if_enemy2(){
    	Game g(9,9);
    	Food f(0);
        Hopper h(0);
        g.add_creature(f,3,3);
        g.add_creature(h,3,2);
        CPPUNIT_ASSERT(g.if_enemy(3,3));
    }
    void test_if_enemy3(){
    	Game g(9,9);
    	Food f1(0);
        Food f2(0);
        g.add_creature(f1,3,3);
        g.add_creature(f2,3,2);
        CPPUNIT_ASSERT(!g.if_enemy(3,3));
    }
    void test_if_enemy4(){
    	Game g(9,9);
    	Trap t1(0);
        g.add_creature(t1,0,0);
        g.run(5, 0);
        CPPUNIT_ASSERT(t1.get_direction() == 3);
    }

	void test_creature_infect1(){
		Rover r1(0);
		Food f1(0);
		++f1._pc;
		CPPUNIT_ASSERT(f1._pc == 1);
		r1.infect(f1);
		CPPUNIT_ASSERT(f1._direction == 0);
		CPPUNIT_ASSERT(r1._species == f1._species);
		CPPUNIT_ASSERT(f1._pc == 0);
	}
    
    void test_creature_infect2(){
        Game g(2,2);
        std::ostringstream o;
        Rover r1(0);
		Food f1(0);
        g.add_creature(r1,0,0);
        g.add_creature(f1,1,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 r.\n"
            "1 .f\n\n");
		r1.infect(f1);
		CPPUNIT_ASSERT(f1._direction == 0);
		CPPUNIT_ASSERT(r1._species == f1._species);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 r.\n"
            "1 .r\n\n");
	}
	
	void test_creature_left1(){
		Food f1(0);
		CPPUNIT_ASSERT(f1.get_direction() == 0);
		f1.turn_left();
		CPPUNIT_ASSERT(f1.get_direction() == 3);
	}
	void test_creature_left2(){
		Food f1(1);
		CPPUNIT_ASSERT(f1.get_direction() == 1);
		f1.turn_left();
		CPPUNIT_ASSERT(f1.get_direction() == 0);
	}
	void test_creature_left3(){
		Food f1(2);
		CPPUNIT_ASSERT(f1.get_direction() == 2);
		f1.turn_left();
		CPPUNIT_ASSERT(f1.get_direction() == 1);
	}
	void test_creature_left4(){
		Food f1(3);
		CPPUNIT_ASSERT(f1.get_direction() == 3);
		f1.turn_left();
		CPPUNIT_ASSERT(f1.get_direction() == 2);
	}
	void test_creature_right1(){
		Food f1(0);
		CPPUNIT_ASSERT(f1.get_direction() == 0);
		f1.turn_right();
		CPPUNIT_ASSERT(f1.get_direction() == 1);
	}
	void test_creature_right2(){
		Food f1(1);
		CPPUNIT_ASSERT(f1.get_direction() == 1);
		f1.turn_right();
		CPPUNIT_ASSERT(f1.get_direction() == 2);
	}
	void test_creature_right3(){
		Food f1(2);
		CPPUNIT_ASSERT(f1.get_direction() == 2);
		f1.turn_right();
		CPPUNIT_ASSERT(f1.get_direction() == 3);
	}
	void test_creature_right4(){
		Food f1(3);
		CPPUNIT_ASSERT(f1.get_direction() == 3);
		f1.turn_right();
		CPPUNIT_ASSERT(f1.get_direction() == 0);
	}
	
	void test_creature_getInstruction1(){
		Food f1(0);
		pair<Instruction,int> p = f1.get_instruction();
		CPPUNIT_ASSERT(p.second == -1);
		++f1._pc;
		p = f1.get_instruction();
		CPPUNIT_ASSERT(p.second == 0);
	}
	
	void test_creature_getInstruction2(){
		Rover r1(0);
		pair<Instruction,int> p = r1.get_instruction();
		CPPUNIT_ASSERT(p.second == 9);
		++r1._pc;
		p = r1.get_instruction();
		CPPUNIT_ASSERT(p.second == 7);
	}
	
	void test_creature_getInstruction3(){
		Trap t1(0);
		pair<Instruction,int> p = t1.get_instruction();
		CPPUNIT_ASSERT(p.second == 3);
		++t1._pc;
		p = t1.get_instruction();
		CPPUNIT_ASSERT(p.second == -1);
	}
	
	void test_game_is_empty1(){
		Game g(2,2);
        Hopper h(0);
        g.add_creature(h,1,1);
		CPPUNIT_ASSERT(!g.is_empty(1, 1));	
	}
	void test_game_is_empty2(){
		Game g(2,2);
        Hopper h(0);
        g.add_creature(h,1,1);
		CPPUNIT_ASSERT(!g.is_empty(2, 2));	
	}
	void test_game_is_empty3(){
		Game g(2,2);
        Hopper h(0);
        g.add_creature(h,1,1);
		CPPUNIT_ASSERT(g.is_empty(0, 0));	
	}
	
	void test_game_is_wall1(){
		Game g(2,2);
        Hopper h(0);
        g.add_creature(h,1,1);
		CPPUNIT_ASSERT(!g.is_wall(1, 1));	
	}
	void test_game_is_wall2(){
		Game g(2,2);
        Hopper h(0);
        g.add_creature(h,1,1);
		CPPUNIT_ASSERT(g.is_wall(2, 2));	
	}
	void test_game_is_wall3(){
		Game g(2,2);
        Hopper h(0);
        g.add_creature(h,1,1);
		CPPUNIT_ASSERT(g.is_wall(0, -1));	
	}
	
	void test_game_if_enemy1(){
		Game g(2,2);
        Food f1(0);
        Food f2(0);
        g.add_creature(f1,1,1);
        g.add_creature(f2,1,0);
		CPPUNIT_ASSERT(!g.if_enemy(1, 1));
	}
	void test_game_if_enemy2(){
		Game g(2,2);
        Food f1(0);
        Food f2(0);
        g.add_creature(f1,1,1);
        g.add_creature(f2,1,0);
		CPPUNIT_ASSERT(!g.if_enemy(1, 0));
	}
	void test_game_if_enemy3(){
		Game g(2,2);
        Food f1(0);
        g.add_creature(f1,1,1);
		CPPUNIT_ASSERT(!g.if_enemy(1, 1));
	}
	void test_game_if_enemy4(){
		Game g(2,2);
        Hopper f1(0);
        Food f2(0);
        g.add_creature(f1,1,1);
        g.add_creature(f2,1,0);
		CPPUNIT_ASSERT(g.if_enemy(1, 1));
	}
	
	void test_game_infect1(){
		Game g(2,2);
        std::ostringstream o;
        Rover r1(2);
		Food f1(0);
        g.add_creature(r1,0,0);
        g.add_creature(f1,0,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 rf\n"
            "1 ..\n\n");
		g.infect_creature(0,0);
		CPPUNIT_ASSERT(f1._direction == 0);
		CPPUNIT_ASSERT(r1._species == f1._species);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 rr\n"
            "1 ..\n\n");
	}
	void test_game_infect2(){
		Game g(2,2);
        std::ostringstream o;
        Rover r1(2);
		Food f1(0);
        g.add_creature(r1,0,0);
        g.add_creature(f1,0,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 rf\n"
            "1 ..\n\n");
		g.infect_creature(0,1);
		CPPUNIT_ASSERT(r1._direction == 2);
		CPPUNIT_ASSERT(r1._species == f1._species);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 ff\n"
            "1 ..\n\n");
	}
	
	void test_game_move_creature1(){
		Game g(2,2);
        std::ostringstream o;
		Food f1(0);
        g.add_creature(f1,0,0);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 f.\n"
            "1 ..\n\n");
		g.move_creature(0,0,0,1);
		CPPUNIT_ASSERT(g._grid[0][0] == NULL);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 .f\n"
            "1 ..\n\n");
	}
	void test_game_move_creature2(){
		Game g(2,2);
        std::ostringstream o;
		Food f1(0);
        g.add_creature(f1,0,0);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 f.\n"
            "1 ..\n\n");
		g.move_creature(0,0,0,2);
		CPPUNIT_ASSERT(g._grid[0][0] != NULL);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 f.\n"
            "1 ..\n\n");
	}
	void test_game_move_creature3(){
		Game g(2,2);
        std::ostringstream o;
		Food f1(0);
		Food f2(0);
        g.add_creature(f1,0,0);
        g.add_creature(f1,1,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 f.\n"
            "1 .f\n\n");
		g.move_creature(0,0,1,1);
		CPPUNIT_ASSERT(g._grid[0][0] != NULL);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 f.\n"
            "1 .f\n\n");
	}
	
	void test_action_left1(){
		Game g(2,2);
        Food f1(0);
        g.add_creature(f1,1,1);
        Action::left(g,f1,1,1,0);
		CPPUNIT_ASSERT(f1._direction == 3);
	}
	void test_action_left2(){
		Game g(2,2);
        Food f1(0);
        g.add_creature(f1,1,1);
        Action::left(g,f1,1,1,0);
        Action::left(g,f1,1,1,0);
		CPPUNIT_ASSERT(f1._direction == 2);
	}
	
	void test_action_right1(){
		Game g(2,2);
        Food f1(0);
        g.add_creature(f1,1,1);
        Action::right(g,f1,1,1,0);
		CPPUNIT_ASSERT(f1._direction == 1);
	}
	void test_action_right2(){
		Game g(2,2);
        Food f1(0);
        g.add_creature(f1,1,1);
        Action::right(g,f1,1,1,0);
        Action::right(g,f1,1,1,0);
		CPPUNIT_ASSERT(f1._direction == 2);
	}
	
	void test_action_hop1(){
		Game g(2,2);
        Hopper h1(0);
        g.add_creature(h1,1,1);
        Action::hop(g,h1,1,1,0);
		CPPUNIT_ASSERT(h1._direction == 0);
		CPPUNIT_ASSERT(g._grid[1][1] == NULL);
		CPPUNIT_ASSERT(g._grid[1][0] != NULL);
	}
	void test_action_hop2(){
		Game g(2,2);
        Hopper h1(2);
        g.add_creature(h1,1,1);
        Action::hop(g,h1,1,1,0);
		CPPUNIT_ASSERT(h1._direction == 2);
		CPPUNIT_ASSERT(g._grid[1][1] != NULL);
		CPPUNIT_ASSERT(g._grid[1][0] == NULL);
		CPPUNIT_ASSERT(g._grid[1][2] == NULL);
	}
	
	void test_action_infect1(){
		Game g(2,2);
        std::ostringstream o;
        Rover r1(2);
		Food f1(0);
        g.add_creature(r1,0,0);
        g.add_creature(f1,0,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 rf\n"
            "1 ..\n\n");
		Action::infect(g,r1,0,0,0);
		CPPUNIT_ASSERT(f1._direction == 0);
		CPPUNIT_ASSERT(r1._species == f1._species);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 rr\n"
            "1 ..\n\n");
	}
	void test_action_infect2(){
		Game g(2,2);
        std::ostringstream o;
        Rover r1(2);
		Food f1(0);
        g.add_creature(r1,0,0);
        g.add_creature(f1,0,1);
        g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 rf\n"
            "1 ..\n\n");
		Action::infect(g,f1,0,1,0);
		CPPUNIT_ASSERT(r1._direction == 2);
		CPPUNIT_ASSERT(r1._species == f1._species);
		o.str("");
		o.clear();
		g.print_grid(o);
        CPPUNIT_ASSERT(o.str() == 
            "Turn = 0.\n"
            "  01\n"
            "0 ff\n"
            "1 ..\n\n");
	}
	
	void test_control_go1(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		CPPUNIT_ASSERT(Control::go(g,f1,0,0,5) == 5);
	}
	void test_control_go2(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		CPPUNIT_ASSERT(Control::go(g,f1,0,0,-2) == -2);
	}
	
	void test_control_if_enemy1(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		CPPUNIT_ASSERT(Control::if_enemy(g,f1,0,0,5) == -2);
	}
	void test_control_if_enemy2(){
		Game g(2,2);
		Food f1(0);
		Hopper h1(0);
		g.add_creature(f1,0,1);
		g.add_creature(h1,0,0);
		CPPUNIT_ASSERT(Control::if_enemy(g,f1,0,1,5) == 5);
	}
	
	void test_control_if_random1(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		CPPUNIT_ASSERT(Control::if_random(g,f1,0,0,5) == 5);
	}
	void test_control_if_random2(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		Control::if_random(g,f1,0,0,5);
		Control::if_random(g,f1,0,0,5);
		CPPUNIT_ASSERT(Control::if_random(g,f1,0,0,5) == 5);
	}
	
	void test_control_if_wall1(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		CPPUNIT_ASSERT(Control::if_wall(g,f1,0,0,5) == 5);
	}
	void test_control_if_wall2(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,1);
		CPPUNIT_ASSERT(Control::if_wall(g,f1,0,1,5) == -2);
	}
	
	void test_control_if_empty1(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,0);
		CPPUNIT_ASSERT(Control::if_empty(g,f1,0,0,5) == -2);
	}
	void test_control_if_empty2(){
		Game g(2,2);
		Food f1(0);
		g.add_creature(f1,0,1);
		CPPUNIT_ASSERT(Control::if_empty(g,f1,0,1,5) == 5);
	}
	void test_control_if_empty3(){
		Game g(2,2);
		Food f1(0);
		Food f2(0);
		g.add_creature(f1,0,1);
		g.add_creature(f2,0,0);
		CPPUNIT_ASSERT(Control::if_empty(g,f1,0,1,5) == -2);
	}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(test_game1);
    CPPUNIT_TEST(test_game2);
    CPPUNIT_TEST(test_game3);
    CPPUNIT_TEST(test_print1);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST(test_add1);
    CPPUNIT_TEST(test_add2);
    CPPUNIT_TEST(test_add3);
    CPPUNIT_TEST(test_creature_equals1);
    CPPUNIT_TEST(test_creature_equals2);
    CPPUNIT_TEST(test_if_enemy1);
    CPPUNIT_TEST(test_if_enemy2);
    CPPUNIT_TEST(test_if_enemy3);
    CPPUNIT_TEST(test_if_enemy4);
    CPPUNIT_TEST(test_creature_infect1);
    CPPUNIT_TEST(test_creature_infect2);
    CPPUNIT_TEST(test_creature_left1);
    CPPUNIT_TEST(test_creature_left2);
    CPPUNIT_TEST(test_creature_left3);
    CPPUNIT_TEST(test_creature_left4);
    CPPUNIT_TEST(test_creature_right1);
    CPPUNIT_TEST(test_creature_right2);
    CPPUNIT_TEST(test_creature_right3);
    CPPUNIT_TEST(test_creature_right4);
    CPPUNIT_TEST(test_creature_getInstruction1);
    CPPUNIT_TEST(test_creature_getInstruction2);
    CPPUNIT_TEST(test_creature_getInstruction3);
    CPPUNIT_TEST(test_game_is_empty1);
    CPPUNIT_TEST(test_game_is_empty2);
    CPPUNIT_TEST(test_game_is_empty3);
    CPPUNIT_TEST(test_game_is_wall1);
    CPPUNIT_TEST(test_game_is_wall2);
    CPPUNIT_TEST(test_game_is_wall3);
    CPPUNIT_TEST(test_game_if_enemy1);
    CPPUNIT_TEST(test_game_if_enemy2);
    CPPUNIT_TEST(test_game_if_enemy3);
    CPPUNIT_TEST(test_game_if_enemy4);
    CPPUNIT_TEST(test_game_infect1);
    CPPUNIT_TEST(test_game_infect2);
    CPPUNIT_TEST(test_game_move_creature1);
    CPPUNIT_TEST(test_game_move_creature2);
    CPPUNIT_TEST(test_game_move_creature3);
    CPPUNIT_TEST(test_action_left1);
    CPPUNIT_TEST(test_action_left2);
    CPPUNIT_TEST(test_action_right1);
    CPPUNIT_TEST(test_action_right2);
    CPPUNIT_TEST(test_action_hop1);
    CPPUNIT_TEST(test_action_hop2);
    CPPUNIT_TEST(test_action_infect1);
    CPPUNIT_TEST(test_action_infect2);
    CPPUNIT_TEST(test_control_go1);
    CPPUNIT_TEST(test_control_go2);
    CPPUNIT_TEST(test_control_if_enemy1);
    CPPUNIT_TEST(test_control_if_enemy2);
    CPPUNIT_TEST(test_control_if_random1);
    CPPUNIT_TEST(test_control_if_random2);
    CPPUNIT_TEST(test_control_if_wall1);
    CPPUNIT_TEST(test_control_if_wall2);
    CPPUNIT_TEST(test_control_if_empty1);
    CPPUNIT_TEST(test_control_if_empty2);
    CPPUNIT_TEST(test_control_if_empty3);
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
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
