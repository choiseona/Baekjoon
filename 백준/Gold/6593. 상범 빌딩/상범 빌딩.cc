#include <iostream>
#include <queue>
using namespace std;

char building[31][31][31];
bool visited[31][31][31];
int dist[31][31][31];
int L, R, C;
pair<int, pair<int, int>> success;
queue<pair<int, pair<int, int>>> q;
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dh[] = { 0, 0, 0, 0, -1, 1 };

void bfs() {
    while (!q.empty()) {
        int h = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        for (int i = 0; i < 6; i++) {
            int new_h = h + dh[i];
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_h < 0 || new_x < 0 || new_y < 0 || new_h > L - 1 || new_x > R - 1 || new_y > C - 1 
                || building[new_h][new_x][new_y] == '#' || visited[new_h][new_x][new_y]) continue;

            dist[new_h][new_x][new_y] = dist[h][x][y] + 1;
            q.push({ new_h,{new_x,new_y} });
            visited[new_h][new_x][new_y] = 1;
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        fill(&visited[0][0][0], &visited[30][30][30], 0);
        fill(&dist[0][0][0], &dist[30][30][30], 0);

        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) return 0;

        // 빌딩 입력
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string S;
                cin >> S;
                for (int k = 0; k < C; k++) {
                    building[i][j][k] = S[k];
                    if (building[i][j][k] == 'S') {
                        q.push({ i, {j, k} });
                        visited[i][j][k] = 1;
                    }
                    else if (building[i][j][k] == 'E') success = { i, {j, k} };
                }
            }
        }

        // 탈출
        bfs();

        // 출력
        if (!visited[success.first][success.second.first][success.second.second]) {
            cout << "Trapped!";
        }
        else {
            cout << "Escaped in " << dist[success.first][success.second.first][success.second.second] << " minute(s).";
        }
        cout << "\n";
    }
}
