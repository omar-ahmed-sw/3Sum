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
	uint32 LeftSideIndex = NAN;
	uint32 MiddleIndex = NAN ;
	uint32 RightSideIndex = NAN;
	bool NoPositive = true;
	bool NoNegative = true;
	bool NoZero = true;

	//sorting the array first
	std::sort(Array.begin(), Array.end());

	//no triplets if : items are less than 3, all positive values, or, all negative values
	if ((ArraySize < 3U) || (Array[0] > 0) || (Array[ArraySize-1] <= 0))
	{
		return TripletArray;
	}

	/*
	//sorting the array first
	for (uint32 j = 0U; j < ArraySize - 1U; j++)
	{
		for (uint32 i = 0U; i < ArraySize - 1U; i++)
		{
			if (Array[i + 1] < Array[i])
			{
				int32 Temp = 0;
				Temp = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = Temp;
				NoPositive = (Array[i] > 0) ? (false) : NoPositive;
				NoNegative = (Array[i] < 0) ? (false) : NoNegative;
			}
			if (Array[i] == 0)
			{
				NoZero = false;
				ZeroIndex = i;
			}
		}
	}

	if (NoNegative || NoPositive)
	{
		std::cout << "no triplets found ";
		return TripletArray;
	}

	*/


	//finding the middle, leftside and rightside indexes 
	for (uint32 i = 0U; i < ArraySize; i++)
	{
		if (Array[i] > 0)
		{
			RightSideIndex = i;
			if (Array[i - 1] == 0)
			{
				MiddleIndex = i - 1U;
				LeftSideIndex = i - 2U;
				break;
			}
			else
			{
				LeftSideIndex = i - 1U;
				break;
			}
		}
	}




	//printing debug

	for (uint32 i = 0U; i < ArraySize; i++)
	{
		std::cout << Array[i] << "\t";

	}
	
	std::cout << "\n" << "Last -ve " << LeftSideIndex << "\tZero " << MiddleIndex << "\tfirst +ve" << RightSideIndex << "\n";



	

	//first loop to take X as 1st number fixed with me
	for (uint32 i = 0U; i <= MiddleIndex; i++)
	{
		//2ND loop to take Y as 2nd number fixed with me
		for (uint32 j = i+1U; j < ArraySize - 1U; j++)
		{
			if ((Array[i] + Array[j]) < 0)
			{
				//start from the 1st +ve element looking for the right Z
				for (uint32 k = RightSideIndex; k < ArraySize; k++)
				{
					if ((Array[k] * -1) == (Array[i] + Array[j]))
					{
						TripletArray.push_back({ Array[i], Array[j], Array[k] });
					}
				}
			}
			/*
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
			*/
		}
	}

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

	//std::cout << "\ntriplets = " << TripletArray[0] << "\t" << TripletArray[1] << "\t" << TripletArray[2];

	return   TripletArray;
}


int main()
{
	int32 DataArray[] = {-5, 5,1,2,6,9,1,0,2 };
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

