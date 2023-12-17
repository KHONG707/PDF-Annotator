//
// Created by Kristal Hong on 12/5/23.
//

#include "Canvas.h"
#include "AppHandler/AppHandler.h"
//
//Canvas::Canvas() {
//
//    setSize({50, 30});
//
//    setOrigin(27, 17);
//    brush.setFillColor(colors[color]);
//}
//
//Canvas::Canvas(sf::Vector2f canvasPosition, sf::Vector2f canvasSize) {
//    canvas.create(800, 600);
//    canvas.clear(sf::Color::White);
//
//
//    sprite.setTexture(canvas.getTexture(), true);
//
//
//    brush.setOrigin(27, 17);
//    brush.setFillColor(colors[color]);
//
//
//
//
////
////
////    canvas.create(canvasSize.x, canvasSize.y);
////    sprite.setPosition(canvasSize.x, canvasSize.y);
////
////    brush.setSize({50, 30});
////    brush.setOrigin(27, 17);
////    brush.setFillColor(colors[color]);
////
////    brush.setPosition(canvasPosition);
////
////    // You may need to adjust the scale depending on your needs
//////    brush.setScale(canvasSize.x / brush.getSize().x, canvasSize.y / brush.getSize().y);
////
////    // Set the drawing area to be the same as the canvas
////    drawArea.setFillColor(sf::Color::White);
////    drawArea.setSize(canvasSize);
////    drawArea.setPosition(canvasPosition);
//////    drawArea.setFillColor(sf::Color::Transparent);
////    drawArea.setOutlineThickness(2.f);
////    drawArea.setOutlineColor(sf::Color::White);
////
////
////
//////    canvas.setPosition(canvasPosition);
////    sprite.setTexture(canvas.getTexture(), true);
//}
////Canvas::Canvas(sf::Vector2f position, sf::Vector2f size) {
////    setSize(size);
////    setOrigin(size.x / 2, size.y / 2);  // Center the origin
////    setPosition(position);
////    brush.setFillColor(colors[color]);
////}
//
//void Canvas::update() {
//    //
//}
//
//
//void Canvas::draw(sf::RenderTarget &window, sf::RenderStates states) const {
////    window.draw(sprite, states);
//    window.draw(drawArea);
//    window.draw(sprite, states);
//    window.draw(brush);
//}
//
//
//void Canvas::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    switch (event.type) {
//        case sf::Event::Closed:
//            window.close();
//            break;
//        case sf::Event::KeyPressed:
//            switch (event.key.code) {
//                case sf::Keyboard::C:
//                    // Clear our canvas
//                    canvas.clear(sf::Color::White);
//                    canvas.display();
//                    break;
//                case sf::Keyboard::R:
//                    // Get next color
//                    color = (color + 1) % colors.size();
//                    // Apply it
//                    brush.setFillColor(colors[color]);
//                    break;
//                case sf::Keyboard::L:
//                    // Get previous color
//                    color = (color - 1) % colors.size();
//                    // Apply it
//                    brush.setFillColor(colors[color]);
//                    break;
//            }
//            break;
//        case sf::Event::Resized:
//        {
//            // Window got resized, update the view to the new size
//            sf::View view(window.getView());
//            const sf::Vector2f size(window.getSize().x, window.getSize().y);
//            view.setSize(size); // Set the size
//            view.setCenter(size / 2.f); // Set the center, moving our drawing to the top left
//            window.setView(view); // Apply the view
//            break;
//        }
//        case sf::Event::MouseButtonPressed:
//            // Only care for the left button
//            if (MouseEvents::isClicked(drawArea, window)) {
//                isDrawing = true;
//                // Store the cursor position relative to the canvas
//                lastPos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
//
//                // Now let's draw our brush once, so we can
//                // draw dots without actually draging the mouse
//                brush.setPosition(lastPos);
//
//                // Draw our "brush"
//                canvas.draw(brush);
//
////                std::cout << "Draw\n";
//                // Finalize the texture
//                canvas.display();
//            }
//            break;
//        case sf::Event::MouseButtonReleased:
//            // Only care for the left button
//            if (event.mouseButton.button == sf::Mouse::Left)
//                isDrawing = false;
//            break;
//        case sf::Event::MouseMoved:
//            if (isDrawing)
//            {
//                // Calculate the cursor position relative to the canvas
//                const sf::Vector2f newPos(window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)));
//
//                // I'm only using the new position here
//                // but you could also use `lastPos` to draw a
//                // line or rectangle instead
//                brush.setPosition(newPos);
//
//                // Draw our "brush"
//                canvas.draw(brush);
//
//                // Finalize the texture
//                canvas.display();
//                break;
//            }
//    }
//}
//
////void Canvas::addEventHandler(sf::RenderWindow &window, sf::Event event) {
////    switch (event.type) {
//////        case sf::Event::Closed:
//////            window.close();
//////            break;
////        case sf::Event::KeyPressed:
////            switch (event.key.code) {
////                case sf::Keyboard::C:
////                    // Clear our canvas
////                    window.clear(sf::Color::White);
////                    window.display();
////                    break;
////                case sf::Keyboard::Right:
////                    // Get next color
////                    color = (color + 1) % colors.size();
////                    // Apply it
////                    brush.setFillColor(colors[color]);
////                    break;
////                case sf::Keyboard::Left:
////                    // Get previous color
////                    color = (color - 1) % colors.size();
////                    // Apply it
////                    brush.setFillColor(colors[color]);
////                    break;
////            }
////            break;
////        case sf::Event::Resized:
////        {
////            // Window got resized, update the view to the new size
////            sf::View view(window.getView());
////            const sf::Vector2f size(window.getSize().x, window.getSize().y);
////            view.setSize(size); // Set the size
////            view.setCenter(size / 2.f); // Set the center, moving our drawing to the top left
////            window.setView(view); // Apply the view
////            break;
////        }
////        case sf::Event::MouseButtonPressed:
////            // Only care for the left button
////            if (MouseEvents::mouseClicked(window, event)) {
////                isDrawing = true;
////                // Store the cursor position relative to the canvas
////                lastPos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
////
////                // Now let's draw our brush once, so we can
////                // draw dots without actually draging the mouse
////                brush.setPosition(lastPos);
////
////                // Draw our "brush"
////                window.draw(brush);
////
////                // Finalize the texture
////                window.display();
////            }
////            break;
////        case sf::Event::MouseButtonReleased:
////            // Only care for the left button
////            if (event.mouseButton.button == sf::Mouse::Left)
////                isDrawing = false;
////            break;
////        case sf::Event::MouseMoved:
////            if (isDrawing)
////            {
////                // Calculate the cursor position relative to the canvas
////                const sf::Vector2f newPos(window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)));
////
////                // I'm only using the new position here
////                // but you could also use `lastPos` to draw a
////                // line or rectangle instead
////                brush.setPosition(newPos);
////
////                // Draw our "brush"
////                window.draw(brush);
////
////                // Finalize the texture
////                window.display();
////                break;
////            }
////    }
////}
//
//
//void Canvas::setSize(sf::Vector2f size) {
//    brush.setSize(size);
//    //size = {50, 30}
//}
//
//
//void Canvas::setOrigin(float x, float y) {
//    brush.setOrigin(x, y);
//}
//
//
//Snapshot Canvas::getSnapshot() {
//    //
//}
//
//
//void Canvas::applySnapshot(const Snapshot& snapshot) {
//    //
//}
//
//void Canvas::clearCanvas() {
//    canvas.clear(sf::Color::White);
//}
//
//void Canvas::changeColor(bool forward) {
//    color = (forward) ? (color + 1) % colors.size() : (color - 1) % colors.size();
//    brush.setFillColor(colors[color]);
//}

//Canvas::Canvas(sf::Vector2u windowSize) {
//    canvas.create(800, 600);
//    canvas.clear(sf::Color::White);
//
//
//    sprite.setPosition((windowSize.x - canvas.getSize().x) / 2.f, (windowSize.y - canvas.getSize().y) / 2.f);
//    sprite.setTexture(canvas.getTexture(), true);
//
//    brush.setSize({50, 30});
//    brush.setOrigin(27, 17); // Center on the brush's center
//    brush.setFillColor(colors[color]);
//}

Canvas::Canvas(sf::Vector2f canvasPosition, sf::Vector2f canvasSize) {
    canvas.create(canvasSize.x, canvasSize.y);
    canvas.clear(sf::Color::Transparent);

    sprite.setTexture(canvas.getTexture(), true);

    sprite.setPosition((canvasPosition.x - getCanvasSize().x) / 2.f, (canvasPosition.y - getCanvasSize().y) / 2.f);

    brush.setSize({50, 30});
    brush.setOrigin(27, 17);  // Center on the brush's center
    brush.setFillColor(colors[color]);

    drawArea.setFillColor(sf::Color::Transparent);
    drawArea.setSize({canvasSize.x, canvasSize.y});
    drawArea.setPosition(sprite.getPosition());
    drawArea.setOutlineThickness(2.f);
    drawArea.setOutlineColor(sf::Color::Black);

    enableState(HIDDEN);

//    setPosition((canvasPosition.x - getCanvasSize().x) / 2.f, (canvasPosition.y - getCanvasSize().y) / 2.f);
}

//Canvas::Canvas(sf::RenderWindow& window) : window(window) {
//
//    canvas.create(800, 600);
//    canvas.clear(sf::Color::White);
//
//
//    // Set the position of the sprite to center it in the window
//    sf::Vector2u windowSize = window.getSize();
//    sprite.setPosition((windowSize.x - canvas.getSize().x) / 2.f, (windowSize.y - canvas.getSize().y) / 2.f);
//
//
//    sprite.setTexture(canvas.getTexture(), true);
//
//    brush.setSize({50, 30});
//    brush.setOrigin(27, 17); // Center on the brush's center
//    brush.setFillColor(colors[color]);
//}



void Canvas::update() {
    //

    //store the local sprite from the
    //
     if(AppHandler::isHasSprite()){
         importedImage = AppHandler::getSprite();
     }

}

void Canvas::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    if(AppHandler::isHasSprite()) {
        window.draw(importedImage, states);
    }

    window.draw(sprite, states);

    window.draw(drawArea, states);

}


void Canvas::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code) {
                case sf::Keyboard::R:
                    // Get next color
                    color = (color + 1) % colors.size();
                    // Apply it
                    brush.setFillColor(colors[color]);
                    break;
                case sf::Keyboard::L:
                    // Get previous color
                    color = (color - 1 + colors.size()) % colors.size();
                    // Apply it
                    brush.setFillColor(colors[color]);
                    break;
            }
            break;
        case sf::Event::MouseButtonPressed:
            // Only care for the left button
            if (event.mouseButton.button == sf::Mouse::Left) {
                isDrawing = true;


                lastPos = (sf::Vector2f) sf::Mouse::getPosition(window);

                brush.setPosition(lastPos - sprite.getPosition());


                if(!checkState(HIDDEN)) {
                    canvas.draw(brush);
                }

            }
            break;
        case sf::Event::MouseButtonReleased:

            if (event.mouseButton.button == sf::Mouse::Left)
                isDrawing = false;
            break;
        case sf::Event::MouseMoved:
            if (isDrawing) {

                sf::Vector2i newPos = sf::Mouse::getPosition(window);

                brush.setPosition(static_cast<sf::Vector2f>(newPos) - sprite.getPosition());

                if (!checkState(HIDDEN)){
                    canvas.draw(brush);
                }


                canvas.display();
            }
            break;
    }
}


void Canvas::setSize(sf::Vector2f size) {
    brush.setSize(size);
    drawArea.setFillColor(sf::Color::White);
    drawArea.setSize(size);
}

void Canvas::setOrigin(float x, float y) {
    brush.setOrigin(x, y);
}

Snapshot Canvas::getSnapshot() {
    //
}

void Canvas::applySnapshot(const Snapshot &snapshot) {
    //
}

void Canvas::clearCanvas() {
    canvas.clear(sf::Color::White);
    canvas.display();
}

void Canvas::changeColor(bool forward) {
    color = (forward) ? (color + 1) % colors.size() : (color - 1 + colors.size()) % colors.size();
    brush.setFillColor(colors[color]);
}

sf::Vector2f Canvas::getCanvasSize() const {
    return drawArea.getSize();
}