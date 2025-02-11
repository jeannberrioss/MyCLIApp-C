/* The code here creates a square and then
animates it by adding in 0's for each row.
Then after the next row of 0's is genereated below
it converts the prior row of 0's to 1's */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE_HEIGHT 13 // Height of the square (13 rows)
#define SQUARE_WIDTH 17  // Width of the square (17 columns, wider to the right)

// Function prototypes
void print_final_frame();                    // Prints "Here is the final frame:"
void print_square(char grid[SQUARE_HEIGHT][SQUARE_WIDTH]); // Prints the square
void generate_rows(char grid[SQUARE_HEIGHT][SQUARE_WIDTH]); // Generates and transforms rows

int main() {
    char grid[SQUARE_HEIGHT][SQUARE_WIDTH]; // Square grid

    // Initialize the grid with the square outline
    for (int i = 0; i < SQUARE_HEIGHT; i++) {
        for (int j = 0; j < SQUARE_WIDTH; j++) {
            if ((i == 0 || i == SQUARE_HEIGHT - 1) && (j == 0 || j == SQUARE_WIDTH - 1)) grid[i][j] = '+';
            else if (i == 0 || i == SQUARE_HEIGHT - 1) grid[i][j] = '-';
            else if (j == 0 || j == SQUARE_WIDTH - 1) grid[i][j] = '|';
            else grid[i][j] = ' ';
        }
    }

    // Print the initial statement and square
    print_final_frame();
    printf("\n"); // Fix #2: Add space between statement and square
    print_square(grid);

    // Generate and transform rows
    generate_rows(grid);

    // Wait 2 seconds before exiting
    sleep(2);
    return 0;
}

// Final Frame Function
void print_final_frame() {
    printf("Here is the final frame:\n");
}

// Square Functions
void print_square(char grid[SQUARE_HEIGHT][SQUARE_WIDTH]) {
    for (int i = 0; i < SQUARE_HEIGHT; i++) {
        for (int j = 0; j < SQUARE_WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Row Functions
void generate_rows(char grid[SQUARE_HEIGHT][SQUARE_WIDTH]) {
    int row_positions[5] = {4, 5, 6, 7, 8}; // Fix #1: Consecutive rows (no gaps)
    for (int row = 0; row < 5; row++) {
        sleep(2); // Wait 2 seconds

        // Set current row to 'O's
        grid[row_positions[row]][7] = 'O';
        grid[row_positions[row]][8] = 'O';
        grid[row_positions[row]][9] = 'O';

        // Print updates
        system("clear");
        print_final_frame();
        printf("\n"); // Maintain visual spacing
        print_square(grid);

        if (row > 0) { 
            // Convert previous row to '1's
            grid[row_positions[row - 1]][7] = '1';
            grid[row_positions[row - 1]][8] = '1';
            grid[row_positions[row - 1]][9] = '1';

            // Print updates
            system("clear");
            print_final_frame();
            printf("\n");
            print_square(grid);
        }
    }

    // Convert last row to '1's
    grid[row_positions[4]][7] = '1';
    grid[row_positions[4]][8] = '1';
    grid[row_positions[4]][9] = '1';

    // Final print
    system("clear");
    print_final_frame();
    printf("\n");
    print_square(grid);
}
