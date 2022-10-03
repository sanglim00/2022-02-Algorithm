#include <iostream>
using namespace std;

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

struct Point {
    int x;
    int y;
};

Point direction[8] = {
    {1, -2}, {2, -1}, {1, 2}, {-2, -1}, 
    {-1, 2}, {-2, 1}, {-1, -2}, {2, 1}
};

int** board; 
int** path;

int Tour(int m, int n, Point pos, int counter) {
    Point next;

    if(counter == m * n) return 1;

    for(int i = 0; i< 8; i++) {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if(next.x >= 0 && next.x < n && next.y >= 0 && next.y < m && board[next.y][next.x] != MARK) {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;

            if(Tour(m, n, next, counter+1)) return 1;

            board[next.y][next.x] = UNMARK;
        }
    }

    return 0;
}

int main() {

    int times;
    int m, n, s, t;

    cin >> times;
    for(int i = 0; i< times; i++) {
        Point start;
        cin >> m >> n >> s >> t;

        board = new int*[m];  
        path = new int*[m];

        for(int j = 0; j < m; j++) {
            board[j] = new int[n];
            path[j] = new int[n];
        }
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                board[j][k] = UNMARK;
            }
        }
        board[s-1][t-1] = MARK;
        path[s-1][t-1] = 1;
        start.x = s-1;
        start.y = t-1;

        int answer = Tour(m, n, start, 1);
        cout<< answer<< endl;
        cout<< start.x << ' '<<start.y <<endl;
        
        // if( answer) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n; k++) {
                    cout<< path[j][k]<< ' ';
                }
                cout<<endl;
            }
        // }
    }

    return 0;
}