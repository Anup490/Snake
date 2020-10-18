#include "painter/Painter.h"
#include "items/Snakeitem.h"
#include "items/Fooditem.h"
#include "timer/Timer.h"
#include "collision/Collision.h"
#include "constant/Constants.h"
#include <ppl.h>
#include <iostream>

using namespace std;

char value = INPUT_RIGHT;

void setup_key_listener(SnakeItem* pSnakeItem, Timer* pTimer);
void listen_input(SnakeItem* pSnakeItem, Timer* pTimer);
void run_game(Collision* pCollision, Painter* pPainter, Timer* pTimer);
void show_game_over_message();

int main()
{
	SnakeItem snakeItem;
	FoodItem foodItem;
	initializer_list<AbstractItem*> items({ &snakeItem , &foodItem});
	Painter painter(&items);
	Timer timer;
	Collision collision(&items);
	setup_key_listener(&snakeItem, &timer);
	run_game(&collision,&painter,&timer);
	show_game_over_message();
	return 0;
}

void setup_key_listener(SnakeItem* pSnakeItem, Timer* pTimer) 
{
	thread listener(listen_input, pSnakeItem, pTimer);
	listener.detach();
}

void listen_input(SnakeItem* pSnakeItem, Timer* pTimer) 
{
	while (value != EXIT_KEY) 
	{
		if (pTimer->IsMilliSecondComplete(FRAME_INTERVAL_MILLIS)) 
		{
			cin >> value;
			pSnakeItem->OnInput(value);
		}
	}
}

void run_game(Collision* pCollision, Painter* pPainter, Timer* pTimer) 
{
	while (value != EXIT_KEY) 
	{
		if (pTimer->IsMilliSecondComplete(FRAME_INTERVAL_MILLIS)) 
		{
			try 
			{
				pCollision->CheckCollision(pPainter->Paint());
			}
			catch (CollisionException& e) 
			{
				value = EXIT_KEY;
			}
		}
	}
}

void show_game_over_message() 
{
	for (int i = 0; i < (((MAX_X_AXIS) / 2) - 5); i++) 
	{
		cout << " ";
	}
	cout << "GAME OVER" << endl;
}