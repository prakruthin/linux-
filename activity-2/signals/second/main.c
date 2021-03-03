#include "count.h"

int main()
{
  printf("open file \n");
  checkfile();
  printf("Lines : %d\n", getLines());
  printf("Words : %d\n", getWords());
  printf("Characters : %d\n", getCharacters());
}
