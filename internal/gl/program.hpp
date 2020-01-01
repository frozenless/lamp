#pragma once

#include "types.hpp"

namespace lamp::gl
{
	struct Program
	{
		Program();

		void create()  noexcept;
		void release() const noexcept;

		void use()  const noexcept;
		void link() const noexcept;

		void attach(handle shader) const noexcept;
		void detach(handle shader) const noexcept;

		static void uniform(int location, f32 value) noexcept;
		static void uniform(int location, const m4& mat);
		static void uniform(int location, const v3& vec);

		#ifndef NDEBUG
		void status();
		#endif

		handle id;
	};
}
