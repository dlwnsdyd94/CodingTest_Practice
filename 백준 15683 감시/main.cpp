#include<bits/stdc++.h>
using namespace std;

int N, M;
int Map[8][8];

int cctv[5][4]
= { // 우 하 좌 상
	{1, 0, 0, 0},
	{1, 0, 1, 0},
	{1, 0, 0, 1},
	{1, 0, 1, 1},
	{1, 1, 1, 1}
};

void rotate(int* one_cctv) // 시계방향 회전
{
	int temp = one_cctv[3];
	one_cctv[3] = one_cctv[2];
	one_cctv[2] = one_cctv[1];
	one_cctv[1] = one_cctv[0];
	one_cctv[0] = temp;
}

struct CCTV
{
	int y, x, num;
	int one_cctv[4];
};

vector<CCTV> cctv_location;

int visited[8][8];

int Min_non_cctv = 987654321;

int check_non_cctv() // cctv 검사 안됨 영역 개수 구하기
{
	int check_cctv_count = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (visited[y][x] == 1)
			{
				check_cctv_count += 1;
			}
		}
	}

	return N * M - check_cctv_count;
}

//int test_count = 0; // 케이스 점검용
void go_cctv()
{
	// 우하좌상
	int dy[4] = {0, 1, 0, -1};
	int dx[4] = {1, 0, -1, 0};

	for (CCTV now_cctv : cctv_location)
	{
		int now_y = now_cctv.y;
		int now_x = now_cctv.x;
		int* now_one_cctv = now_cctv.one_cctv;
		visited[now_y][now_x] = 1;

		// 한 개의 현재 방향 cctv 검사 (rotate 안함)
		for (int dir = 0; dir < 4; dir++)
		{
			if (now_one_cctv[dir])
			{
				int new_y = now_y;
				int new_x = now_x;
				while (1)
				{
					new_y += dy[dir];
					new_x += dx[dir];

					if (new_x >= M || new_x < 0 || new_y >= N || new_y < 0 || Map[new_y][new_x] == 6)
					{
						break;
					}

					visited[new_y][new_x] = 1;
				}
			}
		}
	}

	int non_cctv = check_non_cctv();
	if (Min_non_cctv > non_cctv)
	{
		Min_non_cctv = non_cctv;
	}

	//test_count += 1;
	//cout << test_count << '\n';
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			//cout << visited[y][x] << ' ';
			visited[y][x] = 0;
			if (Map[y][x] == 6)
			{
				visited[y][x] = 1;
			}
		}
		//cout << '\n';
	}
	//cout << Min_non_cctv << '\n';
	//cout << '\n';
}

void dfs(int cctv_num)
{
	int cctv_location_size = cctv_location.size();
	if (cctv_num == cctv_location_size)
	{
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		go_cctv();
		rotate(cctv_location[cctv_num].one_cctv);
		dfs(cctv_num + 1);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int wall_count = 0;
	bool no_cctv = true;

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			readFile >> Map[y][x];
			if (Map[y][x] >= 1 && Map[y][x] <= 5)
			{
				cctv_location.push_back({y, x, Map[y][x] - 1, cctv[Map[y][x] - 1][0], cctv[Map[y][x] - 1][1] , cctv[Map[y][x] - 1][2] , cctv[Map[y][x] - 1][3] });
				no_cctv = false;
			}
			if (Map[y][x] == 6)
			{
				visited[y][x] = 1;
				wall_count += 1;
			}
		}
	}

	dfs(0);
	if (no_cctv)
	{
		cout << N*M - wall_count;
	}
	else 
	{
		cout << Min_non_cctv;
	}

	return 0;
}