#define _CRT_SECURE_NO_WARNINGS 1

//�༶ָ��
//Ұָ��
//int main01()
//{
//    //Ұָ�����û�г�ʼ����ָ��,ָ���ָ���������,������ ����Ұָ��
//    //int  a = 0;
//    //ָ��p����ĵ�ַһ���Ƕ������(��ϵͳ�������)
//    int* p;//Ұָ�� 
//    *p = 200;
//    printf("%d\n", *p);
//    system("pause");
//    return 0;
//}


//��ָ��
//int main()
//{
//    int  a;
//    //��ָ���ֵ��ֵΪ0,0x0000000 =  NULL
//    int* p = NULL;//��ָ��p�����ݸ�ֵΪ0
//
//    *p = 200;//err  ��Ϊp������0x0000�ĵ�ַ,�����ַ�ǲ�����ʹ�õ�,�Ƿ�
//    printf("%d\n", *p);
//    system("pause");
//    return 0;
//}


//����ָ��
//int main()
//{
//    //void b; �����Զ���void���͵ı���,��Ϊ��������֪��������������Ŀռ�
//    //���ǿ��Զ���void *����,��Ϊָ�붼��4���ֽ�
//    int  a = 10;
//    short b = 10;
//    void* p = (void*)&a;//����ָ����Ա�������ĵ�ַ
//    void* q = (void*)&b;
//    //printf("%d\n", *p);//err  p��void*,��֪��ȡ�����ֽڵĴ�С
//    printf("%d\n", *(int*)p);// *(  (int *)��ַ)
//    system("pause");
//    return 0;
//}

//int main()
//{
//    int  a = 10;
//    int  b = 20;
//    //const���ε��� * ���Ǳ���p,
//    //�������ε���*
//
//    //const int  *p = &a;//����ͨ�� *p,��p��ָ��ռ������
//    //*p = 100; err  ��Ϊ����ͨ��p��p��ָ��ռ������
//    //const���εı���p
//    //p����ĵ�ַ�������޸�
//    //int  * const p = &a;
//    //p = &b;err  p�����ֵ���ܱ�����
//    const  int* const p = &a;//p�����ָ���ܸı�,����ͨ��*p�޸�p
//    //���ǿ�ռ������
//    system("pause");
//    return 0;
//}

////�༶ָ��
//int main()
//{
//    int a = 10;
//    //*p  int a     int *p
//    int* p = &a;
//    //*q  int *p   int **q
//    int** q = &p;
//    //���*��&����,�����
//    // **q == *(*q) == *(p) ==  a
//    //**q == *(*q) == *(&a) ==  a
//    printf("%d\n", **q);
//    // *k  int **q  int ***k
//    int*** k = &q;
//    //*���Ž��,�������k��һ��ָ�����
//    //k��һ������
//    //k������,������k�Ϻ�,ʣ�µ�����
//    //k��������˭�ĵ�ַ  ������k��k�����*һ���Ϻ�,ʣ��ʲô����
//    //�ͱ���ʲô�������ݵĵ�ַ
//    int******************* g;
//    int******************** f = &g;
//    system("pause");
//    return 0;
//}
//
//int main()
//{
//    //int  a[10] = {1,2,3,4,5,6,7,8,9,10};
//    int  a[10] = { 0 };
//    //a ������,��Ԫ�صĵ�ַ
//    int* p = a;//ָ��p���������Ԫ�صĵ�ַ
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//    {
//        //printf("%d ",a[i]);
//        //printf("%d ", *(p+i));
//        *(p + i) = i;
//    }
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//    {
//        printf("%d ", a[i]);
//        //printf("%d ", *(p+i));
//        //*(p + i) = i;
//    }
//    system("pause");
//    return 0;
//}
//
//int main()
//{
//    //[] == *()
//    int  a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int* p = a;
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//    {
//        //printf("%d ",a[i]);//a[i] == *(a+i)
//        //printf("%d ", *(p+i));
//        //printf("%d ", p[i]);// p[i]  == *(p+i)
//        printf("%d ", *(a + i));
//    }
//    system("pause");
//    return 0;
//}
//int main09()
//{
//    //[]�ǲ��������ר��
//    //int  a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    //  []  ==  *()
//    //p[0]   ==  *(p+0)
//    int a = 10;
//    int* p = &a;
//    p[0] = 100;
//    //p[1] = 200;
//    printf("a=%d\n", a);
//    system("pause");
//    return 0;
//}

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    // int *p1 = &a  int *p2 = &a  int *p2 = &a
    //����:  �����е�ÿһ��Ԫ�ض���ָ��(��ַ)
    int* num[3] = { &a,&b,&c };
    //printf("%d\n",sizeof(num));
    ////&a  ==  num[0]
    //for(int i=0;i<sizeof(num)/sizeof(num[0]);i++)
    //{
    // printf("%d\n",*num[i]);
    //
    //}
    //����һ��ָ��������������num��Ԫ�صĵ�ַ
    // num ==  &num[0] =   &(int *)  == int **
    //num[0]��int *����,Ҫ����int  *���͵ĵ�ַ,��Ҫ������һ��*
    int** k = num;
    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
    {
        printf("%d ", **(k + i));
    }

    system("pause");
    return 0;
}