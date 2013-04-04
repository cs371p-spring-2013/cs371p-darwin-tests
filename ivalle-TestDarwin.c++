#define private public
#define protected public

#include "Darwin.h"

#include <iostream>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

struct TestDarwin : CppUnit::TestFixture
{
    void Location_GetNextLocation1()
    {
        //Arrange
        Location location(Direction::EAST, 0, 0);

        //Act
        Location nextLocation = location.GetNextLocation();

        //Assert
        CPPUNIT_ASSERT(nextLocation._direction == Direction::EAST);
        CPPUNIT_ASSERT(nextLocation.x == 0);
        CPPUNIT_ASSERT(nextLocation.y == 1);
    }

    void Location_GetNextLocation2()
    {
        //Arrange
        Location location(Direction::NORTH, 0, 0);

        //Act
        Location nextLocation = location.GetNextLocation();

        //Assert
        CPPUNIT_ASSERT(nextLocation._direction == Direction::NORTH);
        CPPUNIT_ASSERT(nextLocation.x == -1);
        CPPUNIT_ASSERT(nextLocation.y == 0);
    }

    void Location_GetNextLocation3()
    {
        //Arrange
        Location location(Direction::SOUTH, 5, 3);

        //Act
        Location nextLocation = location.GetNextLocation();

        //Assert
        CPPUNIT_ASSERT(nextLocation._direction == Direction::SOUTH);
        CPPUNIT_ASSERT(nextLocation.x == 6);
        CPPUNIT_ASSERT(nextLocation.y == 3);
    }

    void Direction_turnRight1()
    {
        //Arrange
        Direction direction = Direction::EAST;

        //Act
        direction.turnRight();

        //Assert
        CPPUNIT_ASSERT(direction == Direction::SOUTH);
    }

    void Direction_turnRight2()
    {
        //Arrange
        Direction direction = Direction::WEST;

        //Act
        direction.turnRight();

        //Assert
        CPPUNIT_ASSERT(direction == Direction::NORTH);
    }

    void Direction_turnRight3()
    {
        //Arrange
        Direction direction = Direction::SOUTH;

        //Act
        direction.turnRight();

        //Assert
        CPPUNIT_ASSERT(direction == Direction::WEST);
    }

    void Direction_turnLeft1()
    {
        //Arrange
        Direction direction = Direction::EAST;

        //Act
        direction.turnLeft();

        //Assert
        CPPUNIT_ASSERT(direction == Direction::NORTH);
    }

    void Direction_turnLeft2()
    {
        //Arrange
        Direction direction = Direction::WEST;

        //Act
        direction.turnLeft();

        //Assert
        CPPUNIT_ASSERT(direction == Direction::SOUTH);
    }

    void Direction_turnLeft3()
    {
        //Arrange
        Direction direction = Direction::NORTH;

        //Act
        direction.turnLeft();

        //Assert
        CPPUNIT_ASSERT(direction == Direction::WEST);
    }

    void Instruction_Instruction1()
    {
        //Act
        Instruction instruction(Instruction::if_enemy, 2);

        //Assert
        CPPUNIT_ASSERT(instruction._instruction == Instruction::if_enemy);
        CPPUNIT_ASSERT(instruction._argument == 2);
    }

    void Instruction_Instruction2()
    {
        //Act
        Instruction instruction(Instruction::hop, 0);

        //Assert
        CPPUNIT_ASSERT(instruction._instruction == Instruction::hop);
        CPPUNIT_ASSERT(instruction._argument == 0);
    }

    void Instruction_Instruction3()
    {
        //Act
        Instruction instruction(Instruction::go, 0);

        //Assert
        CPPUNIT_ASSERT(instruction._instruction == Instruction::go);
        CPPUNIT_ASSERT(instruction._argument == 0);
    }

    void Program_AddInstruction1()
    {
        //Arrange
        Program p;
        Instruction instruction(Instruction::go, 0);

        //Act
        p.AddInstruction(instruction);

        //Assert
        CPPUNIT_ASSERT(p._instructions[0]._instruction == instruction._instruction);
    }

    void Program_AddInstruction2()
    {
        //Arrange
        Program p;
        Instruction instruction(Instruction::go, 0);
	    Instruction instruction1(Instruction::hop, 0);

        //Act
        p.AddInstruction(instruction);
	    p.AddInstruction(instruction1);

        //Assert
        CPPUNIT_ASSERT(p._instructions[0]._instruction == instruction._instruction);
	    CPPUNIT_ASSERT(p._instructions[1]._instruction == instruction1._instruction);
    }

    void Program_AddInstruction3()
    {
        //Arrange
        Program p;
        Instruction instruction(Instruction::go, 0);
	    Instruction instruction1(Instruction::hop, 0);
	    Instruction instruction2(Instruction::if_enemy, 4);

        //Act
        p.AddInstruction(instruction);
	    p.AddInstruction(instruction1);
	    p.AddInstruction(instruction2);

        //Assert
        CPPUNIT_ASSERT(p._instructions[0]._instruction == instruction._instruction);
	    CPPUNIT_ASSERT(p._instructions[1]._instruction == instruction1._instruction);
	    CPPUNIT_ASSERT(p._instructions[2]._instruction == instruction2._instruction);
    }

    void Program_GetInstructionByLineNumber1()
    {
        //Arrange
        Program p;

        //Act
        p._instructions.push_back(Instruction(Instruction::go, 0));

        //Assert
        CPPUNIT_ASSERT(p.GetInstructionByLineNumber(0)._instruction == Instruction::go);
    }
    void Program_GetInstructionByLineNumber2()
    {
        //Arrange
        Program p;

        //Act
        p._instructions.push_back(Instruction(Instruction::go, 0));
        p._instructions.push_back(Instruction(Instruction::hop, 0));

        //Assert
        CPPUNIT_ASSERT(p.GetInstructionByLineNumber(1)._instruction == Instruction::hop);
    }
    void Program_GetInstructionByLineNumber3()
    {
        //Arrange
        Program p;

        //Act
        p._instructions.push_back(Instruction(Instruction::go, 0));
        p._instructions.push_back(Instruction(Instruction::hop, 0));

        //Assert
        CPPUNIT_ASSERT(p.GetInstructionByLineNumber(0)._instruction == Instruction::go);
    }

    void Board_Board1()
    {
        //Act
        Board board(5, 5);

        //Assert
        CPPUNIT_ASSERT(board.ROWS == 5);
        CPPUNIT_ASSERT(board.COLUMNS == 5);
        CPPUNIT_ASSERT(board.board[0].size() == 5);
        CPPUNIT_ASSERT(board.board[4].size() == 5);
    }
    void Board_Board2()
    {
        //Act
        Board board(10, 5);

        //Assert
        CPPUNIT_ASSERT(board.ROWS == 10);
        CPPUNIT_ASSERT(board.COLUMNS == 5);
        CPPUNIT_ASSERT(board.board[0].size() == 5);
        CPPUNIT_ASSERT(board.board[4].size() == 5);
    }
    void Board_Board3()
    {
        //Act
        Board board(5, 10);

        //Assert
        CPPUNIT_ASSERT(board.ROWS == 5);
        CPPUNIT_ASSERT(board.COLUMNS == 10);
        CPPUNIT_ASSERT(board.board[0].size() == 10);
        CPPUNIT_ASSERT(board.board[4].size() == 10);
    }

    void Board_EnemyAhead1()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        Creature trap = Trap(Direction::EAST, 0, 1);
        board.board[0][0] = &food;
        board.board[0][1] = &trap;

        //Act
        bool enemyAhead = board.EnemyAhead(&food);

        //Assert
        CPPUNIT_ASSERT(enemyAhead);
    }
    void Board_EnemyAhead2()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        board.board[0][0] = &food;

        //Act
        bool enemyAhead = board.EnemyAhead(&food);

        //Assert
        CPPUNIT_ASSERT(!enemyAhead);
    }
    void Board_EnemyAhead3()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        Creature food1 = Food(Direction::EAST, 0, 1);
        board.board[0][0] = &food;
        board.board[0][1] = &food1;

        //Act
        bool enemyAhead = board.EnemyAhead(&food);

        //Assert
        CPPUNIT_ASSERT(!enemyAhead);
    }

    void Board_IsOccupied1()
    {
        //Arrange
        Board board(5, 5);
        Location location(Direction::EAST, 0, 0);

        //Act
        bool isOccupied = board.IsOccupied(location);

        //Assert
        CPPUNIT_ASSERT(!isOccupied);
    }
    void Board_IsOccupied2()
    {
        //Arrange
        Board board(5, 5);
        Location location(Direction::EAST, 0, 0);
        Food food(Direction::EAST, 0, 0);
        board.board[0][0] = &food;

        //Act
        bool isOccupied = board.IsOccupied(location);

        //Assert
        CPPUNIT_ASSERT(isOccupied);
    }
    void Board_IsOccupied3()
    {
        //Arrange
        Board board(5, 5);
        Location location(Direction::EAST, 0, 1);
        Food food(Direction::EAST, 0, 0);
        board.board[0][0] = &food;
        //Act
        bool isOccupied = board.IsOccupied(location);

        //Assert
        CPPUNIT_ASSERT(!isOccupied);
    }

    void Board_IsWall1()
    {
        //Arrange
        Board board(5, 5);
        Location location(Direction::EAST, 0, 0);

        //Act
        bool isWall = board.IsWall(location);

        //Assert
        CPPUNIT_ASSERT(!isWall);
    }
    void Board_IsWall2()
    {
        //Arrange
        Board board(5, 5);
        Location location(Direction::EAST, 0, -1);

        //Act
        bool isWall = board.IsWall(location);

        //Assert
        CPPUNIT_ASSERT(isWall);
    }
    void Board_IsWall3()
    {
        //Arrange
        Board board(5, 5);
        Location location(Direction::EAST, -1, 0);

        //Act
        bool isWall = board.IsWall(location);

        //Assert
        CPPUNIT_ASSERT(isWall);
    }

    void Board_RemoveCreature1()
    {
        //Assert
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        board.board[0][0] = &food;

        //Act
        board.RemoveCreature(&food);

        //Assert
        CPPUNIT_ASSERT(board.board[0][0] == NULL);
    }
    void Board_RemoveCreature2()
    {
        //Assert
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 4, 4);
        board.board[4][4] = &food;

        //Act
        board.RemoveCreature(&food);

        //Assert
        CPPUNIT_ASSERT(board.board[4][4] == NULL);
    }
    void Board_RemoveCreature3()
    {
        //Assert
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 2, 3);
        board.board[2][3] = &food;

        //Act
        board.RemoveCreature(&food);

        //Assert
        CPPUNIT_ASSERT(board.board[2][3] == NULL);
    }

    void Board_UpdateCreature1()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);

        //Act
        board.UpdateCreature(&food);

        //Assert
        CPPUNIT_ASSERT(board.board[0][0] != NULL);
    }
    void Board_UpdateCreature2()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::NORTH, 2, 3);

        //Act
        board.UpdateCreature(&food);

        //Assert
        CPPUNIT_ASSERT(board.board[2][3] != NULL);
    }
    void Board_UpdateCreature3()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::SOUTH, 4, 4);

        //Act
        board.UpdateCreature(&food);

        //Assert
        CPPUNIT_ASSERT(board.board[4][4] != NULL);
    }

    void Board_UpdateCreatures1()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        vector<Creature*> creatures;
        creatures.push_back(&food);

        //Act
        board.UpdateCreatures(creatures);

        //Assert
        CPPUNIT_ASSERT(board.board[0][0] != NULL);
    }
    void Board_UpdateCreatures2()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        Creature hopper = Hopper(Direction::EAST, 1, 1);
        vector<Creature*> creatures;
        creatures.push_back(&food);
        creatures.push_back(&hopper);

        //Act
        board.UpdateCreatures(creatures);

        //Assert
        CPPUNIT_ASSERT(board.board[0][0] != NULL);
        CPPUNIT_ASSERT(board.board[1][1] != NULL);
    }
    void Board_UpdateCreatures3()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        Creature hopper= Hopper(Direction::EAST, 1, 1);
        Creature rover = Rover(Direction::EAST, 2, 2);
        vector<Creature*> creatures;
        creatures.push_back(&food);
        creatures.push_back(&hopper);
        creatures.push_back(&rover);

        //Act
        board.UpdateCreatures(creatures);

        //Assert
        CPPUNIT_ASSERT(board.board[0][0] != NULL);
        CPPUNIT_ASSERT(board.board[1][1] != NULL);
        CPPUNIT_ASSERT(board.board[2][2] != NULL);
    }

    void Board_GetCreature1()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        Location location(Direction::EAST, 0, 0);
        board.board[0][0] = &food;

        //Act
        Creature* creature = board.GetCreature(location);

        //Assert
        CPPUNIT_ASSERT(creature->type == food.type);
    }
    void Board_GetCreature2()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 2, 3);
        Location location(Direction::EAST, 2, 3);
        board.board[2][3] = &food;

        //Act
        Creature* creature = board.GetCreature(location);

        //Assert
        CPPUNIT_ASSERT(creature->type == food.type);
    }
    void Board_GetCreature3()
    {
        //Arrange
        Board board(5, 5);
        Creature food = Food(Direction::EAST, 3, 2);
        Location location(Direction::EAST, 3, 2);
        board.board[3][2] = &food;

        //Act
        Creature* creature = board.GetCreature(location);

        //Assert
        CPPUNIT_ASSERT(creature->type == food.type);
    }

    void Game_Game1()
    {
        //Act
        Game game(5, 5);

        //Assert
        CPPUNIT_ASSERT(game.board.ROWS == 5);
        CPPUNIT_ASSERT(game.board.COLUMNS == 5);
    }
    void Game_Game2()
    {
        //Act
        Game game(2, 3);

        //Assert
        CPPUNIT_ASSERT(game.board.ROWS == 2);
        CPPUNIT_ASSERT(game.board.COLUMNS == 3);
    }
    void Game_Game3()
    {
        //Act
        Game game(3, 2);

        //Assert
        CPPUNIT_ASSERT(game.board.ROWS == 3);
        CPPUNIT_ASSERT(game.board.COLUMNS == 2);
    }

    void Game_canHop1()
    {
        //Arrange
        Game game(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        game.addCreature(food);

        //Act
        bool canHop = game.canHop(&food);

        //Assert
        CPPUNIT_ASSERT(canHop);
    }
    void Game_canHop2()
    {
        //Arrange
        Game game(5, 5);
        Creature food = Food(Direction::WEST, 0, 0);
        game.addCreature(food);

        //Act
        bool canHop = game.canHop(&food);

        //Assert
        CPPUNIT_ASSERT(!canHop);
    }
    void Game_canHop3()
    {
        //Arrange
        Game game(5, 5);
        Creature food = Food(Direction::EAST, 0, 0);
        Creature hop = Hopper(Direction::EAST, 0, 1);
        game.board.board[0][0] = &food;
        game.board.board[0][1] = &hop;
        //Act
        bool canHop = game.canHop(&food);

        //Assert
        CPPUNIT_ASSERT(!canHop);
    }

    void Game_addCreature1()
    {
        //Arrange
        Game game(5, 5);
        Creature creature = Food(Direction::EAST, 0, 0);

        //Act
        game.addCreature(creature);

        //Assert
        CPPUNIT_ASSERT(game.creatures[0]->type == creature.type);
    }
    void Game_addCreature2()
    {
        //Arrange
        Game game(5, 5);
        Creature creature = Food(Direction::EAST, 0, 0);
        Creature creature2 = Hopper(Direction::EAST, 1, 1);

        //Act
        game.addCreature(creature);
        game.addCreature(creature2);

        //Assert
        CPPUNIT_ASSERT(game.creatures[0]->type == creature.type);
        CPPUNIT_ASSERT(game.creatures[1]->type == creature2.type);
    }
    void Game_addCreature3()
    {
        //Arrange
        Game game(5, 5);
        Creature creature = Food(Direction::EAST, 0, 0);
        Creature creature2 = Hopper(Direction::EAST, 1, 1);
        Creature creature3 = Rover(Direction::EAST, 2, 2);

        //Act
        game.addCreature(creature);
        game.addCreature(creature2);
        game.addCreature(creature3);

        //Assert
        CPPUNIT_ASSERT(game.creatures[0]->type == creature.type);
        CPPUNIT_ASSERT(game.creatures[1]->type == creature2.type);
        CPPUNIT_ASSERT(game.creatures[2]->type == creature3.type);
    }

    void Game_runInstruction1()
    {
        //Arrange
        Game game(5, 5);
        Creature creature = Food(Direction::EAST, 0, 0);
        game.addCreature(creature);

        //Act
        int returnCode = game.runInstruction(&creature, Instruction(Instruction::go, 0));

        //Assert
        CPPUNIT_ASSERT(returnCode == 0);
    }
    void Game_runInstruction2()
    {
        //Arrange
        Game game(5, 5);
        Creature creature = Food(Direction::EAST, 0, 0);
        game.addCreature(creature);

        //Act
        int returnCode = game.runInstruction(&creature, Instruction(Instruction::if_empty, 3));

        //Assert
        CPPUNIT_ASSERT(returnCode == 3);
    }
    void Game_runInstruction3()
    {
        //Arrange
        Game game(5, 5);
        Creature creature = Food(Direction::EAST, 0, 0);
        game.addCreature(creature);

        //Act
        int returnCode = game.runInstruction(&creature, Instruction(Instruction::hop, 0));

        //Assert
        CPPUNIT_ASSERT(returnCode == -1);
    }

    void Game_executeProgram1()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        game.addCreature(hopper);

        //Act
        game.executeProgram(&hopper);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &hopper);
    }
    void Game_executeProgram2()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 4, 4);
        game.board.board[4][4] = &hopper;

        //Act
        game.executeProgram(&hopper);

        //Assert
        CPPUNIT_ASSERT(game.board.board[4][4] == &hopper);
    }
    void Game_executeProgram3()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature rover = Rover(Direction::NORTH, 1, 0);
        game.addCreature(rover);
        game.addCreature(hopper);

        //Act
        game.executeProgram(&rover);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][0]->type == rover.type);
    }

    void Game_move1()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature food = Food(Direction::EAST, 0, 1);
        game.board.UpdateCreature(&hopper);
        game.board.UpdateCreature(&food);

        //Act
        game.move(0);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &food);
    }
    void Game_move2()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature food = Food(Direction::EAST, 0, 1);
        game.board.UpdateCreature(&hopper);
        game.board.UpdateCreature(&food);

        //Act
        game.move(0);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &food);
    }
    void Game_move3()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature food = Food(Direction::EAST, 0, 1);
        game.board.UpdateCreature(&hopper);
        game.board.UpdateCreature(&food);

        //Act
        game.move(0);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &food);
    }

    void Game_simulate1()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature food = Food(Direction::EAST, 0, 1);
        game.board.UpdateCreature(&hopper);
        game.board.UpdateCreature(&food);

        //Act
        game.simulate(1, 0);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &food);
    }
    void Game_simulate2()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature food = Food(Direction::EAST, 0, 1);
        game.board.UpdateCreature(&hopper);
        game.board.UpdateCreature(&food);

        //Act
        game.simulate(1, 0);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &food);
    }
    void Game_simulate3()
    {
        //Arrange
        Game game(5, 5);
        Creature hopper = Hopper(Direction::EAST, 0, 0);
        Creature food = Food(Direction::EAST, 0, 1);
        game.board.UpdateCreature(&hopper);
        game.board.UpdateCreature(&food);

        //Act
        game.simulate(1, 0);

        //Assert
        CPPUNIT_ASSERT(game.board.board[0][1] == &food);
    }



	CPPUNIT_TEST_SUITE(TestDarwin);
    CPPUNIT_TEST(Location_GetNextLocation1);
    CPPUNIT_TEST(Location_GetNextLocation2);
    CPPUNIT_TEST(Location_GetNextLocation3);
    CPPUNIT_TEST(Direction_turnRight1);
    CPPUNIT_TEST(Direction_turnRight2);
    CPPUNIT_TEST(Direction_turnRight3);
    CPPUNIT_TEST(Direction_turnLeft1);
    CPPUNIT_TEST(Direction_turnLeft2);
    CPPUNIT_TEST(Direction_turnLeft3);
    CPPUNIT_TEST(Instruction_Instruction1);
    CPPUNIT_TEST(Instruction_Instruction2);
    CPPUNIT_TEST(Instruction_Instruction3);
    CPPUNIT_TEST(Program_AddInstruction1);
    CPPUNIT_TEST(Program_AddInstruction2);
    CPPUNIT_TEST(Program_AddInstruction3);
    CPPUNIT_TEST(Program_GetInstructionByLineNumber1);
    CPPUNIT_TEST(Program_GetInstructionByLineNumber2);
    CPPUNIT_TEST(Program_GetInstructionByLineNumber3);
    CPPUNIT_TEST(Board_Board1);
    CPPUNIT_TEST(Board_Board2);
    CPPUNIT_TEST(Board_Board3);
    CPPUNIT_TEST(Board_IsOccupied1);
    CPPUNIT_TEST(Board_IsOccupied2);
    CPPUNIT_TEST(Board_IsOccupied3);
    CPPUNIT_TEST(Board_IsWall1);
    CPPUNIT_TEST(Board_IsWall2);
    CPPUNIT_TEST(Board_IsWall3);
    CPPUNIT_TEST(Board_RemoveCreature1);
    CPPUNIT_TEST(Board_RemoveCreature2);
    CPPUNIT_TEST(Board_RemoveCreature3);
    CPPUNIT_TEST(Board_UpdateCreature1);
    CPPUNIT_TEST(Board_UpdateCreature2);
    CPPUNIT_TEST(Board_UpdateCreature3);
    CPPUNIT_TEST(Board_UpdateCreatures1);
    CPPUNIT_TEST(Board_UpdateCreatures2);
    CPPUNIT_TEST(Board_UpdateCreatures3);
    CPPUNIT_TEST(Board_GetCreature1);
    CPPUNIT_TEST(Board_GetCreature2);
    CPPUNIT_TEST(Board_GetCreature3);
    CPPUNIT_TEST(Board_EnemyAhead1);
    CPPUNIT_TEST(Board_EnemyAhead2);
    CPPUNIT_TEST(Board_EnemyAhead3);
    CPPUNIT_TEST(Game_Game1);
    CPPUNIT_TEST(Game_Game2);
    CPPUNIT_TEST(Game_Game3);
    CPPUNIT_TEST(Game_canHop1);
    CPPUNIT_TEST(Game_canHop2);
    CPPUNIT_TEST(Game_canHop3);
    CPPUNIT_TEST(Game_addCreature1);
    CPPUNIT_TEST(Game_addCreature2);
    CPPUNIT_TEST(Game_addCreature3);
    CPPUNIT_TEST(Game_runInstruction1);
    CPPUNIT_TEST(Game_runInstruction2);
    CPPUNIT_TEST(Game_runInstruction3);
    CPPUNIT_TEST(Game_executeProgram1);
    CPPUNIT_TEST(Game_executeProgram2);
    CPPUNIT_TEST(Game_executeProgram3);
    CPPUNIT_TEST(Game_move1);
    CPPUNIT_TEST(Game_move2);
    CPPUNIT_TEST(Game_move3);
    CPPUNIT_TEST(Game_simulate1);
    CPPUNIT_TEST(Game_simulate2);
    CPPUNIT_TEST(Game_simulate3);
	CPPUNIT_TEST_SUITE_END();
};

int main()
{
	using namespace std;
	cout << "TestDarwin.c++" << endl;

	CppUnit::TextTestRunner tr;
	tr.addTest(TestDarwin::suite());
	tr.run();

	cout << "Done." <<endl;
	return 0;
}
