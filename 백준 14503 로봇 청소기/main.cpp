#include<bits/stdc++.h>
using namespace std;

#define MAX 50

int N, M, start_y, start_x, start_dir;
int wall_map[MAX][MAX];
int clean_map[MAX][MAX];

int clean_count = 0;

// �ϵ�����
// dir 0 : ��
// dir 1 : ��
// dir 2 : ��
// dir 3 : ��
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Robot
{
	int y, x, dir, count;
};
Robot robot;
int visited[MAX][MAX];

// ��ȸ��
void rotate()
{
	robot.dir = (robot.dir + 3) % 4;
}

// �̵� �������� üũ
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
	if (can_not_move_count == 3) // �ѹ��� ���Ҵµ� �� �� ���� // ����
	{
		int new_y = robot.y - dy[robot.dir];
		int new_x = robot.x - dx[robot.dir];

		if (wall_map[new_y][new_x] != 1) // ������ ���� ���� �ƴҶ� ����
		{
			robot.y = new_y;
			robot.x = new_x;
			can_not_move_count = 0;
			return false;
		}
		else if(wall_map[new_y][new_x] == 1)// ������ ���� ���϶�
		{
			return true; // �ý��� ���� �ñ׳�
		}


	}

	can_not_move_count += 1;

	return false; // ���� �ý��� ������ �� �ƴ�
}

void move()
{
	while (1)
	{
		if (wall_map[robot.y][robot.x] == 0 && clean_map[robot.y][robot.x] == 0)
		{
			clean_map[robot.y][robot.x] = 1;
		}

		rotate(); // �켱 ȸ��

		if (check()) // �̵��� �����ϴٸ� �̵�
		{
			robot.y += dy[robot.dir];
			robot.x += dx[robot.dir];
			can_not_move_count = 0; // �̵� �Ұ��� ���� ȸ�� �ʱ�ȭ
		}
		else // �̵��� �Ұ����� ��
		{
			if (can_not_move())
			{
				break; // �����Ϸ��µ� ���� ������ ��
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