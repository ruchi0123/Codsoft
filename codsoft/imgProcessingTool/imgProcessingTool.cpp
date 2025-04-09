#include <iostream>
#include <vector>
using namespace std;

const int WIDTH = 5;
const int HEIGHT = 5;

void displayImage(const vector<vector<int>>& image) {
    cout << "Image Matrix:\n";
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << "\t";
        }
        cout << endl;
    }
}

void applyBrightness(vector<vector<int>>& image, int value) {
    for (auto& row : image) {
        for (auto& pixel : row) {
            pixel = max(0, min(255, pixel + value));  // clamp between 0–255
        }
    }
}

void applyGrayscale(vector<vector<int>>& image) {
    // Simulated grayscale, assume image is already grayscale
    cout << "Grayscale already applied (simulation)." << endl;
}

void applyInvert(vector<vector<int>>& image) {
    for (auto& row : image) {
        for (auto& pixel : row) {
            pixel = 255 - pixel;
        }
    }
}

int main() {
    vector<vector<int>> image(HEIGHT, vector<int>(WIDTH, 128));  // Simulated gray image

    int choice;
    do {
        cout << "\n=== Image Processing Tool ===\n";
        cout << "1. Display Image\n";
        cout << "2. Apply Grayscale\n";
        cout << "3. Adjust Brightness\n";
        cout << "4. Invert Colors\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayImage(image);
                break;
            case 2:
                applyGrayscale(image);
                break;
            case 3: {
                int value;
                cout << "Enter brightness adjustment value (-255 to 255): ";
                cin >> value;
                applyBrightness(image, value);
                cout << "Brightness adjusted.\n";
                break;
            }
            case 4:
                applyInvert(image);
                cout << "Image inverted.\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
