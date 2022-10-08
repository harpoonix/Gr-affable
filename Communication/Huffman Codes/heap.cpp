#include "heap.h"
#include <cassert>

bool HeapNode::isLeaf(){
    /**
     * Check if a node is leaf
     * 
     */
    return false;
}

void Heap::swapNode(HeapNode *x, HeapNode *y){    
    /**
     * swap two Nodes
     * 
     */
    HeapNode* temp = x;
    x = y;
    y = temp;
}

void Heap::Heapify(int Index){
    /**
     * Implement Heapify function that ensures
     * the Heap properties are maintained
     * and Re-establishes the heap conditions
     * if they are violated somewhere
     */
}

HeapNode *Heap::delMin(){
    /**
     * Delete the top element (minimum here)
     * from the heap, ensure that this function 
     * works correctly as desired
     */
    if(currSize > 0){
        HeapNode *temp = array[0];
        if(currSize == 1){
            array[currSize] = nullptr;
        }
        else{
            array[currSize] = 0;
            array[0] = array[currSize];
            Heapify(0);
        }
        return temp;
    }
    else return nullptr;
}

void Heap::insert(HeapNode *newNode){
    if(currSize == cap){
        assert("Max Capacity of array reached!");
    }
    else{
        array[currSize] = newNode;
        int i = currSize;
        currSize++;
        while(i && array[(i-1)/2]->freq > array[i]->freq){
            swapNode(array[i],array[(i-1)/2]);
            i = (i-1)/2;
        }
    }
}


void Heap::printHeap(){

    // Print the Heap in a suitable way as you like

}


