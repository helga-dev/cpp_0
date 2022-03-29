//
// Created by User on 29.03.2022.
//

#ifndef CPP_PROJECT_0_BOX_H
#define CPP_PROJECT_0_BOX_H


class Box {
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
        bool res = true;

        for (int i = 1; i < n; i++) {

            for (int j = n - 1; j >= i; j--) {

                if (arr[j - 1].getLength() >= arr[j].getLength() &&
                    arr[j - 1].getWidth() >= arr[j].getWidth() &&
                    arr[j - 1].getHeight() >= arr[j].getHeight()) {
                    if (arr[j - 1].getLength() == arr[j].getLength() ||
                        arr[j - 1].getWidth() == arr[j].getWidth() ||
                        arr[j - 1].getHeight() == arr[j].getHeight()) {
                        return false;
                    }
                    temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;

//                    }
                }
            }

        }
        return res;
    }

};


#endif //CPP_PROJECT_0_BOX_H
