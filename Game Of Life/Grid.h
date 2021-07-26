#pragma once

#include <cstdint>
#include <array>
#include <vector>


class Grid
{
public:
	Grid(const std::vector<std::tuple<uint32_t, uint32_t>>& ac_aCellPositions);
	Grid(); // Random generation of cells

	Grid(const Grid& mv_Other);

	void mf_SetValueAt(uint32_t av_nX, uint32_t av_nY, bool av_bValue);

	uint32_t mf_nGetGridSize() const;
	bool mf_bValueAt(uint32_t av_nX, uint32_t av_nY) const;

private:
	static const uint32_t sc_nGridSize = 50;

private:
	bool mv_aGrid[sc_nGridSize + 1][sc_nGridSize + 1]{};
};

