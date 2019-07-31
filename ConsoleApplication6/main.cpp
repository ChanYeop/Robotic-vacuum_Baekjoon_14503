#include <iostream>
#include <queue>
using namespace std;

struct info {
	int r, c, d;
};

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N;
int M;

int Turn_Direction(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else if (d == 3) return 2;
}
bool outer(int a, int  b) {
	return a < 0 || a >= N || b < 0 || b >= M;
}

queue<info> q;
int arr[51][51];

void robot() {
	int nx, ny, nd;
	int cnt = 0;
	cnt++;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		arr[r][c] = 2;
		q.pop();
		bool Clean = false;
		int direct = 0;
		int Temp_d = d;
		for (int i = 0; i < 4; i++) {
			nd = Turn_Direction(d);
			nx = r + dx[nd];
			ny = c + dy[nd];
			if (arr[nx][ny] == 0) {
				Clean = true;
				break;
			}
			else if (arr[nx][ny] == 1 || arr[nx][ny] == 2 || outer(nx, ny)) {
				d = nd;
				direct++;
			}
		}
		if (Clean == true) {
			q.push({ nx,ny,nd });
			cnt++;
		}
		if (direct == 4) {
			nx = r - dx[Temp_d];
			ny = c - dy[Temp_d];
			d = Temp_d;
			q.push({ nx,ny,d });
			if (outer(nx, ny) || arr[nx][ny] == 1)
				break;
		}
	}
	cout << cnt << endl;
}

int main() {
	cin >> N >> M;
	int r, c, d;
	cin >>r >> c >> d;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	q.push({ r,c,d });
	robot();
	return 0;

}