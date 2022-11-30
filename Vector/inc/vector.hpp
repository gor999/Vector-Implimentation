
template<typename X> class Vector{
    private:
        X* m_arr = nullptr;
        int m_size;
        int m_capacity;
    public:
        Vector():
		m_capacity(0),
		m_size(0)
		{};
        ~Vector();
        Vector(int size);
        Vector(const std::initializer_list<X> &list); //Constructor for parametres
        Vector(const Vector &other); //Copy Constructor
        Vector&operator=(const Vector &other); // operator =
        bool operator==(const Vector &other); // operator == 
        X& operator[](int);//operator []
        void show();
        void clear();
        int size();
        void push_back(X);
        void pop_back();
        bool empty();
        int capacity();
}; 

template<typename X> X& Vector<X>::operator[](int index)
{
    if (index >= m_size || index < 0) {
        std::cout << "Array index out of bound, exiting"<<std::endl;
        exit(0);
    }   
    return m_arr[index];
}


template<typename X>
bool Vector<X>::empty(){
    if(m_size == 0){
        return true;
    }
    return false;
}

template<typename X>
void Vector<X>:: clear(){
    m_capacity = 0;
    m_size = 0;
}


template<typename X>
void Vector<X>::push_back(X elem){
    if(m_size == m_capacity){
        X *temp = new X[m_capacity + 1 * 2];
        for(int i = 0; i < m_size; ++i){
            temp[i] = m_arr[i];
        }
        delete m_arr;
        m_arr = temp;
    }
    m_arr[m_size++] = elem;
}
template<typename X>
void Vector<X>::pop_back(){
    if(m_size == m_capacity / 2){
        m_capacity = m_size;
    }
    if(m_size != 0){
        m_arr[--m_size];
    }
}



template<typename X>
int Vector<X>::capacity(){
    return m_capacity;
}
template<typename X>
int Vector<X>::size(){
    return m_size;
}

template <typename X>
Vector<X>::Vector(const Vector &other){
    (*this).m_size = other.m_size;
    (*this).m_arr = new X[(*this).m_size];
    (*this).m_capacity = other.m_capacity;

    for(int i = 0; i < m_size; ++i){
        m_arr[i] = other.m_arr[i]; 
    }
}
template <typename X>
Vector<X> &Vector<X>::operator=(const Vector &other){
    if(this == &other){
        return *this;
    }
    delete m_arr;
    (*this).m_size = other.m_size;
    (*this).m_arr = new X[m_size];
    (*this).m_capacity = other.m_capacity;

    for(int i = 0; i < m_size; ++i){
        m_arr[i] = other.m_arr[i];
    }
    return *this;
}

template <typename X>
bool Vector<X>::operator==(const Vector &other){
    if(m_size != other.m_size){
        return false;
    }
    for(int i = 0; i < m_size; ++i){
        if(m_arr[i] != other.m_arr[i]){
            return false;
        }
    }
    return true;
};

template<typename X> 
Vector<X>::Vector(int size):
    m_size(size), m_capacity(m_size * 2){}

template<typename X> Vector<X>::Vector(const std::initializer_list<X> &list):
    Vector(list.size()){
    m_arr = new X[m_capacity];
	int count = 0;
	    for (auto &element : list)
	    {   
		    m_arr[count++] = element;
	    }
    }
template<typename X> Vector<X>::~Vector(){
        delete [] m_arr;
        m_arr = nullptr;
    }

template<typename X> void Vector<X>::show(){
    if(m_size == 0){
        std::cout<<"The vectore dont have element"<<std::endl;
    }else{
        for(int i = 0; i < m_size; ++i){
            std::cout<<m_arr[i]<<std::endl;
        }
    }
}
