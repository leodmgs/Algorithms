// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    long apples_count = 0;
    long oranges_count = 0;
    vector<int>::iterator it;
    for (it = apples.begin(); it != apples.end(); ++it)
    {
        long d = (*it + a);
        if ( d >= s && d <= t ) 
            ++apples_count;
    }
    for (it = oranges.begin(); it != oranges.end(); ++it)
    {
        long d = (*it + b);
        if ( d >= s && d <= t ) 
            ++oranges_count;
    }
    cout << apples_count << endl;
    cout << oranges_count << endl;
}