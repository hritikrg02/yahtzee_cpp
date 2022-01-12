/// @file       main.cpp
/// @date       01/11/2021
/// @details    Contains the main function of the program, which is a
///             C++ implementation of a simple yahtzee rolling game,
///             in which a user inputs a number of dice and the sides per
///             die, and the machine rolls until every die rolled lands on
///             the same number, at the same time.
///
/// @author     Hritik "Ricky" Gupta

#include <sstream>
#include <cstdlib>
#include <vector>
#include "assets.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return EXIT_FAILURE;
    }

    srand(time(nullptr) + 0);
    vector<int> yahtzee_roll;

    int total_rolls = 0;
    int num_dice = 0;
    int num_sides = 0;

    stringstream dice_arg(argv[1]);
    dice_arg >> num_dice;
    stringstream sides_arg(argv[2]);
    sides_arg >> num_sides;

    while (true) {
        assets::yahtzee y(num_dice, num_sides);
        vector<int> dice_roll = y.roll_dice();

        if (std::adjacent_find(dice_roll.begin(), dice_roll.end(), std::not_equal_to<>()) == dice_roll.end()) {
            yahtzee_roll = dice_roll;
            break;
        }

        total_rolls++;
    }

    std::cout << "Yahtzee rolled: [ ";
    for (int r : yahtzee_roll) {
        std::cout << r << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Total number of rolls: " << total_rolls << std::endl;
}