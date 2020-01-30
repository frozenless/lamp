#pragma once

#include "object.hpp"

namespace lamp::gl
{
	struct Program : public Object
	{
		void create()  noexcept;
		void release() const noexcept;

		void bind() const noexcept final;
		void link() const noexcept;

		void attach(handle shader) const noexcept;
		void detach(handle shader) const noexcept;

		static void uniform(int location, f32 value) noexcept;
		static void uniform(int location, const m4& mat);
		static void uniform(int location, const v3& vec);

		#ifndef NDEBUG
		void status();
		#endif
	};
}
