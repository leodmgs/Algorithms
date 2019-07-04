#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int distributeCandies(vector<int>& candies) 
{
	int n = candies.size();
	unordered_map<int,int> kinds;
	for (int i = 0; i < n; ++i)
		if (kinds.find(candies[i]) == kinds.end())
			kinds[candies[i]] = 1;
		else
			kinds[candies[i]] += 1;
	return kinds.size() < n/2 ? kinds.size() : n/2;
}

int main()
{
	vector<vector<int>> v_inputs({
		{1,1,1,1,2,2,3,4,5,6},
		{1,1,1,1,1,2,2,3,3,3,4,4,4,5,5,5},
		{1,1,2,2,2,2,2,2,3,3,3,3,3,3},
		{1,1,1,1,1,1,1,2},
		{1,1,1,1,1,2,2,3},
		{1,1,1,2,2,3},
		{1,1,1,1,2,2,2,3,3,3},
		{1,1,2,2,2,3,3,3,4,4,4,4},
		{1,1,1,1,2,2,2,3,3,3,5,5},
		{1,1,2,2,3,3},
		{1,1,1,1,2,2,2,3,3,3,4,4},
		{1,1,1,1,1,1,2,2,2,3,3,3,4,4,4,5},
		{1,1,1,1,2,2,2,3,3,3,4,4,4,5,5,6}
	});

	int ans = 0;
	for (auto& v: v_inputs)
	{
		ans = distributeCandies(v);
		printf("%d\n", ans);
	}
	
	return 0;
}