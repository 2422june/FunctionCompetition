//데이터 저장용도의 클레스이다.
//클레스의 복사 방법
// 
//1.얕은 복사 
//클레스의 복사본을 만들어 혼자 사용
// 
//2.깊은 복사
//클레스 내에서 직접적으로 작업(전역적, public)
#pragma once

template <class T>

class CSingleTon {

private:
	static T* m_Single;

public:
	CSingleTon() {};
	virtual ~CSingleTon() {

		delete m_Single;
	}

	static T* GetInstance() {

		if (m_Single == NULL)
			m_Single = new T();

		return m_Single;
	};
};

template <class T> T* CSingleTon<T>::m_Single = 0;