
// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int len = a.size();
    vector<int> circular_v(len);
    int index = 0;
    for (int i = 0; i < len; ++i)
    {
        index = (i + k) % len;
        circular_v[index] = a[i];
    }
    return circular_v;
}