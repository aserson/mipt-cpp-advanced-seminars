#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
class Grid {
private:
	float *memory;
	size_t x_size, y_size;
public:
	Grid(size_t x_size, size_t y_size):x_size(x_size),y_size(y_size)
	{
		memory = new float [x_size * y_size];
	}
	float operator()(size_t x_idx, size_t y_idx) const
	{
		return memory[x_idx + x_size * y_idx];
	}
	float& operator()(size_t x_idx, size_t y_idx)
	{
		return memory[x_idx + x_size * y_idx];
	}
	size_t get_xsize() const
	{
		return x_size;
	}
	size_t get_ysize() const
	{
		return y_size;
	}
	~Grid()
	{
		delete []memory;
	}
	
	Grid (const Grid &elem):x_size(elem.x_size), y_size(elem.y_size)
	{
		memory = new float [x_size * y_size];
		for (size_t i = 0 ; i < x_size * y_size ; i++)
		{
			memory[i] = elem.memory[i];
		}
	}
	
	
	Grid(Grid&& G):x_size(G.x_size),y_size(G.y_size),memory(G.memory)
	{
		G.x_size = 0;
		G.y_size = 0;
		G.memory = NULL;
	}
	
	Grid& operator=(Grid& x)
	{
		if (&x == this)
			return *this;
		cout << "delete memory: " << memory;
		delete[] memory;
		x_size = x.x_size;
		y_size = x.y_size;
		memory = new float [x_size*y_size];
		for (size_t i = 0; i < x_size*y_size; i++)
			{
    			memory[i] = x.memory[i];
			}
		return *this;
		
	}
	
	Grid& operator=(Grid &&x)
	{
		if(&x == this)
			return *this;

		cout << "delete memory: " << memory;
		delete[] memory;

		x_size = x.x_size;
		y_size = x.y_size;
		memory = x.memory;
		x.memory = NULL;

		return *this;
	}
	friend ostream& operator<< (ostream &out, Grid const& x);
	
	friend istream& operator>> (istream &in, Grid &x);
};

ostream& operator<<(ostream& out, Grid const &x)
{
	for (size_t i = 0; i < x.x_size ; i++)
	{
	    for (size_t j = 0 ; j < x.y_size ; j++)
		    out << x.memory[i * x.x_size +j] << " ";
	}
	return out;	
}

istream& operator>>(istream &in, Grid  &x)
{
	for (size_t i = 0; i < x.x_size*x.y_size ; i++)
	{
		in >> x.memory[i];
	}
	return in;
}
int main()
{
	int n,m,x;
	cin >> n >> m;
	Grid  G(n,m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			{
				cin >> x;
				G(i,j) = x;
			}

	cout << "G:\n" << G << endl << endl;

	Grid   H(G);
	cout << "H:\n" << H << endl << endl;

	G = H;
	cout << "New G:\n" << G << endl << endl;
	
	return 0;
}

