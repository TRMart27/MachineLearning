#include "matrix.h"
#include "nn.h"
#include "util.h"


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "Incorrect Usage! Please input number of training iterations!\n");
		exit(EXIT_FAILURE);
	}
	
	char *endptr;
	float n_iter = strtol(argv[1], &endptr, 10);
	assert(n_iter != 0);

	float or_table[] = {
		0, 0, 0,
		1, 0, 1,
		0, 1, 1,
		1, 1, 1,
	};

	float num_samples = sizeof(or_table) / sizeof(or_table[0]) / 3;

	Matrix train = {
		.num_rows = num_samples,
		.num_cols = 2,
		.stride = 3,
		.data = or_table
	};

	Matrix test = {
		.num_rows = num_samples,
		.num_cols = 1,
		.stride = 3,
		.data = &or_table[2]
	};

	size_t architecture[] = {2, 1, 1};
	
	NN network = nn_alloc(architecture, ARRAY_LEN(architecture));
	nn_fill_rand(network, 0, 1);
	NN gradient = nn_alloc(architecture, ARRAY_LEN(architecture));

	float eps = 1e-1;
	float learning_rate = 1e-1;

	nn_train(network, gradient, eps, learning_rate, n_iter, train, test);
	gate_verify(network, .6);

	return 0; 
}
