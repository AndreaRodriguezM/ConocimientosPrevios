#include <iostream>
#include <locale>
#include <string>


using namespace std;

struct CD
{
    int codigo;
    string artista;
    string album;
    int no_canciones;
    float precio;
    int existencias;
};

void agregarCD(CD[], int&);
void mostrarCDs(CD[], int);
void buscarPorCodigo(CD[], int);
void modificarCD(CD[], int);
void realizarVenta(CD[], int);

int main()
{
    CD cds[50];
    int numCDs = 0;
    int opc;

    setlocale(LC_ALL,"");
    while (true)
    {
        cout<<"------------MENÚ CONTROL DE CDs------------"<<endl;
        cout<<""<<endl;
        cout<<"\t1. Agregar CD"<<endl;
        cout<<"\t2. Mostrar todos los CDs"<<endl;
        cout<<"\t3. Buscar por codigo"<<endl;
        cout<<"\t4. Modificar"<<endl;
        cout<<"\t5. Realizar una venta"<<endl;
        cout<<"\t6. Salir"<<endl;
        cout<<"\n\t Ingrese una opción: ";
        cin>>opc;

        system("cls");

        switch (opc)
        {
        case 1:
            agregarCD(cds, numCDs);
            break;
        case 2:
            mostrarCDs(cds, numCDs);
            break;
        case 3:
            buscarPorCodigo(cds, numCDs);
            break;
        case 4:
            modificarCD(cds, numCDs);
            break;
        case 5:
            realizarVenta(cds, numCDs);
            break;
        case 6:
            cout<<"\nSALIENDO DEL PROGRAMA." << endl;
            return 0;
        default:
            cout<<"\nSELECCIONA UNA OPCION VALIDA." << endl;
            cout<<""<<endl;
            break;
        }
    }

    return 0;
}

void agregarCD(CD cds[], int& numCDs)
{
    if(numCDs<50)
    {
        cout<<"\tTeclea el codigo del CD: ";
        cin>>cds[numCDs].codigo;

        cout<<"\tTeclea el nombre del artista: ";
        cin.ignore();
        getline(cin, cds[numCDs].artista);

        cout<<"\tTeclea el nombre del album: ";
        getline(cin, cds[numCDs].album);

        cout<<"\tTeclea el numero de canciones: ";
        cin>>cds[numCDs].no_canciones;

        cout<<"\tTeclea el precio: ";
        cin>>cds[numCDs].precio;

        cout<<"\tTeclea la cantidad de existencias: ";
        cin>>cds[numCDs].existencias;
        cout<<"\n\t---------------------------------------------"<<endl;
        numCDs++;
        cout<<"\n\t¡EL CD FUE AGREGADO CON EXITO!\n"<<endl;

    }
    else
    {
        cout<<"\nEL LIMITE DE CDs HA SIDO ALCANZADO."<<endl;
    }

    system("pause");
    system("cls");
}

void mostrarCDs(CD cds[], int numCDs)
{
    if (numCDs == 0)
    {
        cout<<"\nNO HAY CDs."<<endl;
        return;
    }

    cout<<"\t--------------------LISTA DE CDS--------------------"<<endl;

    for (int i = 0; i < numCDs; i++)
    {
        cout<<"Codigo: " << cds[i].codigo<<endl;
        cout<<"Artista: " << cds[i].artista<<endl;
        cout<<"Álbum: " << cds[i].album<<endl;
        cout<<"Número de canciones: "<< cds[i].no_canciones <<endl;
        cout<<"Precio: "<< cds[i].precio <<endl;
        cout<<"Existencias: "<< cds[i].existencias <<endl;
        cout<<"-------------------------------------------"<<endl;
    }

    system("pause");
    system("cls");
}

void buscarPorCodigo(CD cds[], int numCDs)
{
    int codigo;
    cout<<"\n\tTeclea el código a buscar: ";
    cin>>codigo;
    system("pause");
    system("cls");

    for(int i = 0; i < numCDs; i++)
    {
        if(cds[i].codigo == codigo)
        {
            cout<<" CD encontrado: "<<endl;

            cout<<"Código: "<< cds[i].codigo <<endl;
            cout<<"Artista: "<< cds[i].artista <<endl;
            cout<<"Álbum: "<< cds[i].album << endl;
            cout<<"Número de canciones: " << cds[i].no_canciones <<endl;
            cout<<"Precio: "<< cds[i].precio <<endl;
            cout<<"Existencias: "<< cds[i].existencias <<endl;
            return;
        }
    }
    cout<<"\n\tCD NO ENCONTRADO."<< endl;

    cout<<"";
    system("pause");
    system("cls");
}

void modificarCD(CD cds[], int numCDs)
{
    int codigo;
    cout<<"\tIngrese el código del CD a modificar: ";
    cin>>codigo;

    for(int i = 0; i < numCDs; i++)
    {
        if(cds[i].codigo == codigo)
        {
            cout<<"\tIngrese el nuevo precio: ";
            cin>>cds[i].precio;

            cout<<"\tIngrese la nueva cantidad de existencias: ";
            cin>>cds[i].existencias;

            cout<<"\tCD MODIFICADO CON EXITO."<<endl;
            return;
        }
    }
    cout<<"\tEL CD NO SE HA ENCONTRADO."<<endl;

    system("pause");
    system("cls");
}

void realizarVenta(CD cds[], int numCDs)
{
    int codigo, cantidad;
    cout<<"\n\tIngrese el código del CD a vender: ";
    cin>>codigo;

    for(int i = 0; i < numCDs; i++)
    {
        if(cds[i].codigo == codigo)
        {
            cout<<"\n\tIngrese la cantidad a vender: ";
            cin>>cantidad;

            if (cantidad <= cds[i].existencias)
            {
                cds[i].existencias -= cantidad;
                cout<<"\tVENTA REALIZADO CON EXITO."<<endl;
                return;
            }
            else
            {
                cout<<"\tNO HAY SUFICIENTES EXISTENCIAS."<<endl;
                return;
            }
        }
    }
    cout<<"CD NO ENCONTRADO."<<endl;
    system("pause");
    system("cls");
}

