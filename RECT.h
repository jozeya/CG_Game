#ifndef RECT_H
#define RECT_H
#include <utility>

using namespace std;

class Rect{
public:
	pair <float, float> ini_Point;
	pair <float, float> end_Point;

	Rect();
	~Rect();

	void set_Rect(float, float, float, float);
	pair<float,float> get_iniPoint();
	pair<float,float> get_endPoint();
};

#endif //RECT_H