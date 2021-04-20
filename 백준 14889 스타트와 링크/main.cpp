#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int N;
int Map[MAX][MAX];
int visited[MAX];
int start_team[MAX];
int link_team[MAX];
int Min = 987654321;

void dfs(int cur, int team_num)
{
	if (team_num == N/2)
	{
		int start_team_num = 0;
		int link_team_num = 0;
		for (int i = 0; i < N; i++)
		{
			if (visited[i] == 1) // 스타트팀
			{
				start_team[start_team_num] = i;
				start_team_num += 1;
			}
			else // 링크팀
			{
				link_team[link_team_num] = i;
				link_team_num += 1;
			}
		}

		int start_sum = 0;
		int link_sum = 0;
		for (int j = 0; j < N/2; j++)
		{
			for (int i = j + 1; i < N/2; i++)
			{
				start_sum += Map[start_team[j]][start_team[i]];
				start_sum += Map[start_team[i]][start_team[j]];

				link_sum += Map[link_team[j]][link_team[i]];
				link_sum += Map[link_team[i]][link_team[j]];
			}
		}

		if (Min > abs(start_sum - link_sum))
		{
			Min = abs(start_sum - link_sum);
		}

		return;
	}

	for (int i = cur; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i + 1, team_num + 1);
			visited[i] = 0;
		}
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
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			readFile >> Map[y][x];
		}
	}

	dfs(0, 0); // 처음엔 아직 아무도 안 뽑음
	cout << Min;

	return 0;
}