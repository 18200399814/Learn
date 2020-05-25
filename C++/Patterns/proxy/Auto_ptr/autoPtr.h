template<class T>
class Auto_ptr {
private:
    T *ptr;        //������ָ��ֵ
    mutable bool owns;    //�Ƿ�ӵ�и�ָ��
public:
    //��������ʽת���Ĺ��캯��
    explicit Auto_ptr(T *p = 0):ptr(p),owns((bool)p){}    //������ʽת��������Auto_ptr<int> Ap = new int(1024) //error
    //���ƹ��캯��
    //Auto_ptr(const Auto_ptr& a):ptr(a.ptr),owns(a.owns){ a.owns = 0;}
    //������ĸ��ƹ��캯��
    template <class U>
    Auto_ptr(const Auto_ptr<U>& a):ptr(a.ptr),owns(a.owns){ a.owns = 0;}

    //���ظ�ֵ������
    Auto_ptr& operator=(const Auto_ptr& a)
    {
        if(&a != this)    //��ֹ����ֵ
        {
            if(owns)
                delete ptr;
            owns = a.owns;
            ptr  = a.ptr;
            a.owns = 0;
        }
		return *this;
    }
    //����������ظ�ֵ������
    template<class U>
    Auto_ptr& operator=(Auto_ptr<U>& a)
    {
        if (&a != this)
        {
            if(owns)
                delete ptr;
            owns = a.owns;
            ptr  = a.ptr;
            a.owns = false;
        }
        return *this;
    }
    T& operator  *() const {return *ptr;} 
    T* operator ->() const {return ptr;}
    T* get() const { return ptr;}
    void reset(T *p = 0)
    {
        if(owns)
        {
            if(ptr != p)    //���p �� ptr��ֵ��ͬ    
            {
                delete ptr;    //ɾ��ԭ��ָ��Ķ���
            }                //else������ͬ�϶�����ɾ����
        }
        ptr = p;            //���︳ֵʱ��ȫ�ģ�����ptr��pԭ�����
    }
    T* release() const{ owns = false;return ptr;}
    ~Auto_ptr(){if(owns) {cout << "������"<< endl;delete ptr;}}
};