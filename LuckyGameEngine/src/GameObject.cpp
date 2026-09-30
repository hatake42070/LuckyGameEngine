#include "GameObject.h"

void GameObject::AddComponent(Component* component)
{
	components.push_back(component);
	component->gameObject = this;
}

void GameObject::Start()
{
	for (Component* component : components)
	{
		component->Start();
	}
}

void GameObject::Update()
{
	for (Component* component : components)
	{
		component->Update();
	}
}

void GameObject::Draw()
{
	for (Component* component : components)
	{
		component->Draw();
	}
}