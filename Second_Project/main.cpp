#include <iostream>
#include <string>


struct FamilyTreeNode {
    std::string name; 
    FamilyTreeNode* parent; 
    FamilyTreeNode* leftChild; 
    FamilyTreeNode* rightChild; 


    FamilyTreeNode(std::string name) : name(name), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
};


void addChild(FamilyTreeNode* parent, FamilyTreeNode* child, bool isLeftChild) {
    if (isLeftChild) {
        parent->leftChild = child;
    } else {
        parent->rightChild = child;
    }
    child->parent = parent;
}

void printFamilyTree(FamilyTreeNode* node, int level = 0) {
    if (node != nullptr) {
        printFamilyTree(node->rightChild, level + 1);
        std::cout << std::string(level * 4, ' ') << node->name << std::endl;
        printFamilyTree(node->leftChild, level + 1);
    }
}

FamilyTreeNode* findMember(FamilyTreeNode* root, const std::string& name) {
    if (root == nullptr) {
        return nullptr; 
    }
    if (root->name == name) {
        return root; 
    }
    FamilyTreeNode* foundMember = findMember(root->leftChild, name); 
    if (foundMember == nullptr) {
        foundMember = findMember(root->rightChild, name); 
    }
    return foundMember; 
}


int main() {
    
    FamilyTreeNode* grandParent = new FamilyTreeNode("GrandParent");
    FamilyTreeNode* parent1 = new FamilyTreeNode("Parent1");
    FamilyTreeNode* parent2 = new FamilyTreeNode("Parent2");
    FamilyTreeNode* child1 = new FamilyTreeNode("Child1");
    FamilyTreeNode* child2 = new FamilyTreeNode("Child2");

    
    addChild(grandParent, parent1, true);
    addChild(grandParent, parent2, false);
    addChild(parent1, child1, true);
    addChild(parent2, child2, false);

  
    printFamilyTree(grandParent);

    std::string memberName = "Child1";

    FamilyTreeNode* member = findMember(grandParent, memberName);
    if (member != nullptr) {
        std::cout << "Member: " << member->name << std::endl;
    } else {
        std::cout << "No members found: " << memberName << std::endl;
    }

    return 0;
}