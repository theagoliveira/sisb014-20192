#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr_count(int *arr, int s, int n) {
  int i, result;
  for(i = 0; i < s; i++) {
    if(arr[i] == n)
      result++;
  }

  return result;
}

float f_arr_max(float *arr, int s) {
  float max = 0;
  int i;
  for(i = 0; i < s; i++) {
    if(arr[i] > max)
      max = arr[i];
  }

  return max;
}

int main() {
  int i, j, k, space_pos;
  int n_cases;
  int n_candidates;
  int n_votes;
  char candidates[20][81];
  char str_vote[52];
  int vote[20];
  int votes[1000][20];
  int vote_count[20];
  float vote_perc[20];
  FILE *in;

  in = fopen("australian_voting_input.txt", "r");

  fscanf(in, "%d", &n_cases);

  // DEBUG
  printf("Number of cases: %d\n", n_cases);
  //

  for(i = 0; i < n_cases; i++) {
    fscanf(in, "%d", &n_candidates);
    fgetc(in);

    // DEBUG
    printf("Case %d, number of candidates: %d\n", i + 1, n_candidates);
    //

    for(j = 0; j < n_candidates; j++) {
      fgets(candidates[j], 80, in);
      candidates[j][strlen(candidates[j]) - 1] = '\0';
    }

    // DEBUG
    printf("Case %d, candidates: ", i + 1);
    for(j = 0; j < n_candidates; j++) {
      printf("%s", candidates[j]);
      if (j != n_candidates - 1) {
        printf(", ");
      }
    }
    printf("\n");
    //

    n_votes = 0;
    k = fgets(str_vote, 51, in);
    str_vote[strlen(str_vote) - 1] = '\0';

    // DEBUG
    // printf("Case %d, str vote %d: %s\n", i + 1, n_votes + 1, str_vote);
    //

    while(k) {
      // DEBUG
      printf("Case %d, vote %d: ", i + 1, n_votes + 1);
      //

      space_pos = 0;
      for(j = 0; j < n_candidates; j++) {
        sscanf(&str_vote[space_pos], "%d", &votes[n_votes][j]);

        if(j == 0)
          vote_count[votes[n_votes][j] - 1]++;

        while(str_vote[space_pos] != ' ') {
          space_pos++;
        }
        space_pos++;

        // DEBUG
        printf("%d", votes[n_votes][j]);
        if(j != n_candidates - 1) {
          printf(" ");
        }
        //
      }

      // DEBUG
      printf("\n");
      //

      k = fgets(str_vote, 51, in);
      str_vote[strlen(str_vote) - 1] = '\0';
      n_votes++;
      if (k) {
        // DEBUG
        // printf("Case %d, str vote %d: %s\n", i + 1, n_votes + 1, str_vote);
        //
      }
    }

    // DEBUG
    printf("Case %d, vote count (percentage): ", i + 1);
    //

    for(j = 0; j < n_candidates; j++) {
      vote_perc[j] = (float) 100 * vote_count[j] / n_votes;

      // DEBUG
      printf("%d (%.2f)", vote_count[j], vote_perc[j]);
      if(j != n_candidates - 1) {
        printf(" ");
      }
      //
    }

    // DEBUG
    printf("\n");
    //

    while(f_arr_max(vote_perc) <= 50.0) {

    }
  }

  fclose(in);
  return 0;
}
