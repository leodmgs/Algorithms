#include <cstdio>
#include <unordered_map>

using namespace std;

/*
	#- Naive solution
	The solution below consists in loop through all numbers from 1 to <1e6 (1M).
	In that way, for each number of the sequence is calculated and it is checked
	againt the 'greater' variable to see if a biggest number was found.

	#- Complexity
	Once this solution loop throuth all value from 1 to <1e6 (where 1e6 is 'n' in 
	this case), in the worst case the solution below takes O(n*m), where 'm' is the
	calculated sequence from 'n' to 1.

	#- Time of execution
	real	0m0.781s
	user	0m0.777s
	sys		0m0.003s
 */
uint64_t collatz_solution_ONE(uint64_t n)
{
	uint64_t greater = 0;
	int counter = 0;
	// Loop through all the elements to find the biggest sequence.
	for (uint64_t i = 1; i < n; ++i)
	{
		uint64_t t = i;
		// From the current number, calculate the sequence toward to 1.
		while (t > 1)
		{
			t = (t % 2 == 0) ? t/2 : 3*t + 1;
			++counter;
		}
		// If the current calculation has a bigger sequence, 'greater' variable is updated.
		if (counter > greater) 
			greater = counter;
		counter = 0;
	}
	return greater;
}


/*
	#- Time of execution
	real	0m2.009s
	user	0m1.965s
	sys		0m0.037s
 */
uint64_t collatz_solution_TWO(uint64_t n)
{
	unordered_map<uint64_t, uint64_t> collatz_map;
	collatz_map[1] = 0;

	uint64_t counter = 0, greater = 0;
	for (uint64_t i = 1; i <= n; ++i)
	{
		uint64_t it = i;
		while (it > 0)
		{
			if (collatz_map.find(it) != collatz_map.end())
			{
				counter += collatz_map[it];
				collatz_map[i] = counter;
				if (counter > greater)
					greater = counter;
				break;
			}
			else
			{
				it = (it % 2 == 0) ? it/2 : 3*it + 1;
				++counter;
			}
		}
		counter = 0;
	}
	return greater;
}

int main()
{
	uint64_t n = 1e6;
	uint64_t ans = 0;

	ans = collatz_solution_ONE(n);
	printf("[1]: %llu\n", ans);

	ans = collatz_solution_TWO(n);
	printf("[2]: %llu\n", ans);

	return 0;
}

