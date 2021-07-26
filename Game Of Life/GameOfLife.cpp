#include "GameOfLife.h"
#include "WindowsStuff.h"

#include <iostream>
#include <Windows.h>

GameOfLife::GameOfLife(Type av_eGameType, const std::vector<std::tuple<uint32_t, uint32_t>>& ac_aCellPositions)
{
	switch (av_eGameType)
	{
	case Type::RANDOM:
		mv_Grid = std::make_unique<Grid>();
		break;
	case Type::DEFINED:
		mv_Grid = std::make_unique<Grid>(ac_aCellPositions);
		break;
	case Type::UNKNOWN:
	default:
		break;
	}
}

void GameOfLife::mf_Start()
{
	while (true)
	{
		mf_PrintGrid();
		mf_DetermineGridState();
		mf_RefreshScreen();
	}
}

void GameOfLife::mf_PrintGrid() const
{
	auto av_nGridSize = mv_Grid->mf_nGetGridSize();

	for (size_t i = 1; i < av_nGridSize; i++)
	{
		for (size_t j = 1; j < av_nGridSize; j++)
		{
			if (mv_Grid->mf_bValueAt(i, j) == true)
			{
				std::cout << " O ";
			}
			else
			{
				std::cout << " . ";
			}
			if (j == av_nGridSize - 1)
			{
				std::cout << std::endl;
			}
		}
	}
}

void GameOfLife::mf_DetermineGridState()
{
	auto av_nGridSize = mv_Grid->mf_nGetGridSize();
	std::unique_ptr<Grid> av_aCopyGrid = std::make_unique<Grid>((*mv_Grid));

	for (size_t i = 1; i < av_nGridSize; i++)
	{
		for (size_t j = 1; j < av_nGridSize; j++)
		{
			size_t av_nAlive = 0;
			for (int x = -1; x < 2; x++)
			{
				for (int y = -1; y < 2; y++)
				{
					if (!(x == 0 && y == 0))
					{
						if (av_aCopyGrid->mf_bValueAt(i + x, j + y))
						{
							++av_nAlive;
						}
					}
				}
			}

			if (av_nAlive < 2)
			{
				mv_Grid->mf_SetValueAt(i, j, false);
			}
			else if (av_nAlive == 3)
			{
				mv_Grid->mf_SetValueAt(i, j, true);
			}
			else if (av_nAlive > 3)
			{
				mv_Grid->mf_SetValueAt(i, j, false);
			}
		}
	}
}

void GameOfLife::mf_RefreshScreen() const
{
	cls();
}
