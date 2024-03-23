#ifndef LENGTHTYPE_H_GUARD
#define LENGTHTYPE_H_GUARD
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
#include <stdexcept>

namespace Units
{
   class Area;
   class Time;
   class Speed;

   class Length
   {
   public:

      Area operator*(const Length& length) const;
      Speed operator/(const Time& time) const;
      Time operator/(const Speed& time) const;

      GENERIC_OPERATORS(Length);
   };

   typedef Length Distance;

} //end namespace Units

   // https://www.nist.gov/pml/us-surveyfoot/revised-unit-conversion-factors
UNIT_TEMPLATE(Length, FlightLevel, 0.032808398950131, fl); //  3.2808398950131E-2 fl/m
UNIT_TEMPLATE(Length, AstronomicalUnits, 149597870700.0, au); // https://physics.nist.gov/cuu/Units/outside.html 1 au = 149 597 870 700 m, exactly
UNIT_TEMPLATE(Length, DataMiles, 0.0005468066491689, data_mile); //  5.468066491689E-4 data mile per meter
UNIT_TEMPLATE(Length, NauticalMiles, 1852.0, nmi); // 1852 m/nmi
UNIT_TEMPLATE(Length, Miles, (25146000.0 / 15625.0), mi); // https://www.sfei.org/it/gis/map-interpretation/conversion-constants#Constants%20are%20exact // 1609.347 218 694 m
UNIT_TEMPLATE(Length, Leagues, 4828.041656083, league); // 4828.041 656 083 m
UNIT_TEMPLATE(Length, Fathoms, 1.828803658, fathom); // 1.828 803 658 m
UNIT_TEMPLATE(Length, Furlong, 201.168402337, furlong); // 201.168 402 337 m
UNIT_TEMPLATE(Length, Yards, 0.9144, yd); // https://www.sfei.org/it/gis/map-interpretation/conversion-constants#Constants%20are%20exact
UNIT_TEMPLATE(Length, KiloFeet, 304.8, Kft); // Feet * 1000
UNIT_TEMPLATE(Length, Feet, 0.3048, ft); // https://www.sfei.org/it/gis/map-interpretation/conversion-constants#Constants%20are%20exact
UNIT_TEMPLATE(Length, US_Survey_Feet, (1200.0 / 3937.0), survey_ft); // https://www.sfei.org/it/gis/map-interpretation/conversion-constants#Constants%20are%20exact
UNIT_TEMPLATE(Length, Inches, (0.3048 / 12.0), in);  // Feet/12

//Metric
UNIT_TEMPLATE(Length, Gigameters, (double(std::giga::num) / double(std::giga::den)), Gm);
UNIT_TEMPLATE(Length, Megameters, (double(std::mega::num) / double(std::mega::den)), Mm);
UNIT_TEMPLATE(Length, Kilometers, (double(std::kilo::num) / double(std::kilo::den)), km);
UNIT_TEMPLATE(Length, Hectometers, (double(std::hecto::num) / double(std::hecto::den)), Hm);
UNIT_TEMPLATE(Length, Decameters, (double(std::deca::num) / double(std::deca::den)), Dm);
UNIT_TEMPLATE(Length, Meters, 1.0, m);
UNIT_TEMPLATE(Length, Decimeters, (double(std::deci::num) / double(std::deci::den)), dm);
UNIT_TEMPLATE(Length, Centimeters, (double(std::centi::num) / double(std::centi::den)), cm);
UNIT_TEMPLATE(Length, Millimeters, (double(std::milli::num) / double(std::milli::den)), mm);
UNIT_TEMPLATE(Length, Micrometers, (double(std::micro::num) / double(std::micro::den)), um);
UNIT_TEMPLATE(Length, Nanometers, (double(std::nano::num) / double(std::nano::den)), nm);
UNIT_TEMPLATE(Length, Picometers, (double(std::pico::num) / double(std::pico::den)), pm);

#endif  // LENGTHTYPE_H_GUARD
