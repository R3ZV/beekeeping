#ifndef BEE_H
#define BEE_H

#include <cstdint>
#include <iostream>

enum Color { Red, Blue, White };

class Bee {
    const Color type;
    const uint16_t color_multiplier;
    const uint16_t honey_per_pollen;

    friend std::ostream &operator<<(std::ostream &out, const Bee &bee);

public:
    Bee(Color bee_type, uint16_t bee_color_multiplier,
        uint16_t bee_honey_per_pollen);
};

#endif // BEE_H
