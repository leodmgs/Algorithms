
// Complete the hurdleRace function below.
int hurdleRace(int k, vector<int> height) {
    int doses = 0;
    int max = 0;
    vector<int>::iterator it;
    for (it = height.begin(); it != height.end(); ++it)
        if ((*it) > max)
            max = (*it);
    doses = max - k;
    return doses > 0 ? doses : 0;
}