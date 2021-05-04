//.h file code:

#include <string>
#include <vector>
#include <iostream>
#include "rectangularvectors.h"

public:
class OBST
{
public:
	static void main(std::vector<std::wstring> &Art3mis);
	static float CalculateCost(std::vector<std::vector<float>> &a, int i, int j, int n);

};

//Helper class added by Java to C++ Converter:

#include <string>
#include <vector>

int main(int argc, char **argv)
{
    std::vector<std::wstring> args(argv + 1, argv + argc);
    OBST::main(args);
}

//Helper class added by Java to C++ Converter:

//----------------------------------------------------------------------------------------
//	Copyright © 2007 - 2021 Tangible Software Solutions, Inc.
//	This class can be used by anyone provided that the copyright notice remains intact.
//
//	This class includes methods to convert multidimensional arrays to C++ vectors.
//----------------------------------------------------------------------------------------
#include <vector>

class RectangularVectors
{
public:
    static std::vector<std::vector<float>> RectangularFloatVector(int size1, int size2)
    {
        std::vector<std::vector<float>> newVector(size1);
        for (int vector1 = 0; vector1 < size1; vector1++)
        {
            newVector[vector1] = std::vector<float>(size2);
        }

        return newVector;
    }
};

//.cpp file code:

#include "snippet.h"

void OBST::main(std::vector<std::wstring> &Art3mis)
{
	Scanner *s = new Scanner(System::in);
	int n = s->nextInt();
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: float a[][] = new float[n+1][n+1];
	std::vector<std::vector<float>> a = RectangularVectors::RectangularFloatVector(n + 1, n + 1);
	a[0][0] = 0;
	for (int i = 1;i <= n;i++)
	{
			std::wcout << L"Input Key " << (i) << L" : ";
			a[i][i] = s->nextFloat();
	}

	for (int i = 1;i <= n - 1;i++)
	{
		for (int j = 1,k = i + 1;k <= n;k++,j++)
		{
			a[j][k] = CalculateCost(a,j,k,n);
		}
	}
/*        for(int j=0;j<n+1;j++)
            System.out.print(j+" ");
        System.out.println();
        System.out.print("**");
        System.out.println();*/
	std::wcout << std::endl;
	std::wcout << std::endl;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			std::wcout << a[i][j] << L" ";
		}
		std::wcout << std::endl;
	}

	delete s;
}

float OBST::CalculateCost(std::vector<std::vector<float>> &a, int i, int j, int n)
{
	float sum = 0;
	for (int m = i;m <= j;m++)
	{
		sum += a[m][m];
	}
	float temp;
	float cost1 = a[i][i - 1];
	float cost2 = a[i + 1][j];
	float minimum = cost1 + cost2;
	for (int b = i + 1;b <= j;b++)
	{
		cost1 = a[i][b - 1];
		if (b + 1 <= n)
		{
			cost2 = a[b + 1][j];
		}
		else
		{
			cost2 = 0;
		}
		temp = cost1 + cost2;
		if (temp < minimum)
		{
			minimum = temp;
		}
	}
	return minimum + sum;
}

