#ifndef BEE_H
#define BEE_H

#include <cstdint>
#include <iostream>

enum Color {
    Red,
    Blue,
    White
};

class Bee {
    const Color type;
    const uint8_t color_multiplier;
    const uint8_t honey_per_pollen;

    friend std::ostream &operator<<(std::ostream &out, const Bee &bee);

public:
    Bee(Color bee_type, uint8_t bee_color_multiplier, uint8_t bee_honey_per_pollen);
};

#endif // BEE_H
