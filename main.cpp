#include "shape.h"
#include "list.h"
#include "lib.h"

using namespace std;

int main()
{
    const int randomAmount = 30;
    const int maxLetter = 10;
    srand(time(NULL));

    linkedList<char *> names;
    linkedList<TwoDShape *> shapes;

    for (int i = 0; i < randomAmount; i++)
    {
        char *name = new char[maxLetter + 1];
        int count = rand() % 10 + 1;
        for (int j = 0; j < count; j++)
        {
            name[j] = 'a' + rand() % 26;
        }
        name[count] = '\0';

        names.add(name);

        // Нэрнүүдийг хэвлэх
        // cout << name << endl;
    }

    for (int i = 0; i < randomAmount; i++)
    {
        cout << endl;
        TwoDShape::getCount();
        cout << endl;
        int id = rand() % 3 + 1;
        int x = rand() % 21 - 10;
        int y = rand() % 21 - 10;
        int a = rand() % 10 + 1;

        switch (id)
        {
        case 1:
            shapes.add(new Triangle(x, y, a, names.get(i)));
            break;
        case 2:
            shapes.add(new Square(x, y, a, names.get(i)));
            break;
        case 3:
            shapes.add(new Circle(x, y, a, names.get(i)));
            break;
        }
    }

    
    cout << "AREA SORTING------------------------------" << endl;
    TwoDBusiness::areaSort(shapes);
    cout << endl;

    for (int i = 0; i < randomAmount; i++)
    {
        cout << "Area: " << shapes.get(i)->getArea() << endl;
        shapes.get(i)->print();
        cout << endl;
    }

    cout << "PERIMETER SORTING------------------------------" << endl;
    TwoDBusiness::perimeterSort(shapes);

    for (int i = 0; i < randomAmount; i++)
    {
        cout << "Perimeter: " << shapes.get(i)->getPerimeter() << endl;
        shapes.get(i)->print();
        cout << endl;
    }

    for (int i = 0; i < randomAmount; i++)
    {
        delete shapes.get(i);
        delete[] names.get(i);
        cout << endl;
        TwoDShape::getCount();
        cout << endl;
    }
}