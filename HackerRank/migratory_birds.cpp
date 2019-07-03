
// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
    int max_bird_id = 0;
    map<int, int> birds_map;
    pair<map<int, int>::iterator, bool> birds_map_pair;
    vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it > max_bird_id)
            max_bird_id = *it;
        birds_map_pair = birds_map.insert(pair<int, int>(*it, 1));
        if (birds_map_pair.second == false)
            ++birds_map[*it];
    }
    int bird = 0;
    long total_bird_occur = 0;
    for (int i = 0; i <= max_bird_id; ++i) 
    {
        if (birds_map[i] > total_bird_occur) 
        {
            total_bird_occur = birds_map[i];
            bird = i;
        }
    }
    return bird;
}