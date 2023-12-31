using namespace std;

class Shape {
protected:
    float L, H;

public:
    virtual void read() {
        cout << "Enter Length (L): ";
        cin >> L;
        cout << "Enter Height (H): ";
        cin >> H;
    }

    virtual float area() const = 0;

    void display() const {
        cout << "Area: " << this->area() << endl;
    }
};

class Square : virtual public Shape {
public:
    float area() const {
        return L * L;
    }
};

class Triangle : virtual public Shape {
public:
    float area() const {
        return 0.5 * L * H; // L being the base
    }
};

class SqPyramid : public Square, public Triangle {
public:
    float area() const {
        return Square::area() + (4 * Triangle::area());
    }
};

int main() {
    Shape* shapes[3];

    Square square;
    Triangle triangle;
    SqPyramid sqPyramid;

    shapes[0] = &square;
    shapes[1] = &triangle;
    shapes[2] = &sqPyramid;


    for (int i = 0; i < 3; ++i) {
        shapes[i]->read();
        shapes[i]->display();
        cout << endl;
    }

    return 0;
}
