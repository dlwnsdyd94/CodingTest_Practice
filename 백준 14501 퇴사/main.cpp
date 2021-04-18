#include<bits/stdc++.h>
using namespace std;

#define MAX 15

int N;
int cons_T[MAX];
int cons_P[MAX];

int Max = 0;

void dfs(int cur, int sum)
{
	if (cur >= N)
	{
		if (Max < sum)
		{
			Max = sum;
		}
		return;
	}
	// 상담하기
	if(cur + cons_T[cur] - 1 < N) dfs(cur + cons_T[cur], sum + cons_P[cur]);

	// 상담 안하기
	dfs(cur + 1, sum);
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
		readFile >> cons_T[i] >> cons_P[i];
	}

	dfs(0, 0);

	cout << Max;

	return 0;
}