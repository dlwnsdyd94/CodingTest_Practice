#include<bits/stdc++.h>
using namespace std;

#define MAX 101

int N, K;
int appleMap[MAX][MAX]; // 사과의 위치를 포함하고 있는 지도
int L;

//상우하좌 방향 : 시계방향
// 우 dir : 0
// 하 dir : 1
// 좌 dir : 2
// 상 dir : 3
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct Snake
{
	queue<pair<int, int>> q;
	int Map[MAX][MAX];
	int y, x; // 머리 위치
	int dy, dx, dir; // 머리 방향
	int time; // 뱀의 "현재" 시간
};
Snake snake;

char cmd[10101];

int myMove()
{
	while (1)
	{
		// 현재 방향대로 다음칸 이동
		snake.time += 1;
		snake.y += snake.dy;
		snake.x += snake.dx;

		if (snake.y >= N || snake.y < 0 || snake.x >= N || snake.x < 0 || snake.Map[snake.y][snake.x] == 1) 
		{
			break;
		}

		snake.Map[snake.y][snake.x] = 1;
		snake.q.push({ snake.y, snake.x });

		// 사과
		if (appleMap[snake.y][snake.x] == 0)
		{
			snake.Map[snake.q.front().first][snake.q.front().second] = 0;
			snake.q.pop();
		}
		else
		{
			appleMap[snake.y][snake.x] = 0;
		}

		// 다음 방향 설정
		if (cmd[snake.time] == 'D')
		{
			snake.dir = (snake.dir + 1) % 4;
		}
		else if (cmd[snake.time] == 'L')
		{
			snake.dir = (snake.dir + 3) % 4;
		}

		snake.dy = dy[snake.dir];
		snake.dx = dx[snake.dir];
	}

	return snake.time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int y, x;
		readFile >> y >> x;
		appleMap[y - 1][x - 1] = 1;
	}

	readFile >> L;
	for (int i = 0; i < L; i++)
	{
		int sec;
		char dir;
		readFile >> sec >> dir;
		cmd[sec] = dir;
	}

	// start 정보
	snake.q.push({0, 0});
	snake.Map[0][0] = 1;
	snake.y = 0;
	snake.x = 0;
	snake.dir = 0; // 오른쪽을 나타냄
	snake.dy = dy[0]; // 오른쪽 방향
	snake.dx = dx[0]; // 오른쪽 방향
	snake.time = 0;

	cout << myMove();

	return 0;

}