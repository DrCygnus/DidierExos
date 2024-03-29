#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char tab[10001] = "Qui que quoi quand quid coq";
    int taille = strlen(tab);
    int alphatab[26] = {0};
    int cpt = 0;
    int test = 0;
    for (int i = 0; i < taille; i++)
    {
        /*@ invariant 0<=i && i < taille; */
        tab[i] = toupper(tab[i]);
        /*@ assume StrManip: tab[i] > 65; */
        if (tab[i] - 65 >= 0)
        {
        alphatab[tab[i] - 65] += 1;
        }
        else {}
    }
    for (int j = 0; j < 26; j++)
    {
        if (alphatab[j] > cpt)
        {
            cpt = alphatab[j];
            test = j;
        }
    }
    printf("%c\n", (test + 65));
    return (test + 65);
}
