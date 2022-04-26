// Merge sort in C++
 #include <iostream>
	using namespace std;

// Menggabungkan dua subarray L dan M menjadi arr
	void merge(int arr[], int l, int m, int r){
// Membuat salinan dari subarray L A[p..q] dan M A[q+1..r]
	    int i, j, k;
	    int n1 = m - l + 1;
	    int n2 = r - m;
	
	    int L[n1], R[n2];
	
	    for (i = 0; i < n1; i++)
	        L[i] = arr[l + i];
	    for (j = 0; j < n2; j++)
	        R[j] = arr[m + 1 + j];
// Pertahankan indeks sub-array dan larik utama saat ini
	    i = 0;
	    j = 0;
	    k = l;
// Sampai kita mencapai salah satu ujung L atau M, pilih yang lebih besar di antara
// elemen L dan M dan letakkan di posisi yang benar di A[p..r]
	    while (i < n1 && j < n2)
	    {
	        if (L[i] <= R[j])
	        {
	            arr[k] = L[i];
	            i++;
	        }
	        else
	        {
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
 // Saat kita kehabisan elemen di L atau M,
 // ambil elemen yang tersisa dan masukkan ke A[p..r]	
	    while (i < n1)
	    { // Kita keluar dari loop sebelumnya karena j < n2 tidak berlaku
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	
	    while (j < n2)
	    {// Kita keluar dari loop sebelumnya karena i < n1 tidak berlaku
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	// Bagilah array menjadi dua subarray, urutkan dan gabungkan
	void mergeSort(int arr[], int l, int r)
	{
	    if (l < r)
	    {// m adalah titik di mana array dibagi menjadi dua subarray
	
	        int m = l + (r - l) / 2;
	
	        mergeSort(arr, l, m);
	        mergeSort(arr, m + 1, r);
	// Gabungkan subarray yang diurutkan
	        merge(arr, l, m, r);
	    }
	}
	// Cetak array
	void show(int A[], int size)
	{
	    int i;
	    for (i = 0; i < size; i++)
	    {
	    	cout <<"["<< A[i]<<"]";
		}	
	}
	// Driver program
	int main()
	//int arr_size = sizeof(myarray)/sizeof(myarray[0]);
	{
	    int size;
	    cout << "Masukan Banyak Data : ";
		cin >> size;
		cout << endl;
		
	    cout << "Masukan " << size << " Nilai Data : "<<endl;
    	int arr[size];
    	
	    for (int i = 0; i < size; ++i)
	    {
	        cin >> arr[i];
	    }
		cout << endl;
		// memanggil mergesort(array,kanan,kiri) 
		
	    mergeSort(arr, 0, size);
		// menampilkan hasil sorting melalui looping input
	    cout << "Hasil Data yang sudah di Sorting: \n";
	    show(arr, size);
	    return 0;
	}
