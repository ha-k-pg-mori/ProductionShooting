#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();

	

public:
	virtual void Exec();  // ������s��
	virtual void Draw();  // �`���s��

	virtual bool IsEnd() const; // �V�[�����I���������ǂ�����Ԃ�

private:
	void step_LogoIn();
	void step_Input();

};

#endif // !TITLESCENE_H



