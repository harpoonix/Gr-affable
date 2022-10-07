#include "huffman.h"

int main(){
    char arr[] = { 'h','e','l','o','f','s'};
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanTree *tree = new HuffmanTree(arr,freq,size);
	
    int *huffman = new int[size];
    tree->printCode(tree->root,huffman,0);

}

// Compile - g++ huffman.cpp
// Run 	   - ./a.out