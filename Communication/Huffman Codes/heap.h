#include <iostream>
using namespace std;

struct HeapNode{
    int freq;
    string data;
    HeapNode *left, *right;

    HeapNode(int Freq, string Data, HeapNode *leftChild, HeapNode *rightChild) : freq(Freq), data(Data), left(leftChild), right(rightChild) {}

    bool isLeaf();
};

class Heap{
    int currSize;
    int cap;
    HeapNode **array;

public:
    Heap(int cap){
        this->cap = cap;
        this->currSize = currSize;
        array = (struct HeapNode**)malloc(cap * sizeof(struct MinHeapNode*));
    }

    void swapNode(HeapNode *x, HeapNode *y); // Swap two Nodes   
    void Heapify(int index);                 // Heapify a binary Tree 
    int getSize(){return currSize;}          // Get current size of the heap
    HeapNode *delMin();                      // Assuming it is a min Heap
    void insert(HeapNode *newNode);          // insert new Node into heap
    void printHeap();                        // Print heap
    
};
