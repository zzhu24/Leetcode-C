int lengthOfLongestSubstring(char* s) {
    int count = 0;
    int max = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    bool check[200];
    for(int i = 0; i < 200; i++){
        check[i] = false;
    }
    int size = strlen(s);
    while(b < size){
        if(check[s[b]] == true){
            if(count >= max){
                max = count;
            }
            c = a;
            while(s[c] != s[b]){
                check[s[c]] = false;
                c ++;
            }
            a = c + 1;
            count = b - c - 1;
        }
        check[s[b]] = true;
        b ++;
        count ++;
    }
    if(count >= max){
        max = count;
    }
    return max;
}