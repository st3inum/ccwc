#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "helper.hpp"

TEST_CASE("Counting lines in a string") {
	SECTION("Empty string") {
		std::string s = "";
		REQUIRE(countLines(s) == 0);
	}

	SECTION("Single line") {
		std::string s = "Hello, world!";
		REQUIRE(countLines(s) == 0);
	}

	SECTION("Multiple lines") {
		std::string s = "Line 1\nLine 2\nLine 3";
		REQUIRE(countLines(s) == 2);
	}

	SECTION("No newline characters") {
		std::string s = "This is a test";
		REQUIRE(countLines(s) == 0);
	}

	SECTION("Only newline characters") {
		std::string s = "\n\n\n";
		REQUIRE(countLines(s) == 3);
	}

	SECTION("Mixed newline characters") {
		std::string s = "Line 1\nLine 2\r\nLine 3";
		REQUIRE(countLines(s) == 2);
	}
	SECTION("Newline characters at the end") {
		std::string s = "Line 1\nLine 2\r\nLine 3\n";
		REQUIRE(countLines(s) == 3);
	}
}
