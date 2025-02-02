#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Contact{
public:
    string nama;
    string alamat;
    string tempat_tinggal;
    string kekuatan;

    Contact(string xnama, string xalamat, string xdomisili, string xkekuatan) {
        nama = xnama;
        alamat = xalamat;
        tempat_tinggal = xdomisili;
        kekuatan = xkekuatan;
    }
    void printdata(){//output detail contact
        cout<<"Nama        \t= " << nama << endl;
        cout<<"Alamat     \t= "<<alamat<<endl;
        cout<<"Tempat tinggal\t= "<<tempat_tinggal<<endl;
        cout<<"Kekuatan\t= "<<kekuatan<<endl;
        cout<<""<<endl;
    }
};

class PhoneBook{
    private:
        vector<Contact> ListContact;

    public:
    void Add(string nama, string alamat, string domisili, string kekuatan){
        if (ListContact.size()>=8)
        {
            ListContact.erase(ListContact.begin());//menghapus contact paling atas atau paling pertama ditambahkan
        }
        ListContact.push_back(Contact(nama, alamat, domisili, kekuatan ));//menambah contact ke dalam vector
        }

    void inputcontact(){
        string nama, alamat, domisili, kekuatan;
        cout<<"---Menambahkan contact baru---"<<endl;
        cout<<"Masukkan nama contact: ";
        getline(cin>>ws, nama);
        cout<<"Masukkan alamat contact: ";
        getline(cin>>ws, alamat);
        cout<<"Masukkan tempat tinggal contact: ";
        getline(cin>>ws, domisili);
        cout<<"Masukkan kekuatan contact: ";
        getline(cin>>ws, kekuatan);

        Add(nama, alamat, domisili, kekuatan);
    }

    void Search(string nama){
        bool ada=false;
        for(auto& Contact: ListContact){
            if (Contact.nama==nama)
            {
                Contact.printdata();//output jika contact tersedia
                ada=true;
            }
        if (!ada)
        {
            cout<<"Contact "<<nama<<" tidak ada, silakan tambahkan kontak baru"<<endl;//output jika contact tidak tersedia
            cout<<""<<endl;
        }
            
        return;
        }
    }
    void show() {
        if (ListContact.empty()) {//jika phonebook kosong
            cout<<"PhoneBook kosong, silakan Add terlebih dahulu"<<endl;
            return ;
        }
        else{
            int i = 1;
            cout<<""<<endl;
            cout<<"---PhoneBook Pak Bell---"<<endl;
            for (auto& contact : ListContact) {
                cout<<i++<<". "<<contact.nama<<endl;
            }
        }
        cout<<""<<endl;
    }
};
 
int main (){ //main program
    PhoneBook pb; 
    while (true) {   
        cout<<"---PhoneBook Pak Bell---"<<endl;
        string pilihan;
        cout<<"1. Add"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Masukkan pilihan (Add/Search/Exit)= ";
        cin>>pilihan;
        cout<<""<<endl;
        
        if (pilihan=="Exit"){
            cout<<"PhoneBook Pak Bell ditutup";
            break;
            }
        else if (pilihan=="Search"){            
            pb.show();
            cout<<"Masukkan nama kontak yang ingin dicari: ";
            string orang;
            getline(cin>>ws, orang);//input kontak yang ingin dicari
            cout<<""<<endl;
            pb.Search(orang);
            }
        else if (pilihan=="Add"){
            pb.inputcontact();
            cout<<"Contact berhasil ditambahkan!!"<<endl;
            cout<<""<<endl;
            }
        else{
            cout<<"Silakan masukkan input yang valid"<<endl;//jika input salah
            }
    }
   return 0; 
}
