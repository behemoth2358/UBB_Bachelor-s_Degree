#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int cnt = 0;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

typedef struct something_s {
    char* file;
    char* word;
}something;

void* foo(void* param) {
    something* obj = (something*)param;

    char cmd[ 10000 ];
    strcpy(cmd, "cat ");
    strcat(cmd, obj->file);
    strcat(cmd, " | grep -o \"");
    strcat(cmd, obj->word);
    strcat(cmd, "\" | wc -l > temp_file.out");

    pthread_mutex_lock(&mut);

    system(cmd);

    FILE *f = fopen("temp_file.out", "r");

    int nr;
    fscanf(f, "%d\n", &nr);
    cnt += nr;

    fclose(f);

    system("rm temp_file.out");

    pthread_mutex_unlock(&mut);

    return NULL;
}

int main(int argc, char** args) {

    int nr_words = argc - 2;

    something* objects = (something*)malloc(nr_words * sizeof(something));

    int file_len = strlen(args[ 1 ]);
    for(int i = 2;i < argc;i++) {
        objects[ i-2 ].file = (char*)malloc((file_len + 1) * sizeof(char));
        objects[ i-2 ].word = (char*)malloc((strlen(args[ i ]) + 1) * sizeof(char));

        strcpy(objects[ i-2 ].file, args[ 1 ]);
        strcpy(objects[ i-2 ].word, args[ i ]);
    }

    pthread_t* thread = (pthread_t*)malloc(nr_words * sizeof(pthread_t));

    for(int i = 0;i < nr_words;i++) {
        pthread_create(&thread[ i ], NULL, foo, (void*)&objects[ i ]);
    }

    for(int i = 0;i < nr_words;i++) {
        pthread_join(thread[ i ], NULL);
    }

    printf("Number of aparitions = %d\n", cnt);

    for(int i = 0; i < nr_words; i++) {
        free(objects[ i ].file);
        free(objects[ i ].word);
    }
    free(objects);
    free(thread);
    
    return 0;
}
