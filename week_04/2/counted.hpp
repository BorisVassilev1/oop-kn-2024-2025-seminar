#pragma once
#include <cstddef>

class Counted {
   public:
	Counted() { ++count; }

	~Counted() { --count; }

	Counted(const Counted &) = delete;
	Counted operator=(const Counted &) = delete;

   private:
	static std::size_t count;

   public:
	static std::size_t getCount() { return count; }
};
