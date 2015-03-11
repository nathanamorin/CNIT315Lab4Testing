#ifndef LAB4_LIB_H_
#define LAB4_LIB_H_


int wordCount(char* sentence_array, int count, int start, int maxSize);
/*
  This function counts the number of words in a char array
  sentence_array needs to be the character array that has all of the words to be counted
  count needs to be initialized to 0
  start needs to be initialized to 0
  maxSize needs to be the maximum size of the character array entered
*/

int wordRemove(char* sentence_array, int maxSize);
/*
  This function removes a single word from a char array.
  sentence_array needs to be the char array that has the word that you want removed
  maxSize needs to be the maximum size of the character array entered
*/

void vowelCheck();
/*
  This function counts the number of vowels in a char array
  the function does not require any input
*/

int substring();
/*
  This function prints the characters in a substring
  The char array is made inside of the function
  the function does not require any input.
*/
#endif
