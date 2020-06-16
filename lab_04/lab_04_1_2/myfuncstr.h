#ifndef _MYFUNCSTR_H
#define _MYFUNCSTR_H

#define STRMAX 256
#define WORDMAX 16
#define COUNTWORD 128

int clean_word_str(char word_str[COUNTWORD][WORDMAX], int n);
void sort(char word_str[COUNTWORD][WORDMAX], int n);
void change1(char word_str[COUNTWORD][WORDMAX], int k);
void change2(char word_str[COUNTWORD][WORDMAX], int j);
int string_split(const char *const str, char word_str[COUNTWORD][WORDMAX], const char *const symbols);
void print(char word_str[COUNTWORD][WORDMAX], int n);
int check(char word_str[COUNTWORD][WORDMAX], int n);

#endif // _MYFUNCSTR_H
