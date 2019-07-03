#include <cstdio>
#include <vector>
#include <limits>

using namespace std;


int maximumProduct(vector<int>& nums) 
{
	int s1=INT_MAX, s2=INT_MAX;
	int b1=INT_MIN, b2=INT_MIN, b3=INT_MIN;
	for (int i=0; i<nums.size(); ++i)
	{
		if (nums[i] < s1 || nums[i] < s2)
		{
			if (nums[i] > s1) {
				s2 = nums[i];
			}
			else 
			{
				s2 = s1;
				s1 = nums[i];
			}
		}
		if (nums[i] > b1)
		{
			if (nums[i] < b2)
			{
				b1 = nums[i];
			}
			else if (nums[i] > b2 && nums[i] < b3) 
			{
				b1 = b2;
				b2 = nums[i];
			}
			else
			{
				b1 = b2;
				b2 = b3;
				b3 = nums[i];
			}
		}
	}
	int max_p1 = (b1*b2*b3);
	int max_p2 = (s1*s2*b3);
	return max_p1 > max_p2 ? max_p1 : max_p2;
}

int main()
{
	// const int arr [] = {1,2,3,4};
	// const int arr [] = {-4,-3,-2,-1,-5,60};
	const int arr [] = {-710,-107,-851,657,-14,-859,278,-182,-749,718,-640,127,-930,-462,694,969,143,309,904,-651,160,451,-159,-316,844,-60,611,-169,-73,721,-902,338,-20,-890,-819,-644,107,404,150,-219,459,-324,-385,-118,-307,993,202,-147,62,-94,-976,-329,689,870,532,-686,371,-850,-186,87,878,989,-822,-350,-948,-412,161,-88,-509,836,-207,-60,771,516,-287,-366,-512,509,904,-459,683,-563,-766,-837,-333,93,893,303,908,532,-206,990,280,826,-13,115,-732,525,-939,-787};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	int ans = maximumProduct(v);
	printf("%d\n", ans);
	return 0;
}