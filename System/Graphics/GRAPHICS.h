#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Init();
	void Shutdown();
	bool Frame();

private:
	bool Render();
};

#endif //GRAPHICS_H