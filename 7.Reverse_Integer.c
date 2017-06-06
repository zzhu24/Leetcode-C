int reverse(int x) {
    
    //printf("%d", x);
    
    int result = 0;
    int start = 0;
    bool isNegative = false;
    
/*    
    if(x > 65535 || x < -65536){
        return 0;
    }
*/    

    if(x == -2147483648){
        return 0;
    }

    if(x < 0){
        start = -x;
        printf("%d", -x);
        isNegative = true;
    }
    else{
        start = x;
    }
    
    while(start != 0){
        if(result > 214748364){
            return 0;
        }
        result = result * 10;
        result = result + start%10;
        start = start / 10;
        
        printf("start = %d, result = %d\n", start, result);
    }
    
    if(isNegative ==  true){
        result = -result;
    }
    
/*
    if(result > 2147483647 || result < -2147483648){
        return 0;
    }
*/  
    
    return result;
    
}