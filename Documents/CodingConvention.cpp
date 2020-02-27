코딩컨벤션

** Ark 팀 프로젝트 코딩에서는 효율성과 가독성 중 가독성을 우선시한다.

1.변수의 표기법은 카멜 표기법을 따른다
float currentTime;

2.	함수의 파라미터의 값들의 맨 뒤에는 언더스코어(‘_’)를 붙인다
void playerController(int time_ /* O */);

3. c파일은 h파일과, cpp파일은 hpp파일과 묶어서 사용한다.

ObjectSpawner.hpp
ObjectSpawner.cpp

PlayerController.h
PlayerController.c

4. float, double 값이 int값이어도 반드시 뒤에 소숫점(.0f or .0) 표기를 한다.
ex)
float initialValue = 0; // X
double returnValue = 5;

float initialValue = 0.0f; // O
double returnValue = 5.0;

5. if, for 등 중괄호 를 사용할때 중괄호는 반드시 if 의 다음줄에 위치한다
if (initialValue == 3) { // X
}

if (initialValue == 3)
{
	// O
}

6. if 의 내용이 1줄이라도 반드시 중괄호를 사용한다
if (playerExist == true)
{
	return 0;
}

// X . 가끔씩 버그있는함수들이 있어서 안된다. 몇몇api함수들은 이러지않는다.
7. bool 타입의 조건문중 함수를 사용하는 경우에서는 == false보다 (!Function())을 이용한다.
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


8. 반드시 헤더파일의 맨 위에는 pragma(visual studio에서) 또는 'define 파일명'을 사용한다
ex)
#pragma once

또는

//파일의 맨앞
#ifndef FILENAME_H
#define FILENAME_H

...
Codes
...

//맨 뒤
#endif

9. 전역변수(global variable) 선언은 절대 하지 않는다.

10. namespace 를 사용한다면 반드시 끝나는 중괄호 뒤에 코멘트를 적는다.
ex)
namespace World
{
	namespace Scene
	{

	} // namespace Scene end
} // namespace World end

11. 매직넘버 사용을 하지않는다. 만약 사용을 하고싶다면 define과 const int, float 등을 사용하며, 그 중 const 형을 우선시 하여 사용한다.
ex)
// X
int applicationNumber = 5;
int maxHealth = 100.0f;

// O
// 맨위
#define APP_NUM 5
const int MAX_HEALTH = 100.0f;

...
Codes
...

int applicationNumber = APP_NUM;
int maxHealth = MAX_HEALTH;



12. external header file을 먼저쓰고, 그 뒤에 in-house 헤더파일을 쓴다
#include <iostream>
#include <vector>

#include "PlayerController.hpp"

13. switch구문에서는 반드시 마지막에 default case를 넣는다.
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

14. recursive 함수에는 반드니 끝에 Rec를 붙인다.
void FibonacciRec();

15. 함수의 이름과 class 와 struct 의 이름은 파스칼 표기법을 따른다 //Class
class ObjectSpawner
{
public:
	ObjectSpawner();
	~ObjectSpawner();

private:

};
struct Object;

void ObjectSpawner(void);

16. class의 멤버 변수의 맨 앞에는 'm_' 를 붙인다 //Class
class ExampleClass
{
public:
	...

private:
	int m_numOfPlayer; // O
};

17. 헤더파일 내에서의 함수선언은 피한다. //Class
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

18. 멤버변수의 Initialize는 Constructor에서 Explicit Initialization을 사용한다 //Class
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

19. 항상 class의 멤버변수에 접근할때는 getter와 setter함수를 쓴다. //Class
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

20. class 안에서의 함수, 변수선언은 다음 순서를 따른다. //Class
	a)	public methods
	b)	protected methods
	c)	private methods
	d)	protected variables
	e) private variables

21. h파일 내에서 다른 파일의 include는 피하고, class 가 필요할시 forward declaration을 사용한다. //Class
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

22. 파일의 이름명에는 해당 파일의 제일 주요가 되는 class 명으로 한다. //Class
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