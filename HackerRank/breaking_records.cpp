// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores) {
    vector<int> hl_score;
    hl_score.push_back(0);
    hl_score.push_back(0);
    int highest = scores[0], lowest = scores[0];
    vector<int>::iterator it;
    for (it = scores.begin(); it != scores.end(); ++it)
    {
        if ( *it > highest )
        {
            highest = *it;
            ++hl_score[0];
        }
        if ( *it < lowest )
        {
            lowest = *it;
            ++hl_score[1];
        }
    }
    return hl_score;
}