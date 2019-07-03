
bool match(int s, int sf, int g, int gf)
{
    int s_acc = (s + sf);
    int g_acc = (g + gf);
    while (s_acc <= g_acc)
    {
        if (s_acc == g_acc)
            return true;
        s_acc += sf;
        g_acc += gf;
    }
    return false;
}

// Complete the kangaroo function below.
string kangaroo(int x1, int v1, int x2, int v2) {
    bool has_match = (x1 + v1) < (x2 + v2) ? match(x1,v1,x2,v2) : match(x2,v2,x1,v1);
    return has_match ? "YES" : "NO";
}