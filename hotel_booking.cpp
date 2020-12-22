
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <ctime>

using namespace std;
double addition (int checkin)

 {
	string cancel,pay;
	double bed,breakfast;


	cout<<"\nNo de cama supletoria (1 cama = 50 RM / noche): ";
	cin>>bed;
	cout<<endl;
	cout<<"No. de pax para el desayuno (RM15 / pax): ";
	cin>>breakfast;
	cout<<endl;
	cout<<"¿Quieres una política de cancelación gratuita? (RM50) (sí / no): " ;
	cin>>cancel;
	cout<<endl;
	cout<<"¿Quiere pagar ahora o en cualquier momento entre la fecha actual y 3 días antes de la fecha de entrada? "<<endl;
	cout<<"Si paga 3 días antes de la fecha de entrada, se le cobrará un total de RM30 (sí / no)"<<endl;
	cin>>pay;
	double total=0;
	bed=bed*50*checkin;
	breakfast=breakfast*15*checkin;
	if(cancel=="si")
    {total+=50;}//precio una noche?
    else if ( cancel=="no")
    {total+=0;}

    if (pay == "si")
    {total+=0;}
    else if (pay == "no")
    {total+=30;}

	total=total+bed+breakfast;
	return total;
}


void payment(double sum,double addf,string name,string address,string hpnum,int room,int people,int day1,int month1,int year1,int day2,int month2,int year2,int days)
{

  double tax = 0;
  double total = 0;
  tax=(sum+addf)*0.1;
  total=tax+sum+addf;

  string room_type;
  if (room==1)
  {
      room_type="Standard";
  }
  else if (room==2)
  {
      room_type="Deluxe";
  }

   cout <<"\t\t\t\t*************************\n"<<endl;
   cout <<"\t\t\t\t   MauHotel"<<endl;
   cout <<"\n\t\t\t\t*************************"<<endl<<endl;
   cout << "Nombre :"<<name<<endl;
   cout << "Localicacion :"<<address<<endl;
   cout << "Nombre de telefono :"<<hpnum<<endl<<endl;
   cout << "habitacion \t\t\t: "<<room_type<<endl;
   cout << "Inquilinos \t\t: "<<people<<" people"<<endl;
   cout << "Registrarse \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
   cout << "dia de retirada \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
   cout << "Duración de la estancia \t: "<<days<<endl<<endl;
   cout << "Precio de la habitación\t\t: RM"<<sum<<endl;
   cout << "Cuotas adicionales \t: RM"<<addf<<endl;
   cout << "Impuesto de servicio (10%)\t: RM"<<tax<<endl;
   cout << "Total final \t\t: RM"<<total<<endl<<endl;
   cout << "¡Gracias por reservar con nosotros! ¡Disfruta tu estancia!"<<endl;
   cout << "Para obtener más información, contáctenos al 03-6557889 o visite nuestro instagram @mauhotel"<<endl;

  fstream myfile;
   myfile.open ("receipt.txt");
   myfile <<"\t\t\t\t*************************\n"<<endl;
   myfile <<"\t\t\t\t   MauHotel"<<endl;
   myfile<<"\n\t\t\t\t*************************"<<endl<<endl;
   myfile << "Nombre :"<<name<<endl;
   myfile << "Localizacion :"<<address<<endl;
   myfile << "numero de telefono :"<<hpnum<<endl<<endl;
   myfile << "Habitacion \t\t\t: "<<room_type<<endl;
   myfile << "Inquilinos \t\t: "<<people<<" people"<<endl;
   myfile << "Registrarse \t\t: "<<day1<<"/"<<month1<<"/"<<year1<<endl;
   myfile << "Dia de salida \t\t: "<<day2<<"/"<<month2<<"/"<<year2<<endl;
   myfile << "Duración de la estancia \t: "<<days<<endl<<endl;
   myfile << "Precio de la habitación\t\t: RM"<<sum<<endl;
   myfile << "Cuotas adicionales \t: RM"<<addf<<endl;
   myfile << "Impuesto de servicio (10%)\t: RM"<<tax<<endl;
   myfile << "Total final \t\t: RM"<<total<<endl<<endl;
   myfile << "¡Gracias por reservar con nosotros! ¡Disfruta tu estancia!"<<endl;
   myfile << "Para obtener más información, contáctenos al 03-6557889 o visite nuestro instagram @mauhotel"<<endl;

  myfile.close();

}


double date (int day1,int month1, int year, int day2, int month2, int year4,int room )
{   int i;
    double difference;
    month1-=1;
    month2-=1;
    struct tm a = {0,0,0,day1,month1,year};
    struct tm b = {0,0,0,day2,month2,year4}; //104 = 2004
    time_t x = mktime(&a);
    time_t y = mktime(&b);
    double days;
    if ( x != (std::time_t)(-1) && y != (time_t)(-1) )
    {
        double difference = difftime(y, x) / (60 * 60 * 24);
        cout << ctime(&x);
        cout << ctime(&y);
        cout << "diferencia = " << difference << " dias" << endl;
        days=difference;
    }

    cout<<days<<endl;
    return days;

}
int main()
{

    string name;
    string address;
    string hpnum;
    string add;
    int room;
    int people;
    int day1,month1,year1;
    int day2,month2,year2;
    int i,year,year4;
    start:
    cout<<"\n\t\t\t\t*************************";
    cout<<"\n\t\t\t\t          MauHotel ";
    cout<<"\n\t\t\t\t      * MENU PRINCIPAL *";
    cout<<"\n\t\t\t\t*************************";

    cout<<"\n\nIntroduzca la fecha de entrada:\n\n"<<endl;;
    cin>>day1>>month1>>year1;
    year=year1-1900;
    system("cls");

    cout<<day1<<"/"<<month1<<"/"<<year1<<endl;
    cout<<"Enter your name"<<endl;
    cin>>name;
    cout<<"Ingrese su direccion"<<endl;
    cin>>address;
    cout<<"Ingrese su número de teléfono"<<endl;
    cin>>hpnum;
    cout<<"Ingrese el número de inquilinos"<<endl;
    cin>>people;
    cout<<"Elija su habitación preferida"<<endl;
    cout<<"Presione '1' para habitación estándar"<<endl;
    cout<<"Presione '2' para habitación de lujo"<<endl;
    cin>>room;
    cout<<"Ingrese su fecha de salida"<<endl;
    cin>>day2>>month2>>year2;
    year4=year2-1900;
    double days = date (day1,month1, year, day2, month2, year4,room);
    //system("cls");
    double sum=0;
    double addf=0;

    if (people<=2&&people>0)
    {
        if (room==1)
        {
            sum+=100;
            for(i=2;i<=days;i++)
            {
                sum+=70;
            }
        }

        else if (room==2)
        {
             sum+=200;
            for(i=2;i<=days;i++)
            {
                sum+=150;
            }
        }

    }
    else if (people<=4&&people>2)
    {
        if (room==1)
        {
            sum+=150;
            for(i=2;i<=days;i++)
            {
                sum+=120;
            }
        }

        else if (room==2)
        {
             sum+=300;
            for(i=2;i<=days;i++)
            {
                sum+=200;
            }
        }

    }
    else if (people<=6&&people>4)
    {
        if (room==1)
        {
            sum+=250;
            for(i=2;i<=days;i++)
            {
                sum+=150;
            }
        }

        else if (room==2)
        {
             sum+=400;
            for(i=2;i<=days;i++)
            {
                sum+=250;
            }
        }

    }
    cout<<sum<<endl;
    system("cls");
    cout<<"¿Quieres una cama supletoria o algún otro servicio? Escriba sí o no"<<endl;
    cin>>add;
   if (add=="si")
    {
     addf=addition (days);
    }
    cout<<addf<<endl;
    system("cls");
    payment(sum,addf,name,address,hpnum,room,people,day1,month1,year1,day2,month2,year2,days);
    string choice;
    cout<<"¿Quieres reservar otra habitación?  (si/no)?"<<endl;
    cin>> choice;
    if (choice=="si")
    {
        goto start;
    }
    else if (choice=="no")
    {
        return 0;
    }


}

