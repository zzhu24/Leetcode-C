char* convert(char* s, int numRows) {
    
    int origin = 0;
    int count = 0;
    
    if(strlen(s) <= numRows || s[0]=='\0' || numRows==1){
        return s;
    }
    
    char *result = (char *)calloc(strlen(s)+1, 1);
    result[strlen(s)] = '\0';
    
    //for the very first row:
    origin = 0;
    //int read = 1;
    while(origin < strlen(s)){
        result[count] = s[origin];
        count ++;
        origin = origin + 2*(numRows-1);
        //read++;
    }
    
    
    //for rows form 2 to n-1:
    for(int i = 2; i < numRows; i++){
        origin = 0;
        //read = 1;
        while(origin < strlen(s)){
            if(origin+i-1 >= strlen(s)){
                break;
            }
            result[count] = s[origin+i-1];
            count ++;
            if(origin + 2*(numRows-1)-i+1 >= strlen(s)){
                break;
            }
            result[count] = s[origin + 2*(numRows-1)-i+1];
            count++;
            origin = origin + 2*(numRows-1);
        }
    }
    
    //for the very last row:
    origin = numRows - 1;
    //read = 1;
    while(origin < strlen(s)){
        result[count] = s[origin];
        count ++;
        origin = origin + 2*(numRows-1);
        //read++;
    }
    
    
    return result;
    
}








