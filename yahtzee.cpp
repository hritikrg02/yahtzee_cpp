/// @file       yahtzee.cpp
/// @date       01/11/2021
/// @details    Provides the yahtzee class implementation for the yahtzee
///             program.
///
/// @author     Hritik "Ricky" Gupta

#include <vector>
#include "assets.h"

using namespace assets;
using std::vector;

yahtzee::yahtzee(int num_dice, int sides_per_die) {
    this->num_dice = num_dice;
    this->sides_per_die = sides_per_die;
}

vector<int> yahtzee::roll_dice() {
    vector<int> rolls;
    for (int i = 0; i < this->num_dice; i++) {
        die d(this->num_dice);
        d.roll();
        rolls.insert(rolls.end(), d.get_rolled_value());
    }
    return rolls;
}
