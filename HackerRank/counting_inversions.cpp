using namespace std;

vector<string> split_string(string);

long merge(int* arr, long b, long e) {
    int m = (b+e)/2;
    int left [m-b];
    for (int l = 0; l < (m-b); ++l) 
    {
        left[l] = arr[b+l];
    }
    int right [e-m];
    for (int r = 0; r < (e-m); ++r) 
    {
        right[r] = arr[m+r];
    }
    int it = b, i = 0, j = 0;
    long s = 0;
    while (it < e)
    {
        if (i < (m-b) && j < (e-m)) {
            if (left[i] <= right[j]) {
                arr[it] = left[i];
                ++i;
            } else if (right[j] < left[i]) {
                arr[it] = right[j];
                ++j;
                s += (m-b-i);
            }
        } else if (i < (m-b)) {
            arr[it] = left[i];
            ++i;
        } else if (j < (e-m)) {
            arr[it] = right[j];
            ++j;
        }
        ++it;
    }
    return s;
}

long merge_sort(int* arr, int b, int e, long s) {
    if ((e-b-1) == 0) {
        return s;
    }
    int m = (b+e)/2;
    s = merge_sort(arr, b, m, s);
    s = merge_sort(arr, m, e, s);
    s += merge(arr, b, e);
    return s;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    int* a = arr.data();
    long swaps = merge_sort(a, 0, arr.size(), 0);
    return swaps;
}