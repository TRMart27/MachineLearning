#include "matrix.h"
#include "util.h"
#include "nn.h"



int main(int argc, char** argv )
{
        srand(time(NULL));

        if(argc != 2)
        {
                fprintf(stderr, "Incorrect Usage! ./exe **n_iterations**\n");
                exit(EXIT_FAILURE);
        }

        char* endptr;
        long long int n_iterations = strtol(argv[1], &endptr, 10);
        assert(n_iterations != 0);


        float xor_table[] = {
                0, 0, 0,
                1, 0, 1,
                0, 1, 1,
                1, 1, 0,
        };
        size_t num_samples = sizeof(xor_table) / sizeof(xor_table[0])/3;

        Matrix train = {
                .num_rows = num_samples,
                .num_cols = 2,
                .stride = 3,
                .data = xor_table //data starts at the starting address of xor_table
        };

        Matrix test = {
                .num_rows = num_samples,
                .num_cols = 1,
                .stride = 3,
                .data = &xor_table[2] //data starts at the address of xor_table[2] 
        };


        size_t arch[] = {2, 2, 1};

        NN network  = nn_alloc(arch, ARRAY_LEN(arch));
        nn_fill_rand(network, 0, 1);
        NN gradient = nn_alloc(arch, ARRAY_LEN(arch));
        //no need to fill gradient, those values will just be overwritten anyway


        float eps = 1e-1;
        float learning_rate = 1e-1;

        nn_train(network, gradient, eps, learning_rate, n_iterations, train, test);
        //nn_train_verbose(network, gradient, eps, learning_rate, n_iterations, train, test);
        gate_verify(network, .6);

        return 0;
}
