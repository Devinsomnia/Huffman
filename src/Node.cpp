//
//  Node.cpp
//  Huffman2
//
//  Created by Tuncay Cansız on 14.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#include "Node.hpp"


Node::Node(char chrter,int frek, Node* lt,Node *rt){
    character=chrter;
    frequency=frek;
    left=lt;
    right=rt;
    code="";
}
bool Node::isItLeaf() const{
    if(left == NULL && right == NULL) return true;
    return false;
}
bool Node::operator==(Node& right){
    if(this->character == right.character) return true;
    else return false;
}
bool Node::operator!=(Node& right){
    if(this->character != right.character) return true;
    else return false;
}
bool Node::operator>(Node& right){
    if(this->frequency > right.frequency) return true;
    else return false;
}
