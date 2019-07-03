
/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    map<int, int> pmap;
    pair<map<int, int>::iterator, bool> mpair;
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        mpair = pmap.insert(pair<int, int>(*it, 1));
        if (mpair.second == false)
            ++pmap[*it];
    }
    int max = 0;
    for (int i = 0; i < a.size() - 1; ++i)
        if (pmap[i] + pmap[i+1] > max)
            max = pmap[i] + pmap[i+1];
    return max;
}