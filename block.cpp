#include "block.h"

std::pair<int, int> Block::get_coords() const
{
    return std::make_pair(Block::x, Block::y);
}

bool Block::is_destroyed() const
{
   return Block::crashed;
}
