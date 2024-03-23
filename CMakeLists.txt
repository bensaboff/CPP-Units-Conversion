#Copyright 2022 Ben Saboff
#
#Licensed under the Apache License, Version 2.0 (the "License");
#you may not use this file except in compliance with the License.
#You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
#Unless required by applicable law or agreed to in writing, software
#distributed under the License is distributed on an "AS IS" BASIS,
#WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#See the License for the specific language governing permissions and
#limitations under the License.

project(CPP-Units)

cmake_minimum_required(VERSION 3.15)

set(source_files
    AccelerationType.cpp
    AngleType.cpp
    AngularAccelerationType.cpp
    AngularSpeedType.cpp
    AngleType.cpp
    AreaType.cpp
    ForceType.cpp
    LengthType.cpp
    MassType.cpp
    PowerType.cpp
    PressureType.cpp
    SpeedType.cpp
    TemperatureType.cpp
    TimeType.cpp
    VolumeType.cpp
   )
   
add_library(${PROJECT_NAME} OBJECT ${source_files})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if(TARGET gtest)
   add_subdirectory(UnitTest)
endif()
