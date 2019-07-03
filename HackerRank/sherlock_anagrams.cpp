using namespace std;

bool anagram(vector<char> v, int l, int t, int f)
{
    map<char, int> map_c;
    pair<map<char, int>::iterator, bool> pair_c;
    for (int i = l; i <= (l+f); ++i) 
    {
        pair_c = map_c.insert(pair<char, int>(v.at(i), 1));
        if (pair_c.second == false)
            ++map_c[v.at(i)];
    }
    map<char, int>::iterator it;
    for (int j = t; j <= (t+f); ++j) 
    {
        it = map_c.find(v.at(j));
        if (it == map_c.end())
            return false;
        --map_c[v.at(j)];
    }

    for (it = map_c.begin(); it != map_c.end(); ++it) 
        if ((*it).second != 0)
            return false;
    return true;
}

int sherlockAndAnagrams(string s) 
{
    int counter = 0;
    int fs = 0;
    int pvl = 0, pvt = 0;
    vector<char> str_v;
    for (int i = 0; i < s.size(); ++i)
        str_v.push_back(s[i]);

    while (fs < str_v.size())
    {
        for (pvl = 0; (pvl + fs) < str_v.size(); ++pvl)
        {
            for (pvt = (pvl + 1); (pvt + fs) < str_v.size(); ++pvt)
            {
                if ( anagram(str_v, pvl, pvt, fs) )
                    ++counter;
            }
        }
        ++fs;
    }

    return counter;
}