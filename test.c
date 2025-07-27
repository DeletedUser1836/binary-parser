#include <stdio.h>
#include <string.h>

int main()
{
    char longass[] = "01100110 01100110 01100110 01100110 01020200 ";
    int i = (strlen(longass) % 8) + 1;
    printf("%d", i);
    /*for(size_t i = strlen(longass) - (strlen(longass) % 8) - 1; i > 0; i++)
    {
        for (size_t i = 0; i < count; i++)
        {
            
        }
        
    }
    */
}