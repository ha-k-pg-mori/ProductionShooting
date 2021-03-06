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
	virtual void Exec();  // 処理を行う
	virtual void Draw();  // 描画を行う

	virtual bool IsEnd() const;

	int Result;
	int g_Couter;

private:
	void step_Input();
};

#endif // !RESULTSCENE_H



