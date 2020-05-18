#pragma once

#include "object.hpp"

namespace lamp::gl
{
	class Program : public Object
	{
	public:
		Program();

		void create()  noexcept final;
		void release() noexcept final;

		void bind() const noexcept final;
		void link() const noexcept;

		void attach(Id shader) const noexcept;
		void detach(Id shader) const noexcept;

		#ifndef NDEBUG
		void status() const;
		#endif
	};
}
