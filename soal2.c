/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : Data Manipulation and External Files
 *   Hari dan Tanggal    : Senin, 20 April 2026
 *   Nama (NIM)          : Muhammad Fadhil Abyan (13224008)
 *   Nama File           : soal2.c
 *   Deskripsi           : Suatu array dibagi menjadi tiga segment. Ketiga segment tersebut harus memiliki bobot sum yang seimbang
 * 
 */

 void find_sum(int* arr, int N, int* sum){
    *sum = 0;
    for(int i = 0; i<N; i++){
        *sum += arr[i];
    }
 }

 int find_max(int* arr, int N){
    int max = arr[0];
    for(int i = 0; i < N; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
 }

  int find_min(int* arr, int N){
    int min = arr[0];
    for(int i = 0; i < N; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
 }

 int max_of_segment(int* s1, int* s2, int* s3, int n1, int n2, int n3){
    int max1 = find_max(s1,n1);
    int max2 = find_max(s2,n2);
    int max3 = find_max(s3,n3);

    if(max1 > max2 && max1 > max3){
        return max1;
    }
    else if(max2 > max1 && max2 > max3){
        return max2;
    }
    else if(max3 > max1 && max3 > max2){
        return max3;
    }
 }

 int min_of_segment(int* s1, int* s2, int* s3, int n1, int n2, int n3){
    int min1 = find_min(s1,n1);
    int min2 = find_min(s2,n2);
    int min3 = find_min(s3,n3);

    if(min1 < min2 && min1 < min3){
        return min1;
    }
    else if(min2 < min1 && min2 < min3){
        return min2;
    }
    else if(min3 < min1 && min3 < min2){
        return min3;
    }
 }



 #include <stdio.h>
 #include <string.h>
  
 int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int sum_array;

    for(int i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }

    find_sum(arr, n, &sum_array);

    int average_segment = sum_array/3;
    


    int moving_sum = 0;
    int i_cut = 0;
    int j_cut = 0;
    int flag_segment = 0;

    //Ide, agar tiap segment punya minimum diff, berarti tiap segment harus memiliki
    //jumlahan sebesar sum_array/3

    for(int i = 0; i<n; i++){
        moving_sum += arr[i];
        if(moving_sum >= average_segment){
            if(flag_segment == 0){
                i_cut = i+1;
                moving_sum = 0;
                flag_segment++;

            }
            else if(flag_segment == 1){
                j_cut = i+1;
                moving_sum = 0;
            }

        }
    }
    int n1 = i_cut;
    int n2 = j_cut - i_cut;
    int n3 = n-j_cut;

    int segment1[n1];
    int segment2[n2];
    int segment3[n3];

    for(int i = 0; i<n; i++){
        if(i < i_cut){
            segment1[i] = arr[i];
        }
        else if(i >= i_cut && i < j_cut){
            segment2[i-n1] = arr[i];
        }
        else{
            segment3[i-n2] = arr[i];
        }
    }

    int diff = max_of_segment(segment1, segment2, segment3, n1,n2,n3) - min_of_segment(segment1, segment2, segment3, n1,n2,n3);

    printf("MIN_DIFF %d\n", diff);
    printf("CUT %d %d\n", i_cut, j_cut);


    return 0;
 }
 
