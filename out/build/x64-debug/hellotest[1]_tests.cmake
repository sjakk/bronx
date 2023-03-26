add_test([=[HelloTest.BasicAssertions]=]  C:/Users/illya/Documents/bronx/out/build/x64-debug/hellotest.exe [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY C:/Users/illya/Documents/bronx/out/build/x64-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hellotest_TESTS HelloTest.BasicAssertions)
