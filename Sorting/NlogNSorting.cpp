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

    void heapifyUp(std::vector<int> *array, int index)
    {
        while(((index-1)/2 >= 0) && array->at((index-1)/2) < array->at(index))
        {
            int t = array->at(index);
            array->at(index) = array->at((index-1)/2);
            array->at((index-1)/2) = t;
            index = (index-1)/2;
        }
    }

    void buildHeap(std::vector<int> *array)
    {
        for(int i = array->size()-1; i >= 0; i--)
        {
            heapifyUp(array,i);
        }
    }

    void heapSorter(std::vector<int> *array)
    {
        buildHeap(array);
        
    }


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


    // Merge Sort
    std::vector<int> mergeSort(std::vector<int> array)
    {
        mergeSorter(&array,0,array.size()-1);
        return array;
    }


    // Heap Sort
    std::vector<int> heapSort(std::vector<int> array)
    {
        heapSorter(&array);
        return array;
    }

};

int main(int argc, const char *argv[])
{
    std::vector<int> a{10,9,8,7,6,5};
    NlogNSorting obj;
    a = obj.mergeSort(a);
    obj.printer(a);
    return 0;
}