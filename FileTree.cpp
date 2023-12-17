//
// Created by Kristal Hong on 11/21/23.
//

#include "FileTree.h"
#include "AppHandler/AppHandler.h"


FileTree::FileTree() {
    root = new FileNode;
}

void FileTree::setPosition(const sf::Vector2f& position) {
    root->getData().setPosition(position);
}

void FileTree::push(std::string parent, std::string item, const std::string type) {
    push(root, parent, item, type);
}

void FileTree::pushPathFinal(FileNode *parent, FileNode *child) {
    parent->getChildren().insert({child->getData().getTextString(), child});
}

void FileTree::pathPush(const std::string &path, const std::string &typeNode) {
    std::string pathCopy = path;
    if(path.empty()) {
        return;
    }

    if (!root) {
        std::string level = getNextInPath(pathCopy);
        root = createNode(level, typeNode);
//        FileNode *p = root;
        fillingMissingDirectories(root, level, path);
    } else {
        FileNode* current = root;
        std::string level = getNextInPath(pathCopy); //get first directory
        if (level != root->getData().getTextString()) {
            std::cout << "Invalid first";
            return;
        }
        //while directories remaining in pathCOpy
        while (level != pathCopy) {
            level = getNextInPath(pathCopy);
            FileNode* match = find(current, level);


            if (match == nullptr) {
                match = createNode(level, typeNode);
                pushPathFinal(current, match);
            }
            current = match;
        }


    }
}




void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}




void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root, window, event);
        FileNode* node = getSelectedNode(root);
        currentSelectedString(node);
        if(node) {
            node->disableState(SELECTED);
            updateDisplayedImage(node);
        }

}





void FileTree::update() {
    repositionTree();
}

Snapshot FileTree::getSnapshot() {
    //
}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    //
}

sf::FloatRect FileTree::getGlobalBounds() {
    //
}





void FileTree::push(FileNode *&root, std::string parent, std::string item, const std::string& type) {
    if (root->getData().getTextString() == parent) {
        FileNode* freshFileNode = createNode(item, type);
        root->getChildren().insert({item, freshFileNode});

    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
}

void FileTree::fillingMissingDirectories(FileNode *p, std::string path, std::string fullPath) {
    path = getNextInPath(fullPath);

    while (path != fullPath) {
        path = getNextInPath(fullPath);
        FileNode* t = createNode(path, "");
        pushPathFinal(p, t);
        p = t;
//        p = find (p, path);
    }
}


std::string FileTree::getNextInPath(std::string& path) {
    int idx = path.find('/');
//    std::cout << "index: " << idx << std::endl;
    std::string s = path.substr(0, idx);
    path = path.substr(idx+1);
    return s;
}


FileNode* FileTree::find(FileNode *parent, std::string data) {
    if (parent) {
        for (auto i = parent->getChildren().begin(); i != parent->getChildren().end(); ++i) {
            if (i->second->getData().getTextString() == data)
                return i->second;
        }
    }
    return nullptr;
}

FileNode* FileTree::createNode(const std::string &name, const std::string& typeNode) {
    auto tempFileNode = new FileNode;
    tempFileNode->getData().setItemName(name);
    if (typeNode == "folder")
        tempFileNode->getData().setIcon("Images/FolderIcon.png");
    else if (typeNode == "file")
        tempFileNode->getData().setIcon("Images/TextIcon.png");
    return tempFileNode;
}

void FileTree::repositionTree() {
    root->reposition();
}











void FileTree::currentSelectedString(FileNode* node) {
    if(node) {
        selectedString = node->getData().getTextString();
    }
}


FileNode* FileTree::getSelectedNode(FileNode* node) {
    if (node) {
        if (node->checkState(SELECTED)) {
            selectedString = node->getData().getTextString();
            return node;
        } else {
            for (const auto& child : node->getChildren()) {
                FileNode* result = getSelectedNode(child.second);
                if (result) {
                    return result;  // Return the first non-empty selected string
                }
            }
        }
    }
    return nullptr;
}

FileNode* FileTree::updateDisplayedImage(FileNode* node) {


    if(node->getData().getTextString() == "Reading.png") {
        node->getData().setPNGImage("Notes/img.png");
    }

    if(node->getData().getTextString() == "Text.png") {
        node->getData().setPNGImage("Notes/theText.png");

    }

}
