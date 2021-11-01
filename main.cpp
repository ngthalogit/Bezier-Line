#include "Bezier.h"
#include <fstream>
/* Functions :
double PowerFunc(double, int);
int Factorial(int);

double Function_B_u(int, float);
double Function_C_u(float, int);

void inPutByIos();
void outPutByIos();

void inPutFile();
void outPutFile();
*/

ifstream fi;
ofstream fo;

/* Power Function */
double PowerFunc(double x, int y){
	if ( y == 0)
		return 1;
	else
	{
        double P = x;
		for (int i = 1; i < y; i++)
        	P *= x;
    	return P;
	}
}

/* Factorial Function */
int Factorial(int n){
    int P = 1;
    for (int i = 1; i <= n ;i++)
        P *= i;
    return P;
}
 
/* inPut Control Point  B0, B1, B2, B3 */
 
/* Compute B(u) Function corresponding i,n */
 
double Function_B_u(int i, float u){
    double B1 = Factorial(N) / ( Factorial(i)*Factorial(N-i) );
    double temp = (u-a)/(b-a);
    double B2 = PowerFunc(temp, i);
    double B3 = PowerFunc(1-temp, N-i);
    return B1*B2*B3;
}
 
/* Compute C(u) Function corresponding x,y */
 
double Function_C_u(float u, int k){
    double C = 0;
    for (int i = 0; i <= N; i++)
        C += B[i][k]*Function_B_u(i, u);
    return C;
}

void inPutByIos(){
    int i = 0;
    double x, y;
    while ( i <= N)
    {
        cin >> x >> y;
        B[i].push_back(x);
        B[i].push_back(y);
        i++;
    }
}
 
void outPutByIos(){
    int x = 0, y = 1;
    float u = 0;
	cout << endl;
    while ( u <= 1.1) 
    {
        cout << "( " << Function_C_u(u, x) << ", " << Function_C_u(u, y) << " )";
        u += 0.1;
        cout << endl;
    }
}

void inPutFile(){
    fi.open("C:\\DACS\\File\\inPut.txt", ios::in);
    if ( fi.fail() )
    {
        cout << " File inPut does not exist ";
    } 
    else 
    {   
        int i = 0;
        double x, y;
        while ( i <= N )
        {
        fi >> x >> y;
        B[i].push_back(x);
        B[i].push_back(x);
        i++;
        }
        
    }
    fi.close();
}

void outPutFile(){
    fo.open("C:\\DACS\\File\\outPut.txt", ios::out);
    int x = 0, y = 1;
    float u = 0;
    fo << endl;
    while ( u <= 1.1 )
    {
        fo << "( " << Function_C_u(u, x) << ", " << Function_C_u(u, y) << " )";
        u += 0.1;
        fo << endl;
    }
    fo.close();
}

void Option(){
    cout << "-Press 1 : Yes to continue ";
    cout << "\n-Press 2 : No to end \n";
    int o;
    cin >> o;
    while ( o != 1 && o != 2 )
    {
        cout << "-Press 1 : Yes to continue ";
        cout << "\n-Press 2 : No to end \n";  
        cin >> o;
    }
    if ( o == 1 )
    {
        cout << "-Options-\n";
        cout << "1. INPUT from KEYBOARD and OUPUT on CONSOLE. \n2. INPUT and OUTPUT with FILE. \n";
        cout << "3. INPUT from KEYBOARD and OUTPUT with FILE. \n4. INPUT with FILE and OUTPUT on CONSOLE. \n";
        char c;
        cin >> c;
        switch ( c )
        {
        case '1':
            inPutByIos();
            outPutByIos();
            Option();
            break;
        case '2':
            inPutFile();
            outPutFile();
            Option();
            break;
        case '3':
            inPutByIos();
            outPutFile();
            Option();
            break;
        case '4':
            inPutFile();
            outPutByIos();
            Option();
            break;
        default:
            break;
        }
    }
}

int main(){
    system ("chcp 65001");
    cout << "\t\t\t\t    ----------------------------| BASE PROJECT |---------------------------- \n\n\n"; 
    cout << "\t\t\t\t Subject 501 : Xây dựng và tính toán tập hợp điểm của đường cong tham số Bézier \n";
    cout << "Group 9\n";
    cout << "Students : Nguyễn Thành Long - Lê Hữu Long \n";
    cout << "Instructor : PGS.TS Nguyễn Tấn Khôi  \n\n";
    cout << "\t\t\t\t\t\t\t\t   -OPTIONS-\n\n";
    cout << "\t1. INPUT from KEYBOARD and OUPUT on CONSOLE. \n\t2. INPUT and OUTPUT with FILE. \n";
    cout << "\t3. INPUT from KEYBOARD and OUTPUT with FILE. \n\t4. INPUT with FILE and OUTPUT on CONSOLE. \n";
    char c;
    cin >> c;
    switch ( c )
    {
    case '1':
        inPutByIos();
        outPutByIos();
        Option();
        break;
    case '2':
        inPutFile();
        outPutFile();
        Option();
        break;
    case '3':
        inPutByIos();
        outPutFile();
        Option();
        break;
    case '4':
        inPutFile();
        outPutByIos();
        Option();
        break;
    default:
        break;
    }
    return 0;
}