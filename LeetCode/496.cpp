#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// O(m)+(O(n)*O(m)) = O(m+nm) = O(nm)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
	int n2 = nums2.size();
    unordered_map<int,int> unmap;
    for (int i=0; i<n2; ++i) // O(m)
    	unmap[nums2[i]] = i;

    int n1 = nums1.size();
    vector<int> ngv;
    for (int j=0; j<n1; ++j) // O(n)
    {
    	int v = -1;
    	if (unmap.find(nums1[j]) != unmap.end())
    	{
    		for (int k=unmap[nums1[j]]; k<n2; ++k) // O(m)
	    	{
	    		if (nums2[k] > nums1[j])
	    		{
	    			v = nums2[k];
	    			break;
	    		}
	    	}
    	}
		ngv.push_back(v);
    }
    return ngv;
}

int main()
{
	// const int arr1 [] = {4,1,2};
	// const int arr2 [] = {1,3,4,2};

	// const int arr1 [] = {1};
	// const int arr2 [] = {4};

	// const int arr1 [] = {1,4,3};
	// const int arr2 [] = {2,3,5};

	// [ 6 -1 9 9 6 -1 ]
	const int arr1 [] = {4,8,2,1,5,9};
	const int arr2 [] = {2,1,9,3,8,5,4,6};

	vector<int> nums1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
	vector<int> nums2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));

	vector<int> ans = nextGreaterElement(nums1, nums2);
	printf("[ ");
	for (int i: ans)
		printf("%d ", i);
	printf("]\n");

	return 0;
}