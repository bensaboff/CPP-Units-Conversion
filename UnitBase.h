#ifndef UNITBASE_H_GUARD
#define UNITBASE_H_GUARD
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

#include <iostream>

#define GENERIC_OPERATORS(T) \
   public: \
      /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */\
      /* Constructors / Destructors                                             */\
      /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */\
      T() : m_value(0.0) {}\
      T(const T & rhs) { m_value = rhs.BaseValue(); }\
      T(const T && rhs) { m_value = rhs.BaseValue(); }\
      ~T() {}\
\
      /* Function to always return zero                                        */\
      /* This is a common value to checkand use of this function will prevent  */\
      /* the need to instantiate a class just to check against 0               */\
      static T zero() { return T(0.0); }\
\
      T& operator=(const T& rhs)\
      {\
         if (&rhs != this)\
         {\
            m_value = rhs.BaseValue();\
         }\
\
         return *this;\
      }\
      T& operator=(const T&& rhs) noexcept\
      {\
         if (&rhs != this)\
         {\
            m_value = rhs.BaseValue();\
         }\
\
         return *this;\
      }\
      T& operator+=(const T& rhs)\
      {\
         if (&rhs != this)\
         {\
            m_value += rhs.BaseValue();\
         }\
\
         return *this;\
      }\
      T& operator-=(const T& rhs)\
      {\
         if (&rhs != this)\
         {\
            m_value -= rhs.BaseValue();\
         }\
\
         return *this;\
      }\
\
      operator T() const\
      {\
         return T(m_value);\
      }\
\
      T operator+(const T& rhs) const\
      {\
         return T(m_value + rhs.BaseValue());\
      }\
\
      T operator-(const T& rhs) const\
      {\
         return T(m_value - rhs.BaseValue());\
      }\
   \
      T operator+() const\
      {\
         return T(m_value);\
      }\
      T operator-() const\
      {\
         return T(-m_value);\
      }\
\
      bool operator< (const T& rhs) const { return m_value <  rhs.m_value; }\
      bool operator> (const T& rhs) const { return m_value >  rhs.m_value; }\
      bool operator<=(const T& rhs) const { return m_value <= rhs.m_value; }\
      bool operator>=(const T& rhs) const { return m_value >= rhs.m_value; }\
      bool operator==(const T& rhs) const { return m_value == rhs.m_value; }\
      bool operator!=(const T& rhs) const { return m_value != rhs.m_value; }\
      bool operator< (double rhs) const { return value() < rhs; }\
      bool operator> (double rhs) const { return value() > rhs; }\
      bool operator<=(double rhs) const { return value() <= rhs; }\
      bool operator>=(double rhs) const { return value() >= rhs; }\
      bool operator==(double rhs) const { return value() == rhs; }\
      bool operator!=(double rhs) const { return value() != rhs; }\
\
   protected:\
      T(double rhs) : m_value(rhs) {}\
      T& operator=(const double& rhs)\
      {\
         m_value = rhs;\
\
         return *this;\
      }\
\
      /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/\
      /* Operator Override Methods */\
      /*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/\
      double BaseValue() const { return m_value; }\
      double value() const { return m_value; }\
      /* This assumes the base type and only used if not created as a specific unit */\
      void SetValue(double input) { m_value = input; }\
\
      double m_value;


#define UNIT_TEMPLATE_EQUATION(Base, TypeName, equation_to_base, equation_from_base, userliteral)\
namespace Units\
{\
   class TypeName : public Base\
   {\
   public:\
      TypeName() : Base(0.0) {}\
      TypeName(const Base& rhs) : Base(rhs) { }\
      TypeName(const Base&& rhs) : Base(rhs) { }\
   \
      TypeName(double input) { m_value = (equation_to_base); }\
      ~TypeName() {}\
   \
      TypeName operator*(double rhs) const { return TypeName(value() * rhs); }\
      TypeName operator/(double rhs) const { return TypeName(value() / rhs); }\
   \
      double value() const { return (equation_from_base); }\
      operator double() const { return value(); }\
   \
      void SetValue(double input) { m_value = (equation_to_base); }\
   };\
\
   namespace Literals\
   {\
      inline Units::TypeName operator"" _##userliteral(unsigned long long int rhs) { return Units::TypeName(double(rhs)); } \
      inline Units::TypeName operator"" _##userliteral(long double rhs) { return Units::TypeName(rhs); }\
   }\
\
} /* end namespace Units */\
\
inline std::ostream& operator<<(std::ostream& os, const Units::TypeName& unit)\
{\
   os << unit.value() << #userliteral;\
   return os;\
}

#define UNIT_TEMPLATE(Base, TypeName, ratio, userliteral)\
static_assert(ratio != 0.0, "zero ratio not allowed");\
UNIT_TEMPLATE_EQUATION(Base, TypeName, (input * (ratio)), (m_value * (1.0 / ratio)), userliteral)


#endif  // UNITBASE_H_GUARD
