// In this program we Implements the famous O(N^2) sorting algorithms

#include <iostream>
#include <vector>


class N2Sorting{
    public:

    // Utility Functions
    // Printer: Function to print the array
    void Printer(std::vector<int> array)
    {
        // Sanity Check: Empty
        if(array.empty()) std::cout<<"NULL"<<std::endl;
        for(int i = 0; i < array.size(); i++)
        {
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }


    // Bubble Sort Algorithm
    std::vector<int> BubbleSort(std::vector<int> array)
    {
        // Sanity Check: Empty
        if(array.empty()) return array;
        // Bubble Sort Logic
        std::cout<<"Running Bubble Sort"<<std::endl;
        for(int i = array.size(); i > 1; i--)
        {
            for(int j = 1; j < i; j++)
            {
                if(array[j-1] > array[j])
                {
                    std::swap(array[j-1], array[j]);
                }
            }
        }
        return array;
    }


    // Insertion Sort Algorithm
    std::vector<int> InsertionSort(std::vector<int> array)
    {
        // Sanity Check: Empty
        if(array.empty()) return array;
        // Insertion Sort Logic
        std::cout<<"Running Insertion Sort"<<std::endl;
        for(int i = 1; i < array.size(); i++)
        {
            int key = array[i];
            int j = i - 1;
            while(j >= 0)
            {
                if(key < array[j])
                {
                    array[j+1] = array[j];
                }
                else break;
                j--;
            }
            array[j+1] = key;
        }
        return array;
    }


    // Selection Sort Algorithm
    std::vector<int> SelectionSort(std::vector<int> array)
    {
        // Sanity Check: Empty
        if(array.empty()) return array;
        // Selection Sort Logic
        std::cout<<"Running Selection Sort"<<std::endl;
        for(int i = 0; i < array.size(); i++)
        {
            int smallest_idx = i;
            for(int j = i; j < array.size(); j++)
            {
                if(array[j] < array[smallest_idx])
                {
                    smallest_idx = j;
                }
            }
            std::swap(array[i], array[smallest_idx]);
        }
        return array;
    }
};


int main(int argc, char const *argv[])
{
    N2Sorting obj;
    std::vector<int> a{10,9,8,7,6,5,4,3,2,1};
    obj.Printer(a);
    std::vector<int> ans = obj.SelectionSort(a);
    obj.Printer(ans);
    return 0;
}