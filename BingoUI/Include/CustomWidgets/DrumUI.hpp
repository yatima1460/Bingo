#pragma once


#include <vector>
#include "GUI/Widget.hpp"
#include "Texture.hpp"

class DrumUI : public Widget
{

    std::vector<unsigned int> ExtractedBalls;

public:


    void SetBalls(const std::vector<unsigned int>& Extracted);

    void Update() override;

    void Draw() override;
};
