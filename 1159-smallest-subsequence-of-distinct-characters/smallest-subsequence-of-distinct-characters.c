char* smallestSubsequence(char* s) {
    int freq[26] = {0};
    int visited[26] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++)
        freq[s[i] - 'a']++;

    char *stack = (char *)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        freq[ch - 'a']--;

        if (visited[ch - 'a'])
            continue;

        while (top >= 0 &&
            stack[top] > ch &&
            freq[stack[top] - 'a'] > 0) {
            visited[stack[top] - 'a'] = 0;
            top--;
        }

        stack[++top] = ch;
        visited[ch - 'a'] = 1;
    }

    stack[top + 1] = '\0';
    return stack;
}