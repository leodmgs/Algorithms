#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> three_sum_v;
	// If it's true, the entire vector has the same integer value.
	if (n >= 3 && nums[0] == nums[n-1])
	{
		// If it has only zeros, add a triplet to be returned.
		if (nums[0] == 0)
			three_sum_v.push_back({0,0,0});
		// Return the result with (ie., [0,0,0]) or without any triplet.
		return three_sum_v;
	}

	int i = 0, p = 0, j = n-1, s = 0;
	/* 
		For each value until the last triplet of values ([n-3,n-2,n-1]),
		from the right next value to the last, check if the sum is equal
		to zero or increase or decrease depending of the result of the sum.
	*/
	for (int i = 0; i < n-2; ++i)
	{
		p = i+1; // 'p' represents the value right after 'i'
		j = n-1; // 'j' represents the last value on the array.
		// The triplet to be tested must be 'nums[i]+nums[p]+nums[j]'
		// Holding the value in nums[i], test all possibilities from 'p' to 'j'.
		while (p < j)
		{
			s = nums[i] + nums[p] + nums[j];
			// Any value greater than nums[j] will be bigger than sum.
			// So 'j' should to be decreased.
			if (s > 0) { --j; }
			// Any value less than nums[p] is lower than sum. In that case,
			// 'p' should be increased.
			else if (s < 0) { ++p; }
			else
			{
				// The triplet has the sum equals to zero. In this case, it
				// is pushed to back on the answer's vector.
				three_sum_v.push_back({nums[i],nums[p],nums[j]});
				// While the next nums[p] value is equal to the last one pushed to
				// the answer's vector, increase 'p' value to skip same results.
				while (p < j && nums[p] == three_sum_v[three_sum_v.size()-1][1])
					++p;
				// Do the same as the last while loop, but looking to the 'j'
				// position and descreasing it if it's necessary.
				while (p < j && nums[j] == three_sum_v[three_sum_v.size()-1][2])
					--j;
			}
		}
		// If the next value is equal to the current one, increase 'i' value
		// until it has a different value. It make sure that any result will
		// be equal starting from 'i' position.
		while (nums[i] == nums[i+1] && i < n-2)
			++i;
	}
	return three_sum_v;
}


int main()
{
	// const int arr [] = {0,0};			//[]
	// const int arr [] = {-1,0,1,2,-1,-4}; //[-1,-1,2],[-1,0,1]
	// const int arr [] = {-2,0,1,1,2};		//[-2,0,2],[-2,1,1]
	// const int arr [] = {-1,0,1,0}; 		//[-1,0,1]
	// const int arr [] = {0,0,0}; 			//[0,0,0]
	// const int arr [] = {3,0,-2,-1,1,2}; 	//[[-2,-1,3],[-2,0,2],[-1,0,1]]
	
	// [-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]
	// const int arr [] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};

	// [-4,1,3],[-4,2,2],[-2,-1,3],[-2,0,2],[-1,0,1]
	// const int arr [] = {2,-1,3,-4,-2,-2,1,2,0};

	// const int arr [] = {0,-4,-1,-4,-2,-3,2}; //[-2,0,2]

	// [-4,1,3],[-4,2,2],[-1,0,1]
	// const int arr [] = {0,2,2,3,0,1,2,3,-1,-4,2};

	// [-4,2,2],[-3,1,2],[-1,-1,2]
	// const int arr [] = {-5,-1,-5,-4,2,1,-1,2,-4,-3,-2,-4};

	// const int arr [] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	// const int arr [] = {1,1,1};

	// const int arr [] = {-1,0,1};

	// const int arr [] = {0,1,1};

	// const int arr [] = {-4,-4,-3,-2,-1,0,1,2,2};

	const int arr [] = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4};

	vector<int> v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	vector<vector<int>> v_ans = threeSum(v);
	if (v_ans.size() > 0) 
	{
		for (int i=0; i<v_ans.size(); ++i) {
			printf("[");
			for (int j=0; j<v_ans[i].size(); ++j)
				printf(" %d ", v_ans[i][j]);
			printf("]\n");
		}
	}
	else {
		printf("[]\n");
	}
	return 0;
}
