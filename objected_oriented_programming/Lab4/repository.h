#ifndef REPOSITORY_H_INCLUDED
#define REPOSITORY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "domain.h"

typedef struct repository_s{
    country *arr;
    int nr,total;
}repository;

void free_repo(repository*);//frees the memory

int size(repository*);//return the number of entities from a given repository

void sort(repository*,int(*compare)(country, country));//sorts the repository

country get(repository*,int);//returns the country from a given index

void save_data(repository*);//save the data from a given repository

void repo_realloc(repository*);

void add(repository*, char*, char*, long);//adds a new element to repository

void del(repository*, int);//erases the element found at position pos

int find_by_name(repository*, char*);//returns an index if element with given name is found, -1 otherwise

int find(repository*, char*, char*, long);//returns an index if element is found, -1 otherwise

repository* load_data();//load data from file, returns a repository containing the data

void update(repository*, int, int);//update the population of the country at index pos with value val

char *to_string(repository*);//returns a string with all the countries in the repository



#endif // REPOSITORY_H_INCLUDED
