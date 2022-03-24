#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <math.h>
#define strip cout << "\n-----------------------------\n"
#define size 3

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

//----------------------------------------------------------------------------------------------

struct Point {
    int x, y;
};

void hand_points_fill(vector <Point>* points) {
    for (int i = 0; i < size; i++){
        int x, y;
        cin >> x >> y;
        points->push_back({ x,y });
    }
}

void random_points_fill(vector <Point>* points, Point min, Point max) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int x, y;
        x = rand() % max.x + min.x;
        y = rand() % max.y + min.y;
        points->push_back({ x,y });
    }
}

void display_points(vector <Point>* points) {
    for (int i = 0; i < size; i++) {
        cout << "(" << points->at(i).x << "," << points->at(i).y << ")" << endl;
    }
}

string disp_point(Point p) {
    return '(' + to_string(p.x) + ',' + to_string(p.y) + ')';
}

bool checks_points(vector <Point>* points, int p1, int p2) {
    cout << "Now : " << disp_point(points->at(p1)) << " " << disp_point(points->at(p2)) << endl;
    double x1, x2, y1, y2;
    x1 = points->at(p1).x;
    x2 = points->at(p2).x;
    y1 = points->at(p1).y;
    y2 = points->at(p2).y;

    double k = (y2 - y1) / (x2 - x1);
    double angle = abs(atan(k) * 180 / 3.1415926535);

    bool check_y;

    if (angle < 45 || angle > 135) {
        //check by y
        check_y = true;
    }
    else {
        check_y = false;
    }

    bool is_on_one_side = true;
    bool side = true; // true - left, false - rigth
    int zero = 0;
    for (int i = 0; i < size; i++) {
        double x, y;
        if (i == p1 || i == p2) {
            cout << "Point is line base\n";
            zero++;
            continue;
        }
        x = points->at(i).x;
        y = points->at(i).y;
        if (check_y) {
            double line_y = ((x - x1) * (y2 - y1) - y1 * x1 + y1 * x2) / (x2 - x1);
            if (i == 0) {
                if (y > line_y)side = true;
                else side = false;
            }
            else {
                bool now_side;
                if (y > line_y) {
                    now_side = true;
                }
                else now_side = false;

                if (now_side != side) {
                    is_on_one_side = false;
                    break;
                }
            }
        }
        else {
            double line_x = ((y - y1) * (x2 - x1) - x1 * y1 + x1 * y2) / (y2 - y1);
            if (i == zero) {
                if (x > line_x)side = false;
                else side = true;
            }
            else {
                bool now_side;
                if (x > line_x) {
                    now_side = false;
                }
                else now_side = true;

                if (now_side != side) {
                    is_on_one_side = false;
                    break;
                }
            }
        }
        cout << "(" << x << "," << y << ")" << endl;
    }
    if (is_on_one_side) {
        cout << "Every point is on one side\n";
        return true;
    }
    else {
        cout << "Not every point on one side\n";
        return false;
    }
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
            vector <Point> points;
            strip;
            cout << " - Random input : 1\n - Hand input : 2\nType input method : ";
            int method = prot_input(1, 2);
            if (method == 2) {
                hand_points_fill(&points);
            }
            else if (method == 1) {
                random_points_fill(&points, { 0,0 }, {10,10});
            }
            display_points(&points);
            
            bool is_every_point = true;
            for (int i = 0; i < size; i++) {
                bool have_point = false;
                for (int j = 0; j < size; j++) {
                    if (i == j)continue;
                    bool is_on_one_side = checks_points(&points, i, j);
                    if (is_on_one_side) {
                        have_point = true;
                        break;
                    }
                }
                if (!have_point) {
                    is_every_point = false;
                    break;
                }
            }
            if (is_every_point)cout << "Yes\n";
            else cout << "Not every point have so pair\n";
        }
        else if (task == 0) {
            stop = true;
            break;
        }
    }
}