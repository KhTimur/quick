#include "catch.hpp"
#include <quick.h>
#include <iterator>

TEST_CASE("quick test") {

	int nums[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *begi = std::begin(nums);
	int *en = std::end(nums);
	quick_sort(begi, en);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums[i] == nums_proverka[i]);
	}
}
