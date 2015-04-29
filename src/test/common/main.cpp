/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#include <cstdlib>

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

using namespace CppUnit;

int main(int argc, char** argv) {
	(void) argc;
	(void) argv;

	TestResult res;

	TestResultCollector resColl;
	res.addListener(&resColl);

	BriefTestProgressListener progList;
	res.addListener(&progList);

	TestRunner runner;
	runner.addTest(TestFactoryRegistry::getRegistry().makeTest());
	runner.run(res);

	CompilerOutputter o(&resColl, std::cerr);
	o.write();

	return resColl.wasSuccessful() ? EXIT_SUCCESS : EXIT_FAILURE;
}
