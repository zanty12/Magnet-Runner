#pragma once
class Scene
{
	public:
	Scene() = default;
	~Scene() = default;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void* GetInstance() = 0;
};

