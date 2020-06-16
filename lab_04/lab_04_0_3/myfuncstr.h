#ifndef _MYFUNCSTR_H
#define _MYFUNCSTR_H

#define STRMAX 257
#define WORDMAX 17
#define COUNTWORD 129

int clean(char word_array[COUNTWORD][WORDMAX], int n);
void word_arr(char word_array[COUNTWORD][WORDMAX], int n);
void str_new(char new_str[STRMAX], char word_array[COUNTWORD][WORDMAX], int n);
int string_split(char *str, char *pword_array[], char word_array[COUNTWORD][WORDMAX], const char *const symbols);

#endif // _MYFUNCSTR_H
