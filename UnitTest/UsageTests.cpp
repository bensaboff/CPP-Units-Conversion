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
#include "AngleType.h"
#include "PowerType.h"
#include "TemperatureType.h"
#include <gtest/gtest.h>

const Units::Seconds MAX_TIME(1);

class Usage_Test : public testing::Test
{
public:
   Usage_Test() {}
   virtual ~Usage_Test() {}

protected:
   void SetUp() override { m_timer = MAX_TIME;  }
   void TearDown() override {}

   bool UpdateTimer(Units::Time FrameTime);
   Units::Speed GetUpdatedSpeed(Units::Time FrameTime, Units::Distance NewPosition);

   Units::Time m_timer;
};

bool Usage_Test::UpdateTimer(Units::Time FrameTime)
{
   //For rounding errors
   FrameTime += Units::Picoseconds(1);

   if (m_timer > Units::Time::zero())
      m_timer -= FrameTime;

   return (m_timer > Units::Time::zero());
}

Units::Speed Usage_Test::GetUpdatedSpeed(Units::Time FrameTime, Units::Distance NewPosition)
{
   static Units::Distance oldPosition(Units::Distance::zero());

   Units::Speed ret = ((NewPosition - oldPosition) / FrameTime);
   oldPosition = NewPosition;

   return ret;
}

TEST_F(Usage_Test, Verify_Timer)
{
   EXPECT_TRUE(UpdateTimer(Units::Time::zero()));
   EXPECT_TRUE(UpdateTimer(Units::Milliseconds(1)));
   EXPECT_TRUE(UpdateTimer(Units::Milliseconds(998)));
   EXPECT_FALSE(UpdateTimer(Units::Milliseconds(1)));
   EXPECT_FALSE(UpdateTimer(Units::Time::zero()));
}

TEST_F(Usage_Test, Update_Speed)
{
   Units::MetersPerSecond newSpeed;

   newSpeed = GetUpdatedSpeed(Units::Seconds(5), Units::Meters(10));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(2), newSpeed);

   newSpeed = GetUpdatedSpeed(Units::Hours(1), Units::Kilometers(10)+Units::Meters(10));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond((10.0*1000.0)/3600.0), newSpeed);
}

TEST_F(Usage_Test, Verify_Time)
{
   EXPECT_DOUBLE_EQ(Units::Seconds(Units::Days(30.4375)), Units::Seconds(Units::Months(1)));
   EXPECT_DOUBLE_EQ(Units::Seconds(Units::Days(365.25)), Units::Seconds(Units::Years(1)));
   EXPECT_DOUBLE_EQ(Units::Seconds(Units::Months(12)), Units::Seconds(Units::Years(1)));
}

TEST_F(Usage_Test, Verify_Distance)
{
   using namespace Units::Literals;

   EXPECT_DOUBLE_EQ(Units::KiloFeet(1), Units::KiloFeet(Units::Feet(1000)));
   EXPECT_DOUBLE_EQ(Units::Meters(149597870700), Units::Meters(Units::AstronomicalUnits(1)));
   EXPECT_NEAR(Units::Meters(1609.344), Units::Meters(Units::Feet(5280)), 0.00000000001);
   EXPECT_NEAR(Units::Miles(1), Units::Miles(Units::Feet(5280)), 0.000000001);
   EXPECT_NEAR(Units::Miles(1), Units::Miles(Units::Meters(1609.344)), 0.00000001);
   EXPECT_DOUBLE_EQ(Units::Meters(1852), Units::Meters(Units::NauticalMiles(1)));
   EXPECT_DOUBLE_EQ(Units::Inches(1.0), 1.0_in);
}

TEST_F(Usage_Test, Verify_Speed)
{
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1852.0 / 3600.0), Units::MetersPerSecond(Units::Knots(1)));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::KilometersPerHour(3.6)));
   EXPECT_DOUBLE_EQ(Units::FeetPerMinute(1), Units::FeetPerMinute(Units::Feet(10) / Units::Minutes(10)));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::MilesPerHour(2.236936292054402))); // Decimal determined by external calculation
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(3600), Units::MetersPerSecond(Units::MetersPerHour(1)));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(340.3), Units::MetersPerSecond(Units::Mach(1))); // This needs a better answer
}

TEST_F(Usage_Test, Verify_Angle)
{
    using namespace Units::Literals;

   EXPECT_DOUBLE_EQ(Units::Degrees(360.0), Units::Degrees(Units::Radians(2.0*3.1415926535897932384626433832795028841971)));
   EXPECT_DOUBLE_EQ(Units::Milliradians(6400.0), Units::Milliradians(Units::Radians(2.0 * 3.1415926535897932384626433832795028841971)));
   EXPECT_DOUBLE_EQ(Units::Degrees(360.0), Units::Degrees(6400_mil));
   EXPECT_DOUBLE_EQ(Units::Degrees( 90.0), Units::Degrees(( 0.5_bams).LimitAnglePositive()));
   EXPECT_DOUBLE_EQ(Units::Degrees(270.0), Units::Degrees((-0.5_bams).LimitAnglePositive()));
}

TEST_F(Usage_Test, Verify_Power)
{
    using namespace Units::Literals;

   EXPECT_DOUBLE_EQ(Units::GigaWatts(1.0), Units::GigaWatts(120_dBm));
   EXPECT_DOUBLE_EQ(100_kW, Units::KiloWatts(80_dBm));
   EXPECT_DOUBLE_EQ(10_W, Units::Watts(10_dBW));
   EXPECT_DOUBLE_EQ(Units::Watts(1_MW), Units::Watts(60_dBW));
}

TEST_F(Usage_Test, Verify_Temperature)
{
    using namespace Units::Literals;

    EXPECT_DOUBLE_EQ(Units::Celsius(1.0), 1.0_degC);
    EXPECT_DOUBLE_EQ(Units::Farenheit(1.0), 1.0_degF);
    EXPECT_DOUBLE_EQ(Units::Kelvin(1.0), 1.0_degK);
    EXPECT_DOUBLE_EQ(Units::Rankine(1.0), 1.0_degR);
    EXPECT_DOUBLE_EQ(0.0_degC, Units::Celsius(32.0_degF));
    EXPECT_DOUBLE_EQ(0.0_degC, Units::Celsius(273.15_degK));
    EXPECT_DOUBLE_EQ(0.0_degC, Units::Celsius(491.67_degR));
    EXPECT_DOUBLE_EQ(212.0_degF, Units::Farenheit(100.0_degC));
    EXPECT_DOUBLE_EQ(273.15_degK, Units::Kelvin(0_degC)); // test integer conversion
    EXPECT_DOUBLE_EQ(491.67_degR, Units::Rankine(0.0_degC));
    //EXPECT_DOUBLE_EQ(Units::Celsius(-40.0_degC), Units::Celsius(-40.0_degF));
    EXPECT_DOUBLE_EQ(Units::Celsius(-40.0_degC), Units::Celsius(Units::Farenheit(-40.0)));
    EXPECT_DOUBLE_EQ(100.0_degC, Units::Celsius(212.0_degF));
}

