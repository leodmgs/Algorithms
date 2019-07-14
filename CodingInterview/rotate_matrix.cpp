#include <cstdio>
#include <vector>

using namespace std;

// Helper method
void print_matrix(vector<vector<int>> &m)
{
	for (auto &row: m)
	{
		for (auto &col: row)
		{
			printf("%d ", col);
		}
		printf("\n");
	}
}

// Solution: O(n^2)
void rotate_matrix(vector<vector<int>> &m)
{
	int n = m.size();
	int b = 0, i = 0, j = n-1, t = 0;
	while (b < n)
	{
		i = b;
		while (i < j)
		{
			t = m[b][i];
			m[b][i] = m[n-i-1][b];
			m[n-i-1][b] = m[j][n-i-1];
			m[j][n-i-1] = m[i][j];
			m[i][j] = t;
			++i;
		}
		++b;
		--j;
	}
}


int main()
{
	vector<vector<int>> mtx({{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}});
	// vector<vector<int>> mtx({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}});
	// vector<vector<int>> mtx({{1,2,3},{4,5,6},{7,8,9}});
	// vector<vector<int>> mtx({{1,2},{3,4}});
	printf("Original\n");
	print_matrix(mtx);
	
	rotate_matrix(mtx);
	printf("\nRotated\n");
	print_matrix(mtx);

	return 0;
}