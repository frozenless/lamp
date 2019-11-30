#pragma once

namespace lamp::gl
{
	class Attribute
	{
	public:
		Attribute(int index, int count, int offset);

		void update(int vertex_size) const noexcept;
		void enable() const noexcept;

		int count;

	private:
		int _index;
		int _offset;
	};
}
