#include "SceneNode.h"



SceneNode::SceneNode()
{
}


SceneNode::~SceneNode()
{
}
void SceneNode::attachChild(Ptr child)
{
	child->MyParent = this;
	MyChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto find = std::find_if(MyChildren.begin(), MyChildren.end()),
		[&](Ptr& p) -> bool {return p.get() == &node; });


	if (find != MyChildren.end())
	{

	}
}