#include<iostream>
#include<math.h>
#include<Cmath>
#include<algorithm>


using namespace std;



int main()
{
    string input_string,isEven,even,odd;
    int dataBit, parityBit, totalBit, tot_parityBit;
    cout << "Enter Input string: ";
    cin >> input_string;

////////////////////////  Manage Even/Odd parity  ///////////////////////////////

    cout << "Even or Odd parity? e/o : ";
    cin >> isEven;

    if(isEven == "e" || isEven == "1")
    {
        even = "0";
        odd = "1";
    }
    else
        {
            even = "1";
            odd = "0";
        }

    dataBit = input_string.size();

////////////////////////  calculate Number of Parity Bit  ///////////////////////////////
    int temp_parity = 1;
    while (1)
    {
        if (pow(2, temp_parity) >= (dataBit + temp_parity + 1))
        {
            parityBit = temp_parity;
            break;
        }
        temp_parity++;
    }


    totalBit = dataBit + parityBit;
    tot_parityBit = ceil(log2(totalBit));


////////////////////////  put input data bits in Array  ///////////////////////////////

    string tot_array[totalBit],Copy_tot_array[totalBit];
    int tot_par_array[tot_parityBit];

    for (int i = 0, j = dataBit - 1; i < totalBit; i++)
    {
        if (log2(i + 1) != ceil(log2(i + 1)))
        {
            tot_array[i] = input_string[j];
            j--;
        }
        else
            tot_array[i] = "p";              /////// put 'p' in parity bit's position.

    }

    copy(tot_array, tot_array+totalBit, Copy_tot_array);    ////// copy Code-word Bitstream without Parity values


////////////////////////  Calculate Number of Odd/Even Parity bits  ///////////////////////////////

    int flag = 0;
    for (int z = 0; z < tot_parityBit; z++)
    {
        int i = pow(2, z);
        int r = i-1;
        while (r < totalBit)
        {
            for (int k = i-1; k >= 0; k--)
            {
                if(r >= totalBit)
                    break;
                if (tot_array[r] == even)
                    flag++;
                r++;
            }
            r = r + i;
        }
        tot_par_array[z] = flag;
        flag = 0;

    }

////////////////////////  put Parity bits value  ///////////////////////////////


    for (int i = 0; i < tot_parityBit; i++)
    {
        if(tot_par_array[i]%2 == 0)
        {
            int temp = pow(2,i)-1;
            tot_array[temp] = even;
        }

        else
        {
            int temp = pow(2,i)-1;
            tot_array[temp] = odd;
        }
    }


    cout << endl << "Code-word Bitstream: " << endl;
    for (int i = totalBit - 1; i >= 0; i--)
    {
        cout << tot_array[i];
    }

    cout << endl <<endl;

    cout<<"Want to see extra Information? y/n : ";
    string x;
    cin>>x;

    cout << endl <<endl;

    ////////////////////////  Print Extra Information //////////////////////////////

    if(x == "Y" || x == "y")
    {
        cout <<"             Extra Information           "<< endl <<endl;
        cout << "Input String: " << input_string;
        cout << endl << "Number of data bits (m): " << dataBit;
        cout << endl << "Number of redundant parity bit (r): " << parityBit;
        cout << endl << "Total length of Codeword (n): " << totalBit;


        cout << endl<< endl << "Code-word Bitstream without Parity values: " << endl;
        for (int i = totalBit - 1; i >= 0; i--)
        {
            cout << Copy_tot_array[i];
        }


        cout << endl<< endl << "Parity String Array: " << endl;
        for (int i = tot_parityBit-1; i >= 0; i--)
        {
            cout << tot_par_array[i];
        }

        cout<< endl << endl;

        for (int i = 0; i<tot_parityBit; i++)
        {
            int temp = pow(2,i)-1;
            cout <<"P"<< temp+1 <<" = "<< tot_array[temp]<<endl;
        }
    }




}
