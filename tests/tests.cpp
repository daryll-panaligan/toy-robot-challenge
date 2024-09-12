#pragma once

#include <gtest/gtest.h>
#include "robot.h"
#include <format>

std::string toReport(int x, int y, eDirection dir)
{
	return std::format("{},{},{}", x, y, dirToString(dir));
}

TEST(TestRobot, Place)
{
	Robot r;
	r.place(1, 1, eDirection::SOUTH);
	EXPECT_EQ(r.report(), "1,1,SOUTH");
}

class TestRobotMove : public testing::TestWithParam<eDirection>
{
protected:
	TestRobotMove()
	{
		r.place(x, y, GetParam());
	}

	Robot r;

	const int x = 3;
	const int y = 3;
};

INSTANTIATE_TEST_SUITE_P(TestDirections,
						 TestRobotMove,
						 testing::Values(eDirection::SOUTH, eDirection::NORTH, eDirection::WEST, eDirection::EAST), [](const testing::TestParamInfo<TestRobotMove::ParamType> &info)
						 { return dirToString(info.param); });

TEST_P(TestRobotMove, Move)
{
	r.move();
	eDirection dir = GetParam();
	switch (dir)
	{
	case eDirection::SOUTH:
		EXPECT_EQ(r.report(), toReport(x, y - 1, dir));
		break;
	case eDirection::NORTH:
		EXPECT_EQ(r.report(), toReport(x, y + 1, dir));
		break;
	case eDirection::WEST:
		EXPECT_EQ(r.report(), toReport(x - 1, y, dir));
		break;
	case eDirection::EAST:
		EXPECT_EQ(r.report(), toReport(x + 1, y, dir));
		break;
	default:
		// should fail. eg. when a new direction is added (northeast, northwest, etc.)
		EXPECT_TRUE(false);
	}
}

class TestRobotTurn : public testing::Test
{
protected:
	TestRobotTurn()
	{
		r.place(x, y, eDirection::SOUTH);
	}

	Robot r;

	const int x = 1;
	const int y = 1;
};

TEST_F(TestRobotTurn, Left)
{
	r.left();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::EAST));
	r.left();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::NORTH));
	r.left();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::WEST));
	r.left();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::SOUTH));
}

TEST_F(TestRobotTurn, Right)
{
	r.right();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::WEST));
	r.right();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::NORTH));
	r.right();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::EAST));
	r.right();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::SOUTH));
}

TEST_F(TestRobotTurn, RightLeft)
{
	r.right();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::WEST));
	r.left();
	EXPECT_EQ(r.report(), toReport(x, y, eDirection::SOUTH));
}
