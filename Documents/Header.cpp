파일헤더
파일의 맨 위에 작성
/*******************************************************************************
filename			: 파일명
team name	: Team Ark
author			: 작성자 이름
email				: 본인 이메일, officialteamark@gmail.com
date				: 최초 작성일

description:
  파일이 하는 역할 및 파일 내용

@This file was written by team-ark ( ark-official.com )
*******************************************************************************/

함수 헤더

/****************************************************************************
\Function Name : commentExample
\Inputs : 
	lhs_ - int for example
	rhs_ - float for example
\Output : 
	bool - return type for example
\Role : 
	This function show how function header will be written

*****************************************************************************/
bool commentExample(int lhs_, float rhs_)
{
	return true;
}

클래스 헤더
/****************************************************************************
\Class Name : Object
\Role :
	This function show how function header will be written

*****************************************************************************/
class Object
{
public:
	Object();
	~Object();

private:
	bool m_isHandeld;  //!< 물체가 들려있는지 확인
	int m_health;            //!< 물체의 체력
};
