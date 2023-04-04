/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16

int rows = 4;
int cols = 4;
bool visited[MAX_SIZE][MAX_SIZE];

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point start, end;
    int maze[rows][cols];

    // Read in the maze from the input file
    char nama_file[128];
    printf("nama file: ");
    scanf("%s", nama_file);
    
    printf("arjuna menemukan cinta!\n");
    printf("arjuna tidak menemukan cinta!\n");

    return 0;
}
