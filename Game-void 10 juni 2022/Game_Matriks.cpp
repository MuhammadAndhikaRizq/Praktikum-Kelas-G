#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 75
#define KEY_LEFT 77
#define KEY_RIGHT 80


struct animalsInfo {
	string nama;
	string habitat;
	string kelangkaan;
	int Hp;
	int harga;
	
};

struct senjataInfo{
	string nama;
	int dmg;
	
	printKekuatan() {
		cout << "Kekuatan dari " << nama << " !!! " << "Sisa darah " << dmg << "\n"; 
	}
	
	attack(animalsInfo animalsHp){
		dmg = animalsHp.Hp - dmg;
		cout<<" Damage yang diterima oleh " << animalsHp.nama << " Dengan Hp : " << animalsHp.Hp << endl;
		printKekuatan();
	}
};

void rulesinfo(){
	cout << "Movement KEY\n";
    cout << "PageUp\n";
    cout << "PageDown\n";
    cout << "ArrowRight\n";
    cout << "ArrowLeft\n";
    cout << "===================\n";
    cout << "Selamat Bermain\n";
    cout << "===================\n";
}
int main() {
    // Animals Hunter, With Pokemon Style Game
    //Hunting Hewan langka sebanyak mungkin di sebuah pulau rahasia
    
    /*
    KEY_MAP IN GAME
    1 = jalan
    2 = pohon
    5 = batu
    6 = semak
    7 = sungai
    8 = jembatan
	*/
    
    char lawan, Y, T;
    int panjangPeta = 15; // x
    int lebarPeta = 12; // y
    int posisiKarakterY = 10;
    int posisiKarakterX = 2;
    int randomAnimal;
    int pilih;
    int attlagi;
    
    animalsInfo animals[]{
		{
			"Giant Crocodile",
			"Water",
			"Rare",
			5000,
			500000000
		},
		{
			"Red Lion",
			"forest",
			"Super Rare",
			4500,
			1500000000
		},
		{
			"Silver Elephant",
			"forest",
			"Rare",
			15000,
			500000000
		},
		{
			"Fire Cobra",
			"bush",
			"Super Legendary",
			2000,
			500000000000000
		},
		{
			"Lynx",
			"forest",
			"Common",
			3500,
			2000000
		},
	
	};
    
    rulesinfo();
    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";
    
    int peta[lebarPeta][panjangPeta] = {
        {5,5,5,5,5,5,1,1,7,7,7,7,6,6,6},
        {5,5,1,1,5,5,1,6,7,7,7,7,6,6,1},
        {1,1,1,1,1,1,1,6,7,7,7,7,5,5,1},
        {2,2,1,1,2,2,2,6,7,7,7,7,5,5,1},
        {2,2,1,1,1,1,1,1,7,7,7,7,5,5,1},
        {2,2,1,1,1,2,2,1,7,7,7,7,5,5,1},
        {2,2,1,1,2,2,2,1,7,7,7,7,6,6,1},
        {2,2,2,1,1,2,2,1,8,8,8,8,1,1,1},
        {2,2,2,1,1,2,2,1,8,8,8,8,2,2,2},
        {5,5,5,1,1,2,1,1,7,7,7,7,2,2,2},
        {1,1,1,1,2,2,6,6,7,7,7,7,2,2,2},
        {5,5,5,5,5,5,6,6,7,7,7,7,2,2,2},
    };
    
    
    int arrowKey = 0;
    
    /*
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    */
    
    while(1) {
    	
    	
    	randomAnimal = rand() % 50;
        // Input Keyboard
        cout << "Input arrow key ";
        arrowKey = getch();
        cout << "Arrow key yang dimasukan " << arrowKey << "\n";
        
        //clear screen
        system("cls");
        
        if (arrowKey == 72 && posisiKarakterY > 0) {
            if (peta[posisiKarakterY - 1][posisiKarakterX] == 1 || peta[posisiKarakterY - 1][posisiKarakterX] == 6 || peta[posisiKarakterY - 1][posisiKarakterX] == 8) {
                posisiKarakterY--;
            }
        } else if (arrowKey == 75 && posisiKarakterX > 0) {
            if (peta[posisiKarakterY][posisiKarakterX - 1] == 1 || peta[posisiKarakterY][posisiKarakterX - 1] == 6 || peta[posisiKarakterY][posisiKarakterX - 1] == 8) {
                posisiKarakterX--;
            }
        } else if (arrowKey == 77 && posisiKarakterX < lebarPeta) {
            if (peta[posisiKarakterY][posisiKarakterX + 1] == 1 || peta[posisiKarakterY][posisiKarakterX + 1] == 6 || peta[posisiKarakterY][posisiKarakterX + 1] == 8) {
                posisiKarakterX++;
            }
        } else if (arrowKey == 80 && posisiKarakterY < panjangPeta) {
            if (peta[posisiKarakterY + 1][posisiKarakterX] == 1 || peta[posisiKarakterY + 1][posisiKarakterX] == 6 || peta[posisiKarakterY + 1][posisiKarakterX] == 8) {
                posisiKarakterY++;
            }
        }
        
        // Render grafik
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {
                
                if(posisiKarakterX == x && posisiKarakterY == y) {
                    cout << 0 << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
        
        
        //Cek obstacle
        if (arrowKey == 72 && posisiKarakterY > 0) {
            if (peta[posisiKarakterY - 1][posisiKarakterX] == 2 || peta[posisiKarakterY - 1][posisiKarakterX] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        } else if (arrowKey == 75 && posisiKarakterX > 0) {
            if (peta[posisiKarakterY][posisiKarakterX - 1] == 2 || peta[posisiKarakterY][posisiKarakterX - 1] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        } else if (arrowKey == 77 && posisiKarakterX < (panjangPeta - 1)) {
            if (peta[posisiKarakterY][posisiKarakterX + 1] == 2 || peta[posisiKarakterY][posisiKarakterX + 1] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        } else if (arrowKey == 80 && posisiKarakterY < (lebarPeta - 1)) {
            if (peta[posisiKarakterY + 1][posisiKarakterX] == 2 || peta[posisiKarakterY + 1][posisiKarakterX] == 5 || peta[posisiKarakterY-1][posisiKarakterX] == 7 ) {
                cout << "Hati-hati ada obstacle yg menghalangi jalan!!!\n";
            }
        }
        
        //Cek lokasi player
        if(peta[posisiKarakterX][posisiKarakterY] == 1){
        	cout<<"Player Berada Dijalan!!!\n";
            if (randomAnimal == 1) {
                cout << "Anda Menemukan " << animals[0].nama <<" , "<< "Habitanya : " << animals[0].habitat <<" , "<< " Jenis Kelangkaan : " << animals[0].kelangkaan <<" , "<< " Harga : " << animals[0].harga << endl;
                
                cout <<"Anda Ingin Menangkapnya Y/T ";
                cin>>lawan;
                
                if(lawan == 'T'){
                		cout<<"Menolak Untuk Bertarung, Lanjut Bermain"<<endl;
				}else if(lawan == 'Y'){
						cout<<"Beratunglah dan pilih senjata anda!!!"<<endl;
						
				}else{
					cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
				}
                
                while(lawan != 'T' && lawan == 'Y'){
					
                	do{
	                	cout<<"Silahkan Pilih Senjata Mu :"<<endl;
	                	cout<<"1. Pedang Laskar "<<endl;
	                	cout<<"2. Sniper Row "<<endl;
	                	cout<<"3. Night Bow"<<endl;
	                	cout<<"4. Exit"<<endl;
	                	cout<<"Masukan pilihan :";
	                	cin>>pilih;
	                	
	                	switch(pilih){
	                		case 1:
	                			{
	                				senjataInfo senjataInfo1;
									senjataInfo1.nama = "Pedang Laskar";
									senjataInfo1.dmg = 500;
									
									while(1){
										cout<<"Mau melawanya dengan senjata ini?";
										cin>>attlagi;
										if(attlagi == 1){
											senjataInfo1.attack(animals[0]);
											if(animals[0].Hp == 0 || animals[0].Hp < 0){
												cout<<"Musuh Kalash"<<endl;
												break;
											}
										}
									}
									
									/*cout<<"Attack lagi ?"<<endl;
									cin>>attlagi;
									
									while(attlagi == 'Y' && attlagi != 'T'){
										senjataInfo1.attack(animals[0]);
										if(senjataInfo1.attack(animals[0]) == 0){
											attlagi == 'T';
										}
									}*/
								break;	
								}
							case 2:
								{
									senjataInfo senjataInfo2;
									senjataInfo2.nama = "Sniper Row";
									senjataInfo2.dmg = 1700;
									
									senjataInfo2.attack(animals[0]);
									
								break;
								}
							
							case 3:
								{
									senjataInfo senjataInfo3;
									senjataInfo3.nama = "Night Bow";
									senjataInfo3.dmg = 1500;
									
									senjataInfo3.attack(animals[0]);
								break;
								}
									
							case 4:
								cout<<"Aplikasi Keluar"<<endl;
								lawan = 'T';
								break;
									
							default:
								cout<<"Pilihan Tidak Tersedia :("<<endl;
						}
					}
	                while(pilih != 4);	
				}
                
					
			}
                
             
            }else if (randomAnimal == 2) {
                cout << "Anda Menemukan " << animals[1].nama <<" , "<< " Habitatnya : " << animals[1].habitat <<" , "<< " Jenis Kelangkaan : " << animals[1].kelangkaan <<" , "<< " Harga : " << animals[1].harga << endl;
                
                cout <<"Anda Ingin Menangkapnya Y/T ";
                cin>>lawan;
                
                if(lawan == 'T'){
                		cout<<"Menolak Untuk Bertarung, Lanjut Bermain"<<endl;
				}else if(lawan == 'Y'){
						cout<<"Beratunglah dan pilih senjata anda!!!"<<endl;
						
				}else{
					cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
				}
				
                while(lawan != 'T' && lawan == 'Y'){
                	
                	do{
	                	cout<<"Silahkan Pilih Senjata Mu :"<<endl;
	                	cout<<"1. Pedang Laskar "<<endl;
	                	cout<<"2. Sniper Row "<<endl;
	                	cout<<"3. Night Bow"<<endl;
	                	cout<<"4. Exit"<<endl;
	                	cout<<"Masukan pilihan :";
	                	cin>>pilih;
	                	
	                	switch(pilih){
	                		case 1:
	                			{
	                				senjataInfo senjataInfo1;
									senjataInfo1.nama = "Pedang Laskar";
									senjataInfo1.dmg = 500;
									
									while(1){
										cout<<"Mau melawanya dengan senjata ini?";
										cin>>attlagi;
										if(attlagi == 1){
											senjataInfo1.attack(animals[1]);
											if(animals[1].Hp == 0 || animals[1].Hp < 0){
												cout<<"Musuh Kalash"<<endl;
												break;
											}
										}
									}
									/*cout<<"Attack lagi ?"<<endl;
									cin>>attlagi;
									
									while(attlagi == 'Y' && attlagi != 'T'){
										
										senjataInfo1.attack(animals[1]);
										if(senjataInfo1.attack(animals[1]) == 0){
											attlagi == 'T';
										}
									}*/
								break;	
								}
							case 2:
								{
									senjataInfo senjataInfo2;
									senjataInfo2.nama = "Sniper Row";
									senjataInfo2.dmg = 1700;
									
									senjataInfo2.attack(animals[1]);
								break;
								}
							
							case 3:
								{
									senjataInfo senjataInfo3;
									senjataInfo3.nama = "Night Bow";
									senjataInfo3.dmg = 1500;
									
									senjataInfo3.attack(animals[1]);
								break;
								}
									
							case 4:
								cout<<"Aplikasi Keluar"<<endl;
								lawan = 'T';
								break;
									
							default:
								cout<<"Pilihan Tidak Tersedia :("<<endl;
						}
					}
	                while(pilih != 4);	
				}
				
                
            }else if (randomAnimal == 3) {
                cout << "Anda Menemukan " << animals[2].nama <<" , "<< " Habitatnya : " << animals[2].habitat <<" , "<< " Jenis Kelangkaan : " << animals[2].kelangkaan <<" , "<< " Harga : " << animals[2].harga << endl;
                
                cout <<"Anda Ingin Menangkapnya Y/T ";
                cin>>lawan;
                
                if(lawan == 'T'){
                		cout<<"Menolak Untuk Bertarung, Lanjut Bermain"<<endl;
				}else if(lawan == 'Y'){
						cout<<"Beratunglah dan pilih senjata anda!!!"<<endl;
						
				}else{
					cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
				}
					
                while(lawan != 'T' && lawan == 'Y'){
                	
					
                	do{
	                	cout<<"Silahkan Pilih Senjata Mu :"<<endl;
	                	cout<<"1. Pedang Laskar "<<endl;
	                	cout<<"2. Sniper Row "<<endl;
	                	cout<<"3. Night Bow"<<endl;
	                	cout<<"4. Exit"<<endl;
	                	cout<<"Masukan pilihan :";
	                	cin>>pilih;
	                	
	                	switch(pilih){
	                		case 1:
	                			{
	                				senjataInfo senjataInfo1;
									senjataInfo1.nama = "Pedang Laskar";
									senjataInfo1.dmg = 500;
									
									while(1){
										cout<<"Mau melawanya dengan senjata ini?";
										cin>>attlagi;
										if(attlagi == 1){
											senjataInfo1.attack(animals[2]);
											if(animals[2].Hp == 0 || animals[2].Hp < 0){
												cout<<"Musuh Kalash"<<endl;
												break;
											}
										}
									}
									/*cout<<"Attack lagi ?"<<endl;
									cin>>attlagi;
										
									while(attlagi == 'Y' && attlagi != 'T'){
										senjataInfo1.attack(animals[2]);
										if(senjataInfo1.attack(animals[2]) == 0){
											attlagi == 'T';
										}
									}*/
								break;	
								}
							case 2:
								{
									senjataInfo senjataInfo2;
									senjataInfo2.nama = "Sniper Row";
									senjataInfo2.dmg = 1700;
									
									senjataInfo2.attack(animals[2]);
								break;
								}
							
							case 3:
								{
									senjataInfo senjataInfo3;
									senjataInfo3.nama = "Night Bow";
									senjataInfo3.dmg = 1500;
									
									senjataInfo3.attack(animals[2]);
								break;
								}
								
							case 4:
								cout<<"Aplikasi Keluar"<<endl;
								lawan = 'T';
								break;
									
							default:
								cout<<"Pilihan Tidak Tersedia :("<<endl;		
						}
					}
	                while(pilih != 4);
				}
				
				
                
            }else if (randomAnimal == 4) {
                cout << "Anda Menemukan " << animals[3].nama <<" , "<< " Habitatnya : " << animals[3].habitat <<" , "<<" Jenis Kelangkaan : " << animals[3].kelangkaan <<" , "<< " Harga : " << animals[3].harga << endl;
                
                cout <<"Anda Ingin Menangkapnya Y/T ";
                cin>>lawan;
                
                if(lawan == 'T'){
                		cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
				}else if(lawan == 'Y'){
						cout<<"Beratunglah dan pilih senjata anda!!!"<<endl;
						
				}else{
					cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
				}
					
                while(lawan != 'T' && lawan == 'Y'){
                	if(lawan == 'T'){
                		cout<<"Menolak Untuk Bertarung, Lanjut Bermain"<<endl;
					}else{
						cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
					}
					
                	do{
	                	cout<<"Silahkan Pilih Senjata Mu :"<<endl;
	                	cout<<"1. Pedang Laskar "<<endl;
	                	cout<<"2. Sniper Row "<<endl;
	                	cout<<"3. Night Bow"<<endl;
	                	cout<<"4. Exit"<<endl;
	                	cout<<"Masukan pilihan :";
	                	cin>>pilih;
	                	
	                	switch(pilih){
	                		case 1:
	                			{
	                				senjataInfo senjataInfo1;
									senjataInfo1.nama = "Pedang Laskar";
									senjataInfo1.dmg = 500;
									
									while(1){
										cout<<"Mau melawanya dengan senjata ini?";
										cin>>attlagi;
										if(attlagi == 1){
											senjataInfo1.attack(animals[3]);
											if(animals[3].Hp == 0 || animals[3].Hp < 0){
												cout<<"Musuh Kalash"<<endl;
												break;
											}
										}
									}
										
									/*cout<<"Attack lagi ?"<<endl;
									cin>>attlagi;
									while(attlagi == 'Y' && attlagi != 'T'){
										
										senjataInfo1.attack(animals[3]);
										if(senjataInfo1.attack(animals[3]) == 0){
											attlagi == 'T';
										}
									}*/
								
								break;	
								}
							case 2:
								{
									senjataInfo senjataInfo2;
									senjataInfo2.nama = "Sniper Row";
									senjataInfo2.dmg = 1700;
									
									senjataInfo2.attack(animals[3]);
								break;
								}
							
							case 3:
								{
									senjataInfo senjataInfo3;
									senjataInfo3.nama = "Night Bow";
									senjataInfo3.dmg = 1500;
									
									senjataInfo3.attack(animals[3]);
								break;
								}
									
							case 4:
								cout<<"Aplikasi Keluar"<<endl;
								lawan = 'T';
								break;
									
							default:
								cout<<"Pilihan Tidak Tersedia :("<<endl;
						}
					}
	                while(pilih != 4);
				}
                
            }else if (randomAnimal == 5) {
                cout << "Anda Menemukan " << animals[4].nama <<" , "<<" Habitatnya : " << animals[4].habitat <<" , "<< " Jenis Kelangkaan : " << animals[4].kelangkaan <<" , "<< " Harga : " << animals[4].harga << endl;
                
                cout <<"Anda Ingin Menangkapnya Y/T ";
                cin>>lawan;
                
                if(lawan == 'T'){
                		cout<<"Menolak Untuk Bertarung, Lanjut Bermain"<<endl;
				}else if(lawan == 'Y'){
						cout<<"Beratunglah dan pilih senjata anda!!!"<<endl;
						
				}else{
					cout<<"Tidak Ada Pilihan!!, Lanjut Bermain Saja"<<endl;
				}
					
                while(lawan != 'T' && lawan == 'Y'){
					
                	do{
	                	cout<<"Silahkan Pilih Senjata Mu :"<<endl;
	                	cout<<"1. Pedang Laskar "<<endl;
	                	cout<<"2. Sniper Row "<<endl;
	                	cout<<"3. Night Bow"<<endl;
	                	cout<<"4. Exit"<<endl;
	                	cout<<"Masukan pilihan :";
	                	cin>>pilih;
	                	
	                	switch(pilih){
	                		case 1:
	                			{
	                				senjataInfo senjataInfo1;
									senjataInfo1.nama = "Pedang Laskar";
									senjataInfo1.dmg = 500;
									
									while(1){
										cout<<"Mau melawanya dengan senjata ini?";
										cin>>attlagi;
										if(attlagi == 1){
											senjataInfo1.attack(animals[4]);
											if(animals[4].Hp == 0 || animals[4].Hp < 0){
												cout<<"Musuh Kalash"<<endl;
												break;
											}
										}
									}
									
									/*cout<<"Attack lagi ?"<<endl;
									cin>>attlagi;
										
									while(attlagi == 'Y' && attlagi != 'T'){
										senjataInfo1.attack(animals[4]);
										if(senjataInfo1.attack(animals[4]) == 0){
											attlagi == 'T';
										}
									}*/
								break;	
								}
							case 2:
								{
									senjataInfo senjataInfo2;
									senjataInfo2.nama = "Sniper Row";
									senjataInfo2.dmg = 1700;
									
									senjataInfo2.attack(animals[4]);
								break;
								}
							
							case 3:
								{
									senjataInfo senjataInfo3;
									senjataInfo3.nama = "Night Bow";
									senjataInfo3.dmg = 1500;
									
									senjataInfo3.attack(animals[4]);
								break;
								}
							case 4:
								cout<<"Aplikasi Keluar"<<endl;
								lawan == 'T';
								break;
									
							default:
								cout<<"Pilihan Tidak Tersedia :("<<endl;
						}
					}
	                while(pilih != 4);	
				}
				
				
            }
            
            randomAnimal = 0;
		}
		
     
    return 0;
}
