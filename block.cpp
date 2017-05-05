#include <block.h>

std::pair<int, int> block::get_coords() const
{
    return std::make_pair(block::x, block::y);
}

bool block::is_destroyed() const
{
   return block::crashed;
}
