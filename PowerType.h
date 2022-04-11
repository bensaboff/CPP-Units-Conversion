#ifndef POWERTYPE_H_GUARD
#define POWERTYPE_H_GUARD
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
   class Power
   {
   public:

      GENERIC_OPERATORS(Power);
   };
} //end namespace Units

UNIT_TEMPLATE(Power, HorsePower, (1.0 / 745.7), hp);
UNIT_TEMPLATE_EQUATION(Power, decibelWatts, (std::pow(10, (input / 10.0))), (10.0 * std::log10(m_value)), dBW);
UNIT_TEMPLATE_EQUATION(Power, decibelMilliwatts, (std::pow(10, (input / 10.0)) * (double(std::milli::num) / double(std::milli::den))),
   (10.0 * std::log10(m_value * (double(std::milli::den) / double(std::milli::num)))), dBm);

//Metric
UNIT_TEMPLATE(Power, GigaWatts, (double(std::giga::num) / double(std::giga::den)), GW);
UNIT_TEMPLATE(Power, MegaWatts, (double(std::mega::num) / double(std::mega::den)), MW);
UNIT_TEMPLATE(Power, KiloWatts, (double(std::kilo::num) / double(std::kilo::den)), KW);
UNIT_TEMPLATE(Power, HectoWatts, (double(std::hecto::num) / double(std::hecto::den)), HW);
UNIT_TEMPLATE(Power, DecaWatts, (double(std::deca::num) / double(std::deca::den)), DW);
UNIT_TEMPLATE(Power, Watts, 1.0, W);
UNIT_TEMPLATE(Power, DeciWatts, (double(std::deci::num) / double(std::deci::den)), dW);
UNIT_TEMPLATE(Power, CentiWatts, (double(std::centi::num) / double(std::centi::den)), cW);
UNIT_TEMPLATE(Power, MilliWatts, (double(std::milli::num) / double(std::milli::den)), mW);
UNIT_TEMPLATE(Power, MicroWatts, (double(std::micro::num) / double(std::micro::den)), uW);
UNIT_TEMPLATE(Power, NanoWatts, (double(std::nano::num) / double(std::nano::den)), nW);
UNIT_TEMPLATE(Power, PicoWatts, (double(std::pico::num) / double(std::pico::den)), pW);

#endif  // POWERTYPE_H_GUARD
