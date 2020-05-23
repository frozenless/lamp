#include "object.hpp"

namespace lamp::gl
{
	Object::Object(const Type type)
		: _type(type)
		, _id(0)
	{
	}

    Id Object::id() const
    {
        return _id;
    }

    Object::Type Object::type() const {
        return _type;
    }
}
