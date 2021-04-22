#include<bits/stdc++.h>
using namespace std;

int N;
int x, y, d, g;

// 우하좌상
// 0 : 우
// 1 : 상
// 2 : 좌
// 3 : 하
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int dir_arr[10000];

int Map[101][101];

void generation(int start_dir, int gen)
{
	dir_arr[0] = start_dir;
	if (gen >= 1)
	{
		int end_cur = 0;
		int i = 0;
		for (int now_gen = 1; now_gen <= gen; now_gen++)
		{
			int now_cur;
			for (now_cur = end_cur; now_cur >= 0; now_cur--)
			{
				dir_arr[++i] = (dir_arr[now_cur] + 1) % 4;
			}
			end_cur = i;
		}
	}
}

void draw_map(int start_y, int start_x, int gen)
{
	Map[start_y][start_x] = 1;

	int now_y = start_y;
	int now_x = start_x;

	int size = pow(2, gen);
	for (int i = 0; i < size; i++)
	{
		now_y += dy[dir_arr[i]];
		now_x += dx[dir_arr[i]];

		Map[now_y][now_x] = 1;

		// 방향 모음 초기화
		dir_arr[i] = 0;
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
	for (int i = 0; i < N; i++)
	{
		readFile >> x >> y >> d >> g;

		generation(d, g); // 세대에 따른 방향 길 구하기
		
		draw_map(y, x, g); // 지도에 그리기
	}

	// 맵에 정사각형 얼마나 있는 지 구하기
	int sqr_count = 0;
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
		{
			if (Map[y][x] == 1 && Map[y][x + 1] == 1 && Map[y + 1][x] == 1 && Map[y + 1][x + 1] == 1)
			{
				sqr_count += 1;
			}
		}
	}

	cout << sqr_count;

	return 0;
}