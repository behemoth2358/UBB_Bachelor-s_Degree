#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <stdio.h>
#include "controller.h"

typedef struct ui_s{
    controller cont;
}ui;

void stack_realloc(ui*, int*, int*);

void run_app(ui);

#endif // UI_H_INCLUDED
