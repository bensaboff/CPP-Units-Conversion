#ifndef SPEEDTYPE_H_GUARD
#define SPEEDTYPE_H_GUARD
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
   class Time;

   class Speed
   {
   public:

      Length operator*(const Time& speed) const;

      GENERIC_OPERATORS(Speed);
   };
} //end namespace Units

// As modeled in the International Standard Atmosphere, dry air at mean sea level, standard temperature of 15 °C (59 °F)
UNIT_TEMPLATE(Speed, Mach, 340.3, mach); // Mach = 340.3 m/s (https://en.wikipedia.org/wiki/Mach_number#Overview)
UNIT_TEMPLATE(Speed, Knots, (1852.0 / 3600.0), kt); // https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication811e2008.pdf 1 nautical mile per hour = (1852/3600) m/s 
UNIT_TEMPLATE(Speed, MetersPerHour, (1.0 / 3600.0), meter_per_hour); // (1 m) / (1/3600 hr/sec)
UNIT_TEMPLATE(Speed, FeetPerMinute, 0.00508, fpm); // (0.3048 m/ft) / (60 min/sec)
UNIT_TEMPLATE(Speed, FeetPerSecond, 0.3048, fps); // (0.3048 m/ft)
UNIT_TEMPLATE(Speed, MilesPerHour, (1609.344 / 3600), mph); // (1609.344 m/mi) / (3600 sec/hr)
UNIT_TEMPLATE(Speed, KilometersPerHour, (10.0 / 36.0), kph); // (1000 m/km) / (3600 sec/hr)
UNIT_TEMPLATE(Speed, MetersPerSecond, 1.0, mps);
UNIT_TEMPLATE_EQUATION(Speed, WarpFactor, (Units::MetersPerSecond(299792458) * (std::pow(2, (3.0/5.0) * std::log2(input)))),
   std::pow(std::sqrt(m_value / Units::MetersPerSecond(299792458)), 10.0/3.0), wf);

namespace Units
{
   const Speed SPEED_OF_LIGHT = MetersPerSecond(299792458);
}

#endif  // SPEEDTYPE_H_GUARD
