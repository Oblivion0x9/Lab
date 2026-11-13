#include <stdio.h>
#include <stdlib.h>


void cifra(char testo[], int chiave);
void decifra(char testo[], int chiave);

int main()
{

    char testo[100];
    int chiave = 3;

    printf("Inserisci il testo da cifrare: ");
    fgets(testo, sizeof(testo), stdin);

    printf("\nInserisci la chiave numerica: ");
    scanf("%d", &chiave);




    printf("\n\nTesto in chiaro: %s", testo);

    cifra(testo, chiave);

    printf("\nTesto cifrato: %s", testo);

    decifra(testo, chiave);

     printf("\n\nTesto decifrato: %s", testo);

    return 0;
}

void cifra(char testo[], int chiave)
{
    for (int i = 0; testo[i] != '\0'; i++)
    {
        testo[i] = testo[i] + chiave;
    }
}

void decifra(char testo[], int chiave)
{
    for (int i = 0; testo[i] != '\0'; i++)
    {
        testo[i] = testo[i] - chiave;
    }
}
