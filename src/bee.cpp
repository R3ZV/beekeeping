#include "bee.h"

std::ostream &operator<<(std::ostream &out, const Bee &bee) {
    out << "Bee has type: ";
    switch (bee.type) {
    case Red:
        out << "Red";
        break;
    case Blue:
        out << "Blue";
        break;
    case White:
        out << "White";
        break;
    }

    out << std::endl;

    out << "Bee has a color multiplier of: " << bee.color_multiplier << "%"
        << std::endl;
    out << "Bee has honey_per_pollen multiplier of: " << bee.honey_per_pollen
        << "%" << std::endl;
    return out;
}

Bee::Bee(Color bee_type, uint16_t bee_color_multiplier,
         uint16_t bee_honey_per_pollen)
    : type(bee_type), color_multiplier(bee_color_multiplier),
      honey_per_pollen(bee_honey_per_pollen) {}
