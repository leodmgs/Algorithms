using namespace std;

vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    map<string, int> hashmap;
    pair<map<string,int>::iterator,bool> insert_op;
    vector<string>::iterator it;
    for (it = magazine.begin(); it != magazine.end(); ++it)
    {
        insert_op = hashmap.insert(pair<string, int>(*it, 1));
        if (insert_op.second == false)
            ++hashmap[*it];
    }
    vector<string>::iterator it_note;
    for (it_note = note.begin(); it_note != note.end(); ++it_note)
    {
        if (!hashmap[*it_note] || hashmap[*it_note] == 0)
        {
            cout << "No" << endl;
            return;
        } else {
            --hashmap[*it_note];
        }
    }
    cout << "Yes" << endl;
}