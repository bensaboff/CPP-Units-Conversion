#ifndef ANGULARSPEEDTYPE_H_GUARD
#define ANGULARSPEEDTYPE_H_GUARD
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
   class Angle;
   class AngularAcceleration;
   class Time;

   class AngularSpeed
   {
   public:

      Angle operator*(const Time& time) const;
      AngularAcceleration operator/(const Time& time) const;

      GENERIC_OPERATORS(AngularSpeed);
   };
} //end namespace Units

UNIT_TEMPLATE(AngularSpeed, DegreesPerSecond, 1.0, deg_s);
UNIT_TEMPLATE(AngularSpeed, DegreesPerMinute, (1.0 / 60.0), deg_m);
UNIT_TEMPLATE(AngularSpeed, DegreesPerHour, (1.0 / 3600.0), deg_hr);
UNIT_TEMPLATE(AngularSpeed, RadiansPerSecond, (180.0 / 3.1415926535897932384626433832795028841971), rad_s);
UNIT_TEMPLATE(AngularSpeed, MilliradiansPerSecond, (180.0 / 3200.0), mil_s); // 6,400 milliradians for a full circle // DECIDE: This is an old standard, current appears to be 6283/full circle
// See: https://en.wikipedia.org/wiki/Milliradian, should each exist for compatibility? Should only the old or only the new be used?
UNIT_TEMPLATE(AngularSpeed, BAMS_PerSecond, (180.0), bams_s);
UNIT_TEMPLATE(AngularSpeed, RevolutionPerSecond, (360.0), rps);
UNIT_TEMPLATE(AngularSpeed, RevolutionPerMinute, ((360.0) / 60), rpm);
UNIT_TEMPLATE(AngularSpeed, RevolutionPerHour, ((360.0) / 3600), rph);

#endif  // ANGULARSPEEDTYPE_H_GUARD
