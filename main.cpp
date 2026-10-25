#include <iostream>
#include <string>
#include <iomanip>

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
            case 3: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokinių sąrašas tuščias." << endl;
                    break;
                }

                int mokinioNr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuKiekis << ", 0 - grįžti į meniu): ";
                cin >> mokinioNr;
                while (mokinioNr < 0 || mokinioNr > mokiniuKiekis) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuKiekis << " (0 - grįžti į meniu): ";
                    cin >> mokinioNr;
                }

                if (mokinioNr == 0) {
                    break;
                }

                int indeksas = mokinioNr - 1;
                cout << vardai[indeksas] << ": ";
                if (pazymiuKiekis[indeksas] == 0) {
                    cout << "pažymių nėra";
                } else {
                    for (int j = 0; j < pazymiuKiekis[indeksas]; j++) {
                        cout << pazymiai[indeksas][j] << " ";
                    }
                }
                cout << endl;
                break;
            }
            case 4: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokinių sąrašas tuščias." << endl;
                    break;
                }

                int mokinioNr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuKiekis << ", 0 - grįžti į meniu): ";
                cin >> mokinioNr;
                while (mokinioNr < 0 || mokinioNr > mokiniuKiekis) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuKiekis << " (0 - grįžti į meniu): ";
                    cin >> mokinioNr;
                }

                if (mokinioNr == 0) {
                    break;
                }

                int indeksas = mokinioNr - 1;
                if (pazymiuKiekis[indeksas] == 0) {
                    cout << vardai[indeksas] << " neturi pažymių." << endl;
                    break;
                }

                cout << vardai[indeksas] << " pažymiai:" << endl;
                for (int j = 0; j < pazymiuKiekis[indeksas]; j++) {
                    cout << j + 1 << ". " << pazymiai[indeksas][j] << endl;
                }

                int pazymioNr;
                cout << "Įveskite pažymio numerį (1-" << pazymiuKiekis[indeksas] << ", 0 - grįžti į meniu): ";
                cin >> pazymioNr;
                while (pazymioNr < 0 || pazymioNr > pazymiuKiekis[indeksas]) {
                    cout << "Neteisingas pažymio numeris. Įveskite skaičių nuo 1 iki " << pazymiuKiekis[indeksas] << " (0 - grįžti į meniu): ";
                    cin >> pazymioNr;
                }

                if (pazymioNr == 0) {
                    break;
                }

                int naujasPazymys;
                cout << "Įveskite naują pažymį: ";
                cin >> naujasPazymys;
                while (naujasPazymys < 1 || naujasPazymys > 10) {
                    cout << "Pažymys turi būti nuo 1 iki 10. Įveskite iš naujo: ";
                    cin >> naujasPazymys;
                }

                pazymiai[indeksas][pazymioNr - 1] = naujasPazymys;
                cout << "Pažymys atnaujintas." << endl;
                break;
            }
            case 5: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokinių sąrašas tuščias." << endl;
                    break;
                }

                int mokinioNr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuKiekis << ", 0 - grįžti į meniu): ";
                cin >> mokinioNr;
                while (mokinioNr < 0 || mokinioNr > mokiniuKiekis) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuKiekis << " (0 - grįžti į meniu): ";
                    cin >> mokinioNr;
                }

                if (mokinioNr == 0) {
                    break;
                }

                int indeksas = mokinioNr - 1;
                if (pazymiuKiekis[indeksas] == 0) {
                    cout << vardai[indeksas] << " neturi pažymių, vidurkio apskaičiuoti negalima." << endl;
                    break;
                }

                int suma = 0;
                for (int j = 0; j < pazymiuKiekis[indeksas]; j++) {
                    suma = suma + pazymiai[indeksas][j];
                }

                double vidurkis = (double) suma / pazymiuKiekis[indeksas];
                cout << vardai[indeksas] << " vidurkis: " << fixed << setprecision(2) << vidurkis << endl;
                break;
            }
            case 6: {
                if (mokiniuKiekis == 0) {
                    cout << "Mokinių sąrašas tuščias." << endl;
                    break;
                }

                int mokinioNr;
                cout << "Įveskite mokinio numerį (1-" << mokiniuKiekis << ", 0 - grįžti į meniu): ";
                cin >> mokinioNr;
                while (mokinioNr < 0 || mokinioNr > mokiniuKiekis) {
                    cout << "Neteisingas mokinio numeris. Įveskite skaičių nuo 1 iki " << mokiniuKiekis << " (0 - grįžti į meniu): ";
                    cin >> mokinioNr;
                }

                if (mokinioNr == 0) {
                    break;
                }

                int indeksas = mokinioNr - 1;
                string pasalintasVardas = vardai[indeksas];

                for (int i = indeksas; i < mokiniuKiekis - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuKiekis[i] = pazymiuKiekis[i + 1];
                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }

                mokiniuKiekis--;
                cout << "Mokinys " << pasalintasVardas << " pašalintas." << endl;
                break;
            }
            case 7:
                cout << "Programa uždaryta" << endl;
                break;
            default:
                cout << "Tokio pasirinkimo nėra. Pasirinkite nuo 1 iki 7." << endl;
        }
    } while (pasirinkimas != 7);

    return 0;
}
