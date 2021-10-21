/* 
This file implements the famous O(NlogN) sorting algorithms:
1: Merge Sort
2: Quick Sort
3: Heap Sort
*/

#include <iostream>
#include <vector>

class NlogNSorting{
    private:

    // Merge Sort Logic:
    void merge(std::vector<int> *array, int low, int mid, int high){
        int las = mid - low + 1;
        int ras = high - mid;
        int L[las];
        int R[ras];
        for(int i = 0 ; i < las; i++)
        {
            L[i] = array->at(low + i);
        }
        for(int i = 0; i < ras; i++)
        {
            R[i] = array->at(mid+1+i);
        }

        int i = 0;
        int j = 0;
        int k = low;
        while(i < las && j < ras)
        {
            if(L[i] <= R[j])
            {
                array->at(k) = L[i];
                i++;
            }
            else
            {
                array->at(k) = R[j];
                j++;
            }
            k++;
        }
        while(i < las)
        {
            array->at(k) = L[i];
            i++;
            k++;
        }
        while(j < ras)
        {
            array->at(k) = R[j];
            j++;
            k++;
        }
    }

    void mergeSorter(std::vector<int> *array, int low, int high)
    {
        if(low < high)
        {
            int mid = (low + high)/2;
            mergeSorter(array,low, mid);
            mergeSorter(array, mid+1, high);
            merge(array,low,mid,high);
        }
    }
    // Merge Sort Logic Ends:

    // Heap Sort Logic:

    void heapifyDown(std::vector<int> *array, int index, int size)
    {
        int leftChildIdx = 2*index + 1;
        int rightChildIdx = 2*index + 2;
        int smallestIdx = index;
        if(leftChildIdx < size && array->at(leftChildIdx) < array->at(smallestIdx)) smallestIdx = leftChildIdx;
        if(rightChildIdx < size && array->at(rightChildIdx) < array->at(smallestIdx)) smallestIdx = rightChildIdx;
        if(index != smallestIdx)
        {
            std::swap(array->at(index), array->at(smallestIdx));
            heapifyDown(array,smallestIdx,size);
        }
    }

    void buildHeap(std::vector<int> *array)
    {
        int lnln = array->size()/2 - 1;
        for(int i = lnln; i >= 0; i--)
        {
            heapifyDown(array,i,array->size());
        }
    }

    int getMin(std::vector<int> *array, int size)
    {
        int top = array->at(0);
        std::swap(array->at(0), array->at(size));
        heapifyDown(array,0,size);
        return top;
    }

    void heapSorter(std::vector<int> *array)
    {
        buildHeap(array);
        int size = array->size() - 1;
        while(size >= 0)
        {
            getMin(array,size);
            size--;
        }
        int low = 0;
        int high = array->size()-1;
        while(low <= high)
        {
            std::swap(array->at(low++), array->at(high--));
        }
    }
    // Heap sort Logic Ends


    // Quick sort Logic
    int partition(std::vector<int> *array, int low, int high)
    {
        int pivot = high;
        int i = low - 1;
        int j = low;
        while(j < high)
        {
            if(array->at(j) < array->at(pivot))
            {
                std::swap(array->at(++i), array->at(j));
            }
            j++;
        }
        std::swap(array->at(++i), array->at(pivot));
        return pivot;
    }

    void quickSorter(std::vector<int> *array, int low, int high)
    {
        if(low < high)
        {
            int pi = partition(array,low,high);
            quickSorter(array,low,pi-1);
            quickSorter(array,pi+1,high);
        }
    }
    // Quick Sort Logic Ends


    public:
    // Utility function to print a 1D-vector.
    void printer(std::vector<int> array)
    {
        for(int i = 0 ; i < array.size(); i++)
        {
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }


    // Merge Sort Wrapper
    std::vector<int> mergeSort(std::vector<int> array)
    {
        mergeSorter(&array,0,array.size()-1);
        return array;
    }


    // Heap Sort Wrapper
    std::vector<int> heapSort(std::vector<int> array)
    {
        heapSorter(&array);
        return array;
    }

    // QuickSort Wrapper
    std::vector<int> quickSort(std::vector<int> array)
    {
        quickSorter(&array,0,array.size()-1);
        return array;
    }

};

int main(int argc, const char *argv[])
{
    std::vector<int> a{10,9,8,7,6,5,4,3,2,1};
    NlogNSorting obj;
    a = obj.quickSort(a);
    obj.printer(a);
    return 0;
}