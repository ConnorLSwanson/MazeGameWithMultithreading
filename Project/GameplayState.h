#pragma once
#include "GameState.h"
#include "Player.h"

#include <windows.h>
#include <vector>
#include <string>
#include <thread>

class Level;
class StateMachineExampleGame;

class GameplayState : public GameState
{
	StateMachineExampleGame* m_pOwner;
	
	Player m_player;
	Level* m_pLevel;

	bool m_didBeatLevel;
	bool m_hasInput;
	int m_input = 0;
	int m_arrowInput = 0;
	int m_skipFrameCount;
	static constexpr int kFramesToSkip = 2;

	int m_currentLevel;

	std::vector<std::string> m_LevelNames;
	std::thread* m_pInputThread = nullptr;

public:
	GameplayState(StateMachineExampleGame* pOwner);
	~GameplayState();

	virtual void Enter() override;
	virtual bool Update(bool processInput = true) override;
	virtual void Draw() override;

protected:
	void ProcessInput() override;
	void CheckBeatLevel();

private:
	void MovePlayer();
	void HandleCollision(int newPlayerX, int newPlayerY);
	bool Load();
	void DrawHUD(const HANDLE& console);
};
