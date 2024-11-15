// 3Sum.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include "vector"
#include <algorithm> 

std::vector<std::vector<int>> threeSum(std::vector<int32>& Array)
{
	const uint32 ArraySize = Array.size();
	int32 SortedArray[] = { 0 };
	std::vector<std::vector<int>> TripletArray;
	uint32 LastNegIndex;
	uint32 MiddleIndex ;
	uint32 FisrtPosIndex;

	//no triplets if : items are less than 3 before even sorting
	if (ArraySize < 3U)
	{
		return TripletArray;
	}

	//sorting the array first
	std::sort(Array.begin(), Array.end());

	//no triplets if : all positive values, or, all negative values
	if (((Array[0] + Array[1] + Array[2]) > 0) || ((Array[ArraySize - 1] + Array[ArraySize - 2] + Array[ArraySize - 3]) < 0))
	{
		return TripletArray;
	}

	//if all items are 0s or at least 1st three items or  last three items are 0s
	if (((Array[0] == 0) && (Array[2] == 0)) || ((Array[ArraySize - 1] == 0) && (Array[ArraySize - 3] == 0)))
	{	
			TripletArray.push_back({ 0,0,0 });

		return TripletArray;
	}


		//finding the middle, leftside and rightside indexes 
		for (uint32 i = 0U; i < ArraySize; i++)
		{
			if (Array[i] > 0)
			{
				if (Array[i - 1] == 0U)
				{
					MiddleIndex = i - 1U;
					FisrtPosIndex = i;
					uint32 j = i - 1U;
					while (Array[j] == 0U)
					{
						--j;
					}
					LastNegIndex = j;
					if ((MiddleIndex - LastNegIndex) >= 3U)
					{
						TripletArray.push_back({ 0,0,0 });
					}
				}
				else 
				{
					MiddleIndex = i;
					FisrtPosIndex = MiddleIndex;
					LastNegIndex = i - 1U;
				}
					break;
			}
		}


		/*
	//printing debug

	for (uint32 i = 0U; i < ArraySize; i++)
	{
		std::cout << Array[i] << "\t";

	}
	
	//std::cout << "\n" << "Last -ve " << LeftSideIndex << "\tZero " << MiddleIndex << "\tfirst +ve" << RightSideIndex << "\n";
	*/

	///First take triplets of -ve,0,+ve
	if (Array[MiddleIndex] == 0)
	{
		for (uint32 i = 0U; i <= LastNegIndex; i++)
		{
			if(Array[i+1] == Array[i])
			{
				continue;
			}
			for (uint32 j = FisrtPosIndex; j < ArraySize; j++)
			{
				if (Array[i] == ((Array[j]) * -1))
				{
					TripletArray.push_back({ Array[i], 0, Array[j] });
					break;
				}
			}
		}
	}


	uint32 LastTripletIndex = TripletArray.size() - 1U;

	//Second do the -ve,-ve,+ve triplets

	for (uint32 i = 0U; i < LastNegIndex; i++)
	{
		for (uint32 j = i + 1U; j <= LastNegIndex; j++)
		{
			if(Array[j] == 0)
			{
				continue;
			}
			if (((Array[i] + Array[j]) * -1) > (Array[ArraySize - 1]))
			{
				continue;
			}
			for (uint32 k = FisrtPosIndex; k < ArraySize; k++)
			{
				if (Array[i] + Array[j] + Array[k] == 0)
				{
					bool Duplicate = false;
					if ((!TripletArray.empty()) && (TripletArray[LastTripletIndex][0] == Array[i]))
					{ 
						uint32 n = 0U;
						while((LastTripletIndex >= n) && (TripletArray[LastTripletIndex - n][0] == Array[i]))
						{
							if ((TripletArray[LastTripletIndex - n][1] == Array[j]) || (TripletArray[LastTripletIndex - n][2] == Array[j]))
							{
								Duplicate = true;
								break;	
							}
							++n;
						}
					}
					if (Duplicate) { continue; }
					else
					{
						TripletArray.push_back({ Array[i], Array[j], Array[k] });
						++LastTripletIndex;
					}
				}
			}

		}
	}


	///Third Triplets of -ve, +ve, +ve

	for (uint32 i = FisrtPosIndex; i < ArraySize - 1U; i++)
	{
		for (uint32 j = i + 1U; j < ArraySize; j++)
		{
			if ((Array[i] + Array[j]) > ((Array[0]) * -1))
			{
				continue;
			}
			for (uint32 k = 0U; k <= LastNegIndex; k++)
			{
				if (Array[k] == 0)
				{
					continue;
				}
				if (Array[i] + Array[j] + Array[k] == 0)
				{
					bool Duplicate = false;
					if ((!TripletArray.empty()) && (TripletArray[LastTripletIndex][0] == Array[i]))
					{
						uint32 n = 0U;
						while ((LastTripletIndex >= n) && (TripletArray[LastTripletIndex - n][0] == Array[i]))
						{
							if ((TripletArray[LastTripletIndex - n][1] == Array[j]) || (TripletArray[LastTripletIndex - n][2] == Array[j]))
							{
								Duplicate = true;
								break;
							}
							++n;
						}
					}
					if (Duplicate) { continue; }
					else
					{
						TripletArray.push_back({ Array[i], Array[j], Array[k] });
						++LastTripletIndex;
					}
				}

			}
		}

	}

	return   TripletArray;
}


int main()
{
	int32 DataArray[] = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
	uint32 Size = sizeof(DataArray) / sizeof(DataArray[0]);



	std::vector <int32> Array(DataArray, DataArray + Size);

	std::vector<std::vector<int>> TripletArray = threeSum(Array);

	std::cout << "\n\n";

	for (uint32 i = 0U; i < TripletArray.size(); i++)
	{

		for (uint32 j = 0U; j < TripletArray[i].size(); j++)
		{
			std::cout << TripletArray[i][j] << " ";
		}
		std::cout << "\n";
	}
	while (true)
	{

	}
    return 0;
}

