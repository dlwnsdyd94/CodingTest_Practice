#include<bits/stdc++.h>
using namespace std;

int N, M;
char myMap[10][10];
struct Point{ // R�� B�� ���� ��ǥ�� ���̴� ����ü
	int x;
	int y;
};
int dx[4] = {0, 0, -1, 1}; // �����¿�
int dy[4] = {-1, 1, 0, 0}; // �����¿�
bool R_check[10][10];
bool B_check[10][10];

int ans; // ����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���� �Է�
	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> M;
	
	// map �����
	// R�� B�� ��ǥ ����
	Point R_point, B_point;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			readFile >> myMap[y][x];
			if (myMap[y][x] == 'R')
			{
				// R�� ��ǥ ����
				R_point.y = y;
				R_point.x = x;
				R_check[y][x] = true;
			}
			else if (myMap[y][x] == 'B')
			{
				// B�� ��ǥ ����
				B_point.y = y;
				B_point.x = x;
				B_check[y][x] = true;
			}
		}

	// R�� ���忡�� �����¿� �� �������� '#'�̳� 'O', 'B'�� ���������� �� �̵�
	for (int i = 0; i < 4; i++)
	{
		int R_new_x = R_point.x + dx[i];
		int R_new_y = R_point.y + dy[i];

		// ���ο� ��ġ�� �ѷ��ο��ִ� �� �ȿ� ��ġ�ϴ��� üũ
		if (R_new_x <= 0 || R_new_x >= M - 1 || R_new_y <= 0 || R_new_y >= N - 1 || R_check[R_new_y][R_new_x] == true) // �̹� ������ ��ġ�� �ٽ� �Ȱ���.
			continue;

		ans++; // ���� + 1
		if (ans > 10)
		{
			cout << -1;
			return 0;
		}

		while (myMap[R_new_y][R_new_x] != '#' && myMap[R_new_y][R_new_x] != 'B')
		{
			if (myMap[R_new_y][R_new_x] == 'O')
			{
				// ����
				cout << ans;
				return 0;
			}
			else if (myMap[R_new_y][R_new_x] == '#' || myMap[R_new_y][R_new_x] == 'B')
			{
				continue;
			}

			// R�� ������ġ ����
			R_point.x = R_new_x;
			R_point.y = R_new_y;
			R_check[R_new_y][R_new_x] = true;

			// R�� ���� ��ġ
			R_new_x = R_point.x + dx[i];
			R_new_y = R_point.y + dy[i];
		}

		int B_new_x = B_point.x + dx[i];
		int B_new_y = B_point.y + dy[i];

		// ���ο� ��ġ�� �ѷ��ο��ִ� �� �ȿ� ��ġ�ϴ��� üũ
		if (B_new_x <= 0 || B_new_x >= M - 1 || B_new_y <= 0 || B_new_y >= N - 1) // �̹� �������� ��ġ�� �� ���� ��� ����
			continue;

		while (myMap[B_new_y][B_new_x] != '#' && myMap[B_new_y][B_new_x] != 'B')
		{
			if (myMap[B_new_y][B_new_x] == 'O')
			{
				// ����
				cout << ans;
				return 0;
			}
			else if (myMap[B_new_y][B_new_x] == '#' || myMap[B_new_y][B_new_x] == 'B')
			{
				continue;
			}

			// R�� ������ġ ����
			R_point.x = B_new_x;
			R_point.y = B_new_y;
			R_check[B_new_y][B_new_x] = true;

			// R�� ���� ��ġ
			B_new_x = R_point.x + dx[i];
			B_new_y = R_point.y + dy[i];
		}

		i = 0; // ���� �ʱ�ȭ
	}

	return 0;
}

