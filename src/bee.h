#ifndef BEE_H
#define BEE_H

#include <cstdint>
#include <iostream>

// TODO: for static add to count how many bees have been init
enum BeeColor { Red, Blue, White };

class Bee {
    BeeColor type;
    short int color_multiplier;
    short int honey_per_pollen;
    static int created;

    friend std::ostream &operator<<(std::ostream &out, const Bee &bee);

public:
    Bee(BeeColor bee_type, short int bee_color_multiplier,
        short int bee_honey_per_pollen);

    BeeColor get_type() const;
    short int get_honey_per_pollen() const;
    short int get_color_multiplier() const;

    static void display_created();
};

#endif // BEE_H
