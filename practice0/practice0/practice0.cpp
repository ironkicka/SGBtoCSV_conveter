// practice0.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "practice0.h"
#include <fstream>
#include <string>
#include <sstream> //�J���}�ŋ�؂邽�߂ɕK�v
 #include <cmath>
#include <vector>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �B��̃A�v���P�[�V���� �I�u�W�F�N�g�ł��B

CWinApp theApp;



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC �����������āA�G���[�̏ꍇ�͌��ʂ�������܂��B
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: �K�v�ɉ����ăG���[ �R�[�h��ύX���Ă��������B
			_tprintf(_T("�v���I�ȃG���[: MFC �̏��������ł��܂���ł����B\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �A�v���P�[�V�����̓�����L�q����R�[�h�������ɑ}�����Ă��������B
// �������ł���t�@�C���p�X����t�@�C���I�u�W�F�N�g�����
    ifstream ifs("C:\\users\\hioki\\documents\\cpp_test\\csvtest3.csv");
 
    // �J���Ȃ�������G���[
    if (!ifs)
    {
        cout << "Error! File can not be opened" << endl;
        return 0;
    }
 
     
    //  ���ɕS�l���̔z�������Ă����B
    //�@���O�E����E�p��E���w�̏��ɒl������B
    vector <vector <string>> Score;
    string str = "";
   
    // �t�@�C���̒��g����s���ǂݎ��
    while(getline(ifs, str))
    {
        string tmp= "";
        istringstream stream(str);
		vector <string> inner;
        // ��؂蕶�����Ȃ��Ȃ�܂ŕ�������؂��Ă���
        while (getline(stream, tmp, ','))//��s������
        {
            //��s���̋�؂�ꂽ������tmp�ɓ���
			inner.push_back(tmp);
        }
		Score.push_back(inner);//�s���ƂɎ����I�ɓY�������ς��B
       
    }
	ifs.close();
	ifs.clear();//�t���O�������B�@close clear�̓Z�b�g
	
	cout<< Score.size()<<endl;

	vector<double>	 ad1;
	vector<double>	 ad2;
	double    sum1= 0;
	double    sum2=0;
    string tmp = "";
	const double FRAMESIZE =10000.0;
	cout<<"�t���[������"<<FRAMESIZE<<endl;
	double emg_bias1;
	vector<double> iemg1;
    //
	cout<<"�f�[�^����"<<Score.size()<<endl;

    for (int count = 0; count < Score.size(); count++)
    {   
		
        //�z��ɂ���f�[�^��double�ɕϊ�
       ad1.push_back(stod(Score[count][0]));
       sum1 += ad1[count];
	   //cout<<ad1[count]<<endl;
    }
	 for (int count = 0; count < Score.size(); count++)
    {   
		
        //�z��ɂ���f�[�^��double�ɕϊ�
       ad2.push_back(stod(Score[count][1]));
       sum2 += ad2[count];
	 // cout<<ad2[count]<<endl;
    }
	vector<double> emg1;
	int n=0;
	int a=0;//ad�p�J�E���^

	do{
	 double sum=0;
	 int m=0;
	 emg1.clear();//����d�v�B
	 /////////////////�ϕ��p�z��ɋؓd���i�[
	 //cout<<"ad["<<a<<"]����ad["<<a+FRAMESIZE-1<<"]"<<endl;
	  for(m=0;m<FRAMESIZE;m++){
	 emg1.push_back(ad1[a]);
	 //cout<<emg1[m]<<endl;
	 a++;
	
	 }
	/////////////////�ϕ��J�n
     for(m=0;m<FRAMESIZE;m++){//�t���[�����̐��f�[�^�̘a���Ƃ�B
        sum+=emg1[m];
      }
      emg_bias1=sum/FRAMESIZE;//�t���[�����̐��f�[�^�̕��ςƂ�
    //cout<<"�o�C�A�X��"<<emg_bias1<<endl;
      sum=0;//sum�̍ė��p�̂��߂̏�����
	/////////////////�e�_�ƃo�C�A�X�̍����o���B
      for(m=0;m<FRAMESIZE;m++){
        sum+=abs(emg1[m]-emg_bias1);
     }
	//////////////////�U���̕��ς��Ƃ�Aiemg�Ɋi�[
      iemg1.push_back(sum/FRAMESIZE);
	  //cout<<"���̘a��"<<sum<<endl;
	 // cout<<"�ϕ��ؓd="<<iemg1[n]<<endl;
	 // cout<<endl;
	 // cout<<"���[�v"<<n+1<<"��ڏI���"<<endl;
	  a=n+1;//�z��̏���
	  n++;//iemg�̔z��ԍ����V�t�g
	  
	}while((Score.size()-n)>=FRAMESIZE);

 cout<<"���ڂ̍��v��"<<sum1<<endl;

	ofstream ofs("C:\\users\\hioki\\documents\\cpp_test\\csvtest_result_1025.csv");

	for(int k=0;k<iemg1.size();k++){
	ofs<<iemg1[k]<<endl;
	}
	cout<<"�o�͊���"<<endl;
    return 0;
		}
	}
	else
	{
		// TODO: �K�v�ɉ����ăG���[ �R�[�h��ύX���Ă��������B
		_tprintf(_T("�v���I�ȃG���[: GetModuleHandle �����s���܂���\n"));
		nRetCode = 1;
	}

	return nRetCode;
}


