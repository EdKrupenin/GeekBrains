//
// Created by edkru on 03.02.2022.
//

#ifndef LESSON4_BRIDGE_H
#define LESSON4_BRIDGE_H

// Implementor
class DrawingImplementor {
public:
    virtual void drawRectangle(double) = 0;
    virtual ~DrawingImplementor() {
    }
};

class drawBrush : public DrawingImplementor{
public:
    void drawRectangle(double ) override{
        std::cout << "Brush draw" << std::endl;
    }
};

class drawPencil : public DrawingImplementor{
public:
    void drawRectangle(double ) override{
        std::cout << "Pencil draw" << std::endl;
    }
};


// Abstraction
class Shape {
protected:
    DrawingImplementor* drawingType{};
public:
    explicit Shape(DrawingImplementor* type) : drawingType(type){};
    virtual void draw()= 0; // low-level
    virtual void resize(double pct) = 0; // high-level
    virtual ~Shape() {
    }
};

class Rectangle: public Shape {
    double _size{};
public:
    explicit Rectangle(DrawingImplementor* type, double size) : _size(size), Shape(type){};
    void draw() override{
        drawingType->drawRectangle(_size);
        std::cout << "size" << _size<<"* size"<<_size<<std::endl;
    }
    void resize(double pct) override{
        _size*=pct;
    }
    ~Rectangle() override= default;
};





#endif //LESSON4_BRIDGE_H
