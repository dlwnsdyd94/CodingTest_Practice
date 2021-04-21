#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int N, L;
int Map[MAX][MAX];
int div_arr[MAX][MAX];
int ans = 0;

void divide_arr()
{
	int div_num = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			div_arr[div_num][x] = Map[y][x];
		}
		div_num += 1;
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			div_arr[div_num][x] = Map[x][y];
		}
		div_num += 1;
	}
}

bool check_slope(int num) // 오른쪽에 경사면을 두거나 그냥 갈 수 있는지
{
	int count = 1;
	int down_slope_cur = -1;
	for (int cur = 0; cur < N; cur++)
	{
		if (cur + 1 < N && div_arr[num][cur] == div_arr[num][cur + 1])
		{
			count += 1;
			continue;
		}

		// 오른쪽 하강과 상승 경사
		if (cur + 1 < N && abs(div_arr[num][cur] - div_arr[num][cur + 1]) > 1) // 2칸 이상 차이가 날때
		{
			return false;
		}

		if (cur + 1 < N)
		{
			// 오른쪽에 하강 경사
			if (div_arr[num][cur] - div_arr[num][cur + 1] == 1)
			{
				for (int slope = 1; slope <= L; slope++)
				{
					if (cur + slope >= N || (div_arr[num][cur] - div_arr[num][cur + slope]) != 1) // 경사면이 밖으로 나가거나 면이 고르지 않을때
					{
						return false;
					}
				}
				count = 1;
				down_slope_cur = cur + L;
			}

			// 오른쪽에 상승 경사
			else if (div_arr[num][cur] - div_arr[num][cur + 1] == -1)
			{
				if (count < L)
				{
					return false;
				}

				if (down_slope_cur >= cur + 1 - L)
				{
					return false;
				}
				count = 1;
			}
		}
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> L;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			readFile >> Map[y][x];
		}
	}

	divide_arr(); // 1차원으로 분리

	for (int num = 0; num < 2*N; num++)
	{
		if (check_slope(num))
		{
			//cout << "num : " << num << '\n';
			ans += 1;
		}
	}

	cout << ans;

	return 0;
}