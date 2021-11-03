#include<iostream>
#include<set>
#include<random>
#include<fstream>
#include<string>
#include<new>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;



template<typename T>
class Grid {
private:
	T* memory;
	size_t x_size, y_size;

public:
	Grid(size_t x_size, size_t y_size): //выделяет память под одномерный массив(т.к возможна биекция между матрицей NxM и вектором размерности N*M)
		x_size(x_size), 
		y_size(y_size),
		memory(new T[x_size*y_size]){ };


	Grid(Grid const& copy) : Grid(copy.x_size, copy.y_size){  //конструктор копирования
		for (size_t pos = 0; pos != x_size * y_size; ++pos) {
			memory[pos] = copy.memory[pos];
		}
	}

	~Grid() { 
		delete[] memory; 
	}

	T operator()(size_t x_idx, size_t y_idx) const { 
		return memory[(x_idx - 1) + x_size*(y_idx - 1)];
	}

	T& operator()(size_t x_idx, size_t y_idx) { 
		return memory[(x_idx - 1) + x_size * (y_idx - 1)];
	}

	size_t get_xsize() const {
		return x_size;
	}

	size_t get_ysize() const {
		return y_size;
	}


	
	Grid& operator=(T value) {        //оператор присваивания заменяет все элементы сетки на значение входящего параметра value
		for (size_t pos = 0; pos != x_size * y_size; ++pos) {
			memory[pos] = value;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Grid const& grid) { //выводит сетку
		for (T i = 1; i != grid.y_size+1; i++) {
			for (T j = 1; j != grid.x_size+1; j++) {
				out << grid.memory[(j - 1) + grid.x_size*(i-1)] << ' ';
			
			}
			out << std::endl;
		}

		return out;
	}

	friend std::istream& operator>>(std::istream& in, Grid& grid) { //ввод сетки, тупо построчно
		for (T i = 0; i != grid.y_size*grid.x_size; i++) {
			in >> grid.memory[i];
		}
		return in;
	}
};




int main() {
	Grid<int> g1(3, 2);
	g1 = 3;
	cout << g1;
	cout << std::endl;
	cout << g1(1, 1);
	cout << std::endl;
	g1(3, 1) = 0; //номер столбца, строки(отсчет от 1)
	cout << std::endl;
	cout << g1;
	cout << std::endl;


	Grid<int> g_in(2, 3);
	cout << "Enter grid elements";
	cout << std::endl;
	cin >> g_in;
	cout << std::endl;
	cout << g_in;
	cout << std::endl;

	
	Grid<int> copy1(g1); //используем конструктор копирования
	cout << copy1;
	copy1(2, 2) = 0;
	cout << std::endl;
	cout << copy1;
	cout << "Copy changed";
	cout << std::endl;
	cout << g1;
	cout << "Original not";


}