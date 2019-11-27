//Demo code for operator overload in C++

#include <iostream>
#include <vector>
using namespace std;


//simple Point class 
class Point
{
	private: 
		

	public:
		int x,y;
		Point();
		Point(int, int);
		void showPoint();
};

Point::Point():x(0),y(0){}
Point::Point(int x, int y): x(x), y(y){}
void Point::showPoint(){cout << x << " " << y << endl;} 

//simple line class containing two points
class Line
{
	private: 
		
		
	public:
	Point p1, p2;
		Line();
		Line(Point, Point);
		void showLine();
		//Point array[2];
		//Point operator[] (int index);
		friend Line operator++(Line &ln);
		friend ostream & operator<< (ostream &out,  Line &ln);
		friend istream & operator>> (istream &in, Line &ln);
		
		
};

Line::Line(Point p1, Point p2):p1(p1),p2(p2){}
Line::Line(){}		// why don't I need to construct the points?
void Line::showLine(){p1.showPoint(); p2.showPoint();}
ostream & operator<< (ostream &out,  Line &ln){
	ln.showLine();
	return out; 
}
istream & operator>> (istream &in, Line &ln){
	in >> ln.p1.x >> ln.p1.y >> ln.p2.x >> ln.p2.y;
	return in;
}
Line operator++(Line &ln){
	++ln.p2.x;
	++ln.p2.y;
}
/*Point& Line::operator[] (int index){
	return array[index];
}*/

int main()
{	
	Point p1(1,1);
	Point p2(2,2);
	Line ln(p1,p2);

	
	//PART 2 
	//3. Implement a line output stream operator for homework. 
	cout << "Print line ln " << endl; 
	cout << ln;

	//6. Implement a line input stream operator for homework. 
	Line ln2(p1,p2);
	cout << "input for line 2, first two inputs are pt1 and the next twp are pt2" << endl; 
	cin >> ln2;
	//13. Implement a pre increment overload for line that just increments p2 for homework
	cout << ln << endl;
	++ln;
	cout << ln << endl; 
	//17. Implement a subscript operator for line that returns a point for homework
	/*ln.array[0] = ln.p1;
	ln.array[1] = ln.p2;
	cout << "return p1 or p2" << endl; 
	cout << ln[2] << endl; 
	*/
}