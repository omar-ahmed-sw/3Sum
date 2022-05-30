// 3Sum.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "TypeDef.h"
#include "vector"

std::vector<std::vector<int32>> threeSum(std::vector<int32>& Array)
{
	const uint32 ArraySize = Array.size();
	int32 SortedArray[] = { 0 };
	std::vector<std::vector<int32>> TripletArray
	{
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	};
	uint32 LastNegativeIndex = NAN;
	uint32 ZeroIndex = NAN ;
	uint32 FirstPositiveIndex = NAN;
	bool NoPositive = true;
	bool NoNegative = true;
	bool NoZero = true;

	if (ArraySize < 3U )
	{
		return TripletArray;
	}
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

	//finding the last -ve index 
	for (uint32 i = ZeroIndex - 1U; i >= 0; i--)
	{
		if(Array[i] < 0)
		{
			LastNegativeIndex = i;
			break;
		}
	}

	//finding 1st +ve index

	for (uint32 i = ZeroIndex + 1U; i <ArraySize ; i++)
	{
		if (Array[i] > 0)
		{
			FirstPositiveIndex = i;
			break;
		}
	}

	//need to hold indexes of last -ve , zero, 1st +ve values in the array




	//printing debug

	for (uint32 i = 0U; i < ArraySize; i++)
	{
		std::cout << Array[i] << "\t";

	}
	
	std::cout << "\n" << "Last -ve " << LastNegativeIndex << "\tZero " << ZeroIndex << "\tfirst +ve" << FirstPositiveIndex << "\n";



	

	//first loop to take X as 1st number fixed with me
	for (uint32 i = 0U; i <= ZeroIndex; i++)
	{
		//2ND loop to take Y as 2nd number fixed with me
		for (uint32 j = i+1U; j < ArraySize - 1U; j++)
		{
			if ((Array[i] + Array[j]) < 0)
			{
				//start from the 1st +ve element looking for the right Z
				for (uint32 k = FirstPositiveIndex; k < ArraySize; k++)
				{
					if ((Array[k] * -1) == (Array[i] + Array[j]))
					{
						static uint32 Dimension = 0U;
						TripletArray[Dimension].push_back(Array[i]);
						TripletArray[Dimension].push_back(Array[j]);
						TripletArray[Dimension].push_back(Array[k]);

						++Dimension;
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
	int32 DataArray[] = {NAN};
	uint32 Size = sizeof(DataArray) / sizeof(DataArray[0]);



	std::vector <int32> Array(DataArray, DataArray + Size);

	//int32 Ptr = threeSum(Array);

	//std::cout << "\nTriplets =" << *Ptr << "\t" << *(Ptr + 1) << "\t" << *(Ptr + 2);

	std::vector<std::vector<int32>> TripletArray = threeSum(Array);

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

