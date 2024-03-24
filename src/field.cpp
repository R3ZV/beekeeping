#include "field.h"
std::ostream &operator<<(std::ostream& out, const Field& field) {
    out << "Red flowers: " << field.red_flowers;
    out << "\n";
    out << "Blue flowers: " << field.blue_flowers;
    out << "\n";
    out << "White flowers: " << field.white_flowers;
    return out;
}

Field::Field(
    int red_flowers,
    int blue_flowers,
    int white_flowers,
    Texture2D field
) :
    red_flowers(red_flowers),
    blue_flowers(blue_flowers),
    white_flowers(white_flowers),
    field(field)
{}

Field::~Field() {
    red_flowers = 0;
    blue_flowers = 0;
    white_flowers = 0;
}

Field::Field(const Field& other) {
    red_flowers = other.red_flowers;
    blue_flowers = other.blue_flowers;
    white_flowers = other.white_flowers;
    field = other.field;
}

Field& Field::operator=(const Field& other) {
    if (this != &other) {
        red_flowers = other.red_flowers;
        blue_flowers = other.blue_flowers;
        white_flowers = other.white_flowers;
        field = other.field;
    }
    return *this;
}

std::vector<Field> Field::all_fields(std::shared_ptr<AssetManager> textures) {
    std::vector<Field> fields;
    fields.push_back(Field(27, 0, 5, textures->get_strawberry_field()));
    fields.push_back(Field(4, 4, 24, textures->get_sunflower_field()));
    fields.push_back(Field(10, 10, 12, textures->get_clover_field()));
    fields.push_back(Field(16, 16, 0, textures->get_cactus_field()));
    fields.push_back(Field(22, 0, 10, textures->get_cherry_field()));
    fields.push_back(Field(6, 0, 26, textures->get_orange_field()));
    fields.push_back(Field(26, 0, 6, textures->get_blueberry_field()));
    return fields;
}

Texture2D Field::get_field() const {
    return field;
}

int Field::get_red_flowers() const {
    return red_flowers;
}

int Field::get_blue_flowers() const {
    return blue_flowers;
}

int Field::get_white_flowers() const {
    return white_flowers;
}
