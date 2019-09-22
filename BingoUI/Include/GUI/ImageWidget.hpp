


#pragma once


#include "GUI/Widget.hpp"


class ImageWidget : public Widget
{

    Texture& texture;

public:

    explicit ImageWidget(Texture& texture);

    void Draw() override;

    void Update() override;
};