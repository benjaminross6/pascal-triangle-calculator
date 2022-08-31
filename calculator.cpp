#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

int main()
{
    bool run = true;
    int num_of_rows;
    int prev_row[100000];
    int i1 = 0;//counts out rows
    int i2 = 0;//counts out numbers for each row
    int prev_row_q = 0;
    do
    {
        std::cout << std::endl << "How many rows of Pascal's triangle would you like to calculate?\n";
        std::vector<int> row;
        if(std::cin >> num_of_rows)
        {
            for(i1 = 0; i1 <= num_of_rows - 1; i1++)
            {
                std::cout << std::endl;
                if(i1 < 10)
                {
                    std::cout << "Row: " << i1 << ":    ";
                }
                else
                {
                    std::cout << "Row: " << i1 << ":   ";
                }
                for(i2 = 0; i2 <= i1; i2++)
                {
                    if(i2 == 0)
                    {
                        row[i2] = 1;
                        std::cout << row[i2] << ",";
                        prev_row_q = row[i2];
                    }
                    else if(i2 == i1)
                    {
                        row[i2] = 1;
                        std::cout << row[i2] << ",";
                        prev_row[i2 - 1] = prev_row_q;
                        prev_row_q = row[i2];
                        prev_row[i2] = row[i2];
                    }
                    else
                    {
                        row[i2] = prev_row[i2 - 1] + prev_row[i2];
                        std::cout << row[i2] << ",";
                        prev_row[i2 - 1] = prev_row_q;
                        prev_row_q = row[i2];
                    }
                }
            }
        }
        else
        {
            run = false;
            std::cout << std::endl << "goodbye" << std::endl;
        }
    }while(run == true);
}
