#include <iostream>
#include "keyboard.h"

using namespace std;

void KeyInput::up(bool IsDown)
{
	if (IsDown && key_up) // ��������
	{
		if (GetDirKeyNum() == 1)
		{
			dir = Direct::up;
		}
	}
	else if (IsDown && !key_up) // ����˲��
	{
		dir = Direct::up;
	}
	else // δ����
	{
	}

	key_up = IsDown;
	return;
}

void KeyInput::down(bool IsDown)
{
	if (IsDown && key_down) // ��������
	{
		if (GetDirKeyNum() == 1)
		{
			dir = Direct::down;
		}
	}
	else if (IsDown && !key_down) // ����˲��
	{
		dir = Direct::down;
	}
	else // δ����
	{
	}

	key_down = IsDown;
	return;
}

void KeyInput::left(bool IsDown)
{
	if (IsDown && key_left) // ��������
	{
		if (GetDirKeyNum() == 1)
		{
			dir = Direct::left;
		}
	}
	else if (IsDown && !key_left) // ����˲��
	{
		dir = Direct::left;
	}
	else // δ����
	{
	}

	key_left = IsDown;
	return;
}

void KeyInput::right(bool IsDown)
{
	if (IsDown && key_right) // ��������
	{
		if (GetDirKeyNum() == 1)
		{
			dir = Direct::right;
		}
	}
	else if (IsDown && !key_right) // ����˲��
	{
		dir = Direct::right;
	}
	else // δ����
	{
	}

	key_right = IsDown;
	return;
}

void KeyInput::brake(bool IsDown)
{
	if (IsDown && key_brake) // ��������
	{
		if (GetDirKeyNum() == 1)
		{
			dir = Direct::brake;
		}
	}
	else if (IsDown && !key_brake) // ����˲��
	{
		dir = Direct::brake;
	}
	else // δ����
	{
	}

	key_brake = IsDown;
	return;
}

void KeyInput::stop(bool IsDown)
{
	if (IsDown && key_stop) // ��������
	{
		if (GetDirKeyNum() == 1)
		{
			dir = Direct::stop;
		}
	}
	else if (IsDown && !key_stop) // ����˲��
	{
		dir = Direct::stop;
	}
	else // δ����
	{
	}

	key_stop = IsDown;
	return;
}

Direct KeyInput::GetDir()
{
	if (GetDirKeyNum() != 0)
	{
		return dir;
	}

	return Direct::unassign;
}

int KeyInput::GetDirKeyNum()
{
	int result = 0;
	if (key_right) result++;
	if (key_left) result++;
	if (key_up) result++;
	if (key_down) result++;
	if (key_brake) result++;
	if (key_stop) result++;
	return result;
}
