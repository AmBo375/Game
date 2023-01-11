#pragma once
#include <iostream>
#include <memory>
#include <bitset>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

class Comp;
class Entity;

inline size_t GetCompID() {
	static size_t LastID = 0;
	return LastID++;
}

template <typename T> inline size_t GetCompID() noexcept {
	static size_t typeID = GetCompID();
	return typeID;
}

constexpr size_t MaxComp = 32;

class Comp {
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Comp() {}
};

class Entity {
private:
	bool active = true;
	vector<unique_ptr<Comp>> comps;
	bitset<MaxComp> CompBS;
	array<Comp*, MaxComp> CompArr;
public:
	void update() {
		for (auto& c : comps) c->update();
		}
	void draw(){
		for (auto& c : comps) c->draw();
	}
	bool isActive() const { return active; }
	void destroy() { active = false; }

	template <typename T> bool hasComp() const {
		return CompBS[GetCompID<T>()];
	}

	template <typename T, typename... TArgs>
	T& AddComp(TArgs&&...mArgs) {
		T* c(new T(forward<TArgs>(mArgs)...));
		c->entity = this;
		unique_ptr<Comp> uPtr{ c };
		comps.emplace_back(move(uPtr));
		CompArr[GetCompID<T>()] = c;
		CompBS[GetCompID<T>()] = true;
		c->init();
		return *c;
	}

	template <typename T> T& GetComp() const {
		auto ptr(CompArr[GetCompID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

class Mngr {
private:
	vector <unique_ptr<Entity>> entities;
public:
	void update() {
		for (auto& e : entities) e->update();
	}
	void draw() {
		for (auto& e : entities) e->draw();
	}
	void refresh() {
		entities.erase(remove_if(begin(entities), end(entities),
			[](const unique_ptr<Entity>& mEntity) {
			return !mEntity->isActive();
			}), end(entities));
	}

	Entity& AddEnt() {
		Entity* e = new Entity();
		unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(move(uPtr));
		return *e;
	}
};
