class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> vals = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
            {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
            {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string result;
        for(auto &p : vals){
            while(num>=p.first()){
                result+=p.second();
                num-=p.first();
            }
        }
        return result;
    }
};


class Solution {
public:
    string intToRoman(int num) {
        string ones[] ={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] ={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundred[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousand[]={"","M","MM","MMM"};
        
        string roman = thousand[num/1000]+hundred[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
        return roman;
    }
};