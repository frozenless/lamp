#pragma once

#include "util.hpp"

namespace lamp::gl
{
	struct Program
	{
		void use()  const noexcept;
		void link() const noexcept;

		void attach(u32 shader) const noexcept;
		void detach(u32 shader) const noexcept;

		static void uniform(int location, f32 value) noexcept;
		static void uniform(int location, const m4& mat);
		static void uniform(int location, const v3& vec);

		u32 id;
	};
}
