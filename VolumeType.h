#ifndef VOLUMETYPE_H_GUARD
#define VOLUMETYPE_H_GUARD
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
   class Area;
   class Length;

   class Volume
   {
   public:

      Area operator/(const Length& length) const;

      GENERIC_OPERATORS(Volume);
   };
} //end namespace Units

UNIT_TEMPLATE(Volume, Gallons, 3.785411784, gal);
UNIT_TEMPLATE(Volume, ImperialGallons, 4.54609, impgal);
UNIT_TEMPLATE(Volume, Quart, (3.785411784 / 4.0), quart);
UNIT_TEMPLATE(Volume, Pint, (3.785411784 / 8.0), pint);
UNIT_TEMPLATE(Volume, FluidOunces, (3.785411784 / 128.0), floz);
UNIT_TEMPLATE(Volume, Fifth, (3.785411784 / 5.0), fifth);
UNIT_TEMPLATE(Volume, CubicMeters, (0.001), m3);
UNIT_TEMPLATE(Volume, CubicCentimeters, (1000.0), cm3);
UNIT_TEMPLATE(Volume, CubicYard, (0.00130795062), yd3);
UNIT_TEMPLATE(Volume, CubicInches, (3.785411784 / 231.0), in3);

//Metric
UNIT_TEMPLATE(Volume, Gigaliters, (double(std::giga::num) / double(std::giga::den)), GL);
UNIT_TEMPLATE(Volume, Megaliters, (double(std::mega::num) / double(std::mega::den)), ML);
UNIT_TEMPLATE(Volume, Kiloliters, (double(std::kilo::num) / double(std::kilo::den)), kL);
UNIT_TEMPLATE(Volume, Hectoliters, (double(std::hecto::num) / double(std::hecto::den)), HL);
UNIT_TEMPLATE(Volume, Decaliters, (double(std::deca::num) / double(std::deca::den)), DL);
UNIT_TEMPLATE(Volume, Liters, 1.0, L);
UNIT_TEMPLATE(Volume, Deciliters, (double(std::deci::num) / double(std::deci::den)), dL);
UNIT_TEMPLATE(Volume, Centiliters, (double(std::centi::num) / double(std::centi::den)), cL);
UNIT_TEMPLATE(Volume, Milliliters, (double(std::milli::num) / double(std::milli::den)), mL);
UNIT_TEMPLATE(Volume, Microliters, (double(std::micro::num) / double(std::micro::den)), uL);
UNIT_TEMPLATE(Volume, Nanoliters, (double(std::nano::num) / double(std::nano::den)), nL);
UNIT_TEMPLATE(Volume, Picoliters, (double(std::pico::num) / double(std::pico::den)), pL);

#endif  // VOLUMETYPE_H_GUARD
