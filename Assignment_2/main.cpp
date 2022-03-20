// Johannes A. Kjær

#include "std_lib_facilities.h"
// Oppg.5:
#include "Graph.h"
#include "AnimationWindow.h"





// Oppgave 1 //

// 1a)
void inputAndPrintInteger() {
	cout << "Input an integer:\n";
	int integer = 0;
	cin >> integer;
	cout << "You wrote: " << integer << "\n";
}
 
// 1b)
int inputInteger() {
	cout << "Input an integer:\n";
	int integer;
	cin >> integer;
	return integer;
}

// 1c)

void inputIntegersAndPrintSum() {
	int a = inputInteger();
	int b = inputInteger();
	cout << a+b << "\n";
}

// 1d)
//
// Den andre returnerer ikke noen verdi
//


// 1e)

bool isOdd(int a) {
	return a % 2;
}

// 1f)

void printHumanReadableTime(int s) {
	int sec = s % 60;
	int m = (s-sec)/60;
	int min = m % 60;
	int h = (m-min)/60;
	cout << h << " timer, " << min << " minutter og " << sec << " sekunder\n";
}


// Oppgave 2 //

// 2a)

void sumOfIntegers() {
	cout << "How many integers? "; 
	int n = 0;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cout << "Input an integer? "; 
		int temp;
		cin >> temp;
		sum += temp;
	}
	cout << "The sum of your integers is: " << sum << "\n";
}

// 2b)

void sumOfIntegersUntilZero() {
	int sum = 0;
	int temp = 1;
	while (temp != 0) {
		cout << "Input an integer? "; 
		cin >> temp;
		sum += temp;
	}
	cout << "The sum of your integers is: " << sum << "\n";
}

// 2c)
//
// I deloppgave a er en for-løkke best egent da en hvis kode skal kjøres et visst antall ganger, uavhengig av hva hendelser som måtte skje. I deloppgave b derimot er en while-løkke best egnet, da en hvis kode skal kjøres frem til en hvis hendelse, og aldri stoppe med mindre hendelsen inntreffer.
//


// 2d)

double inputDouble() {
	double someDouble = 0;
	cout << "Input a double: ";
	cin >> someDouble;
	return someDouble;
}

// 2e)

void convertCurrency(double ex_rate = 9.75) {
	double NOK = 0;
	cout << "How many NOK do you have? ";
	cin >> NOK;
	double Euro = NOK / ex_rate; 
	cout << NOK << " NOK amounts to " << Euro << " Euros";
}

// 2f)
//
// Man kan ikke gjøre operasjoner på integers som resulterer i doubles, da vil svaret bli avrundet til en integer. Dermed er det enklere å bruke en funksjon som tar inn en double, istedenfor å bruke en som tar inn en integer som så må konverteres til en double.
//

// Oppgave 3 //

// 3a) 
// Se main funksjonen

// 3b)

void multiplicationTable() {
	int w = 0;
	int h = 0;
	cout << "What width should the multiplication table have?\n"; 
	cin >> w;
	cout << "What height should the multiplication table have?\n"; 
	cin >> h;
	for (int i=1; i<=h; i++) {
		for (int n=1; n<=w; n++) {
			cout << setw(to_string(h*w).length()+1) << n*i;
		}
		cout << "\n";
	}
}

// Oppgave 4 //

// 4a)

double discriminant(double a,double b, double c) {
	return b*b - 4*a*c;
}

// 4b)

void printRealRoots(double a, double b, double c) {
	double dis = discriminant(a,b,c);
	if (dis < 0 ) {
		cout << "No real roots exist for the given arguments.\n";
	} else if (dis == 0) {
		cout << "x = " << -b/(2*a) << "\n";
	} else {
		cout << "x_1 = " << (-b + pow(dis,0.5))/(2*a) << ", x_2 = " << (-b - pow(dis,0.5))/(2*a) << "\n";
	}
}


// 4c) 

void solveQuadraticEquation() {
	double a = inputDouble();
	double b = inputDouble();
	double c = inputDouble();
	printRealRoots(a,b,c);
}

// 4d - menyvalg nummer 13

// 4e - Ikke teste foreløpig, da kompilering ikke funker.


// Oppgave 5 //

void pythagoras() { //Untested due to compilation failing
	// a)
	using namespace Graph_lib;
	using namespace TDT4102;
	// b)
	int h = 256;
	int w = 256;
	AnimationWindow win{100,100,w,h,"Pythagoras"};
	// c)
	Point point1{100,100};
	Point point2{100,180};
	Point point3{130,180};

	win.draw_triangle(point1,point2,point3,Color::red);
	// d)
	win.draw_quad(point1,point2,Point{20,180},Point{20,100}, Color::blue);
	win.draw_quad(point2,point3,Point{130,210},Point{100,210}, Color::blue);
	win.draw_quad(point1,point3,Point{210,150},Point{180,70}, Color::blue);

	win.wait_for_close();
}

// Oppgave 6 //

// a)

vector<int> calculateBalance(double deposit, int interest, int years) {
	vector<int> t;
	for (int i = 0; i<years;i++) {
		t.push_back(deposit * pow(1+interest/100.0,i));
	}
	return t;
}

// b)

void printBalance(vector<int> ole) {
	cout << setw(4) << "Year" << setw(12) << "Saldo" << "\n";
	for (int i = 0; i<ole.size(); i++) {
		cout << setw(4) << i << setw(12) << ole[i] << "\n";
	}
}

// c)
//
// I dunno
//

// d)

// Den funka jo


// Main

int main() {
	cout << "0) Exit\n1) (1a) inputAndPrintInteger\n2) (1b) inputInteger\n3) (1c) inputIntegersAndPrintSum\n4) (1e) isOdd(integer)\n5) (1f) printHumanReadableTime(seconds)\n6) (2a) sumOfIntegers\n7) (2b) sumOfIntegersUntilZero\n8) (2d) inputDouble\n9) (2e) convertCurrency\n10) (3b) multiplicationTable\n11) (4a) discriminant\n12) (4b) printRealRoots\n13) (4c) solveQuadraticEquation\n14) (5) pythagoras\n15) (6a) calculateBalance\n16) (6b) printBalance\n17) (6d) debugging";
	int option;
	cin >> option;
	if (option == 1) {
		inputAndPrintInteger();
	} else if (option == 2) {
		cout << inputInteger() << '\n';
	} else if (option == 3) {
		inputIntegersAndPrintSum();
	} else if (option == 4) {
		cout << isOdd(15) << '\n';
	} else if (option == 5) {
		printHumanReadableTime(10000);
	} else if (option == 6) {
		sumOfIntegers();
	} else if (option == 7) {
		sumOfIntegersUntilZero();
	} else if (option == 8) {
		cout << inputDouble() << '\n';
	} else if (option == 9) {
		convertCurrency();
	} else if (option == 10) {
		multiplicationTable();
	} else if (option == 11) {
		cout << discriminant(3,4,5) << "\n";
	} else if (option == 12) {
		printRealRoots(2,3,2);
	} else if (option == 13) {
		solveQuadraticEquation();
	} else if (option == 14) {
		pythagoras();
	} else if (option == 15) {
		calculateBalance(5000,3,10);
	} else if (option == 16) {
		printBalance(calculateBalance(5000,3,10));
	} else if (option == 17) {
		vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for (int i = 0; i <= v.size(); i++) {
			cout << v[i] << endl;
		}
	}
}


