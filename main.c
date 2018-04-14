#include "filler.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"

int main(int ac, char **av)
{
    char *input;
    FILE *f;

    f = fopen("vm_input.txt", "w+");
    fprintf(f, "ac = %d & av[0] = %s\n", ac, av[0]);
    int i = 0;
    while (i++ < 25 && get_next_line(0, &input) > 0)
        fprintf(f, "%s\n", input);
    fclose(f);
    return (0);
}
