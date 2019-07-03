#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <limits>
#include <tuple>

using namespace std;

class heap_comparison {
	bool is_min_heap;
public:
	heap_comparison(const bool& min_heap=false)
	{ this->is_min_heap = min_heap; }
	bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const
	{
		if (is_min_heap)
			return (lhs.first + lhs.second) > (rhs.first + rhs.second);
		return (lhs.first + lhs.second) < (rhs.first + rhs.second);
	}
};

typedef priority_queue<pair<int,int>, vector<pair<int,int>>, heap_comparison > heapi;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
{
	// #1 create a heap to store the minimum pairs
	heapi max_heap;

	// #2 loop all nums (nums1 and nums2) and store the minimum into heap
	for (int i=0; i<nums1.size(); ++i) {
		for (int j=0; j<nums2.size(); ++j) {
			if (max_heap.size() < k)
			{
				max_heap.push(pair<int,int>(nums1[i],nums2[j]));
			}
			else
			{
				pair<int,int> top_pair = max_heap.top();
				if ( (nums1[i]+nums2[j]) < (top_pair.first+top_pair.second))
				{
					max_heap.pop();
					max_heap.push(pair<int,int>(nums1[i],nums2[j]));
				}
			}
		}
	}

	// #3 create and return the minimum pairs
	vector<vector<int>> sum_pairs(max_heap.size(), vector<int>());
	int m = max_heap.size()-1;
	pair<int,int> top_pair;
	while (!max_heap.empty())
	{
		top_pair = max_heap.top();
		sum_pairs[m].push_back(top_pair.first);
		sum_pairs[m].push_back(top_pair.second);
		max_heap.pop();
		--m;
	}
	return sum_pairs;
}

int main()
{
	const int arr1 [] = {1};
	const int arr2 [] = {1,1};
	vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
	vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
	vector<vector<int>> v_ans = kSmallestPairs(v1, v2, 3);
	for (auto it=v_ans.begin(); it!=v_ans.end(); ++it)
		printf("[%d,%d] ", (*it)[0], (*it)[1]);
	printf("\n");
	return 0;
}