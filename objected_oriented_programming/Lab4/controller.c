#include "controller.h"

void free_memory(controller *cont)//frees memory
{
    free_repo(cont->repo);
    free(cont->repo);
    free(cont->stack);
}

void controller_load_data(controller *cont)//load data into controller cont
{
    cont->repo=load_data();
    cont->stack=(operation*)malloc(3*sizeof(operation));
    cont->m=cont->n=0;
    cont->sz=3;
}

void controller_save_data(controller cont)//save the data from controller cont in the file
{
    save_data(cont.repo);
}

void stack_realloc(controller *cont)
{
    if(cont->sz <= cont->m)
    {
        cont->sz=2*cont->sz+1;
        cont->stack=(operation*)realloc(cont->stack,cont->sz*(sizeof(operation)));
    }
}

int isContinentValid(char *s)//returns 0 if the given string is a valid continent
{
    const char ss[4][10]={ "Europe", "Asia", "America", "Africa" };
    for(int i=0;i<4;i++)
        if(strcmp(s,ss[i])==0)
            return 0;
    return 1;
}

int populationCompare(country x, country y)
{
    return x.population > y.population;
}

int notPopulationCompare(country x, country y)
{
    return x.population < y.population;
}

int nameCompare(country x, country y)
{
    return strcmp(x.name, y.name)>0;
}

char *search1(controller cont, char *continent)
{
    sort(cont.repo, nameCompare);
    char *out=(char*)malloc(1000*sizeof(char));
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(strcmp(get(cont.repo,i).continent,continent)==0)
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}

char *search2(controller cont, char *continent, int val)//returns all the countries from a given continent whose population is larger than val
{
    sort(cont.repo,populationCompare);
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(get(cont.repo,i).population>val && (strcmp(get(cont.repo,i).continent,continent)==0 || strlen(continent)==0))
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}



char *continentSearch(controller cont, char *continent)//returns all the countries from a given continent whose population is larger than val
{
    sort(cont.repo,nameCompare);
    if(strlen(continent)==0)
    {
        return to_string(cont.repo);
    }
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(strcmp(get(cont.repo,i).continent,continent)==0)
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}


char *continentSearch1(controller cont, char *continent)//returns all the countries from a given continent whose population is larger than val
{
    sort(cont.repo,notPopulationCompare);
    if(strlen(continent)==0)
    {
        return to_string(cont.repo);
    }
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    if(isContinentValid(continent)==1)
    {
        strcpy(out,"\nInvalid continent\n");
        return out;
    }
    for(int i=0;i<size(cont.repo);i++)
    if(strcmp(get(cont.repo,i).continent,continent)==0)
    {
        country x=get(cont.repo,i);
        strcat(out, x.name);
        strcat(out," ");
        strcat(out, x.continent);
        strcat(out," ");
        char aux[20];
        sprintf(aux,"%ld\n",x.population);
        strcat(out,aux);
    }
    return out;
}

char *substringSearch(controller cont, char *s)//returns all countries whose name contain a given string
{
    if(strlen(s)==0)
        return to_string(cont.repo);
    char *out=(char*)malloc(1000*sizeof(char));//TO BE MODIFIED
    strcpy(out,"");
    for(int i=0;i<size(cont.repo);i++)
        if(strstr(get(cont.repo,i).name,s)!=NULL)
        {
            country x=get(cont.repo,i);
            strcat(out, x.name);
            strcat(out," ");
            strcat(out, x.continent);
            strcat(out," ");
            char aux[20];
            sprintf(aux,"%ld\n",x.population);
            strcat(out,aux);
        }
    return out;
}

int Update(controller *cont, char *name, int val)//updates the population of a given country
{
    int pos=find_by_name(cont->repo,name);
    if(pos==-1)
        return 1;

    stack_realloc(cont);
    cont->stack[ cont->m ].var1=get(cont->repo,pos);
    cont->stack[ cont->m ].op=3;
    cont->n++;
    cont->m=cont->n;


    update(cont->repo,pos,val);
    save_data(cont->repo);
    return 0;
}

int Migration(controller *cont, char *name1, char *name2, int val)//updates the population of 2 given countries
{
    int pos1=find_by_name(cont->repo,name1),pos2=find_by_name(cont->repo,name2);
    if(pos1==-1 || pos2==-1)
        return 1;

    stack_realloc(cont);
    cont->stack[ cont->m ].var1=get(cont->repo,pos1);
    cont->stack[ cont->m ].var2=get(cont->repo,pos2);
    cont->stack[ cont->m ].op=4;
    cont->n++;
    cont->m=cont->n;


    update(cont->repo,pos1,-val);
    update(cont->repo,pos2,val);
    save_data(cont->repo);
    return 0;
}

int Add(controller *cont, char *name, char *continent, long population)//adds a country
{
    if(find(cont->repo,name,continent,population)!=-1 || isContinentValid(continent)==1)
        return 1;

    stack_realloc(cont);
    country x;
    strcpy(x.name,name);
    strcpy(x.continent,continent);
    x.population=population;
    cont->stack[ cont->m ].var1=x;
    cont->stack[ cont->m ].op=1;
    cont->n++;
    cont->m=cont->n;

    add(cont->repo,name,continent,population);
    return 0;
}

char *Show_all(controller cont)//returns all countries
{
    return to_string(cont.repo);
}

int Del(controller *cont, char *name)//erases a country
{
    int pos=find_by_name(cont->repo,name);
    if(pos==-1)
        return 1;

    stack_realloc(cont);
    cont->stack[ cont->m ].var1=get(cont->repo,pos);
    cont->stack[ cont->m ].op=2;
    cont->n++;
    cont->m=cont->n;

    del(cont->repo,pos);
    return 0;
}

int undo(controller *cont)
{
    if(cont->n-1<0)
    {
        return 1;
    }
    operation x = cont->stack[ cont->n - 1 ];
    if(x.op==1)
    {

        del(cont->repo,find_by_name(cont->repo,x.var1.name));
        cont->stack[ cont->n - 1 ].op=2;
        cont->n--;
    }
    if(x.op==2)
    {
        add(cont->repo,x.var1.name,x.var1.continent,x.var1.population);
        cont->stack[ cont->n - 1 ].op=1;
        cont->n--;
    }
    if(x.op==3)
    {

        long val=x.var1.population - get(cont->repo, find_by_name(cont->repo,x.var1.name)).population;
        update(cont->repo,find_by_name(cont->repo,x.var1.name),val);
        cont->stack[ cont->n - 1 ].var1.population-=val;
        cont->n--;
    }
    if(x.op==4)
    {
        long val=x.var1.population - get(cont->repo, find_by_name(cont->repo,x.var1.name)).population;
        update(cont->repo,find_by_name(cont->repo,x.var1.name),val);
        update(cont->repo,find_by_name(cont->repo,x.var2.name),-val);
        cont->stack[ cont->n - 1 ].var1.population-=val;
        cont->stack[ cont->n - 1 ].var2.population+=val;
        cont->n--;
    }
    return 0;
}


int redo(controller *cont)
{
    if(cont->n >= cont->m)
    {
        return 1;
    }

    operation x = cont->stack[ cont->n ];
    if(x.op==1)
    {

        del(cont->repo,find_by_name(cont->repo,x.var1.name));
        cont->stack[ cont->n ].op=2;
        cont->n++;
    }
    if(x.op==2)
    {
        add(cont->repo,x.var1.name,x.var1.continent,x.var1.population);
        cont->stack[ cont->n ].op=1;
        cont->n++;
    }
    if(x.op==3)
    {

        long val=x.var1.population - get(cont->repo, find_by_name(cont->repo,x.var1.name)).population;
        update(cont->repo,find_by_name(cont->repo,x.var1.name),val);
        cont->stack[ cont->n ].var1.population-=val;
        cont->n++;
    }
    if(x.op==4)
    {
        long val=x.var1.population - get(cont->repo, find_by_name(cont->repo,x.var1.name)).population;
        update(cont->repo,find_by_name(cont->repo,x.var1.name),val);
        update(cont->repo,find_by_name(cont->repo,x.var2.name),-val);
        cont->stack[ cont->n ].var1.population-=val;
        cont->stack[ cont->n ].var2.population+=val;
        cont->n++;
    }

    return 0;
}
