//
// Created by Kristal Hong on 11/16/23.
//

#include "Application.h"
std::vector<GUIComponent*> Application::components;

Application::Application() {
    //
}


void Application::addComponent(GUIComponent &component) {
    components.push_back(&component);
}

void Application::run() {
    sf::RenderWindow window({1000, 800}, "Final Project");
    window.setFramerateLimit(100);
    window.clear(sf::Color::White);

    Canvas canvas({200, 220}, {800, 350});

    TextInput textInput;

    DropdownMenu dropdownMenu;
    dropdownMenu.addItem("OpenSans");
    dropdownMenu.addItem("ComicSans");
    dropdownMenu.addItem("Whisper");
    dropdownMenu.addItem("Lobster");


    dropdownMenu.setSize({200, 40});
    dropdownMenu.setPosition({745, 530});


    Menu menu1 ("Create/View");

    ///functional parameter
    menu1.addItem("Create Note", [&](const std::string& str) {
//        std::cout << str << " new Node created\n";
        textInput.disableState(HIDDEN);
    });

    Menu menu2 ("Edit");
    menu2.addItem("Highlighter", [&](const std::string& str) {
        canvas.disableState(HIDDEN);
    });

    MenuBar menuBar;
    menuBar.addMenu(menu1);
    menuBar.addMenu(menu2);
    menuBar.setMenuSize({180, 50.f});
    menuBar.setPosition({600.f, 10.f});


    FileTree testFileTree;
    testFileTree.setPosition({10, 10});


    testFileTree.pathPush("Notes/Reading.png", "file");
    testFileTree.pathPush("Notes/Text.png", "file");

    addComponent(canvas);
    addComponent(textInput);
    addComponent(dropdownMenu);
    addComponent(menuBar);
    addComponent(testFileTree);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            for (GUIComponent *&g: components) {
                g->addEventHandler(window, event);
            }
            if (KeyShortcuts::isUndo() && History::canUndo()) {
                // Handle undo action
                History::undo();
            }




//            Check if user wants to change font
            if(dropdownMenu.getString() == "OpenSans"){
                textInput.setFont(OPEN_SANS);
            } else if(dropdownMenu.getString() == "ComicSans"){
                textInput.setFont(COMIC_SANS);
            } else if(dropdownMenu.getString() == "Whisper"){
                textInput.setFont(WHISPER);
            }else if(dropdownMenu.getString() == "Lobster"){
                textInput.setFont(LOBSTER);
            }

        }

        for (GUIComponent *&g: components) {
            g->update();
        }

        window.clear(sf::Color::White);
        for (GUIComponent *&g: components) {
            window.draw(*g);
        }

        window.display();



    }
}
