#pragma once


#include <vector>
#include "GUI/Widget.hpp"
#include "Texture.hpp"

class DrumUI : public Widget
{

    std::vector<unsigned int> ExtractedBalls;

public:

    std::vector<unsigned int> ExtractNewBalls();

    void Update() override;

    void Draw() override;
};
