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

		void attach(ID shader) const noexcept;
		void detach(ID shader) const noexcept;

		#ifndef NDEBUG
		void status() const;
		#endif
	};
}
