/*!
 * \file
 * Implements tests for the nonvolatile_write_set component of libMTM.
 *
 * \author Andres Jaan Tack <tack@cs.wisc.edu>
 */
#include <unittest++/UnitTest++.h>
#include <nonvolatile_write_set.h>
#include "nonvolatile_write_set.fixtures.hxx"

SUITE(NonvolatileWriteSet) {
	TEST_FIXTURE(AllWriteSetsAvailable, FirstAllocationDoesNotFail) {
		nonvolatile_write_set_t* first_set = nonvolatile_write_set_next_available();
		CHECK(first_set != NULL);
	}
	
	TEST_FIXTURE(AllWriteSetsAvailable, SecondAllocationDoesNotFail) {
		nonvolatile_write_set_t* first_set  = nonvolatile_write_set_next_available();
		nonvolatile_write_set_t* second_set = nonvolatile_write_set_next_available();
		CHECK(second_set != NULL);
		CHECK(second_set != first_set);
	}
}