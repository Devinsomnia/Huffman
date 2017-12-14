//
//  main.cpp
//  Huffman2
//
//  Created by Tuncay Cansız on 14.12.2017.
//  Copyright © 2017 Tuncay Cansız. All rights reserved.
//

#include "Huffman.hpp"

int main(){
    Huffman *huffman = new Huffman("devinsomnia.txt");
    huffman->encode();
    cout<<*huffman;
    delete huffman;
    return 0;
}
