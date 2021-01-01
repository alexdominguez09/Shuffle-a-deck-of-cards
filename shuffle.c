#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utility function to swap two elements A[i] and A[j] in the array
void swap(int A[], int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

// Function to shuffle an array A[] of n elements
void shuffle(int A[], int n)
{
	//srand(time(NULL));
	// read array from highest index to lowest
	for (int i = n - 1; i >= 1; i--)
	{
		// generate a random number j such that 0 <= j <= i
		int j = rand() % (i + 1);

		// swap current element with randomly generated index
		swap(A, i, j);
	}
}

// A utility function to print an array
void printArray (int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

void clrscr()
{
    system("cls||clear");
    //printf("\033[2J");        //  clear the screen
    //printf("\033[H");         // position cursor at top-left corner
}

double factorial(int n)
{
  int c;
  double r = 1;

  for (c = 1; c <= n; c++)
    r = r * c;

  return r;
}


int main(void)
{
	int A[] = { 1, 2, 3, 4, 5, 6,7,8,9,10,11,12,
                21,22,23,24,25,26,27,28,29,30,31,32,
                41,42,43,44,45,46,47,48,49,50,51,52,
                61,62,63,64,65,66,67,68,69,70,71,72 };

	int original[] = { 1, 2, 3, 4, 5, 6,7,8,9,10,11,12,
                21,22,23,24,25,26,27,28,29,30,31,32,
                41,42,43,44,45,46,47,48,49,50,51,52,
                61,62,63,64,65,66,67,68,69,70,71,72 };

	int n = sizeof(A) / sizeof(A[0]);
	int equality = 0;
	long barajados = 0;
	float speed, seconds = 0;
	int segundos = 1;
	time_t start, end;

	// Presentation
    clrscr();
	printf ("         The infinite shuffle of a deck of cards. \n         ---------------------------------------- \n\n" );
	printf (" This programs simulate the shuffle of a deck of cards, it shuffles the deck \n" );
	printf (" indefenetly untill the final state of the cards is actually sorted all of them. \n");

    printf("Enter the number of cards in the deck (1 to 48): ");
    scanf("%d", &n);
	printf("  Number of cards: %d \n",n);
	printf("  Posible diferent combinations for %d cards are %.0lf = %d! \n",n, factorial(n), n);
	printf("\n >> Press Enter <<\n");
	getchar(); // Pause to read the explanation
    getchar(); // Pause to read the explanation
    clrscr();

	// Seed for random input
	srand(time(NULL));

	printf("Original deck of cards. \n\n");
	printArray( A, n);
	printf("\n");
    printf("Shuffled a few times. \n\n");
	for (int j = 0; j < 6; j++)
        {
        shuffle(A, n);
        printArray( A, n);
        }
	printf("\n  >> Press Enter to begin the infinite shuffle << \n");
	getchar(); // Pause to read the explanation
	clrscr();
	printf("\n  >> SHUFFLING HAS STARTED << \n");


	// compare array
	start = time(NULL); 	start--;

	while (equality!=(n))
	{
	  equality=0;
	  barajados++;
	  end = time(NULL);
	  seconds = (end - start);
	  segundos = seconds;
	  speed = barajados/seconds;

      shuffle(A, n);
      //printArray( A, n);
      for (int i = 0 ; i < n ; i++)
        {
		// compare array elements
		if (A[i]==original[i])
            {equality++;
            }
            else
            {//equality=0;
            }

        }
     // Show info every x seconds
     if ( (segundos%30)<0.01 )
        if (equality>n/3)
        {
        clrscr();
        printf(" Number of times the deck is shuffled: %ld. Elapsed time: %.1f minutes. \n\n",barajados, seconds/60 );
        printf(" Speed: %.0f shuffles per second.\n\n", speed  );
        printArray( A, n);
        printf("\n Equality: %d, still shuffling !! \n",equality);
        }


	}

	  clrscr();
      printf(" Number of times the deck is shuffled: %ld. Elapsed time: %.1f minutes. \n\n",barajados, seconds/60 );
      printf(" Speed: %.0f shuffles per second.\n\n", speed  );
      printArray( A, n);
      printf("\n Equality: %d \n",equality);

	return 0;
}

