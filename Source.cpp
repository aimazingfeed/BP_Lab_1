#include <iostream>
#include <math.h>


double Fun_1(double x, double a, double b);
double Fun_2(double x, double a, double b);
double integ(double a, double b,double x0,double y0, double Fun(double,double,double));


int main()
{
	setlocale(LC_ALL, "");


	double M1 = (1 - sqrt(0.75)) - integ(-2, -1 - sqrt(0.75), -1, 1, Fun_1) + sqrt(0.75) - integ(-1 - sqrt(0.75), -1, -1, 0, Fun_2);
	double M2 = integ(-1, 0, 0, 0, Fun_2) + integ(-1, 0, -1, -1, Fun_2) + integ(0, 1, 1, 1, Fun_1) + integ(0, 1, 1, -1, Fun_2);
	double M3 = integ(1, 2, 1, 0, Fun_2) - (integ(1, 1 + sqrt(0.75), 1, 1, Fun_1) + integ(1 + sqrt(0.75), 2, 1, 0, Fun_2)) + integ(sqrt(0.75), 1, 0, 1, Fun_1) - integ(sqrt(0.75), 1, 0, 0, Fun_2);
	double M4 = (1-sqrt(0.75))-integ(-1,-sqrt(0.75),0,-1,Fun_2)+sqrt(0.75)-integ(-sqrt(0.75),0,0,0,Fun_1);
	double M5 = integ(1, 2, 1, -1, Fun_1)-1 + ((2*0.5 - integ(0.5, 1, 0, -1, Fun_1)) - (2*0.5 - integ(0.5, 1, 1, -1, Fun_1))) + sqrt(0.75)-integ(1, 1 + sqrt(0.75), 1, 0, Fun_1) + (1-sqrt(0.75))-integ(1 + sqrt(0.75), 2, 1, -1, Fun_2);
	
	std::cout << "M1= " << M1 << std::endl;
	std::cout << "M2= " << M2 << std::endl;
	std::cout << "M3= " << M3 << std::endl;
	std::cout << "M4= " << M4 << std::endl;
	std::cout << "M5= " << M5 << std::endl;


	double x, y;
	
	while (true) {
		std::cin >> x >> y;
		if (((-2 <= x and x <= -1 - sqrt(0.75)) and (Fun_1(x, -1, 1) <= y and y <= 1)) or ((-1 - sqrt(0.75) <= x and x <= -1) and (Fun_2(x, -1, 0) <= y and y <= 1)))
			std::cout << "Попадение в М1" << std::endl;

		if ((-1 <= x and x <= 0 and Fun_2(x, -1, -1) <= y and y <= Fun_2(x, 0, 0)) or (0 <= x and x <= 1 and Fun_2(x, 1, -1) <= y and y <= Fun_1(x, 1, 1)))
			std::cout << "Попадение в М2" << std::endl;

		if ((sqrt(0.75) <= x and x <= 1 and Fun_2(x, 0, 0) <= y and y <= Fun_1(x, 0, 1)) or (1 <= x and x <= 1 + sqrt(0.75) and Fun_1(x, 1, 1) <= y and y <= Fun_2(x, 1, 0)))
			std::cout << "Попадение в М3" << std::endl;

		if (((-1 <= x and x <= -sqrt(0.75)) and (Fun_2(x, 0, -1) >= y and y >= -1)) or ((-sqrt(0.75) <= x and x <= 0) and (Fun_1(x, 0, 0) >= y and y >= -1)))
			std::cout << "Попадение в М4" << std::endl;

		if (((0.5 <= x and x <= 1) and (Fun_1(x, 0, -1) >= y and y >= Fun_1(x, 1, -1))) or ((1 <= x and x <= 2) and (Fun_1(x, 1, 0) <= y and y <= Fun_1(x, 1, -1))))
			std::cout << "Попадение в М5" << std::endl;
	}
}
double integ(double a, double b, double x0, double y0, double Fun(double,double,double))
{
	double y1, y2;
	double s = 0;
	double h = 0.0001;
	for (double i = a; i < b; i += h)
	{
		y1 = abs(Fun(i,x0,y0));
		if (i + h > b)				//это сделано для того, чтобы не было выхода за b (иначе квадратный корень из отриц. числа == nan)
			y2 = abs(Fun(b,x0,y0));
		else
			y2 = abs(Fun(i + h,x0,y0));


		s += ((y1 + y2) / 2) * h;
	}
	return s;

}
double Fun_1(double x, double a, double b)
{
	return b - sqrt(1 - (x - a) * (x - a));
}
double Fun_2(double x, double a, double b)
{
	return sqrt(1 - (x - a) * (x - a)) + b;
}

