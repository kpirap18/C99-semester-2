#ifndef INPUTSTR_H
#define INPUTSTR_H

#define STRMAX 257
#define WORDMAX 17
#define COUNTWORD 129

int string_split(char *str, char *pword_array[], \
                 char word_array[COUNTWORD][WORDMAX], \
                 const char *const symbols);

#endif // INPUTSTR_H
