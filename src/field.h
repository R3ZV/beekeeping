#ifndef FIELD_H
#define FIELD_H

#include "asset_manager.h"

#include <iostream>
#include <memory>
#include <raylib.h>
#include <vector>

class Field {
    int red_flowers;
    int blue_flowers;
    int white_flowers;
    Texture2D field;

    Field(
        int red_flowers,
        int blue_flowers,
        int white_flowers,
        Texture2D field
    );

public:
    friend std::ostream &operator<<(std::ostream& out, const Field& field);
    ~Field();
    static std::vector<Field> all_fields(std::shared_ptr<AssetManager> textures);
    Field(const Field& other);
    Field& operator=(const Field& other);

    Texture2D get_field() const;
    int get_red_flowers() const;
    int get_blue_flowers() const;
    int get_white_flowers() const;
};
#endif // FIELD_H
