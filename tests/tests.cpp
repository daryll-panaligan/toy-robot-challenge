#pragma once

#include <gtest/gtest.h>
#include "robot.h"

TEST(TestRobot, Place)
{
	Robot raven;
	raven.place(1, 1, eDirection::SOUTH);
	EXPECT_EQ(raven.report(), "1,1,SOUTH");
}
