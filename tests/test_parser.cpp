#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <format>
#include "Robot.h"
#include "parser.h"
#include "fixtures.h"

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

class TestParser : public TestingTable
{
protected:
    std::shared_ptr<Parser> p;
    std::shared_ptr<MockRobot> mockRobot;

    TestParser()
    {
        mockRobot = std::make_shared<MockRobot>();
        p = std::make_shared<Parser>();
    }
};

class TestCommand : public TestParser, public testing::Test
{
};

TEST_F(TestCommand, ValidPlace)
{
    EXPECT_CALL(*mockRobot, place(3, 3, eDirection::NORTH, table));
    p->parseCommand(table, mockRobot, "PLACE 3,3,NORTH");
}

using ::testing::_;
const auto commands = testing::Values("PLACE 3,3,NORTHEAST", "PLACE 3,3,NORTH,", "PLACE 3,,3,NORTH", "PLACE  3,,3,NORTH", "UNKNOWN", "MOVES");
class InvalidCommands : public TestParser, public testing::TestWithParam<std::string>
{
protected:
    InvalidCommands()
    {
        EXPECT_CALL(*mockRobot, place(_, _, _, _)).Times(0);
        EXPECT_CALL(*mockRobot, move()).Times(0);
        EXPECT_CALL(*mockRobot, left()).Times(0);
        EXPECT_CALL(*mockRobot, right()).Times(0);
        EXPECT_CALL(*mockRobot, report()).Times(0);
        EXPECT_CALL(*mockRobot, isPlaced()).Times(testing::Between(0, 1));
    }
};

INSTANTIATE_TEST_SUITE_P(TestCommandInvalid,
                         InvalidCommands,
                         commands);

TEST_P(InvalidCommands, commands)
{
    EXPECT_CALL(*mockRobot, place(_, _, _, _)).Times(0);
    p->parseCommand(table, mockRobot, GetParam());
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
    p->parseCommand(table, mockRobot, "MOVE");
}

TEST_P(TestIgnoreIfNotPlaced, Left)
{
    EXPECT_CALL(*mockRobot, left()).Times(num_expected_calls);
    p->parseCommand(table, mockRobot, "LEFT");
}

TEST_P(TestIgnoreIfNotPlaced, Right)
{
    EXPECT_CALL(*mockRobot, right()).Times(num_expected_calls);
    p->parseCommand(table, mockRobot, "RIGHT");
}

TEST_P(TestIgnoreIfNotPlaced, report)
{
    EXPECT_CALL(*mockRobot, report()).Times(num_expected_calls);
    p->parseCommand(table, mockRobot, "REPORT");
}
