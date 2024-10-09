#include <iostream>
#include <utility>
#include <cmath>
#include <fstream>
#include "basicDataStructure/SqList.cpp"
#include "basicDataStructure/LinkList.cpp"
#include "basicDataStructure/CLinkList.cpp"
static int start;
class PositionXY {//不考虑复杂的经纬度，仅从二维欧拉平面数学角度考虑问题
    double X;
    double Y;
public:
    PositionXY(double x, double y) : X(x), Y(y){}
    PositionXY() : PositionXY(0, 0) {}

    PositionXY operator+(const PositionXY &xy) const {
        PositionXY ret;
        ret.X = this->X + xy.X;
        ret.Y = this->Y + xy.Y;
        return ret;
    }

    PositionXY operator-(const PositionXY &xy) const {
        PositionXY ret;
        ret.X = this->X - xy.X;
        ret.Y = this->Y - xy.Y;
        return ret;
    }

    [[nodiscard]] double getX() const {
        return this->X;
    }
    [[nodiscard]] double getY() const {
        return this->Y;
    }
    [[nodiscard]] std::string toString() const{
        return std::to_string(X) + " " + std::to_string(Y);
    }
};
class City {
    std::string Name;
    PositionXY Pos;
public:
    City() = default;
    City(std::string name, PositionXY pos) : Name(std::move(name)), Pos(pos) {}
    City(std::string name, double x, double y) : Name(std::move(name)), Pos(PositionXY(x, y)) {}
    [[nodiscard]] std::string toString() const{
        return Name + " " + Pos.toString();
    }
    double distanceTo(const City& city) {
        return distanceTo(city.Pos);
    }
    double distanceTo(PositionXY xy) {
        double
                diffX = fabs((this->Pos.getX() - xy.getX())),
                diffY = fabs((this->Pos.getY() - xy.getY()));
        return sqrt(diffX*diffX + diffY*diffY);
    }
    static ds::LinkList<City>* readDataFromText(const std::string& filePath) {
        std::ifstream infile;
        infile.open(filePath, std::ios::in);
        if(!infile) {
            std::cerr << "Unable to open file";
            throw std::exception();
        }
        std::string line;
        auto *ret = new ds::LinkList<City>;
        int i = 1;
        while (std::getline(infile, line)) {
            char city[20] = "";
            double x,y;
            sscanf(line.c_str(),"%s %lf %lf", city, &x, &y);
            ret->insertElem(i, City(city, x, y));
        }
        infile.close();
        return ret;
    }
    static void saveDataToText(ds::LinkList<City> list, const std::string &filePath) {
        std::ofstream outfile;
        outfile.open(filePath, std::ios::out);
        if(!outfile) {
            std::cerr << "Unable to open file";
            throw std::exception();
        }
        int i = 1;
        City e;
        while (list.getElem(i++, e)){
            std::string input = e.toString() + "\n";
            outfile.write(input.c_str(), sizeof(input.c_str()));
        }
        outfile.close();
    }
};
class Person{
public:
    int number;
    int m;
    Person() = default;
    explicit Person(int m) : m(m) { number = ++start;}
    [[nodiscard]] bool shouldOut(int n) const {
        return m == n;
    }
};
int sqListExp();
int linkListExp();
int extra_one();
int extra_two();
int main() {
    return extra_two();
}
int sqListExp() {
    using namespace std;
    auto *sqList = new ds::SqList<char>;
    char element;
    cout << "顺序表的基本运算如下:\n";
    cout << "(1）初始化顺序表L\n";
    sqList->init();
    cout << "(2）依次插入a、b、c、d、e元素\n";
    sqList->insertElem(1,'a');
    sqList->insertElem(2,'b');
    sqList->insertElem(3,'c');
    sqList->insertElem(4,'d');
    sqList->insertElem(5,'e');
    cout << "(3）输出顺序表L: ";
    sqList->display();
    sqList->getElem(3, element);
    cout << "(4) 输出顺序表L的第3个元素: " << element << endl;
    cout << "(5）在第4个元素的位置上插入f元素\n";
    sqList->insertElem(4, 'f');
    cout << "(6）删除顺序表L的第3个元素\n";
    sqList->deleteElem(3, element);
    cout << "(7) 输出顺序表L: ";
    sqList->display();
    sqList->destroy();
    return 0;
}
int linkListExp() {
    using namespace std;
    auto *lLink = new ds::LinkList<char>;
    char element;
    cout << "单链表的基本运算如下:\n";
    cout << "(1) 初始化单链表h\n";
    lLink->init();
    cout << "(2) 依次采用尾插法插入a,b,c,d,e元素\n";
    lLink->insertElem(1,'a');
    lLink->insertElem(2,'b');
    lLink->insertElem(3,'c');
    lLink->insertElem(4,'d');
    lLink->insertElem(5,'e');
    cout << "(3) 输出单链表h:";
    lLink->display();
    lLink->getElem(3, element);
    cout << "(4) 单链表h的第3个元素:" << element << endl;
    cout << "(5) 在第4个元素位置上插入f元素\n";
    lLink->insertElem(4,'f');
    cout << "(6) 删除h的第3个元素\n";
    lLink->deleteElem( 3, element);
    cout << "(7) 输出单链表h:";
    lLink->display();
    lLink->destroy();
    return 0;
}


int extra_one() {
    std::string fp = "..\\data\\extra_one.txt";
    ds::LinkList<City> *readRes = City::readDataFromText(fp);
    int i = 1;
    City e;
    double x, y, d;
    std::cout << "请依次输入 x坐标 y坐标 距离D" << std::endl;
    std::cin >> x >> y >> d;
    std::cout << "符合条件的结果如下：" << std::endl;
    while (readRes->getElem(i++ ,e)) {
        if(e.distanceTo(PositionXY(x, y)) <= d)
            std::cout << i - 1 << ") " << e.toString() << std::endl;
    }
    return 0;
}
int extra_two() {
    auto *pList = new ds::CLinkList<Person>;
    pList->init();
    int mMax,co;
    std::cout << "请输入报数上限值mMax 和 人数co" << std::endl;
    std::cin >> mMax >> co;
    if(co <= 0 || mMax <= 0) {
        std::cerr << "异常数据，退出程序";
        exit(0);
    }
    std::cout << "分别输入这" << co << "个人的密码";
    for (int i = 0, m; i < co ; i++) {
        std::cin >> m;
        if (m > mMax || m < 0) {
            std::cerr << "异常数据，退出程序";
            exit(0);
        }
        pList->insertElem(i + 1, Person(m));
    }
    auto* list = new ds::SqList<int>;
    list->init();
    int s, j = s = 0, len = co;
    Person person{};
    while (!pList->isEmpty()) {
        j++;
        s++;
        if (s == mMax) {
            list->insertElem(list->getLength() + 1, person.number);
            mMax = person.number;
            pList->deleteElem(j % len + 1, person);
            s = 1;
            len--;
        }
        if (j > mMax) s = 1;
    }
    list->display();
    return 0;
}

