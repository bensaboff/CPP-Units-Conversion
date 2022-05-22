#ifndef ACCELERATIONTYPE_H_GUARD
#define ACCELERATIONTYPE_H_GUARD
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

namespace Units
{
   class Speed;
   class Time;
   class Mass;
   class Force;

   class Acceleration
   {
   public:

      Speed operator*(const Time& time) const;
      Force operator*(const Mass& mass) const;

      GENERIC_OPERATORS(Acceleration);
   };
} //end namespace Units

//https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b8
UNIT_TEMPLATE(Acceleration, StandardGravity, 9.80665, g0); // acceleration of free fall, standard (gn)
UNIT_TEMPLATE(Acceleration, MetersPerHourSquared, 12960000.0, meter_per_hour_2); // (1 m) / (1/(3600^2) hr/sec^2)
UNIT_TEMPLATE(Acceleration, FeetPerMinuteSquared, (0.3048 / 3600.0), fpm2); // (0.3048 m/ft) / (60^2 min^2/sec)
UNIT_TEMPLATE(Acceleration, FeetPerSecondSquared, 0.3048, fps2); // (0.3048 m/ft)
UNIT_TEMPLATE(Acceleration, MilesPerHourSquared, (1609.344 / 12960000.0), mph2); // (1609.344 m/mi) / (3600^2 sec^2/hr)
UNIT_TEMPLATE(Acceleration, KilometersPerHourSquared, (10.0 / 1296.0), kph2); // (1000 m/km) / (3600^2 sec^2/hr)
UNIT_TEMPLATE(Acceleration, InchesPerSecondSquared, 0.0254, inps2);
UNIT_TEMPLATE(Acceleration, gal, 0.01, Gal);
UNIT_TEMPLATE(Acceleration, MetersPerSecondSquared, 1.0, mps2);



#endif  // ACCELERATIONTYPE_H_GUARD
