#include "PauseMenu.hpp"

namespace Menus
{

	PauseMenu::PauseMenu(States::StateMachine* pStateMachine, States::Level* pLevel) : Menu(), States::State(pStateMachine, States::StateID::pauseMenu),
		title(Math::CoordinateF(300, 300), "HEROES", FONT2_PATH), pLevel(pLevel)
	{

		title.setFontSize(120);
		title.setTextInfo("GAME PAUSED");
		title.setTextColor(0, 0, 0);
		title.setTextAlignment(GraphicalElements::TextAlignment::center);
		title.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 - 200));

		back.initialize(PAUSEMENUBACKGROUND_PATH, Math::CoordinateF(pGraphicManager->getWindowSize().x / 2, pGraphicManager->getWindowSize().y / 2), Math::CoordinateF(pGraphicManager->getWindowSize().x, pGraphicManager->getWindowSize().y));
		GraphicalElements::Button* button = nullptr;
		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 ), "RESUME");
		button->select(true);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 + 100), "QUIT");
		button->select(false);
		buttons.push_back(button);

		
		min = 0;
		max = 1;
	}

	PauseMenu::~PauseMenu()
	{

	}

	void PauseMenu::render()
	{
		updateView();
		back.render();
		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->render();
		}
		title.render();
	}

	void PauseMenu::update(const float dt)
	{
		active = true;
	}

	void PauseMenu::execute()
	{
		if (active) {
			active = false;
			switch (selected) {
			case 0:
				pLevel->setResume(true);
				changeState(States::StateID::playing);
				break;
			case 1:
				pLevel->setResume(false);
				changeState(States::StateID::mainMenu);
				break;
			default:
				break;
			}
		}
	}

	void PauseMenu::resetState()
	{
		active = false;
	}

	void PauseMenu::triggerPauseMenu()
	{
		pStateMachine->changeCurrentState(States::pauseMenu);
	}

	

}