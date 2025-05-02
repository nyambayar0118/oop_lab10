#include "shape.h"

using namespace std;

// Цэгийн байгуулагч функцүүд
Point::Point()
{
    setX(0);
    setY(0);
}

Point::Point(float x, float y)
{
    setX(x);
    setY(y);
}

// Цэгийн координатуудын setter функцүүд
void Point::setX(float x)
{
    this->coordX = x;
}
void Point::setY(float y)
{
    this->coordY = y;
}

// Цэгийн координатуудын getter функцүүд
float Point::getX() { return coordX; };
float Point::getY() { return coordY; };

int TwoDShape::count = 0;

int TwoDShape::getCount()
{
    cout << "Үүссэн дүрсийн тоо: " << count << endl;
    return count;
}

void TwoDShape::incCount()
{
    count++;
}

TwoDShape::TwoDShape()
{
    cout << "TwoDShape default contructor" << endl;
}

TwoDShape::TwoDShape(float ax, float ay, float side, const char *name)
{
    TwoDShape::incCount();
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->pointA = Point(ax, ay);

    this->side = side;
    cout << "TwoDShape parameterized contructor" << endl;
}
TwoDShape::~TwoDShape()
{
    count--;
    cout << "TwoDShape destructor" << endl;
};

// Гурвалжны периметрийг буцаах функц
float Triangle::getPerimeter()
{
    return 3 * side;
}
// Гурвалжны талбайг буцаах функц
float Triangle::getArea()
{
    return sqrt(3) * side * side / 4;
}

// Гурвалжны анхдагч байгуулагч функц
Triangle::Triangle()
{
    this->name = NULL;
    this->side = 0;
    this->pointA = Point(0, 0);
    this->pointB = Point(0, 0);
    this->pointC = Point(0, 0);
}
// Гурвалжны байгуулагч функц
Triangle::Triangle(float ax, float ay, float side, const char *name) : TwoDShape(ax, ay, side, name)
{
    cout << "Triangle parameterized constructor" << endl;
    // Гурвалжны гурван оройн цэгийн объект байгуулаад байгуулагчаар нь утгуудыг тооцоолж онооно
    this->pointA = Point(ax, ay);
    this->pointB = Point(ax - (side / 2), ay + (sqrt(3) * side / 2));
    this->pointC = Point(ax + (side / 2), ay + (sqrt(3) * side / 2));
};

// Гурвалжны устгагч функц
Triangle::~Triangle()
{
    // Нэрийг хадгалахын тулд нөөцөлсөн ойг чөлөөлнө
    if (this->name)
    {
        cout << name << " triangle deleted" << endl;
        delete[] this->name;
    }
}

// Гурвалжны цэгийн координатуудыг хэвлэнэ
void Triangle::print()
{
    cout << this->name << " nertei gurvaljnii medeelel:" << endl
         << "Point A: " << this->pointA.getX() << ", " << this->pointA.getY() << endl
         << "Point B: " << this->pointB.getX() << ", " << this->pointB.getY() << endl
         << "Point C: " << this->pointC.getX() << ", " << this->pointC.getY() << endl
         << "Side: " << this->side << endl;
}

// Квадратын периметрийг буцаах функц
float Square::getPerimeter()
{
    return 4 * side;
}
// Квадратын талбайг буцаах функц
float Square::getArea()
{
    return side * side;
}

// Квадратын анхдагч байгуулагч функц
Square::Square()
{
    this->name = NULL;
    this->side = 0;
    this->pointA = Point(0, 0);
    this->pointB = Point(0, 0);
    this->pointC = Point(0, 0);
    this->pointD = Point(0, 0);
}
// Квадратын байгуулагч функц
Square::Square(float ax, float ay, float s, const char *squareName) : TwoDShape(ax, ay, s, squareName)
{
    cout << "Square parameterized constructor" << endl;
    // Квадратын дөрвөн оройн цэгийн объект байгуулаад байгуулагчаар нь утгуудыг тооцоолж онооно
    this->pointA = Point(ax, ay);
    this->pointB = Point(ax + side, ay);
    this->pointC = Point(ax + side, ay + side);
    this->pointD = Point(ax, ay + side);
}

// Квадратын устгагч функц
Square::~Square()
{
    // Нэрийг хадгалахын тулд нөөцөлсөн ойг чөлөөлнө
    if (this->name)
    {

        cout << name << " square deleted" << endl;
        delete[] this->name;
    }
}

// Квадратын цэгийн координатуудыг хэвлэнэ
void Square::print()
{
    cout << name << " nertei square:" << endl;
    cout << "Point A: (" << pointA.getX() << ", " << pointA.getY() << ")" << endl;
    cout << "Point B: (" << pointB.getX() << ", " << pointB.getY() << ")" << endl;
    cout << "Point C: (" << pointC.getX() << ", " << pointC.getY() << ")" << endl;
    cout << "Point D: (" << pointD.getX() << ", " << pointD.getY() << ")" << endl;
    cout << "Side: " << this->side << endl;
}

// Тойргийн анхдагч байгуулагч функц
Circle::Circle()
{
    this->name = NULL;
    this->side = 0;
    this->pointA = Point(0, 0);
}

// Тойргийн байгуулагч функц
Circle::Circle(float cx, float cy, float r, const char *name) : TwoDShape(cx, cy, r, name)
{
    cout << "Circle parameterized constructor" << endl;
}

// Тойргийн устгагч функц
Circle::~Circle()
{
    // Нэрийг хадгалахын тулд нөөцөлсөн ойг чөлөөлнө
    if (this->name)
    {
        cout << name << " circle deleted" << endl;
        delete[] this->name;
    }
}
// Тойргийн талбайг буцаах функц
float Circle::getArea()
{
    return M_PI * side * side;
}
// Тойргийн периметрийг буцаах функц
float Circle::getPerimeter()
{
    return 2 * M_PI * side;
}
// Тойргийн цэг болон радиусыг хэвлэх функц
void Circle::print()
{
    cout << this->name << " nertei toirgiin medeelel:" << endl
         << "Tuv: " << this->pointA.getX() << ", " << this->pointA.getY() << endl
         << "Radius: " << this->side << endl;
}

void TwoDBusiness::areaSort(linkedList<TwoDShape *> &shapes)
{
    int n = shapes.length();

    if (n < 2)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int minIndex = 0;

        for (int j = n - 1 - i; j > 0; j--)
        {
            if (shapes.get(j)->getArea() < shapes.get(minIndex)->getArea())
            {
                minIndex = j;
            }
        }

        TwoDShape *minShape = shapes.get(minIndex);

        shapes.deleteL(minIndex);

        shapes.add(minShape);
    }
}

void TwoDBusiness::perimeterSort(linkedList<TwoDShape *> &shapes)
{
    int n = shapes.length();

    if (n < 2)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int minIndex = 0;

        for (int j = n - 1 - i; j > 0; j--)
        {
            if (shapes.get(j)->getPerimeter() < shapes.get(minIndex)->getPerimeter())
            {
                minIndex = j;
            }
        }
        TwoDShape *minShape = shapes.get(minIndex);
        shapes.deleteL(minIndex);
        shapes.add(minShape);
    }
};