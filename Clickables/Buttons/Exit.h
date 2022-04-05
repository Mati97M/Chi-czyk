#ifndef EXIT_H
#define EXIT_H


class Exit: public Button
{
	void draw();	
	void OnClick() { hosting_surface->close(); }
	
	Exit(std::string name, float x, float y, int w, int h, std::string normal, std::string hoovered) : Button(name, x, y, w, h, normal, hoovered)
	{}

	friend class Board;
};

#endif // !EXIT_H