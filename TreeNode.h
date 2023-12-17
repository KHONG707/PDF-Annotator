//
// Created by Kristal Hong on 11/20/23.
//

#ifndef CS8_FILETREE_TREENODE_H
#define CS8_FILETREE_TREENODE_H
#include <string>
#include <vector>
#include <set>

//std::set - does not permit duplicate entry
struct TreeNode {
    std::string data;
//    std::vector<TreeNode*> children;
    std::set<TreeNode*> children;
};

#endif //CS8_FILETREE_TREENODE_H
