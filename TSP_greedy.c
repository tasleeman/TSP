#include <stdio.h>

int n; // Declare 'n' as a global variable

int input[10][10];
int visited[10] = {0};
int cost = 0;

int findClosestNode(int currentNode) {
    int minDistance = 999;
    int nearestNode = -1;

    for (int k = 0; k < n; k++) {
        if (input[currentNode][k] != 0 && !visited[k] && input[currentNode][k] < minDistance) {
            minDistance = input[currentNode][k];
            nearestNode = k;
        }
    }

    return nearestNode;
}

void travellingsalesman(int startNode) {
    int currentNode = startNode - 1;
    printf("Shortest Path: ");

    for (int i = 0; i < n; i++) {
        visited[currentNode] = 1;
        printf("%d ", currentNode + 1);
        int nearestNode = findClosestNode(currentNode);
        if (nearestNode == -1) {
            break;
        }

        cost += input[currentNode][nearestNode];
        currentNode = nearestNode;
    }
    cost += input[currentNode][startNode - 1]; // Return to the starting node
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int startNode;

    while (1) {
        printf("Enter the start node (1 to %d): ", n);
        scanf("%d", &startNode);

        if (startNode >= 1 && startNode <= n) {
            break;
        } else {
            printf("Invalid start node. Please enter a valid start node.\n");
        }
    }

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Shortest Path: ");
    travellingsalesman(startNode);
    printf("%d", startNode);
    printf("\nMinimum Cost: %d\n", cost);

    return 0;
}
