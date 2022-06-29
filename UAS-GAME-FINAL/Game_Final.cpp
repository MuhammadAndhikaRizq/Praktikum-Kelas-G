 #include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 75
#define KEY_LEFT 77
#define KEY_RIGHT 80

struct uang {
	int jumlah;
	
};

struct dompet{
	int uangDompet;
	 
    void tambahin(uang *jumlahTambah){
		jumlahTambah->jumlah = uangDompet + jumlahTambah->jumlah;
		cout<<" Uang Jajan Setelah DItambah : "<<jumlahTambah->jumlah<<endl;
	}
	
	void tambah(dompet *tambahAwal){
		cout<<" Uang Jajan : " << uangDompet << endl;
		
	}
	
};

struct tas{
	string item;
	
	void collect(tas *ambilItem){
		cout<<"Item Yand Di Dapat : " << ambilItem->item <<endl;
	}
};

struct pertanyaan{
	string kuis;
	string jawaban;
};

void resep();
void meja();
void lemari();
void catetan();
void baju();
void win();
void lose();
void rulesInfo();

int main() {
    
    int panjangPeta = 17; // x
    int lebarPeta = 17; // y
    int posisiKarakterY = 15;
    int posisiKarakterX = 0;
    int randomIbu;
    int randomPertanyaan;
    
    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";
    
    string peta[lebarPeta][panjangPeta] = {
       {"||","||","||","||","||","||","||","||","||","||","||","||","||","||","||","||","||"},
       {"||","||","||","||","||","||","||","||","||","||","||","||","  ","R3","||","##","||"},
       {"||","||","||","||","||","||","||","||","||","||","  ","==","  ","  ","||","  ","||"},
       {"||","||","||","||","||","||","||","||","||","  ","  ","^3","  ","?3","||","  ","||"},
       {"||","||","||","  ","  ","  ","  ","  ","  ","  ","  ","==","  ","+3","||","  ","||"},
       {"||","R4","||","  ","||","||","||","||","||","  ","  ","||","||","||","||","  ","||"},
       {"||","  ","||","  ","||","||","||","||","||","||","  ","  ","  ","  ","  ","  ","||"},
       {"||","?4","||","  ","||","||","R1","  ","  ","  ","||","  ","||","||","||","||","||"},
       {"||","  ","==","  ","  ","==","  ","  ","  ","  ","||","  ","||","||","||","||","||"},
       {"||","  ","  ","  ","  ","  ","A+","  ","@@","  ","||","  ","||","R5","  ","||","||"},
       {"||","  ","==","  ","  ","==","  ","  ","  ","  ","||","  ","==","  ","  ","||","||"},
       {"||","||","||","  ","||","||","  ","  ","  ","  ","||","  ","^5","  ","  ","||","||"},
       {"||","||","||","  ","||","||","||","||","||","||","||","  ","==","  ","?5","||","||"},
       {"||","||","||","  ","==","R2","  ","  ","  ","||","||","||","||","  ","  ","||","||"},
       {"||","||","||","  ","^2","  ","  ","  ","+2","||","||","||","||","  ","  ","||","||"},
       {"  ","  ","  ","  ","==","  ","  ","!2","?2","||","||","||","||","||","||","||","||"},
       {"||","||","||","||","||","||","||","||","||","||","||","||","||","||","||","||","||"},
    };
    
    
    int arrowKey = 0;
    
    pertanyaan pertanyaan1[]{
		{
			"Berapakah 5 x 5 ?",
			"25"
		},
		{
			"Ibu kota indonesia?",
			"jakarta"
		},
	};
    
    /*
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    */
    
    uang money1;
    money1.jumlah = 200;
    
    uang money3;
    money3.jumlah = 300;
        
    uang money2;
    money2.jumlah = 500;
    
    dompet dompetInfo;
	dompetInfo.uangDompet = 1000;
	
	tas tas1;
	tas1.item = "(locked)";
	
	rulesInfo();
		
    while(1) {
    	
    	randomIbu = rand() % 40;
    	
        // Input Keyboard;
        
		dompetInfo.tambah(&dompetInfo);
		tas1.collect(&tas1);
		 	 
        cout << "Input arrow key ";
        arrowKey = getch();
        cout << "Arrow key yang dimasukan " << arrowKey << "\n";
        
        //clear screen
        system("cls");
        
        //ATAS
        if (arrowKey == 72) {
            if (peta[posisiKarakterY - 1][posisiKarakterX] != "||" && peta[posisiKarakterY - 1][posisiKarakterX] != "==") {
                posisiKarakterY--;
            }
        //BAWAH
        } else if (arrowKey == 80) {
            if (peta[posisiKarakterY + 1][posisiKarakterX] !="||" && peta[posisiKarakterY + 1][posisiKarakterX] != "==") {
                posisiKarakterY++;
            }
        //KIRI
        } else if (arrowKey == 75) {
            if (peta[posisiKarakterY][posisiKarakterX - 1] !="||" && peta[posisiKarakterY][posisiKarakterX - 1] != "==") {
                posisiKarakterX--;
            }
        //KANAN
        } else if (arrowKey == 77) {
            if (peta[posisiKarakterY][posisiKarakterX + 1] !="||" && peta[posisiKarakterY][posisiKarakterX + 1] != "==") {
                posisiKarakterX++;
            }
    	}
    	
        // Render grafik
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {
                
                if(posisiKarakterX == x && posisiKarakterY == y) {
                    cout << "**" << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
        
        //CEK CLUE Ruangan R4
	        //ATAS
	        if (arrowKey == 72 || arrowKey == 80) {
	            if (peta[posisiKarakterY][posisiKarakterX] == "?4") {
	                resep();
	            }
			}
		
		//CEK ClUE Ruangan R2
			//KANAN, Cek Barcode Room
	        if (arrowKey == 77) {
	            if (peta[posisiKarakterY][posisiKarakterX ] =="^2") {
	            	string r2, q45R2;
	            	int cek = 4;
	            	
	                while(cek >= 1){
	                	cout<<"Masukan Password Ruangan Terimakasih !! \n";
		                cin>>r2;
		                
		                if(r2 != "q45R2"){
		                	cout<<"Password Salah" <<endl;
		                	cek--;
		                	if(cek == 1){
		                		goto GameOver;
							}
						}
						else{
							cout<<"Silahkan Masuk !!! \n";
							cek=0;
						}
					}       
	            }
	    	}
	    	
	    	//BAWAH,KANAN, Cek Meja
	    	if(arrowKey == 80 || arrowKey == 77){
	    		if (peta[posisiKarakterY][posisiKarakterX ] =="?2"){
	    			meja();
				}
			}
			
			//BAWAH,KANAN, Cek Meja
	    	if(arrowKey == 80 || arrowKey == 77){
	    		if (peta[posisiKarakterY][posisiKarakterX ] =="+2"){
	    				char ambil;
	    				
				
							cout<<"ADA UANG 200 DI MEJA APAKAH INGIN DI AMBIL (Y/T)";
							cin>>ambil;
							
							if(ambil =='Y'){
								
								dompetInfo.tambahin(&money1);
								if(money1.jumlah == 1200){
									money1.jumlah = 0;
									dompetInfo.uangDompet = 1200;
									cout<<" Uang di meja sudah diambil semua "<<endl;
								}
								else if(money1.jumlah == 1700){
									money1.jumlah = 0;
									dompetInfo.uangDompet = 1700;
									cout<<" Uang di meja sudah diambil semua "<<endl;
								}
								else if(money1.jumlah == 1500){
									money1.jumlah = 0;
									dompetInfo.uangDompet = 1500;
									cout<<" Uang di meja sudah diambil semua "<<endl;
								}
								else if(money1.jumlah == 1800){
									money1.jumlah = 0;
									dompetInfo.uangDompet = 1800;
									cout<<" Uang di meja sudah diambil semua "<<endl;
								}
								else if(money1.jumlah == 2000){
									money1.jumlah = 0;
									dompetInfo.uangDompet = 2000;
									cout<<" Uang di meja sudah diambil semua "<<endl;
								}	
								
							}else if(ambil == 'T'){
								cout<<"Baiklah, Lanjutkan Misi !!! \n";
							}else{
								cout<<"Tidak ada pilihan jalan !!! lanjut jalan saja \n";
							}				
				}
			}
			
			//BAWAH, KIRI, KANAN Cek Catatan
			if(arrowKey == 77 || arrowKey == 80 || arrowKey == 75){
				if (peta[posisiKarakterY][posisiKarakterX ] =="!2"){
	    			catetan();
				}
			}
			
		//CEK ClUE Ruangan R5
			//Cek Code ROOM
			if (arrowKey == 77) {
		        if (peta[posisiKarakterY][posisiKarakterX ] =="^5") {
		            string r5, code="EP-49";
		            int cek = 4;
		            	
		            while(cek >= 1){
		                cout<<"Masukan Password Ruangan Terimakasih !! \n";
			            cin>>r5;
			                
			            if(r5 != code){
			                cout<<"Password Salah" <<endl;
			                cek--;
			                if(cek == 1){
			                	goto GameOver;
							}
						}
						else{
							cout<<"Silahkan Masuk !!! \n";
							cek=0;
						}
					}          
		        }
		    }
		    
		    //CEK CLUE BAJU
		    if(arrowKey== 72 || arrowKey == 77 || arrowKey == 80){
		    	if (peta[posisiKarakterY][posisiKarakterX ] =="?5") {
		              baju();    
		        }
			}
		
		//CEK CLUE RUANGAN R3
			//CEK CODE ROOM
			if (arrowKey == 77) {
		        if (peta[posisiKarakterY][posisiKarakterX ] =="^3") {
		            string r3, code="345XZ";
		            int cek = 4;
		            	
		            while(cek >= 1){
		                cout<<"Masukan Password Ruangan Terimakasih !! \n";
			            cin>>r3;
			                
			            if(r3 != code){
			                cout<<"Password Salah" <<endl;
			                cek--;
			                if(cek == 1){
			                	goto GameOver;
							}
						}
						else{
							cout<<"Silahkan Masuk !!! \n";
							cek=0;
						}
					}          
		        }
		    }
		    
		    //CEK CATETAN DI LEMARI
		    if(arrowKey== 72 || arrowKey == 77 || arrowKey == 80){
		    	if (peta[posisiKarakterY][posisiKarakterX ] =="?3") {
		             lemari();    
		        }
			}
			
			//AMBIL UANG DI RUANGAN R3
			if(arrowKey == 80 || arrowKey == 77){
	    		if (peta[posisiKarakterY][posisiKarakterX ] =="+3"){
	    			char ambil;
	    				
				
					cout<<"ADA UANG 500 DI KASUR APAKAH INGIN DI AMBIL (Y/T)";
					cin>>ambil;
							
					if(ambil =='Y'){
								
					dompetInfo.tambahin(&money2);
						if(money2.jumlah == 1700){
							money2.jumlah = 0;
							dompetInfo.uangDompet = 1700;
							cout<<" Uang di kasur sudah diambil semua "<<endl;
						}
						else if(money2.jumlah == 1500){
							money2.jumlah = 0;
							dompetInfo.uangDompet = 1500;
							cout<<" Uang di kasur sudah diambil semua "<<endl;
						}
						else if(money2.jumlah == 1800){
							money2.jumlah = 0;
							dompetInfo.uangDompet = 1800;
							cout<<" Uang di kasur sudah diambil semua "<<endl;
						}
						else if(money2.jumlah == 2000){
							money2.jumlah = 0;
							dompetInfo.uangDompet = 2000;
							cout<<" Uang di kasur sudah diambil semua "<<endl;
						}				
					}else if(ambil == 'T'){
						cout<<"Baiklah, Lanjutkan Misi !!! \n";
					}else{
						cout<<"Tidak ada pilihan jalan !!! lanjut jalan saja \n";
					}				
				}
			}
			
		//CEK CLUU RUANG R1
			//CEK CODE ROOM
			if (arrowKey == 77) {
		        if (peta[posisiKarakterY][posisiKarakterX ] =="A+") {
		            string r1, code="ANDHIKA";
		            int cek = 4;
		            
		            cout<<"Adik : Hei kak, knp kau sudah pulang jam segini? apakah kaka ingin bermain denganku? \n";
		            cout<<"Player : Ehh anu, ada barang ku yang ketinggalan. lagi ngapain de kamu disni dan kenapa mengalangi jalan \n";
		            cout<<"Adik : Aku sedang bermain ka, kalo kamu mau lewat kamu harus menyebut namaku dulu karena kamu tidak bisa bermain hari ini bersamaku \n";
		            
		            while(cek >= 1){
		               	cout<<"Adik : Ayoo jawab dengan benar ka \n";
			            cin>>r1;
			                
			            if(r1 != code){
			                cout<<"Adik : Itu bukan namaku ka :( " <<endl;
			                cek--;
			                if(cek == 1){
			                	goto GameOver;
							}
						}
						else{
							cout<<"Adik : Okee ka, silahkan masuk nanti pulang sekolah kita main yaa \n";
							cek=0;
						}
					}          
		        }
		    }
		    
		    //CEK NGAMBIL ITEM
		    if(arrowKey == 77){
		    	if(peta[posisiKarakterY][posisiKarakterX ] =="@@"){
		    		cout<<" Item Sudah Terambil \n";
		    		tas1.item = "Tas";
				}
			}
			
		//CEK KELUAR ##
		if(arrowKey == 72){
		    if(peta[posisiKarakterY][posisiKarakterX ] =="##"){
		    	cout<<" Item Sudah Terambil \n";
		    	tas1.collect(&tas1);
		    	if(tas1.item != "Tas" && dompetInfo.uangDompet != 2000){
		    		lose();	
		    		break;
				}else{
					win();
					break;
				}
			}
		}
		
		//random ibu
		if(peta[posisiKarakterY + 1][posisiKarakterX] !="||" && peta[posisiKarakterY + 1][posisiKarakterX] != "=="){
			if(randomIbu == 1){
				string answer;
				string pilih;
				
				cout<< "Anda Menemukan ibu "<< endl;
				cout<< "Ibu : Hei nak kenapa kamu kembali ke rumah " << endl;
				cout<< "Player : Hehe ada yang tertinggal bu maaf " << endl;
				cout<< "Ibu : Okee, oiya apakah kamu kekurangan uang jajan?? " << endl;
				cout<< "Player : Hehe sepertinya iyaa " << endl;
				cout<< "Ibu : Baiklah, ibu Punya Pertanyaan untukmu nanti dapat uang jajan tambahan!! pilihan 1. soal mtk, 2 soal sosial pilih (1/2) " << endl;
				cin>>pilih;
				
				if(pilih == "1"){
					cout<< pertanyaan1[0].kuis << endl;
					cin>>answer;
					
					if(answer == pertanyaan1[0].jawaban){
						cout<<" Kamu dapet uang jajan tambahan 300 ";
						dompetInfo.tambahin(&money3);
						
						if(money3.jumlah == 2000){
							money3.jumlah = 0;
							dompetInfo.uangDompet = 2000;
						}
						else if(money3.jumlah == 1300){
							money3.jumlah = 0;
							dompetInfo.uangDompet = 1300;
						}
						else if(money3.jumlah == 1800){
							money3.jumlah = 0;
							dompetInfo.uangDompet = 1800;
						}
						else if(money3.jumlah == 1500){
							money3.jumlah = 0;
							dompetInfo.uangDompet = 1500;
						}	
					}
					else{
						goto GameOver;
					}
					
				}else if(pilih == "2"){
					cout<< pertanyaan1[1].kuis << endl;
					cin>>answer;
					
					
					if(answer == pertanyaan1[1].jawaban){
						cout<<" Kamu dapet uang jajan tambahan 300 ";
						dompetInfo.tambahin(&money3);
						
					if(money3.jumlah == 2000){
						money3.jumlah = 0;
						dompetInfo.uangDompet = 2000;
					}
					else if(money3.jumlah == 1300){
						money3.jumlah = 0;
						dompetInfo.uangDompet = 1300;
					}
					else if(money3.jumlah == 1800){
							money3.jumlah = 0;
							dompetInfo.uangDompet = 1800;
					}
					else if(money3.jumlah == 1500){
						money3.jumlah = 0;
						dompetInfo.uangDompet = 1500;
					}	
				  } 
				  else{
					goto GameOver;
				  } 
				}
				else{
				  	cout<<"Ibu : Tidak ada pilihannya, sepertinya kamu tidak mau memilih\n";
				}
			} 
		}	    
 	}
    return 0;
    
    	//Code GameWin
    
    	//Code GameOver
    	GameOver:
    		system("cls");
    		cout << "========================================\n";
    		cout << "GAME OVER\n";
    		cout << "========================================\n";
    		cout<<"Carilah Clue Dengan Benar Agar Dapat Menyelesaikan Misi Ini!!!\n";
    		cout << "========================================\n";
    		cout<<"Anda Gagal Dalam Menjalankan Misi\n";

}

void resep(){
	cout << "========================================\n";	
	cout << "RESEP MEMBUAT NASI GORENG\n";
	cout << "1. Nasi \n";
	cout << "2. Kecap \n";
	cout << "3. Bumbu Racik \n";
	cout << "4. Telur \n";
	cout << "5. BawANg \n";
	cout << "========================================\n";
	cout << "Barcode: q45R2 \n";
};

void meja(){
	cout << "========================================\n";
	cout << "CIRI-CIRI ANGGUR YANG SIAP DI PANEN DENGAN CODE EP-49\n";
	cout << "1. Tekstur buah tidak terlalu keras\n";
	cout << "2. Buah tidak sulit dilepas dari rantingnya\n";
	cout << "3. Seluruh buah dalam satu ranting yang sama matang dengan warna seragam\n";
	cout << "========================================\n";
}

void catetan(){
	cout << "========================================\n";
	cout << "Jangan Lupa Mengerjakan Latihan Penggunaan Huruf KAPITAL yang benar, perhatikan setiap huruf KAPITAL !!!! \n";
	cout << "========================================\n";
}

void baju(){
	cout << "========================================\n";
	cout << "Ukuran Baju Keluarga\n";
	cout << "1. Ayah = l, dengan merk linx 3-KA \n";
	cout << "2. Ibu = m \n";
	cout << "3. Kaka = xl, dengan code 345XZ \n";
	cout << "4. Tobi = l \n";
	cout << "5. Adik = s \n";
	cout << "========================================\n";
}

void lemari(){
	cout << "========================================\n";
	cout << "TATA LETAK PAKAIAN\n";
	cout << "1. Kemeja 2 DHI sebelah kanan\n";
	cout << "2. Celana di bawah\n";
	cout << "3. Kaos di kiri\n";
	cout << "4. Sweater di atas\n";
	cout << "========================================\n";
}

void lose(){
		system("cls");
    	cout << "========================================\n";
    	cout << "GAME OVER\n";
    	cout << "========================================\n";
    	cout <<"Kamu tidak bisa mebayar kaka dengan uang segitu !!!\n";
    	cout <<"Kaka menolpon ayah karena kamu ke rumah bukanya sekolah !!!\n";
    	cout <<"Dan Tidak Ada Item Yang Dibawa :( !!\n";
    	cout << "========================================\n";
    	cout <<"Anda Gagal Dalam Menjalankan Misi\n";
}

void win(){
		system("cls");
    	cout << "========================================\n";
    	cout << "CONGRATULATION YOU WIN\n";
    	cout << "========================================\n";
    	cout<<"Anda Benar-Benar Menyelesaikan Misi Ini Dengan Hebat!!!\n";
}

void rulesInfo(){
	cout << "==========================================================\n";
    cout << "WELCOM TO MY GAME\n";
    cout << "==========================================================\n";
    cout <<"MYSTERY : FIND THE CODE\n";
    cout << "==========================================================\n";
    cout <<"Rules&Info, Please Read Befor Play The Game\n";
    cout <<"1. R1 = Ruangan 1, Kamar Player\n";
    cout <<"2. R2 = Ruangan 2, Ruang Tamu\n";
    cout <<"3. R3 = Ruangan 3, Ruang Kamar\n";
    cout <<"4. R4 = Ruangan 4, Dapur\n";
    cout <<"5. R5 = Ruangan 5, Garden\n";
    cout <<"6. ** = Player\n";
    cout <<"7. !2 = Catetan untuk nambah clue\n";
    cout <<"8. ?2 = Clue Membuka code ruangan\n";
    cout <<"9. +2 = Menambah Uang Jajan\n";
    cout <<"9. ?3 = Clue Membuka code ruangan\n";
    cout <<"10. +3 = Menambah Uang Jajan\n";
    cout <<"11. ?4 = Clue Membuka code ruangan\n";
    cout <<"12. ?5 = Clue Membuka code ruangan\n";
    cout <<"13. A+ = Adik\n";
    cout <<"11. @@ = Lokasi item berada\n";
    cout <<"11. ## = Finish yg dijaga oleh kaka yg meminta bayaran\n";
    cout << "========================================================\n";
    cout <<"Sinopsis : \n";
    cout <<"Seorang pelajar yang ketinggalan tasnya di rumah, dimana dia harus kembali ke rumah untuk mengambilnya "
    	 <<" Akan tetapi, ada beberapa rintangan yang harus di lalui. Karena rumahnya ini smarthome maka setiap ruangan memiliki codenya masing-masing maka dari itu player harus menemukan clue-clue code setiap ruangan untuk mencari item yang di cari yaitu sebuah tas"
		 <<" Selain itu player akan berhadapan dengan anggota keluarga yang berada dirumah seperti ibu, kaka, dan adik "
		 <<" yg dimana ketika ketemu ibu player harus menjawab agar mendapatkan tambahan uang jajan selain dari uang yang di temukan di setiap ruangan, "
		 <<" adik akan menjaga kamar utama karena dia sedang bermain untuk membujuknya bisa dengan menyebutkan namanya(CLUE SETIAP HURUF KAPITAL DISETIAP RUANGAN DISUSUN),"
		 <<" kaka menajaga pintu keluar yg dimana kita harus memberi uang kepada kaka kalo tidak dia akan mengadu kepada ayah \n";
	cout << "========================================================\n";
	cout <<"WIN&LOSE CONDITION\n";
	cout << "1. LOSE : 1. Ketika salah memasukan code ruangan sebanyak 3x\n";
	cout <<	"	  2. Ketika jawaban salah dari quis yang di berikan ibu\n";
	cout <<	"	  3. Ketika Mencoba keluar tanpa membawa item yang di cari dan uang yang cukup untuk kaka\n";
	cout <<"2. WIN : Ketika berhasil keluar dengan memenuhi syarat uang dan item\n";
	cout << "========================================================\n";
	cout << "START BEGIN\n";
}

