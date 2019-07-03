
// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    map<char, long> s1_map;
    pair<map<char, long>::iterator, bool> in_op;
    for (int i = 0; i < s1.size(); ++i)
    {
        in_op = s1_map.insert(pair<char, long>(s1[i], 1));
        if (in_op.second == false)
            ++s1_map[s1[i]];
    }
    for (int j = 0; j < s2.size(); ++j)
    {
        if (s1_map[s2[j]])
            return "YES";
    }
    return "NO";
}