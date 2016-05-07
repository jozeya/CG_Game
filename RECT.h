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

	float x;
	float y;
	float h;
	float w;


	void set_Rect(float, float, float, float);
	void ini_Values(float, float, float, float);

	bool collide(Rect*);
	pair<float,float> get_iniPoint();
	pair<float,float> get_endPoint();
};

#endif //RECT_H