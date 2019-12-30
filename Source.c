/*
Copyright 2019 Drak Lord

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#define N 5

void targetTester(int target[N][N])
{
	int i,j, max = target[0][0], flag = 1;
	for (i = 0; i < (int)(N/2) && flag; i++)
	{
		for (j = i; j < N-i && flag; j++)
		{
			if (target[i][j] != max)
				flag = 0;
			if (target[j][i] != max)
				flag = 0;
			if (target[N-1-j][i] != max)
				flag = 0;
			if (target[N-1-i][j] != max)
				flag = 0;
		}
		if (max >= target[i + 1][i + 1])
			flag = 0;
		max = target[i + 1][i + 1];
	}
	if (flag)
	{
		printf("The target is good");
		return;
	}
	printf("Target is bad");
	return;

}

int main()
{
	int target[N][N] = {
		{30,30,30,30,30},
		{30,40,40,40,30},
		{30,40,100,40,30},
		{30,40,40,40,30},
		{30,30,30,30,30}
	};
	targetTester(target);
	return 0;
}