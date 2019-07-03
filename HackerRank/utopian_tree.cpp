// Complete the utopianTree function below.
int utopianTree(int n) {
    int ut = 1;
    for (int i = 1; i <= n; ++i)
        ut = (i%2==0) ? ut+1 : 2*ut;
    return ut;
}