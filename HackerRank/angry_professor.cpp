
// Complete the angryProfessor function below.
string angryProfessor(int k, vector<int> a) {
    bool cancel = false;
    int late = 0;
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
    {
        if ( (*it) > 0 )
        {
            ++late;
            if ( late > (a.size() - k) ) 
            {
                cancel = true;
                break;
            }
        }
    }
    return cancel ? "YES" : "NO";
}