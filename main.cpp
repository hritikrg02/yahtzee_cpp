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
#include <random>
#include "assets.h"

using namespace std;

static void display_roll(vector<int> roll) {
    cout << "[ ";
    for (int r : roll) {
        cout << r << " ";
    }
    cout << "]" << endl;
}

static bool check_all_same(vector<int> roll) {
    int first = roll.front();
    for (int r : roll) {
        if (r != first) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    int num_dice = 0;
    int num_sides = 0;

    if (argc == 3) {
        num_dice = std::stoi(argv[1]);
        num_sides = std::stoi(argv[2]);
    } else {
        cout << "How many dice? ";
        cin >> num_dice;
        cout << "How many sides per die? ";
        cin >> num_sides;
        cout << endl;
    }

    srandom(time(nullptr) + 0);

    vector<int> yahtzee_roll;
    int total_rolls = 0;

    auto start_time = chrono::high_resolution_clock::now();

    while (true) {
        assets::yahtzee y(num_dice, num_sides);
        vector<int> dice_roll = y.roll_dice();
        total_rolls++;

        //display_roll(dice_roll);

        if (check_all_same(dice_roll)) {
            yahtzee_roll = dice_roll;
            break;
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration_ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    auto duration_ns = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

    std::cout << "Yahtzee rolled: ";
    display_roll(yahtzee_roll);
    cout << "Total number of rolls: " << total_rolls << endl;
    cout << "Time taken: " << duration_ms.count() << " ms" << endl;
    cout << "Average time per roll: " << duration_ns.count()/total_rolls << " ns/roll";

    return EXIT_SUCCESS;
}
