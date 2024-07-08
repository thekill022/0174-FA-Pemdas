#include <iostream>
using namespace std;

class MasukUniversitas{
private : // isi access modifier disini 
int uangPendaftaran;
// isi daftar variable yang dibutuhkan di bawah ini 
int uangSmesterPertama, uangBangunan, totalBiaya;

public:

    MasukUniversitas() {
        uangPendaftaran = 0;
        // isi nilai default variable yang dibutuhkan di bawah ini 
        uangSmesterPertama = 0;
        uangBangunan = 0;
        totalBiaya = 0;
    }

    virtual void namaJalurMasuk()  {

        cout << "Aku Jalur masuk" << endl;
        
    }
    // isi disini dengan fungsi virtual yang dibutuhkan 

    void setUangPendaftaran(int nilai) {
        this->uangPendaftaran = nilai;
    }

    int getUangPendaftaran() {
        return uangPendaftaran;
    }


    // isi setter dan getter variable yang dibutuhkan di bawah ini 
    void setUangSmesterPertama(int nilai) {
        this->uangSmesterPertama = nilai;
    }

    int getUangSmesterPertama() {
        return uangSmesterPertama;
    }

    void setUangBangunan(int nilai) {
        this->uangBangunan = nilai;
    }

    int getUangBangunan() {
        return uangBangunan;
    }

    virtual int hitungtotalBiaya() {
     return   totalBiaya = getUangBangunan() + getUangPendaftaran() + getUangSmesterPertama();
    };

    virtual void tampilkanTotalBiaya() = 0;

    virtual void input() = 0;
   

};

class SNBT : public MasukUniversitas {
    // isi disini untuk melengkapi class SNBT 
public :
    void namaJalurMasuk() {

        cout << "SNBT" << endl;

    };
    void input() {
        
        int daftar, smester, bangunan;

        cout << "Masukkan biaya daftar : ";
        cin >> daftar;
        cout << "Masukkan biaya smester : ";
        cin >> smester;
        cout << "Masukkan biaya bangunan : ";
        cin >> bangunan;

        setUangBangunan(bangunan);
        setUangPendaftaran(daftar);
        setUangSmesterPertama(smester);

    };


    int hitungtotalBiaya() {

        return getUangBangunan() + getUangPendaftaran() + getUangSmesterPertama();
 
    }

    void tampilkanTotalBiaya() {
        cout << "Total : " << hitungtotalBiaya() << endl << endl;
    }

};

class SNBP : public MasukUniversitas{
    // isi disini untuk melengkapi class SNBP 
public :
    void namaJalurMasuk() {

        cout << "SNBP" << endl;

    };
    void input() {

        int daftar, smester, bangunan;

        cout << "Masukkan biaya daftar : ";
        cin >> daftar;
        cout << "Masukkan biaya smester : ";
        cin >> smester;
        

        
        setUangPendaftaran(daftar);
        setUangSmesterPertama(smester);

    };


    int hitungtotalBiaya() {

        return getUangPendaftaran() + getUangSmesterPertama();

    }

    void tampilkanTotalBiaya() {
        cout << "Total : " << hitungtotalBiaya() << endl << endl;
    }
};

int main()
{
    MasukUniversitas* masuk;
    SNBT snbt;
    SNBP snbp;

    

    while (true)
    {
        int pil;

        cout << "\nPilih Jalur Masuk : " << endl;
        cout << "1. SNBT " << endl;
        cout << "2. SNBP " << endl;
        cout << "3. KELUAR " << endl;
        cout << "Pilih : ";
        cin >> pil;

        switch (pil)
        {
        case 1 :
            masuk = &snbt;
            masuk->namaJalurMasuk();
            masuk->input();
            masuk->tampilkanTotalBiaya();
            break;
        case 2 :
            masuk = &snbp;
            masuk->namaJalurMasuk();
            masuk->input();
            masuk->tampilkanTotalBiaya();
            break;
        case 3 :
            return 0;

        default:
            break;
        }
    }

}
