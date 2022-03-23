#include <iostream>
#include <ctime>
#include <string>
#define strip cout << "\n-----------------------------\n"

using namespace std;

void matrix_display(float** matrix, int n);

void swap_strip_connected(float** matrix, int n, int s1, int s2) {
    for (int x = 1; x <= n * 2; x++) {
        // matrix[x][s1] <-> matrix[x][s2]
        float buffer = matrix[x][s1];
        matrix[x][s1] = matrix[x][s2];
        matrix[x][s2] = buffer;
    }
}

void swap_row_connected(float** matrix, int n, int r1, int r2) {
    for (int y = 1; y <= n; y++) {
        //matrix[r1][y] <-> matrix[r2][y] && matrix[r1 + n][y] <-> matrix[r2 + n][y]
        float buffer = matrix[r1][y];
        matrix[r1][y] = matrix[r2][y];
        matrix[r2][y] = buffer;

        buffer = matrix[r1 + n][y];
        matrix[r1 + n][y] = matrix[r2 + n][y];
        matrix[r2 + n][y] = buffer;
    }
}

void mult_srip(float** matrix, int n, int s, float co) {
    for (int x = 1; x <= n * 2; x++) {
        // matrix[x][s] * co
        matrix[x][s] *= co;
    }
}

void mult_row(float** matrix, int n, int r, float co) {
    for (int y = 1; y <= n; y++) {
        // matrix[r][y] * co && matrix[r + n][y] * co
        matrix[r][y] *= co;
        matrix[r + n][y] *= co;
    }
}

void add_strip_to_strip(float** matrix, int n, int s1, int s2, float co) {
    for (int x = 1; x <= n * 2; x++) {
        // matrix[x][s1] + matrix[x][s2] * co
        matrix[x][s1] += matrix[x][s2] * co;
    }
}

void add_row_to_row(float** matrix, int n, int r1, int r2, float co) {
    for (int y = 1; y <= n; y++) {
        // matrix[r1][y] + matrix[r2][y] * co && matrix[r1 + n][y] + matrix[r2 + n][y] * co
        matrix[r1][y] += matrix[r2][y] * co;
        matrix[r1 + n][y] += matrix[r2 + n][y] * co;
    }
}


void hand_array_input(float** matrix, int n) {
    strip;
    cout << "Type array of " << n << " order :\n";
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> matrix[x][y];
        }
    }
}

void random_array_input(float** matrix, int n, int min, int max) {
    srand(time(0));
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            matrix[x][y] = min + rand() % max;
        }
    }
}

void recursive_part_of_JG(float** matrix, int n, int i) {
    //  I -> III
    // go through first row leftward if first value in row is zero serching non zero then swap this strips
    // if first value is non zero divide first strip on this value

    if (matrix[i][i] != 0) {
        mult_srip(matrix, n, i, (1 / matrix[i][i]));
    }
    else {
        int s_s;
        for (int y = i + 1; y <= n; y++){
            if (matrix[i][y] != 0)s_s = y;
            if (y == n && matrix[i][y] == 0) {
                cout << "Reverse matrix does not exsist\n";
                return;
            }
        }
        swap_strip_connected(matrix, n, i, s_s);
        mult_srip(matrix, n, i, (1 / matrix[i][i]));
    }
    matrix_display(matrix, n);

    // IV
    // substract of all remaining strips first strip multiplied on relevant strip first values

    for (int y = 1; y <= n; y++) {
        if (y != i) {
            add_strip_to_strip(matrix, n, y, i, -matrix[i][y]);
        }
    }
    matrix_display(matrix, n);
}

void jordan_gausse_method(float** matrix, int n) {
    recursive_part_of_JG(matrix, n, 1);
    for (int i = 2; i <= n; i++) {
        recursive_part_of_JG(matrix, n, i);
    }


}

void matrix_display(float** matrix, int n) {
    strip;
    int max_length = 0;
    int length = 0;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n * 2; x++) {
            /*
            int copy = matrix[x][y];
            if (copy < 0) {
                copy *= -1;
                length++;
            }
            while (copy > 0) {
                copy /= 10;
                length++;
            }
            */
            string num = to_string(matrix[x][y]);
            length = num.length();
            if (length > max_length)max_length = length;
            length = 0;
        }
    }
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n * 2; x++) {
            /*
            int copy = matrix[x][y];
            if (copy < 0) {
                copy *= -1;
                length++;
            }
            if (copy == 0)length = 1;
            else {
                while (copy > 0) {
                    copy /= 10;
                    length++;
                }
            }
            */
            string num = to_string(matrix[x][y]);
            length = num.length();
            string space = " ";
            for (int i = 0; i < max_length - length; i++) {
                space += " ";
            }

            cout << space << matrix[x][y];
            length = 0;
        }
        cout << endl;
    }
}

int prot_input(int min, int max) {
    int inp;
    while (true) {
        cin >> inp;
        if (inp > max || inp < min) {
            cout << "Wrong input\nType again: ";
        }
        else {
            return inp;
        }
    }
    return inp;
}

int main(){
    bool stop = false;
    while (true) {

        if (stop)break;

        strip;
        cout << " - Two dimentional array : 1\n - Vector : 2\n - Stop : 0\nType task number : ";
        int task = prot_input(0, 2);

        if (task == 1) {
            strip;
            int n;
            cout << "Type order of matrix : ";
            cin >> n;
            float** matrix = new float* [n + 1];

            for (int y = 0; y <= n * 2; y++) {
                matrix[y] = new float[n * 2 + 1];
            }

            for (int y = 1; y <= n; y++) {
                for (int x = n; x <= n * 2; x++) {
                    if (y == x - n)matrix[x][y] = 1;
                    else matrix[x][y] = 0;
                }
            }

            cout << " - Random input : 1\n - Hand input : 2\nType input method : ";

            int method = prot_input(1, 2);

            switch (method)
            {
            case 1:
                random_array_input(matrix, n, 1, 10); // -30 100, 1 10
                break;
            case 2:
                hand_array_input(matrix, n);
                break;
            default:
                break;
            }
            jordan_gausse_method(matrix, n);
            cout << "Final result : " << endl;
            matrix_display(matrix, n);

        }
        else if (task == 2) {
        //
        }
        else if (task == 0) {
            stop = true;
            break;
        }
    }
}