char* longestPalindrome(char* s) {
    
    //char* test = (char *)calloc(sizeof(char), 5);
    //test = "cbbd";
    int length = strlen(s);//not include the last null
    if(length < 2){
        return s;
    }
    
    int a = 0;//index of start
    int b = 0;//index of end
    int center = 0;
    
    int max = 0;
    int count = 0;
    int maxA = 0;
    int maxB = 0;
    
    //odd length substring
    for(; center < length; center ++){
        a = center;
        b = center;
        
        while(a >= 0 && b < length && s[a]==s[b]){
            a = a - 1;
            b = b + 1;
        }
        
        count = b - a - 1;
        
        if(count > max){
            max = count;
            maxA = a + 1;
            maxB = b - 1;
        }
    }
    printf("first: maxA = %d, maxB = %d, max = %d\n", maxA, maxB, max);
    
    //even length substring
    center = 0;
    for(; center < length - 1; center ++){
        a = center;
        b = center + 1;
        
        while(a >= 0 && b < length && s[a]==s[b]){
            a = a - 1;
            b = b + 1;
        }
        
        count = b - a - 1;
        
        if(count > max){
            max = count;
            maxA = a + 1;
            maxB = b - 1;
        }
    }
    printf("second: maxA = %d, maxB = %d, max = %d", maxA, maxB, max);
    
    char * result = (char*)calloc(max + 1, sizeof(char));
    for(int i = 0; i < max; i++){
        result[i] = s[maxA + i];
    }
    
    return result;
    
}