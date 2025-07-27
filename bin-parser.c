#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    for(int i = argc; i != 0; i--)
    {
        printf("\n Argument %d is argv[%d] and it is %s", i, i, argv[i]);
    }
    return 0;
}