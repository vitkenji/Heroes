#include "MainMenu.hpp"
#include "Game.hpp"

namespace Menus
{

	MainMenu::MainMenu(States::Game* pGame) : Menu(), States::State(static_cast<States::StateMachine*>(pGame), States::StateID::mainMenu), pGame(pGame),
		title(Math::CoordinateF(300, 300), "HEROES", FONT2_PATH)
	{
		Managers::GraphicManager* pGraphicManager = Managers::GraphicManager::getInstance();

		GraphicalElements::Button* button = nullptr;
		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 ), "PLAY");
		button->select(true);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 + 100), "LEADERBOARD");
		button->select(false);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 + 200), "HOW TO PLAY");
		button->select(false);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 + 300), "QUIT");
		button->select(false);
		buttons.push_back(button);

		title.setFontSize(160);
		title.setTextInfo("HEROES");
		title.setTextColor(0,0,0);
		title.setTextAlignment(GraphicalElements::TextAlignment::center);
		title.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 - 200));

		min = 0;
		max = 3;

		pAudioManager->loadMusic(MAIN_MENU_MUSIC_PATH, &music);
	}

	MainMenu::~MainMenu()
	{

	}

	void MainMenu::update(const float dt)
	{
		active = true;
		title.setPosition(Math::CoordinateF(title.getPosition().x, title.getPosition().y));
	}
	void MainMenu::render()
	{
		updateView();
		back.render();
		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->render();
		}
		
		title.render();
	}
	void MainMenu::resetState()
	{
		active = false;
		buttons[selected]->select(false);
		selected = 0;
		buttons[selected]->select(true);
		int aux = 0;
		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->setTextPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 + 100 * aux));
			aux++;
		}

		music.play();

		title.setPosition(Math::CoordinateF(Managers::GraphicManager::getInstance()->getWindowSize().x / 2.0f, Managers::GraphicManager::getInstance()->getWindowSize().y / 2 - 200));
		
	}
	void MainMenu::execute()
	{
		if (active) {
			music.stop();
			active = false;
			switch (selected) {
			case 0:
				changeState(States::StateID::playing);
				break;
			case 1:
				changeState(States::StateID::leaderboard);
				break;
			case 2:
				break;
			
			case 3:
				pGame->quit();
				break;
			default:
				break;
			}
		}
	}
}