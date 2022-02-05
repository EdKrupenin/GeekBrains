//
// Created by krupenin on 31.01.2022.
//

#ifndef UNTITLED_STRATEGY_H
#define UNTITLED_STRATEGY_H

#include <iostream>
#include <fstream>

///Прородитель делителе экрана
class DivideByScreen{
public:
    virtual ~DivideByScreen() = default;;
    virtual void use(size_t EditorWidth = 0) = 0;
};

///Различные вариации деления

class DivideByScreenWidth : public DivideByScreen{
public:
    void use(size_t EditorWidth) override{
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
    }
};

class DivideBySentence : public DivideByScreen{
public:
    void use(size_t EditorWidth = 0) override{
        std::cout << "Divided by Sentences" << std::endl;
    }
};

class DivideByUserWidth: public DivideByScreen{
public:
    void use(size_t userWidth) override{
        std::cout << "DivideByScreenWidth by screen width = " << userWidth << std::endl;
    }
};

///Управляющий класс
class DivideStrategy{
protected:
    DivideByScreen* divideByScreen;
public:
    virtual void Divide(size_t userWidth = 0) = 0;
    virtual void setStrategy(DivideByScreen*) = 0;
    virtual ~DivideStrategy() {}
};


///Текстовый редактор который использует стратегии деления
class TextEditor: DivideStrategy{
private:
    size_t EditorWidth;
    std::string all_text;
    DivideByScreen* divideByScreen;
public:
    TextEditor(){};
    TextEditor(const std::string &text) : all_text(text) {};

    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
            {
                all_text+=line;
            }
        }
    }

    void PrintText() const{
        std::cout << all_text << std::endl;
    }

    void setStrategy(DivideByScreen* strategy) override{
        divideByScreen = strategy;
    }

    void Divide(size_t userWidth = 0) override {
        divideByScreen->use(userWidth);
    }
};


#endif //UNTITLED_STRATEGY_H
