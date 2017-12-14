//
//  Huffman.cpp
//  Huffman2
//
//  Created by Tuncay Cansız on 14.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#include "Huffman.hpp"


Huffman::Huffman(string filePath)throw(string){
    letters = 256;
    inputData="";
    try{
        readFile(filePath);
    }
    catch(string ex){
        throw ex;
    }
    root=NULL;
}
void Huffman::readFile(string filePath)throw(string){
    string line;
    ifstream file(filePath.c_str());
    if (file.is_open())
    {
        while (getline(file,line))
        {
            inputData+=line;
            inputData+='\n';
        }
        file.close();
    }
    else throw "file failed to open";
}
void Huffman::encode(){
    char characters[inputData.size()-1];

    strcpy(characters, inputData.c_str());

    //Frekanslarý say
    int freq[letters];
    // frekanslarý sýfýrla
    for(int i=0;i<letters;i++)freq[i] = 0;

    for (int i = 0; i < inputData.size()-1; i++)
        freq[characters[i]]++;

    // create huffman tree
    root = createTree(freq);

    // coding
    createCode(root, "");
}
Node* Huffman::createTree(int freq[]){
    // dosyada var olan karakterler için düðüm oluþtur.
    Node* nodes[letters];
    for(int i=0;i<letters;i++){
        if(freq[i]>0){
            nodes[i] = new Node((char)i,freq[i]);
        }
        else{
            nodes[i] = NULL;
        }
    }
    while(true){
        int firsIndex = minNodeIndex(nodes);
        Node *min1 = nodes[firsIndex];
        nodes[firsIndex] = NULL;
        int secondIndex = minNodeIndex(nodes);
        if(secondIndex == -1){
            return min1;
        }
        Node *min2 = nodes[secondIndex];
        nodes[secondIndex] = NULL;
        nodes[secondIndex] = new Node(0,min1->frequency + min2->frequency ,min1,min2);
    }

}
int Huffman::minNodeIndex(Node* nodes[]){
    Node* min = nullptr;
    int minIndeks=-1;

    // take the first non-empty node as a minimum
    for(int i=0;i<letters;i++){
        if(nodes[i] != NULL){
            min = nodes[i];
            minIndeks = i;
            break;
        }
    }

    for(int i=0;i<letters;i++)
    {
        if(nodes[i] == NULL) continue;

        if(*min > *(nodes[i])) {
            min = nodes[i];
            minIndeks = i;
        }
    }
    return minIndeks;
}
void Huffman::createCode(Node* subNode,string code){
    if(!subNode->isItLeaf()){
        createCode(subNode->left,code+'0');
        createCode(subNode->right,code+'1');
    }
    else{
        subNode->code = code;
    }
}
ostream& operator<<(ostream& screen,Huffman& right){
    screen<<"Characters and Codes in the Huffman Tree: "<<endl;
    right.inorder(right.root);
    return screen;
}
void Huffman::inorder(Node* subNode){
    if(subNode != NULL){
        inorder(subNode->left);
        if(subNode->isItLeaf()) cout<<subNode->character<<":"<<subNode->code<<endl;
        inorder(subNode->right);
    }
}
void Huffman::deleteNode(Node* subNode){
    if(subNode == NULL) return;
    deleteNode(subNode->left);
    deleteNode(subNode->right);
    delete subNode;
    subNode = NULL;
}
Huffman::~Huffman(){
    // The tree is being cleaned so that no trash is formed.
    deleteNode(root);
}
