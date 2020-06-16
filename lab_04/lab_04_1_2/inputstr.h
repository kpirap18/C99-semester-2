#ifndef _INPUTSTR_H_
#define _INPUTSTR_H_

#define STRMAX 256
#define WORDMAX 16
#define COUNTWORD 128

int string_split(const char *const str, \
                 char word_str[COUNTWORD][WORDMAX], \
                 const char *const symbols);
void print(char word_str[COUNTWORD][WORDMAX], int n);
int check(char word_str[COUNTWORD][WORDMAX], int n);

#endif // _INPUTSTR_H_

