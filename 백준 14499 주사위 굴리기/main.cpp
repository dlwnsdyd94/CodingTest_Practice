#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int N, M, y, x, K; // x, y�� ���� �ֻ��� ��ġ
int Map[MAX][MAX];
int cmd[1000];

int dice[6];

// �����ϳ�
// �� : 0
// �� : 1
// �� : 2
// �� : 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> M >> y >> x >> K;

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
		{
			readFile >> Map[j][i];
		}
	}

	for (int i = 0; i < K; i++)
	{
		readFile >> cmd[i];
	}

	for (int i = 0; i < K; i++)
	{
		y += dy[cmd[i] - 1];
		x += dx[cmd[i] - 1];

		if (y >= N || y < 0 || x >= M || x < 0)
		{
			y -= dy[cmd[i] - 1];
			x -= dx[cmd[i] - 1];
			continue;
		}

		if (cmd[i] == 1) // ��
		{
			int a, b, c, d;
			a = dice[1];
			b = dice[3];
			c = dice[4];
			d = dice[5];

			dice[1] = c;
			dice[3] = d;
			dice[4] = b;
			dice[5] = a;
		}
		else if (cmd[i] == 2) //��
		{
			int a, b, c, d;
			a = dice[1];
			b = dice[3];
			c = dice[4];
			d = dice[5];

			dice[1] = d;
			dice[3] = c;
			dice[4] = a;
			dice[5] = b;

		}
		else if (cmd[i] == 3) // ��
		{
			int a, b, c, d;
			a = dice[0];
			b = dice[1];
			c = dice[2];
			d = dice[3];

			dice[0] = b;
			dice[1] = c;
			dice[2] = d;
			dice[3] = a;

		}
		else if (cmd[i] == 4) // ��
		{
			int a, b, c, d;
			a = dice[0];
			b = dice[1];
			c = dice[2];
			d = dice[3];

			dice[0] = d;
			dice[1] = a;
			dice[2] = b;
			dice[3] = c;
		}

		if (Map[y][x] != 0)
		{
			dice[3] = Map[y][x];
			Map[y][x] = 0;
		}
		else
		{
			Map[y][x] = dice[3];
		}

		cout << dice[1] << '\n';

	}

	return 0;
}