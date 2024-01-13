#include <stdbool.h>
#include <stdio.h>

#define N 4
#define M 5

typedef struct {
  int x;
  int y;
} Point;

bool isSafe(int maze[N][M], int x, int y) {
  return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1);
}

void updatePath(Point path[], int *path_size, Point current_path[],
                int current_path_size) {
  *path_size = current_path_size;
  for (int i = 0; i < current_path_size; i++) {
    path[i] = current_path[i];
  }
}

bool solveMaze(int maze[N][M], int x, int y, int fx, int fy, Point path[],
               int *path_size, Point current_path[], int current_path_size) {
  if (x == fx && y == fy) {
    current_path[current_path_size] = (Point){x, y};
    current_path_size++;

    if (*path_size == -1 || current_path_size < *path_size) {
      updatePath(path, path_size, current_path, current_path_size);
    }
    return true;
  }

  // Mark current cell as visited
  maze[x][y] = 0;

  // Try all possible directions
  if (isSafe(maze, x + 1, y)) {
    current_path[current_path_size] = (Point){x, y};
    current_path_size++;
    solveMaze(maze, x + 1, y, fx, fy, path, path_size, current_path,
              current_path_size);
    current_path_size--;
  }

  if (isSafe(maze, x, y + 1)) {
    current_path[current_path_size] = (Point){x, y};
    current_path_size++;
    solveMaze(maze, x, y + 1, fx, fy, path, path_size, current_path,
              current_path_size);
    current_path_size--;
  }

  if (isSafe(maze, x - 1, y)) {
    current_path[current_path_size] = (Point){x, y};
    current_path_size++;
    solveMaze(maze, x - 1, y, fx, fy, path, path_size, current_path,
              current_path_size);
    current_path_size--;
  }

  if (isSafe(maze, x, y - 1)) {
    current_path[current_path_size] = (Point){x, y};
    current_path_size++;
    solveMaze(maze, x, y - 1, fx, fy, path, path_size, current_path,
              current_path_size);
    current_path_size--;
  }

  // Backtrack if path is not found
  maze[x][y] = 1;
  return false;
}

int main() {
  int maze[N][M];
  int fx, fy;

  // Input for the maze
  printf("Enter the maze (1 for open path, 0 for blocked path):\n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &maze[i][j]);
    }
  }

  // Input for the destination coordinates
  printf("Enter the destination coordinates (x y): ");
  scanf("%d %d", &fx, &fy);

  Point path[N * M];
  int path_size = -1;
  Point current_path[N * M];
  int current_path_size = 0;

  solveMaze(maze, 0, 0, fx, fy, path, &path_size, current_path,
            current_path_size);

  if (path_size != -1) {
    printf("Minimum Path Found!\n");
    for (int i = 0; i < path_size; i++) {
      printf("-->(%d, %d)", path[i].x, path[i].y);
    }
  } else {
    printf("No path found\n");
  }
  return 0;
}
