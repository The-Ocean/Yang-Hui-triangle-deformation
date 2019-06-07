//iNOC产品部-杨辉三角的变形
//1  0  0  0  0  0  0  0  0
//1  1  1  0  0  0  0  0  0 
//1  2  3  2  1  0  0  0  0
//1  3  6  7  6  3  1  0  0
//1  4 10 16 19 16 10  4  1
//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
//
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
//
//
//
//输入n(n <= 1000000000)
#include<iostream>
#include<vector>

int main()
{
	int n;
	while (std::cin >> n) {
		if (n == 1 || n == 2)
		{
			std::cout << -1 << std::endl;
			continue;
		}
		std::vector<std::vector<int>> arr;
		arr.resize(n);
		for (int i = 0; i < n; i++)
		{
			arr[i].resize((n-1) * 2 + 1);
			for (int j = 0; j < n * 2 + 1; j++)
			{
				if (j < i * 2 + 1)
				{
					arr[i][0] = 1;
					arr[i][1] = i;
					if (i > 0)
					{
						arr[i][i * 2] = 1;
					}
					if (j > 1 && i > 1)
					{
						arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 1][j - 2];
					}
				}

			}
		}

		for (int i = 0; i < n * 2 + 1; i++)
		{
			if (arr[n - 1][i] % 2 == 0)
			{
				std::cout << i + 1 << std::endl;
				break;
			}
			if (i == n * 2)
			{
				std::cout << -1 << std::endl;
			}
		}
	}
	return 0;
}