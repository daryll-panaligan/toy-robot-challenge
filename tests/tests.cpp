#pragma once

#include <gtest/gtest.h>
#include "robot.h"
#include <format>

TEST(TestRobot, Place)
{
	Robot r;
	r.place(1, 1, eDirection::SOUTH);
	EXPECT_EQ(r.report(), "1,1,SOUTH");
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

std::string toReport(int x, int y, eDirection dir)
{
	return std::format("{},{},{}", x, y, dirToString(dir));
}

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
