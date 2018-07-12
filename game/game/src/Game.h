#pragma once
#include <SFML/Window.hpp>
#include "ResourceMgr/ResourceMgr.h"
#include "Renderer/Renderers/MasterRenderer.h"
#include "Renderer/QuadVBO.h"
#include "Terrain/World.h"
#include "Terrain/TerrainGen.h"

class Game
{
private:
	ResourceMgr resourceMgr;
	ComponentRegistry componentRegistry;
	EntityRegistry entityRegistry;

	Camera camera;
	MasterRenderer renderer;
	World world;

	TerrainGen terrainGen;

	QuadVBO quadVbo;

public:
	Game();
	~Game();

	void onFocusGained(const sf::Event& event);
	void onFocusLost(const sf::Event& event);
	void onWindowClosed();
	void onWindowResized(const sf::Event& event);

	void tick();
	void render(const float partialTicks);

	void init();
};