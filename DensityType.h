#ifndef DENSITYTYPE_H_GUARD
#define DENSITYTYPE_H_GUARD
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
   class Volume;

   class Density
   {
   public:

      Mass operator*(const Volume& volume) const;

      GENERIC_OPERATORS(Density);
   };
} //end namespace Units

UNIT_TEMPLATE(Density, KilogramsPerCubicMeter, 1.0, kg_m3);
UNIT_TEMPLATE(Density, KilogramsPerLiter, 0.001, kg_L);
UNIT_TEMPLATE(Density, GramsPerCubicCentimeter, (0.001), g_cm3);
UNIT_TEMPLATE(Density, GramsPerMilliliter, (0.001), g_mL);
UNIT_TEMPLATE(Density, TonnesPerCubicMeter, (1/1000), t_m3); // 1000 Kg per Tonne

#endif  // DENSITYTYPE_H_GUARD
