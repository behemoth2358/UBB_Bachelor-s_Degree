#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "repository.h"

typedef struct operation_s{
    int op;
    /*
       add - 1
       del - 2
       update - 3
       migration - 4
    */
    country var1,var2;
}operation;

typedef struct controller_s{
    repository *repo;
    operation *stack;
    int n,m,sz;
}controller;

void free_memory(controller*);//frees memory

void controller_load_data(controller*);//load data into controller cont

void controller_save_data(controller);//save the data from controller cont in the file

int isContinentValid(char*);//returns 0 if the given string is a valid continent

int populationCompare(country, country);

int notPopulationCompare(country, country);

int nameCompare(country, country);

char *search1(controller, char*);

char *search2(controller, char*, int);//returns all the countries from a given continent whose population is larger than val

char *continentSearch(controller, char*);//returns all the countries from a given continent whose population is larger than val

char *continentSearch1(controller, char*);

char *substringSearch(controller, char*);//returns all countries whose name contain a given string

int Update(controller*, char*, int);//updates the population of a given country

int Migration(controller*, char*, char*, int);//updates the population of 2 given countries

int Add(controller*, char*, char*, long);//adds a country

char *Show_all(controller);//returns all countries

int Del(controller*, char*);//erases a country

int undo(controller*);

int redo(controller*);
#endif // DOMAIN_H_INCLUDED
