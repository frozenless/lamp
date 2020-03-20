#ifndef NDEBUG

void* operator new(size_t size)
{
	std::cerr << "allocating " << size << " bytes\n";

	return malloc(size);
}

void operator delete(void* ptr, size_t size) noexcept
{
	std::cerr << "freeing " << size << " bytes\n";

	free(ptr);
}

#endif