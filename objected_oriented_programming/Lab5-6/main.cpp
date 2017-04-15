#include <iostream>
#include <string>
#include "UI.h"
#include "controller.h"
#include "repository.h"

int main()
{
    Repository repo;
    Controller cont(repo);
    UI ui(cont);

    ui.Run();

    return 0;
}
