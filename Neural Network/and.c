#include "matrix.h"
#include "nn.h"
#include "util.h"

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "Incorrect usage! Please provide number of training iterations!\n");
		exit(EXIT_FAILURE);
	}
	
	char* endptr;
	long long int n_iter = strtol(argv[1], &endptr, 10);
	assert(n_iter != 0);

	float and_table[] = {
		0, 0, 0,
		1, 0, 0,
		0, 1, 0,
		1, 1, 1
	};
	float num_samples = sizeof(and_table) / sizeof(and_table[0])/3; 
	
	Matrix train = {
		.num_rows = num_samples,
		.num_cols = 2,
		.stride = 3,
		.data = and_table
	};

	Matrix test = {
		.num_rows = num_samples,
		.num_cols = 1,
		.stride = 3,
		.data = &and_table[2]
	};


	size_t architecture[] = {2, 1, 1};

	NN network = nn_alloc(architecture, ARRAY_LEN(architecture));
	nn_fill_rand(network, 0, 1);
	NN gradient = nn_alloc(architecture, ARRAY_LEN(architecture));

	float eps = 1e-1;
	float learning_rate = 1e-1;

	//n_train_verbose(network, gradient, eps, learning_rate, n_iter, train, test);
	nn_train(network, gradient, eps, learning_rate, n_iter, train, test);


	gate_verify(network, .6);
}
