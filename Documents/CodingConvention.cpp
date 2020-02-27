�ڵ�������

** Ark �� ������Ʈ �ڵ������� ȿ������ ������ �� �������� �켱���Ѵ�.

1.������ ǥ����� ī�� ǥ����� ������
float currentTime;

2.	�Լ��� �Ķ������ ������ �� �ڿ��� ������ھ�(��_��)�� ���δ�
void playerController(int time_ /* O */);

3. c������ h���ϰ�, cpp������ hpp���ϰ� ��� ����Ѵ�.

ObjectSpawner.hpp
ObjectSpawner.cpp

PlayerController.h
PlayerController.c

4. float, double ���� int���̾ �ݵ�� �ڿ� �Ҽ���(.0f or .0) ǥ�⸦ �Ѵ�.
ex)
float initialValue = 0; // X
double returnValue = 5;

float initialValue = 0.0f; // O
double returnValue = 5.0;

5. if, for �� �߰�ȣ �� ����Ҷ� �߰�ȣ�� �ݵ�� if �� �����ٿ� ��ġ�Ѵ�
if (initialValue == 3) { // X
}

if (initialValue == 3)
{
	// O
}

6. if �� ������ 1���̶� �ݵ�� �߰�ȣ�� ����Ѵ�
if (playerExist == true)
{
	return 0;
}

// X . ������ �����ִ��Լ����� �־ �ȵȴ�. ���api�Լ����� �̷����ʴ´�.
7. bool Ÿ���� ���ǹ��� �Լ��� ����ϴ� ��쿡���� == false���� (!Function())�� �̿��Ѵ�.
// O
bool playerExist = false;

if (playerExist)
{
	return 0;
}
if (!playerNotExist)
{
	return 0;
}
// O
if (!isEmpty())
{

}
// X
if (isEmpty() == false)
{

}


//if (!isEmpty())
//{
//
//}


8. �ݵ�� ��������� �� ������ pragma(visual studio����) �Ǵ� 'define ���ϸ�'�� ����Ѵ�
ex)
#pragma once

�Ǵ�

//������ �Ǿ�
#ifndef FILENAME_H
#define FILENAME_H

...
Codes
...

//�� ��
#endif

9. ��������(global variable) ������ ���� ���� �ʴ´�.

10. namespace �� ����Ѵٸ� �ݵ�� ������ �߰�ȣ �ڿ� �ڸ�Ʈ�� ���´�.
ex)
namespace World
{
	namespace Scene
	{

	} // namespace Scene end
} // namespace World end

11. �����ѹ� ����� �����ʴ´�. ���� ����� �ϰ�ʹٸ� define�� const int, float ���� ����ϸ�, �� �� const ���� �켱�� �Ͽ� ����Ѵ�.
ex)
// X
int applicationNumber = 5;
int maxHealth = 100.0f;

// O
// ����
#define APP_NUM 5
const int MAX_HEALTH = 100.0f;

...
Codes
...

int applicationNumber = APP_NUM;
int maxHealth = MAX_HEALTH;



12. external header file�� ��������, �� �ڿ� in-house ��������� ����
#include <iostream>
#include <vector>

#include "PlayerController.hpp"

13. switch���������� �ݵ�� �������� default case�� �ִ´�.
switch (value)
{
	case 0;
		...
		break;
	case 1:
		...
		break;
	default:
		break;
}

14. recursive �Լ����� �ݵ�� ���� Rec�� ���δ�.
void FibonacciRec();

15. �Լ��� �̸��� class �� struct �� �̸��� �Ľ�Į ǥ����� ������ //Class
class ObjectSpawner
{
public:
	ObjectSpawner();
	~ObjectSpawner();

private:

};
struct Object;

void ObjectSpawner(void);

16. class�� ��� ������ �� �տ��� 'm_' �� ���δ� //Class
class ExampleClass
{
public:
	...

private:
	int m_numOfPlayer; // O
};

17. ������� �������� �Լ������� ���Ѵ�. //Class
ex)
>> ObjectSpawner.hpp

class ObjectSpawner
{
public:
	ObjectSpawner(void);
	~ObjectSpawner(void);

	void update(void) // X
	{
		++m_timeFlow;
	}
private:
	float m_timeFlow;
};

>> ObjectSpawner.cpp
void ObjectSpawner::update(void) // o
{
	++m_timeFlow;
}

18. ��������� Initialize�� Constructor���� Explicit Initialization�� ����Ѵ� //Class
ex)
//(X)
ObjectSpawner::ObjectSpawner(void)
{
	m_firstValue = 0;
	m_secondValue = 0;
}
//(O)
ObjectSpawner::ObjectSpawner(void) : m_firstValue(0), m_secondValue(0)
{
}

19. �׻� class�� ��������� �����Ҷ��� getter�� setter�Լ��� ����. //Class
class ExampleClass
{
public:
	ExampleClass();
	~ExampleClass();

	int GetHealth(void);
	void SetHealth(int health_);

private:
	int m_health; // O
};

20. class �ȿ����� �Լ�, ���������� ���� ������ ������. //Class
	a)	public methods
	b)	protected methods
	c)	private methods
	d)	protected variables
	e) private variables

21. h���� ������ �ٸ� ������ include�� ���ϰ�, class �� �ʿ��ҽ� forward declaration�� ����Ѵ�. //Class
ObjectSpawner.hpp

// X
#include "Object.hpp"

class ObjectSpawner
{
public:
	ObjectSpawner(void);
	~ObjectSpawner(void);
	void ObjectSpawn(Object* toSpawn_);

private:
	Object m_prefab_;
};

// O
class Object;

class ObjectSpawner
{
public:
	ObjectSpawner(void);
	~ObjectSpawner(void);
	void ObjectSpawn(Object* toSpawn_);

private:
	Object m_prefab_;
};

22. ������ �̸����� �ش� ������ ���� �ֿ䰡 �Ǵ� class ������ �Ѵ�. //Class
>>ObjectSpawner.hpp

class ObjectSpawner
{
public:
	ObjectSpawner(void);
	~ObjectSpawner(void);
	void ObjectSpawn(Object* toSpawn_);
};

>>ObjectSpawner.cpp

ObjectSpawner::ObjectSpawner(void)
{

}
~ObjectSpawner::ObjectSpawner(void)
{

}