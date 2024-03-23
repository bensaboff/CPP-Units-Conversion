#ifndef TIMETYPE_H_GUARD
#define TIMETYPE_H_GUARD
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

#include "UnitBase.h"
#include <ratio>
#include <stdexcept>

namespace Units
{
   class Length;
   class Speed;

   class Time
   {
   public:

      Length operator*(const Speed& speed) const;

      GENERIC_OPERATORS(Time);
   };

} //end namespace Units

   // Leap seconds are not taken into account
UNIT_TEMPLATE(Time, LeapYears, 31622400.0, leap_yr); // Based on 366 days per year
UNIT_TEMPLATE(Time, NonLeapYears, 31536000, non_leap_yr); // Based on 365 days per year
UNIT_TEMPLATE(Time, Years, 31557600, yr); // Based on 365.25 days per year
UNIT_TEMPLATE(Time, NonLeapYearMonths, 2628000, non_leap_yr_mon); // Based on 12 months per non leap year
UNIT_TEMPLATE(Time, Months, 2629800, mon); // Based on 12 months per year
UNIT_TEMPLATE(Time, Weeks, 604800, wk);
UNIT_TEMPLATE(Time, Days, 86400, day);
UNIT_TEMPLATE(Time, Hours, 3600.0, hr);
UNIT_TEMPLATE(Time, Minutes, 60, min);
UNIT_TEMPLATE(Time, Seconds, 1.0, s);
UNIT_TEMPLATE(Time, Milliseconds, (double(std::milli::num) / double(std::milli::den)), ms);
UNIT_TEMPLATE(Time, Microseconds, (double(std::micro::num) / double(std::micro::den)), us);
UNIT_TEMPLATE(Time, Nanoseconds, (double(std::nano::num) / double(std::nano::den)), ns);
UNIT_TEMPLATE(Time, Picoseconds, (double(std::pico::num) / double(std::pico::den)), ps);

#endif  // TIMETYPE_H_GUARD
