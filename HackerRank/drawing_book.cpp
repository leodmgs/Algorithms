/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    int lp = n % 2 == 0 ? 1 : 0;
    return p <= (n / 2) ? (p / 2) : ((n - p + lp) / 2);
}