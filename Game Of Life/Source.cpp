#include "GameOfLife.h"

int main()
{
	std::vector<std::tuple<uint32_t, uint32_t>> mv_aStartingPositions
	{
		std::make_tuple(5, 4),
		std::make_tuple(7, 4),
		std::make_tuple(5, 5),
		std::make_tuple(6, 5),
		std::make_tuple(5, 6),
	};

	GameOfLife mv_GameOfLife(Type::RANDOM, mv_aStartingPositions);
	mv_GameOfLife.mf_Start();

	return 0;
}