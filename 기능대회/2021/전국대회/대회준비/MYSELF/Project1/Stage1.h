#pragma once
class Stage1
{
public:
	Stage1(int _stage);
	~Stage1();

	void Peathon1();

	void Update(float deltaTime);

	list<Object1*> _enemys;
};

