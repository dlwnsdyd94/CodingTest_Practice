#include<bits/stdc++.h>
using namespace std;

#define MAX 500

int N, M;
int Map[MAX][MAX];

int block[19][4][2] = 
{
	// 1번 블록
	{
		{0, 0}, {0, 1}, {0, 2}, {0, 3}
	},
	// 2번 블록
	{
		{0, 0}, {1, 0}, {2, 0}, {3, 0}
	},
	// 3번 블록
	{
		{0, 0}, {1, 0}, {0, 1}, {1, 1}
	},
	// 4번 블록
	{
		{0, 0}, {1, 0}, {2, 0}, {2, 1}
	},
	// 5번 블록
	{
		{0, 0}, {-2, 1}, {-1, 1}, {0, 1}
	},
	// 6번 블록
	{
		{0, 0}, {1, 0}, {0, 1}, {0, 2}
	},
	// 7번 블록
	{
		{0, 0}, {0, 1}, {0, 2}, {1, 2}
	},
	// 8번 블록
	{
		{0, 0}, {0, 1}, {1, 1}, {2, 1}
	},
	// 9번 블록
	{
		{0, 0}, {1, 0}, {2, 0}, {0, 1}
	},
	// 10번 블록
	{
		{0, 0}, {0, 1}, {0, 2}, {-1, 2}
	},
	// 11번 블록
	{
		{0, 0}, {1, 0}, {1, 1}, {1, 2}
	},
	// 12번 블록
	{
		{0, 0}, {1, 0}, {1, 1}, {2, 1}
	},
	// 13번 블록
	{
		{0, 0}, {1, 0}, {0, 1}, {-1, 1}
	},
	// 14번 블록
	{
		{0, 0}, {0, 1}, {-1, 1}, {-1, 2}
	},
	// 15번 블록
	{
		{0, 0}, {0, 1}, {1, 1}, {1, 2}
	},
	// 16번 블록
	{
		{0, 0}, {0, 1}, {0, 2}, {1, 1}
	},
	// 17번 블록
	{
		{0, 0}, {1, 0}, {2, 0}, {1, 1}
	},
	// 18번 블록
	{
		{0, 0}, {0, 1}, {0, 2}, {-1, 1}
	},
	// 19번 블록
	{
		{0, 0}, {0, 1}, {-1, 1}, {1, 1}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> M;

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			readFile >> Map[j][i];
		}
	}

	int Max = 0;
	int flag = 0;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			for (int block_num = 0; block_num < 19; ++block_num)
			{
				int sum_block = 0;
				for (int dir = 0; dir < 4; ++dir)
				{
					int ny = block[block_num][dir][0] + y;
					int nx = block[block_num][dir][1] + x;
					if (ny >= N || ny < 0 || nx >= M || nx < 0)
					{
						flag = 1;
						break;
					}
					sum_block += Map[ny][nx];
				}
				if (flag == 1)
				{
					flag = 0;
					continue;
				}

				if (Max < sum_block)
				{
					Max = sum_block;
				}
			}
		}
	}

	cout << Max;

	return 0;
}