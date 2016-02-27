// my first program in C++
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <string>

using namespace std;

int ** readmatrix(string filename);
int ** matrix_empty(int dim);
int** rand_matrix(int dim, int max);
int inner_product(int *v, int *w);
int* projection(int *e, int *a);
bool is_symmetric (int** matrix);

void matrix_print(int ** matrix);



int main ()
{
  cout << "Please provide a file containing a symmetric matrix\n";

  string str;
  cin >> str;

  matrix_print(readmatrix(str));

}

int ** readmatrix(string filename)
{
  string line;
  ifstream file(filename);

  int ** matrix;

  if (file.is_open())
  {

    int rows = 0;
    int cols = 0;

    if(getline(file,line)) 
    {
      //tokenise first line seperately to get dimensions of line

      char *line_ = (char *) line.c_str();

      rows = atoi(strtok(line_, " "));
      cols = atoi(strtok(NULL, " "));

      if (rows != cols) 
      {
        cout << "You must provide a square matrix!";
        return NULL;
      }

      matrix = matrix_empty(rows);

      int lines = 0;

      int i = 0;
      int j = 0;

      while (getline (file,line))
      {
        cout << line << '\n';

        char *int_str = strtok(line_, " ");

        while(int_str != NULL)
        {
          int_str = strtok(line_, " ");
          matrix[i][j] = atoi(int_str);

          i++;
        }
        j++;
      }
      file.close();
    }
    else 
    {
      cout << "Unable to open file"; 
    }
  }

  return matrix;
}

int ** matrix_empty(int dim) 
{
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

// calculates v^(T)w
int inner_product(int *v, int *w) 
{
  //PRE: v and w have the same size
  assert(sizeof(v) == sizeof(w));

  int dim = sizeof(v);
  int accum = 0;

  for (int i = 0; i < dim; i++) 
  {
    accum += (v[i]*w[i]);
  }

  return accum;
}


// projection of a in direction of e
int* projection(int *e, int *a) 
{
  //(<e,a>/<e,e>) e
  //PRE: dimension of e = dimension of a
  assert(sizeof(e) == sizeof(a));
  int dim = sizeof(e);

  float frac = (float) inner_product(e, a) / (float) inner_product(e, e);

  int *res = new int[dim];

  for (int i = 0; i < dim; i++) 
  {
    res[i] = e[i] * frac;
  }

  return res;
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

void matrix_print(int ** matrix)
{
  int rows = sizeof(matrix);
  int cols = sizeof(matrix[0]);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      cout << matrix[i][j];
    }
  }


}