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

#include "AccelerationType.h"
#include "AngleType.h"
#include "AngularAccelerationType.h"
#include "AngularSpeedType.h"
#include "AreaType.h"
#include "ForceType.h"
#include "LengthType.h"
#include "MassType.h"
#include "PowerType.h"
#include "PressureType.h"
#include "SpeedType.h"
#include "TemperatureType.h"
#include "TimeType.h"
#include "VolumeType.h"

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

   EXPECT_NEAR(Units::Seconds(10000000), Units::Seconds(Units::LeapYears(0.3162315321)), 0.01);
   EXPECT_NEAR(Units::Seconds(10000000), Units::Seconds(Units::NonLeapYears(0.3170979198)), 0.01);
   EXPECT_NEAR(Units::Seconds(10000000), Units::Seconds(Units::Years(0.3168808781402895)), 0.01);
   //EXPECT_NEAR(Units::Seconds(100), Units::Seconds(Units::NonLeapYearMonths(1)), 0.000001);
   //EXPECT_NEAR(Units::Seconds(100), Units::Seconds(Units::Months(1)), 0.000001);
   EXPECT_NEAR(Units::Seconds(100000), Units::Seconds(Units::Weeks(0.16534392)), 0.01);
   EXPECT_NEAR(Units::Seconds(10000), Units::Seconds(Units::Days(0.1157407)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Hours(0.000277778)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Minutes(0.0166667)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Seconds(1)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Milliseconds(1000)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Microseconds(1000000)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Nanoseconds(1000000000)), 0.01);
   EXPECT_NEAR(Units::Seconds(1), Units::Seconds(Units::Picoseconds(1000000000000)), 0.01);
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

   //EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::FlightLevel(0.3162315321)), 0.01); // CAN'T FIND INFO
   EXPECT_NEAR(Units::Meters(100000000000), Units::Meters(Units::AstronomicalUnits(0.66845871222684)), 0.01);
   EXPECT_NEAR(Units::Meters(1000), Units::Meters(Units::DataMiles(0.546808)), 0.01);
   EXPECT_NEAR(Units::Meters(1000), Units::Meters(Units::NauticalMiles(0.539957)), 0.01);
   EXPECT_NEAR(Units::Meters(1000), Units::Meters(Units::Miles(0.621371)), 0.01);
   EXPECT_NEAR(Units::Meters(1000), Units::Meters(Units::Leagues(0.2071237307)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Fathoms(0.546807)), 0.01);
   EXPECT_NEAR(Units::Meters(100), Units::Meters(Units::Furlong(0.497096)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Yards(1.09361)), 0.01);
   EXPECT_NEAR(Units::Meters(100), Units::Meters(Units::KiloFeet(0.32808399)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Feet(3.28084)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::US_Survey_Feet(3.2808333333)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Inches(39.3701)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Gigameters(0.000000001)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Megameters(0.000001)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Kilometers(0.001)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Hectometers(0.01)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Decameters(0.1)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Meters(1)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Decimeters(10)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Centimeters(100)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Millimeters(1000)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Micrometers(1000000)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Nanometers(1000000000)), 0.01);
   EXPECT_NEAR(Units::Meters(1), Units::Meters(Units::Picometers(1000000000000)), 0.01);
}

TEST_F(Usage_Test, Verify_Speed)
{
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1852.0 / 3600.0), Units::MetersPerSecond(Units::Knots(1)));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::KilometersPerHour(3.6)));
   EXPECT_DOUBLE_EQ(Units::FeetPerMinute(1), Units::FeetPerMinute(Units::Feet(10) / Units::Minutes(10)));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::MilesPerHour(2.236936292054402))); // Decimal determined by external calculation
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::MetersPerHour(3600)));
   EXPECT_DOUBLE_EQ(Units::MetersPerSecond(340.3), Units::MetersPerSecond(Units::Mach(1))); // This needs a better answer

   EXPECT_NEAR(Units::MetersPerSecond(100), Units::MetersPerSecond(Units::Mach(0.293867)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::Knots(1.94384)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::MetersPerHour(3600)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::FeetPerMinute(196.85)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::FeetPerSecond(3.28084)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::MilesPerHour(2.23694)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::KilometersPerHour(3.6)), 0.01);
   EXPECT_NEAR(Units::MetersPerSecond(1), Units::MetersPerSecond(Units::MetersPerSecond(1)), 0.01);
   //EXPECT_NEAR(Units::MetersPerSecond(1000), Units::MetersPerSecond(Units::WarpFactor(0.546808)), 0.01); unclear

}

TEST_F(Usage_Test, Verify_Angle)
{
    using namespace Units::Literals;

   EXPECT_DOUBLE_EQ(Units::Degrees(360.0), Units::Degrees(Units::Radians(2.0*3.1415926535897932384626433832795028841971)));
   EXPECT_DOUBLE_EQ(Units::Milliradians(6400.0), Units::Milliradians(Units::Radians(2.0 * 3.1415926535897932384626433832795028841971)));
   EXPECT_DOUBLE_EQ(Units::Degrees(360.0), Units::Degrees(6400_mil));
   EXPECT_DOUBLE_EQ(Units::Degrees( 90.0), Units::Degrees(( 0.5_bams).LimitAnglePositive()));
   EXPECT_DOUBLE_EQ(Units::Degrees(270.0), Units::Degrees((-0.5_bams).LimitAnglePositive()));

   EXPECT_NEAR(Units::Degrees(1), Units::Degrees(Units::Degrees(1)), 0.01);
   EXPECT_NEAR(Units::Degrees(10), Units::Degrees(Units::Radians(0.174533)), 0.01);
   //EXPECT_NEAR(Units::Degrees(1), Units::Degrees(Units::Milliradians(17.453293)), 0.01); See comment on Milliradians, apparent outdated standard, address
   //EXPECT_NEAR(Units::Degrees(100), Units::Degrees(Units::BAMS(0.293867)), 0.01); // Need further research
   EXPECT_NEAR(Units::Degrees(100), Units::Degrees(Units::Revolution(0.277778)), 0.01);
   EXPECT_NEAR(Units::Degrees(1), Units::Degrees(Units::ArcMinute(60)), 0.01);
   EXPECT_NEAR(Units::Degrees(1), Units::Degrees(Units::ArcSecond(3600)), 0.01);
}

TEST_F(Usage_Test, Verify_Power)
{
    using namespace Units::Literals;

   EXPECT_DOUBLE_EQ(Units::GigaWatts(1.0), Units::GigaWatts(120_dBm));
   EXPECT_DOUBLE_EQ(100_kW, Units::KiloWatts(80_dBm));
   EXPECT_DOUBLE_EQ(10_W, Units::Watts(10_dBW));
   EXPECT_DOUBLE_EQ(Units::Watts(1_MW), Units::Watts(60_dBW));

   EXPECT_NEAR(Units::Watts(100), Units::Watts(Units::HorsePower(0.134102)), 0.01);
   EXPECT_NEAR(Units::Watts(1.5), Units::Watts(Units::decibelWatts(1.761)), 0.01);
   EXPECT_NEAR(Units::Watts(1.5), Units::Watts(Units::decibelMilliwatts(31.7609125906)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::GigaWatts(0.000000001)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::MegaWatts(0.000001)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::KiloWatts(0.001)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::HectoWatts(0.01)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::DecaWatts(0.1)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::Watts(1)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::DeciWatts(10)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::CentiWatts(100)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::MilliWatts(1000)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::MicroWatts(1000000)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::NanoWatts(1000000000)), 0.01);
   EXPECT_NEAR(Units::Watts(1), Units::Watts(Units::PicoWatts(1000000000000)), 0.01);

   // Verify undefined behavior for dBW and dBm
   Units::Power myPow = Units::Watts(0);

   double converted_dBW = Units::decibelWatts(myPow); // This is undefined behavior, and currently returns -inf
   double converted_dBm = Units::decibelWatts(myPow); // This is undefined behavior, and currently returns -inf
   // What should be tested here? What's the appropriate behavior?

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

    EXPECT_NEAR(Units::Celsius(20), Units::Celsius(Units::Celsius(20)), 0.01);
    EXPECT_NEAR(Units::Celsius(20), Units::Celsius(Units::Kelvin(293.15)), 0.01);
    EXPECT_NEAR(Units::Celsius(20), Units::Celsius(Units::Farenheit(68)), 0.01);
    EXPECT_NEAR(Units::Celsius(20), Units::Celsius(Units::Rankine(527.67)), 0.01);
}

TEST_F(Usage_Test, Verify_Acceleration)
{
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::StandardGravity(10.19716213)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::MetersPerHourSquared(1296000000.0)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::FeetPerMinuteSquared(1181102.36)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::FeetPerSecondSquared(328.08399)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::MilesPerHourSquared(805297.065)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::KilometersPerHourSquared(1296000.0)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::InchesPerSecondSquared(3937.00787)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::Galileo(10000.0)), 0.01);
   ASSERT_NEAR(Units::MetersPerSecondSquared(100), Units::MetersPerSecondSquared(Units::MetersPerSecondSquared(100.0)), 0.01);
}

TEST_F(Usage_Test, Verify_AngularAcceleration)
{
   ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::DegreesPerSecondSquared(1)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::DegreesPerMinuteSquared(3600.0)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::DegreesPerHourSquared(12960000.0)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecondSquared(10), Units::DegreesPerSecondSquared(Units::RadiansPerSecondSquared(0.1745329252)), 0.01);
   //ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::MilliradiansPerSecondSquared(17.45329252)), 0.01); // See comment about milliradian standard
   //ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::BAMS_PerSecondSquared(10.19716213)), 0.01); // Need more research
   ASSERT_NEAR(Units::DegreesPerSecondSquared(100), Units::DegreesPerSecondSquared(Units::RevolutionPerSecondSquared(0.277777777778)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::RevolutionPerMinuteSquared(10)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecondSquared(1), Units::DegreesPerSecondSquared(Units::RevolutionPerHourSquared(36000)), 0.01);
}

TEST_F(Usage_Test, Verify_AngularSpeed)
{
   ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::DegreesPerSecond(1)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::DegreesPerMinute(60)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::DegreesPerHour(3600)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecond(10), Units::DegreesPerSecond(Units::RadiansPerSecond(0.174533)), 0.01);
   //ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::MilliradiansPerSecond(1)), 0.01); // See comment about milliradian standard
   //ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::BAMS_PerSecond(1)), 0.01); // Need more research
   ASSERT_NEAR(Units::DegreesPerSecond(100), Units::DegreesPerSecond(Units::RevolutionPerSecond(0.277778)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::RevolutionPerMinute(0.166667)), 0.01);
   ASSERT_NEAR(Units::DegreesPerSecond(1), Units::DegreesPerSecond(Units::RevolutionPerHour(10)), 0.01);
}

TEST_F(Usage_Test, Verify_Area)
{
   ASSERT_NEAR(Units::SquareMeters(1), Units::SquareMeters(Units::Hectare(0.0001)), 0.01);
   ASSERT_NEAR(Units::SquareMeters(1), Units::SquareMeters(Units::SquareFeet(10.7639)), 0.01);
   ASSERT_NEAR(Units::SquareMeters(1), Units::SquareMeters(Units::SquareInches(1550)), 0.01);
   ASSERT_NEAR(Units::SquareMeters(1), Units::SquareMeters(Units::SquareMeters(1)), 0.01);
}

TEST_F(Usage_Test, Verify_Force)
{
   ASSERT_NEAR(Units::Newton(1), Units::Newton(Units::Newton(1)), 0.01);
   ASSERT_NEAR(Units::Newton(1), Units::Newton(Units::Dyne(100000)), 0.01);
   ASSERT_NEAR(Units::Newton(1), Units::Newton(Units::KilogramsForce(0.101972)), 0.01);
   ASSERT_NEAR(Units::Newton(1), Units::Newton(Units::PoundsForce(0.224809)), 0.01);
}

TEST_F(Usage_Test, Verify_Mass)
{
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Grain(15.4324)), 0.01);
   ASSERT_NEAR(Units::Grams(100), Units::Grams(Units::Pound(0.220462)), 0.01);
   ASSERT_NEAR(Units::Grams(10), Units::Grams(Units::Ounce(0.35274)), 0.01);
   ASSERT_NEAR(Units::Grams(1000), Units::Grams(Units::Stone(0.157473)), 0.01);
   ASSERT_NEAR(Units::Grams(100000), Units::Grams(Units::ShortTon(0.11023113)), 0.01);
   ASSERT_NEAR(Units::Grams(100000), Units::Grams(Units::LongTon(0.098420653)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Tonne(0.000001)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Gigagrams(0.000000001)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Megagrams(0.000001)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Kilograms(0.001)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Hectograms(0.01)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Decagrams(0.1)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Grams(1)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Decigrams(10)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Centigrams(100)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Milligrams(1000)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Micrograms(1000000)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Nanograms(1000000000)), 0.01);
   ASSERT_NEAR(Units::Grams(1), Units::Grams(Units::Picograms(1000000000000)), 0.01);
}

TEST_F(Usage_Test, Verify_Pressure)
{
   ASSERT_NEAR(Units::Pascals(100000), Units::Pascals(Units::Atmospheres(0.98692327)), 0.01);
   ASSERT_NEAR(Units::Pascals(10000), Units::Pascals(Units::TechnicalAtmospheres(0.1019716213)), 0.01);
   ASSERT_NEAR(Units::Pascals(100), Units::Pascals(Units::Bars(0.001)), 0.01);
   ASSERT_NEAR(Units::Pascals(100), Units::Pascals(Units::PoundsPerSquareInch(0.0145038)), 0.01);
   ASSERT_NEAR(Units::Pascals(100), Units::Pascals(Units::Torr(0.750062)), 0.01);
   ASSERT_NEAR(Units::Pascals(100), Units::Pascals(Units::MillimetersMercury(0.750062)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::GigaPascals(0.000000001)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::MegaPascals(0.000001)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::KiloPascals(0.001)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::HectoPascals(0.01)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::DecaPascals(0.1)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::Pascals(1)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::DeciPascals(10)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::CentiPascals(100)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::MilliPascals(1000)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::MicroPascals(1000000)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::NanoPascals(1000000000)), 0.01);
   ASSERT_NEAR(Units::Pascals(1), Units::Pascals(Units::PicoPascals(1000000000000)), 0.01);
}

TEST_F(Usage_Test, Verify_Volume)
{
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Gallons(0.264172)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::ImperialGallons(0.219969)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Quart(1.05669)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Pint(2.11338)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::FluidOunces(33.814)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Fifth(1.3208602562078)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::CubicMeters(0.001)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::CubicCentimeters(1000)), 0.01);
   ASSERT_NEAR(Units::Liters(100), Units::Liters(Units::CubicYard(0.130795)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::CubicInches(61.0237)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Gigaliters(0.000000001)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Megaliters(0.000001)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Kiloliters(0.001)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Hectoliters(0.01)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Decaliters(0.1)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Liters(1)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Deciliters(10)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Centiliters(100)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Milliliters(1000)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Microliters(1000000)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Nanoliters(1000000000)), 0.01);
   ASSERT_NEAR(Units::Liters(1), Units::Liters(Units::Picoliters(1000000000000)), 0.01);
}













TEST_F(Usage_Test, Test_Precision)
{
   using namespace Units::Literals;

   Units::Length myLength = 1_ft;

   const int ITERATIONS = 10000;

   for (int i = 0; i < ITERATIONS; i++)
   {
      myLength = Units::Meters(myLength);
      myLength = Units::Feet(myLength);
   }

   //std::cout << Units::Feet(myLength) << std::endl;

   EXPECT_NEAR(Units::Feet(myLength), 1.0, 0.000000000001);
}