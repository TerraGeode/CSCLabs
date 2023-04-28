/* TerraGeode
   CSC1710-03
   Program 2: Generate an amortization table from user input.
   Level:95
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
   //generate variables
   double prinAmnt, Aint, downPayPerNum, prinBal, Mint, downPayPer, PMI, PMT, Ipay, Ppay, totalInt = 0, totalPMI = 0, Gtotal;
   int totalPay, payment;

   //get the purchase price/principal amount, annual interest rate, no. of payments, and down payment %
   /*cout << "Please input the purchase price, annual interest rate, number of payments, and down payment percentage.\n
      Do not use any symbols aside from decimal points.\n
      Do not input any percentages as a decimal." << endl;
   cin >> prinAmnt >> Aint >> totalPay >> downPayPerNum;
   above was mostly for proof of working concept.*/

   //idiot proofing :)
   cout << "Please input the purchase price. Do not include '$.'" << endl;
   cin >> prinAmnt;
   while (prinAmnt <= 0) {
      cout << "Please input a value greater than 0." << endl;
      cin >> prinAmnt;
   }
   cout << "Please input the annual interest rate. Do not include '%.'" << endl;
   cin >> Aint;
   while (Aint <= 0 || Aint > 100) {
      cout << "Please input a value between 0 and 100." << endl;
      cin >> Aint;
   }
   cout << "Please input the total amount of payments." << endl;
   cin >> totalPay;
   while (totalPay <= 0) {
      cout << "Please input a value greater than 0." << endl;
      cin >> totalPay;
   }
   cout << "Please input the down payment percentage. Do not include '%.'" << endl;
   cin >> downPayPerNum;
   while (downPayPerNum < 0 || downPayPerNum > 100) {
      cout << "Please input a value between 0 and 100." << endl;
      cin >> downPayPerNum;
   }

   //calculate principal balance, monthly interest, decimal down payment %, and monthly payment
   downPayPer = downPayPerNum/100.0;
   prinBal = prinAmnt*(1-downPayPer);
   Mint = Aint/100.0/12.0;
   PMT = Mint*prinBal/(1-pow((1+Mint), -totalPay));

   //make output display 2 decimal places
   cout << fixed << showpoint << setprecision(2);

   //check if Private Mortgage Insurance applies and calculate amount due if so
   if (downPayPerNum >= 0 && downPayPerNum < 5) {
      PMI = prinBal*.0103;
   } else if (downPayPerNum >= 5 && downPayPerNum < 10) {
      PMI = prinBal*.00875;
   } else if (downPayPerNum >= 10 && downPayPerNum < 15) {
      PMI = prinBal*.00675;
   } else if (downPayPerNum >= 15 && downPayPerNum < 20) {
      PMI = prinBal*.00375;
   } else if (downPayPerNum >= 20) {
      PMI = 0;
   }

   //make table head
   cout << "|Payment No.|Interest Payment|Principal Payment|Principal Balance|" << setw(11) << "PMI|" << endl;
   cout << "|" << setw(76) << setfill('=') << "|" << endl;

   //generate for loop that runs for the total ammount of payments
   for (payment = 1; payment <= totalPay; payment++) {
      //calculate interest payment, principal payment,and update principal balance, total interest payed, and total PMI
      Ipay = prinBal*Mint;
      Ppay = PMT-Ipay;
      prinBal -= Ppay;
      totalInt += Ipay;
      totalPMI += PMI;

      //output payment number, interest payment, principal payment, principal balance, and PMI
      cout << "|" << setw(11) << setfill(' ') << payment << "|";
      cout << setw(16) << Ipay << "|";
      cout << setw(17) << Ppay << "|";
      cout << setw(17) << prinBal << "|";
      cout << setw(10) << PMI << "|" << endl;

      //check if payment balance is less than 80% of principal amount, if so set PMI to 0
      if (prinBal <= prinAmnt * .8) {
         PMI = 0;
      }
   }

   //calculate grand total
   Gtotal = prinAmnt + totalInt + totalPMI;

   //output total interest, grand total, and total PMI
   cout << "|" << setw(76) << setfill('=') <<"|" << endl;
   cout << "|" <<setw(12) << setfill(' ') << "Total|";
   cout << setw(16) << totalInt << "|";
   cout << setw(35) << Gtotal << "|";
   cout << setw(10) << totalPMI << "|" << endl;
   return 0;
}
