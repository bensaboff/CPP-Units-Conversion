#ifndef ANGLETYPE_H_GUARD
#define ANGLETYPE_H_GUARD
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

namespace Units
{
   class AngularSpeed;
   class Time;

   class Angle
   {
   public:

      AngularSpeed operator/(const Time& time) const;

      GENERIC_OPERATORS(Angle);

   private:
      const double HALF_CIRCLE = 180.0;
      const double FULL_CIRCLE = 360.0;

   public:
      Angle& LimitAnglePositive()
      {
         m_value = fmod(m_value, FULL_CIRCLE);

         if (m_value < 0.0)
         {
            m_value += (FULL_CIRCLE);
         }
         return *this;
      }
      Angle& LimitAngle360() { return LimitAnglePositive(); }
      Angle& LimitAngle()
      {
         LimitAnglePositive();
         if (m_value > HALF_CIRCLE)
         {
            m_value -= FULL_CIRCLE;
         }
         return *this;
      }
      int Sign()
      {
         LimitAngle();
         if (m_value > 0.0) return 1;
         if (m_value < 0.0) return -1;
         return 0;
      }
   };
} //end namespace Units

UNIT_TEMPLATE(Angle, Degrees, 1.0, deg); // 360 degrees for a full circle
UNIT_TEMPLATE(Angle, Radians, (180.0 / 3.1415926535897932384626433832795028841971), rad); // 2pi radians for a full circle
UNIT_TEMPLATE(Angle, Milliradians, (180.0 / 3200.0), mil); // 6,400 milliradians for a full circle
UNIT_TEMPLATE(Angle, BAMS, (180.0), bams); // 2 for a full circle
UNIT_TEMPLATE(Angle, Revolution, (1.0 / 360.0), rev); // Full circle
UNIT_TEMPLATE(Angle, ArcMinute, (1.0 / 60.0), arc_min);
UNIT_TEMPLATE(Angle, ArcSecond, (1.0 / 3600.0), arc_sec);

#endif  // ANGLETYPE_H_GUARD
