#pragma once

#include "Grid.h"

#include <memory>


enum class Type
{
	RANDOM,
	DEFINED,
	UNKNOWN
};

class GameOfLife
{
public:
	GameOfLife(Type av_eGameType, const std::vector<std::tuple<uint32_t, uint32_t>>& ac_aCellPositions = {});
	void mf_Start();

private:
	void mf_PrintGrid() const;
	void mf_DetermineGridState();
	void mf_RefreshScreen() const;

private:
	std::unique_ptr<Grid> mv_Grid;
};

