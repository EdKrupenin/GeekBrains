//
// Created by edkru on 16.02.2022.
//
#pragma once
#include<iostream>
#include<fstream>
#include <vector>

struct playerInfo{
    float hp;
    int speed {};
    std::string name {};
};

class Memento {
private:
    playerInfo player;
public:
    Memento(float hp, int speed, const std::string &name) : player{hp,speed,name}{
        std::ofstream wf("player.dat", std::ios::out | std::ios::binary);
        if(!wf) {
            std::cout << "Error opening file";
        }
        wf.write((char *) &player, sizeof(playerInfo));
        wf.close();
    }
    Memento()= default;

    Memento(const Memento & m) {
        player = m.player;
    }

    playerInfo getValue() const {
        std::ifstream rf("student.dat", std::ios::out | std::ios::binary);
        if(!rf) {
            std::cout << "Error opening file";
        }
        playerInfo answer{};
        rf.read((char *) &answer, sizeof(playerInfo));
        rf.close();
        return answer;
    }
};

class Player{
private:
    class Impl;
    Impl* pImpl;
public:
    Player(float hp, int speed, const std::string &name);
    void changeSpeed(int change);
    void changeHp(float change);
    int getSpeed() const;
    float getHp() const;
    const std::string &getName() const;
    Memento createMemento();
    void reinstateMemento(Memento& mem);
};

class Game{
private:
    Player p;
    std::vector<Memento> mem;
    void print(){
        std::cout << "Player " << p.getName() << "has hp "<<p.getHp()<<" and has speed "
        <<p.getSpeed()<<" and Undos: " << mem.size() << std::endl;
    }
public:
    explicit Game(const Player &p) : p(p) {}

    void changeSpeed(int change){
        mem.push_back(p.createMemento());
        p.changeSpeed(change);
        print();
    }

    void changeHp(int change){
        mem.push_back(p.createMemento());
        p.changeHp(change);
        print();
    }

    void undo(){
        if (!mem.empty()){
            Memento m(mem[mem.size()-1]);
            mem.pop_back();
            p.reinstateMemento(m);
            print();
        } else
            std::cout << "Nothing to undo!" << std::endl;
    }
};
