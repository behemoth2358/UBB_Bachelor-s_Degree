#ifndef UI_H
#define UI_H

#include "../controller/controller.h"
#include "../domain/movie.h"
#include "../utilities/config.h"
#include <exception>


#include <iostream>

class UI {

private:

    Controller controller;

public:

    UI(const Controller&);
    void run();
    void run_admin_mode();
    void run_client_mode();
};

#endif
