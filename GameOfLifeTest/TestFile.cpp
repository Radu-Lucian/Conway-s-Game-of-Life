#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch_amalgamated.hpp"

#include "Grid.h"

// 1. Create the base project
// 2. Write the code
// 3. Create a secondary project (same, empty C++)
// 4. Create catch_amalgamated.hpp (copy from: https://raw.githubusercontent.com/catchorg/Catch2/devel/extras/catch_amalgamated.hpp) and catch_amalgamted.cpp (https://raw.githubusercontent.com/catchorg/Catch2/devel/extras/catch_amalgamated.cpp)
// 5. Add reference to the base project (Properties -> C/C++ -> Additional Include AND Properties -> Linker -> Input -> Add the obj(s))
// 6. Add this file
// 7. Do this in order to compile the test project https://docs.microsoft.com/bs-cyrl-ba/cpp/build/reference/zc-hiddenfriend?view=msvc-160
// 8. Happy testing

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Factorials are computedeee", "[factorfial]") {
    Grid newGrid;
    REQUIRE(Factorial(1) == 1);
}