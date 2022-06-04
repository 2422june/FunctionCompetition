#pragma once

 template <class T>

 class CSingleTon {

 private:
	 static T* m_Single;

 public:
	 CSingleTon() {};
	 virtual ~CSingleTon() {

		 delete m_Single;
	 };

	 static T* GetInstance() {

		 if (m_Single == NULL)
			 m_Single = new T();

		 return m_Single;
	 };
 };

 template <class T> T* CSingleTon<T>::m_Single = 0;