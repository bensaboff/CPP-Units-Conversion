#ifndef AREATYPE_H_GUARD
#define AREATYPE_H_GUARD
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

   class Area
   {
   public:

      GENERIC_OPERATORS(Area);
   };
} //end namespace Units

//https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b8
UNIT_TEMPLATE(Area, Hectare, 10000, ha); // 1.0	E+04
UNIT_TEMPLATE(Area, SquareFeet, 0.09290304, ft2); // 9.290 304	E-02
UNIT_TEMPLATE(Area, SquareInches, 6.4516E-04, in2); // 6.4516	E-04
UNIT_TEMPLATE(Area, SquareMeters, 1.0, m2);



#endif  // AREATYPE_H_GUARD
