#include <iostream> 
#include <thread>
#include <string> 
#include <cctype>
using namespace std; 
 string str; 
 string rev_string="";
  
   void input_thread() 
   {                 // take a user input 
     try
    {
        cout << "Enter a string: ";
        cin >> str;
    }
    catch (const exception  ex)
    {
        cout << "Exception in input thread: " << ex.what() << endl;
    }
    cout<<endl; 
   } 
   
    void capital_thread() 
    {               
     for(int i=0; i<str.length(); i++)
{

if(str[i]>= 'a' && str[i]<='z') 

{
str[i]=str[i]-32;


}
}
 cout<<"Upper Case String: \n"<<str;

  }
  
void reverse_thread()
 {    
  cout<<"\nReverse string: "; 
 for(int i=str.size()-1;i>=0;i--) 
   {         
                    rev_string+=str[i];    
   }     cout<<rev_string<< endl;
    }
   
   void change_letter() {

	int char_code;
	
	for (int x = 0; x < str.length(); x++)
	{
		char_code = int(str[x]);

		if (char_code == 122)
		{
			str[x] = char(97);
		}
		else if (char_code == 90)
		{
			str[x] = char(65);
		}
		else if (char_code >= 65 && char_code <= 90 || char_code >= 97 && char_code <= 122)
		{
			str[x] = char(char_code + 2);
		}
	
	}

	cout  << "Shifted Result BY 2  "<< endl << str<< endl;
}
  
              
               int main() 
               {                 
                thread thr1(input_thread);  
                thr1.join();  
                thread thr2(capital_thread); 
                thr2.join();    
                thread thr3(reverse_thread); 
                thr3.join(); 
                thread thr4(change_letter); 
                thr4.join(); 
                return 0;
}
                
                

