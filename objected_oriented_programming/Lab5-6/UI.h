#ifndef UI_H
#define UI_H

#include "controller.h"
#include "vector.h"
#include <iostream>

class UI{
private:
    Controller controller;
public:
    UI(const Controller&);
    void Run();
    void RunAdminMode();
    void RunClientMode();
};

#endif
