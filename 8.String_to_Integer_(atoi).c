int myAtoi(char* str) {
    
    //discard white space
    //all numbers start with an minus or plus sign
    //find the first correct sequence of numbers
    //return 0 if no sequence adapt
    //return INT_MAX (2147483647) or INT_MIN (-2147483648) if out of range
    
    char * start = str;
    int sign = 1;
    int result = 0;
    bool begin = false;
    bool have = false;
    
    while(* start != '\0'){
        
        //printf("%c\n", * start);
        if(*start != '-' && *start != '+' && (*start < '0' || *start > '9') && *start != ' '){
            return result;
        }
        
        //while(*start == ' '){
        //    start ++;
        //}
        
        if(*start == '-' || *start == '+' || (*start >= '0' && *start <= '9')){
            //printf("%c\n", * start);
            if(*start == '-' || *start == '+'){
                sign = (*start == '-') ? -1:1;
                start ++;
                begin = true;
            }
            if(*start >= '0' && *start <= '9'){
                begin = true;
            }
            //if(begin){
            //    sign = (*start == '-') ? -1:1;
            //    printf("%d\n", sign);
            //}
            if(have){
                return result;
            }
        }
        
        //if(begin){
        //    sign = (*start == '-') ? -1:1;
        //    printf("%d\n", sign);
        //}
        
        if((*start < '0' || *start > '9')&&begin){
            have = true;
            begin = false;
        }
        
        if(*start >= '0' && *start <= '9' && begin && sign == 1){
            if(result < 214748364 || (result == 214748364 && *start <= '7')){
                result = result * 10 + *start - '0';
            }
            else{
                return INT_MAX;
            }
        }
        
        else if(*start >= '0' && *start <= '9' && begin && sign == -1){
            if(result > -214748364 || (result == -214748364 && *start <= '8')){
                result = result * 10 - *start + '0';
                printf("%d\n", result);
            }
            else{
                return INT_MIN;
            }
        }
        
        else if(begin && (*start < '0' || *start > '9')){
            begin = false;
        }
        
        start ++;
    }
    
    return result;
    
}






