#include "stdafx.h"
#include "Game.h"

//c-tor
Game::Game()
	:m_level(make_unique<Level>(m_bar))
{
	m_window.create(VideoMode(1100, 1300),
		"Tetris", sf::Style::Titlebar | sf::Style::Close);
}
// run game
void Game::run()
{
	while (m_bar.getLevel() != 10){
		    m_level->run(m_window);
			m_bar.increaseLevel();
			m_level->updateSpeed();
			m_level = make_unique<Level>(m_bar);
		}
}
