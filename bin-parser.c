#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
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

char* clearText(char* bin_text[])
{
    size_t write_idx = 0;
    for(size_t read_idx = 0; read_idx < strlen(bin_text); read_idx++)
    {
        if(!isspace(bin_text[read_idx]))
        {
            bin_text[write_idx] = bin_text[read_idx];
            write_idx++;
        }
    }
    return bin_text;
}

int main(int argc, char* argv[])
{
    char mode = ' ';
    /*  MODES:

        f - file mode
        h - help mode
        d - decode mode
    */

    //Parse args
    if(argc == 1)
    {
        printf("Neither the text or path to a file was not provided.\n");
        printf("Use the \"--help\" flag to see the help text.\n");
    }
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-d") == 0)
        {
            if(argc == 3)
            {
                mode = 'd';
            }
            else if (argc > 3)
            {
                printf("Too many arguments was provided.\n");
            }
            else if(argc < 3)
            {
                printf("Text to decode was not provided.\n");
            }
        }
        if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0)
        {
            if(argc == 3)
            {
                mode = 'f';
            }
            else if (argc > 3)
            {
                printf("Too many arguments was provided.\n");
            }
            else if(argc < 3)
            {
                printf("Path to file was not provided.\n");
            }
            
        }
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            mode = 'h';
            printf("\nbin-parse - command to change text from binary to normal ASCII characters");
            printf("\n\nModes:");
            printf("\n\nDecode Mode: ");
            printf("\nJust put the binary text to decode in the quotes after the \"-d\" flag.");
            printf("\n./bin-parse \"01110100 01100101 01111000 01110100\"");
            printf("\n\nFile Mode: ");
            printf("\nPut the path to the file with binary text after the \"-f\" or the \"--file\" flag.");
            printf("\n./bin-parse -f /path/to/the/file");
            printf("\n\nHelp mode: ");
            printf("\nUse the \"-h\"or the \"--help\" flag to see this text.\n\n");
        }
    }
    
    char* bin_text = NULL;
    char decoded_text[4096] = "";
    switch (mode)
    {
        case 'd':
        {
            bin_text = argv[3];
            clearText(bin_text);

            //TODO

            break;
        }
        case 'f':
        {
            FILE* file = fopen(argv[3], "r");
            if (file == NULL)
            {
                perror("File open error.\n");
                return 1;
            }
            bin_text = file;
            clearText(bin_text);

            //TODO

            bin_text = decoded_text;
            break;
        }

        default:
        {
            printf("Something went wrong. Please run the program again.\n");
            break;
        }
    }
}