#pragma once

#include <glad/glad.h>

template<typename T> u32 create_buffer(const u32 type, const std::vector<T> &info, const u32 usage) noexcept
{
	u32 id;
	glGenBuffers(1, &id);

	glBindBuffer(type, id);
	glBufferData(type, sizeof(T) * info.size(), info.data(), usage);

	return id;
}