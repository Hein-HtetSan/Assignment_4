#include "stdio.h"
#include "stdlib.h"

// case sensativie in capitable letter and smaller letter

void findWord(char word[100]);
char word[100];

int main()
{
    printf("Find word: ");
    scanf("%s", &word);
    // finding words
    findWord(word);
    return 0;
}

void findWord(char word[100])
{
    FILE *file;
    int size = 0;
    file = fopen("word.txt", "r");
    for(int i=0 ;i<100; i++)
    {
        if(word[i] >=65 && word[i] <= 90 || word[i] >=97 && word[i] <= 122)
        {
            size++;
        }else{
            break;
        }
    }
    if(file != NULL)
    {
        int found = 0;
        int index=0;
        int count=0;    
        char c = fgetc(file);
        while(!feof(file))
        {
            if(c == word[index])
            {
                index++;
                found = index;
                if(found == size)
                {
                    count++;
                    found=0;
                }
            }
            else{
                index = 0;
            }
            c = fgetc(file);                
        }
        if(count > 1)
        {
            printf("We found %s: %d times", word, count);
        }else{
            printf("We found %s: %d times", word, count);
        }
        found=0;
    }
    fclose(file);   
}
