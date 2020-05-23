#pragma once

#include "types.hpp"

namespace lamp::events
{
    struct Input
    {
        int32_t action;
        int32_t key;
    };
}