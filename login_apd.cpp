#include <iostream>
using namespace std;

int main(){
		string user, pass;
		
		cout << "Login\n\n";
		login:
		cout << "Username    = ";
		cin >> user;
		cout << "Password    = "
		cin >> pass;
		
		
		if(user=="admin"&&pass=="admin123"){
			cout << "Login berhasil";
		} else {
			cout << "Password atau username salah\n";
			goto login;
		}
		return 0;
}
