
#include "InputManager.h"


// �L�[���͍X�V
void InputManager::Update()
{
	for( int i = 0; i < KeyType_Max; i++ )
	{
		// ���݂̃L�[�̓��͏�Ԃ�擾
		const bool now = (CheckHitKey(KEY_ASSIGN[i]) == 1);

		// �O��̃L�[���Ɣ�r����Č��݂̏�Ԃ�X�V
		m_State[i].on   = now;
//		m_State[i].push = (now == true)  && (m_State[i].old == false);
//		m_State[i].pull = (now == false) && (m_State[i].old == true);
		m_State[i].push =  now & !m_State[i].old;
		m_State[i].pull = !now &  m_State[i].old;

		m_State[i].old = now;
	}
}

// �L�[�������ꂽ��
bool InputManager::IsPush( KeyType key ) const
{
	if( key == KeyType_Max ){ return false; }
	return m_State[key].push;
}

// �L�[����������Ă��邩
bool InputManager::IsOn( KeyType key ) const
{
	if( key == KeyType_Max ){ return false; }
	return m_State[key].on;
}

// �L�[�������ꂽ��
bool InputManager::IsPull( KeyType key ) const
{
	if( key == KeyType_Max ){ return false; }
	return m_State[key].pull;
}



//------------------------------------------------------------
// �V���O���g���f�U�C��
InputManager* InputManager::m_pInstance = nullptr;

// ���̂���֐�
void InputManager::CreateInstance()
{
	// null�`�F�b�N����邱�ƂŁA�Q��ڈȍ~�͍���Ȃ�
	if( m_pInstance == nullptr )
	{
		m_pInstance = new InputManager();
	}
}
// ���̂�j������֐�
void InputManager::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}
// ���̂����邩��m�F����֐�
bool InputManager::IsNull()
{
	return (m_pInstance == nullptr);
}
// ���̂�擾����֐�
InputManager* InputManager::GetInstance()
{
	return m_pInstance;
}

InputManager::InputManager()
{
}
InputManager::~InputManager()
{
}
