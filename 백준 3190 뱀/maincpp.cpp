#include<bits/stdc++.h>
using namespace std;

#define MAX 101

int N, K;
int appleMap[MAX][MAX]; // ����� ��ġ�� �����ϰ� �ִ� ����
int L;

//������� ���� : �ð����
// �� dir : 0
// �� dir : 1
// �� dir : 2
// �� dir : 3
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct Snake
{
	queue<pair<int, int>> q;
	int Map[MAX][MAX];
	int y, x; // �Ӹ� ��ġ
	int dy, dx, dir; // �Ӹ� ����
	int time; // ���� "����" �ð�
};
Snake snake;

char cmd[10101];

int myMove()
{
	while (1)
	{
		// ���� ������ ����ĭ �̵�
		snake.time += 1;
		snake.y += snake.dy;
		snake.x += snake.dx;

		if (snake.y >= N || snake.y < 0 || snake.x >= N || snake.x < 0 || snake.Map[snake.y][snake.x] == 1) 
		{
			break;
		}

		snake.Map[snake.y][snake.x] = 1;
		snake.q.push({ snake.y, snake.x });

		// ���
		if (appleMap[snake.y][snake.x] == 0)
		{
			snake.Map[snake.q.front().first][snake.q.front().second] = 0;
			snake.q.pop();
		}
		else
		{
			appleMap[snake.y][snake.x] = 0;
		}

		// ���� ���� ����
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

	// start ����
	snake.q.push({0, 0});
	snake.Map[0][0] = 1;
	snake.y = 0;
	snake.x = 0;
	snake.dir = 0; // �������� ��Ÿ��
	snake.dy = dy[0]; // ������ ����
	snake.dx = dx[0]; // ������ ����
	snake.time = 0;

	cout << myMove();

	return 0;
}