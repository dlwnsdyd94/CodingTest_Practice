#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int N, K;
int ans;
int myMap[MAX][MAX]; // ����� ��ġ�� �����ϰ� �ִ� ����

int L;
struct Direction
{
	int second;
	char dir;
};
vector<Direction> v;

//�����¿� ����
// �� dir : 0
// �� dir : 1
// �� dir : 2
// �� dir : 3
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Snake
{
	int y, x, dy, dx, count;
};
int visited[MAX][MAX];

void myMove(Snake start)
{
	queue<Snake> q;
	q.push(start);
	visited[start.y][start.x] = 1;

	while (1)
	{
		Snake now_cur = q.front();

		int next_y = now_cur.y + now_cur.dy;
		int next_x = now_cur.x + now_cur.dx;

		if (next_y >= N || next_y < 0 || next_x >= N || next_x < 0)
		{
			ans = now_cur.count + 1;
			break;
		}
		if (visited[next_y][next_x] == 1)
		{
			ans = now_cur.count + 1;
			break;
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
	readFile >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int y, x;
		readFile >> y >> x;
		myMap[y - 1][x - 1] = 1;
	}

	readFile >> L;
	for (int i = 0; i < L; i++)
	{
		int sec;
		char dir;
		readFile >> sec >> dir;
		v.push_back({sec, dir});
	}

	Snake start;
	start.y = 0;
	start.x = 0;
	start.dy = dy[3];
	start.dx = dx[3];
	start.count = 0;

	myMove(start);
	cout << ans;

	return 0;
}