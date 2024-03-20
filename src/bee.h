#ifndef BEE_H
#define BEE_H

#include <cstdint>
#include <iostream>

enum BeeColor { Red, Blue, White };

class Bee {
    const BeeColor type;
    const short int color_multiplier;
    const short int honey_per_pollen;

    friend std::ostream &operator<<(std::ostream &out, const Bee &bee);

public:
    Bee(BeeColor bee_type, short int bee_color_multiplier,
        short int bee_honey_per_pollen);

    BeeColor get_type();
    short int get_honey_per_pollen();
    short int get_color_multiplier();
};

#endif // BEE_H
