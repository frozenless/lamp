#pragma once

namespace lamp
{
	class Random
	{
	public:
		template<typename T> static T linear(const T min, const T max);

		static void seed();
	};
}