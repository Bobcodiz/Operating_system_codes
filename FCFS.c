#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[]) {
  wt[0] = 0;

  for (int i = 1; i < n; i++) {
    wt[i] = bt[i - 1] + wt[i - 1];
  }
}

void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
  for (int i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
  }
}

void findAverageTime(int n, int bt[]) {
  int wt[n], tat[n], total_wt = 0, total_tat = 0;

  findWaitingTime(n, bt, wt);
  findTurnaroundTime(n, bt, wt, tat);

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

  for (int i = 0; i < n; i++) {
    total_wt += wt[i];
    total_tat += tat[i];
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
  }

  float avg_wt = (float)total_wt / n;
  float avg_tat = (float)total_tat / n;

  printf("\nAverage Waiting Time: %.2f\n", avg_wt);
  printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
  int n = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int burst_time[n];
  printf("Enter the burst time for each process:\n");
  for (int i = 0; i < n; i++) {
    printf("Process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
  }

  findAverageTime(n, burst_time);

  return 0;
}

