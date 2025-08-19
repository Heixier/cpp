#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::Serializer() { }
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator= (const Serializer& other) { return ((void)other, *this); }
Serializer::~Serializer() { }

