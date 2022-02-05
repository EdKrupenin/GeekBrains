#include <utility>

//
// Created by krupenin on 31.01.2022.
//

#ifndef UNTITLED_ADAPTER_H
#define UNTITLED_ADAPTER_H

class IShape{
public:
    virtual void scale(double scale_percentage) = 0;// Масштабируем фигуру
    virtual void rotate(double angle) = 0;          // Поворачиваем фигуру
    virtual void flip() = 0;                        // Отражаем фигуру
};

class Figure: IShape{
private:
    int width;
    int height;
    double angle;
    bool isFlipped;
public:
    Figure(int width, int height) : width(width), height(height), angle(0.0), isFlipped(false) {}

    void scale(double scale_percentage) override {
        width *= scale_percentage;
        height *= scale_percentage;
    }

    void rotate(double angle) override {
        angle += angle;
    }

    void flip() override {
        isFlipped = !isFlipped;
    }
};

class IText{
    virtual void newSize(int size) = 0;   // Изменяем размер шрифта текста
    virtual void rotate(double angle) = 0;   // Поворачиваем текст
    virtual void reverse() = 0;              // Изменяем направление текста
};

class Text: IText{
private:
    int size;
    double angle;
    bool isReversed;
    std::string text;
public:
    Text(const std::string text, int size, double angle, bool isReversed) : text(text), size(size), angle(0.0), isReversed(false) {}

private:
    void newSize(int newSize) override {
        size = newSize;
    }

    void rotate(double newAngle) override {
        angle = newAngle;
    }

    void reverse() override {
        for (int i = 0; i < text.size()/2; ++i) {
            char c = text[i];
            text[i] = text[text.size() - 1 - i];
            text[text.size() - 1 - i] = c;
        }
    }
};

class FiqureAdapter : IText {
    Figure _figure;
public:
    explicit FiqureAdapter(Figure figure) : _figure(std::move(figure)) {}
    void newSize(int size) override{
        _figure.scale(size);
    }
    void rotate(double newAngle) override {
        _figure.rotate(newAngle);
    }

    void reverse() override {
        _figure.flip();
    }
};
/// Теперь фигуры могут работать с методами текста, через адаптер

#endif //UNTITLED_ADAPTER_H
