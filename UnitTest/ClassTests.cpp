/*
Copyright 2022 Ben Saboff

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissionsand
limitations under the License.
*/

#include "TimeType.h"
#include "LengthType.h"
#include "SpeedType.h"
#include <gtest/gtest.h>

class Time_Test : public testing::Test
{
public:
   Time_Test() {}
   virtual ~Time_Test() {}

protected:
   void SetUp() override {}
   void TearDown() override {}

};

TEST_F(Time_Test, Verify_Zero_Time)
{
   EXPECT_DOUBLE_EQ(Units::Seconds(Units::Time::zero()), 0.0);
}

TEST_F(Time_Test, Hours_Compared_To_Minutes)
{
   Units::Hours test_hours = 1.0;
   Units::Minutes test_minutes = (60.0);

   // Multiplying a unit by a double will result in the double being treated as the unit
   // Since both values are being converted to double, we are equating 60 hours to 60 minutes.
   EXPECT_DOUBLE_EQ(test_hours * 60.0, test_minutes);

   // In order to compare different units, first convert to make them both the same
   EXPECT_DOUBLE_EQ(Units::Minutes(test_hours), test_minutes);
}
TEST_F(Time_Test, Assignment_Operator)
{
   Units::Hours test_hours(1.0);
   Units::Minutes test_minutes = test_hours;

   EXPECT_DOUBLE_EQ(60.0, test_minutes);
}

TEST_F(Time_Test, Copy_Constructor)
{
   Units::Hours test_hours(1.0);

   EXPECT_DOUBLE_EQ(60.0, Units::Minutes(test_hours));
}

TEST_F(Time_Test, Move_Constructor)
{
   Units::Hours test_hours(1.0);
   Units::Minutes test_minute = std::move(test_hours);

   EXPECT_DOUBLE_EQ(60.0, test_minute);
}

TEST_F(Time_Test, Add_Same)
{
   Units::Hours test_hours_1(1.0);
   Units::Hours test_hours_2(2.0);
   Units::Hours value = test_hours_1 + test_hours_2;

   EXPECT_DOUBLE_EQ(Units::Hours(3.0), value);
}

TEST_F(Time_Test, Subtract_Same)
{
   Units::Hours test_hours_1(1.0);
   Units::Hours test_hours_2(2.0);
   Units::Hours value = Units::Hours(test_hours_2 - test_hours_1);

   EXPECT_DOUBLE_EQ(Units::Hours(1.0), value);
}

TEST_F(Time_Test, Subtract_Same_Negative_Output)
{
   Units::Hours test_hours_1(1.0);
   Units::Hours test_hours_2(2.0);
   Units::Hours value = Units::Hours(test_hours_1 - test_hours_2);

   EXPECT_DOUBLE_EQ(Units::Hours(-1.0), value);
}

TEST_F(Time_Test, Add_Different_Convert_Store_Different)
{
   Units::Hours test_hours(1.0);
   Units::Seconds test_seconds(2000.0);
   Units::Milliseconds value = Units::Hours(test_hours + test_seconds);

   EXPECT_DOUBLE_EQ(Units::Milliseconds(5600000.0), value);
}

TEST_F(Time_Test, Subtract_Different)
{
   Units::Hours test_hours(1.0);
   Units::Seconds test_seconds(3000.0);
   Units::Seconds value = test_hours - test_seconds;

   EXPECT_DOUBLE_EQ(Units::Seconds(600.0), value);
}

TEST_F(Time_Test, Subtract_Different_Negative_Output)
{
   Units::Hours test_hours(1.0);
   Units::Seconds test_seconds(4000.0);
   Units::Seconds value = test_hours - test_seconds;

   EXPECT_DOUBLE_EQ(Units::Seconds(-400.0), value);
}

TEST_F(Time_Test, Distance_From_Time_by_Speed)
{
   Units::MetersPerSecond test_speed(2.0);
   Units::Seconds test_time(4.0);
   Units::Meters value = test_time * test_speed;

   EXPECT_DOUBLE_EQ(Units::Meters(8.0), value);
}

TEST_F(Time_Test, Distance_From_Speed_by_Time)
{
   Units::MetersPerSecond test_speed(8.0);
   Units::Seconds test_time(4.0);
   Units::Meters value = test_speed * test_time;

   EXPECT_DOUBLE_EQ(Units::Meters(32.0), value);
}

TEST_F(Time_Test, Speed_From_Distance_over_Time)
{
   Units::Seconds test_time(2.0);
   Units::Meters test_distance(6);
   Units::MetersPerSecond value = test_distance / test_time;

   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(3.0), value);
}
