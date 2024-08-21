#include <stdio.h>
#include <stdlib.h>

// Define the structure for a job
typedef struct
{
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
} Job;

// Function to compare two jobs based on their profit
int compare(const void *a, const void *b)
{
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit; // Sort in descending order of profit
}

// Function to find the maximum profit from job scheduling
void jobSequencing(Job jobs[], int n)
{
    // Sort jobs based on profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Array to keep track of free time slots
    int slot[n];
    for (int i = 0; i < n; i++)
    {
        slot[i] = -1; // Initialize slots as free
    }

    int totalProfit = 0;
    int jobCount = 0;

    // Iterate through all jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;                   // Assign job to this slot
                totalProfit += jobs[i].profit; // Add profit
                jobCount++;
                break;
            }
        }
    }

    // Print the result
    printf("Job sequence to maximize profit:\n");
    for (int i = 0; i < n; i++)
    {
        if (slot[i] != -1)
        {
            printf("Job ID: %d, Deadline: %d, Profit: %d\n",
                   jobs[slot[i]].id, jobs[slot[i]].deadline, jobs[slot[i]].profit);
        }
    }
    printf("Total number of jobs scheduled: %d\n", jobCount);
    printf("Total profit: %d\n", totalProfit);
}

int main()
{
    // Number of jobs
    int n = 4;

    // Define jobs with their ID, deadline, and profit
    Job jobs[] = {
        {1, 2, 60},
        {2, 1, 100},
        {3, 3, 20},
        {4, 2, 40},
        {5, 1, 20}};

    // Call the jobSequencing function
    jobSequencing(jobs, n);

    return 0;
}
