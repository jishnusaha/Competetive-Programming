#include <iomanip>
#include<iostream>
using namespace std;
int main()
{
    double diposit=5520,interest=8, year=10, source_tax=10;
    cin >> diposit >> interest >> year >> source_tax;
    interest/=100;
    source_tax/=100;
    double total=0;
    cout << "diposit\t\ttotal\t\tinterest\ttax\tgross_amount\n";
    cout << "----------------------------------------------------------------------------------------------\n";
    double total_diposit = 12*year*diposit;
    double total_interest_sum = 0;
    double total_tax_sum=0;
    while(year--)
    {
        double before_interste = total+12*diposit;
        double interest_total = before_interste*interest;
        total_interest_sum+= interest_total;
        total= before_interste+interest_total;
        total_tax_sum += interest_total*source_tax;
        cout << fixed << setprecision(3) << "12*" << diposit << "\t" << before_interste << "\t" << interest_total << "\t" << interest_total*source_tax << "\t" << total << endl;
    }
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << fixed << setprecision(3)  << total_diposit << "\t\t\t" << total_interest_sum << "\t" << total_tax_sum << "\t" << total << endl;
    cout << "net payable: " << total-total_tax_sum << endl;
    main();
}
