#include <iostream>
using namespace std;

class MataKuliah
{
protected:
    float presensi;

public:
    MataKuliah()
    {
        presensi = 0.0;
    }
    virtual void namaMataKuliah() { return; }

    void setPresensi(float nilai)
    {
        this->presensi = nilai;
    }

    float getPresensi()
    {
        return presensi;
    }

};

class Pemrograman : public MataKuliah
{
private:
    float activity;
    float exercise;
    float tugasAkhir;

public:
    void inputNilai(float presensi, float activity, float exercise, float tugasAkhir) override
    {
        this->presensi = presensi;
        this->activity = activity;
        this->exercise = exercise;
        this->tugasAkhir = tugasAkhir;
    }

    float hitungNilaiAkhir() override
    {
        
        float nilaiAkhir = (0.2 * presensi) + (0.3 * activity) + (0.3 * exercise) + (0.2 * tugasAkhir);
        return nilaiAkhir;
    }

    void cekKelulusan() override
    {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir >= 75)
            cout << "Lulus" << endl;
        else
            cout << "Tidak Lulus." << endl;
    }
};

class Jaringan : public MataKuliah
{
private:
    float activity;
    float exercise;

public:
    void inputNilai(float activity, float exercise) override
    {
        this->activity = activity;
        this->exercise = exercise;
    }

    float hitungNilaiAkhir() override
    {
        
        float nilaiAkhir = (0.4 * activity) + (0.6 * exercise);
        return nilaiAkhir;
    }

    void cekKelulusan() override
    {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir >= 75)
            cout << "Lulus" << endl;
        else
            cout << "Tidak Lulus." << endl;
    }
};

int main()
{
    char pilih;
    MataKuliah* mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    do
    {
        cout << "Pilih Mata Kuliah:" << endl;
        cout << "1. Pemrograman" << endl;
        cout << "2. Jaringan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case '1':
            mataKuliah = &pemrograman;            
        case '2':
            mataKuliah = &jaringan;            
        case '3':
            cout << "" << endl;
            return 0;
        }

        float presensi, activity, exercise, tugasAkhir;
        
        cout << "Masukkan nilai activity: ";
        cin >> activity;
        cout << "Masukkan nilai exercise: ";
        cin >> exercise;
        if (pilih == '1')
        {
            cout << "Masukkan nilai presensi: ";
            cin >> presensi;

            cout << "Masukkan nilai tugas akhir: ";
            cin >> tugasAkhir;            
        }

        mataKuliah->inputNilai(presensi, activity, exercise, tugasAkhir);
        mataKuliah->cekKelulusan();

    } while (pilih != '3');

    return 0;
}
