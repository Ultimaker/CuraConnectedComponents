#include "word.h"


char* Word::reverse() const
{
    int length;
    for (length = 0; the_word[length] != '\0'; length++)
    {
    }
    
    char* reversed = new char[length+1];
    for (int i = 0; i < length; i++)
    {
        reversed[i] = the_word[length-i-1];
    }
    reversed[length] = '\0';
    
    return reversed;
}
