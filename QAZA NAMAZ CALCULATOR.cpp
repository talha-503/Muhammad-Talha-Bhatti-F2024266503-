#include <iostream>
using namespace std;

int main() 
{
    int byear, cyear, adult_age = 12;
    int total_fajr = 0, total_zuhr = 0, total_asr = 0;
    int total_maghrib = 0, total_isha = 0, total_witr = 0;

    // Input birth year
    cout<<"\t\t\t\t\tQAZA NAMAZ CALCULATOR"<<endl;
	cout << "Enter your birth year: ";
    cin >> byear;

    // Input adult age with default handling
    cout << "Enter your adult age (default 12): ";
    if (!(cin >> adult_age) || adult_age <= 0) 
	{
        adult_age = 12;
       
    }

    // Input current year
    cout << "Enter current year: ";
    cin >> cyear;

    int adult_year = byear + adult_age;
    if (adult_year >= cyear) 
	{
        cout << "\nYou haven't reached adulthood yet or just became adult this year.\n";
        return 0;
    }

    //  calculation loop
    for (int year = adult_year; year <= cyear; year++) 
	{
        int leap = 0;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
		{
            leap = 1;
        }

        for (int month = 1; month <= 12; month++) 
		{
            int days;
            if (month == 2) days = leap ? 29 : 28;
            else if (month == 4 || month == 6 || month == 9 || month == 11) days = 30;
            else days = 31;

            // Monthly input
            int f, z, a, m, i, w;
            cout << "\nYear " << year << " Month " << month << ":\n";
            cout << "Missed Fajr: "; cin >> f;
            cout << "Missed Zuhr: "; cin >> z;
            cout << "Missed Asr: "; cin >> a;
            cout << "Missed Maghrib: "; cin >> m;
            cout << "Missed Isha: "; cin >> i;
            cout << "Missed Witr: "; cin >> w;

            total_fajr += f;
            total_zuhr += z;
            total_asr += a;
            total_maghrib += m;
            total_isha += i;
            total_witr += w;
        }
    }

    // Display results
    cout << "\n=== Approximately Total Qaza Prayers ===";
    cout << "\nFajr:\t\t" << total_fajr;
    cout << "\nZuhr:\t\t" << total_zuhr;
    cout << "\nAsr:\t\t" << total_asr;
    cout << "\nMaghrib:\t" << total_maghrib;
    cout << "\nIsha:\t\t" << total_isha;
    cout << "\nWitr:\t\t" << total_witr;

    // Suggestions
    cout << "\n\n=== Prayer Makeup Plan ===";
    if (total_fajr > 0) 
        cout << "\n- Pray " << total_fajr << " Fajr after morning prayers";
    if (total_zuhr > 0)
        cout << "\n- Pray " << total_zuhr << " Zuhr after current Zuhr";
    if (total_asr > 0)
        cout << "\n- Pray " << total_asr << " Asr before Maghrib";
    if (total_maghrib > 0)
        cout << "\n- Pray " << total_maghrib << " Maghrib before Isha";
    if (total_isha > 0)
        cout << "\n- Pray " << total_isha << " Isha before Fajr";
    if (total_witr > 0)
        cout << "\n- Pray " << total_witr << " Witr with Isha";
       
	cout <<endl<< "Note: Try to complete at least 2 qaza daily after current prayers and seek forgiveness from Allah.";
    
	return 0;
}