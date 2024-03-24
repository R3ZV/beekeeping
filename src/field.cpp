#include "game_texture.h"
#include <vector>

class Field {
    int red_flowers;
    int blue_flowers;
    int white_flowers;
    // field texture

public:
    Field(
        int red_flowers,
        int blue_flowers,
        int white_flowers
        // texture
    ) :
        red_flowers(red_flowers),
        blue_flowers(blue_flowers),
        white_flowers(white_flowers)
    {}
public:
    static std::vector<Field> all_fields(GameTexture textures) {
        std::vector<Field> fields;
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        // fields.push_back(Field(16, 8, 8, textures.get_strawberry_icon()));
        return fields;
    }
};
