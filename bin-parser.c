#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/*
 How this shit has to work:
 
 user@pc$~ ./bin-parse "01100001 01100111 01100111 01101001 01101110 00001010"
 aggin
 user@pc$~ 

 then from file

 user@pc$~ ./bin-parse -f bin-file.txt
 <things he has in this file idk>
 user@pc$~

 and help menu
 
 user@pc$~ ./bin-parse -h
 <help-message>
 user@pc$~
*/

int main(int argc, char* argv[])
{
    //Programm modes
    bool helpMode = false;
    bool fileMode = false;
    bool commonMode = false;

    //Parse args
    for(int i = 1; i < argc; i++)
    {
        if(argv[i] == "-f")
        {
            fileMode = true;
            printf("FILE MODE TRUE");
        }
        if(argv[i] == "-h")
        {
            helpMode = true;
            printf("HELP MODE TRUE");
        }
        else
        {
            commonMode = true;
            printf("COMMON MODE TRUE");
        }
        
    }
    //Check args
    if(fileMode && helpMode || fileMode && commonMode || commonMode && helpMode || fileMode && commonMode && helpMode)
    {
        printf("\nToo maany arguments.\n");
        printf("Please run %c./bin-parse -h%c for help. \n", 34,  34);
    }
    /*
    if(argc > 1)
    {    
        char bin_msg[] = argv[1];
    }
    else if(argc == 1)
    {
        char bin_msg[] = argv[0];
    }
    else if(argc == 0)
    {
        printf("\nText to decode was not provided/Too few argumets.\n");
        printf("Please run %c./bin-parse -h%c for help. \n", 34,  34);
    }
    */
}