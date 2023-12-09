#ifndef TEMPERATURETYPE_H_GUARD
#define TEMPERATURETYPE_H_GUARD
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
   class Temperature
   {
   public:

      GENERIC_OPERATORS(Temperature);
   };

} //end namespace Units

// from: https://www.weather.gov/media/epz/wxcalc/tempConvert.pdf
//To convert between degrees Celsius(°C) --> Kelvin(K) || Rankine (R) || Farenheit (F):
// Updated with International Bureau of Weights and Measures
//    2019 redefinition of the SI base units
//    see: https://en.wikipedia.org/wiki/2019_redefinition_of_the_SI_base_units
//
//    Tc = Tk - 273.15
//    Tk = Tc + 273.15
//
//    Tc = (5 / 9) * (Tf - 32)
//    Tf = ((9 / 5) * Tc) + 32
//
//    Tc = (5 / 9) * ((Tr - 459.67) - 32)
//    Tr = ((9 / 5) * Tc) + 32) + 459.67
//
//    Where Tc is temperature in Celsius
//          Tk is temperature in Kelvin
//          Tr is temperature in Rankine
//          Tf is temperature in Fareneheit
//
UNIT_TEMPLATE(Temperature, Celsius, 1.0, degC); // Base Unit
UNIT_TEMPLATE_EQUATION(Temperature, Kelvin, (input - 273.15), (m_value + 273.15) , degK); //  https://www.bipm.org/documents/20126/41483022/SI-Brochure-9.pdf pg.133
UNIT_TEMPLATE_EQUATION(Temperature, Farenheit, ((5.0 / 9.0) * (input - 32.0)), ((9.0/5.0 * m_value) + 32), degF); // 
UNIT_TEMPLATE_EQUATION(Temperature, Rankine, ((5.0/9.0) * ((input - 459.67) - 32.0)), ((((9.0/5.0) * m_value) + 32.0) + 459.67), degR); // https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication811e2008.pdf pg.66


#endif  // TEMPERATURETYPE_H_GUARD
