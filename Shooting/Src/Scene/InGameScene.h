#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include "DxLib.h"
#include "SceneBase.h"
// ��`�w�b�^�[
#include "../Definition.h"

class InGameScene : public SceneBase
{
public:
	InGameScene();
	virtual~InGameScene();

public:
	virtual void Exec();  // ������s��
	virtual void Draw();  // �`���s��

	virtual bool IsEnd() const;

	int BG;

	int Color = GetColor(0, 0, 0);

private:
	void step_StartJingle();
	void step_Input();
	void step_ClearJingle();

// �q�ɔԂɊ֌W����֐��Q
private:
	// �Q�[���N���A����
	bool IsClear()const;
	// ��������ԂɃ��Z�b�g
	void Reset();
	// �ړ�����
	void Move( DirType dir_ );
};

#endif // !RESULTSCENE_H
