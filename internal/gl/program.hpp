#pragma once

#include "object.hpp"

namespace lamp::gl
{
	struct Program : public Object
	{
		Program();

		void create()  noexcept final;
		void release() noexcept final;

		void bind() const noexcept final;
		void link() const noexcept;

		void attach(ID shader) const noexcept;
		void detach(ID shader) const noexcept;

		static void uniform(int32_t location, float value) noexcept;
		static void uniform(int32_t location, const m4& mat);
		static void uniform(int32_t location, const v3& vec);

		#ifndef NDEBUG
		void status() const;
		#endif
	};
}
