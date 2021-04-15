#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int N;
struct Game
{
	int map[MAX][MAX];
	int count;
	int value;
};

int bfs(Game start)
{
	// 상하좌우
	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = {0, 0, -1, 1};

	queue<Game> q;
	q.push(start);

	int ans = start.value;
	while (!q.empty())
	{
		Game now_map = q.front();
		q.pop();

		if (now_map.count == 5)
		{
			// 최대값 알아내기 = ans
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int new_map[MAX][MAX];
			memcpy(new_map, now_map.map, sizeof(now_map.map));

			while (1)
			{

			}
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N;

	Game start;
	int myMax = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			readFile >> start.map[y][x];
			if (myMax < start.map[y][x])
			{
				myMax = start.map[y][x];
			}
		}
	}
	start.count = 0;
	start.value = myMax;

	cout << bfs(start);

	return 0;
}