#pragma once

#include <gtest/gtest.h>
#include "robot.h"
#include "table.h"
#include <format>

std::string toReport(int x, int y, eDirection dir)
{
	return std::format("{},{},{}", x, y, dirToString(dir));
}

class TestRobot
{
protected:
	TestRobot() : table(5, 5), xLimit(5), yLimit(5) {};
	Robot robot;
	Table table;

	const int xLimit;
	const int yLimit;
};

class TestRobotPlace : public TestRobot, public testing::Test
{
};

TEST_F(TestRobotPlace, Place)
{
	int x_0 = xLimit - 1;
	int y_0 = yLimit - 1;
	robot.place(x_0, y_0, eDirection::SOUTH, std::make_shared<Table>(table));
	EXPECT_EQ(robot.report(), toReport(x_0, y_0, eDirection::SOUTH));
}

TEST_F(TestRobotPlace, PlaceOutside)
{
	int x_0 = xLimit + 1;
	int y_0 = yLimit + 1;
	eDirection dir = eDirection::SOUTH;
	robot.place(x_0, y_0, dir, std::make_shared<Table>(table));
	EXPECT_EQ(robot.report(), "-1,-1,INVALID");
}

class TestRobotMove : public TestRobot,
					  public testing::TestWithParam<eDirection>
{
protected:
	TestRobotMove()
	{

		robot.place(x, y, GetParam(), std::make_shared<Table>(table));
	}

	int x = 3;
	int y = 3;
};

INSTANTIATE_TEST_SUITE_P(TestDirections,
						 TestRobotMove,
						 testing::Values(eDirection::SOUTH, eDirection::NORTH, eDirection::WEST, eDirection::EAST), [](const testing::TestParamInfo<TestRobotMove::ParamType> &info)
						 { return dirToString(info.param); });

TEST_P(TestRobotMove, Move)
{
	robot.move();
	eDirection dir = GetParam();
	switch (dir)
	{
	case eDirection::SOUTH:
		EXPECT_EQ(robot.report(), toReport(x, y - 1, dir));
		break;
	case eDirection::NORTH:
		EXPECT_EQ(robot.report(), toReport(x, y + 1, dir));
		break;
	case eDirection::WEST:
		EXPECT_EQ(robot.report(), toReport(x - 1, y, dir));
		break;
	case eDirection::EAST:
		EXPECT_EQ(robot.report(), toReport(x + 1, y, dir));
		break;
	default:
		// should fail. eg. when a new direction is added (northeast, northwest, etc.)
		EXPECT_TRUE(false);
	}
}
class TestRobotTurn : public TestRobot, public testing::Test
{
protected:
	TestRobotTurn()
	{
		robot.place(x, y, eDirection::SOUTH, std::make_shared<Table>(table));
	}

	int x = 1;
	int y = 1;
};

TEST_F(TestRobotTurn, Left)
{
	robot.left();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::EAST));
	robot.left();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::NORTH));
	robot.left();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::WEST));
	robot.left();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::SOUTH));
}

TEST_F(TestRobotTurn, Right)
{
	robot.right();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::WEST));
	robot.right();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::NORTH));
	robot.right();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::EAST));
	robot.right();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::SOUTH));
}

TEST_F(TestRobotTurn, RightLeft)
{
	robot.right();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::WEST));
	robot.left();
	EXPECT_EQ(robot.report(), toReport(x, y, eDirection::SOUTH));
}
