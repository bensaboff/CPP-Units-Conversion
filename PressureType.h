#ifndef PRESSURETYPE_H_GUARD
#define PRESSURETYPE_H_GUARD
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
   class Area;
   class Force;

   class Pressure
   {
   public:

      Force Pressure::operator*(const Area& area) const;
      Area Pressure::operator/(const Force& force) const;

      GENERIC_OPERATORS(Pressure);
   };
} //end namespace Units

UNIT_TEMPLATE(Pressure, Atmospheres, 101325.0, atm); // Standard Atmosphere https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b9#PRESSURE
UNIT_TEMPLATE(Pressure, TechnicalAtmospheres, 98066.5, at); // https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b9#PRESSURE
UNIT_TEMPLATE(Pressure, Bars, (100000.0), bar); // https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b9#PRESSURE
UNIT_TEMPLATE(Pressure, PoundsPerSquareInch, (6894.757), PSI); // https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b8#P (pound-force per square inch (psi) (lbf/in2) Approximate)
UNIT_TEMPLATE(Pressure, Torr, (101325.0 / 760.0), Torr); // https://en.wikipedia.org/wiki/Torr#Conversion_factors
UNIT_TEMPLATE(Pressure, MillimetersMercury, (133.3223684), mmHg); 

//Metric
UNIT_TEMPLATE(Pressure, GigaPascals, (double(std::giga::num) / double(std::giga::den)), GPa);
UNIT_TEMPLATE(Pressure, MegaPascals, (double(std::mega::num) / double(std::mega::den)), MPa);
UNIT_TEMPLATE(Pressure, KiloPascals, (double(std::kilo::num) / double(std::kilo::den)), kPa);
UNIT_TEMPLATE(Pressure, HectoPascals, (double(std::hecto::num) / double(std::hecto::den)), HPa);
UNIT_TEMPLATE(Pressure, DecaPascals, (double(std::deca::num) / double(std::deca::den)), DPa);
UNIT_TEMPLATE(Pressure, Pascals, 1.0, Pa);
UNIT_TEMPLATE(Pressure, DeciPascals, (double(std::deci::num) / double(std::deci::den)), dPa);
UNIT_TEMPLATE(Pressure, CentiPascals, (double(std::centi::num) / double(std::centi::den)), cPa);
UNIT_TEMPLATE(Pressure, MilliPascals, (double(std::milli::num) / double(std::milli::den)), mPa);
UNIT_TEMPLATE(Pressure, MicroPascals, (double(std::micro::num) / double(std::micro::den)), uPa);
UNIT_TEMPLATE(Pressure, NanoPascals, (double(std::nano::num) / double(std::nano::den)), nPa);
UNIT_TEMPLATE(Pressure, PicoPascals, (double(std::pico::num) / double(std::pico::den)), pPa);

#endif  // PRESSURETYPE_H_GUARD
