# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

// is prime
bool
isgerman(long number)
{
	if (number == 2 || number == 3)
		return true;

	if (number < 2 || !(number & 1) || !(number % 3))
		return false;

	for (int i = 5; i*i <= number; i += 6)
		if (!(number % i) || !(number % (i + 2)))
            return false;

	return true;
}

// fuh.rar
void
hitlerSort(int germany[], size_t size, int **aryan, size_t *new_size)
{
	size_t population_germany = size;

	// get rid of non-germans
	for (int i = 0; i < size; i++)
		if (!isgerman(germany[i])) {
			germany[i] = 0;
			population_germany--;
		}

	// take them for further investigation
	size_t germans = population_germany;
	int non_j3ws[germans];
	size_t non_j3w = 0;
	for (int i = 0; i < size; i++)
		if (germany[i])
			non_j3ws[non_j3w++] = germany[i];

	// only the pure aryans stay
	size_t german = 1;
	while (german < germans) {
		if (non_j3ws[german] < non_j3ws[german-1]) {
			non_j3ws[german--] = 0;
			germans--;
		}
		german++;
	}

	// investigation over, go home
	*new_size = germans;
	int *pureblood = malloc(germans * sizeof(int));
	size_t index = 0;
	for (int i = 0; i < germans; i++)
		if (non_j3ws[i])
			pureblood[index++] = non_j3ws[i];

	*aryan = pureblood;
}


int main()
{
	int pre_war_germany[] = {
		4659, 736,4951,9344,1927,6271,8837,8711,3241,6579,7660,5499,5616,3743,
		5801,4682,9748,8796, 779,1833,4549,8138,4026, 775,4170,2432,4174,3741,
		7540,8017,2833,4027, 396, 811,2871,1150,9809,2719,9199,8504,1224, 540,
		2051,3519,7982,7367,2761, 308,3358,6505,2050,4836,5090,7864, 805,2566,
		2409,6876,3361,8622,5572,5895,3280, 441,7893,8105,1634,2929, 274,3926,
		7786,6123,8233,9921,2674,5340,1445, 203,4585,3837,5304,5499, 564,2801,
		 679,2653,1783,3608,7359,7797,3284, 796,3222, 437,7185,6135,8571,2778,
		7488,5746, 678,6140, 861,7750, 803,9859,9918,2425,3734,2698,9005,4864,
		9818,6743,2475, 132,9486,3825,5472, 919, 292,4411,7213,7699,6435,9019,
		6769,1388, 802,2124,1345,8493,9487,8558,7061,8777,8833,2427,2238,5409,
		4957,8503,3171,7622,5779,6145,2417,5873,5563,5693,9574,9491,1937,7384
	};
	int germany_population = sizeof(pre_war_germany)/sizeof(*pre_war_germany);

	int *aryans;
	size_t number_of_aryans;
	hitlerSort(pre_war_germany, germany_population, &aryans, &number_of_aryans);

	for (int i = 0; i < number_of_aryans; i++)
		printf("%d ", aryans[i]);
	printf("\n");
}

