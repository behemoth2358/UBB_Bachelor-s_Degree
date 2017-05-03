#ifndef TESTS_H
#define TESTS_H

#include <cassert>

#include "../repository/repository.h"
#include "../controller/controller.h"
#include "../domain/movie.h"
#include "../utilities/constants.h"

class Tests {

public:

	static void test_domain();

	static void test_repository();

	static void test_controller();

	static void run_tests();

};

#endif