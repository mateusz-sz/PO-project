#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>
class SceneNode
{
public:
	SceneNode();
	~SceneNode();
	typedef std::unique_ptr<SceneNode> Ptr;

private:
	std::vector<Ptr> MyChildren;
	SceneNode* MyParent;
	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
};

