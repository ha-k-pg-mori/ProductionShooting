#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include "SceneBase.h"
#include "InGameScene.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	virtual~ResultScene();
	
public:
	virtual void Exec();  // �������s��
	virtual void Draw();  // �`����s��

	virtual bool IsEnd() const;

	int Result;

private:
	void step_Input();
};

#endif // !RESULTSCENE_H



