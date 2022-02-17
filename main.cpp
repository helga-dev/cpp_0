#include <iostream>

int main() {

}
//дополнительно можно разобраться с тестами(не обязательно)
    struct Box {
private:
    //длина, ширина и высота коробки в см
        int length;
        int width;
        int height;
        double weight; //масса коробки в кг
        int value;  //стоимость содержимого в копейках

public:
    // использовать для исключений try catch?
    Box (int length1, int width1, int height1, double weight1, int value1){
        if (length1 < 0) {
            throw "length can't be negative";
        }
        else {
            length = length1;
        }
        if (width1 < 0) {
            throw "width can't be negative";
        }
        else {
            width = width1;
        }
        if (height1 < 0) {
            throw "height can't be negative";
        }
        else {
            height = height1;
        }

        if (weight1 < 0) {
            throw "weight can't be negative";
        }
        else {
            weight = weight1;
        }
        if (value < 0) {
            throw "value can't be negative";
        }
        else {
            value = value1;
        }
    };

    // вычисляет суммарную стоимость содержимого всех коробок:
    double get_final_value(Box boxes[], int count){
        for(Box box: ){

        }
    }