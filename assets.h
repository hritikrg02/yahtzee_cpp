/// @file       assets.h
/// @date       01/11/2021
/// @details    Provides the class declarations for the yahtzee program.
///
/// @author     Hritik "Ricky" Gupta

#ifndef YAHTZEE_ASSETS_H
#define YAHTZEE_ASSETS_H

#include <iostream>

using std::vector;

namespace assets {

    class die {
    private:
        int rolled_value;
        int num_sides;
    public:
        die(int num_sides);
        void roll();
        int get_rolled_value();
    };

    class yahtzee {
    private:
        int num_dice;
        int sides_per_die;
    public:
        yahtzee(int num_dice, int sides_per_die);
        std::vector<int> roll_dice();
    };
}

#endif //YAHTZEE_ASSETS_H
