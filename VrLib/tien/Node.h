#pragma once

#include <list>
#include <vector>
#include <functional>

namespace vrlib
{
	namespace tien
	{
		class Component;

		class Node
		{
		protected:
			virtual void setTreeDirty() { parent->setTreeDirty(); };

		public:
			std::string name;

			Node* parent;
			std::list<Node*> children;


			std::vector<Component*> components;
			template<class T> T* getComponent()
			{
				for (auto c : components)
				{
					T* r = dynamic_cast<T*>(c);
					if (r) 
						return r;
				}
				return nullptr;
			}


			template<class T> Node* findNodeWithComponent()
			{
				if (getComponent<T>())
					return this;
				for (auto c : children)
				{
					Node* cn = c->findNodeWithComponent<T>();
					if (cn)
						return cn;
				}
				return nullptr;
			}


			Node(const std::string &name, Node* parent);


			void fortree(const std::function<void(Node*)> &callback);

		};

	}
}