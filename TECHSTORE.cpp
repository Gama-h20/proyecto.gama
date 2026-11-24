
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

const int MAX = 30;

struct Producto {
    string nombre;
    string categoria;
    double precio;
    int stock;
};

Producto productos[MAX];
int cantidadProductos = 12;

double totalVentas = 0;
int compras = 0;

int leerNumero(string mensaje, int minimo, int maximo) {
    int numero;

    do {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Ingrese un numero valido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            numero = minimo - 1;
        }
        else if (numero < minimo || numero > maximo) {
            cout << "Opcion fuera de rango.\n";
        }

    } while (numero < minimo || numero > maximo);

    return numero;
}

double leerPrecio(string mensaje) {
    double precio;

    do {
        cout << mensaje;
        cin >> precio;

        if (cin.fail()) {
            cout << "Ingrese un precio valido.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            precio = -1;
        }
        else if (precio <= 0) {
            cout << "El precio debe ser mayor que cero.\n";
        }

    } while (precio <= 0);

    return precio;
}

void cargarProductos() {
    productos[0] = {"iPhone 15", "Celulares", 750, 10};
    productos[1] = {"Samsung S24", "Celulares", 620, 8};
    productos[2] = {"Xiaomi Redmi", "Celulares", 220, 15};
    productos[3] = {"Laptop HP", "Computadoras", 650, 7};
    productos[4] = {"Laptop Lenovo", "Computadoras", 580, 6};
    productos[5] = {"Monitor ASUS", "Computadoras", 220, 9};
    productos[6] = {"Audifonos JBL", "Accesorios", 65, 20};
    productos[7] = {"Mouse Logitech", "Accesorios", 25, 30};
    productos[8] = {"Teclado RGB", "Accesorios", 80, 12};
    productos[9] = {"PlayStation 5", "Videojuegos", 500, 5};
    productos[10] = {"Control Xbox", "Videojuegos", 60, 14};
    productos[11] = {"Nintendo Switch", "Videojuegos", 300, 6};
}
void encabezado() {
    cout << "\n";
    cout << "==================================================\n";
    cout << "  TTTTT  EEEEE  CCCCC  H   H  SSSSS  TTTTT  OOOOO  RRRR   EEEEE\n";
    cout << "    T    E      C      H   H  S        T    O   O  R   R  E\n";
    cout << "    T    EEEE   C      HHHHH  SSSSS    T    O   O  RRRR   EEEE\n";
    cout << "    T    E      C      H   H      S    T    O   O  R  R   E\n";
    cout << "    T    EEEEE  CCCCC  H   H  SSSSS    T    OOOOO  R   R  EEEEE\n";
    cout << "==================================================\n";
    cout << "              TECNOLOGIA ONLINE                   \n";
    cout << "          [ CELULARES | PC | GAMING ]             \n";
    cout << "==================================================\n";
}

void mostrarProductos() {
    encabezado();

    cout << "\n              PRODUCTOS DISPONIBLES\n\n";

    for (int i = 0; i < cantidadProductos; i++) {
        cout << i + 1 << ". " << productos[i].nombre
             << " | $" << fixed << setprecision(2)
             << productos[i].precio
             << " | Stock: " << productos[i].stock << endl;
    }
}

void comprarProductos() {
    int opcion;
    int cantidad;
    char continuar;
    double total = 0;

    do {
        mostrarProductos();

        opcion = leerNumero(
            "\nSeleccione el producto que desea comprar (0 para salir): ",
            0, cantidadProductos
        );

        if (opcion == 0) {
            break;
        }

        int indice = opcion - 1;

        if (productos[indice].stock == 0) {
            cout << "Este producto esta agotado.\n";
        }
        else {
            cantidad = leerNumero(
                "Cuantas unidades desea comprar: ",
                1, productos[indice].stock
            );

            double subtotal = productos[indice].precio * cantidad;

            productos[indice].stock -= cantidad;
            total += subtotal;

            cout << "\nProducto agregado a tu compra.\n";
            cout << "Subtotal: $" << fixed << setprecision(2)
                 << subtotal << endl;
        }

        cout << "\nDesea comprar otro producto? (S/N): ";
        cin >> continuar;

        continuar = toupper(continuar);

        while (continuar != 'S' && continuar != 'N') {
            cout << "Ingrese S o N: ";
            cin >> continuar;
            continuar = toupper(continuar);
        }

    } while (continuar == 'S');

    if (total > 0) {
        cout << "\n============================================\n";
        cout << "              FACTURA TECHSTORE              \n";
        cout << "============================================\n";
        cout << "TOTAL A PAGAR: $" << fixed << setprecision(2)
             << total << endl;
        cout << "============================================\n";
        cout << "          GRACIAS POR SU COMPRA!\n";
        cout << "          VUELVA PRONTO A TECHSTORE\n";
        cout << "============================================\n";

        totalVentas += total;
        compras++;
    }
    else {
        cout << "\nNo se realizo ninguna compra.\n";
    }
}

void categorias() {
    cout << "\n1. Celulares\n";
    cout << "2. Computadoras\n";
    cout << "3. Accesorios\n";
    cout << "4. Videojuegos\n";

    int opcion = leerNumero("Seleccione una categoria: ", 1, 4);

    string categoria;

    switch (opcion) {
        case 1: categoria = "Celulares"; break;
        case 2: categoria = "Computadoras"; break;
        case 3: categoria = "Accesorios"; break;
        case 4: categoria = "Videojuegos"; break;
    }

    cout << "\nProductos de " << categoria << ":\n";

    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].categoria == categoria) {
            cout << productos[i].nombre
                 << " - $" << productos[i].precio
                 << " - Stock: " << productos[i].stock << endl;
        }
    }
}

void inventario() {
    encabezado();

    for (int i = 0; i < cantidadProductos; i++) {
        cout << productos[i].nombre
             << " | Stock: " << productos[i].stock << endl;
    }

    cout << "\nTotal de productos registrados: "
         << cantidadProductos << endl;
}

void reporteVentas() {
    encabezado();

    cout << "\n========== REPORTE DE VENTAS ==========\n";
    cout << "Compras realizadas: " << compras << endl;
    cout << "Total generado: $" << fixed << setprecision(2)
         << totalVentas << endl;
}

void menu() {
    int opcion;

    do {
        encabezado();

        cout << "\n       BIENVENIDO A TECHSTORE\n\n";
        cout << "1. Comprar productos\n";
        cout << "2. Ver categorias\n";
        cout << "3. Consultar inventario\n";
        cout << "4. Reporte de ventas\n";
        cout << "5. Salir\n";

        opcion = leerNumero("\nSeleccione una opcion: ", 1, 5);

        switch (opcion) {
            case 1: comprarProductos(); break;
            case 2: categorias(); break;
            case 3: inventario(); break;
            case 4: reporteVentas(); break;
            case 5:
                cout << "\nGracias por visitar TECHSTORE. Hasta pronto!\n";
                break;
        }

        if (opcion != 5) {
            cout << "\nPresione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (opcion != 5);
}

int main() {
    cargarProductos();
    menu();

    return 0;
}