#ifndef FORCETYPE_H_GUARD
#define FORCETYPE_H_GUARD
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
   class Mass;
   class Acceleration;

   class Force
   {
   public:

      Mass operator/(const Acceleration& acceleration) const;
      Acceleration operator/(const Mass& mass) const;

      GENERIC_OPERATORS(Force);
   };
} //end namespace Units

UNIT_TEMPLATE(Force, Newton, 1.0, N);
UNIT_TEMPLATE(Force, Dyne, 100000.0, dyn);
UNIT_TEMPLATE(Force, KilogramsForce, (1.0 / 9.80665), KgF); // 1Kg * standard gravitation field
UNIT_TEMPLATE(Force, PoundsForce, (4.4482216152605), lbF); // https://en.wikipedia.org/wiki/Pound_(force)#Product_of_avoirdupois_pound_and_standard_gravity

#endif  // FORCETYPE_H_GUARD
