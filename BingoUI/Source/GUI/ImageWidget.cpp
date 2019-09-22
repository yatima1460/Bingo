
#include <Texture.hpp>
#include <Graphics.hpp>
#include "GUI/ImageWidget.hpp"

void ImageWidget::Draw()
{
    Graphics::DrawTexture(&texture);
}

ImageWidget::ImageWidget(Texture& texture) : texture(texture)
{

}

void ImageWidget::Update()
{

}
