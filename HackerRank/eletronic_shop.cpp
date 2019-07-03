
/*
 * Complete the getMoneySpent function below.
 */
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int spend = -1;
    vector<int>::iterator it_k = keyboards.begin();
    vector<int>::iterator it_d = drives.begin();
    while (it_k != keyboards.end())
    {
        while (it_d != drives.end())
        {
            if ( (*it_k) + (*it_d) == b ) 
                return b;
            if ( (*it_k) + (*it_d) < b && (*it_k) + (*it_d) > spend )
                spend = (*it_k) + (*it_d);
            ++it_d;
        }
        it_d = drives.begin();
        ++it_k;
    }
    return spend;
}