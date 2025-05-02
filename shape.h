#ifndef SHAPE_H
#define SHAPE_H

#include "lib.h"
#include "list.h"

using namespace std;

// Дүрсийг бүтээх цэг класс
class Point
{
protected:
    // Цэгийн х координат
    float coordX;
    // Цэгийн у координат
    float coordY;

    // Цэгийн байгуулагч функцүүд
public:
    Point();

    Point(float x, float y);

    // Цэгийн координатуудын setter функцүүд
    void setX(float x);
    void setY(float y);

    // Цэгийн координатуудын getter функцүүд
    float getX();
    float getY();
};

// Дүрс класс
class Shape
{
protected:
    // Дүрсийн нэр
    char *name;
    // Дүрсийн үндсэн цэг
    Point pointA;
    // Дүрсийн тал/радиусын урт
    float side;

public:
    // Дүрсийн мэдээллийг хэвлэх функц
    virtual void print() = 0;
};

// Хавтгай буюу 2 хэмжээст дүрс класс
class TwoDShape : public Shape
{
protected:
static int count;

public:
    // Дүрсийн периметрийг буцаах функц
    virtual float getPerimeter() = 0;
    // Дүрсийн талбайг буцаах функц
    virtual float getArea() = 0;
    TwoDShape();

    TwoDShape(float ax, float ay, float side, const char *name);
    virtual ~TwoDShape();

    static int getCount();
    static void incCount();
};

// Зөв гурвалжин класс
class Triangle : public TwoDShape
{
protected:
    // Гурвалжны зүүн доод цэг
    Point pointB;
    // Гурвалжны баруун доод цэг
    Point pointC;

public:
    // Гурвалжны периметрийг буцаах функц
    float getPerimeter();
    // Гурвалжны талбайг буцаах функц
    float getArea();

    // Гурвалжны анхдагч байгуулагч функц
    Triangle();
    // Гурвалжны байгуулагч функц
    Triangle(float ax, float ay, float side, const char *name);

    // Гурвалжны устгагч функц
    ~Triangle();

    // Гурвалжны цэгийн координатуудыг хэвлэнэ
    void print();
};

// Квадрат класс
class Square : public TwoDShape
{
protected:
    // Квадратын баруун дээд, баруун доод, зүүн доод цэг
    Point pointB, pointC, pointD;

public:
    // Квадратын периметрийг буцаах функц
    float getPerimeter();
    // Квадратын талбайг буцаах функц
    float getArea();

    // Квадратын анхдагч байгуулагч функц
    Square();
    // Квадратын байгуулагч функц
    Square(float ax, float ay, float s, const char *squareName);

    // Квадратын устгагч функц
    ~Square();

    // Квадратын цэгийн координатуудыг хэвлэнэ
    void print();
};

// Тойрог класс
class Circle : public TwoDShape
{

public:
    // Тойргийн анхдагч байгуулагч функц
    Circle();

    // Тойргийн байгуулагч функц
    Circle(float cx, float cy, float r, const char *name);

    // Тойргийн устгагч функц
    ~Circle();
    // Тойргийн талбайг буцаах функц
    float getArea();
    // Тойргийн периметрийг буцаах функц
    float getPerimeter();
    // Тойргийн цэг болон радиусыг хэвлэх функц
    void print();
};

// Бизнес класс
class TwoDBusiness
{
public:
    static void areaSort(linkedList<TwoDShape*>& shapes);
    static void perimeterSort(linkedList<TwoDShape*>& shapes);
};

#endif