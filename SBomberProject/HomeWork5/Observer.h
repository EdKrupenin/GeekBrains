//
// Created by edkru on 04.02.2022.
//

#ifndef HOMEWORK5_OBSERVER_H
#define HOMEWORK5_OBSERVER_H
class ISubject {
public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void changeAnnouncment() =0;
};

class ICitizen{
public:
    virtual void listen(int, std::string) = 0;
    virtual void RemoveMeFromTheList() = 0 ;
};

class Doctor: public ICitizen{
private:
    int hearingPower = 100;
    ICitizen subject_;
public:
    Doctor(const ICitizen& subject) : subject_(subject){}
    void listen(int voicePower, std::string msg) override {
        if(voicePower >= hearingPower){
            std::cout<<msg<<std::endl;
        }
    }
    void RemoveMeFromTheList(){
        subject_.Detach(this);
        std::cout << "Observer Doctor removed from the list.\n";
    }
};

class Blacksmith: public ICitizen{
private:
    int hearingPower = 30;
public:
    Blacksmith(const ICitizen& subject) : subject_(subject){}
    void listen(int voicePower, std::string msg) override {
        if(voicePower >= hearingPower){
            std::cout<<msg<<std::endl;
        }
    }
    void RemoveMeFromTheList(){
        subject_.Detach(this);
        std::cout << "Observer Blacksmith removed from the list.\n";
    }
};

class Child: public ICitizen{
private:
    int hearingPower = 50;
public:
    Child(const ICitizen& subject) : subject_(subject){}
    void listen(int voicePower, std::string msg) override {
        if(voicePower >= hearingPower){
            std::cout<<msg<<std::endl;
        }
    }
    void RemoveMeFromTheList(){
        subject_.Detach(this);
        std::cout << "Observer Child removed from the list.\n";
    }
};

class Herald : ISubject{
private:
    int voicePower{};
    std::string announcement{};
    std::vector<ICitizen*> citizens{};
public:
    Herald() : citizens(citizens) {
        citizens = {new Doctor, new Child, new Child};
    }

    void Attach(ICitizen *observer) override {
        list_observer_.push_back(observer);
    }
    void Detach(ICitizen *observer) override {
        list_observer_.remove(observer);
    }

    double getVoicePower(){
        return voicePower;
    };
    std::string getAnnouncement(){
        return announcement;
    }
    void setVoicePower(int voice){
        voicePower = voice;
    };
    void setAnnouncement(std::string _announcement){
        announcement = _announcement;
    }

    void changeAnnouncment(){
        voicePower = getVoicePower();
        announcement = getAnnouncement();
        for(const auto citizen : citizens){
            citizen->listen(voicePower, announcement);
        }
    }
};



#endif //HOMEWORK5_OBSERVER_H
