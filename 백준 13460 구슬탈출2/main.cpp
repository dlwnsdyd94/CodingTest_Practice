#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int N, M;
char myMap[MAX][MAX];
struct Location
{
	int ry, rx, by, bx, count;
};
int visited[MAX][MAX][MAX][MAX];

int bfs(Location start)
{
	// »óÇÏÁÂ¿ì
	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = {0, 0, -1, 1};

	queue<Location> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1;

	int ans = -1;
	while (!q.empty())
	{
		Location now_location = q.front();
		q.pop();

		if (now_location.count > 10) break;
		if (myMap[now_location.ry][now_location.rx] == 'O' && myMap[now_location.by][now_location.bx] != 'O')
		{
			ans = now_location.count;
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int new_ry = now_location.ry;
			int new_rx = now_location.rx;
			int new_by = now_location.by;
			int new_bx = now_location.bx;

			while (1)
			{
				if (myMap[new_ry][new_rx] != 'O' && myMap[new_ry][new_rx] == '#')
				{
					new_ry -= dy[dir];
					new_rx -= dx[dir];
					break;
				}
				else
				{
					if (myMap[new_ry][new_rx] == 'O')
					{
						break;
					}
					else
					{
						new_ry += dy[dir];
						new_rx += dx[dir];
					}
				}
			}

			while (1)
			{
				if (myMap[new_by][new_bx] != 'O' && myMap[new_by][new_bx] == '#')
				{
					new_by -= dy[dir];
					new_bx -= dx[dir];
					break;
				}
				else
				{
					if (myMap[new_by][new_bx] == 'O')
					{
						break;
					}
					else
					{
						new_by += dy[dir];
						new_bx += dx[dir];
					}
				}
			}
			if (new_ry == new_by && new_rx == new_bx)
			{
				if (myMap[new_by][new_bx] != 'O')
				{
					int dist_r = abs(new_ry - now_location.ry) + abs(new_rx - now_location.rx);
					int dist_b = abs(new_by - now_location.by) + abs(new_bx - now_location.bx);

					if (dist_r > dist_b)
					{
						new_ry -= dy[dir];
						new_rx -= dx[dir];
					}
					else
					{
						new_by -= dy[dir];
						new_bx -= dx[dir];
					}
				}
			}

			if(visited[new_ry][new_rx][new_by][new_bx] == 0)
			{
				visited[new_ry][new_rx][new_by][new_bx] = 1;
				Location next;
				next.ry = new_ry;
				next.rx = new_rx;
				next.by = new_by;
				next.bx = new_bx;
				next.count = now_location.count + 1;
				q.push(next);
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
	readFile >> N >> M;

	Location start;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			readFile >> myMap[y][x];
			if (myMap[y][x] == 'R')
			{
				start.ry = y;
				start.rx = x;
			}
			else if (myMap[y][x] == 'B')
			{
				start.by = y;
				start.bx = x;
			}
		}
	}
	start.count = 0;

	cout << bfs(start);

	return 0;
}