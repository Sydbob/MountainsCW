#pragma once

class Mountain {

public:
	//2 constructors: first basic, 2nd custom
	Mountain();
	Mountain(string name, int height);

	
	void SetHeight();
	void SetName();

	string GetName() { return name; }
	int GetHeight() { return height; }

private:
	string name;
	int height;
};

