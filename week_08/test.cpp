#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../week_07/doctest.h"
#include "vector.hpp"

TEST_CASE("vector creation") {
	SUBCASE("primitive type") {
		Vector<int> v;
		CHECK_EQ(v.Size(), 0);
	}
	SUBCASE("string ") {
		Vector<std::string> v;
		CHECK_EQ(v.Size(), 0);
	}
}

TEST_CASE("vector push") {
	Vector<int> v;
	SUBCASE("push") {
		v.Push(1);
		v.Push(2);
		v.Push(3);
	}
	SUBCASE("+=") {
		v += 1;
		v += 2;
		v += 3;
	}

	CHECK_EQ(v.Size(), 3);

	CHECK_EQ(v[0], 1);
	CHECK_EQ(v[1], 2);
	CHECK_EQ(v[2], 3);
}

TEST_CASE("vector iterator") {
	Vector<int> v;
	v.Push(0);
	v.Push(1);
	v.Push(2);
	v.Push(3);
	CHECK_EQ(v.Size(), 4);

	int k;
	SUBCASE("forward") {
		k = 0;
		for (auto i = v.begin(); i != v.end(); ++i) {
			CHECK_EQ(*i, k);
			++k;
		}
	}
	SUBCASE("reverse") {
		k = 3;
		for (auto i = v.rbegin(); i != v.rend(); ++i) {
			CHECK_EQ(*i, k);
			--k;
		}
	}
}

TEST_CASE("operator=") {
	Vector<int> v;
	v.Push(1);
	v.Push(2);
	v.Push(3);
	
	Vector<int> copy;
	copy = v;
	CHECK_EQ(copy[0], 1);
	CHECK_EQ(copy[1], 2);
	CHECK_EQ(copy[2], 3);

	Vector<int> moved = std::move(copy);

	CHECK_EQ(moved[0], 1);
	CHECK_EQ(moved[1], 2);
	CHECK_EQ(moved[2], 3);
}

