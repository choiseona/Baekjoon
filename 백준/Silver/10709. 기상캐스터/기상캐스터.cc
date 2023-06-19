#include <iostream>
#include <cstring>
using namespace std;

int cloud[101][101];
int main() {
    int H, W;
    cin >> H >> W;

    memset(cloud, -1, sizeof(cloud));

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for (int j = W - 1; j >= 0; j--) {
            if (s[j] == 'c') //현재 구름 있으면 0
                cloud[i][j] = 0;
      
            else { //현재 구름 없으면 몇 분 후 구름 있는지
                int cnt = 0;
                for (int k = j - 1; k >= 0; k--) { //뒤에서부터 탐색
                    cnt++;
                    if (s[k] == 'c') {
                        cloud[i][j] = cnt;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << cloud[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}