#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"

/** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @param flag Nonzero if using pointer sort, zero if using array sort
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

void timesort (int a[], int count, int flag)
{

  struct timeval start_time; // time stamps for start and end of sorting
  struct timeval end_time;
  struct timeval sort_time; // Elapsed time while sorting

  printf("Unsorted array:\n");
  print_int_array(a, count);

  gettimeofday(&start_time, NULL); // Get timestamp
  if (flag == 0) // Check sort type flag
  {
    printf("sorting using arrays\n");
    sort_descending(a, count);
  }
  else
  {
    printf("sorting using pointers\n");
    sort_descending_pointers(a, count);
  }
  gettimeofday(&end_time, NULL); // Get timestamp

  printf("Sorted array (descending order):\n");
  print_int_array(a, count);

  printf("Timestamp before sorting: ");
  print_timeval(start_time);
  printf("Timestamp after sorting: ");
  print_timeval(end_time);
  sort_time = timediff(start_time, end_time);
  printf("Time spent sorting: ");
  print_timeval(sort_time);

  return; // nothing to return
}
