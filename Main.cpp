//※試験時間は90分です。
//試験中にわからないこと(関数名やinclude名など)があれば、
//ネットや本で調べてもらって構いません。
//問題の意図が理解できない場合は先生に質問してもらって構いません。
//他の生徒と会話することや、解答を見せてもらうことは禁止です。
//
//試験時間90分で試験終了後に、gitにて提出を始めてください。
//それまでは問題を解くか、別の作業をしてもかまいません。
//
//終了時刻
//
//提出最終時間

// 第1問(10点)
// 以下のクラスにコンストラクタ、デストラクタを追加してください。
// コンストラクタ、デストラクタの処理の内容はなんでも構いません

class Point
{
private:
    int x;
    int y;
public:
    int getX() { return x; }
    int getY() { return y; }
    ~Point() { x, y = 0; }
};



// 第2問(10点)
// int型の変数をnewを使い確保してください。
// また、char型の配列をnewを使い確保してください。
// どちらもdeleteを呼び出すようにしてください。

int main()
{
    int* newInt = new int();
    char* newArray = new char[1000];
    delete newInt;
    delete newArray;
}



// 第3問(15点)
// 以下の継承先クラスのデストラクタが正しく呼び出されるように、
// クラスを修正してください。

class Test
{
public:
    Test()
    {
        printf("Test\n");
    }
    virtual ~Test()
    {
        printf("~Test\n");
    }
};
class Test2 : public Test
{
public:
    Test2()
    {
        printf("Test2\n");
    }
    ~Test2()
    {
        printf("~Test2\n");
    }
};
int main()
{
    Test* t;
    t = new Test2();

    delete t;
    return 0;
}



// 第4問(25点)
// 以下の関数をテンプレート化して、
// 様々な型で計算できるようにしてください。

template <typename T>
T Calc(T a, T b, int type)
{
    T ans = 0;
    switch (type)
    {
    case 0:
        ans = a + b;
        break;
    case 1:
        ans = a - b;
        break;
    case 2:
        ans = a * b;
        break;
    case 3:
        ans = a / b;
        break;
    }

    return ans;
}

int main()
{
    int ans1;
    float ans2;
    char ans3;

    ans1 = Calc<int>(2, 5, 0);
    ans2 = Calc<float>(10.0f, 2.5f, 3);
    ans3 = Calc<char>(10, 4, 2);

    return 0;
}



// 第5問(25点)
// 次のプログラムを修正し、以下のような表示になるようにプログラムを作成してください。
// num = 50
// num = 40
// num = 30
// num = 20
// num = 10
// また、リストのデータが30しかない状態にしてください。その際表示は以下のになります。
// num = 30

int main()
{
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
    {
        // ここにプログラムを記述
        lst.push_back(50 - (10 * i));
    }

    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

    // リストを修正してnum=30と表示されるようにプログラムを記述
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end();)
    {
        if (*it != 30)
            it = lst.erase(it);
        else
            ++it;
    }
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        printf("num = %d\n", *it);
    }
}


// 第6問(25点)
// 第5問と同じ表示になるようにstd::vectorを使ってプログラムを記述してください。

int main()
{
    std::vector<int> vec;

    for (int i = 0; i < 5; ++i)
    {
        vec.push_back(50 - (10 * i));
    }
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("num = %d\n", *it);
    }
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end();)
    {
        if (*it != 30)
            it = vec.erase(it);
        else
            ++it;
    }
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("num = %d\n", *it);
    }
}


