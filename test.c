#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char longass[] = "01100110 01100110 0110                                     0110  01100110 01020200  ";
    size_t write_idx = 0;
    for(size_t read_idx = 0; read_idx < strlen(longass); read_idx++)
    {
        if(!isspace(longass[read_idx]))
        {
            longass[write_idx] = longass[read_idx];
            write_idx++;
        }
    }
    longass[write_idx] = '\0';
    printf("%s", longass);
    
    //TODO TS-↓
    size_t currPoint = 0;
    for(size_t i = (strlen(longass) % 8) + 1; i < 3; i++)
    {
        for (size_t j = 0; j <= 8; j++)
        {
            //12345678
            //01010101
            
        }
        
    }
}