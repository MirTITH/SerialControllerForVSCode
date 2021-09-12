#pragma once

#include <Windows.h>

enum class Direct
{
	unassign,
	up,
	down,
	left,
	right,
	brake,
	stop
};

// ��������
class KeyInput
{
public:
	KeyInput()
	{
		dir = Direct::unassign;
	}

	void Update()
	{
		up(GetAsyncKeyState(87));// w
		down(GetAsyncKeyState(83));// s
		left(GetAsyncKeyState(65));// a
		right(GetAsyncKeyState(68));// d
		brake(GetAsyncKeyState(32));// space
		stop(GetAsyncKeyState(20));// Cape Lock
	}

	void up(bool IsDown);
	void down(bool IsDown);
	void left(bool IsDown);
	void right(bool IsDown);
	void brake(bool IsDown);
	void stop(bool IsDown);
	Direct GetDir();//��ȡ����
	int GetDirKeyNum(); //��ȡͬʱ���µķ��������
private:
	bool key_up = false;
	bool key_down = false;
	bool key_left = false;
	bool key_right = false;
	bool key_brake = false;
	bool key_stop = false;
	Direct dir;
};

// ���������ٶȿ���
class KeyInputSpeed
{
public:
	KeyInputSpeed()
	{
		dir = Direct::unassign;
	}

	void Update()
	{
		up(GetAsyncKeyState(87));// w
		down(GetAsyncKeyState(83));// s
	}

	void up(bool IsDown)
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

	void down(bool IsDown)
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

	Direct GetDir()//��ȡ����
	{
		if (GetDirKeyNum() != 0)
		{
			return dir;
		}

		return Direct::unassign;
	}


	int GetDirKeyNum() //��ȡͬʱ���µķ��������
	{
		int result = 0;
		if (key_up) result++;
		if (key_down) result++;
		return result;
	}
private:
	bool key_up = false;
	bool key_down = false;
	Direct dir;
};

// ��������ת�����
class KeyInputTurnRatio
{
public:
	KeyInputTurnRatio()
	{
		dir = Direct::unassign;
	}

	void Update()
	{
		left(GetAsyncKeyState(65));// a
		right(GetAsyncKeyState(68));// d
	}

	void left(bool IsDown)
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

	void right(bool IsDown)
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

	Direct GetDir()//��ȡ����
	{
		if (GetDirKeyNum() != 0)
		{
			return dir;
		}

		return Direct::unassign;
	}


	int GetDirKeyNum() //��ȡͬʱ���µķ��������
	{
		int result = 0;
		if (key_left) result++;
		if (key_right) result++;
		return result;
	}
private:
	bool key_left = false;
	bool key_right = false;
	Direct dir;
};

// ���������������
class KeyInputEmergency
{
public:
	KeyInputEmergency()
	{
		dir = Direct::unassign;
	}

	void Update()
	{
		brake(GetAsyncKeyState(32));// space
		stop(GetAsyncKeyState(VK_SHIFT));// SHIFT
	}

	void brake(bool IsDown)
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

	void stop(bool IsDown)
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

	Direct GetDir()//��ȡ����
	{
		if (GetDirKeyNum() != 0)
		{
			return dir;
		}

		return Direct::unassign;
	}

	int GetDirKeyNum() //��ȡͬʱ���µķ��������
	{
		int result = 0;
		if (key_brake) result++;
		if (key_stop) result++;
		return result;
	}

private:
	bool key_brake = false;
	bool key_stop = false;
	Direct dir;
};