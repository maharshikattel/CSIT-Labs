#include <stdio.h>
#include <math.h>
#define MAX_SIZE 10 // Maximum size of the grid
#define MAX_ITER 1000 // Maximum number of iterations
#define EPSILON 1e-5 // Convergence criterion
// Function to solve the Laplace equation using the finite difference method
void solveLaplace(int size_x, int size_y) {
if (size_x <= 2 || size_y <= 2 || size_x > MAX_SIZE || size_y > MAX_SIZE) {

printf("Invalid grid size. Please provide valid dimensions.\n");
return;
}
double grid[MAX_SIZE][MAX_SIZE];
double max_diff;
int iter = 0;
// Initialize the grid with user-provided values
printf("Enter the values for the grid points:\n");
for (int i = 0; i < size_x; i++) {
for (int j = 0; j < size_y; j++) {
printf("Enter the value for grid point (%d, %d): ", i, j);
scanf("%lf", &grid[i][j]);
}
}
// Perform iterations until convergence or maximum number of iterations reached
do {
max_diff = 0.0;
// Update the interior points
for (int i = 1; i < size_x - 1; i++) {
for (int j = 1; j < size_y - 1; j++) {
double diff = grid[i][j];
grid[i][j] = 0.25 * (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1]);
diff = fabs(diff - grid[i][j]);
if (diff > max_diff) {
max_diff = diff;
}
}
}
iter++;
} while (max_diff > EPSILON && iter < MAX_ITER);
// Print the final solution
printf("Iterations: %d\n", iter);
printf("Final solution:\n");
for (int i = 0; i < size_x; i++) {
for (int j = 0; j < size_y; j++) {
printf("%0.2f ", grid[i][j]);
}
printf("\n");

}
}
int main() {
int size_x, size_y;
printf("Enter the number of grid points along the x-axis (max %d): ", MAX_SIZE);
scanf("%d", &size_x);
printf("Enter the number of grid points along the y-axis (max %d): ", MAX_SIZE);
scanf("%d", &size_y);
solveLaplace(size_x, size_y);
return 0;
}
