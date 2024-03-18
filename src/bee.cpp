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

Bee::Bee(
    BeeColor type,
    short int color_multiplier,
    short int honey_per_pollen
) :
    type(type),
    color_multiplier(color_multiplier),
    honey_per_pollen(honey_per_pollen)
{}

BeeColor Bee::get_type() {
    return type;
}
