#include <stdio.h>
#define PATH "..\\set.txt"

#include "fileIO.h"
int main() {
    Line *input = process_input(PATH);
    print_lines(input);

    return 0;
}
