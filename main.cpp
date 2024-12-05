#include "std_lib_inc.h"

// Funktion zur Berechnung der n-ten Fibonacci-Zahl
// Vorbedingungen:
// 1. n muss positiv sein.
// 2. n darf keinen Überlauf verursachen (maximale Fibonacci-Zahl < 2^15 - 1, also 32767).
int fibonacci(int n)
{
    // Assertions zur Prüfung der Vorbedingungen
    assert(n > 0, "n muss positiv sein.");
    assert(n <= 24, "n darf keinen ueberlauf verursachen (maximal n = 24)."); // Fibonacci[24] = 46368 < 32767

    if (n == 1 || n == 2) return 1; // Erste beiden Fibonacci-Zahlen

    int prev = 1, curr = 1, next = 0;

    for (int i = 3; i <= n; ++i)
    {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main()
{
    activateAssertions(); // Aktiviert Assertions für die Laufzeit

    cout << "Fibonacci-Zahlen-Berechnung\n";
    cout << "Gib eine Zahl zwischen 1 und 24 ein (0 zum Beenden): \n";

    while (true)
    {
        int n;
        cin >> n; // Benutzereingabe

        if (n == 0)
        {
            cout << "Programm beendet.\n";
            break; // Beendet das Programm, wenn 0 eingegeben wird
        }

        // Validierung der Eingabe
        if (n <= 0)
        {
            cout << "Fehler: Die Zahl muss positiv sein. Bitte erneut eingeben.\n";
            continue;
        }
        if (n > 24)
        {
            cout << "Fehler: Die Zahl darf nicht größer als 24 sein. Bitte erneut eingeben.\n";
            continue;
        }

        // Berechnung der Fibonacci-Zahl
        try
        {
            int result = fibonacci(n);
            cout << "Fibonacci[" << n << "] = " << result << "\n";
        } catch (const runtime_error& e) {
            cerr << "Fehler: " << e.what() << "\n";
        }

        cout << "Gib eine Zahl zwischen 1 und 24 ein (0 zum Beenden):\n";
    }
    return 0;
}
