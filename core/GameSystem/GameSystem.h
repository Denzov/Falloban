#ifndef THEMOLLUSK_APP_H
#define THEMOLLUSK_APP_H

#include "MainWindow/MWindowHandler.h"
#include "MainCamera2D/MCamera2DHandler.h"

class GameSystem {
public:
	void Run();

private:
	void init();
	void draw();
	void close();
	void loop();
	void process();

private:
	MWindowHandler _window;
    MCamera2DHandler _camera;
};

#endif // !THEMOLLUSK_APP_H