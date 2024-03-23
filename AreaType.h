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
   class Length;
   class Volume;

   class Area
   {
   public:

      Volume operator*(const Length& length) const;
      Length operator/(const Length& length) const;

      GENERIC_OPERATORS(Area);
   };
} //end namespace Units

//https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b8
UNIT_TEMPLATE(Area, Hectare, 10000, ha); // 1.0	E+04
UNIT_TEMPLATE(Area, SquareFeet, 0.09290304, ft2); // 9.290 304	E-02
UNIT_TEMPLATE(Area, SquareInches, 6.4516E-04, in2); // 6.4516	E-04

//Metric
UNIT_TEMPLATE(Area, SquareGigameters, ((double(std::giga::num) / double(std::giga::den)) * (double(std::giga::num) / double(std::giga::den))), Gm2);
UNIT_TEMPLATE(Area, SquareMegameters, ((double(std::mega::num) / double(std::mega::den)) * (double(std::mega::num) / double(std::mega::den))), Mm2);
UNIT_TEMPLATE(Area, SquareKilometers, ((double(std::kilo::num) / double(std::kilo::den)) * (double(std::kilo::num) / double(std::kilo::den))), km2);
UNIT_TEMPLATE(Area, SquareHectometers, ((double(std::hecto::num) / double(std::hecto::den)) * (double(std::hecto::num) / double(std::hecto::den))), Hm2);
UNIT_TEMPLATE(Area, SquareDecameters, ((double(std::deca::num) / double(std::deca::den)) * (double(std::deca::num) / double(std::deca::den))), Dm2);
UNIT_TEMPLATE(Area, SquareMeters, 1.0, m2);
UNIT_TEMPLATE(Area, SquareDecimeters, ((double(std::deci::num) / double(std::deci::den)) * (double(std::deci::num) / double(std::deci::den))), dm2);
UNIT_TEMPLATE(Area, SquareCentimeters, ((double(std::centi::num) / double(std::centi::den)) * (double(std::centi::num) / double(std::centi::den))), cm2);
UNIT_TEMPLATE(Area, SquareMillimeters, ((double(std::milli::num) / double(std::milli::den)) * (double(std::milli::num) / double(std::milli::den))), mm2);
UNIT_TEMPLATE(Area, SquareMicrometers, ((double(std::micro::num) / double(std::micro::den)) * (double(std::micro::num) / double(std::micro::den))), um2);
UNIT_TEMPLATE(Area, SquareNanometers, ((double(std::nano::num) / double(std::nano::den)) * (double(std::nano::num) / double(std::nano::den))), nm2);
UNIT_TEMPLATE(Area, SquarePicometers, ((double(std::pico::num) / double(std::pico::den)) * (double(std::pico::num) / double(std::pico::den))), pm2);


#endif  // AREATYPE_H_GUARD
