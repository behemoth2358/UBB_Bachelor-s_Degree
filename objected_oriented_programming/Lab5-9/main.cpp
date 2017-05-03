#include <iostream>
#include <string>

#include "ui/ui.h"
#include "controller/controller.h"
#include "repository/repository.h"
#include "repository/file_repository.h"
#include "repository/html_repository.h"
#include "utilities/config.h"
#include "tests/tests.h"

int main() {

	Tests::run_tests();

    HTMLRepository repo( std::string(DATA_FILE) , std::string(USER_FILE), std::string(HTML_FILE) );

    Controller cont(&repo);

    UI ui(cont);

    ui.run();

    return 0;
}
