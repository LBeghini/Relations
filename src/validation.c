//
// Created by Lavinia on 9/14/2020.
//

#include "validation.h"

int validate(char *str) {
    if (is_odd((int)strlen(str)) && (int)strlen(str) > 1) {
        if(check_operators(str)){
            if(check_operands(str)){
                return 1;
            }
        }

    }
    return 0;
}

int check_operators(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (is_odd(i)) {
            if(!strchr(OPERANDS, *(str+i))){
                return 0;
            }
        }
    }
    return 1;
}

int check_operands(char *str){
    int validation = 1;
    for (int i = 0; i < strlen(str); ++i) {
        char current = *(str+i);
        if (!is_odd(i)) {
            if(current>='A' && current<='Z'){
                if(!contains_in_sets(current)){
                    validation = 0;
                }
            }else{
                validation = 0;
            }
        }
    }

    return validation;
}


int contains_in_sets(char target) {
    Set *current = listOfSets;
    while (current) {
        if (current->name == target) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int is_odd(int num) {
    return num % 2;
}



