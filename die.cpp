/// @file       yahtzee.cpp
/// @date       01/11/2021
/// @details    Provides the die class implementation for the yahtzee
///             program.
///
/// @author     Hritik "Ricky" Gupta

#include <random>
#include "assets.h"

using namespace assets;

die::die(int num_sides) {
    this->num_sides = num_sides;
    this->rolled_value = 0;
}

void die::roll() {
    this->rolled_value = (int) (random() % (num_sides) + 1);
}
int die::get_rolled_value() {
    return this->rolled_value;
}