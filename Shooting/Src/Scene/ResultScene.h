#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include "SceneBase.h"
#include "InGameScene.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	virtual~ResultScene();

	int Color = GetColor(255, 255, 255);
	
public:
	virtual void Exec();  // �������s��
	virtual void Draw();  // �`����s��

	virtual bool IsEnd() const;

	int Result;
	int g_Couter;

private:
	void step_Input();
};

#endif // !RESULTSCENE_H



