#include <iostream>
#include <array>
#include <vector>


struct Box {
private:
    //длина, ширина и высота коробки в см
    int length, width, height;
//    int width;
//    int height;
    double weight; //масса коробки в кг
    int value;  //стоимость содержимого в копейках

public:

    void setLength(int length1) {
        if (length1 < 0) {
            throw "length can't be negative";
        } else {
            length = length1;
        }
    }

    int getLength() { return length; }

    void setWidth(int width1) {
        if (width1 < 0) {
            throw "width can't be negative";
        } else {
            width = width1;
        }
    }

    int getWidth() { return width; }

    void setHeight(int myHeight) {
        if (myHeight < 0) {
            throw "height can't be negative";
        } else {
            height = myHeight;
        }
    }

    int getHeight() { return height; }

    void setWeight(double myWeight) {
        if (myWeight < 0) {
            throw "weight can't be negative";
        } else {
            weight = myWeight;
        }
    }

    double getWeight() { return weight; }

    void setValue(int myValue) {
        if (myValue < 0) {
            throw "value can't be negative";
        } else {
            value = myValue;
        }
    }

    double getValue() { return value; }


    Box(int length1, int width1, int height1, double weight1, int value1) {

        setLength(length1);
        setWidth(width1);
        setHeight(height1);
        setWeight(weight1);
        setValue(value1);
    };


    // вычисляет суммарную стоимость содержимого всех коробок:
    int static getFinalValue(Box boxes[], int count) {
        int res = 0;
        for (int i = 0; i < count; i++) {
            res += boxes[i].getValue();
        }
        return res;
    }

    bool static checkSize(Box boxes[], int count, int size) {
        bool res = true;
        for (int i = 0; i < count; i++) {
            if (boxes[i].getHeight() + boxes[i].getLength() + boxes[i].getWidth() > size) {
                res = false;
//                i = count;
                return res;
            }
        }
        return res;
    }

    double static getMaxWeightWithMaxV(Box boxes[], int count, int maxV) {
        double maxW = -1;
        for (int i = 0; i < count; i++) {
            if (boxes[i].getWidth() * boxes[i].getLength() * boxes[i].getHeight() <= maxV) {
                if (boxes[i].getWeight() > maxW) {
                    maxW = boxes[i].getWeight();
                }
            }
        }
        return maxW;
    }


    bool static isInside(Box arr[], int n) {
        Box temp = {0, 0, 0, 0, 0};
//        bool res = true;

        for (int i = 1; i < n; i++) {

            for (int j = n - 1; j >= i; j--) {

                if (arr[j - 1].getLength() >= arr[j].getLength() &&
                    arr[j - 1].getWidth() >= arr[j].getWidth() &&
                    arr[j - 1].getHeight() >= arr[j].getHeight()) {

                    temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;

                }
            }
        }
        for (int i = 1; i < n; i++) {

            for (int j = n - 1; j >= i; j--) {
                if (arr[j - 1].getLength() == arr[j].getLength() ||
                    arr[j - 1].getWidth() == arr[j].getWidth() ||
                    arr[j - 1].getHeight() == arr[j].getHeight()) {
                    return false;
                }
            }
        }
        return true;

    }

};

//Операторы возвращают потоки как результат, чтобы работали цепочки вида
//cout << a << b;

std::istream &operator>>(std::istream &in, Box &box) {
    int length, width, height, value;
    double weight;
    in >> length >> width >> height >> value >> weight;
    box.setLength(length);
    box.setWidth(width);
    box.setHeight(height);
    box.setValue(value);
    box.setWeight(weight);
    return in;
}

std::ostream &operator<<(std::ostream &out, Box &box) {
    out << "length: " << box.getLength() << " width: " << box.getWidth() << " height: " << box.getHeight()
        << " value: " << box.getValue() << " weight: " << box.getWeight();
    return out;
}
//std::ostream &operator<<(std::ostream &os, const Box &b) {
//    return os << "length = " << b.length << " , width = " << b.width << ", height = " << b.height << std::endl;
//}

//std::istream &operator>>(std::istream &in, const Box &b, const int &length,
//        const int &height, const int &width, const int &value, const double &weight) {
//    return in >> b.length=length >> b.width=width >> b.height=height >> b.value = value >> b.weight=weight;
//}



//}
// оператор == сравнения двух коробок на равенство всех параметров.
//?норм ли НЕ писать const?
bool operator==(Box &b1, Box &b2) {
    return b1.getLength() == b2.getLength() && b1.getHeight() == b2.getHeight()
           && b1.getWidth() == b2.getWidth() && b1.getWeight() == b2.getWeight() && b1.getValue() == b2.getValue();
}


int main() {

    int n = 3;
    Box box3 = {1, 1, 1, 1, 50};
    Box box2 = {2, 2, 2, 2, 20};
    Box box1 = {3, 3, 3, 3, 10};
    Box box0 = {3, 3, 3, 3, 10};
    Box boxes[] = {box1, box2, box3};
    Box newBoxes[] = {box0, box1, box2, box3};
    Box wrongBoxes[] = {box2, box3, box1};
    bool g;
    bool k;
    g = Box::checkSize(boxes, 3, 2);
//    std::cout << g;
    g = Box::checkSize(boxes, 3, 30);
//    std::cout << g;
    int m;
    m = Box::getFinalValue(boxes, 3);
//    std::cout << m;
    double l;
    l = Box::getMaxWeightWithMaxV(boxes, 3, 10);
//    std::cout << l;
//    k = Box::isInside(boxes, 3);
//    std::cout <<"k = "<< k;

//#5
    g = Box::isInside(boxes, n);
    std::cout << " isInside: " << g << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "boxes[" << i << "]: " << boxes[i] << std::endl;
    }
    n = 4;
    g = Box::isInside(newBoxes, n);
    std::cout << " isInside: " << g << std::endl;
    n = 3;
    g = Box::isInside(wrongBoxes, n);
    std::cout << " isInside: " << g << std::endl;


    //#6
    bool f = box1 == box2;
    std::cout << "(expected true) f = " << f << std::endl;
    f = box0 == box1;
    std::cout << "(expected false)f = " << f << std::endl;

    std::cout << box1;
//    box1 = std::cin >> 1 >> 2 >> 3 >> 4 >> 5;

}

