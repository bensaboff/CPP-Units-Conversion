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
   class Angle
   {
   public:

      GENERIC_OPERATORS(Angle);

   private:
      const double PI = 3.1415926535897932384626433832795028841971;
      const double TWO_PI = 2.0 * PI;

   public:
      Angle& LimitAnglePositive()
      {
         m_value = fmod(m_value, TWO_PI);

         if (m_value < 0.0)
         {
            m_value += (TWO_PI);
         }
         return *this;
      }
      Angle& LimitAngle360() { return LimitAnglePositive(); }
      Angle& LimitAngle()
      {
         LimitAnglePositive();
         if (m_value > PI)
         {
            m_value -= TWO_PI;
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

UNIT_TEMPLATE(Angle, Radians, 1.0, rad); // 2pi radians for a full circle
UNIT_TEMPLATE(Angle, Degrees, (3.1415926535897932384626433832795028841971/180.0), deg); // 360 degrees for a full circle
UNIT_TEMPLATE(Angle, Milliradians, (3.1415926535897932384626433832795028841971/3200.0), mil); // 6,400 milliradians for a full circle
UNIT_TEMPLATE(Angle, BAMS, 3.1415926535897932384626433832795028841971, bams); // 2 for a full circle
UNIT_TEMPLATE(Angle, Revolution, (3.1415926535897932384626433832795028841971 * 2.0), rev); // Full circle

#endif  // ANGLETYPE_H_GUARD
