#ifndef INPUT_H
#define INPUT_H

class Input
{
public:
	Input();
	~Input();

	bool Init();
	void KeyDown(unsigned int);
	void KeyUp(unsigned int);
	bool IsKeyDown(unsigned int);

private:
	bool m_bKeys[256];
};

#endif //INPUT_H