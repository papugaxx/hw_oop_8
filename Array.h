#pragma once
template <typename T>
class Array {
private:
    T* arr;       
    int size;    

public:

    void resize(int newSize);
    Array();                      
    ~Array();                      
    int GetSize() const;          
    void SetSize(int newSize);     
    int GetUpperBound() const;    
    bool IsEmpty() const;          
    void FreeExtra();              
    void RemoveAll();              
    T GetAt(int index) const;     
    void SetAt(int index, const T& value); 
    T& operator[](int index);      
    void Add(const T& value);     
    void Append(const Array<T>& other); 
    Array<T>& operator=(const Array<T>& other); 
    void InsertAt(int index, const T& value);  
    void RemoveAt(int index);                  

};
