//
// Created by edkru on 09.02.2022.
//

#ifndef HOMEWORK6_TEMPLATE_METHOD_H
#define HOMEWORK6_TEMPLATE_METHOD_H

class DrawPicture{
public:
    void openFile(const std::string& filename){
        std::cout << "Open file " << filename << std::endl;
    }

    void final(){
        std::cout << "Drawing image complete" << std::endl;
    }

    virtual void readFile() = 0;

    virtual void draw() = 0;

    virtual void drawPicture(const std::string& filename) final {
        openFile(filename);
        readFile();
        draw();
        final();
    };
};

struct Pixel{
    int x{};
    int y{};
    std::string color{};
    void draw(){
        std::cout << "("<< x << ", " << y << ", " << color << ") ";
    }
};

class BitmapImage : public DrawPicture{        // Растровое изображение
private:
    std::vector<Pixel*> pixels{};     // это пиксели, которые хранятся в файле
    std::vector<Pixel> buffer{};      // это пиксели, которые мы читаем для отображение на экране
public:

    void readFile() override{
        for (const auto pixel: pixels) {
            buffer.push_back(*pixel);      // Имитируем чтение пикселей из файла в буфер
        }
    }

    void draw() override{
        for (const auto pixel: pixels) {
            pixel->draw();      // Рисуем каждый пиксель из буфера
        }
    }

};

struct Figure{
    int x{};
    int y{};
    std::string figure{};
    void draw(){
        std::cout << "("<< x << ", " << y << ", " << figure << ") ";
    }
};

class VectorImage : DrawPicture{        // Векторное изображение
private:
   std::vector<Figure*> figures{};     // это описание фигур, которые хранятся в файле
   std::vector<Figure> buffer{};       // это описание фигур, которые мы читаем для отображение на экране
public:
    void readFile() override {
        for (const auto figure: figures) {
            buffer.push_back(*figure);        // Имитируем чтение фигур из файла в буфер
        }
    };
    void draw() override{
         for (const auto figure: figures) {
             figure->draw();      // Рисуем каждую фигуру из буфера
         }
     }
};

#endif //HOMEWORK6_TEMPLATE_METHOD_H
