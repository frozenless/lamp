#pragma once

namespace lamp
{
	class Random
	{
	public:
		Random() = delete;

		template<typename T> static T linear(T min, T max);

		static void seed();
	};
}