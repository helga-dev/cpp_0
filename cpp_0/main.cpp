#include <iostream>
#include <array>
#include <vector>


struct Box {
private:

//длина, ширина и высота коробки в см
    int length, width, heigth;
//    int width;
//    int heigth;
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
            throw "heigth can't be negative";
        } else {
            heigth = myHeight;
        }
    }

    int getHeight() { return heigth; }

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


//    bool static isInside(Box b[], int size) {//коробку в коробку
//        int minLen;//длина
//        int minWid;//ширина
//        int minHei;//высота
//        int memory = 0;
//        Box c[size];
//        Box d = Box(2147483647, 2147483647, 2147483647, 0, 0);
//
//        for (int i = 0; i < size; i++) {//копия ориг массива
//            c[i] = b[i];
//        }
//
//        for (int j = 0; j < size; j++) {
//            minLen = 2147483647;
//            minHei = 2147483647;
//            minWid = 2147483647;
//            for (int i = j + 1; i < size; i++) {//найти самую маленькую и запомнить ее индекс
//                if(c[i].length == c[j].length || c[i].width == c[j].width || c[i].heigth == c[j].heigth){
//                    std::cout << "1";
//                    return false;
//                }
//                if((b[i].length < b[j].length) && (b[i].width > b[j].width) && (b[i].heigth > b[j].heigth) ||
//                   (b[i].length > b[j].length) && (b[i].width < b[j].width) && (b[i].heigth > b[j].heigth) ||
//                   (b[i].length > b[j].length) && (b[i].width > b[j].width) && (b[i].heigth < b[j].heigth)){
//                    std::cout << "2";
//                    return false;
//                }
//                if ((minLen > c[i].length) &&
//                    (minWid > c[i].width) &&
//                    (minHei > c[i].heigth)) {
//
//                    minLen = c[i].length;
//                    minWid = c[i].width;
//                    minHei = c[i].heigth;
//                    memory = i;
//
//                }
//                else continue;
//            }
//
//            c[memory] = d;
//        }
//        //if что разные и там массив коробка которая да не большая и если будут разные показатели 131 и 222
//
//        return true;
//    }
//    bool static isInside(Box arr[], int n) {
//        Box temp = {0, 0, 0, 0, 0};
////        bool res = true;
//
//        for (int i = 1; i < n; i++) {
//
//            for (int j = n - 1; j >= i; j--) {
//
//                if (arr[j - 1].getLength() >= arr[j].getLength() &&
//                    arr[j - 1].getWidth() >= arr[j].getWidth() &&
//                    arr[j - 1].getHeight() >= arr[j].getHeight()) {
//
//                    temp = arr[j];
//                    arr[j] = arr[j - 1];
//                    arr[j - 1] = temp;
//
//                }
//            }
//        }
//        for (int i = 1; i < n; i++) {
//
//            for (int j = n - 1; j >= i; j--) {
//                if (arr[j - 1].getLength() == arr[j].getLength() ||
//                    arr[j - 1].getWidth() == arr[j].getWidth() ||
//                    arr[j - 1].getHeight() == arr[j].getHeight()) {
//                    return false;
//                }
//            }
//        }
//        return true;
//
//    }

};

//Операторы возвращают потоки как результат, чтобы работали цепочки вида
//cout << a << b;

friend std::istream &operator>>(std::istream &in, Box &box) {
//    int length, width, height, value;
//    double weight;
    in >> box.getLength();
    in >> box.getWidth() >> box.getHeight() >> box.getValue() >> box.getWeight();

    return in;
}

std::ostream &operator<<(std::ostream &out, Box &box) {
    out << "length: " << box.getLength() << " width: " << box.getWidth() << " heigth: " << box.getHeight()
        << " value: " << box.getValue() << " weight: " << box.getWeight();
    return out;
}
//std::ostream &operator<<(std::ostream &os, const Box &b) {
//    return os << "length = " << b.length << " , width = " << b.width << ", heigth = " << b.heigth << std::endl;
//}

//std::istream &operator>>(std::istream &in, const Box &b, const int &length,
//        const int &heigth, const int &width, const int &value, const double &weight) {
//    return in >> b.length=length >> b.width=width >> b.heigth=heigth >> b.value = value >> b.weight=weight;
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

////#5
//    g = Box::isInside(boxes, n);
//    std::cout << " isInside: " << g << std::endl;
//    for (int i = 0; i < n; i++) {
//        std::cout << "boxes[" << i << "]: " << boxes[i] << std::endl;
//    }
//    n = 4;
//    g = Box::isInside(newBoxes, n);
//    std::cout << " isInside: " << g << std::endl;
//    n = 3;
//    g = Box::isInside(wrongBoxes, n);
//    std::cout << " isInside: " << g << std::endl;
//

    //#6
    bool f = box1 == box2;
    std::cout << "(expected 0) f = " << f << std::endl;
    f = box0 == box1;
    std::cout << "(expected 1) f = " << f << std::endl;

//    #7
    std::cout << box1;
    std::cin >> box1;
}

