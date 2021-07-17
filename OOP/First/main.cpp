#include <iostream>
#include <cstdint>

class Power{
    double first = 0;
    double second = 0;
public:
    Power(double first, double second) : first(first), second(second)
    {

    }
    void setValue (double first, double second) {
        this->first = first;
        this->second = second;
    }
    double calculate(){
        return pow(first,second);
    }
};

class RGBA{
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:
    RGBA(){}
    RGBA(uint8_t red,uint8_t green,uint8_t blue,uint8_t alpha):
    m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {}
    void print(){
        std::cout << "Red = " << m_red <<", Green = "<< m_green<<", Blue = "<< m_blue<<", Alpha = "<<m_alpha<<" ;"<<std::endl;
    }
};

class Stack{
    int s_length = 10;
    int* s_array = new int[s_length];
    int s_index = -1;
public:
    ~Stack(){
        delete s_array;
    }

    void reset(){
        s_index = -1;
        for (int i = 0; i < s_length; ++i) {
            s_array[i] = 0;
        }
    }
    bool push(int value){
        s_index++;
        if(s_index < s_length){
            s_array[s_index] = value;
            return true;
        }
        return false;
    }
    int pop(){
        if(s_index<0){
            std::cout<<"stack is empty!!!"<<std::endl;
            return -1;
        }
        else{
            int answer = s_array[s_index];
            s_index--;
            return answer;
        }
    }

    void print(){
        std::cout << "( ";
        for (int i = 0; i <= s_index; i++) {
            std::cout << s_array[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};

int main() {
    Power power(2,2);
    std::cout << power.calculate() << std::endl;
//------------------------------------------------//
    RGBA color(128,198,255,255);
    color.print();
//-----------------------------------------------//
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
