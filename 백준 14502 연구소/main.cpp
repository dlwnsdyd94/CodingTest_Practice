#include<bits/stdc++.h>
using namespace std;

#define MAX 8

int N, M;
int Map[MAX][MAX];
int virus_visited[MAX][MAX];
int wall_visited[MAX][MAX];

struct Point
{
	int y, x;
};
vector<Point> virus;

// »óÇÏÁÂ¿ì
// »ó : 0
// ÇÏ : 1
// ÁÂ : 2
// ¿ì : 3
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int start_visited = 0;
int virus_visited_count = 0;
int Min_visited_count = 987654321;

void virus_move_bfs(int y, int x)
{
	queue<Point> q;
	q.push({ y, x });

	while (!q.empty())
	{
		int now_y = q.front().y;
		int now_x = q.front().x;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int new_y = now_y + dy[dir];
			int new_x = now_x + dx[dir];

			if (new_y >= N || new_y < 0 || new_x >= M || new_x < 0 || Map[new_y][new_x] != 0 || wall_visited[new_y][new_x] == 1 || virus_visited[new_y][new_x] == 1)
			{
				continue;
			}
			else
			{
				virus_visited[new_y][new_x] = 1;
				virus_visited_count += 1;
				q.push({ new_y, new_x });
			}
		}
	}
}

void set_wall_dfs(int now_y, int  now_x, int wall_count)
{
	if (wall_count == 3)
	{
		for (Point a : virus)
		{
			virus_move_bfs(a.y, a.x);
		}
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				virus_visited[y][x] = 0;
			}
		}
		if (Min_visited_count > virus_visited_count)
		{
			Min_visited_count = virus_visited_count;
		}

		virus_visited_count = 0;
		return;
	}

	for (int y = now_y; y < N; y++)
	{
		for (int x = now_x; x < M; x++)
		{
			if (Map[y][x] == 0 && wall_visited[y][x] == 0)
			{
				wall_visited[y][x] = 1;
				set_wall_dfs(y, x, wall_count + 1);
				wall_visited[y][x] = 0;
			}
		}
		now_x = 0;
	}

}

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
			if (Map[j][i] == 2)
			{
				virus.push_back({j, i});
				start_visited += 1;
			}
			else if (Map[j][i] == 1)
			{
				start_visited += 1;
			}
		}
	}

	set_wall_dfs(0, 0, 0);

	cout << M * N - Min_visited_count - start_visited - 3;

	return 0;
}