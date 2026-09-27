#include "GameSystem.h"

#include <raylib.h>

void GameSystem::Run(){
    init();
    loop();
    close();
}

void GameSystem::init(){
	_window.init();
	_camera.init();
}

void GameSystem::draw()
{
	BeginDrawing();
	BeginMode2D(_camera.getData());

	ClearBackground(BLANK);
	EndMode2D();	

	DrawFPS(10, 100);
	EndDrawing();
}

void GameSystem::close(){
	CloseWindow();
}

void GameSystem::loop()
{
	while (!WindowShouldClose())
	{
		process();
		draw();
	}
}

void GameSystem::process(){
	_window.process();
	_camera.process();
}