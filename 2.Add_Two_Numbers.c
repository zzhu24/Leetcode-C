/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * re1 = l1;
    //re1 = l1;
    struct ListNode * re2 = l2;
    //re2 = l2;
    int sum = 0;
    while(re1 != NULL && re2 != NULL){
        sum = re1 -> val + re2 -> val + sum;
        if(sum >= 10){
            re1 -> val = sum - 10;
            re2 -> val = sum - 10;
            sum = 1;
        }
        else{
            re1 -> val = sum;
            re2 -> val = sum;
            sum = 0;
        }
        if(re1 -> next == NULL || re2 -> next == NULL){
            break;
        }
        re1 = re1 -> next;
        re2 = re2 -> next;
    }
    struct ListNode * temp= (struct ListNode *)malloc(sizeof(struct ListNode));
    temp -> next = NULL;
    if(sum == 1 && re1 -> next == NULL && re2 -> next == NULL){
        re1 -> next = temp;
        re1 = re1 -> next;
        re1 -> val = 1;
        return l1;
    }
    else if(re1 -> next != NULL){
        re1 = re1 -> next;
        while(re1 != NULL){
            sum = re1 -> val + sum;
            if(sum >= 10){
                re1 -> val = sum - 10;
                sum = 1;
            }
            else{
                re1 -> val = sum;
                sum = 0;
            }
            if(re1 -> next == NULL){
                break;
            }
            re1 = re1 -> next;
        }
        if(sum == 1){
            //struct ListNode * temp1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            //temp1 -> next = NULL;
            re1 -> next = temp;
            re1 = re1 -> next;
            re1 -> val = 1;
        }
        return l1;
    }
    else if(re2 -> next != NULL){
        re2 = re2 -> next;
        while(re2 != NULL){
            sum = re2 -> val + sum;
            if(sum >= 10){
                re2 -> val = sum - 10;
                sum = 1;
            }
            else{
                re2 -> val = sum;
                sum = 0;
            }
            if(re2 -> next == NULL){
                break;
            }
            re2 = re2 -> next;
        }
        if(sum == 1){
            //struct ListNode * temp2 = (struct ListNode *)malloc(sizeof(struct ListNode));
            //temp2 -> next = NULL;
            re2 -> next = temp;
            re2 = re2 -> next;
            re2 -> val = 1;
        }
        return l2;
    }
    else{
        return l1;
    }
}










