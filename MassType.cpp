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

#include "ForceType.h"
#include "AccelerationType.h"
#include "MassType.h"

namespace Units
{
    Force Mass::operator*(const Acceleration& acceleration) const
    {
        // Newtons use kilograms rather than grams
        return Newton(m_value * 1000.0 * MetersPerSecondSquared(acceleration));
    }
} //end namespace Units
