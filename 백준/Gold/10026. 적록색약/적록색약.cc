#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N;
char picture[101][101];
bool visited[101][101];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int result = 0;

void bfs1() {
    while (!q1.empty()) {
        int x = q1.front().first;
        int y = q1.front().second;

        q1.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N || visited[new_x][new_y]) continue;
            if (picture[x][y] == 'R' || picture[x][y] == 'G') {
                if (!(picture[new_x][new_y] == 'R' || picture[new_x][new_y] == 'G')) continue;
            }
            if (picture[x][y] == 'B') {
                if (picture[new_x][new_y] != 'B') continue;
            }

            q1.push({ new_x, new_y });
            visited[new_x][new_y] = 1;
        }
    }
}

void bfs2() {
    while (!q2.empty()) {
        int x = q2.front().first;
        int y = q2.front().second;

        q2.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N || visited[new_x][new_y] || picture[x][y] != picture[new_x][new_y]) continue;

            q2.push({ new_x, new_y });
            visited[new_x][new_y] = 1;
        }
    }
}

int main() {
    cin >> N;

    // 그림 입력
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;

        for (int j = 0; j < N; j++) {
            picture[i][j] = S[j];
        }
    }

    // 적록색약 아닐 때 BFS
    fill(&visited[0][0], &visited[100][100], 0);
    result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            q2.push({ i, j });
            visited[i][j] = 1;
            bfs2();
            result++;
        }
    }
    cout << result << " ";

    // 적록색약일 때 BFS
    fill(&visited[0][0], &visited[100][100], 0);
    result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            q1.push({ i, j });
            visited[i][j] = 1;
            bfs1();
            result++;
        }
    }
    cout << result;

    return 0;
}
