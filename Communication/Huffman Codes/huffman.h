#include"heap.cpp"


Heap *createHeap(string data, int freq[], int size){

    // Create a Heap storing data with frequency freq and given size 
    // data : array of character, whose elements are to be stored at Nodes
    // freq : array of frequency of each character
    // size : the size of the heap to be created
    Heap *heap = new Heap(size);

    return heap;
}
class HuffmanTree{
public:
    struct HeapNode* root;

    HuffmanTree(){
        root = nullptr;
    }

    // Create a HuffmanTree for given data, freq, and size
    HuffmanTree(string data, int freq[], int size){
        Heap *heap = createHeap(data,freq,size);
        /**
         * Idea is to utilize heap for accessing element with 
         * minimum freq in O(1) time, then get two nodes with 
         * minimum freq from the heap and insert a new Node
         * made by combining these two lowest freq nodes into Huffman Tree.
         * The heap created above will become an Huffman Tree.
         * You will have to modify print function below a little bit
         * to assign code of '0' or '1' to new Huffman tree you have
         */
    }

    void printCode(HeapNode* node, int arr[], int top){
        if (node->left != nullptr) {
            arr[top] = 0;
		    printCode(node->left, arr, top + 1);
	    }

	    if (root->right) {
            // Assign 1 to right and do recursive call
	    }

	    if (node->isLeaf()) {
            // A leaf node contains the characters
            // So print it from the array arr[]
		    cout<< root->data <<": ";
		    for(int i = 0; i < top; i++){
                cout << arr[i];
            }
            cout << endl;
	    }
    }
};