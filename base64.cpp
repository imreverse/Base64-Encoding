#include<iostream>
#include<bitset>
using namespace std;

char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string base64_util(int a, int b, int c)
{
    string A = bitset<8>(a).to_string();
    string B = bitset<8>(b).to_string();
    string C = bitset<8>(c).to_string();
    string ABC = A+B+C;
    string x="", y="", z="", w="";
    for(int j=0; j<6; j++)
        x += ABC[j];
    for(int j=6; j<12; j++)
        y += ABC[j];
    for(int j=12; j<18; j++)
        z += ABC[j];
    for(int j=18; j<24; j++)
        w += ABC[j];
    unsigned long long int l, m, n, o;
    l = bitset<6>(x).to_ullong();
    m = bitset<6>(y).to_ullong();
    n = bitset<6>(z).to_ullong();
    o = bitset<6>(w).to_ullong();
    char L = b64[l], M = b64[m], N = b64[n], O = b64[o];
    if( m==0 ) M = '=';
    if( n==0 ) N = '=';
    if( o==0 ) O = '=';
    string temp = "";
    temp += L;
    temp += M;
    temp += N;
    temp += O;
    return temp;
}
string base64(string s)
{
    string encoded = "";
    unsigned long long int h = s.length()/3, e = s.length()%3;
    unsigned long long int k = h*3;
    for(int i=0; i<k; i+=3)
    {
        int a=s[i], b=s[i+1], c=s[i+2];
        encoded += base64_util(a, b, c);
    }
    if( s.length()%3!=0 )
    {
        int a[3], j=0;
        for(int i=k; i<e+k; i++)
            a[j] = s[i], j++;
        while(j<3)
            a[j] = 0, j++;
        encoded += base64_util(a[0], a[1], a[2]);
        //return encoded;
    }
    return encoded;
}

int main()
{
    cout<<"=BASE64 ENCODING==========================\n";
    cout<<"\nInput your string: \n";
    string s;
    //getline(cin,s);
    string paragraph;
    do
    {
        getline(cin, s);
        paragraph += s + "\n";
    }while(s.length() > 0);
    paragraph[paragraph.length()-1] = ' ';
    //cout<<paragraph;
    cout<<"\nCorresponding Base64 Encoded string: \n";
    cout<<base64(paragraph)<<"\n";
}
