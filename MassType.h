#ifndef MASSTYPE_H_GUARD
#define MASSTYPE_H_GUARD
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
   class Force;
   class Acceleration;

   class Mass
   {
   public:

      Force operator*(const Acceleration& acceleration) const;

      GENERIC_OPERATORS(Mass);
   };
} //end namespace Units

//https://www.nist.gov/pml/special-publication-811/nist-guide-si-appendix-b-conversion-factors/nist-guide-si-appendix-b8
UNIT_TEMPLATE(Mass, Grain, 0.06479891, gr); // 6.479 891	E-05
UNIT_TEMPLATE(Mass, Pound, 453.59237, lb); // International Pound agreement
UNIT_TEMPLATE(Mass, Ounce, (453.59237 / 16.0), oz); // 16 oz per pound
UNIT_TEMPLATE(Mass, Stone, (453.59237 * 14.0), st); // 14 pounds per stone
UNIT_TEMPLATE(Mass, ShortTon, (453.59237 * 2000.0), ton_us);
UNIT_TEMPLATE(Mass, LongTon, (453.59237 * 2240.0), ton_uk);
UNIT_TEMPLATE(Mass, Tonne, 1000000.0, t); // Metric ton

//Metric
UNIT_TEMPLATE(Mass, Gigagrams, (double(std::giga::num) / double(std::giga::den)), Gg);
UNIT_TEMPLATE(Mass, Megagrams, (double(std::mega::num) / double(std::mega::den)), Mg);
UNIT_TEMPLATE(Mass, Kilograms, (double(std::kilo::num) / double(std::kilo::den)), kg);
UNIT_TEMPLATE(Mass, Hectograms, (double(std::hecto::num) / double(std::hecto::den)), Hg);
UNIT_TEMPLATE(Mass, Decagrams, (double(std::deca::num) / double(std::deca::den)), Dg);
UNIT_TEMPLATE(Mass, Grams, 1.0, m);
UNIT_TEMPLATE(Mass, Decigrams, (double(std::deci::num) / double(std::deci::den)), dg);
UNIT_TEMPLATE(Mass, Centigrams, (double(std::centi::num) / double(std::centi::den)), cg);
UNIT_TEMPLATE(Mass, Milligrams, (double(std::milli::num) / double(std::milli::den)), mg);
UNIT_TEMPLATE(Mass, Micrograms, (double(std::micro::num) / double(std::micro::den)), ug);
UNIT_TEMPLATE(Mass, Nanograms, (double(std::nano::num) / double(std::nano::den)), ng);
UNIT_TEMPLATE(Mass, Picograms, (double(std::pico::num) / double(std::pico::den)), pg);

#endif  // MASSTYPE_H_GUARD
