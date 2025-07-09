#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------------\n"


class Point
{
	double x;
	double y;
public: 
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//			Constructors;
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
		//Конструктор с одним параметром
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}




	//			Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++()		//Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)	//Postfix (Suffix) increment
	{
		Point old = *this;	//Сохраняем старое значение объекта
		x++;
		y++;
		return old;
	}



	//    Methods:
	double distance(const Point& other)const 
	{
		//this - эта точка (находим расстояние от этой точки)
		// other - та точка (до указанной точки)
		//this->x *= 100;     // E0137
		//other.x *= 100;  // E0137
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);  // sqrt() - Square Root(квадратный корень)
		return distance;
	}
	void print()const
	{
		cout << this << ":\tX = " << x << ",\tY = " << y << endl;
	}

};

double distance(const Point& A, const Point& B)
{
	//A.set_x(A.get_x() * 100);
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;

}


//#define struct_point
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHEK
//#define ASSIGNMENT_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifdef struct_point

	int a;   // объявление переменной 'a' типа 'int'.
	Point A; // объявление переменной 'А' типа 'Point'.
	         // Создание объекта 'А' структуры 'Point'.
	         // Создание экземпляра 'А' структуры 'Point'.
	         // 'A' is instance of struct 'Point'
	         // Instantiate - создать объект.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // struct_point

#ifdef DISTANCE_CHECK



	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
	cout << delimiter << endl;

#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHEK



	Point A;         //Здесь мы просто создаем объект, и для этого неявно вызывается конструктор по умолчанию
	A.print();
    {
   	    /*Point A;
		Point B;
	    cout << "Point B существует " << endl;
		B.distance(A);*/
	}

	Point B = 5;    // Палимитризованный конструтор позволяет задавать то каким будет наш объект при создании   // Single
	B.print(); 
	
	Point C(7, 8);	//
	C.print();

	Point D = C;  // copy constructor
	D.print();

#endif // CONSTRUCTORS_CHEK

//	cout << " Здесь Point B уже Не существует " << endl;

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	// Point(2,3) - здесь мы явно вызываем констурктор, и создаем временный безымянный объект.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

}


