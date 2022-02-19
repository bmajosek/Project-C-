#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define N 5000
#define YES 1
#define NO 2
#define M 4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* result, * argumentx, * argumenty;
int bad = 0, bad2 = 0;

void fill(char* x)
{
    int length = strlen(x);
    for (int i = 0; i < length; i++)
    {
        if (x[i] > 'Z')
        {
            x[i] = '\0';
        }
        if (x[i] < '0')
        {
            x[i] = '\0';
        }
        if (x[i] > '9' && x[i] < 'A')
        {
            x[i] = '\0';
        }
    }
    return;
}
/* Funkcja zwracajaca liczbe od tylu */
void reverse(char* x)
{
    int length = strlen(x), len3;
    len3 = length + 5;
    char* p;
    p = (char*)calloc(len3, sizeof(char));
    if (p != NULL)
    {
        /* length to zmienna przechowujaca dlugosc podanej liczby x */
        for (int i = 0; i < length; i++)
        {
            p[i] = x[length - i - 1];
        }
        for (int i = 0; i < length; i++)
        {
            x[i] = p[i];
        }
    }
    return;
}
/* Funkcja porownujaca dwie liczby x,y */
int isbigger(char* x, char* y) {

    int lex = strlen(x);
    int ley = strlen(y);
    int i, j = 0;
    for (i = 0; i < lex - 1; i++)
    {
        if (x[i] == '0') j++;
        else
            break;
    }
    if (j > 0)
    {
        for (i = 0; i + j < lex; i++)
        {
            x[i] = x[i + j];
        }
        for (i = lex - j; i < lex; i++)
        {
            x[i] = '\0';
        }
    }

    j = 0;
    for (i = 0; i < ley - 1; i++)
    {
        if (y[i] == '0') j++;
        else
            break;
    }
    if (j > 0)
    {
        for (i = 0; i + j < ley; i++)
        {
            y[i] = y[i + j];
        }
        for (i = lex - j; i < ley; i++)
        {
            y[i] = '\0';
        }
    }
    if (x[0] == '0' && y[0] == '0')
    {
        return 0;
    }
    /* lex, ley to zmienne przechowujace odpowiednio dlugosc liczby x, y */
    if (lex > ley)
    {
        return YES;
    }
    if (ley > lex)
    {
        return NO;
    }
    /* Funckja isbigger() zwraca odpowiednio 1 albo 2 odpowiednio jezeli
    pierwsza liczba jest wieksza od drugiej lub jezeli druga jest wieksza od pierwszej */
    for (int i = 0; i < lex; i++)
    {
        if (x[i] > y[i])
        {
            return YES;
        }
        if (x[i] < y[i])
        {
            return NO;
        }
    }
    /* Funckja isbigger() zwraca 0, jezeli liczby x i y sa rowne */
    return 0;
}
/* Funkcja zamieniajaca wartosc x z y */
void change(char* x, char* y)
{
    char* tmp = x;
    /* tmp to zmienna pomocnicza przechowujaca jedna z liczb */
    strcpy(tmp, x);
    strcpy(x, y);
    strcpy(y, tmp);
    return;
}
/* Funkcja zwracajaca sume dwoch liczb x i y */
void add(char* x, char* y, char* out)
{
    int maks = 0, howmuch = 0, j = 0, sum = 0, i;
    if (strlen(x) > strlen(y))
    {
        maks = strlen(x);
    }
    else {
        maks = strlen(y);
    }
    /* Zmienna maks przechowuje dlugosc wiekszej liczby */
    /* Zmienna howmuch przechowuje liczbe wykraczajaca poza zakres [0;9]
    Zmienna j przechowuje obecna dlugosc liczby wyjsciowej
    Zmienna sum przechowuje sume cyfry x z y */
    strrev(x);
    strrev(y);
    /* Odwracam obydwie liczby, aby dodawac odpowiednio od cyfry najmlodszej do najstarszej */
    for (i = 0; i < maks; i++)
    {
        /* Sprawdzam, czy obydwie liczby nadal maja wartosc o danym indeksie i */
        if (x[i] >= '0' && x[i] <= '9' && y[i] >= '0' && y[i] <= '9')
        {
            sum = x[i] + y[i] - '0' - '0' + howmuch;
        }
        else if (x[i] >= '0' && x[i] <= '9')
        {
            sum = x[i] - '0' + howmuch;
        }
        else if (y[i] >= '0' && y[i] <= '9')
        {
            sum = y[i] - '0' + howmuch;
        }
        if (sum > 9)
        {
            howmuch = 1;
        }
        else
        {
            howmuch = 0;
        }
        /* Sprawdzam czy sum jest wieksze od 9, aby wiedziec, czy suma wykracza poza mozliwy zasieg zapisania na jednym indeksie wyniku */
        sum = sum % 10;
        out[j] = sum + '0';
        j++;
        /* Dopisuje do wyniku sume i zwiekszam dlugosc wyniku sumy */
    }
    if (howmuch != 0)
    {
        out[j] = howmuch + '0';
    }
    else
    {
        j--;
    }
    strrev(out);
    strrev(y);
    return;
}
/* Funkcja zwracajaca roznice dwoch liczb x i y */
void substract(char* x, char* y, char* end)
{
    int howmuch = 0, i, lex, ley, subs, le, bool, which, number, length;
    lex = strlen(x);
    ley = strlen(y);
    length = lex + 3;
    /* Zmienna howmuch przechowuje, czy istnieje zapozyczenie z kolejnego indeksu
    Zmienne lex, ley przechowujac odpowiednio dlugosc liczby x oraz y */
    char* res;
    res = (char*)calloc(length, sizeof(char));
    reverse(x);
    reverse(y);
    /* Odwracam obydwie liczby, aby odejmowac odpowiednio od cyfry najmlodszej do najstarszej */
    for (i = 0; i < ley; i++)
    {
        subs = (x[i] - '0') - (y[i] - '0') - howmuch;
        /* Zmienna roznica przechowuje rďż˝nicďż˝ cyfr o tych samych indeksach liczby x,y oraz zapoďż˝yczenia howmuch */
        if (subs < 0)
        {
            subs += 10;
            howmuch = 1;
        }
        else {
            howmuch = 0;
        }
        /* Sprawdzam czy istnieje zapozyczenie */
        res[i] = subs + '0';
    }
    for (i = ley; i < lex; i++)
    {
        /* Przepisuje do wyniku liczbe x, jezeli byla dluzsza od y i odejmuje pozostale zapozyczenie */
        subs = (x[i] - '0') - howmuch;
        if (subs < 0)
        {
            subs += 10;
            howmuch = 1;
        }
        else {
            howmuch = 0;
        }
        res[i] = subs + '0';
    }
    reverse(res);
    le = strlen(res);
    bool = 0;
    which = 0;
    for (i = 0; i < lex; i++)
    {
        end[i] = 0;
    }
    /* Przepisuje do wyniku liczbe wyn pomijajac zera */
    for (i = 0; i < le; i++)
    {
        number = res[i];
        
        if (number != '0')
        {
            bool = 1;
        }
        if (bool == 1)
        {
            end[which] = res[i];
            which++;
        }
    }
    reverse(x);
    reverse(y);
    reverse(end);
    free(res);
    return;
}
/* Funkcja zwracajaca iloczyn dwoch liczb x i y */
void multiple(char* x, char* y, char* end)
{
    int lex = strlen(x), ley = strlen(y), bool = 0, how = 0, i, lengt, j;
    lengt = lex * ley + 7;
    int* res;
    res = (int*)calloc(lengt, sizeof(int));
    /* Zmienne lex, ley przechowuja odpowiednio dlugosc liczby x oraz y */
    char* zero = "0";
    int howmuch = 0;
    if (isbigger(x, zero) == 0 || isbigger(y, zero) == 0)
    {
        add(result, zero, result);
        return;
    }
    strrev(x);
    strrev(y);
    /* Przypisuje do wyniczku odpowiednio iloczyn cyfr od najmlodszych do najstarszych na odpowiednich indeksach */
    for (i = 0; i < lex; i++)
    {
        for (j = 0; j < ley; j++)
        {
            res[i + j] += (x[i] - '0') * (y[j] - '0');
        }
    }
    /* Zapisuje odpowiednio ka�demu indeksowi w wyniczku cyfre z przedzia�u [0;9], a reszt� z dzielenia przez 10 zapisuje,
    jako 10, aby nastepnie moc ja dodac do starszego indeksu */
    for (i = 0; i < lex + ley; i++)
    {
        howmuch = res[i] / 10;
        res[i] = res[i] % 10;
        res[i + 1] += howmuch;
    }
    /* Zapisuje w wyniku wyniczek bez poprzedzajacych zer oraz zamieniam wszystkie cyfry na kod ASCII */
    for (i = lex + ley; i >= 0; i--)
    {
        if (res[i] != 0)
        {
            bool = 1;
        }
        if (bool == 1)
        {
            end[how] = res[i] + '0';
            how++;
        }

    }
    reverse(x);
    reverse(y);
    free(res);
    return;
}
/* Funkcja zwracajaca iloraz dwoch liczb x i y */
void divide(char* x, char* y)
{
    int length = strlen(x),i,lengthy=strlen(y), len;
    char* howmuch,*temp,*tem;
    len = length + 2;
    howmuch = (char*)calloc(len, sizeof(char));
    temp = (char*)calloc(len, sizeof(char));
    tem = (char*)calloc(len, sizeof(char));
    char* one = "1";
    char* zero = "0";
    if (isbigger(zero, y) == 0)
    {
        bad2 = 1;
        return;
    }
    if (isbigger(x, y) == 2)
    {
        add(result, zero, result);
        return;
    }
    fill(temp);
    add(temp, y, temp);
    for (i = lengthy;i<length-1; i++)
    {
        temp[i] = '0';
    }
    for (i = length-2; i > 0; i--)
    {
        tem[i] = '0';
    }
    tem[0] = '1';
    i = length;
    if (length == lengthy)
    {
        while (isbigger(result, x) == 2)
        {
            add(result, temp, result);
            if (isbigger(result, x) == 2)
            {
                add(howmuch, one, howmuch);
            }
        }
        change(result, howmuch);
        return;
    }
    while (i>lengthy)
    {
        while (isbigger(result, x) == 2)
        {
            
            add(result, temp, result);
            if (isbigger(result, x) == 2)
            {
                add(howmuch, tem, howmuch);
            }

        }
        substract(result, temp, result);
        temp[strlen(temp)-1] = '\0';
        tem[strlen(tem) - 1] = '\0';
        i--;
    }
    
    free(temp);
    free(tem);
    change(result, howmuch);
    free(howmuch);
    return;
}
void modulo(char* x, char* y)
{
    int length = strlen(x), i, lengthy = strlen(y), doorno = 1, len;
    char* howmuch, * temp, * tem;
    len = length + 3;
    howmuch = (char*)calloc(len, sizeof(char));
    temp = (char*)calloc(len, sizeof(char));
    tem = (char*)calloc(len, sizeof(char));
    char* one = "1";
    char* zero = "0";
    if (isbigger(zero, y) == 0)
    {
        bad2 = 1;
        return;
    }
    if (isbigger(x, y) == 2)
    {
        add(result, x, result);
        return;
    }
    fill(temp);
    add(temp, y, temp);
    add(howmuch, one, howmuch);
    for (i = lengthy; i < length - 1; i++)
    {
        temp[i] = '0';
    }
    for (i = length - 2; i > 0; i--)
    {
        tem[i] = '0';
    }
    tem[0] = '1';
    i = length;
    if (length == lengthy)
    {
        add(result, temp, result);
        if (isbigger(result, x) == 2)
        {
            add(howmuch, one, howmuch);
        }
        change(result, howmuch);
        return;
    }
    while (i > lengthy)
    {
        doorno = 0;
        while (isbigger(result, x) == 2)
        {

            add(result, temp, result);
            if (isbigger(result, x) == 2)
            {
                add(howmuch, tem, howmuch);
            }

        }
        substract(result, temp, result);
        temp[strlen(temp) - 1] = '\0';
        tem[strlen(tem) - 1] = '\0';
        i--;
    }
    free(temp);
    free(tem);
    free(howmuch);
    if (doorno)
    {
        while (isbigger(result, x) == 2)
        {
            add(result, y, result);
        }
        if (isbigger(result, x) == 0)
        {
            substract(result, x, result);
            add(result, zero, result);
            return;
        }
        substract(result, y, result);
        substract(x, result, result);
        return;
    }
    substract(x, result, result);
    return;
}
/* Funkcja zwracajaca wynik potegowania liczby o podstawie x do potegi y */
void power(char* x, char* y)
{
    int howmuch = 0, ley = strlen(y), lex = strlen(x), i, howzero = 0, length = 0;
    char* one = "1",*temp;
    temp = x;
    for (i = 0; i < ley; i++)
    {
        howmuch += y[i] - '0';
        howmuch *= 10;
    }
    howmuch /= 10;
    /* Rozpatruje przypadki trywialne */
    if (howmuch == 0)
    {
        add(result, one, result);
        return;
    }
    if (howmuch == 1)
    {
        for (int i = 0; i < lex; i++)
        {
            result[i] = x[i];
        }
        return;
    }
    i = lex - 1;
    while (x[i] == '0')
    {
        howzero++;
        x[i] = '\0';
        i--;
    }
    /* Mnoze x*x dopoki, az x pomnoze y razy */
    multiple(x, x, result);
    if (howzero)
    {
        strrev(result);
    }
    howmuch--;
    for (i = 1; i < howmuch; i++)
    {
        if (i > 1) {
            strrev(result);
        }
        multiple(result, x, result);
    }
    if (howmuch > 1)
    {
        strrev(result);
    }
    length = strlen(result);
    for (i = 0; i < howzero * (howmuch + 1); i++)
    {
        result[length] = '0';
        length++;
    }
    return;
}
/* Funkcja zwracajaca wynik konwersji liczby x z systemu liczbowego wejsciowy na system liczbowy wyjsciowy */
void conversion(int input, int output, char* x, char* out)
{
    int length = strlen(x), which = 0, le, tmp, y, k, first = 0, howmuch = 0, len, len2, i, j, len3;
    int* tab, * carry, * end;
    char* zero = "0",*tempor;
    tempor = (char*)calloc(3, sizeof(char));
    if (isbigger(x, zero)==0)
    {
        add(tempor, zero, tempor);
        change(out, tempor);
        return;
    }
    len = length + 3;
    for (i = 0; i < length; i++)
    {
        if (x[i] >= '0' && x[i] <= '9')
        {
            if (x[i] - '0' >= input)
            {
                bad = 1;
                return;
            }
        }
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            if (x[i] - 'A' >= input)
            {
                bad = 1;
                return;
            }
        }
        if (x[i] > 'Z')
        {
            bad = 1;
            return;
        }
    }
    /* Rozpatruje trywialny przypadek */
    if (input == output) {
        for (i = 0; i < length; i++)
        {
            out[i] = x[i];
        }
        return;
    }
    len3 = length + 5;
    tab = (int*)calloc(len3, sizeof(int));
    /* Zamieniam wszystkie chary na integery */
    for (i = length - 1; i >= 0; i--)
    {
        if (x[i] >= '0' && x[i] <= '9')
        {
            tab[which++] = (int)(x[i] - '0');
        }
        else
        {
            tab[which++] = 10 + (int)(x[i] - 'A');
        }
    }
    /* Zmienna le przechowuje maksymalna dlugosc liczby wyjsciowej */
    if (length * (input / (output)) > length * (output / (input)))
    {
        le = length * (input / (output));
    }
    else
    {
        le = length * (output / (input));
    }
    /* Carry przechowuje nadmiar, jaki przypada na dany indeks,
    End przechowuje wyjsciowa tablice */
    len2 = which * le + 5;
    carry = (int*)calloc(len2, sizeof(int));
    end = (int*)calloc(len2, sizeof(int));
    if (carry != NULL && end != NULL)
    {
        carry[0] = 1;
        for (i = 0; i < which; i++)
        {
            for (j = 0; j < le; j++)
            {
                /* Dla kazdej cyfry z wejscia dodaje kazda cyfre z wejscia */
                end[j] += carry[j] * tab[i];
                tmp = end[j];
                y = 0;
                k = j;
                /* Dodaje wszystkie zapozyczenia */
                do {
                    y = tmp / output;
                    end[k] = tmp - y * output;
                    k++;
                    end[k] += y;
                    tmp = end[k];

                } while (tmp >= output);
            }
            /* Zwiekszam potege */
            for (j = 0; j < le; j++)
            {
                carry[j] = carry[j] * input;
            }
            for (j = 0; j < le; j++)
            {
                tmp = carry[j];
                y = 0;
                k = j;
                /* Dodaje wszystkie zapozyczenia */
                do {
                    y = tmp / output;
                    carry[k] = tmp - y * output;
                    k++;
                    carry[k] += y;
                    tmp = carry[k];
                } while (tmp >= output);
            }
        }
        tmp = 0;
        first = 0;
        free(carry);
        free(tab);
        /* Konwertuje odpowiednio na cyfry w danym systemie wyjsciowym */
        for (i = le; i >= 0; i--)
        {
            if (end[i] != 0)
            {
                first = 1;
            }
            if (first != 0)
            {
                if (end[i] < 10)
                {
                    out[tmp] = (char)(end[i] + '0');
                    tmp++;
                }
                else
                {
                    out[tmp] = (char)(end[i] + 'A' - 10);
                    tmp++;
                }
            }
        }
        out[tmp] = out[tmp + 1];
    }
    free(end);
    return;
}
int howlong(int x)
{
    int y = 9, i;
    for (i = 0; i < x; i++)
    {
        y *= 10;
        y += 9;
    }
    y /= 10;
    return y;
}
int main()
{
    /* Zmienna oper przechowuje operacje, jaka ma zostala wykonana,
    Zmienna syst przechowuje, w jakim systemie zostaly wprowadzone dane,
    Zmienna argumentp przechowuje piewrszy argument,
    Zmienna argumentd przechowuje drugi argument*/
    int syst, act = 0, system = 0, lengthofy = 0, lengthofp = 0, lengthofd = 0, lengthofx = 0, maxlength = 0, option, newlen, smth;
    char argumentp[N], argumentd[N], * pathh, * one = "1", which[N], tex[] = ".txt", * path, * path2;
    char oper[M];
    FILE* fp, * fy;
    memset(which, 0, sizeof(which));
    fp = fopen("../Input/in.txt", "r");
    printf("Wybierz opcje jak maja byc zapisane pliki:\n1. W jednym pliku wszystkie przyklady. \n2. Kazdy przyklad w oddzielnym.\n");
    scanf("%d", &option);
    if (option > 2 || option < 1)
    {
        printf("\nWybrales/as niepoprawna opcje\n");
        return 0;
    }
    if (option == 1)
    {
        fy = fopen("../Input/out.txt", "w");
        memset(oper, 0, sizeof(oper));
        if (fp)
        {
            while (fscanf(fp, "%s", oper) != EOF)
            {
                act++;
                system = 0, lengthofy = 0, lengthofp = 0, lengthofd = 0, lengthofx = 0, maxlength = 0;
                printf("Jest wykonywane %d dzialanie\nProsze czekac\n\n", act);
                fscanf(fp, "%d", &syst);
                memset(argumentp, 0, sizeof(argumentp));
                memset(argumentd, 0, sizeof(argumentd));
                /* Sprawdzam czy operacje, jaka nalezy wykonac jest conversion na inny system liczbowy */
                if (oper[0] >= '0' && oper[0] <= '9')
                {
                    fscanf(fp, "%s", argumentp);
                    system = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        if (oper[i] >= '0' && oper[i] <= '9')
                        {
                            system *= 10;
                            system += oper[i] - '0';
                        }
                    }
                    lengthofp = strlen(argumentp);
                    argumentp[lengthofp] = '\0';
                    if (system / (11) > 10 / system)
                    {
                        lengthofx = lengthofp * (system / (syst + 1)) + 3;
                    }
                    else
                    {
                        lengthofx = lengthofp * (syst / (system + 1)) + 3;
                    }
                    argumentx = (char*)calloc(lengthofx + 3, sizeof(char));

                    conversion(system, syst, argumentp, argumentx);
                    fill(argumentx);
                    if (bad == 1)
                    {
                        fprintf(fy, "%s %d\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, act);
                        bad = 0;
                    }
                    else
                    {
                        fprintf(fy, "%s %d\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentx);
                    }
                }
                else
                {
                    fscanf(fp, "%s", argumentp);
                    fscanf(fp, "%s", argumentd);
                    argumentp[strlen(argumentp)] = '\0';
                    argumentd[strlen(argumentd)] = '\0';
                    lengthofp = strlen(argumentp);
                    lengthofd = strlen(argumentd);

                    if (syst / (11) > 10 / syst)
                    {
                        lengthofx = lengthofp * (syst / 11);
                        lengthofy = lengthofd * (syst / 11);
                    }
                    else
                    {
                        lengthofx = lengthofp * (10 / syst);
                        lengthofy = lengthofd * (10 / syst);
                    }
                    argumentx = (char*)calloc(lengthofx + 3, sizeof(char));
                    argumenty = (char*)calloc(lengthofy + 3, sizeof(char));
                    /* Zamieniam obydwa argumenty z systemu wejsciowego na system 10,
                    zapisuje nowopowstale zmienne odpowiednio, jako argumentx i argumenty */
                    conversion(syst, 10, argumentp, argumentx);
                    conversion(syst, 10, argumentd, argumenty);
                    if (bad == 1)
                    {
                        fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        bad = 0;
                        continue;
                    }
                    /* Sprawdzam, jaka powinna zostac wykonana operacja */
                    if (oper[0] == '+')
                    {
                        if (lengthofx > lengthofy)
                        {
                            result = (char*)calloc(lengthofx + 2, sizeof(char));
                        }
                        else
                        {
                            result = (char*)calloc(lengthofy + 2, sizeof(char));
                        }
                        fill(argumentx);
                        fill(argumenty);
                        add(argumentx, argumenty, result);
                        conversion(10, syst, result, result);
                        fill(result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        else
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        
                        bad = 0;
                    }
                    if (oper[0] == '*')
                    {
                        result = (char*)calloc((lengthofx + lengthofy + 3), sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        multiple(argumentx, argumenty, result);
                        conversion(10, syst, result, result);
                        fill(result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        else 
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        
                        bad = 0;
                    }
                    if (oper[0] == '/')
                    {
                        result = (char*)calloc(lengthofx + 3, sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        divide(argumentx, argumenty);
                        conversion(10, syst, result, result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        if (bad2 == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nDzialanie niewykonalne: dzielenie przez zero\n\n\n", oper, syst, argumentp, argumentd);
                        }
                        if (bad == 0 && bad2 == 0)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        bad2 = 0;
                        bad = 0;
                    }
                    if (oper[0] == '%')
                    {
                        result = (char*)calloc(lengthofx + 3, sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        modulo(argumentx, argumenty);
                        conversion(10, syst, result, result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        if (bad2 == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nDzialanie niewykonalne: dzielenie przez zero\n\n\n", oper, syst, argumentp, argumentd);
                        }
                        if (bad == 0 && bad2 == 0)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        bad2 = 0;
                        bad = 0;
                    }
                    if (oper[0] == '^')
                    {
                        maxlength = howlong(lengthofy);
                        result = (char*)calloc((lengthofx + 4) * (maxlength + 4) + 5, sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        power(argumentx, argumenty);
                        fill(result);
                        conversion(10, syst, result, result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        else
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        bad = 0;
                    }
                    if (oper[0] != '^' && oper[0] != '*' && oper[0] != '+' && oper[0] != '/' && oper[0] != '%')
                    {
                        fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                    }
                    memset(oper, 0, sizeof(oper));
                }
            }
            printf("\nOdpowiedz zostala zapisana w pliku tekstowym ../Input/out.txt\n");
            fclose(fy);
            fclose(fp);
        }
        else
        {
            printf("Blad w otwieraniu pliku");
        }
    }
    if (option == 2)
    {
        path = "../Input/out1.txt";
        path2 = "../Input/";
        pathh = "out";
        while (fscanf(fp, "%s", oper) != EOF)
        {
            add(which, one, which);
            if (act > 0)
            {
                newlen = strlen(pathh) + strlen(which) + strlen(path2);
                path = (char*)calloc(newlen+50, sizeof(char));
                strcpy(path, path2);
                strcat(path, pathh);
                strcat(path, which);
                strcat(path, tex);
            }
            fy = fopen(path, "w");
            if (fy)
            {
                act++;
                system = 0, lengthofy = 0, lengthofp = 0, lengthofd = 0, lengthofx = 0, maxlength = 0;
                printf("Jest wykonywane %d dzialanie\nProsze czekac\n\n", act);
                fscanf(fp, "%d", &syst);
                memset(argumentp, 0, sizeof(argumentp));
                memset(argumentd, 0, sizeof(argumentd));
                /* Sprawdzam czy operacje, jaka nalezy wykonac jest conversion na inny system liczbowy */
                if (oper[0] >= '0' && oper[0] <= '9')
                {
                    fscanf(fp, "%s", argumentp);
                    system = 0;
                    for (int i = 0; i < 2; i++)
                    {
                        if (oper[i] >= '0' && oper[i] <= '9')
                        {
                            system *= 10;
                            system += oper[i] - '0';
                        }
                    }
                    lengthofp = strlen(argumentp);
                    argumentp[lengthofp] = '\0';
                    if (system / (11) > 10 / system)
                    {
                        lengthofx = lengthofp * (system / (syst + 1)) + 3;
                    }
                    else
                    {
                        lengthofx = lengthofp * (syst / (system + 1)) + 3;
                    }
                    argumentx = (char*)calloc(lengthofx + 3, sizeof(char));

                    conversion(system, syst, argumentp, argumentx);
                    fill(argumentx);
                    if (bad == 1)
                    {
                        fprintf(fy, "%s %d\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, act);
                        bad = 0;
                    }
                    else
                    {
                        fprintf(fy, "%s %d\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentx);
                    }
                }
                else
                {
                    fscanf(fp, "%s", argumentp);
                    fscanf(fp, "%s", argumentd);
                    argumentp[strlen(argumentp)] = '\0';
                    argumentd[strlen(argumentd)] = '\0';
                    lengthofp = strlen(argumentp);
                    lengthofd = strlen(argumentd);

                    if (syst / (11) > 10 / syst)
                    {
                        lengthofx = lengthofp * (syst / 11);
                        lengthofy = lengthofd * (syst / 11);
                    }
                    else
                    {
                        lengthofx = lengthofp * (10 / syst);
                        lengthofy = lengthofd * (10 / syst);
                    }
                    argumentx = (char*)calloc(lengthofx + 3, sizeof(char));
                    argumenty = (char*)calloc(lengthofy + 3, sizeof(char));
                    /* Zamieniam obydwa argumenty z systemu wejsciowego na system 10,
                    zapisuje nowopowstale zmienne odpowiednio, jako argumentx i argumenty */
                    conversion(syst, 10, argumentp, argumentx);
                    conversion(syst, 10, argumentd, argumenty);
                    if (bad == 1)
                    {
                        fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        bad = 0;
                        continue;
                    }
                    /* Sprawdzam, jaka powinna zostac wykonana operacja */
                    if (oper[0] == '+')
                    {
                        if (lengthofx > lengthofy)
                        {
                            result = (char*)calloc(lengthofx + 2, sizeof(char));
                        }
                        else
                        {
                            result = (char*)calloc(lengthofy + 2, sizeof(char));
                        }
                        fill(argumentx);
                        fill(argumenty);
                        add(argumentx, argumenty, result);
                        conversion(10, syst, result, result);
                        fill(result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        else
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }

                        bad = 0;
                    }
                    if (oper[0] == '*')
                    {
                        result = (char*)calloc((lengthofx + lengthofy + 3), sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        multiple(argumentx, argumenty, result);
                        conversion(10, syst, result, result);
                        fill(result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        else
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }

                        bad = 0;
                    }
                    if (oper[0] == '/')
                    {
                        result = (char*)calloc(lengthofx + 3, sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        divide(argumentx, argumenty);
                        conversion(10, syst, result, result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        if (bad2 == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nDzialanie niewykonalne: dzielenie przez zero\n\n\n", oper, syst, argumentp, argumentd);
                        }
                        if (bad == 0 && bad2 == 0)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        bad2 = 0;
                        bad = 0;
                    }
                    if (oper[0] == '%')
                    {
                        result = (char*)calloc(lengthofx + 3, sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        modulo(argumentx, argumenty);
                        conversion(10, syst, result, result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        if (bad2 == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nDzialanie niewykonalne: dzielenie przez zero\n\n\n", oper, syst, argumentp, argumentd);
                        }
                        if (bad == 0 && bad2 == 0)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        bad2 = 0;
                        bad = 0;
                    }
                    if (oper[0] == '^')
                    {
                        maxlength = howlong(lengthofy);
                        result = (char*)calloc((lengthofx + 4) * (maxlength + 4) + 5, sizeof(char));
                        fill(argumentx);
                        fill(argumenty);
                        power(argumentx, argumenty);
                        fill(result);
                        conversion(10, syst, result, result);
                        if (bad == 1)
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                        }
                        else
                        {
                            fprintf(fy, "%s %d\n\n%s\n\n%s\n\n%s\n\n\n", oper, syst, argumentp, argumentd, result);
                            free(result);
                        }
                        bad = 0;
                    }
                    if (oper[0] != '^' && oper[0] != '*' && oper[0] != '+' && oper[0] != '/' && oper[0] != '%')
                    {
                        fprintf(fy, "%s %d\n\n%s\n\n%s\n\nWprowadzono bledne dane dla przykladu: %d prosze poprawic\n\n\n", oper, syst, argumentp, argumentd, act);
                    }
                }
                fclose(fy);
                memset(oper, 0, sizeof(oper));
            }

            
        }
        printf("\nOdpowiedz zostala zapisana w plikach tekstowych ../Input/out<numer>.txt\n");
        fclose(fp);
    }
    return 0;
}
