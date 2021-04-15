#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int N, M;
char myMap[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];
struct Location
{
	int rx, ry, bx, by, count;
};

//상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs(Location start)
{
	queue<Location> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1;

	int ans = -1;
	while (!q.empty())
	{
		Location now_location = q.front();
		q.pop();

		if (now_location.count > 10) break;
		if(myMap[now_location.ry][now_location.rx] == 'O' && myMap[now_location.by][now_location.bx] != 'O')
		{
			ans = now_location.count;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int new_rx = now_location.rx;
			int new_ry = now_location.ry;
			int new_bx = now_location.bx;
			int new_by = now_location.by;

			//R의 입장
			while (1)
			{
				if (myMap[new_ry][new_rx] != '#' && myMap[new_ry][new_rx] != 'O')
				{
					new_ry += dy[i];
					new_rx += dx[i];
				}
				else
				{
					if (myMap[new_ry][new_rx] == '#')
					{
						new_ry -= dy[i];
						new_rx -= dx[i];
					}
					break;
				}
			}

			//B의 입장
			while (1)
			{
				if (myMap[new_by][new_bx] != '#' && myMap[new_by][new_bx] != 'O')
				{
					new_by += dy[i];
					new_bx += dx[i];
				}
				else
				{
					if (myMap[new_by][new_bx] == '#')
					{
						new_by -= dy[i];
						new_bx -= dx[i];
					}
					break;
				}
			}

			if (new_ry == new_by && new_rx == new_bx)
			{
				if (myMap[new_ry][new_rx] != 'O')
				{
					int dist_r = abs(new_ry - now_location.ry) + abs(new_rx - now_location.rx);
					int dist_b = abs(new_by - now_location.by) + abs(new_bx - now_location.bx);

					if (dist_r > dist_b)
					{
						new_ry -= dy[i];
						new_rx -= dx[i];
					}
					else
					{
						new_by -= dy[i];
						new_bx -= dx[i];
					}
				}
			}

			//push
			if (visited[new_ry][new_rx][new_by][new_bx] == 0)
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