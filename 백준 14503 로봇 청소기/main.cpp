#include<bits/stdc++.h>
using namespace std;

#define MAX 50

int N, M, start_y, start_x, start_dir;
int wall_map[MAX][MAX];
int clean_map[MAX][MAX];

int clean_count = 0;

// 북동남서
// dir 0 : 북
// dir 1 : 동
// dir 2 : 남
// dir 3 : 서
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Robot
{
	int y, x, dir, count;
};
Robot robot;
int visited[MAX][MAX];

// 좌회전
void rotate()
{
	robot.dir = (robot.dir + 3) % 4;
}

// 이동 가능한지 체크
bool check()
{
	int new_y = robot.y + dy[robot.dir];
	int new_x = robot.x + dx[robot.dir];

	if (wall_map[new_y][new_x] == 0 && clean_map[new_y][new_x] == 0)
	{
		return true;
	}

	return false;
}

int can_not_move_count = 0;
bool can_not_move()
{
	if (can_not_move_count == 3) // 한바퀴 돌았는데 갈 곳 없음 // 후진
	{
		int new_y = robot.y - dy[robot.dir];
		int new_x = robot.x - dx[robot.dir];

		if (wall_map[new_y][new_x] != 1) // 후진할 곳이 벽이 아닐때 후진
		{
			robot.y = new_y;
			robot.x = new_x;
			can_not_move_count = 0;
			return false;
		}
		else if(wall_map[new_y][new_x] == 1)// 후진할 곳이 벽일때
		{
			return true; // 시스템 종료 시그널
		}


	}

	can_not_move_count += 1;

	return false; // 아직 시스템 종료할 때 아님
}

void move()
{
	while (1)
	{
		if (wall_map[robot.y][robot.x] == 0 && clean_map[robot.y][robot.x] == 0)
		{
			clean_map[robot.y][robot.x] = 1;
		}

		rotate(); // 우선 회전

		if (check()) // 이동이 가능하다면 이동
		{
			robot.y += dy[robot.dir];
			robot.x += dx[robot.dir];
			can_not_move_count = 0; // 이동 불가로 인한 회전 초기화
		}
		else // 이동이 불가능할 때
		{
			if (can_not_move())
			{
				break; // 후진하려는데 벽을 만났을 때
			}
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
	readFile >> N >> M >> robot.y >> robot.x >> robot.dir;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			readFile >> wall_map[y][x];
		}
	}

	move();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (clean_map[y][x] == 1)
			{
				clean_count += 1;
			}
		}
	}

	cout << clean_count;

	return 0;
}