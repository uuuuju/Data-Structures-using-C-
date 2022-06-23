class rectangleType
{
//function declarations
public:
		void setDimension(double l, double w);
				//Function to set the length and width of the rectangle.
				//Postcondition: length = l; width = w;
		double getLength() const;
				//Function to return the length of the rectangle.
				//Postcondition: The value of length is returned.
		double getWidth() const;
				//Function to return the width of the rectangle.
				//Postcondition: The value of width is returned.
		double area() const;
				//Function to return the area of the rectangle.
				//Postcondition: The area of the rectangle is calculated
				// and returned.
		double perimeter() const;
				//Function to return the perimeter of the rectangle.
				//Postcondition: The perimeter of the rectangle is
				// calculated and returned.
		void print() const;
			//Function to output the length and width of the rectangle.
		
    rectangleType();
			//default constructor
			//Postcondition: length = 0; width = 0;
		rectangleType(double l, double w);
			//constructor with parameters
			//Postcondition: length = l; width = w;
private:
		double length;
		double width;
};

//function definitions
void rectangleType::setDimension(double l, double w)
{
		if (l >= 0)
			length = l;
		else
			length = 0;
		if (w >= 0)
			width = w;
		else
			width = 0;
}
double rectangleType::getLength() const
{
	return length;
}
double rectangleType::getWidth() const
{
	return width;
}
double rectangleType::area() const
{
	return length * width;
}
double rectangleType::perimeter() const
{
	return 2 * (length + width);
}

void rectangleType::print() const
{
		cout << "Length = " << length
		<< "; Width = " << width;
}
rectangleType::rectangleType(double l, double w)
{
		setDimension(l, w);
}
rectangleType::rectangleType()
{
		length = 0;
		width = 0;
}

//class boxtype derived from class rectangletype
class boxType: public rectangleType
{
public:
		void setDimension(double l, double w, double h);
				//Function to set the length, width, and height of the box.
				//Postcondition: length = l; width = w; height = h;
		double getHeight() const;
				//Function to return the height of the box.
				//Postcondition: The value of height is returned.
		double area() const;
				//Function to return the surface area of the box.
				//Postcondition: The surface area of the box is
				// calculated and returned.
		double volume() const;
				//Function to return the volume of the box.
				//Postcondition: The volume of the box is calculated and
				// returned.
		void print() const;
				//Function to output the length, width, and height of a box.
		boxType();
				//Default constructor
				//Postcondition: length = 0; width = 0; height = 0;
		boxType(double l, double w, double h);
				//Constructor with parameters
				//Postcondition: length = l; width = w; height = h;
private:
		double height;
};

//function declarations
void boxType::print() const
{
		rectangleType::print();
		cout << "; Height = " << height;
}
//in the preceding definition of the function setDimension, a call to the
//member function setDimension of the class rectangleType is preceded by the
//name of the class and the scope resolution operator, even though the class boxType
//overloads—not overrides—the function setDimension
//void boxType::setDimension(double l, double w, double h)
{
		rectangleType::setDimension(l, w);
		if (h >= 0)
			height = h;
		else
			height = 0;
}

double boxType::getHeight() const
{
    return height;
}

double boxType::area() const
{
			return 2 * (getLength() * getWidth()
			+ getLength() * height
			+ getWidth() * height);
}

double boxType::volume() const
{
    return rectangleType::area() * height;
}

boxType::boxType()
{
height = 0.0;
}

boxType::boxType(double l, double w, double h)
: rectangleType(l, w)
{
if (h >= 0)
height = h;
else
height = 0;
}

rectangleType myRectangle(5.0, 3.0);
boxType myBox(6.0, 5.0, 4.0);
