#include "main.h"
/**
 * leet - encodes a string into 1337
 * @s: input string.
 * Return: the pointer dest.
 */

char *leet(char *s)
{
  int i, j;
  int lower_case[] = {97, 101, 111, 116, 108};
  int upper_case[] = {65, 69, 79, 84, 76};
  int numbers[] = {52, 51, 48, 55, 49};
  
  for (i = 0; s[i] != '\0'; i++)
  {
    for (j = 0; j < 5; j++)
    {
      if (s[i] == lower_case[j] || s[i] == upper_case[j])
      {
        s[i] = numbers[j];
        break;
      }
    }
  }
  return (s);
}
