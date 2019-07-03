// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int sum_pairs = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if ( (ar[i] + ar[j]) % k == 0 )
                ++sum_pairs;
    return sum_pairs;
}