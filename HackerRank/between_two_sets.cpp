
/*
 * Complete the getTotalX function below.
 */
int getTotalX(vector<int> a, vector<int> b) {
    vector<int> factors;
    int begin_elem_a = a[a.size()-1];
    int end_elem_b = b[0];
    for (int i = begin_elem_a; i <= end_elem_b; ++i)
        if (begin_elem_a % i == 0 || end_elem_b % i == 0)
            factors.push_back(i);
    int count_factors = 0;
    bool is_factor = false;
    vector<int>::iterator it_a;
    vector<int>::iterator it_b;
    vector<int>::iterator it_f;
    for (it_f = factors.begin(); it_f != factors.end(); ++it_f)
    {
        is_factor = true;
        for (it_a = a.begin(); it_a != a.end(); ++it_a)
            if ( ((*it_f) > (*it_a) ? (*it_f) % (*it_a) != 0 : (*it_a) % (*it_f) != 0) )
                is_factor = false;
        for (it_b = b.begin(); it_b != b.end(); ++it_b)
            if ( ((*it_f) > (*it_b) ? (*it_f) % (*it_b) != 0 : (*it_b) % (*it_f) != 0) )
                is_factor = false;
        if (is_factor)
            ++count_factors;
    }
    return count_factors;
}