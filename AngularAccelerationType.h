#ifndef ANGULARACCELERATIONTYPE_H_GUARD
#define ANGULARACCELERATIONTYPE_H_GUARD
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
   class AngularSpeed;
   class Time;

   class AngularAcceleration
   {
   public:

      AngularSpeed operator*(const Time& time) const;

      GENERIC_OPERATORS(AngularAcceleration);
   };
} //end namespace Units
UNIT_TEMPLATE(AngularAcceleration, DegreesPerSecondSquared, 1.0, deg_s2);
UNIT_TEMPLATE(AngularAcceleration, DegreesPerMinuteSquared, 3600.0, deg_m2);
UNIT_TEMPLATE(AngularAcceleration, DegreesPerHourSquared, 12960000.0, deg_hr2);
UNIT_TEMPLATE(AngularAcceleration, RadiansPerSecondSquared, (180.0 / 3.1415926535897932384626433832795028841971), rad_s2);
UNIT_TEMPLATE(AngularAcceleration, MilliradiansPerSecondSquared, (180.0 / 3200.0), mil_s2);
UNIT_TEMPLATE(AngularAcceleration, BAMS_PerSecondSquared, (180.0), bams_s2);
UNIT_TEMPLATE(AngularAcceleration, RevolutionPerSecondSquared, (360.0), rps2);
UNIT_TEMPLATE(AngularAcceleration, RevolutionPerMinuteSquared, ((360.0) * 3600), rpm2);
UNIT_TEMPLATE(AngularAcceleration, RevolutionPerHourSquared, ((360.0) * 12960000.0), rph2);

#endif  // ANGULARACCELERATIONTYPE_H_GUARD
