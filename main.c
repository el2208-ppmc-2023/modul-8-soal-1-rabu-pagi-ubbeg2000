/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 16

int rows = 4;
int cols = 4;
bool visited[MAX_SIZE][MAX_SIZE];

typedef struct {
    int x;
    int y;
} Point;

bool isValid(Point p, int maze[][cols]) {
    // Check if the point is within the bounds of the maze and has not been visited
    return p.x >= 0 && p.x < rows && p.y >= 0 && p.y < cols && maze[p.x][p.y] == 1 && !visited[p.x][p.y];
}

bool solveMaze(Point start, Point end, int maze[][cols]) {
    // Initialize the visited array to false
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }

    // Create a stack to keep track of the current path
    Point stack[MAX_SIZE * MAX_SIZE];
    Point parents[MAX_SIZE][MAX_SIZE] = {0};
    int top = 0;
    stack[top++] = start;

    // Loop until the stack is empty or the end point is reached
    while (top > 0) {
        Point curr = stack[--top];
        visited[curr.x][curr.y] = true;
        if (curr.x == end.x && curr.y == end.y) {
            // If the end point is reached, print the path
            int solution[MAX_SIZE][MAX_SIZE] = {0};
            Point parent = parents[end.x][end.y];
            while (parent.x != start.x || parent.y != start.y) {
                solution[parent.x][parent.y] = 1;
                parent = parents[parent.x][parent.y];
            }
            solution[start.x][start.y] = 1;

            // Print the solution as a 2D array
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i == end.x && j == end.y) {
                        printf("1 ");
                    } else {
                        printf("%d ", solution[i][j]);
                    }
                }
                printf("\n");
            }
            return true;
        }
        // Check all neighbors of the current point
        Point neighbors[4] = {{curr.x-1, curr.y}, {curr.x+1, curr.y}, {curr.x, curr.y-1}, {curr.x, curr.y+1}};
        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (isValid(neighbor, maze)) {
                stack[top++] = neighbor;
                parents[neighbor.x][neighbor.y] = curr;
            }
        }
    }
    // If the stack is empty and the end point was not reached, the maze is unsolvable
    return false;
}


int main() {
    Point start, end;
    int maze[rows][cols];

    // Read in the maze from the input file
    char nama_file[128];
    printf("nama file: ");
    scanf("%s", nama_file);
    FILE* inputFile = fopen(nama_file, "r");
    if (inputFile == NULL) {
        printf("Error: masukan file tidak dapat dibuka!\n");
        return 1;
    }
    fscanf(inputFile, "%d %d", &start.x, &start.y);
    fscanf(inputFile, "%d %d", &end.x, &end.y);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c;
            fscanf(inputFile, " %c", &c);
            maze[i][j] = c - '0';
        }
    }
    fclose(inputFile);
    
    // Solve the maze and print the result
    if (solveMaze(start, end, maze)) {
        printf("arjuna menemukan cinta!\n");
    } else {
        printf("arjuna tidak menemukan cinta!\n");
    }

    return 0;
}
