#include <iostream>
#include <array>
#include <vector>


//дополнительно можно разобраться с тестами(не обязательно)
struct Box {
//private:
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

    bool static BubbleSort(Box arr[], int n){

        Box temp = {0, 0, 0, 0, 0};
        bool res = true;

        for (int i = 1; i < n; i++){

            for (int j = n-1; j >= i; j--){

                if (arr[j-1].getLength() >= arr[j].getLength() &&
                arr[j-1].getWidth() >= arr[j].getWidth() &&
                arr[j-1].getHeight() >= arr[j].getHeight()){
                    if(arr[j-1].getLength() == arr[j].getLength() ||
                       arr[j-1].getWidth() == arr[j].getWidth() ||
                       arr[j-1].getHeight() == arr[j].getHeight()){
                        return false;

                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;

                }
            }
        }

    }
        return res;
    }



    bool static isInside(Box boxes[], int count) {
        int boxLength[]{};

        bool res = true;

        BubbleSort(boxes, count);


        return res;
    }

};

std::ostream& operator << (std::ostream &os, const Box &b){
    return os <<"length = " << b.length <<" , width = "<<b.width<<", height = "<<b.height << std::endl;
}

int main() {

    Box box3 = {1, 1, 1, 1, 50};
    Box box2 = {2, 2, 2, 2, 20};
    Box box1 = {3, 3, 3, 3, 10};
    Box boxes[] = {box1, box2, box3};
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
    g = Box::BubbleSort(boxes,3);
//    std::cout <<"boxes[0]: " << boxes[0].getLength() << " " << boxes[0].getHeight() <<" "<< boxes[0].getWidth()<<std::endl;
//    std::cout <<"boxes[1]: " << boxes[1].getLength() << " " << boxes[1].getHeight() <<" "<< boxes[1].getWidth()<<std::endl;
//    std::cout <<"boxes[2]: " << boxes[2].getLength() << " " << boxes[2].getHeight() <<" "<< boxes[2].getWidth()<<std::endl;
//    std::cout << boxes[0] << " " << boxes[1] << " " << boxes[2] << std::endl;
    std::cout << g << std::endl;





}

//void static BubbleSort(Box arr[], int n){
//
//    Box temp = {0, 0, 0, 0, 0};
//
//    for (int i = 1; i < n; i++){
//
//        for (int j = n-1; j >= i; j--){
//
//            if (arr[j-1].getLength() >= arr[j].getLength() &&
//                arr[j-1].getWidth() >= arr[j].getWidth() &&
//                arr[j-1].getHeight() >= arr[j].getHeight()){
//
//                temp = arr[j];
//                arr[j] = arr[j-1];
//                arr[j-1] = temp;
//
//            }
//        }
//    }
//}
