
// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    const char alpha [] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'};
    map<char, int> alpha_m;
    for (int i = 0; i < h.size(); ++i)
        alpha_m[alpha[i]] = h[i];

    int max_height = 0;
    for (int j = 0; j < word.size(); ++j)
        if (alpha_m[word[j]] > max_height)
            max_height = alpha_m[word[j]];

    return (word.size() * max_height);
}