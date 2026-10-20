#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name, answer;
    int age;
    float height;
    double weight;
    char lastNameInitial;
    bool isRightHanded;

    cout << "What is your name? ";
    cin >> name;

    cout << "What is your height? ";
    cin >> height;

    cout << "What is your weight? ";
    cin >> weight;

    cout << "What is your last name initial? ";
    cin >> lastNameInitial;

    cout << "Are you right handed? ";
    cin >> answer;

    cout << "Hello " << name << " " << lastNameInitial << "." << endl;
    cout << "Your BMI is: " << weight / (height * height) << endl;

    if (answer == "yes")
    {
        isRightHanded = true;
        cout << "You are right handed";
    }
    else
    {
        isRightHanded = false;
        cout << "You are left handed";
    }

    return 0;
}