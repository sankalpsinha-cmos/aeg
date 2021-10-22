/* This C++ programs implements some of the famous searching algorithms 
1: Binary Search: Search in O(logN) time in a sorted list
2: Quick Select: Search for a k-th smallest value in an array
3: Shifted Binary Search: Search effeciently in a sorted list that is shifted by k positions.

*/

#include <iostream>
#include <vector>
#include <climits>

class Searching{
    private:
    std::vector<int> array;

    public:
    Searching(std::vector<int> inputArray)
    {
        array = inputArray;
    }

    // checkSorted: Check if the input array is sorted
    bool checkSorted()
    {
        for(auto itr = array.begin()+1; itr != array.end(); itr++)
        {
            if(*(itr-1) > *itr) return false;
        }
        return true;
    }

    // binarySearch: return the index of a given element in the array
    int binarySearch(int target)
    {
        if(!checkSorted()) return INT_MAX;
        int low = 0;
        int high = array.size() - 1;
        while(low <= high)
        {
            int mid = (high - low)/2 + low;
            if(array[mid] == target) return mid;
            else if(target > array[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return INT_MAX;
    }

    // quickSelect: Get the index of the k-th smallest number in an array
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
        std::swap(array->at(++i),array->at(pivot));
        return i;
    }

    int quickSelect(int k)
    {
        int low = 0;
        int high = array.size() - 1;
        while(low <= high)
        {
            int pi = partition(&array,low,high);
            if(pi == k - 1) return array[pi];
            else if(k - 1 > pi) low = pi + 1;
            else high = pi - 1;
        }
        return INT_MAX;
    }
};

int main(int argc, const char *argv[])
{
    std::vector<int> a{8,5,2,9,7,6,3};
    Searching b(a);
    std::cout<<b.quickSelect(2)<<std::endl;
    return 0;
}