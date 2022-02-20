#include <iostream>
#include <fstream>
#include <string.h>
#include "dicttree.h"



using namespace std;


// Main program
int main(int argc, char **argv)
{
    if(argc == 3)
{
    // Declare number of command line arguments to 3
    // 1) ./countwords for executable file
    // 2) Specify the file path to the dictionary source for building the dictionary tree
    // 3) Specify the file path to the test file for searching words in the dictionary tree


    // Initialize a new dictionary
    struct dictNode *dictnode = createANewNode();

    for(int i = 1; i < argc; i++)
    {
        std::ifstream dictstream(argv[i]);   // Read the text file. In this case, only consider i = 1 or 2

        if(dictstream.is_open())
        {
            string line;
            int result;   // Number of words counted


            const char *delimiters = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~";   // Declare delimiters


            while(std::getline(dictstream, line))
                {
                    char *line_c = &line[0];   // Convert string to char

                    char *word = strtok(line_c, delimiters);   // Split words in text file using delimiters

                    while(word != NULL)
                        {
                            if(i == 1)   // Read argv[1] as dictionary source file
                            {
                                // Call insertWord function to insert words to build dictionary tree
                                insertWords2Dictionary(dictnode, word);
                            }
                            else   // Read argv[2] as the test file
                            {
                                // Call searchWord function
                                // Call countWord function inside searchWord
                                findEndingNodeOfAStr(dictnode, word);
                            }


                            // Read next word
                            word = strtok(NULL, delimiters);

                        }

                }

        }

        else
            {
                cout << "Cannot open the file!!!\n";   // Fail to open file. Exit!
                exit(1);
            }
    }
}
    else
    {
        cout << "ERROR. Invalid number of arguments!\n";
    }

    return 0;

}
