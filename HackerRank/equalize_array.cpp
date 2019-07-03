
// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
    map<int, int> emap;
    pair<map<int, int>::iterator, bool> epair;
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); ++it)
    {
        epair = emap.insert(pair<int, int>(*it, 1));
        if (epair.second == false)
            ++emap[*it];
    }
    map<int, int>::iterator itm;
    map<int, int>::iterator itm_del;
    int max = 101, counter = 0;
    while (emap.size() > 1)
    {
        for (itm = emap.begin(); itm != emap.end(); ++itm) 
        {
            if ( (*itm).second < max ) 
            {
                itm_del = itm;
                max = (*itm).second;
            }
        }
        counter += (*itm_del).second;
        emap.erase(itm_del);
        max = 101;
    }
    return counter;
}

