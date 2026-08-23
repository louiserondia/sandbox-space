#pragma once
#include "BaseGame.h"
#include "FlyFish.h"
#include "Plane.h"
#include "Line.h"
#include "Point.h"
#include "Renderer.h"

class Game : public BaseGame
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update(float elapsedSec) override;
	void Draw() override; // retiré le const ici et dans basegame pour que ça marche -> temporaire !!!!!
	void DrawBackground() const;
	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e) override;
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e) override;
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e) override;
	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e) override;
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e) override;
	void ProcessMouseWheelEvent(const SDL_MouseWheelEvent& e) override;

private:

	// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;
	Point point{ 1, 1, 0 };
	Vector u{ 0, 0, 1, 0 };
	Vector v{ 0, 1, 1, 0 };
	Renderer renderer{};
	float time{};
	bool isAlt{};

	static float zoom;
	Vector	e0{ 1, 0, 0, 0 };
	Vector	e1{ 0, 1, 0, 0 };
	Vector	e2{ 0, 0, 1, 0 };
	Vector	e3{ 0, 0, 0, 1 };
};
