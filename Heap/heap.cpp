/*
In this C++ Program we implement the Min and Max heaps from scratch

Heap is a full-binary tree. A full binary tree can be effeciently implemented as an array.
So the root node of the heap is the first element which is followed by the it's left and right
children respectively and so on for all the other nodes. To implement this we need to define a
relationship between the 'index' of a node and the 'index of it's parent', 'index of it's left child' and
'index of it's right child'. The relationship is given as:
1: index of parent = (index-1)/2
2: index of left child: 2*index + 1
3: index of right child: 2*index + 2

Here we implement a wrapper class around an array(vector) to implement a MinHeap.
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class MinHeap{
    private:
    int size = 0;
    int capacity = 10;
    std::vector<int> array;

    // Utility functions
    int getLeftChildIndex(int parentIndex){return (2*parentIndex+1);}
    int getRightChildIndex(int parentIndex){return (2*parentIndex+2);}
    int getParentIndex(int childIndex){return ((childIndex-1)/2);}
    bool hasLeftChild(int parentIndex){return getLeftChildIndex(parentIndex) < array.size();}
    bool hasRightChild(int parentIndex){return getRightChildIndex(parentIndex) < array.size();}
    bool hasParent(int childIndex){return getParentIndex(childIndex) >= 0;}
    int getLeftChild(int parentIndex){return array[getLeftChildIndex(parentIndex)];}
    int getRightChild(int parentIndex){return array[getRightChildIndex(parentIndex)];}
    int getParent(int childIndex){return array[getParentIndex(childIndex)];}

    public:
   
    MinHeap()
    {
        array = std::vector<int>(capacity,1000);
    }


    // heapifyUp: Bubble up the value in the heap to it's right position
    void heapifyUp()
    {
        int index = size - 1;
        while(hasParent(index) && getParent(index) > array[index])
        {
            std::swap(array[index], array[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }


    // heapifyDown: Bubble down the value to it's right position
    void heapifyDown()
    {
        int index = 0;
        while(hasLeftChild(index) == true)
        {
            int smallestChildIdx = getLeftChildIndex(index);
            if(hasRightChild(index) && getRightChild(index) < getLeftChild(index)) smallestChildIdx = getRightChildIndex(index);
            if(array[index] > array[smallestChildIdx])
            {
                std::swap(array[index], array[smallestChildIdx]);
                index = smallestChildIdx;
            }
            else break;
        }
    }


    // Peek: Return the top of the MinHeap. Note: The heap is NOT modifed.
    int peek()
    {
        // Sanity Check: Empty Heap
        if(array.empty()) return -100;
        // Return the top of the Heap
        std::cout<<"Peeking Top of Heap"<<std::endl;
        return array[0];
    }


    // getMin: Return the top of the heap and reheapify.
    int getMin()
    {
        if(size == 0) return -100;
        int top = array[0];
        array[0] = array[size-1];
        size--;
        heapifyDown();
        std::cout<<"Returning Top of Heap"<<std::endl;
        return top;
    }


    // add: Add a new value to the heap
    void add(int value)
    {
        array[size] = value;
        size++;
        heapifyUp();
    }
};

int main(int argc, char const *argv[])
{
    MinHeap obj;
    obj.add(3);
    obj.add(4);
    obj.add(8);
    obj.add(9);
    obj.add(7);
    obj.add(10);
    obj.add(15);
    obj.add(20);
   
    std::cout<<obj.getMin()<<std::endl;

    std::cout<<obj.getMin()<<std::endl;
 
    std::cout<<obj.getMin()<<std::endl;

    obj.add(0);
  
    std::cout<<obj.getMin()<<std::endl;
   
    std::cout<<obj.getMin()<<std::endl;

    std::cout<<obj.getMin()<<std::endl;
    return 0;
}