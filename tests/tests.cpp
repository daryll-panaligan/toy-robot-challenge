#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "robot.h"
#include "table.h"
#include "parser.h"
#include <format>

std::string toReport(int x, int y, eDirection dir)
{
	return std::format("{},{},{}", x, y, dirToString(dir));
}

const int TABLE_HEIGHT = 5;
const int TABLE_WIDTH = 5;

class TestRobot
{
protected:
	TestRobot()
	{
		robot = std::make_shared<Robot>();
	}
	std::shared_ptr<Robot> robot;
};

class TestTable
{
protected:
	TestTable()
	{
		table = std::make_shared<Table>(TABLE_HEIGHT, TABLE_WIDTH);
	}
	std::shared_ptr<Table> table;
};

class TestRobotPlace : public TestRobot, public TestTable, public testing::Test
{
};

TEST_F(TestRobotPlace, Place)
{
	int x_0 = table->getWidth() / 2;
	int y_0 = table->getHeight() / 2;
	robot->place(x_0, y_0, eDirection::SOUTH, table);
	EXPECT_EQ(robot->report(), toReport(x_0, y_0, eDirection::SOUTH));
}

TEST_F(TestRobotPlace, PlaceOutside)
{
	int x_0 = table->getWidth() + 1;
	int y_0 = table->getHeight() + 1;
	eDirection dir = eDirection::SOUTH;
	robot->place(x_0, y_0, dir, table);
	EXPECT_EQ(robot->isPlaced(), false);
}

const auto directions = testing::Values(eDirection::SOUTH, eDirection::NORTH, eDirection::WEST, eDirection::EAST);

class TestRobotMove : public TestRobot, public TestTable, public testing::TestWithParam<eDirection>
{
protected:
	TestRobotMove()
	{
		x = table->getHeight() / 2;
		y = table->getWidth() / 2;
		robot->place(x, y, GetParam(), table);
	}

	int x;
	int y;
};

std::string const toString(testing::TestParamInfo<TestRobotMove::ParamType> info)
{
	return dirToString(info.param);
}

INSTANTIATE_TEST_SUITE_P(TestDirections,
						 TestRobotMove,
						 directions, toString);

TEST_P(TestRobotMove, Move)
{
	robot->move();
	eDirection dir = GetParam();
	switch (dir)
	{
	case eDirection::SOUTH:
		EXPECT_EQ(robot->report(), toReport(x, y - 1, dir));
		break;
	case eDirection::NORTH:
		EXPECT_EQ(robot->report(), toReport(x, y + 1, dir));
		break;
	case eDirection::WEST:
		EXPECT_EQ(robot->report(), toReport(x - 1, y, dir));
		break;
	case eDirection::EAST:
		EXPECT_EQ(robot->report(), toReport(x + 1, y, dir));
		break;
	}
}

class TestRobotMoveInvalid : public TestRobot, public TestTable, public testing::TestWithParam<eDirection>
{
};

INSTANTIATE_TEST_SUITE_P(TestDirections,
						 TestRobotMoveInvalid,
						 directions, toString);

TEST_P(TestRobotMoveInvalid, Move)
{
	int x;
	int y;
	eDirection dir = GetParam();

	switch (dir)
	{
	case eDirection::SOUTH:
	case eDirection::WEST:
		// place robot at SW corner of table
		x = 0;
		y = 0;
		break;
	case eDirection::NORTH:
	case eDirection::EAST:
		// place robot at NE corner of table
		x = table->getWidth() - 1;
		y = table->getHeight() - 1;
		break;
	}
	robot->place(x, y, GetParam(), table);
	robot->move();

	// nothing should change
	EXPECT_EQ(robot->report(), toReport(x, y, dir));
}

class TestRobotTurn : public TestRobot, public TestTable, public testing::Test
{
protected:
	TestRobotTurn()
	{
		robot->place(x, y, eDirection::SOUTH, table);
	}

	int x = 1;
	int y = 1;
};

TEST_F(TestRobotTurn, Left)
{
	robot->left();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::EAST));
	robot->left();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::NORTH));
	robot->left();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::WEST));
	robot->left();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::SOUTH));
}

TEST_F(TestRobotTurn, Right)
{
	robot->right();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::WEST));
	robot->right();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::NORTH));
	robot->right();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::EAST));
	robot->right();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::SOUTH));
}

TEST_F(TestRobotTurn, RightLeft)
{
	robot->right();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::WEST));
	robot->left();
	EXPECT_EQ(robot->report(), toReport(x, y, eDirection::SOUTH));
}

class MockRobot : public IRobot
{
public:
	MOCK_METHOD(void, place, (int, int, eDirection, std::shared_ptr<Table> const &));
	MOCK_METHOD(std::string, report, (), (const));
	MOCK_METHOD(bool, isPlaced, (), (const));
	MOCK_METHOD(void, move, ());
	MOCK_METHOD(void, left, ());
	MOCK_METHOD(void, right, ());
};

class TestParser : public TestTable
{
protected:
	Parser p;
	std::shared_ptr<MockRobot> mockRobot;

	TestParser()
	{
		mockRobot = std::make_shared<MockRobot>();
	}
};

class TestCommands : public TestParser, public testing::Test
{
};

TEST_F(TestCommands, ValidPlace)
{
	EXPECT_CALL(*mockRobot, place(3, 3, eDirection::NORTH, table));
	p.parseCommand(table, mockRobot, "PLACE 3,3,NORTH");
}

TEST_F(TestCommands, ValidPlace)
{
	EXPECT_CALL(*mockRobot, place(3, 3, eDirection::NORTH, table));
	p.parseCommand(table, mockRobot, "PLACE 3,3,NORTH");
}

class TestIgnoreIfNotPlaced : public TestParser, public testing::TestWithParam<bool>
{
protected:
	TestIgnoreIfNotPlaced()
	{
		EXPECT_CALL(*mockRobot, isPlaced()).Times(1);
		ON_CALL(*mockRobot, isPlaced)
			.WillByDefault(testing::Return(GetParam()));
		num_expected_calls = (GetParam()) ? 1 : 0;
	}

	int num_expected_calls;
};

INSTANTIATE_TEST_SUITE_P(TestIgnoredCommands,
						 TestIgnoreIfNotPlaced,
						 testing::Values(false, true));

TEST_P(TestIgnoreIfNotPlaced, Move)
{
	EXPECT_CALL(*mockRobot, move()).Times(num_expected_calls);
	p.parseCommand(table, mockRobot, "MOVE");
}

TEST_P(TestIgnoreIfNotPlaced, Left)
{
	EXPECT_CALL(*mockRobot, left()).Times(num_expected_calls);
	p.parseCommand(table, mockRobot, "LEFT");
}

TEST_P(TestIgnoreIfNotPlaced, Right)
{
	EXPECT_CALL(*mockRobot, right()).Times(num_expected_calls);
	p.parseCommand(table, mockRobot, "RIGHT");
}

TEST_P(TestIgnoreIfNotPlaced, report)
{
	EXPECT_CALL(*mockRobot, report()).Times(num_expected_calls);
	p.parseCommand(table, mockRobot, "REPORT");
}
