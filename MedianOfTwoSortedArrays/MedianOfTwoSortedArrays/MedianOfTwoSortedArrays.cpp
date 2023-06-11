// MedianOfTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void mergeArrays(vector<int>& a1, vector<int>& a2)
{
    int index = 0;

    for (int i = 0; i < a2.size(); i++)
    {
        //traverse nums1 and place val
        for (int j = index + 1; j < a1.size(); j++)
        {
            if (a1[j] > a2[i])
            {
                //put nums2 before nums1
                a1.emplace(a1.begin() + j, a2[i]);
                index = j;
                break;
            }
        }
    }
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;

        mergeArrays(nums1, nums2); //stores reseult in nums1;

        //CASE1: Odd sized array
        if (nums1.size() % 2 != 0)
        {
            int medIndex = nums1.size() / 2;
            result = nums1[medIndex];
        }

        //CASE 2: even sized array
        else
        {
            int medIndex1 = nums1.size() / 2;
            int medIndex2 = medIndex1 - 1;

            result = (((double)nums1[medIndex1] + (double)nums1[medIndex2]) / 2);
        }

        return result;
    }
};

int main()
{
    vector<int> array1, array2;

    array1.push_back(1);
    array1.push_back(4);

    array2.push_back(2);
    array2.push_back(3);

    Solution obj1;

    cout << "result: " << obj1.findMedianSortedArrays(array1, array2) << endl;
}

