#include "set.h"
#include <stdio.h>
#include "fileIO.h"
#include <conio.h>
#include "global.h"
#define PATH "..\\set.txt"
#include "operations.h"
#include "validation.h"

void clear_console(){
#if defined _WIN32
    system("cls");
#elif defined (LINUX) || defined(gnu_linux) || defined(linux)
    system("clear");
#elif defined (APPLE)
    system("clear");
#endif
}

void print_set(Set* sets){
    printf("       %c = {", sets->name);
    Node* current = sets->head;
    while (current){
        printf("%d", current->value);
        if(current->next){
            printf(", ");
        } else{
            printf("}\n");
        }
        current = current->next;
    }
}

void print_sets(Set* set){
    while (set){
        print_set(set);
        set = set->next;
    }
}

char * int_to_bool(int input){
    if(input){
        return "true";
    } else{
        return "false";
    }
}
void solve(char* input){
    remove_spaces(input);
    if(validate(input)){
        Relation * solution = generate_relation(prepare_operation_list(input));
        printf("------------------------------------------------\n");
        printf("R: %c -> %c\n", solution->initial->name, solution->final->name);
        printf("%s\n", couple_to_string(solution->couple));
        printf("Domain: %s\n", node_to_string(solution->domain));
        printf("Image: %s\n", node_to_string(solution->image));
        printf("Functional: %s\n", int_to_bool(solution->functional));
        printf("Injective: %s\n", int_to_bool(solution->injective));
        printf("Total: %s\n", int_to_bool(solution->total));
        printf("Surjective: %s\n", int_to_bool(solution->surjective));

        if(solution->isomorphism){
            printf("Isomorphism\n");
        }else if(solution->monomorphism){
            printf("Monomorphism\n");
        }else if(solution->epimorphism){
            printf("Epimorphism\n");
        }

        printf("------------------------------------------------\n");

    } else{
        printf("------------------------------------------------\n");
        printf("ERROR: OPERATION NOT VALID\n");
        printf("------------------------------------------------\n");
    }

}



int main() {
    Line *input = process_input(PATH);

    listOfSets = (Set*) malloc(sizeof(Set));
    listOfSets = create_list_set(listOfSets, input);

#ifndef DEBUG
    clear_console();
    printf("  _____      _       _   _                 \n"
           " |  __ \\    | |     | | (_)                \n"
           " | |__) |___| | __ _| |_ _  ___  _ __  ___ \n"
           " |  _  // _ \\ |/ _` | __| |/ _ \\| '_ \\/ __|\n"
           " | | \\ \\  __/ | (_| | |_| | (_) | | | \\__ \\\n"
           " |_|  \\_\\___|_|\\__,_|\\__|_|\\___/|_| |_|___/\n"
           "                                           \n"
           "                                           ");


    printf("\nPRESS ANY KEY TO START");
    getch();

    char e = ' ';

    while (e != 'e'){
        clear_console();
        printf("------------------------------------------------\n");
        printf(" SETS:                                          \n");
        print_sets(listOfSets);
        printf("\n");
        printf("------------------------------------------------\n");
        printf(" OPERATIONS:\n");
        printf("       Greater than:......................... >\n"
               "       Less than:............................ <\n"
               "       Equals:............................... =\n"
               "       Square of:............................ *\n"
               "       Square root of:....................... /\n\n"
               );
        printf("------------------------------------------------\n");
        printf("OPERATION STRING: ");
        char* ops = (char*)calloc(10, sizeof(char));
        gets(ops);
        solve(ops);
        printf("\nPRESS ANY KEY TO CONTINUE OR e TO EXIT");
        e = getch();
    }
#endif


    return 0;
}
