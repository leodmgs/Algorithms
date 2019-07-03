
#include <cstdio>
#include <vector>

using namespace std;

int maxOnes(vector<int> nums) 
{
	int max = 0;
	int sum = 0;
	for (int i=0; i<nums.size(); ++i)
	{
		if (nums[i] == 0)
		{
			if (sum > max) max = sum;
			sum = 0;
		}
		else
		{
			++sum;
		}
	}
	if (sum > max) max = sum;
	return max;
}

int main()
{
	const int arr [] = {1,1,0,1,1,1};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	int ans = maxOnes(v);
	printf("%d\n", ans);
	return 0;
}