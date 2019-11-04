#include "Matrix.h"

namespace Tyrone4 {

	Matrix::Matrix(int rows, int cols) : rowSize{ rows }, colSize{ cols } {
		matrix.resize(rowSize);
		for (std::vector<double>& col : matrix) {
			col.resize(colSize);
		}
	}

	Matrix::~Matrix() {}

	std::vector<double>& Matrix::operator[](const int i) { return matrix[i]; }

	Matrix& Matrix::operator=(const Matrix& m) {
		if (this == &m) {
			return *this;
		}

		// ADD = OPERATOR
	}

	Matrix Matrix::transpose() {
		Matrix tposed(colSize, rowSize);
		for (int i = 0; i < rowSize; ++i) {
			for (int j = 0; j < colSize; ++j) {
				tposed[j][i] = matrix[i][j];
			}
		}
		return tposed;
	}

	Matrix& Matrix::operator*=(const Matrix& m) {
		if (m.colSize == rowSize && m.rowSize == colSize) {
			Matrix temp(rowSize, m.colSize);
			for (int i = 0; i < temp.rowSize; ++i) {
				for (int j = 0; j < temp.colSize; ++j) {
					for (int k = 0; k < colSize; ++k) {
						temp[i][j] += (matrix[i][k] * m.matrix[k][j]);
					}
				}
			}
			return (*this = temp);
		}
	}

	

}