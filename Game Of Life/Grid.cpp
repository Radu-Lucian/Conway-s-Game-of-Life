#include "Grid.h"

#include <random>

Grid::Grid(const std::vector<std::tuple<uint32_t, uint32_t>>& ac_aCellPositions)
{
	for (const auto& [av_nX, av_nY] : ac_aCellPositions)
	{
		this->mv_aGrid[av_nX][av_nY] = true;
	}
}

Grid::Grid()
{
	std::random_device mv_Rand;
	std::mt19937 mv_Mt(mv_Rand());
	std::uniform_int_distribution<size_t> mv_RandomGeneratorCells(1, sc_nGridSize);
	std::uniform_int_distribution<size_t> mv_RandomGeneratorPositions(1, (sc_nGridSize * sc_nGridSize) / 2);

	auto mv_nCellToGenerate = mv_RandomGeneratorPositions(mv_Mt);

	for (size_t i = 0; i < mv_nCellToGenerate; i++)
	{
		auto mv_nX = mv_RandomGeneratorCells(mv_Mt);
		auto mv_nY = mv_RandomGeneratorCells(mv_Mt);

		this->mv_aGrid[mv_nX][mv_nY] = true;
	}
}

Grid::Grid(const Grid& mv_Other)
{
	for (int i = 0; i < sc_nGridSize; i++)
	{
		for (int j = 0; j < sc_nGridSize; j++)
		{
			mv_aGrid[i][j] = mv_Other.mv_aGrid[i][j];
		}
	}
}

void Grid::mf_SetValueAt(uint32_t av_nX, uint32_t av_nY, bool av_bValue)
{
	mv_aGrid[av_nX][av_nY] = av_bValue;
}

uint32_t Grid::mf_nGetGridSize() const
{
	return sc_nGridSize;
}

bool Grid::mf_bValueAt(uint32_t av_nX, uint32_t av_nY) const
{
	return mv_aGrid[av_nX][av_nY];
}
