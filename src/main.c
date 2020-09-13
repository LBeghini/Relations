#include "set.h"
#include <stdio.h>
#include "fileIO.h"
#include <conio.h>
#include "global.h"
#define PATH "..\\set.txt"
#include "operations.h"


int main() {
    Line *input = process_input(PATH);
    listOfSets = (Set*) malloc(sizeof(Set));
    listOfSets = create_list_set(listOfSets, input);
    printf("%s", set_to_string(domain_and_image(equals(listOfSets->head, listOfSets->head))));
    return 0;
}
