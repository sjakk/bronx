#include "application.h"
#include <gtest/gtest.h>

namespace bronx {
	
	void Application::run() {
		while (true);
	}

	TEST(HelloTest, BasicAssertions) {
		// Expect two strings not to be equal.
		EXPECT_STRNE("hello", "world");
		// Expect equality.
		EXPECT_EQ(7 * 6, 42);
	}

	
}