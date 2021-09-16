#include <iostream>
#include <vector>

using namespace std;

void show_menu (vector<int> numbers);
void get_selection (vector<int> numbers);
void do_work (char selection , vector<int> numbers);
void print_numbers (vector<int> numbers);
void add_number(vector<int> &numbers);
void calculate_sum_average (vector<int> numbers);
void determine_the_smallest (vector<int> numbers);
void determine_the_largest (vector<int> numbers);

int main() {

    vector<int> numbers;

    show_menu(numbers);

    cout << "Goodbye..." << endl;

    return 0;
}

void show_menu (vector<int> numbers) {

    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;

    get_selection(numbers);

}

void get_selection (vector<int> numbers) {

    char selection;

    cout << "\nEnter your choice:";
    cin >> selection;
    cout << endl;

    do_work(selection , numbers);

}

void do_work (char selection , vector<int> numbers) {

    switch (selection) {

        case 'p':
        case 'P':

            print_numbers(numbers);

            break;

        case 'a':
        case 'A':

            add_number (numbers);

            break;

        case 'm':
        case 'M':

            calculate_sum_average (numbers);

            break;

        case 's':
        case 'S':

            determine_the_smallest (numbers);

            break;

        case 'l':
        case 'L':

            determine_the_largest(numbers);

            break;

        case 'q':
        case 'Q':
            break;

        default:

            cout << "invalid selection!!!" << endl;

            show_menu(numbers);

            break;

    }

}

void print_numbers (vector<int> numbers) {

    if (numbers.empty()) {

        cout << "[] - the list is empty" << endl;

    } else {

        cout << "[ ";

        for (auto number : numbers) {

            cout << number << " ";

        }

        cout << "]" << endl;

    }

    show_menu(numbers);

}

void add_number(vector<int> &numbers) {

    int add_number;
    bool done = true;

    cout << "write -1 to cancel adding number.\n" << endl;

    while (done) {

        cout << "Enter an integer number:";
        cin >> add_number;

        if (add_number == -1) {

            done = false;

        } else {

            numbers.push_back(add_number);
            cout << add_number << " added\n" << endl;

        }

    }

    show_menu(numbers);

}

void calculate_sum_average (vector<int> numbers) {

    double sum{0};

    if (numbers.empty()) {

        cout << "Unable to calculate the mean - no data!" << endl;

    } else {

        for (auto number : numbers) {

            sum += number;

        }

        cout << "sum= " << sum << " and average= " << sum / static_cast<double> (numbers.size()) << endl;

    }

    show_menu(numbers);

}

void determine_the_smallest (vector<int> numbers) {

    int smallest;

    if (numbers.empty()) {

        cout << "Unable to determine the smallest number - list is empty" << endl;

    } else {

        smallest = numbers.at(0);

        for (auto number : numbers) {

            if (number <= smallest) {

                smallest = number;

            }

        }

        cout << "The smallest number is " << smallest << endl;

    }

    show_menu(numbers);

}

void determine_the_largest (vector<int> numbers) {

    int largest;

    if (numbers.empty()) {

        cout << "Unable to determine the largest number - list is empty" << endl;

    } else {

        largest = numbers.at(0);

        for (auto number : numbers) {

            if (number >= largest) {

                largest = number;

            }

        }

        cout << "The largest number is " << largest << endl;

    }

    show_menu(numbers);

}
