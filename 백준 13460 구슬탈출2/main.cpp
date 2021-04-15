#include<bits/stdc++.h>
using namespace std;

int N, M;
char myMap[10][10];
struct Point{ // R과 B의 현재 좌표에 쓰이는 구조체
	int x;
	int y;
};
int dx[4] = {0, 0, -1, 1}; // 상하좌우
int dy[4] = {-1, 1, 0, 0}; // 상하좌우
bool R_check[10][10];
bool B_check[10][10];

int ans; // 정답

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 파일 입력
	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N >> M;
	
	// map 만들기
	// R과 B의 좌표 저장
	Point R_point, B_point;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			readFile >> myMap[y][x];
			if (myMap[y][x] == 'R')
			{
				// R의 좌표 저장
				R_point.y = y;
				R_point.x = x;
				R_check[y][x] = true;
			}
			else if (myMap[y][x] == 'B')
			{
				// B의 좌표 저장
				B_point.y = y;
				B_point.x = x;
				B_check[y][x] = true;
			}
		}

	// R의 입장에서 상하좌우 네 방향으로 '#'이나 'O', 'B'가 있을때까지 쭉 이동
	for (int i = 0; i < 4; i++)
	{
		int R_new_x = R_point.x + dx[i];
		int R_new_y = R_point.y + dy[i];

		// 새로운 위치가 둘러싸여있는 벽 안에 위치하는지 체크
		if (R_new_x <= 0 || R_new_x >= M - 1 || R_new_y <= 0 || R_new_y >= N - 1 || R_check[R_new_y][R_new_x] == true) // 이미 지나온 위치는 다시 안간다.
			continue;

		ans++; // 방향 + 1
		if (ans > 10)
		{
			cout << -1;
			return 0;
		}

		while (myMap[R_new_y][R_new_x] != '#' && myMap[R_new_y][R_new_x] != 'B')
		{
			if (myMap[R_new_y][R_new_x] == 'O')
			{
				// 종료
				cout << ans;
				return 0;
			}
			else if (myMap[R_new_y][R_new_x] == '#' || myMap[R_new_y][R_new_x] == 'B')
			{
				continue;
			}

			// R의 현재위치 갱신
			R_point.x = R_new_x;
			R_point.y = R_new_y;
			R_check[R_new_y][R_new_x] = true;

			// R의 다음 위치
			R_new_x = R_point.x + dx[i];
			R_new_y = R_point.y + dy[i];
		}

		int B_new_x = B_point.x + dx[i];
		int B_new_y = B_point.y + dy[i];

		// 새로운 위치가 둘러싸여있는 벽 안에 위치하는지 체크
		if (B_new_x <= 0 || B_new_x >= M - 1 || B_new_y <= 0 || B_new_y >= N - 1) // 이미 지나갔던 위치에 또 가도 상관 없음
			continue;

		while (myMap[B_new_y][B_new_x] != '#' && myMap[B_new_y][B_new_x] != 'B')
		{
			if (myMap[B_new_y][B_new_x] == 'O')
			{
				// 종료
				cout << ans;
				return 0;
			}
			else if (myMap[B_new_y][B_new_x] == '#' || myMap[B_new_y][B_new_x] == 'B')
			{
				continue;
			}

			// R의 현재위치 갱신
			R_point.x = B_new_x;
			R_point.y = B_new_y;
			R_check[B_new_y][B_new_x] = true;

			// R의 다음 위치
			B_new_x = R_point.x + dx[i];
			B_new_y = R_point.y + dy[i];
		}

		i = 0; // 방향 초기화
	}

	return 0;
}

