#include "vector.hpp"

struct Thing{
	int i;
	char *p;
};

int main(int argc, char const *argv[])
{
	vector<Thing> v(6);
	std::cout << "size " << v.size()
	<< " capacity " << v.capacity() << '\n';
	return 0;
}
