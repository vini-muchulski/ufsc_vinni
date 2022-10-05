#include <stdio.h>



int main()
{
    char String[] = "  Junte  estas      palavras  ! ";
    for(int x = 0; String[x] != '\0'; x++)
    {
        while(String[x] == ' ')
        {
            for(int y = x; String[y] != '\0'; y++)
            {
                String[y] = String[y + 1];
            }
        }
    }
    printf("String: \"%s\".", String);
    return 0;
}