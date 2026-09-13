#include "Body.h"

class Funcs {
public:
	static double KE(Body* body);
	static double PE(Body* body);
	static double ME(Body* body);

	template <typename T>
	static bool vector_contains(std::vector<T> vector, T obj);
};