#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int N;
int ans;

struct Board
{
	int myMap[MAX][MAX];

	void rotate()
	{
		int temp[MAX][MAX];
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				temp[y][x] = myMap[N - x - 1][y];
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				myMap[y][x] = temp[y][x];
			}
		}
	}

	int get_max()
	{
		int myMax = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (myMax < myMap[y][x])
				{
					myMax = myMap[y][x];
				}
			}
		}
		return myMax;
	}

	void up()
	{
		int temp[MAX][MAX];
		for (int x = 0; x < N; x++)
		{
			int flag = 0;
			int target = -1;
			for (int y = 0; y < N; y++)
			{
				if (myMap[y][x] == 0) continue;
				if (flag == 1 && myMap[y][x] == temp[target][x])
				{
					temp[target][x] *= 2;
					flag = 0;
				}
				else
				{
					temp[++target][x] = myMap[y][x];
					flag = 1;
				}
			}

			for (++target; target < N; ++target)
			{
				temp[target][x] = 0;
			}
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				myMap[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(Board cur, int count)
{
	if (count == 5)
	{
		int myMax = cur.get_max();
		if (ans < myMax)
		{
			ans = myMax;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++)
	{
		Board next = cur;
		next.up();
		dfs(next, count + 1);
		cur.rotate();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N;

	Board start;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			readFile >> start.myMap[y][x];
		}
	}

	ans = 0;
	dfs(start, 0);
	cout << ans;

	return 0;
}