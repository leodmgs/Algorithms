
// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    vector<int> pp;
    map<int,int> emap;
    for (int i = 0; i < p.size(); ++i)
        emap.insert(pair<int, int>(p[i], i));
    for (int j = 1; j <= p.size(); ++j)
        pp.push_back(emap[emap[j]+1]+1);
    return pp;
}

