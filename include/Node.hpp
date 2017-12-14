//
//  Node.hpp
//  Huffman2
//
//  Created by Tuncay Cansız on 14.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp


#include <iostream>
using namespace std;

class Node{
public:
    char character;
    int frequency;
    string code;
    Node* left;
    Node* right;
    Node(char kr,int frek, Node* lt=NULL,Node *rt=NULL);
    bool isItLeaf() const;
    bool operator==(Node&);
    bool operator!=(Node&);
    bool operator>(Node&);
};

#endif /* Node_hpp */
