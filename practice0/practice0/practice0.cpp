// practice0.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "practice0.h"
#include <fstream>
#include <string>
#include <sstream> //カンマで区切るために必要
 #include <cmath>
#include <vector>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一のアプリケーション オブジェクトです。

CWinApp theApp;



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// MFC を初期化して、エラーの場合は結果を印刷します。
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 必要に応じてエラー コードを変更してください。
			_tprintf(_T("致命的なエラー: MFC の初期化ができませんでした。\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: アプリケーションの動作を記述するコードをここに挿入してください。
// 第一引数であるファイルパスからファイルオブジェクトを作る
    ifstream ifs("C:\\users\\hioki\\documents\\cpp_test\\csvtest3.csv");
 
    // 開かなかったらエラー
    if (!ifs)
    {
        cout << "Error! File can not be opened" << endl;
        return 0;
    }
 
     
    //  仮に百人分の配列を作っておく。
    //　名前・国語・英語・数学の順に値が入る。
    vector <vector <string>> Score;
    string str = "";
   
    // ファイルの中身を一行ずつ読み取る
    while(getline(ifs, str))
    {
        string tmp= "";
        istringstream stream(str);
		vector <string> inner;
        // 区切り文字がなくなるまで文字を区切っていく
        while (getline(stream, tmp, ','))//一行ずつ処理
        {
            //一行分の区切られた文字がtmpに入る
			inner.push_back(tmp);
        }
		Score.push_back(inner);//行ごとに自動的に添え字が変わる。
       
    }
	ifs.close();
	ifs.clear();//フラグを消す。　close clearはセット
	
	cout<< Score.size()<<endl;

	vector<double>	 ad1;
	vector<double>	 ad2;
	double    sum1= 0;
	double    sum2=0;
    string tmp = "";
	const double FRAMESIZE =10000.0;
	cout<<"フレーム数は"<<FRAMESIZE<<endl;
	double emg_bias1;
	vector<double> iemg1;
    //
	cout<<"データ個数は"<<Score.size()<<endl;

    for (int count = 0; count < Score.size(); count++)
    {   
		
        //配列にあるデータをdoubleに変換
       ad1.push_back(stod(Score[count][0]));
       sum1 += ad1[count];
	   //cout<<ad1[count]<<endl;
    }
	 for (int count = 0; count < Score.size(); count++)
    {   
		
        //配列にあるデータをdoubleに変換
       ad2.push_back(stod(Score[count][1]));
       sum2 += ad2[count];
	 // cout<<ad2[count]<<endl;
    }
	vector<double> emg1;
	int n=0;
	int a=0;//ad用カウンタ

	do{
	 double sum=0;
	 int m=0;
	 emg1.clear();//これ重要。
	 /////////////////積分用配列に筋電を格納
	 //cout<<"ad["<<a<<"]からad["<<a+FRAMESIZE-1<<"]"<<endl;
	  for(m=0;m<FRAMESIZE;m++){
	 emg1.push_back(ad1[a]);
	 //cout<<emg1[m]<<endl;
	 a++;
	
	 }
	/////////////////積分開始
     for(m=0;m<FRAMESIZE;m++){//フレーム分の生データの和をとる。
        sum+=emg1[m];
      }
      emg_bias1=sum/FRAMESIZE;//フレーム分の生データの平均とる
    //cout<<"バイアスは"<<emg_bias1<<endl;
      sum=0;//sumの再利用のための初期化
	/////////////////各点とバイアスの差を出す。
      for(m=0;m<FRAMESIZE;m++){
        sum+=abs(emg1[m]-emg_bias1);
     }
	//////////////////振幅の平均をとり、iemgに格納
      iemg1.push_back(sum/FRAMESIZE);
	  //cout<<"差の和は"<<sum<<endl;
	 // cout<<"積分筋電="<<iemg1[n]<<endl;
	 // cout<<endl;
	 // cout<<"ループ"<<n+1<<"回目終わり"<<endl;
	  a=n+1;//配列の序数
	  n++;//iemgの配列番号をシフト
	  
	}while((Score.size()-n)>=FRAMESIZE);

 cout<<"一列目の合計は"<<sum1<<endl;

	ofstream ofs("C:\\users\\hioki\\documents\\cpp_test\\csvtest_result_1025.csv");

	for(int k=0;k<iemg1.size();k++){
	ofs<<iemg1[k]<<endl;
	}
	cout<<"出力完了"<<endl;
    return 0;
		}
	}
	else
	{
		// TODO: 必要に応じてエラー コードを変更してください。
		_tprintf(_T("致命的なエラー: GetModuleHandle が失敗しました\n"));
		nRetCode = 1;
	}

	return nRetCode;
}


