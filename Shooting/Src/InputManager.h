#ifndef TNPUT_MANAGER_H
#define TNPUT_MANAGER_H

#include "KeyDefinition.h"

// ���͊Ǘ��N���X
class InputManager
{
private:
	// �L�[��ԍ\��
	struct KeyState
	{
		bool old;  // �O��`�F�b�N���̃t���O���

		bool push; // �����ꂽ�u��
		bool on;   // ��������Ă���
		bool pull; // �����ꂽ�u��

		KeyState()
			:old(false)
			, push(false)
			, on(false)
			, pull(false)
		{};
	};

public:
	// �L�[���͍X�V
	void Update();

	bool IsPush(KeyType key) const;

	bool IsOn(KeyType key) const;

	bool IsPull(KeyType key) const;

private:
	KeyState m_State[KeyType_Max];

public:
	// statice��mpInstance�ւ̃A�N�Z�X�p�ꐔ�Q
	// ���̂���֐�
	static void CreateInstance();
	// ���̂�j������֐�
	static void DestroyInstance();
	// ���̂����邩��m�F����֐�
	static bool IsNull();

	static InputManager* GetInstance();

private:
	InputManager();
	~InputManager();

private:
	// static�ɂ��邱�ƂŁA�N���X��1�����ł��邱�Ƃ�ۏ؂���
	static InputManager* m_pInstance;
};

#endif // !TNPUT_MANAGER_H