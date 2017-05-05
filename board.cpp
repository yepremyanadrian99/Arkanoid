#include "Board.h"

std::pair<int, int> Board::get_coords() const
{
    return std::make_pair(x, y);
}
