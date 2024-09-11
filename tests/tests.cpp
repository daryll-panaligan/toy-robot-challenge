#pragma once

#include <gtest/gtest.h>
#include "robot.h"

TEST(TestRobot, Place)
{
	Robot raven;
	raven.place(1, 1, eDirection::SOUTH);
	EXPECT_EQ(raven.report(), "1,1,SOUTH");
}

TEST(TestRobot, MoveLeft)
{
	Robot raven;
	raven.place(1, 1, eDirection::SOUTH);
	raven.left();
	EXPECT_EQ(raven.report(), "1,1,EAST");
	raven.left();
	EXPECT_EQ(raven.report(), "1,1,NORTH");
	raven.left();
	EXPECT_EQ(raven.report(), "1,1,WEST");
	raven.left();
	EXPECT_EQ(raven.report(), "1,1,SOUTH");
}

TEST(TestRobot, MoveRight)
{
	Robot raven;
	raven.place(1, 1, eDirection::SOUTH);
	raven.right();
	EXPECT_EQ(raven.report(), "1,1,WEST");
	raven.right();
	EXPECT_EQ(raven.report(), "1,1,NORTH");
	raven.right();
	EXPECT_EQ(raven.report(), "1,1,EAST");
	raven.right();
	EXPECT_EQ(raven.report(), "1,1,SOUTH");
}
