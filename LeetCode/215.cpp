#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
	int n = nums.size();
	priority_queue<int, vector<int>, greater<int> > heap;
	for (int i=0; i<n; ++i)
	{
		if (heap.size() < k)
		{
			heap.push(nums[i]);
		}
		else
		{
			if (nums[i] > heap.top())
			{
				heap.pop();
				heap.push(nums[i]);
			}
		}
	}
	return heap.top();
}

int main()
{
	const int arr [] = {7,4,9,2,6,4,1};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	int ans = findKthLargest(v, 3);
	printf("%d\n", ans);
	return 0;
}