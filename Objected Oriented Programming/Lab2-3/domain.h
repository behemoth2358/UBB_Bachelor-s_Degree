#ifndef DOMAIN_H_INCLUDED
#define DOMAIN_H_INCLUDED

#define dataFILE "data.txt"
#define MAXSIZE_COUNTRY_NAME 50
#define MAXSIZE_CONTINENT_NAME 50

typedef struct country_s{
    long population;
    char name[50];
    char continent[50];
}country;

#endif // DOMAIN_H_INCLUDED
