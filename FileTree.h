//
// Created by Kristal Hong on 11/21/23.
//

#ifndef CS8_FILETREE_FILETREE_H
#define CS8_FILETREE_FILETREE_H
#include "FileNode.h"
#include "GUIComponent.h"
#include "Snapshot.h"
#include "TreeNode.h"


class FileTree : public GUIComponent
{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, const std::string& typeNode);

    void pushPathFinal(FileNode* parent, FileNode* child);

    FileNode* createNode(const std::string& name, const std::string& typeNode);
    std::string getNextInPath(std::string& path);

    void repositionTree();


    //traverses the tree and adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};


    FileNode* find(FileNode *parent, std::string data);

    void drawNode(sf::RenderTarget& window, const TreeNode* node, sf::Vector2f position) const;


    void fillingMissingDirectories(FileNode *p, std::string path, std::string fullPath);


    std::string selectedString;


    FileItem* lastDoubleClickedItem;
    sf::Texture displayedTexture;  // Texture for the displayed image
    sf::Sprite displayedImage;     // Sprite for the displayed image
public:
    //constructors
    FileTree();

    //this is the public version of push
    void push(std::string parent, std::string item = "NULL", const std::string typeNode = "folder");
    void pathPush(const std::string& path, const std::string& typeNode = "folder");


    void setPosition(const sf::Vector2f& position);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot getSnapshot();
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();



    FileNode* getSelectedNode(FileNode* node);
//    void updateDisplayedImage();
    FileNode* updateDisplayedImage(FileNode* node);
    void currentSelectedString(FileNode* node);

};

#endif //CS8_FILETREE_FILETREE_H
