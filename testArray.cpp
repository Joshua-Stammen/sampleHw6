#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "SuperArray.h"

/*{  ASSERTION MACROS:
 *  REQUIRE( expression ) and  
 *  CHECK( expression )  Evaluates the 
 *      expression and records the result. If an exception is thrown 
 *      it is caught, reported, and counted as a failure. These are 
 *      the macros you will use most of the time
 *  REQUIRE_FALSE( expression ) and  
 *  CHECK_FALSE( expression ) Evaluates the expression and records the logical NOT of the result. If 
 *      an exception is thrown it is caught, reported, and counted 
 *      as a failure. (these forms exist as a workaround for the 
 *      fact that ! prefixed expressions cannot be decomposed).
 * 
 *  EXCEPTIONS MACROS:
*   REQUIRE_NOTHROW( expression ) and  
*   CHECK_NOTHROW( expression )
*      Expects that no exception is thrown during evaluation of the expression.
*
*   REQUIRE_THROWS( expression ) and 
*   CHECK_THROWS( expression )
*      Expects that an exception (of any type) is be thrown during evaluation of the expression.
*
*   REQUIRE_THROWS_AS( expression, exception type ) and 
*   CHECK_THROWS_AS( expression, exception type )
*      Expects that an exception of the specified type is thrown during evaluation of the expression. Note that the exception type is extended with const& and you should not include it yourself.
*
*   REQUIRE_THROWS_WITH( expression, string or string matcher ) and
*   CHECK_THROWS_WITH( expression, string or string matcher )
*      Expects that an exception is thrown that, when converted to a string, matches the string or string matcher provided (see next section for Matchers).
*
*      e.g.
*
*      REQUIRE_THROWS_WITH( openThePodBayDoors(), Contains( "afraid" ) && Contains( "can't do that" ) );
*      REQUIRE_THROWS_WITH( dismantleHal(), "My mind is going" );
*      REQUIRE_THROWS_MATCHES( expression, exception type, matcher for given exception type ) and
*      CHECK_THROWS_MATCHES( expression, exception type, matcher for given exception type )
*      Expects that exception of exception type is thrown and it matches provided matcher (see next section for Matchers).
 *
 *  LOGGING MACROS:
 *  INFO( message expression )  The message is logged to a buffer, 
 *      but only reported with the next assertion that is logged. 
 *      This allows you to log contextual information in case of failures 
 *      which is not shown during a successful test run (for the console 
 *      reporter, without -s). Messages are removed from the buffer 
 *      at the end of their scope, so may be used, for example, in loops.
 *
 *  WARN( message expression ) The message is always reported but 
 *      does not fail the test.
 *
 *  FAIL( message expression ) The message is reported and the test case fails.
 *
 *  FAIL_CHECK( message expression ) AS FAIL, but does not abort the test
 *
 *  CAPTURE( expression )  Sometimes you just want to log the name and 
 *      value of a variable. While you can easily do this with the INFO macro, 
 *      above, as a convenience the CAPTURE macro handles the stringising of 
 *      the variable name for you (actually it works with any expression, 
 *      not just variables).
 * } */
TEST_CASE("Testing SuperArray class Regular indexes")
{
    INFO("Testing SuperArray class Regular indexes");
	int low = 0;
	int high = 5;
	SuperArray sa(low,high);
	for (int i = low; i < high - low; i++)
	{
		sa[i] = i + 20;
	}
	SECTION("Test #1) Test Constructor")
    {
        INFO("Test #1) Test Constructor FAILED");
        REQUIRE(arrayToString(sa) == "20 21 22 23 24");
    }

	SECTION("Test #2) Test low index")
	{
	    INFO("Test #2) Test low index FAILED");
		REQUIRE(sa.getLowIndex() == low);
	}
	SECTION("Test #3) Test high index")
	{
	    INFO("Test #3) Test high index FAILED");
		REQUIRE(sa.getHighIndex() == high - 1);
	}

	SECTION("Test #4) Test length")
	{
	    INFO("Test #4) Test length FAILED");
		REQUIRE(sa.length() == 5);
	}
	/*
	SECTION("Test #5) Test valid index member")
	{
	    INFO("Test #5) Test valid index member FAILED");
		REQUIRE(sa[0] == 20);
	}
    // This test requires to test an exception 
	SECTION("Test #6) Test invalid index members (too low)")
	{
	    INFO("Test #6) Test valid index member (too low) FAILED");
		REQUIRE_THROWS_WITH(sa[-2], "Invalid index request, too low");
	}
	SECTION("Test #7) Test invalid index members (too high)")
	{
	    INFO("Test #7) Test valid index member (too high) FAILED");
		REQUIRE_THROWS_WITH(sa[9], "Invalid index request, too high");
	}*/
}

TEST_CASE("Testing SuperArray class with super range")
{
    INFO("Testing SuperArray class with super range");
    int low = 5;
    int high = 15;

    SuperArray sa(low, 10);
    for (int i = low; i < high; i++)
    {
        sa[i] = i + 100;
    }
    SECTION("Test #8) Test Constructor")
    {
        INFO("Test #8) Test Constructor FAILED");
        REQUIRE(arrayToString(sa) == "105 106 107 108 109 110 111 112 113 114");
    }

    SECTION("Test #9) Test low index")
    {
        INFO("Test #9) Test low index FAILED");
        REQUIRE(sa.getLowIndex() == low);
    }

    SECTION("Test #10) Test high index")
    {
        INFO("Test #10) Test high index FAILED");
        REQUIRE(sa.getHighIndex() == high - 1);
    }
    SECTION("Test #11) Test length")
    {
        INFO("Test #11) Test length FAILED");
        REQUIRE(sa.length() == 10);
    }
	/*
    SECTION("Test #12) Test valid index member")
    {
        INFO("Test #12) Test valid index member FAILED");
        REQUIRE(sa[8] == 108);
    }
    // This test requires to test an exception
    SECTION("Test #13) Test invalid index members (too low)")
    {
        INFO("Test #13 Test valid index member (too low) FAILED");
        REQUIRE_THROWS_WITH(sa[2], "Invalid index request, too low");
    }
    SECTION("Test #14) Test invalid index members (too high)")
    {
        INFO("Test #14 Test valid index member (too high) FAILED");
        REQUIRE_THROWS_WITH(sa[19], "Invalid index request, too high");
    }
	*/
}
/*
TEST_CASE("Testing SuperArray class Resize Feature")
 {
    INFO("Testing SuperArray class with super range");
    int low = 5;
    int high = 15;
    SuperArray sa(low, high);
    for (int i = low; i < high; i++)
    {
        sa[i] = i + 100;
     }
    // Test Resize now
    low = 3;
    high = 15;
    sa.resize(low, high);
	SECTION("Test #15) Test low index")
	{
	    INFO("Test #15) Test low index FAILED");
		REQUIRE(sa.getLowIndex() == low);
	}
	SECTION("Test #16) Test high index")
	{
	    INFO("Test #16) Test high index FAILED");
		REQUIRE(sa.getHighIndex() == high - 1);
	}
	SECTION("Test #17) Test length")
	{
	    INFO("Test #17) Test length FAILED");
		REQUIRE(sa.length() == 15);
	}
	SECTION("Test #18) Test valid index member")
	{
	    INFO("Test #18) Test valid index member FAILED");
        REQUIRE(sa[5] == 105);
        REQUIRE(sa[14] == 114);
	}
    // Update values and test them
    sa[3] = 1;
    sa[14] = 2;
	SECTION("Test #19) Test valid new values")
	{
	    INFO("Test #19) Test valid new FAILED");
        REQUIRE(sa[3] == 1);
        REQUIRE(sa[14] == 2);
	}
    // This test requires to test an exception
	SECTION("Test #20) Test invalid index members (too low)")
	{
	    INFO("Test #20 Test valid index member (too low) FAILED");
		REQUIRE_THROWS_WITH(sa[2], "Invalid index request, too low");
	}
	SECTION("Test #21) Test invalid index members (too high)")
 	{
	    INFO("Test #21 Test valid index member (too high) FAILED");
		REQUIRE_THROWS_WITH(sa[19], "Invalid index request, too high");
	}
}
TEST_CASE("Testing SuperArray class Resize Feature Negative Index")
{
    INFO("Testing SuperArray class Resize Feature Negative Index");
    int low = 5;
    int high = 15;
    SuperArray sa(low, high);
    for (int i = low; i < high; i++)
    {
        sa[i] = i + 100;
    }
    // Test Resize now
    low = -4;
    high = 23;
    sa.resize(low, high);
    SECTION("Test #22) Test low index")
    {
        INFO("Test #22) Test low index FAILED");
        REQUIRE(sa.getLowIndex() == low);
    }
    SECTION("Test #23) Test high index")
    { 
        INFO("Test #23) Test high index FAILED");
        REQUIRE(sa.getHighIndex() == high - 1);
    }
    SECTION("Test #24) Test length")
    { 
        INFO("Test #24) Test length FAILED");
        REQUIRE(sa.length() == 23);
    }
    SECTION("Test #25) Test valid index member")
    {
        INFO("Test #25) Test valid index member FAILED");
        REQUIRE(sa[5] == 105);
        REQUIRE(sa[14] == 114);
    }
    // Update values and test them
    sa[3] = 1;
    sa[14] = 2;
    sa[-4] = 1234;
    SECTION("Test #26) Test valid new values")
    { 
        INFO("Test #26) Test valid new FAILED");
        REQUIRE(sa[3] == 1);
        REQUIRE(sa[14] == 2);
        REQUIRE(sa[-4] == 1234);
    }
    // This test requires to test an exception
    SECTION("Test #27) Test invalid index members (too low)")
    {
        INFO("Test #27 Test valid index member (too low) FAILED");
        REQUIRE_THROWS_WITH(sa[-6], "Invalid index request, too low");
    }
    SECTION("Test #28) Test invalid index members (too high)")
    {
        INFO("Test #28 Test valid index member (too high) FAILED");
        REQUIRE_THROWS_WITH(sa[25], "Invalid index request, too high");
    }
}
TEST_CASE("Testing SuperArray Offseting array")
{
    INFO("Testing SuperArray Offseting array");
	int low = -20;
	int high = 4;
	SuperArray sa(low, high);
	for (int i = low; i < -16; i++)
	{
		sa[i] = i - 10;
	}
	SECTION("Test #29) Test Constructor")
    {
        INFO("Test #29) Test Constructor FAILED");
        REQUIRE(arrayToString(sa) == "-30 -29 -28 -27");
    }
	SECTION("Test #30) Test low index")
	{
	    INFO("Test #30) Test low index FAILED");
		REQUIRE(sa.getLowIndex() == low);
	}
	SECTION("Test #31) Test high index")
	{
	    INFO("Test #31) Test high index FAILED");
		REQUIRE(sa.getHighIndex() == -17);
	}
	SECTION("Test #32) Test length")
	{
	    INFO("Test #32) Test length FAILED");
		REQUIRE(sa.length() == 4);
	}
    // This test requires to test an exception 
	SECTION("Test #33) Test invalid index members (too low)")
	{
	    INFO("Test #33) Test valid index member (too low) FAILED");
		REQUIRE_THROWS_WITH(sa[-29], "Invalid index request, too low");
	}
	SECTION("Test #34) Test invalid index members (too high)")
 	{
	    INFO("Test #34) Test valid index member (too high) FAILED");
		REQUIRE_THROWS_WITH(sa[0], "Invalid index request, too high");
	}
}
TEST_CASE("Testing SuperArray 1 element")
{
    INFO("Testing SuperArray 1 element");
    int low = 3;
    int high = 1;
    SuperArray sa(low, high);
    sa[3] = 1111;;

    SECTION("Test #35) Test Constructor")
    { 
        INFO("Test #35) Test Constructor FAILED");
        REQUIRE(arrayToString(sa) == "1111");
    }
    SECTION("Test #36) Test low index")
    { 
        INFO("Test #36) Test low index FAILED");
        REQUIRE(sa.getLowIndex() == low);
    }
    SECTION("Test #36) Test high index")
    { 
        INFO("Test #36) Test high index FAILED");
        REQUIRE(sa.getHighIndex() == low);
    }
    SECTION("Test #37) Test length")
    { 
        INFO("Test #37) Test length FAILED");
        REQUIRE(sa.length() == 1);
    }
    // This test requires to test an exception 
    SECTION("Test #38) Test invalid index members (too low)")
    {
        INFO("Test #38) Test valid index member (too low) FAILED");
        REQUIRE_THROWS_WITH(sa[2], "Invalid index request, too low");
    }
    SECTION("Test #39) Test invalid index members (too high)")
    {
        INFO("Test #39) Test valid index member (too high) FAILED");
        REQUIRE_THROWS_WITH(sa[4], "Invalid index request, too high");
    }
} */
