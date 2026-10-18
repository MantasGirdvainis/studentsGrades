#include <iostream>
#include <string>

using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

void meniu() {
    cout << endl;
    cout << "=== MOKINIŲ PAŽYMIŲ SISTEMA ===" << endl;
    cout << "1. Įvesti mokinį ir jo pažymius" << endl;
    cout << "2. Peržiūrėti visų mokinių pažymius" << endl;
    cout << "3. Peržiūrėti konkretaus mokinio pažymius" << endl;
    cout << "4. Atnaujinti pažymį" << endl;
    cout << "5. Apskaičiuoti mokinio vidurkį" << endl;
    cout << "6. Pašalinti mokinį" << endl;
    cout << "7. Išeiti" << endl;
    cout << "Pasirinkite: ";
}

int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazymiuKiekis[MAX_MOKINIU];
    int mokiniuKiekis = 0;

    int pasirinkimas;

    do {
        meniu();
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: {
                if (mokiniuKiekis >= MAX_MOKINIU) {
                    cout << "Pasiektas mokinių limitas (" << MAX_MOKINIU << ")." << endl;
                    break;
                }

                string vardas;
                cout << "Įveskite mokinio vardą: ";
                cin >> vardas;
                vardai[mokiniuKiekis] = vardas;

                int kiekis;
                cout << "Kiek pažymių įvesite (0-" << MAX_PAZYMIU << ")? ";
                cin >> kiekis;
                while (kiekis < 0 || kiekis > MAX_PAZYMIU) {
                    cout << "Neteisingas kiekis. Įveskite skaičių nuo 0 iki " << MAX_PAZYMIU << ": ";
                    cin >> kiekis;
                }

                for (int j = 0; j < kiekis; j++) {
                    int pazymys;
                    cout << "Įveskite " << j + 1 << "-ą pažymį: ";
                    cin >> pazymys;
                    while (pazymys < 1 || pazymys > 10) {
                        cout << "Pažymys turi būti nuo 1 iki 10. Įveskite iš naujo: ";
                        cin >> pazymys;
                    }
                    pazymiai[mokiniuKiekis][j] = pazymys;
                }

                pazymiuKiekis[mokiniuKiekis] = kiekis;
                mokiniuKiekis++;
                cout << "Mokinys pridėtas." << endl;
                break;
            }
            case 2:
                if (mokiniuKiekis == 0) {
                    cout << "Mokinių sąrašas tuščias." << endl;
                    break;
                }

                for (int i = 0; i < mokiniuKiekis; i++) {
                    cout << i + 1 << ". " << vardai[i] << ": ";
                    if (pazymiuKiekis[i] == 0) {
                        cout << "pažymių nėra";
                    } else {
                        for (int j = 0; j < pazymiuKiekis[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
                break;
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                cout << "Programa uždaryta" << endl;
                break;
            default:
                cout << "Tokio pasirinkimo nėra. Pasirinkite nuo 1 iki 7." << endl;
        }
    } while (pasirinkimas != 7);

    return 0;
}
