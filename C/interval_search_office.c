/*
You were given a list of strings which indicated at what time of the day an employee of a company checked in and checked out of the company on a particular day.  Input was in the form of <Employee_Name>, <In_Time>, <Out_Time> (comma separated).
Eg:       
Alice,10:23:02,13:04:45
Bob,09:00:43,12:03:21
The time was always in HH:MM:SS 24-hours format. You were given a time of the day as query <Query_Time> Eg: 11:00:56. We have to determine how many numbers of employees were present inside the company at the point in time (Query_Time). In these examples, o/p should be 2 (Reason: Alice and Bob both are inside the office at time 11:00:56).
*/
#include <stdio.h>
#include <string.h>

#define ENTRY_SIZE 100
#define INTERVAL_SIZE (24 * 60 * 60)

void main ()
{
  int i;
  int in_hour, in_min, in_sec, out_hour, out_min, out_sec;
  char interval[INTERVAL_SIZE] = {0};
  
  printf ("Enter input in Alice,10:23:02,13:04:45 format (Enter 0 to indicate the end of input)\n");

  while (1) {
    char entry[ENTRY_SIZE] = {0};
    char name[20] = {0};
    fgets (entry, ENTRY_SIZE, stdin);
    if (entry[0] == '0')
      break;
    //fgets includes "\n" in the input, so discard that.
    int len = strlen (entry);
    if (entry[len - 1] == '\n')
      entry[len - 1] = '\0';
    //%s format needs to followed by a space. As we don't have space in our format, use strtok to find the actual pointer to the time
    char *ts = strchr (entry, ',') + 1;
    //printf ("ts = %s\n", ts);
    //parse the timestamp
    sscanf (ts, "%d:%d:%d,%d:%d:%d", &in_hour, &in_min, &in_sec, &out_hour, &out_min, &out_sec);
    //printf ("in_hour = %d in_min = %d in_sec = %d out_hour = %d out_min = %d out_sec = %d \n", in_hour, in_min, in_sec, out_hour, out_min, out_sec);
    int in_timestamp = (in_hour * 60 + in_min) * 60 + in_sec;
    int out_timestamp = (out_hour * 60 + out_min) * 60 + out_sec;
    interval[in_timestamp] += 1;
    interval[out_timestamp + 1] -= 1;
    //printf ("%d %d\n", in_timestamp, out_timestamp);
  }

  for (i = 1; i < INTERVAL_SIZE; i++) {
    interval [i] += interval [i - 1];
  }

  while (1) {
    char entry[ENTRY_SIZE] = {0};
    printf ("Enter a time = ");
    fgets (entry, ENTRY_SIZE, stdin);
    sscanf (entry, "%d:%d:%d", &in_hour, &in_min, &in_sec);
    int in_timestamp = (in_hour * 60 + in_min) * 60 + in_sec;
    printf ("%d\n", in_timestamp);
    printf ("Number of employee = %d \n", interval[in_timestamp]);
  }
}
