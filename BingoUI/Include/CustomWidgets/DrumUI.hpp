#pragma once


#include <vector>
#include "GUI/Widget.hpp"
#include "Texture.hpp"

class DrumUI : public Widget
{
    Texture* ball;
    std::vector<unsigned int> extracted;

public:

    explicit DrumUI();

    void SetBalls(std::vector<unsigned int> extracted);

    void Update() override;

    void Draw() override;
};
