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
	uint32 LeftSideIndex;
	uint32 MiddleIndex ;
	uint32 RightSideIndex;
	bool NoPositive = true;
	bool NoNegative = true;
	bool NoZero = true;

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
				}
				else 
				{
					MiddleIndex = i;
				}
					break;
			}
		}



	//printing debug

	for (uint32 i = 0U; i < ArraySize; i++)
	{
		std::cout << Array[i] << "\t";

	}
	
	//std::cout << "\n" << "Last -ve " << LeftSideIndex << "\tZero " << MiddleIndex << "\tfirst +ve" << RightSideIndex << "\n";


	///First take triplets of -ve,0,+ve
	if (Array[MiddleIndex] == 0)
	{
		for (uint32 i = 0U; i < MiddleIndex; i++)
		{
			if(Array[i+1] == Array[i])
			{
				continue;
			}
			for (uint32 j = MiddleIndex+1U; j < ArraySize; j++)
			{
				if (Array[i] == ((Array[j]) * -1))
				{
					TripletArray.push_back({ Array[i], 0, Array[j] });
					break;
				}
			}
		}
	}

	//Second do the -ve,-ve,+ve triplets

	for (uint32 i = 0U; i < MiddleIndex - 1U; i++)
	{
		for (uint32 j = i + 1U; j < MiddleIndex; j++)
		{
			if ((Array[i] + Array[j]) > ((Array[ArraySize - 1]) * -1))
			{
				break;
			}
			for (uint32 k = MiddleIndex; k < ArraySize; k++)
			{
				if (Array[i] + Array[j] + Array[k] == 0)
				{
					TripletArray.push_back({ Array[i], Array[j], Array[k] });
				}
			}

		}
	}


	///Third Triplets of -ve, +ve, +ve

	for (uint32 i = MiddleIndex + 1U; i < ArraySize - 1U; i++)
	{
		for (uint32 j = i + 1U; j < ArraySize; j++)
		{
			if ((Array[i] + Array[j]) > ((Array[0]) * -1))
			{
				break;
			}
			for (uint32 k = 0U; k < MiddleIndex - 1U; k++)
			{
				if (Array[i] + Array[j] + Array[k] == 0)
				{
					TripletArray.push_back({ Array[i], Array[j], Array[k] });
				}
			}

		}
	}



	
	/*

	//first loop to take X as 1st number fixed with me
	for (uint32 i = 0U; i <= MiddleIndex; i++)
	{
		static uint32 LastTripletIndex = 0U;

		//2ND loop to take Y as 2nd number fixed with me
		for (uint32 j = i+1U; j < ArraySize; j++)
		{
			
			if ((Array[i] + Array[j]) <= 0)
			{
				//start from the 1st +ve element looking for the right Z
				for (uint32 k = MiddleIndex + 1U; k < ArraySize; k++)
				{
					if ((!TripletArray.empty()) &&
						((TripletArray[LastTripletIndex - 1][1] == Array[j]) || (TripletArray[LastTripletIndex - 1][2] == Array[j]))
						&& (TripletArray[LastTripletIndex - 1][0] == Array[i]))
					{
						continue;
					}
					if(j == k)
					{
						++k;
					}

					if ((Array[k] * -1) == (Array[i] + Array[j]))
					{
						TripletArray.push_back({ Array[i], Array[j], Array[k] });
						++LastTripletIndex;
					}
				}
			}


			
			
			
			
			else if (((Array[i] + Array[j]) == 0) && ((Array[i] != 0) || (Array[j] != 0)))
			{
				std::cout << "no triplets found ";
				return TripletArray;
			}
			else if ((Array[i] + Array[j]) > 0)
			{
				std::cout << "no triplets found ";
				return TripletArray;
			}
			
		}
	}
	*/


	/*
	//fix duplication
	for (uint32 i = 0U; i < TripletArray.size(); i++)
	{
		for (uint32 j = i+1U; j < TripletArray.size(); j++)
		{
			if (TripletArray[j] == TripletArray[i])
			{
				TripletArray[j].clear();
			}
		}
	}
	*/
	//std::cout << "\ntriplets = " << TripletArray[0] << "\t" << TripletArray[1] << "\t" << TripletArray[2];

	return   TripletArray;
}


int main()
{
	int32 DataArray[] = { -5,3,2,1,2,-1,0,0,-2,5,3,-1,9,2,-3,-1,1 };
	uint32 Size = sizeof(DataArray) / sizeof(DataArray[0]);



	std::vector <int32> Array(DataArray, DataArray + Size);

	//int32 Ptr = threeSum(Array);

	//std::cout << "\nTriplets =" << *Ptr << "\t" << *(Ptr + 1) << "\t" << *(Ptr + 2);

	std::vector<std::vector<int>> TripletArray = threeSum(Array);

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

