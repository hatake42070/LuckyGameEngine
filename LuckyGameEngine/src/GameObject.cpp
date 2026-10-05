#include "GameObject.h"

GameObject::GameObject(float x, float y, float z) : x(x), y(y), z(z)
{
}

void GameObject::AddComponent(std::unique_ptr<Component> component)
{
	component->gameObject = this;
	components.push_back(std::move(component));
}

void GameObject::Start()
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->Start();
	}
}

void GameObject::Update()
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->Update();
	}
}

void GameObject::Draw()
{
	for (std::unique_ptr<Component>& component : components)
	{
		component->Draw();
	}
}