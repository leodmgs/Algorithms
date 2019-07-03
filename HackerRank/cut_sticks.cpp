
// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> sticks_v;
    int smaller = 1001;
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); ++it)
        if ((*it) < smaller)
            smaller = *it;
    
    int sticks_cut = 0;
    sticks_v.push_back( (arr.size() - sticks_cut) );
    int reduce = smaller;
    do {
        sticks_cut = 0;
        smaller = 1001;
        for (it = arr.begin(); it != arr.end(); ++it)
        {
            (*it) -= reduce;
            if ( (*it) < 1 )
                ++sticks_cut;
            if ( (*it) < smaller && (*it) > 0 )
                smaller = (*it);
        }
        if (sticks_cut == arr.size()) break;
        sticks_v.push_back( (arr.size() - sticks_cut) );
        reduce = smaller;
    } while ( (arr.size() - sticks_cut) > 1);
    return sticks_v;
}

