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
#include <climits>

class MinHeap{
    private:
    int capacity;
    int size;
    std::vector<int> array;


    // Heap Utility functions
    bool hasLeftChild(int parentIdx){return (2*parentIdx + 1 < array.size());}
    bool hasRightChild(int parentIdx){return (2*parentIdx + 2 < array.size());}
    bool hasParent(int childIdx){ return ((childIdx-1)/2 >=0 );}
    int getLeftChildIdx(int parentIdx){ return (2*parentIdx + 1);}
    int getRightChildIdx(int parentIdx){ return (2*parentIdx + 2);}
    int getParentIdx(int childIdx){ return ((childIdx-1)/2);}
    int getLeftChild(int parentIdx){ return array[getLeftChildIdx(parentIdx)];}
    int getRightChild(int parentIdx){ return array[getLeftChildIdx(parentIdx)];}
    int getParent(int childIdx){ return array[getParentIdx(childIdx)];}

    /* 
    ensureExtraCapacity: If we run out of heap space then this function makes a new heap of 2*size as before and
    copies the old heap onto the new heap, so that we can add a new element.
    */


   void ensureExtraCapacity()
   {
       if(size == capacity)
       {
        std::vector<int> new_array(2*capacity,INT_MAX);
        std::copy(array.begin(), array.end(), new_array.begin());
        capacity = 2*capacity;
        array = new_array;
       }
   }
   
   
   // heapifyUp: Move a newly inserted element to its correct position in the heap
   void heapifyUp()
   {
       int index = size - 1;
       while(hasParent(index) && array[index] < getParent(index))
       {
           std::swap(array[index], array[getParentIdx(index)]);
           index = getParentIdx(index);  
       }
   }


   // heapifyDown: Move the newly replaced top element in the getMin function to its right position
   void heapifyDown()
   {
       int index = 0;
       int smallestChildIdx = getLeftChildIdx(index);
       while(hasLeftChild(index))
       {
           smallestChildIdx = getRightChild(index) < getLeftChildIdx(index) ? getRightChildIdx(index) : getLeftChildIdx(index);
           if(array[smallestChildIdx] < array[index])
           {
               std::swap(array[index],array[smallestChildIdx]);
               index = smallestChildIdx;
           }
           else break;
       }
   }

    
    public:
    // Constructor
    MinHeap(int capacity = 0)
    {
        size = 0;
        capacity = capacity;
        array = std::vector<int>(capacity,INT_MAX);
    }

    // Constructor when an array is passed as input
    MinHeap(std::vector<int> inputArray)
    {
        capacity = inputArray.size();
        size = inputArray.size();
        array = inputArray;
        int lnln = array.size()/2 -1;
        for(int i = lnln; i >= 0; i--)
        {
            int index = i;
            while(2*index+1 < array.size())
            {
                int leftChildIdx = 2*index + 1;
                int rightChildIdx = 2*index + 2;
                int smallestIdx = index;
                if(leftChildIdx < array.size() && array[leftChildIdx] < array[smallestIdx]) smallestIdx = leftChildIdx;
                if(rightChildIdx < array.size() && array[rightChildIdx] < array[smallestIdx]) smallestIdx = rightChildIdx;
                if(smallestIdx != index)
                {
                    std::swap(array[smallestIdx], array[index]);
                    index = smallestIdx;
                }
                if(smallestIdx == index) break;
            }
        }
    }


    // printer: Utility function to print the heap
    void printer()
    {
        if(array.empty())
        {
            std::cout<<"EMPTY"<<std::endl;
        }
        else
        {
            for(auto itr = array.begin(); itr != array.end(); itr++)
            {
                std::cout<<*itr<<" ";
            }
            std::cout<<std::endl;
        }
    }


    // peek: Return the element at the top of the heap
    int peek()
    {
        return size == 0 ? INT_MAX : array[0];
    }


    // push: Add an input element onto the heap
    void push(int element)
    {
        ensureExtraCapacity();
        array[size] = element;
        size++;
        heapifyUp();
    }


    // getMin: Get the min of the Heap
    int getMin()
    {
        if(size == 0) return INT_MAX;
        int top = array[0];
        array[0] = array[size-1];
        size--;
        heapifyDown();
        return top;
    }
};

int main(int argc, const char *argv[])
{
    std::vector<int> a{15,20,10,17};
    MinHeap h(a);
    std::cout<<h.peek()<<std::endl;
    std::cout<<h.getMin()<<std::endl;
    std::cout<<h.peek()<<std::endl;
    return 0;
}