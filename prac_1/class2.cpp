#include <iostream>

class Progression{
    public: 
        Progression(long f = 0)
            :first(f), cur(f){}
        virtual ~Progression() {};
        void printProgression(int n);
    protected:
        virtual long firstValue();
        virtual long nextValue();
    protected:
        long first;
        long cur;
};

void Progression::printProgression(int n){
    std::cout << firstValue();
    for(int i = 2; i <= n; i++)
    {
        std::cout << " " << nextValue();
        std::cout << "\n";
    }
}

long Progression::firstValue()
{
    cur = first;
    return cur;
}

long Progression::nextValue()
{
    return ++cur;
}

class ArithProgression : public Progression{

    public:
        ArithProgression(long i = 1);
    protected:
        virtual long nextValue();
    protected:
        long inc;
};

    ArithProgression::ArithProgression(long i):
    Progression(), inc(i){}

    long ArithProgression::nextValue()
    {
        cur += inc;
        return cur;
    }

class GeomProgression : public Progression {
    public:
        GeomProgression(long b = 2);
    protected:
        virtual long nextValue();
    protected:
        long base;
};

    GeomProgression::GeomProgression(long b)
        :Progression(1), base(b){}

    long GeomProgression::nextValue(){
        cur *=base;
        return cur;
    }

    class FibonacciProgression : public Progression {
        public:
            FibonacciProgression(long f = 0, long s = 1);
        protected:
            virtual long firstValue();
            virtual long nextValue();
        protected:
            long second;
            long prev;
    };

    FibonacciProgression::FibonacciProgression(long f, long s)
        :Progression(f), second(s), prev(second - first){}

    long FibonacciProgression::firstValue(){
        cur = first;
        prev = second - first;
        return cur;
    }

    long FibonacciProgression::nextValue(){
        long temp = prev;
        prev = cur;
        cur += temp;
        return cur;
    }

int main()
{
    Progression* prog;

    std::cout << "Arithmetic progression with default increment:\n";
    prog = new ArithProgression();
    prog -> printProgression(10);
    std::cout << "\n";
    std::cout << "Arithmetic progression with increment 5:\n";
    prog = new ArithProgression(5);
    prog -> printProgression(10);

    std::cout << "Geometric progression with default base:\n";
    prog = new GeomProgression();
    prog ->printProgression(10); 
    std::cout << "\n";
    std::cout << "Geometric progression with base 3: \n";
    prog = new GeomProgression(3);
    prog ->printProgression(10);

    std::cout << "Fibonacci progression with default start values:\n";
    prog = new FibonacciProgression();
    prog ->printProgression(10);
    std::cout << "Fibonacci progression with start values 4 and 6:\n";
    prog = new FibonacciProgression(1,10);
    prog ->printProgression(10);

}