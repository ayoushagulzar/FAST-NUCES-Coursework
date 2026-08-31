#include <iostream>
#include <stdexcept>

using namespace std;

class Image
{
private:
    int nRows;
    int nCols;
    int **data;

public:
    // Default constructor
    Image()
    {
        nRows = 0;
        nCols = 0;
        data = NULL;
    }

    // Parameterized constructor
    Image(int r, int c)
    {
        nRows = r;
        nCols = c;
        data = new int *[nRows];
        for (int i = 0; i < nRows; i++)
        {
            data[i] = new int[nCols]();
        }
    }

    // Copy constructor
    Image(const Image &other)
    {
        nRows = other.nRows;
        nCols = other.nCols;
        data = new int *[nRows];
        for (int i = 0; i < nRows; i++)
        {
            data[i] = new int[nCols];
            for (int j = 0; j < nCols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Copy assignment operator
    Image &operator=(const Image &other)
    {
        if (this == &other)
            return *this;

        if (data != NULL)
        {
            for (int i = 0; i < nRows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }

        // COPY Size
        nRows = other.nRows;
        nCols = other.nCols;

        // allocate new memory
        data = new int *[nRows];
        for (int i = 0; i < nRows; i++)
        {
            data[i] = new int[nCols];
            for (int j = 0; j < nCols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
        return *this;
    }
    // end copy assignment

    // safe access
    int &operator()(int row, int col)
    {
        if (row < 0 || row >= nRows || col < 0 || col >= nCols)
        {
            throw out_of_range("Invalid row or column!");
        }
        return data[row][col];
    }

    // Apply 3x3 kernel
    Image applyKernel()
    {
        // 5x5 image + 3x3 kernel
        // gives 3x3 output
        Image result(3, 3);

        // kernal all values are 1
        int kernal[3][3] = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}};

        // Move kernel over image
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int sum = 0;
                // Process 3x3 window
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        sum = sum + data[i + k][j + l] * kernal[k][l];
                    }
                }
                // Store result
                result(i, j) = sum;
            }
        }
        return result;
    }

    // display
    void display()
    {
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                cout << data[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Image()
    {
        if (data != NULL)
        {
            for (int i = 0; i < nRows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }
    }
}; // CLASS END

int main()
{
    Image img1(5, 5);

    img1(0, 0) = 10;
    img1(0, 1) = 20;
    img1(0, 2) = 30;
    img1(0, 3) = 40;
    img1(0, 4) = 50;

    img1(1, 0) = 20;
    img1(1, 1) = 40;
    img1(1, 2) = 60;
    img1(1, 3) = 80;
    img1(1, 4) = 100;

    img1(2, 0) = 30;
    img1(2, 1) = 60;
    img1(2, 2) = 90;
    img1(2, 3) = 120;
    img1(2, 4) = 150;

    img1(3, 0) = 40;
    img1(3, 1) = 80;
    img1(3, 2) = 120;
    img1(3, 3) = 160;
    img1(3, 4) = 200;

    img1(4, 0) = 50;
    img1(4, 1) = 100;
    img1(4, 2) = 150;
    img1(4, 3) = 200;
    img1(4, 4) = 250;

    cout << "Original 5x5 Image Matrix:" << endl;
    img1.display();

    Image output = img1.applyKernel();

    cout << "\nFiltered 3x3 Output Matrix:" << endl;
    output.display();

    return 0;
}