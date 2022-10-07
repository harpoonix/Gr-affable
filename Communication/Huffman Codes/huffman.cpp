#include "huffman.h"

int main(){

	string str = "helloFOSS_Gr-affable";
	int size = str.length();
	int freq[size];				// Array for frequency of each character
	string data;				// Compressed string
	/**
	 * Create a string 'data' such that each element of it is
	 * a character in original string 'str', uniquely. Map it with freq
	 * For example, for str = "hellofoss" -> data = "helofs" and freq = {1,1,2,2,1,2}
	 * freq[3] = 2 = frequency of character at index 3 in data, i.e. '0'
	 */

	HuffmanTree *tree = new HuffmanTree(data,freq,size);
	
    int *huffman = new int[size];
    tree->printCode(tree->root,huffman,0);
	/**
	 * Will print the huffman code for each character in given string
	 */

}

// Compile - g++ huffman.cpp
// Run 	   - ./a.out