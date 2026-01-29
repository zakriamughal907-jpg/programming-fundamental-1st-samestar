#include <iostream>
#include <iomanip>
using namespace std;

// 1. Calculate base electricity bill based on units
double calculateElectricityBill(int units)
{
    double bill = 0;

    if (units <= 100)
        bill = units * 0.50;
    else if (units <= 300)
        bill = (100 * 0.50) + (units - 100) * 0.75;
    else if (units <= 600)
        bill = (100 * 0.50) + (200 * 0.75) + (units - 300) * 1.20;
    else
        bill = (100 * 0.50) + (200 * 0.75) + (300 * 1.20) + (units - 600) * 1.50;

    return bill;
}

// 2. Apply peak hour charge
double applyPeakHourCharge(double billAmount, bool isPeakHour)
{
    if (isPeakHour)
        return billAmount * 0.20;
    return 0;
}

// 3. Apply customer category charge
double applyCustomerCategoryCharge(double billAmount, char category)
{
    if (category == 'C' || category == 'c')
        return billAmount * 0.10;
    else if (category == 'I' || category == 'i')
        return billAmount * 0.15;
    return 0;
}

// 4. Apply penalties and discounts
double applyPenaltiesAndDiscounts(double billAmount, int units)
{
    if (units > 1000)
        return billAmount * 0.05;     // Penalty
    else if (units < 150)
        return -billAmount * 0.05;    // Discount
    return 0;
}

// 5. Apply meter rent and tax
double applyTaxAndFinalCharges(double billAmount, double meterRent)
{
    billAmount += meterRent;
    billAmount += billAmount * 0.12;  // 12% tax
    return billAmount;
}

// 6. Generate detailed bill
void generateBill(string customerName, int units, char category, bool isPeakHour)
{
    double baseBill = calculateElectricityBill(units);
    double peakCharge = applyPeakHourCharge(baseBill, isPeakHour);
    double categoryCharge = applyCustomerCategoryCharge(baseBill + peakCharge, category);
    double penaltyDiscount = applyPenaltiesAndDiscounts(baseBill, units);
    double meterRent = 75.0;

    double totalBill = baseBill + peakCharge + categoryCharge + penaltyDiscount;
    double finalBill = applyTaxAndFinalCharges(totalBill, meterRent);

    cout << fixed << setprecision(2);
    cout << "\n--------------------------------------\n";
    cout << "        SMART ELECTRICITY BILL\n";
    cout << "--------------------------------------\n";
    cout << "Customer Name: " << customerName << endl;

    if (category == 'R' || category == 'r')
        cout << "Customer Category: Residential\n";
    else if (category == 'C' || category == 'c')
        cout << "Customer Category: Commercial\n";
    else
        cout << "Customer Category: Industrial\n";

    cout << "Units Consumed: " << units << " kWh\n";
    cout << "--------------------------------------\n";
    cout << "Base Bill Amount: $" << baseBill << endl;
    cout << "Peak Hour Charge: $" << peakCharge << endl;
    cout << "Category Charge: $" << categoryCharge << endl;

    if (units > 1000)
        cout << "Penalty Applied: Yes\n";
    else
        cout << "Penalty Applied: No\n";

    if (units < 150)
        cout << "Discount Applied: Yes\n";
    else
        cout << "Discount Applied: No\n";

    cout << "Meter Rent: $" << meterRent << endl;
    cout << "Tax (12%): $" << (finalBill - totalBill - meterRent) << endl;
    cout << "--------------------------------------\n";
    cout << "Total Payable: $" << finalBill << endl;
    cout << "--------------------------------------\n";
}

int main()
{
    string customerName;
    int units;
    char category;
    bool isPeakHour;

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Units Consumed: ";
    cin >> units;

    cout << "Enter Category (R/C/I): ";
    cin >> category;

    cout << "Peak Hour? (1 for Yes, 0 for No): ";
    cin >> isPeakHour;

    generateBill(customerName, units, category, isPeakHour);

    return 0;
}