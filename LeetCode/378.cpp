#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/*
	Success
	Runtime: 48 ms, faster than 63.48% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
	Memory Usage: 13 MB, less than 29.15% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.

 */
int kthSmallest(vector<vector<int>>& matrix, int k) 
{
	int n = matrix.size();
	priority_queue<int, vector<int>> heap;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)	
		{
			if (heap.size() < k)
			{
				heap.push(matrix[i][j]);
			}
			else
			{
				if (matrix[i][j] < heap.top())
				{
					heap.pop();
					heap.push(matrix[i][j]);
				}
			}
		}
	}
	return heap.top();        
}

int main()
{
	// vector<int> r1({5,6,7});
	// vector<int> r2({6,7,8});
	// vector<int> r3({7,8,9});

	vector<int> r1({1,5,9});
	vector<int> r2({10,11,13});
	vector<int> r3({12,13,15});

	vector<vector<int>> mtx({r1,r2,r3});
	int ans = kthSmallest(mtx, 8);
	printf("%d\n", ans);
	return 0;
}

/*

1 5 9 10 11 12 13 13 15



*/