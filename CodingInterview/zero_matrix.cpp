#include <cstdio>
#include <vector>

using namespace std;

/*
	Cracking the Coding Interview
	Chapter 1
	Question 1.8 - Zero matrix
*/

// Solution: O(mn), 'mn' once the matrix is MxN.
void zero_matrix(vector<vector<int>> &m)
{
	vector<pair<int,int>> zeros;
	for (int i = 0; i < m.size(); ++i)
		for (int j = 0; j < m.size(); ++j)
			if (m[i][j] == 0)
				zeros.push_back(pair<int,int>(i,j));
	for (auto &p: zeros)
	{
		for (int i = 0; i < m[0].size(); ++i)
			m[p.first][i] = 0;
		for (int j = 0; j < m.size(); ++j)
			m[j][p.second] = 0;
	}
}

// Helper method to print a matrix.
void print_matrix(vector<vector<int>> &m)
{
	for (auto &row: m)
	{
		for (auto &col: row)
			printf("%d ", col);
		printf("\n");
	}
}

int main()
{
	// vector<vector<int>> mtx({{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}});
	vector<vector<int>> mtx({{0,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,0}});
	// vector<vector<int>> mtx({{1,2,3},{4,5,6},{7,8,9}});
	// vector<vector<int>> mtx({{1,2},{3,4}});
	zero_matrix(mtx);
	print_matrix(mtx);
	return 0;
}