#pragma once

namespace Tyrone4 {

	class Matrix {

	public:
		Matrix(int rows, int cols);
		~Matrix();

		Matrix transpose();

		Matrix& operator=(const Matrix&);

		Matrix& operator*=(const Matrix&);
		Matrix& operator*=(const double);

		std::vector<double>& operator[](const int i);
	private:
		std::vector < std::vector<double> > matrix;
		int rowSize;
		int colSize;

		void alloc();

	};

}