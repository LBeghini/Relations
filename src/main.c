#include "set.h"
#include <stdio.h>
#include "fileIO.h"
#include <conio.h>
#include "global.h"
#define PATH "..\\set.txt"


int main() {
    Line *input = process_input(PATH);
    listOfSets = (Set*) malloc(sizeof(Set));
    listOfSets = create_list_set(listOfSets, input);

    return 0;
}
