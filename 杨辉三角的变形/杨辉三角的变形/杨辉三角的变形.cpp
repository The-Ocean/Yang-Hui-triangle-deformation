//iNOC��Ʒ��-������ǵı���
//1  0  0  0  0  0  0  0  0
//1  1  1  0  0  0  0  0  0 
//1  2  3  2  1  0  0  0  0
//1  3  6  7  6  3  1  0  0
//1  4 10 16 19 16 10  4  1
//���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
//
//���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
//
//
//
//����n(n <= 1000000000)
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