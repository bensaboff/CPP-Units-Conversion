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

project(CPP-Units_Tests)

include(CTest)

set(gtest_foce_shared_crt ON CACHE BOOL "" FORCE)

set(source_files
   TestMain.cpp
   ClassTests.cpp
   UsageTests.cpp
   )

add_executable(${PROJECT_NAME} ${source_files})

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
   PRIVATE CPP-Units
   PRIVATE gtest_main
)

if(MSVC)
   target_link_libraries(${PROJECT_NAME} PRIVATE legacy_stdio_definitions)
endif()