#include "question_block.h"
#include <iostream>
#include "../world.h"

Question_Block::Question_Block(const int x, const int y, const int width, const int height):
    Block()
{
    texture.loadFromFile(getFilename(), sf::IntRect(getTextureSize() * positionInFile, 0, getTextureSize(), getTextureSize()));
    texture.setRepeated(true);
    texture.setSmooth(true);
    block.setTexture(texture);

    block.setScale(sf::Vector2f(getBlockScale(), getBlockScale()));
    
    block.setPosition(sf::Vector2f(convertInput(x), World::getHeight() - convertInput(y)));
    
    block.setTextureRect(sf::IntRect(0, 0, getTextureSize() * width, getTextureSize() * height));
} 

sf::Sprite Question_Block::getSprite() const
{
    return block;
}

float Question_Block::convertInput(const float input) const
{
    return (float)(input * getBlockScale() * texture.getSize().x);
}