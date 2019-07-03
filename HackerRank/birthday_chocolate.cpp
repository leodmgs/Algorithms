// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {
    int d_sum = 0, p = 0;
    int it_counter = 0, total = 0;
    vector<int>::iterator it_s, it_m;
    for (it_s = s.begin(); it_s != s.end(); ++it_s)
    {
        it_m = it_s;
        d_sum = 0;
        it_counter = 0;
        while (it_counter < m)
        {
            if ( (it_counter + p) >= s.size())
                break;
            d_sum += (*it_m);
            ++it_m;
            ++it_counter;
        }
        if (d_sum == d)
            ++total;
        ++p;
    }
    return total;
}