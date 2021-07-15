using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        auto t = a % b;
        a = b;
        b = t;
    }

    return a;
}

long long solution(int w, int h)
{
    auto unable = w + h - gcd(w, h);
    return ((long long)w * h - unable);
}