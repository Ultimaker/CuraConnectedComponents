// Define the interface to the word library.
#ifndef WORD_H
#define WORD_H

class Word {
    const char *the_word;

public:
    Word(const char *w) : the_word(w) { }

    char* reverse() const;
}; 

#endif // WORD_H