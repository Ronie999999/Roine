
#include  "iostream"
using  namespace  std;
class vehicle{
private:
    int speed,weight;
public:
    vehicle(int speed, int weight){
        this->speed = speed;
        this->weight = weight;
        cout << "vehicle constructor called." << " maxspeed:" << speed << "; weight" << weight << endl;
    }
    ~vehicle(){
        cout << "vehicle destructor called." << " maxspeed:" << speed << "; weight" << weight << endl;
    }
    static void run(){
        cout << "vehicle run" << endl;
    }
    static void stop(){
        cout << "vehicle stop" << endl;
    }
};

class bicycle:virtual public vehicle{
public:
    bicycle(int speed, int weight, int height):vehicle(speed, weight){
        this->height = height;
        cout << "bicycle constructor called. height:" << height << endl;
    }
    ~bicycle(){
        cout << "bicycle destructor called. height:" << height << endl;
    }
private:
    int height;
};
class motorcar:virtual public vehicle{
public:
    motorcar(int speed, int weight, int seatnum):vehicle(speed, weight){
        this->seatnum = seatnum;
        cout << "motorcar constructor called. setnum:" << seatnum << endl;
    }
    ~motorcar(){
        cout << "motorcar destructor called. setnum:" << seatnum << endl;
    }
private:
    int seatnum;
};

class motorcycle:public bicycle,public motorcar{
public:
    motorcycle(int height, int setnum, int maxspeed, int weight) : vehicle(maxspeed, weight),motorcar(maxspeed, weight,setnum),bicycle(maxspeed, weight,height) {
    cout << "motorcycle constructor called" << endl;
    }
    ~motorcycle(){
        cout << "motorcycle destructor called" <<endl;
    }

};
int  main(int  argc,  char  *argv[])
{
    motorcycle m( 1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return  0;
}