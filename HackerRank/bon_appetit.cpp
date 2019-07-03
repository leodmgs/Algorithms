
// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
    long total = 0;
    vector<int>::iterator it;
    for (it = bill.begin(); it != bill.end(); ++it)
        total += *it;
    int calc = (total - bill[k]) / 2;
    if (calc != b)
        cout << b - calc << endl;
    else
        cout << "Bon Appetit" << endl;
}