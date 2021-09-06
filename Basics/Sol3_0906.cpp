
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string s) {
    int answer;
     while(true){
        int idx = s.find("zero");
        if(idx == -1) break;
        s.replace(idx,4,"0");
    }
    while(true){
        int idx = s.find("one");
        if(idx == -1) break;
        s.replace(idx,3,"1");
    }
    while(true){
        int idx = s.find("two");
        if(idx == -1) break;
        s.replace(idx,3,"2");
    }
    while(true){
        int idx = s.find("three");
        if(idx == -1) break;
        s.replace(idx,5,"3");
    }
    while(true){
        int idx = s.find("four");
        if(idx == -1) break;
        s.replace(idx,4,"4");
    }
    while(true){
        int idx = s.find("five");
        if(idx == -1) break;
        s.replace(idx,4,"5");
    }
    while(true){
        int idx = s.find("six");
        if(idx == -1) break;
        s.replace(idx,3,"6");
    }
    while(true){
        int idx = s.find("seven");
        if(idx == -1) break;
        s.replace(idx,5,"7");
    }
    while(true){
        int idx = s.find("eight");
        if(idx == -1) break;
        s.replace(idx,5,"8");
    }
    while(true){
        int idx = s.find("nine");
        if(idx == -1) break;
        s.replace(idx,4,"9");
    }

    answer = stoi(s);
    return answer;
}