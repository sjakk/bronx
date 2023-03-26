cmake_minimum_required (VERSION 3.8)


add_library(bronx "application.cpp" "application.h" "core.h" "entryPoint.h" "log.cpp" "log.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeBronx PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



enable_testing()


add_executable(
  appl
  application.cpp
)
target_link_libraries(
  appl
  GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(appl)
