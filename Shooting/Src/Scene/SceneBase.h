#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneBase
{
public:
	SceneBase();
	virtual~SceneBase();

public:
	// �������e�͔h���N���X���ɈႤ�̂ŁA
	// �������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() = 0;  // �������s��
	virtual void Draw() = 0;  // �`����s��

	virtual bool IsEnd() const; // �V�[�����I���������ǂ�����Ԃ�

protected:
	void set_Step(int step_);

protected:
	int m_Step;   // �������e���Ǘ�����ϐ�
};


#endif // !SCENEBASE_H

