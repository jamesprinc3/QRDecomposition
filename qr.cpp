// my first program in C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>


int main ()
{
  std::cout << "Please provide a file containing a symmetric matrix";
}

int ** matrix_empty(int dim) {

  int** matrix = new int*[dim];

  for(int i = 0; i < dim; i++)
  {
    matrix[i] = new int[dim];
  }

  return matrix;
}




int** rand_matrix(int dim, int max)
{

  int ** matrix = matrix_empty(dim);
  int entry;

	for (int i = 0; i < dim; i++) 
  {
		for (int j = i; j < dim; j++) 
    {
			entry = rand() % max;

      matrix[i][j] = entry;

      if (i != j) 
      {
        // only need to do opposite entry if we're not on the diagonal

        matrix[i][j] = entry;
      }

		}
	}

  return NULL;
}


bool is_symmetric (int** matrix) 
{	
	// PRE: matrix is square
	assert(sizeof(matrix) == sizeof(matrix[0]));

	int dim = sizeof(matrix);

	for (int i = 0; i < dim; i++) 
  {
		for (int j = 0; j < dim; j++) 
    {
			if (i != j && matrix[i][j] != matrix[j][i]) 
      {
				return false;
			}
		}
	}
	return true;
}