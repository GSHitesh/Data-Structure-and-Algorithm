

#include <iostream>

using namespace std;

struct arr{
    int arr[10];
    int length;
    int size;
};


void display(struct arr ar){
    for(int i =0;i<ar.length;i++){
        cout << ar.arr[i] << " ";
}
cout << endl;
    
}

void append(struct arr *ar,int x){ // Its the call by address, as we are upadating the array
    if(ar->length <= ar-> size)
        ar->arr[ar->length++] = x;
}

void insert(struct arr *ar, int index, int value){
    if(index >=0 && index <= ar->length){
        for(int i=ar->length;i>index;i--){
            ar->arr[i] = ar->arr[i-1];
            
        }
        
        ar->arr[index] = value;
        ar->length++;       // This line is very important otherwise array will be short
    }
}

int Delete(struct arr *ar,int index){
    
    int x = 0;
    if(index >=0 && index < ar->length)
    {
        int x = ar->arr[index];
        for(int i = index; i<ar->length;i++)
            ar->arr[i] = ar->arr[i+1];
        ar->length--;
        return x;
    }
    
    
    return x;
}


int main()
{
    struct arr ar{{1,2,3,4,5},5,10};
    display(ar);
    
    append(&ar,6); // You have to pass the pointer
    display(ar);
    
    insert(&ar,5,9);
    display(ar);
    
    cout << "Deleted Element is: " << Delete(&ar,0) << endl;
    display(ar);
     

    return 0;
}
