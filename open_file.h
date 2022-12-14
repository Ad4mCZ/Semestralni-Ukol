#define MAX_LINES 100
#define MAX_LENGTH 200
char data[MAX_LINES][MAX_LENGTH] = {{0}}; // 2d pole pro uchovavani radku
char otazky[MAX_LINES][MAX_LENGTH] = {{0}};
char odpovedi[MAX_LINES][MAX_LENGTH] = {{0}};
char spravne_odpovedi[MAX_LINES][MAX_LENGTH] = {{0}};

void Open_File(char *filename)
{
    FILE *file;
    file = fopen(filename, "r"); // otevreni souboru
    if (file == NULL)            // kontrola jestli existuje
    {
        printf("no such file.");
    }

    int line = 0; // pocitani radku

    while (!feof(file) && !ferror(file)) // pokud neni end of file nebo chyba
    {
        if (fgets(data[line], MAX_LENGTH, file) != NULL) // kontrola jestli nejsme na konci
        {
            line++;
        }
    }
    fclose(file); // zavreni souboru

    for (int i = 0, indexOtazky = 0, indexOdpovedi = 0; i < line; i++) // prochazeni dat
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            if (data[i][j] == '[')
            {
                for (int k = 1; data[i][j + k] != ']'; k++)
                {
                    otazky[indexOtazky][k - 1] = data[i][j + k];
                }
                indexOtazky++;
            }
            else if (data[i][j] == '(')
            {
                for (int k = 1; data[i][j + k] != ')'; k++)
                {
                    odpovedi[indexOdpovedi][k - 1] = data[i][j + k];
                }
                indexOdpovedi++;
            }
        }
    }
}