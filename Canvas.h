//
// Created by Kristal Hong on 12/5/23.
//

#ifndef CS8_FINAL_PROJECT_CANVAS_H
#define CS8_FINAL_PROJECT_CANVAS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "GUIComponent.h"
#include "MouseEvents.h"



class Canvas : public GUIComponent
{
public:
    Canvas();
    Canvas(sf::Vector2u windowSize);
    Canvas(sf::Vector2f canvasPosition, sf::Vector2f canvasSize);

    Canvas(sf::RenderWindow& window);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void update();

    void setSize(sf::Vector2f size);
    void setOrigin(float x, float y);

    sf::Vector2f getCanvasSize() const;

    Snapshot getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

private:
    sf::RenderTexture canvas;
    sf::Sprite sprite;
    sf::Sprite importedImage;


    sf::RectangleShape brush;
    sf::RectangleShape drawArea;


    const std::vector<sf::Color> colors = {
            sf::Color(255, 0, 0, 20),
            sf::Color(255, 255, 0, 20),
            sf::Color(0, 255, 0, 20),
            sf::Color(0, 255, 255, 20),
            sf::Color(0, 0, 255, 20),
            sf::Color(255, 0, 255, 20),
            sf::Color(0, 0, 0, 20),
            sf::Color(255, 255, 255, 255),
    };

    sf::Vector2f lastPos;
    bool isDrawing = false;
    unsigned int color = 0;


    void clearCanvas();
    void changeColor(bool forward);
};


#endif //CS8_FINAL_PROJECT_CANVAS_H
