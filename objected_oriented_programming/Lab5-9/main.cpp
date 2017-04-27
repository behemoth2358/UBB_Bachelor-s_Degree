#include <iostream>
#include <string>

#include "ui/ui.h"
#include "controller/controller.h"
#include "repository/repository.h"

int main()
{
    Repository repo;
    Controller cont(repo);
    UI ui(cont);

    ui.run();

    return 0;
}
