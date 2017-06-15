/*
For each command line argument launch two subprocesses that will race to establish:
- the length of the longest line, if the argument is a file (using popen and wc).
- the size in bytes if the argument is a directory (using popen and du). 
Each process, before send the result to the parent, will sleep between one and five seconds (using sleep call).
The communication between processes we will use a single pipe channel.
Each process will send to the parent a structure that contains his pid, the argument and the established result.
The parent will print only the n/2 received results (n being the number of arguments), the rest will be ignored.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct something_s {
    int pid, res;
    char arg[ 4096 ];
}something;

void print_something(something var) { // prints a something structure
    printf("\npid = %d\nargument = %s\nresult = %d\n", var.pid, var.arg, var.res);
}

int get_directory_size(char *dir) { // returns the directory size or -1 if dir it's not a directory
    struct stat buf;

    if (stat(dir, &buf) != 0) {
        return -1;
    }

    return (S_ISDIR(buf.st_mode) ? buf.st_size : -1);
}

int get_size_of_longest_line_of_file(char *file) { // returns the longest line of a given file
	char command[ 4096 ];
	strcat(command, "cat ");
	strcat(command, file);
	strcat(command, " | wc -L");
    FILE *in = popen(command, "r");

    int max_line_size = -1;

    fscanf(in, "%d", &max_line_size);

    fclose(in);

    return max_line_size;
}

int main(int argv, char **args) {

    int fd[ 2 ], pid;

    int cnt_to_be_printed = (argv + 1) / 2;

    pipe(fd);

    for(int i = 1;i < argv;i++) {

        if(get_directory_size(args[ i ]) != -1) { // if it's a directory

            if((pid = fork()) == 0) {

                something var;
                var.pid = getpid();
                strcpy(var.arg, args[ i ]);

                var.res = get_directory_size(args[ i ]);

                write(fd[ 1 ], &var, sizeof(something));

                close(fd[ 0 ]);
                close(fd[ 1 ]);

                //sleep(3);
                exit(0);
            } else {
                something var;
                read(fd[ 0 ], &var, sizeof(something));

                if(cnt_to_be_printed > 0) {
                    print_something(var);
                    cnt_to_be_printed--;
                }
                wait(0);
            }

        } else { //if it's a file


            if((pid = fork()) == 0) {


                something var;
                var.pid = getpid();
                strcpy(var.arg, args[ i ]);
                var.res = get_size_of_longest_line_of_file(args[ i ]);

                write(fd[ 1 ], &var, sizeof(something));

                close(fd[ 0 ]);
                close(fd[ 1 ]);

                //sleep(3);
                exit(0);
            } else {
                something var;

                read(fd[ 0 ], &var, sizeof(something));

                if(cnt_to_be_printed > 0) {
                    print_something(var);
                    cnt_to_be_printed--;
                }
                wait(0);
            }

        }
    }

    close(fd[ 0 ]);
    close(fd[ 1 ]);

    return 0;
}
