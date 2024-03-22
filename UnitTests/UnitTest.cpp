#include "UnitTest.h"

#include "UnitBase.h"

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

using namespace Units::Literals;

const double MARGIN = 0.01;

// Example test case
TEST_F(UnitTest, AccelerationConversionTest) {
   Units::Acceleration accel = Units::MetersPerSecondSquared(100);

   ASSERT_NEAR(Units::StandardGravity(accel), 10.19716213, MARGIN);
   ASSERT_NEAR(Units::MetersPerHourSquared(accel), 1296000000.0, MARGIN);
   ASSERT_NEAR(Units::FeetPerMinuteSquared(accel), 1181102.36, MARGIN);
   ASSERT_NEAR(Units::FeetPerSecondSquared(accel), 328.08399, MARGIN);
   ASSERT_NEAR(Units::MilesPerHourSquared(accel), 805297.065, MARGIN);
   ASSERT_NEAR(Units::KilometersPerHourSquared(accel), 1296000.0, MARGIN);
   ASSERT_NEAR(Units::InchesPerSecondSquared(accel), 3937.00787, MARGIN);
   ASSERT_NEAR(Units::Galileo(accel), 10000.0, MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), 100.0, MARGIN);

   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(10.19716213_g0), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(1296000000.0_meter_per_hour_2), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(1181102.36_fpm2), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(328.08399_fps2), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(805297.065_mph2), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(1296000.0_kph2), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(3937.00787_inps2), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(10000.0_Galileo), MARGIN);
   ASSERT_NEAR(Units::MetersPerSecondSquared(accel), Units::MetersPerSecondSquared(100.0_mps2), MARGIN);
}

TEST_F(UnitTest, AngleConversionTest) {
   Units::Angle angle = Units::Degrees(100);
   // Add ASSERT_NEAR commands for all conversions
}

TEST_F(UnitTest, AngularAccelerationConversionTest) {
   Units::AngularAcceleration anglular_accel = Units::DegreesPerSecondSquared(100);
   // Add ASSERT_NEAR commands for all conversions
}

TEST_F(UnitTest, AngularSpeedConversionTest) {
   Units::AngularSpeed angular_speed = Units::DegreesPerSecond(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, AreaConversionTest) {
   Units::Area area = Units::SquareMeters(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, ForceConversionTest) {
   Units::Force force = Units::Newton(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, LengthConversionTest) {
   Units::Length length = Units::Meters(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, MassConversionTest) {
   Units::Mass mass = Units::Grams(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, PowerConversionTest) {
   Units::Power power = Units::decibelWatts(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, PressureConversionTest) {
   Units::Pressure pressure = Units::Pascals(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, SpeedConversionTest) {
   Units::Speed speed = Units::MetersPerSecond(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, TemperatureConversionTest) {
   Units::Temperature temp = Units::Celsius(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, TimeConversionTest) {
   Units::Time time = Units::Seconds(100);
   // Add ASSERT_NEAR commands for all conversions
}
TEST_F(UnitTest, VolumeConversionTest) {
   Units::Volume volume = Units::Liters(100);
   // Add ASSERT_NEAR commands for all conversions
}

TEST_F(UnitTest, UnitMathTest) {
   Units::Length distance = Units::Meters(100);
   Units::Time time = Units::Seconds(50);

   Units::Speed speed = distance / time;

   ASSERT_NEAR(Units::MetersPerSecond(speed), 2.0, MARGIN);

   // Add at least one use of each implemented operator
}
