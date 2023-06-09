#include<iostream>         //Application to convert a given amount to different currency
#include<cmath>
using namespace std;
class Currency
    {
        public:
            struct curr
            {
                string name;
                double amt;
                double conv;
            };
            struct curr s[25]; 
            Currency()
            {  
                    s[0].name="INR"; s[0].conv=1.0;
                    s[1].name="GBP"; s[1].conv=0.0097;
                    s[2].name="EUR"; s[2].conv=0.011;
                    s[3].name="USD"; s[3].conv=0.012;
                    s[4].name="AUD"; s[4].conv=0.019;
                    s[5].name="YEN"; s[5].conv=1.7;
                    s[6].name="CHF"; s[6].conv=0.011;
                    s[7].name="CNY"; s[7].conv=0.086;
                    s[8].name="NZD"; s[8].conv=0.02;
                    s[9].name="CLP"; s[9].conv=9.83;
                    s[10].name="SGD"; s[10].conv=0.016;
                    s[11].name="COP"; s[11].conv=53.94;
                    s[12].name="MEX"; s[12].conv=0.21;
                    s[13].name="HKD"; s[13].conv=0.095;
                    s[14].name="DKK"; s[14].conv=0.084;
                    s[15].name="ARS"; s[15].conv=2.91;
                    s[16].name="BHD"; s[16].conv=0.0046;
                    s[17].name="IDR"; s[17].conv=181.29;
                    s[18].name="MYR"; s[18].conv=0.056;
                    s[19].name="BND"; s[19].conv=0.016;
                    s[20].name="BRL"; s[20].conv=0.061;
                    s[21].name="BZD"; s[21].conv=0.024;
                    s[22].name="KWD"; s[22].conv=0.0037;
                    s[23].name="BTC"; s[23].conv=0.000000447;
                    
                }
            string input()
                {
                            string s1;
                            cout<<
                            "1. Indian Rupees (INR)"<<endl<<
                            "2. Great Britain Pounds (GBP)"<<endl<<
                            "3. Euros (EUR)"<<endl<<
                            "4. US Dollars (USD)"<<endl<<
                            "5. Australian Dollars (AUD)"<<endl<<
                            "6. Japanese Yen (YEN)"<<endl<<
                            "7. Swiss Franc (CHF)"<<endl<<
                            "8. Chinese Yuan (CNY)"<<endl<<
                            "9. New Zealand Dollars (NZD)"<<endl<<
                            "10. Chilean Peso (CLP)"<<endl<<
                            "11. Singaporean Dollars (SGD)"<<endl<<
                            "12. Colombian Peso (COP)"<<endl<<
                            "13. Mexican Peso (MEX)"<<endl<<
                            "14. Hong Kong Dollars (HKD)"<<endl<<
                            "15. Danish Krone (DKK)"<<endl<<
                            "16. Argentine Peso (ARS)"<<endl<<
                            "17. Bahraini Dinar (BHD)"<<endl<<
                            "18. Indonesian Rupiah (IDR)"<<endl<<
                            "19. Malaysian Ringgit (MYR)"<<endl<<
                            "20. Brunei Dollars (BND)"<<endl<<
                            "21. Brazilian Real (BRL)"<<endl<<
                            "22. Belize Dollars (BZD)"<<endl<<
                            "23. Kuwaiti Dinar (KWD)"<<endl<<
                            "24. Bitcoins (BTC)"<<endl;
                            cin>>s1;
                            return s1;
                }
            virtual int convert()
                {   int c1=0;
                    int count=0;
                    string s1;
                    cout<<"Welcome to currency converter!"<<endl;
                    while(true)
                        {
                            cout<<"Enter the 3-letter code for the currency which you wish to convert:"<<endl;
                            s1=input();
                            for(int i=0; i<24; i++)
                                {
                                    if(s[i].name==s1)
                                        {
                                            c1=i;
                                            count=1;
                                            break;
                                        }
                                }
                            if(count==1)
                                break;
                            cout<<"Invalid Input, this currency does not exist in my database! Please enter a valid input."<<endl;
                            for(int i=0;i<24; i++)
                                cout<<s[i].name<<endl;
                        }
                    return c1;
                }
    };
class Conversion: public Currency
    {
        public:
            double p=0.0;
            int convert()
                {   int c2=0;
                    string s1;
                    cout<<"Enter the code for the currency which you wish to be converted to:"<<endl;
                    while(true)
                        {   int count=0;
                            s1=input();
                            for(int i=0; i<24; i++)
                                {
                                    if(s[i].name==s1)
                                        {   count=1;
                                            c2=i;
                                            break;
                                        }
                                }
                            if(count==1)
                                break;
                            cout<<"Invalid Input, this currency does not exist in my database! Please enter a valid input."<<endl;
                        }
                    return c2;
                }
            double convert (double a, double b)
                {
                    return (a/b);
                }
    };
int main()
    {   int a1=0,a2=0;
        Currency *ob;
        Currency ob1;
        Conversion ob2;
        ob=&ob1; a1=ob->convert();
        ob=&ob2; a2=ob->convert();
        double c=ob2.convert(ob2.s[a2].conv,ob2.s[a1].conv);     //Conversion rate between the 2 numbers.
        cout<<"Enter the amount:"<<endl;
        cin>>ob2.s[a1].amt;
        for(int i=0; i<24; i++)
            {
                ob2.s[i].amt=ob2.s[a1].amt*ob2.convert(ob2.s[i].conv,ob2.s[a1].conv);  //Amount for every currency
            }
        cout<<"Amount in "<<ob2.s[a2].name<<" is:"<<(round(ob2.s[a2].amt*100.0)/100.0)<<endl;
        cout<<endl;
        cout<<"Choose 1 to see values in all currencies, and any other key to exit:"<<endl;
        int n1;
        cin>>n1;
        if(n1==1)
            {
                for(int i=0; i<24; i++)
                    cout<<ob2.s[i].name<<":"<<(round(ob2.s[i].amt*100.0)/100.0)<<endl;
            }
        cout<<"Thank You!"<<endl;
        return 0;
    }