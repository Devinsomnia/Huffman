//
//  Huffman.hpp
//  Huffman2
//
//  Created by Tuncay Cansız on 14.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include <fstream>
#include <cstring>

#include "Node.hpp"

class Huffman{
private:
    int letters;              // ASCII equivalents of letters
    string inputData;            // input read from file
    Node *root;

    Node* createTree(int freq[]);
    void createCode(Node*,string);
    int minNodeIndex(Node* nodes[]);
    void readFile(string)throw(string);
    void inorder(Node*);
    void deleteNode(Node*);
public:
    Huffman(string)throw(string);
    void encode();
    friend ostream& operator<<(ostream&,Huffman&);
    ~Huffman();
};

#endif /* Huffman_hpp */
