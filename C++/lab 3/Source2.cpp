#include<iostream>
#include<conio.h>

using namespace std;
//error 1 eroare de alocare de memorie
//error 2 eroare la compararea matricelor

class matrice
{
	int m;
	int n;
	double **p;
	int error;
public:
	matrice(int);
	matrice(int, int);
	matrice(const matrice&);
	~matrice();
	int infoerror();
	int info_n();
	int info_m();
	void set_n(double a) { n = a; }
	void set_m(double b) { m = b; }
	void intro();
	void inmultire(int k);
	void set(int i, int j, double valoare);
	matrice& operator=(const matrice&);
	matrice operator*(const matrice&);
	matrice& operator*=(const matrice&);
	matrice operator+(const matrice&);
	matrice &operator+=(const matrice&);
	matrice operator-(const matrice&);
	matrice &operator-=(const matrice&);

	friend ostream& operator<<(ostream& os, const matrice& ob);
	friend istream& operator>>(istream& is, matrice& ob);
	friend matrice operator*(const matrice&, double value);
	friend matrice operator*=(const matrice&, double value);
	friend matrice operator+(double value, const matrice& ob);
	friend matrice operator+=(const matrice&, double value);
	friend matrice operator-(const matrice&, double value);
	friend matrice operator-=(const matrice&, double value);

};

ostream& operator<<(ostream &os, const matrice& ob)
{
	os << endl;
	for (int i = 0; i<ob.n; i++)
	{
		for (int j = 0; j<ob.m; j++)
			os << ob.p[i][j] << " ";
		os << endl;
	}
	os << endl;
	return os;
}

istream& operator >> (istream& is, matrice &ob)
{
	for (int i = 0; i<ob.n; i++)
		for (int j = 0; j<ob.m; j++)
			is >> ob.p[i][j];
	return is;
}

matrice::matrice(int nl = 0)
{
	n = nl;
	m = n;
	p = NULL;
	error = 0;
}
//****************************************************************

matrice::matrice(int nl, int nc)
{
	int i, j;
	error = 0;
	n = nl;
	m = nc;
	if (!(p = new double*[nl])) 
		error = 1;
	for (i = 0; i<n; i++)
	{
		if (!(p[i] = new double[nc])) 
			error = 1;
		for (j = 0; j<m; j++)
			p[i][j] = 0;
	}
}

///*************************************************************11
matrice::matrice(const matrice &ob)
{
	int i, j;
	n = ob.n;
	m = ob.m;
	this->p = new double*[n];
	error = ob.error;
	for (i = 0; i < n; i++)
	{
		this->p[i] = new double[m];
		for (j = 0; j < m; j++)
			this->p[i][j] = ob.p[i][j];
	}
}
//**************************************************************
matrice ::~matrice()
{
	for (int i = 0; i<n; i++)
		delete[] p[i];
	delete[] p;
}
//****************************************************************
int matrice::info_n() { return n; }
//*****************************************************************
int matrice::infoerror() { return error; }
//*******************************************************************
int matrice::info_m() { return m; }
//******************************************************************
void  matrice::set(int i, int j, double valoare)
{
	if ((i>n) && (i<0) && (j>m) && (j<0)) error = 2;
	p[i][j] = valoare;
}
//******************************************************************
matrice& matrice::operator=(const matrice& ob)
{
	if (this == &ob)
		return *this;
	int i, j;
	this->n = ob.n;
	this->m = ob.m;
	this->error = ob.error;
	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
			this->p[i][j] = ob.p[i][j];
	return *this;
}

matrice matrice::operator*(const matrice& ob)
{
	matrice temp = *this;
	temp *= ob;
	return temp;
}
matrice& matrice::operator*=(const matrice& ob)
{
	int i, j, k;
	matrice c(n, m);
	if (this->m != ob.n) error = 3;
	for (i = 0; i<n; i++)
		for (j = 0; j<ob.m; j++)
		{
			int suma = 0;
			for (k = 0; k<ob.m; k++)
				suma += p[i][k] * ob.p[k][j];
			c.p[i][j] = suma;
		}
	for (i = 0; i<n; i++)
		for (j = 0; j<ob.m; j++)
			p[i][j] = c.p[i][j];
	return *this;
}
matrice matrice::operator+(const matrice &ob)
{
	matrice temp(n, m);
	if ((n != ob.n) && (m != ob.m))
		error = 2;
	else
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				temp.p[i][j] = p[i][j] + ob.p[i][j];
	return temp;
}

matrice& matrice::operator+=(const matrice& ob)
{
	if ((n != ob.n) && (m != ob.m))
		error = 2;
	else
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				p[i][j] += ob.p[i][j];
	return *this;
}

matrice matrice::operator-(const matrice& ob)
{
	matrice temp = *this;
	temp -= ob;
	return temp;
}

matrice& matrice::operator-=(const matrice& ob)
{
	int i, j;
	if (n != ob.n&&m != ob.m)
	{
		error = 3;
		cout << "\n error";
	}
	else
		for (i = 0; i<n; i++)
			for (j = 0; j<m; j++)
				p[i][j] -= ob.p[i][j];
	return *this;
}
matrice operator-=(const matrice& ob, double value)
{
	int i, j;
	for (i = 0; i<ob.n; i++)
		for (j = 0; j<ob.m; j++)
			ob.p[i][j] -= value;
	return ob;
}
matrice operator+=(matrice& ob, double value)
{
	ob = ob + value;
	return ob;
}
matrice operator-(const matrice& ob, double value)
{
	int i, j;
	matrice temp(ob.n, ob.m);
	for (i = 0; i<ob.n; i++)
		for (j = 0; j<ob.m; j++)
			temp.p[i][j] = ob.p[i][j] - value;
	return temp;
}
matrice operator+(double value, const matrice& ob)
{
	int i, j;
	matrice temp(ob.n, ob.m);
	for (i = 0; i<ob.n; i++)
		for (j = 0; j<ob.m; j++)
			temp.p[i][j] = ob.p[i][j] + value;
	return temp;
}

void main()
{
	int k;
	matrice a(3, 3), b(3, 3);
	cout << "A = \n";
	cin >> a;
	cout << endl;
	cout << "B = \n";
	cin >> b;
	matrice c(b);
	cout << c;
	c = a + b;
	cout << c;
	c = a * b;
	cout << c;

	if (a > b)
		cout << "a";
	else
		cout << "b";

	return 0;
}