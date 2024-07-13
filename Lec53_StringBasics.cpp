#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int main(){  
    /*declaring a string       
    string str1="karandeep ";

   string str2("singh");
   cout<<str1<<" "<<str2<<endl;;
   */
    
    /*
    //getting input
    // the cin function only take one word as a input
    // so we use getline function
   string str3;
   cout<<"enter a word"<<endl;
   getline(cin,str3);
   cout<<str3<<endl;
   */

    /*
    //for ASCII value
    char ch;
    cout<<"enter a character "<<endl;
    cin>>ch;
    cout<<"ASCII value is of "<<ch<<" is "<<int(ch)<<endl;
    */
     
    //using inbuilt string functions
    /*
    // 1.reverse

    string str4="hello";
    reverse(str4.begin(),str4.end());
    */

    /*
    //2.substr()
    cout<<"sub string of hello is "<<str4.substr(0,3)<<endl;
    // if we write str4.substr(1) then it will start from 1 till end of string
    */

    /*
    //3. +
   string str5="karndeep";
    string str6="Singh";
    cout<<str5+str6<<endl;
    // we can also write
    str5+=str6;
    cout<<str5<<endl;
    //str5+=str6 (str6 is getting appended) & str5=str5+str6 (copy string is created for str5) are different
    */

    /*
    //4. strcat()
    char str7[20]="karandeep";
    char str8[20]="Singh";

    strcat(str7,str8);
   cout<<str7<<endl;
   */
    
    /*
    //5. push_back(add charactetr at the end of string)
    string str9="abcd";
    char ch='e';

    str9.push_back(ch);
    cout<<str9<<endl;
    */
    
    /*
    //6. size() or lenght() and for character array strlen(array_name)
     
    string str10="abcde";
    cout<<str10.size()<<endl;

    char ch[20]="abcde";
    cout<<strlen(ch)<<endl;
    */
    
     /*
    //7. to_string() {convert integer value to string}
    
    int num=432;
    string str11=to_string(num);
    str11+="1";
    cout<<str11<<endl;
    //for printing a special element
    cout<<str11[1]<<endl;
    */

    return 0;
}   