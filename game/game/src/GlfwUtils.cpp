#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include "GlfwUtils.h"

static sf::Window* window;

namespace Glfw
{
	sf::Window& getWindow() 
	{
		return *window;
	}

	void setWindow(sf::Window& win)
	{
		window = &win;
	}

	unsigned int getWidth()
	{
		return window->getSize().x;
	}

	unsigned int getHeight()
	{
		return window->getSize().y;
	}

	glm::uvec2 getSize()
	{
		sf::Vector2u size = window->getSize();
		glm::uvec2* ptr = reinterpret_cast<glm::uvec2*>(&size);
		return *ptr;
	}

	glm::ivec2 getPosition()
	{
		sf::Vector2i pos = window->getPosition();
		return *reinterpret_cast<glm::ivec2*>(&pos);
	}

	void hideCursor()
	{
		window->setMouseCursorVisible(false);
		window->setMouseCursorGrabbed(true);
	}

	void showCursor()
	{
		window->setMouseCursorVisible(true);
		window->setMouseCursorGrabbed(false);
	}

	bool isKeyPressed(sf::Keyboard::Key key)
	{	
		return sf::Keyboard::isKeyPressed(key);
	}

	glm::ivec2 getCursorPos()
	{
		sf::Vector2i pos = sf::Mouse::getPosition();
		glm::ivec2* ptr = reinterpret_cast<glm::ivec2*>(&pos);
		return *ptr;
	}

	void setCursorPos(const glm::ivec2& pos)
	{
		sf::Mouse::setPosition(reinterpret_cast<const sf::Vector2i&>(pos));
	}
}