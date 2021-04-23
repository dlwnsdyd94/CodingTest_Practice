#include<bits/stdc++.h>
using namespace std;

int N, M;
int Map[51][51];

struct Location
{
	int y, x;
};

Location chiken_pos[13];
int chiken_visited[13];
int chiken_count = 0;

Location house_pos[102];
int house_count = 0;


int sum_dis = 0;
void city_chiken_dis()
{
	for (int i = 0; i < house_count; i++)
	{
		int now_y = house_pos[i].y;
		int now_x = house_pos[i].x;

		//cout << "i : " << i << '\n';
		//cout << "now_y : " << now_y << '\n';
		//cout << "now_x : " << now_x << "\n\n";

		int min_one_dis = 987654321;
		for (int j = 0; j < chiken_count; j++)
		{
			//cout << "j : " << j << '\n';
			//cout << "chiken_pos[j].y : " << chiken_pos[j].y << '\n';
			//cout << "chiken_pos[j].x : " << chiken_pos[j].x << "\n\n";

			int one_dis = 0;
			if (chiken_visited[j] == 1)
			{
				one_dis += abs(chiken_pos[j].y - now_y);
				one_dis += abs(chiken_pos[j].x - now_x);
			}
			else
			{
				one_dis = 987654321;
			}

			//cout << "j : " << j << '\n';
			//cout << "one_dis : " << one_dis << "\n";

			if (min_one_dis > one_dis)
			{
				min_one_dis = one_dis;
			}
			//cout <<"min_one_dis : "<< min_one_dis << "\n\n";
		}
		sum_dis += min_one_dis;
	}
}

int min_sum_dis = 987654321;
void dfs(int cur, int count)
{
	if (count == M)
	{
		city_chiken_dis();

		if (min_sum_dis > sum_dis)
		{
			min_sum_dis = sum_dis;
		}
		sum_dis = 0;

		return;
	}

	for (int i = cur; i < chiken_count; i++)
	{
		if (chiken_visited[i] == 0)
		{
			chiken_visited[i] = 1;
			dfs(i + 1, count + 1);
			chiken_visited[i] = 0;
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
	readFile >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			readFile >> Map[y][x];
			if (Map[y][x] == 1)
			{
				house_pos[house_count].y = y;
				house_pos[house_count].x = x;
				house_count += 1;
			}
			else if (Map[y][x] == 2)
			{
				chiken_pos[chiken_count].y = y;
				chiken_pos[chiken_count].x = x;
				chiken_count += 1;
			}

			//cout << Map[y][x] << ' ';

		}
		//cout << '\n';
	}
	//cout << '\n';

	dfs(0, 0);
	cout << min_sum_dis;

	return 0;
}