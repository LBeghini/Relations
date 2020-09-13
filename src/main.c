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
    equals(listOfSets->head, listOfSets->head);
    return 0;
}
