
// Complete the squares function below.
int squares(int a, int b) {
    int count = 0;
    int s = 1;
    int n = s;
    while (s <= b)
    {
        s = n*n;
        if (s >= a && s <= b)
            ++count;
        ++n;
    }
    return count;
}