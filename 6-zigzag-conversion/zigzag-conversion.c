char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len)
        return s;

    char *ans = (char*)malloc(len + 1);
    int k = 0;
    int cycle = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycle) {
            ans[k++] = s[j];

            int diag = j + cycle - 2 * i;
            if (i != 0 && i != numRows - 1 && diag < len)
                ans[k++] = s[diag];
        }
    }

    ans[k] = '\0';
    return ans;
}