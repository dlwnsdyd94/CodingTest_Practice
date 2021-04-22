#include<bits/stdc++.h>
using namespace std;

int N, M, H;
int wall_map[31][10];

int Min_wall = 987654321;

bool go_ladder()
{
	for (int player_num = 0; player_num < N; player_num++)
	{
		int pos = player_num;

		for (int y = 0; y < H; y++)
		{
			// 사다리가 플레이어의 왼쪽에 있는 지 확인
			if (player_num - 1 >= 0 && wall_map[y][player_num - 1] != 0)
			{
				// 왼쪽에 있으면 플레이어 위치 변환
				player_num -= 1;

			}

			// 사다리가 플레이어의 오른쪽에 있는 지 확인
			else if (player_num + 1 < N && wall_map[y][player_num] != 0)
			{
				// 오른쪽에 있으면 플레이어 위치 변환
				player_num += 1;

			}
		}
		if (player_num != pos)
		{
			return false;
		}
	}

	return true;
}

void wall_dfs(int y, int x, int count, int limit)
{
	if (count == limit)
	{
		// 사다리 타기
		if (go_ladder())
		{
			if (Min_wall > count)
			{
				Min_wall = count;
			}
		}
		return;
	}

	for (int ny = y; ny < H; ny++)
	{
		for (int nx = x; nx < N - 1; nx++)
		{
			if (wall_map[ny][nx] == 0)
			{
				if ((nx - 1 >= 0 && wall_map[ny][nx - 1] != 0 ) || (nx + 1 < N - 1 && wall_map[ny][nx + 1] != 0)) // 사다리를 연속해서 둘 수 없을때
				{
					continue;
				}
				wall_map[ny][nx] = 2;
				wall_dfs(ny, nx, count + 1, limit);
				wall_map[ny][nx] = 0;
			}
		}
		x = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		readFile >> a >> b;

		wall_map[a - 1][b - 1] = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		wall_dfs(0, 0, 0, i);
		if (Min_wall != 987654321)
		{
			break;
		}
	}

	if (Min_wall == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << Min_wall;
	}

	return 0;
}