//���˻�������ģ��ϵͳ(UAV.MAS)
//UAV.MAS: Unmanned Aerial Vehicle. Management and Analog System

#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
using namespace std;

class Fly {//���˻���
	public:
		void print_details() {
			//�����Ϣ
			cout << "\n����:" << Name
			     << "\n���:" << ID
			     << "\n�ͺ�:" << Version
			     << "\n״̬:" << Avail
			     << "\n����:" << Desc
			     << "\n��ע:" << Note << endl;
		}
		void clean() {
			//�������˻�
			Name = "��";
			ID = "��";
			Version = "��";
			Avail = "��";
			Desc = "��";
			Note = "��";
		}

		Fly() {
			//���캯��(��ʼ��)
			Name = "��";
			ID = "��";
			Version = "��";
			Avail = "��";
			Desc = "��";
			Note = "��";
		}

		string Name;     //���˻�����(���ظ�)
		string ID;       //���˻����(Ψһȷ��)
		string Version;  //���˻��ͺ�(���ظ�)
		string Avail;    //���˻�״̬(�ڸ�/������)
		string Desc;     //Description���˻�����(�����������ַ����ַ���)
		string Note;     //���˻���ע(�����������ַ����ַ���)
} Flyer;
vector<Fly> FV;   //���˻��ֿ��������(����ʱ������ջ��)

/////////ȫ�ֳ�����///////////
string Head_Str =
    "�������������������������������������˻�������ģ��ϵͳ(UAV.MAS)����������������������������������\n\n";
string Please_Str = "\n>>������ָ��:\n";
string Found = "\n>>���ҳɹ���\n";
string Unfound = "\n>>����ʧ�ܣ�\n";
string Right = ""; //����ȷ����Ϊ����
//////
HANDLE Winptr = GetStdHandle(STD_OUTPUT_HANDLE);	//��ǰ����̨���ھ��(ָ��)
int _Backcolor = 15; //����̨��ɫ������ɫ
int _Fontcolor = 9; //����̨��ɫ����ɫ
const COORD Sizer = {100, 20000}; //��������С(const����Ϊûconst��ʱ������bug���½��ȶ�ʧ��qwq)
////////////////////////////

/////////����������//////////
int SLP();   //ϵͳ����
void SFD();  //��������
int MMP();   //���˵�
void WFD();  //��ѯ���˻���Ϣ
void CFD();  //�������˻���Ϣ
void ADFD(); //��ɾ���˻���Ϣ
void FAG();  //���˻�ģ��С��Ϸ
void SLKM(); //ϵͳ�������
void MF();   //���๦��
int GMr(int, int); //��ȡģʽ
void OE();       //ִ�н���
bool Lockor(string);    //�����
string Locker(string);  //��������㷨
string tostring(int);  //����ת�ַ���
///////////////////////////

//////////������////////////
int main() {
	if (SLP()) {
		return 0;
	}
Begin:
	int Model = MMP(); //���˵�
	switch (Model) {
		case 0: {
			system("cls");
			cout << Head_Str
			     << "\n>>���沢�˳���";
			SFD();
			fflush(stdin);
			getch();
			return 0;
			break;
		}
		case 1: {
			//��ѯ���˻���Ϣ
			system("cls");
			WFD();
			goto Begin;
			break;
		}
		case 2: {
			//�������˻���Ϣ
			system("cls");
			CFD();
			goto Begin;
			break;
		}
		case 3: {
			//���˻���ڻ�����
			system("cls");
			ADFD();
			goto Begin;
			break;
		}
		case 4: {
			//���˻�ģ��С��Ϸ
			system("cls");
			FAG();
			goto Begin;
			break;
		}
		case 5: {
			//ϵͳ�������
			system("cls");
			SLKM();
			goto Begin;
			break;
		}
		case 6: {
			//���๦��
			system("cls");
			MF();
			goto Begin;
			break;
		}
		default: {
			cout << "\n\nδ֪����";
			Sleep(2000);
			return 0;
			break;
		}
	}
	return 0;
}
///////////////////////////

//////////����������///////////
int SLP() {
	//SLP: System_Loading_Pageϵͳ����ҳ��
	Winptr = GetStdHandle(STD_OUTPUT_HANDLE); //ץȡ���ھ��
	system("color F9");
	system("cls");
	system("mode con: cols=100 lines=45");

	//���������
	ifstream wfin("UAV_MAS_Setting_Datas.txt", ios::in);
	if (!wfin.is_open()) {
		//���ⲿ�ļ�:Ĭ��
		int _Backcolor = 15;
		int _Fontcolor = 9;
	} else {
		//�ⲿ����
		wfin >> _Backcolor >> _Fontcolor; //������ɫ
		if (_Backcolor < 0 || _Backcolor > 15 || _Fontcolor < 0 || _Fontcolor > 15 || _Backcolor == _Fontcolor) {
			_Backcolor = 15;
			_Fontcolor = 9; //����:��ԭΪĬ��
		}
	}
	wfin.close();
	wfin.clear();

	SetConsoleTitleA("���˻�������ģ��ϵͳ(UAV.MAS)    Unmanned Aerial Vehicle. Management and Analog System");
	{
		//����̨��������
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 10;
		cfi.dwFontSize.Y = 18;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_HEAVY;
		SetCurrentConsoleFontEx(Winptr, FALSE, &cfi); //����
		SetConsoleScreenBufferSize(Winptr, Sizer);  //���û�����
	}

	SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor); //������ɫ
	system("cls");
	cout << Head_Str;
	Sleep(500);
	cout << "ϵͳ�����У����Ժ�";
	for (int i = 0; i < 10; i++) {
		cout << ".";
		Sleep(50);
	}
	//ǰ���ļ������ؼ����Ų�
	ifstream fina, finb;
	fina.open("UAV_MAS_working_datas.txt", ios::in);
	finb.open("UAV_MAS_retired_datas.txt", ios::in);
	if ((!fina.is_open()) || (!finb.is_open())) {
		return 0;
	}
	Sleep(300);
	system("cls");
	cout << Head_Str;
	cout << "\n>>ǰ���ļ�������\n";
	string name, id, version, avail, desc, note;
	fflush(stdin);
	while (fina >> name >> id >> version >> avail >> desc >> note) {
		Flyer.Name = name;
		Flyer.ID = id;
		Flyer.Version = version;
		if (avail == "�ڸ�") {
			//�����û��Ƿ�״ֵ̬
			Flyer.Avail = avail;
		} else {
			Flyer.Avail = "������";
		}
		Flyer.Desc = desc;
		Flyer.Note = note;
		FV.push_back(Flyer);
	}
	fina.close();
	fina.clear();
	fflush(stdin);
	while (finb >> name >> id >> version >> avail >> desc >> note) {
		Flyer.Name = name;
		Flyer.ID = id;
		Flyer.Version = version;
		if (avail == "�ڸ�") {
			//�����û��Ƿ�״ֵ̬
			Flyer.Avail = avail;
		} else {
			Flyer.Avail = "������";
		}
		Flyer.Desc = desc;
		Flyer.Note = note;
		FV.push_back(Flyer);
	}
	finb.close();
	finb.clear();
	Sleep(100);
	cout << "\n>>���سɹ���\n";
	Sleep(500);

	ifstream kin;
	kin.open("UAV_MAS_key_encoded.txt", ios::in);
	if (kin.is_open()) {
		kin >> Right;
	}
	kin.close();
	kin.clear();
	if (!int(Right.size())) {
		return 0;
	}
Begin_Cin_Key:
	system("cls");
	cout << Head_Str
	     << ">>���������Ա����:" << endl;
	string Key;
	while (1) {
		fflush(stdin);
		cin >> Key;
		if (Lockor(Locker(Key))) {
			Sleep(300);
			cout << "\n>>������ȷ,����ϵͳ��\n";
			Sleep(500);
			break;
		} else {
			cout << "\n>>�������" << endl;
			Sleep(300);
			cout << "\n>>��1���������룬���������˳�����" << endl;
			fflush(stdin);
			if (getch() != '1') {
				system("cls");
				cout << Head_Str
				     << ">>�˳�����" << endl;
				Sleep(1500);
				return -1;
			} else {
				goto Begin_Cin_Key;
			}
		}
	}
	system("cls");
	return 0;
}

void SFD() {
	//SFD: Save_Flys_Datas��������

	//�������˻�����
	ofstream fouta, foutb;
	fouta.open("UAV_MAS_working_datas.txt", ios::out);
	foutb.open("UAV_MAS_retired_datas.txt", ios::out);
	if (int(FV.size())) {
		for (int i = 0; i < int(FV.size()); i++) {
			if (FV[i].Avail == "�ڸ�") {
				Flyer = FV[i];
				fouta << Flyer.Name << endl
				      << Flyer.ID << endl
				      << Flyer.Version << endl
				      << Flyer.Avail << endl
				      << Flyer.Desc << endl
				      << Flyer.Note << endl << endl;
			} else {
				Flyer = FV[i];
				foutb << Flyer.Name << endl
				      << Flyer.ID << endl
				      << Flyer.Version << endl
				      << Flyer.Avail << endl
				      << Flyer.Desc << endl
				      << Flyer.Note << endl << endl;
			}
		}
	} else {
		fouta << "\n";
		foutb << "\n";
	}
	fouta.close();
	foutb.close();
	fouta.clear();
	foutb.clear();

	//��������
	ofstream kout;
	kout.open("UAV_MAS_key_encoded.txt", ios::out);
	if (int(Right.size())) {
		kout << Right;
	} else {
		kout << endl;
	}
	kout.close();
	kout.clear();

	//��������
	ofstream wfout("UAV_MAS_Setting_Datas.txt", ios::out);
	wfout << _Backcolor << " " << _Fontcolor << endl;
	wfout.close();
	wfout.clear();
}

int MMP() {
	//MMP: Main_Menu_Page���˵�ҳ��
	system("cls");
	SetConsoleScreenBufferSize(Winptr, Sizer);
	cout << Head_Str
	     << "�����˵���" << endl << endl
	     << "0.���沢�˳�" << endl
	     << "1.��ѯ���˻���Ϣ" << endl
	     << "2.�������˻���Ϣ" << endl
	     << "3.���˻���ڻ�����" << endl
	     << "4.���˻�ģ��(С��Ϸ)" << endl
	     << "5.ϵͳ�������" << endl
	     << "6.���๦��" << endl;
	cout << Please_Str;
	return GMr(48, 54);
}

void WFD() {
	//WFD: Watch_Fly_Datas��ѯ���˻���Ϣ
	system("cls");
	cout << Head_Str
	     << "����ѯ���˻���Ϣ��\n" << endl
	     << "0.�������˵�" << endl
	     << "1.��ѯȫ�����˻���Ϣ" << endl
	     << "2.�����Ʋ�ѯ���˻���Ϣ" << endl
	     << "3.����Ų�ѯ���˻���Ϣ" << endl
	     << "4.���ͺŲ�ѯ���˻���Ϣ" << endl
	     << "5.��״̬��ѯ���˻���Ϣ" << endl;
	cout << Please_Str;
	int Model = GMr(48, 53);
	switch (Model) {
		case 0:
			break;
		case 1: {
			system("cls");
			cout << Head_Str
			     << "����ѯȫ�����˻���Ϣ��\n";
			Sleep(50);
			for (int pos = 0; pos < int(FV.size()); pos++) {
				FV[pos].print_details();
				Sleep(50);
			}
			OE();
			break;
		}
		case 2: {
			system("cls");
			cout << Head_Str
			     << "�������Ʋ�ѯ���˻���Ϣ��" << endl << endl;
			cout << ">>���������˻�����(��������ո�)��" << endl;
			string name;
			fflush(stdin);
			cin >> name;
			int has = 0;
			for (int pos = 0; pos < int(FV.size()); pos++) {
				if (FV[pos].Name == name) {
					has = 1;
					FV[pos].print_details();
					Sleep(50);
				}
			}
			if (!has) {
				system("cls");
				cout << Head_Str
				     << "�������Ʋ�ѯ���˻���Ϣ��" << endl;
				cout << Unfound;
			}
			OE();
			break;
		}
		case 3: {
			system("cls");
			cout << Head_Str
			     << "������Ų�ѯ���˻���Ϣ��" << endl << endl;
			cout << ">>���������˻����(��������ո�)��" << endl;
			string id;
			fflush(stdin);
			cin >> id;
			int has = 0;
			for (int pos = 0; pos < int(FV.size()); pos++) {
				if (FV[pos].ID == id) {
					has = 1;
					system("cls");
					cout << Head_Str
					     << "������Ų�ѯ���˻���Ϣ��" << endl;
					cout << Found;
					FV[pos].print_details();
					Sleep(50);
					break;
				}
			}
			if (!has) {
				system("cls");
				cout << Head_Str
				     << "������Ų�ѯ���˻���Ϣ��" << endl;
				cout << Unfound;
			}
			OE();
			break;
		}
		case 4: {
			system("cls");
			cout << Head_Str
			     << "�����ͺŲ�ѯ���˻���Ϣ��" << endl << endl;
			cout << ">>���������˻��ͺ�(��������ո�)��" << endl;
			string version;
			fflush(stdin);
			cin >> version;
			int has = 0;
			for (int pos = 0; pos < int(FV.size()); pos++) {
				if (FV[pos].Version == version) {
					has = 1;
					FV[pos].print_details();
					Sleep(50);
				}
			}
			if (!has) {
				system("cls");
				cout << Head_Str
				     << "�����ͺŲ�ѯ���˻���Ϣ��" << endl;
				cout << Unfound;
			}
			OE();
			break;
		}
		case 5: {
			system("cls");
			cout << Head_Str
			     << "����״̬��ѯ���˻���Ϣ��" << endl
			     << "0.�������˵�" << endl
			     << "1.��Ѱȫ���ڸ����˻���Ϣ" << endl
			     << "2.��ѯȫ�����������˻���Ϣ" << endl;
			cout << Please_Str;
			int Model = GMr(48, 50);
			switch (Model) {
				case 0:
					break;
				case 1: {
					for (int pos = 0; pos < int(FV.size()); pos++) {
						if (FV[pos].Avail == "�ڸ�") {
							cout << endl;
							FV[pos].print_details();
							Sleep(50);
						}
					}
					OE();
					break;
				}
				case 2: {
					for (int pos = 0; pos < int(FV.size()); pos++) {
						if (FV[pos].Avail == "������") {
							cout << endl;
							FV[pos].print_details();
							Sleep(50);
						}
					}
					OE();
					break;
				}
				default:
					break;
			}
			break;
		}
		default:
			break;
	}
}

void CFD() {
	string Content, Option, id;
	int pos = 0, has = 0;
	//WFD: Change_Fly_Datas�������˻���Ϣ
Begin_CFD:
	system("cls");
	cout << Head_Str
	     << "���������˻���Ϣ��" << endl
	     << "\n>>��0���������˵����������������������˻���Ϣ" << endl;
	if (getch() == '0')
		goto End_CFD;
	cout << "\n>>���������˻����(��������ո�):" << endl;
	fflush(stdin);
	cin >> id;
	system("cls");
	cout << Head_Str
	     << "���������˻���Ϣ��" << endl;
	for (; pos < int(FV.size()); pos++) {
		if (FV[pos].ID == id) {
			has = 1;
			FV[pos].print_details();
			cout << endl << endl;
			break;
		}
	}
	if (!has) {
		cout << Unfound;
		cout << "\n>>��1�����²��ң����������������˵�\n";
		if (getch() == '1')
			goto Begin_CFD;
		else
			goto End_CFD;
	}
Begin2_CFD:
	cout << ">>��������Ҫ���ĵ���Ϣ��:\n";
	while (1) {
		fflush(stdin);
		cin >> Option;
		//�������ڴ��޸����˻�״̬(����Ƿ�״ֵ̬)
		if (Option == "״̬") {
			cout << "\n>>���棡\n  �Ƿ�����������\n    �˴�������������˻�״̬����س����У�Ȼ��ǰ�������˻���ڻ����ݡ�����״̬���ģ�"
			     << endl;
			MessageBox(NULL, TEXT("�Ƿ�������\n�˴�������������˻�״̬����ǰ�������˻���ڻ����ݡ����ģ�"), TEXT("����"),
			           MB_ICONEXCLAMATION | MB_OK);
			while (1) {
				fflush(stdin);
				char a = getch();
				if (a == '\n' || a == '\r')
					break;
			}
			goto Begin_CFD;
		}
		if (Option == "����" || Option == "���" || Option == "�ͺ�" || Option == "����" || Option == "��ע")
			break;
		cout << "\n>>����Ϣ����ڣ�����������:\n";
	}
	cout << "\n>>�������µ���Ϣ����(��������ո�):\n";

	fflush(stdin);
	cin >> Content;
	if (Option == "����") {
		FV[pos].Name = Content;
	} else if (Option == "���") {
		FV[pos].ID = Content;
	} else if (Option == "�ͺ�") {
		FV[pos].Version = Content;
	} else if (Option == "����") {
		FV[pos].Desc = Content;
	} else if (Option == "��ע") {
		FV[pos].Note = Content;
	}
	cout << "\n>>����ϸ��ʵȷ���޸���Ϣ���󣬰�1��ȡ�����ģ���������ȷ�ϸ���\n";
	int yes;
	fflush(stdin);
	if (getch() == '1') {
		cout << "\n>>ȡ�����ģ�\n";
		yes = 0;
	} else {
		cout << "\n���ĳɹ���\n";
		yes = 1;
	}
	Sleep(1000);
	system("cls");
	cout << Head_Str
	     << "���������˻���Ϣ��" << endl
	     << "\n>>��1��" << (yes ? "���������������˻�" : "���¸���") << "�����������������˵�\n";
	fflush(stdin);
	if (getch() == '1') {
		cout << "\n";
		FV[pos].print_details();
		goto Begin2_CFD;
	}
End_CFD:
	;
}

void ADFD() {
	//ADFD: Add_or_Delete_Fly_Datas��ɾ���˻���Ϣ
	system("cls");
	cout << Head_Str
	     << "�����˻���ڻ����ݡ�" << endl
	     << "0.�������˵�" << endl
	     << "1.���˻��ϸ�(����״̬)" << endl
	     << "2.���˻�����(����״̬)" << endl
	     << "3.���˻����(��������)" << endl
	     << "4.�ݻ����˻�(����ɾ��)" << endl
	     << "5.������˻��ֿ�(�ܱ�)" << endl;
	cout << Please_Str;
	int Model = GMr(48, 53);
	switch (Model) {
		case 0:
			break;
		case 1: {
Begin2_ADFD:
			system("cls");
			cout << Head_Str
			     << "�����˻��ϸڡ�" << endl;
			cout << "\n\n>>���������˻����:" << endl;
			string id;
			fflush(stdin);
			cin >> id;
			for (int pos = 0; pos < int(FV.size()); pos++) {
				if (FV[pos].ID == id) {
					cout << Found;
					FV[pos].print_details();
					if (FV[pos].Avail == "�ڸ�") {
						cout << "\n\n>>�����˻����ڸڣ������ظ��ϸڣ�" << endl;
						Sleep(500);
						goto Here1;
					}
					cout << "\n>>�س�����ȷ���ϸڣ���������ȡ���ϸ�" << endl;
					fflush(stdin);
					char a;
					a = getch();
					if (a == '\n' || a == '\r') {
						FV[pos].Avail = "�ڸ�";
						cout << "\n>>�ϸڳɹ���";
						Sleep(500);
Here1:
						;
						cout << "\n\n>>��1�������ϸ��������˻������������������˵�" << endl;
						fflush(stdin);
						if (getch() == '1') {
							goto Begin2_ADFD;
						} else
							goto End_ADFD2;
					}
				}
			}
			cout << Unfound;
			cout << "\n>>��1������������ң����������������˵�" << endl;
			fflush(stdin);
			if (getch() == '1')
				goto Begin3_ADFD;
End_ADFD2:
			;
			break;
		}
		case 2: {
Begin2_ADFD2:
			system("cls");
			cout << Head_Str
			     << "�����˻����ݡ�" << endl;
			cout << "\n\n>>���������˻����:" << endl;
			string id;
			fflush(stdin);
			cin >> id;
			for (int pos = 0; pos < int(FV.size()); pos++) {
				if (FV[pos].ID == id) {
					cout << Found;
					FV[pos].print_details();
					if (FV[pos].Avail == "������") {
						cout << "\n\n>>�����˻������ݣ������ظ����ݣ�" << endl;
						Sleep(500);
						goto Here13;
					}
					cout << "\n>>�س�����ȷ�����ݣ���������ȡ������" << endl;
					fflush(stdin);
					char a;
					a = getch();
					if (a == '\n' || a == '\r') {
						FV[pos].Avail = "������";
						cout << "\n>>���ݳɹ���";
						Sleep(500);
Here13:
						;
						cout << "\n\n>>��1�����������������˻������������������˵�" << endl;
						fflush(stdin);
						if (getch() == '1') {
							goto Begin2_ADFD2;
						} else
							goto End_ADFD22;
					} else {
						goto End_ADFD22;
					}
				}
			}
			cout << Unfound;
			cout << "\n>>��1������������ң����������������˵�" << endl;
			fflush(stdin);
			if (getch() == '1')
				goto Begin3_ADFD;
End_ADFD22:
			;
			break;
		}
		case 3: {
Begin3_ADFD:
			system("cls");
			cout << Head_Str
			     << "�����˻���ڡ�" << endl;
			cout << "\n�밴��ʾ���������˻������Ϣ(��������ո�)" << endl << endl;
			cout << "����:";
			fflush(stdin);
			cin >> Flyer.Name;
			cout << "���:";
			fflush(stdin);
			cin >> Flyer.ID;
			cout << "�ͺ�:";
			fflush(stdin);
			cin >> Flyer.Version;
			Flyer.Avail = "�ڸ�";
			cout << "����:";
			fflush(stdin);
			cin >> Flyer.Desc;
			cout << "��ע:";
			fflush(stdin);
			cin >> Flyer.Note;
			cout << endl;
			while (1) {
				for (int i = 0; i < int(FV.size()); i++) {
					if (FV[i].ID == Flyer.ID) {
						cout << "\n����ظ���������������:\n";
						fflush(stdin);
						cin >> Flyer.ID;
						goto While_Here;
					}
				}
				break;
While_Here:
				;
			}
			cout << ">>����ϸ��ʵȷ����Ϣ���󣬰�1��ȡ����ڣ���������ȷ�����" << endl;
			fflush(stdin);
			if (getch() == '1') {
				cout << ">>ȡ�����˻���ڣ�" << endl;
				Flyer.clean();
				cout << "\n\n>>��1��������ڣ����������������˵�" << endl;
				fflush(stdin);
				if (getch() == '1') {
					goto Begin3_ADFD;
				}
				goto End_ADFD3;
			}
			FV.push_back(Flyer);
			Flyer.clean();
			cout << endl
			     << "\n>>���˻���ڳɹ���" << endl;
			OE();
End_ADFD3:
			;
			break;
		}
		case 4: {
Begin4_ADFD:
			int has = 0;
			system("cls");
			cout << Head_Str
			     << "���ݻ����˻���" << endl;
			cout << "\n\n>>���������˻����:" << endl;
			string id;
			fflush(stdin);
			cin >> id;
			for (int pos = 0; pos < int(FV.size()); pos++) {
				if (FV[pos].ID == id) {
					has = 1;
					cout << Found;
					FV[pos].print_details();
					cout << "\n>>�س�����ȷ�ϴݻ٣���������ȡ���ݻ�" << endl;
					fflush(stdin);
					char a = getch();
					if (a == '\n' || a == '\r') {
						for (int i = pos; i < int(FV.size()) - 1; i++) {
							FV[i] = FV[i + 1];
						}
						FV.pop_back();
						cout << "\n>>�ݻٳɹ���";
						Sleep(500);
						cout << "\n\n>>��1�������ݻ��������˻������������������˵�" << endl;
						fflush(stdin);
						if (getch() == '1') {
							goto Begin4_ADFD;
						} else
							goto End_ADFD4;
					}
				}
			}
			if (!has)
				cout << Unfound;
			cout << "\n>>��1������������ң����������������˵�" << endl;
			fflush(stdin);
			if (getch() == '1')
				goto Begin4_ADFD;
End_ADFD4:
			;
			break;
		}
		case 5: {
			system("cls");
			cout << Head_Str
			     << "��������˻��ֿ⡿" << endl;
			cout << "\n\n>>��1��ȷ����գ����������������˵�" << endl;
			fflush(stdin);
			if (getch() == '1') {
				if (!int(Right.size())) {
					cout << "\n>>��ճɹ���" << endl;
					OE();
					FV.clear();
					break;
				}
				cout << "\n���������Ա����" << endl;
				string Key;
				cin >> Key;
				if (Lockor(Locker(Key))) {
					cout << "\n������ȷ����ճɹ���" << endl;
					OE();
					FV.clear();
				} else {
					cout << "\n>>������󣡣���" << endl;
					OE();
				}
			}
			break;
		}
		default:
			break;
	}
}

class FAer  {
	public:
		//�����ͳ�Ա����
		void Walk() {
			//ǰ��һ��

			//��¼��ǰλ����Ϣ���޸��켣
			int posxxx = pos_x;
			int posyyy = pos_y;
			int posdottt = pos_dot;
			switch (dir) {
				case 0:
					break;
				case 1: {
					if (pos_h >= int(_map[pos_y][pos_x + 1]) - 48) {
						pos_x++;
					} else if (pos_y == end_y && pos_x + 1 == end_x && pos_h >= end_h) {
						pos_x++;
					}
					break;
				}
				case 2: {
					if (pos_h >= int(_map[pos_y - 1][pos_x]) - 48)
						pos_y--;
					break;
				}
				case 3: {
					if (pos_h >= int(_map[pos_y][pos_x - 1]) - 48)
						pos_x--;
					break;
				}
				case 4: {
					if (pos_h >= int(_map[pos_y + 1][pos_x]) - 48)
						pos_y++;
				}
				default:
					break;
			}
			Fixed();//λ������
			_map[posyyy][posxxx] = char(posdottt + 48);
			pos_dot = int(_map[pos_y][pos_x]) - 48;
		}
		void TLeft() {
			dir++;
			Fixed();
		}
		void TRight() {
			dir--;
			Fixed();
		}
		void TBehind() {
			dir += 2;
			Fixed();
		}
		void WUp() {
			//���Ϸ���1��
			pos_h++;
			Fixed();
		}
		void WDown() {
			//���·���1��
			pos_h--;
			Fixed();
		}
		//�����ͳ�Ա����
		void Fixed() {
			//λ������(��ֹ����)+��������
			if (pos_x >= mapsize)
				pos_x = mapsize - 1;
			if (pos_x < 0)
				pos_x = 0;
			if (pos_y >= mapsize)
				pos_y = mapsize - 1;
			if (pos_y < 0)
				pos_y = 0;
			if (pos_h < pos_dot)
				pos_h = pos_dot;
			if (pos_h > 9)
				pos_h = 9; //�޸�9
			if (dir > 4)
				dir -= 4;
			if (dir < 1)
				dir += 4;
		}
		void Pre_map() {
			//��ʼ����ͼ�����˻����յ��
			for (int i = 0; i < mapsize; i++) {
				for (int j = 0; j < mapsize; j++) {
					srand(time(0) + i * j + i + j);
					_map[i][j] = char(abs(rand() % 10) + 48);
				}
			}
			srand(time(0) + 10086);
			pos_x = rand() % mapsize;
			srand(time(0) * 123 + 10086);
			pos_y = rand() % mapsize;
			pos_h = int(_map[pos_y][pos_x]) - 48;
			dir = 1;
			for (int i = 1;; i++) {
				//��������յ�
				srand(time(0) * 12 * i);
				end_x = rand() % mapsize;
				srand(time(0) * 23 * i + i);
				end_y = rand() % mapsize;
				if ((pos_x != end_x) && (pos_y != end_y))
					break;
			}
			end_h = int(_map[end_y][end_x]) - 48;
		}
		void Out_map() {
			//���²������ͼ
			char thiser;
			switch (dir) {
				case 1: {
					thiser = '>';
					break;
				}
				case 2: {
					thiser = 'A';
					break;
				}
				case 3: {
					thiser = '<';
					break;
				}
				case 4: {
					thiser = 'V';
					break;
				}
			}
			int _Show_Fontcolor = ((_Backcolor + _Fontcolor) + 10086) % 16; //��ֹײɫ
			if (_Backcolor == 15 && _Fontcolor == 9) {
				_Show_Fontcolor = 12;
			}
			for (int i = 0; i < mapsize; i++) {
				for (int j = 0; j < mapsize; j++) {
					if (i == pos_y && j == pos_x) {
						SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Show_Fontcolor); //��ɫ��ʾ
						cout << thiser << ' ';
						SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
					} else if (i == end_y && j == end_x) {
						//�ж�˳��֤���յ��־�ᱻ���˻���־���ǵ�
						SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Show_Fontcolor);
						cout << '+' << ' ';
						SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
					} else {
						cout << _map[i][j] << ' ';
					}
				}
				cout << endl;
			}
			cout << endl
			     << "��ǰ���и߶�:";
			SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Show_Fontcolor);
			cout << pos_h << endl;
			SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
			cout << "��ǰ���θ߶�:";
			SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Show_Fontcolor);
			cout << pos_dot << endl;
			SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
			cout << "�յ���θ߶�:";
			SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Show_Fontcolor);
			cout << end_h << endl;
			SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
		}
		FAer() {
			pos_x = 0;
			pos_y = 0;
			pos_h = 0;
			pos_dot = 0;
			dir = 1;
			mapsize = 10;
			end_x = 0;
			end_y = 0;
		}

		int pos_x;  //���˻���ǰλ��
		int pos_y;
		int pos_h;  //��ǰ���и߶�
		int pos_dot;//��ǰ���θ߶�
		int dir;    //���˻���ǰ����(1������2������3������4����)
		int mapsize;//���˻���ͼ��С
		int end_x;  //���˻��յ�
		int end_y;
		int end_h;
		char _map[30][30];
} FARR;

void FAG() {
	FARR.mapsize = 10;
Begin_moni:
	//FAG: Fly_Analog_Game���˻�ģ��С��Ϸ
Begin_FAG:
	system("cls");
	cout << Head_Str << endl
	     << "�����˻�ģ�⡤�˵���" << endl << endl
	     << "0.����ϵͳ���˵�" << endl
	     << "1.����ָ��" << endl
	     << "2.���õ�ͼ" << endl
	     << "3.��ʼ��Ϸ" << endl;
	int Model = GMr(48, 51);
	switch (Model) {
		case 0:
			goto END654;
		case 1: {
			system("cls");
			cout << Head_Str << endl
			     << "�����˻�ģ�⡤����ָ�ϡ�" << endl
			     << "\n>>����Ȩ������" << endl
			     << ">>����ϷMade By ���ķ� 1724834368@qq.com����Ƕ��UAV.MASϵͳ\n" << endl
			     << "��.���ڡ��˵������õ�ͼ����������Ϸ��ͼ��С����������Ĭ�ϴ�СΪ10*10" << endl
			     << "��.Ȼ�󡾲˵�����ʼ��Ϸ�����ɿ�ʼ��Ϸ����Ϸʱ�������¼��ֲ�������:" << endl
			     << "    W��:ǰ��һ��" << endl
			     << "    A��:��ת��" << endl
			     << "    D��:��ת��" << endl
			     << "    S��:��ת��" << endl
			     << "    P��:���Ϸ���һ��" << endl
			     << "    L��:���·���һ��" << endl
			     << "    E��:������Ϸ�����ز˵�" << endl
			     << "��.�ƶ����˻����յ�(���轵�䣬����ʹ���и߶ȵ��ڵ��θ߶�)����Ϸʤ�������������һ�����˻�������ϵͳ���˻��ֿ���(��������ʧЧ)"
			     << endl
			     << "��.��Ϸ��ͼ������Ϊ����(���ּ���Ӧ����θ߶�)���Լ�ͷ��ʾ���˻�(��ͷ�������˻�����)����+��Ϊ�յ㣬�����˻���ǰ���и߶Ȳ�С��ǰ��һ��ĵ��θ߶�ʱ�����˻�������ǰ����"
			     << endl
			     << "��.���������Ϸ��ͼ������ʾ�쳣���볢�Ը��ĵ�ͼ��С�����̨��С" << endl;
			MessageBox(NULL, TEXT("\
����Ȩ������\n\
����Ϸ���� Made By ���ķ� 1724834368@qq.com����Ƕ��UAV.MASϵͳ\n\n\
��.���ڡ��˵������õ�ͼ����������Ϸ��ͼ��С����������Ĭ�ϴ�СΪ10*10\n\
��.Ȼ�󡾲˵�����ʼ��Ϸ�����ɿ�ʼ��Ϸ����Ϸʱ�������¼��ֲ�������:\n\
 W��:ǰ��һ��\n\
 A��:��ת��\n\
 D��:��ת��\n\
 S��:��ת��\n\
 P��:���Ϸ���һ��\n\
 L��:���·���һ��\n\
 E��:������Ϸ�����ز˵�\n\
��.�ƶ����˻����յ�(���轵�䣬����ʹ���и߶ȵ��ڵ��θ߶�)����Ϸʤ�������������һ�����˻�������ϵͳ���˻��ֿ���(��������ʧЧ)\n\
��.��Ϸ��ͼ������Ϊ����(���ּ���Ӧ����θ߶�)���Լ�ͷ��ʾ���˻�(��ͷ�������˻�����)����+��Ϊ�յ㣬�����˻���ǰ���и߶Ȳ�С��ǰ��һ��ĵ��θ߶�ʱ�����˻�������ǰ����\n\
��.���������Ϸ��ͼ������ʾ�쳣���볢�Ը��ĵ�ͼ��С�����̨��С\
"), TEXT("��UAV.MAS ���˻�ģ�⡤����ָ�ϡ�"), MB_OK);

			cout << "\n>>�س����з�����Ϸ�˵�" << endl;
			while (1) {
				fflush(stdin);
				char a = getch();
				if (a == '\n' || a == '\r')
					goto Begin_FAG;
			}
			break;
		}
		case 2: {
			system("cls");
			cout << Head_Str << endl
			     << "�����˻�ģ�⡤���õ�ͼ��" << endl;
			cout << "�������ͼ��С(һ��10~30��������):" << endl;
			int sizer;
			while (1) {
				fflush(stdin);
				cin >> sizer;
				if (sizer >= 10 && sizer <= 30) {
					FARR.mapsize = sizer;
					cout << "\n>>���óɹ���" << endl;
					cout << "\n\n>>�س����з�����Ϸ�˵�" << endl;
					while (1) {
						fflush(stdin);
						char a = getch();
						if (a == '\n' || a == '\r')
							goto Begin_FAG;
					}
					break;
				}
				cout << "\n\n>>�������ֲ�����Ҫ������������:" << endl;
			}
			break;
		}
		case 3: {
			FARR.Pre_map();
			for (;;) {
				//ѭ��
				system("cls");
				cout << Head_Str << endl
				     << "�����˻�ģ�⡤��Ϸ�С�\n\n" << endl;
				FARR.Out_map();   //���²������ͼ
				if (FARR.pos_x == FARR.end_x && FARR.pos_y == FARR.end_y && FARR.end_h == FARR.pos_h) {
					cout << "\n\n>>��Ϸʤ�������һ�����˻���\n";
					//��������
					srand(time(0) + 10086);
					if (!(int(FV.size()))) {
						Flyer.Name = "�޵к�";
						for (int i = 11;; i++) {
here02:
							srand(time(0)*i + i);
							Flyer.ID = tostring(rand() % 1000001);
							for (int j = 0; j < int(FV.size()); j++) {
								if (Flyer.ID == FV[j].ID) {
									i++;
									goto here02;
								}
							}
							break;
						}
						Flyer.Version = "����ũҵ�������˻�";
						Flyer.Avail = "�ڸ�";
						Flyer.Note = "��";
						goto End666;
					}
					Flyer.Name = FV[rand() % (int(FV.size()))].Name;
					Flyer.Version = FV[rand() * 11 % (int(FV.size()))].Version;
					for (int i = 11;; i++) {
here01:
						srand(time(0)*i + i);
						Flyer.ID = to_string(rand() % 1000001);
						for (int j = 0; j < int(FV.size()); j++) {
							if (Flyer.ID == FV[j].ID) {
								i++;
								goto here01;
							}
						}
						break;
					}
					Flyer.Avail = "�ڸ�";
					Flyer.Note = "��";
					FV.push_back(Flyer);
End666:
					;
					break;
				}
				char move;
				while (1) {
					fflush(stdin);
					move = getch();
					if (islower(move)) {
						move = toupper(move);
					}
					if (move == 'W' || move == 'A' || move == 'D' || move == 'S' || move == 'P' || move == 'L' || move == 'E')
						break;
				}
				switch (move) {
					case 'W': {
						FARR.Walk();
						break;
					}
					case 'A': {
						FARR.TLeft();
						break;
					}
					case 'D': {
						FARR.TRight();
						break;
					}
					case 'S': {
						FARR.TBehind();
						break;
					}
					case 'P': {
						FARR.WUp();
						break;
					}
					case 'L': {
						FARR.WDown();
						break;
					}
					case 'E': {
						cout << "\n\n>>��;������Ϸ��" << endl;
						Sleep(1000);
						goto Begin_moni;
						break;
					}
					default:
						break;
				}
			}
			cout << "\n\n>>�س����з�����Ϸ�˵�" << endl;
			while (1) {
				fflush(stdin);
				char a = getch();
				if (a == '\n' || a == '\r')
					break;
			}
			break;
		}
		default:
			break;
	}
	goto Begin_FAG;
END654:
	;
}

void SLKM() {
	//SLKM: System_Lock_Key_Managementϵͳ�������
	system("cls");
	cout << Head_Str
	     << "��ϵͳ�������" << endl
	     << "0.�������˵�" << endl
	     << "1.����ϵͳ����" << endl
	     << "2.�ر�ϵͳ����" << endl
	     << "3.����ϵͳ����" << endl;
	cout << Please_Str;
	int Model = GMr(48, 51);
	switch (Model) {
		case 0:
			break;
		case 1: {
			system("cls");
			cout << Head_Str
			     << "������ϵͳ���" << endl;

			if (!int(Right.size())) {
				cout << "\n>>ϵͳ����δ���ã��޷�����ϵͳ���" << endl;
				OE();
				break;
			}

			cout << "\n>>������ԭ����:" << endl;
			string key;
			fflush(stdin);
			cin >> key;
			if (Lockor(Locker(key))) {
				cout << "\n������ȷ��" << endl
				     << "\n������������(��������ո�):" << endl;
				string _New;
				fflush(stdin);
				cin >> _New;
				cout << "\n>>�س�����ȷ�ϸ��ģ���������ȡ������" << endl;
				fflush(stdin);
				char a = getch();
				if (a == '\n' || a == '\r') {
					Right = Locker(_New);
					cout << "\n>>���ĳɹ���" << endl;
					OE();
					break;
				}
				cout << "\n>>ȡ�����ģ�" << endl;
				OE();
				break;
			} else {
				cout << "\n>>�������" << endl;
				OE();
				break;
			}
			break;
		}
		case 2: {
			system("cls");
			cout << Head_Str
			     << "���ر�ϵͳ���" << endl;

			if (!int(Right.size())) {
				cout << "\n>>ϵͳ�����Ѿ��رգ������ظ��رգ�" << endl;
				OE();
				break;
			}

			cout << "\n>>������ԭ����:" << endl;
			string Key;
			fflush(stdin);
			cin >> Key;
			if (Lockor(Locker(Key))) {
				cout << "\n>>������ȷ��" << endl
				     << "\n>>�ѹر�ϵͳ���" << endl;
				Right = "";
				Sleep(500);
				OE();
				break;
			} else {
				cout << "\n>>�������" << endl;
				Sleep(500);
				OE();
				break;
			}
			break;
		}
		case 3: {
			system("cls");
			cout << Head_Str
			     << "������ϵͳ���" << endl;

			if (int(Right.size())) {
				cout << "\n>>ϵͳ�����Ѿ����ã������ظ����ã�" << endl;
				OE();
				break;
			}

			cout << "\n>>��������������:" << endl;
			string Key;
			fflush(stdin);
			cin >> Key;
			cout << "\n>>�س�����ȷ�����ã���������ȡ������" << endl;
			fflush(stdin);
			char a = getch();
			if (a == '\n' || a == '\r') {
				cout << "\n>>���óɹ���" << endl;
				Right = Locker(Key);
				Sleep(500);
				OE();
				break;
			}
			cout << "\n>>ȡ�����ã�" << endl;
			Sleep(500);
			OE();
			break;
		}
	}
}

void MF() {
	//More_Function ���๦��
	system("cls");
	cout << Head_Str
	     << "�����๦�ܡ�" << endl
	     << "0.�������˵�" << endl
	     << "1.���ô�����ɫ" << endl
	     << "2.���ڿ����ߡ���ȡ��Դ���ʵ�" << endl;
	cout << Please_Str;
	int Model = GMr(48, 50);
	switch (Model) {
		case 0: {
			break;
		}
		case 1: {
			system("cls");
			cout << Head_Str
			     << "�����๦�ܡ����ô�����ɫ��" << endl
			     << "0.�������˵�" << endl
			     << "1.Ĭ����ɫ" << endl
			     << "2.�Զ���" << endl;
			cout << Please_Str;
			int Model = GMr(48, 50);
			switch (Model) {
				case 0: {
					break;
				}
				case 1: {
					_Backcolor = 15;
					_Fontcolor = 9;
					SetConsoleTextAttribute(Winptr, 15 * 16 + 9);
					break;
				}
				case 2: {
					system("cls");
					cout << Head_Str
					     << "�����๦�ܡ����õ�ǰ������ɫ���Զ��塤����ɫ��" << endl << endl;
					cout << "0.��ɫ    8.��ɫ" << endl
					     << "1.��ɫ    9.����ɫ" << endl
					     << "2.��ɫ    A.����ɫ" << endl
					     << "3.ǳ��ɫ  B.��ǳ��ɫ" << endl
					     << "4.��ɫ    C.����ɫ" << endl
					     << "5.��ɫ    D.����ɫ" << endl
					     << "6.��ɫ    E.����ɫ" << endl
					     << "7.��ɫ    F.����ɫ" << endl
					     << endl;
					cout << ">>��ѡ�񱳾�ɫ:" << endl;
					while (1) {
						char ch = getch();
						if (islower(ch)) {
							ch = toupper(ch);
						}
						if ((ch >= 48 && ch <= 57)) {
							_Backcolor = (ch - 48);
							SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
							break;
						} else if (ch >= 65 && ch <= 70) {
							_Backcolor = (ch - 55);
							SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
							break;
						}
					}

					system("cls");
					cout << Head_Str
					     << "�����๦�ܡ����õ�ǰ������ɫ���Զ��塤����ɫ��" << endl << endl;
					cout << "0.��ɫ    8.��ɫ" << endl
					     << "1.��ɫ    9.����ɫ" << endl
					     << "2.��ɫ    A.����ɫ" << endl
					     << "3.ǳ��ɫ  B.��ǳ��ɫ" << endl
					     << "4.��ɫ    C.����ɫ" << endl
					     << "5.��ɫ    D.����ɫ" << endl
					     << "6.��ɫ    E.����ɫ" << endl
					     << "7.��ɫ    F.����ɫ" << endl
					     << endl;
					cout << ">>��ѡ������ɫ(���ڱ���ɫ):" << endl;
					while (1) {
						char ch = getch();
						if (islower(ch)) {
							ch = toupper(ch);
						}
						if ((ch >= 48 && ch <= 57) && (ch - 48 != _Backcolor)) {
							_Fontcolor = (ch - 48);
							SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
							break;
						} else if ((ch >= 65 && ch <= 70) && (ch - 55 != _Backcolor)) {
							_Fontcolor = (ch - 55);
							SetConsoleTextAttribute(Winptr, _Backcolor * 16 + _Fontcolor);
							break;
						}
					}
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case 2: {
			system("cls");
			cout << Head_Str
			     << "�����ڿ����ߡ���ȡ��Դ���ʵ���" << endl;
			system("start https://JularDepick.github.io/Yuameng/Expand/Page/About_Designer_Page_for_UAV_MAS/");
			Sleep(500);
			cout << endl << "���Է���:";
			string src = "https://JularDepick.github.io/Yuameng/Expand/Page/About_Designer_Page_for_UAV_MAS/";
			for (int i = 0; i < int(src.size()); i++) {
				cout << src[i];
				Sleep(10);
			}
			cout << endl;
			OE();
			break;
		}
		default: {
			break;
		}
	}
}

bool Lockor(string value) {
	return (value == Right);
}

string Locker(string value) {
	const static char Base64[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz&%"; //�����ֵ�(����Base64)
	string encode;
	vector<int> k;

	//�ֽ�չ����ֵ,���������������Ӧ�����ֵ�
	for (int i = 0; i < int(value.size()); i++) {
		byte bt = value[i];  //byte���Ͱ�����Windowsͷ�ļ���(Ϊ�˴�������)
		int a = abs(int(bt));
		int s[8] = {};
		for (int i = a, pos = 7; i > 0; i /= 2, pos--) {
			//չ��Ϊ��������
			s[pos] = i % 2;
		}
		for (int i = 0; i < 8; i++) {
			k.push_back(s[i]);
		}
	}

	for (int i = 0; i < int(k.size()); i++) {
		//��λȡ��
		k[i] = (!k[i]);
	}

	for (int i = 0, posb = 0; i < int(k.size()) / 6; i++) {
		//����λƥ�����
		int l[6] = {};
		for (int posa = 0; posa < 6; posa++, posb++) {
			l[posa] = k[posb];
		}
		int ans = l[0] * 32 + l[1] * 16 + l[2] * 8 + l[3] * 4 + l[4] * 2 + l[5];
		encode.push_back(Base64[ans]);
	}
	if (int(k.size()) / 6 * 6 != int(k.size())) {
		//������ܵ�ʣ��λ
		int ls[6] = {};
		for (int i = int(k.size()) - 1, j = 5; i >= int(k.size()) / 6 * 6; j--, i--) {
			ls[j] = k[i];
		}
		int ans = ls[0] * 32 + ls[1] * 16 + ls[2] * 8 + ls[3] * 4 + ls[4] * 2 + ls[5];
		encode.push_back(Base64[ans]);
	}

	//����ʽ����
	string sa, sb;
	if (encode.size() % 2) {
		for (int i = 0; i < int(encode.size()); i++) {
			if (i <= int(encode.size()) / 2) {
				sa.push_back(encode[i]);
			} else {
				sb.push_back(encode[i]);
			}
		}
	} else {
		for (int i = 0; i < int(encode.size()); i++) {
			if (i < int(encode.size()) / 2) {
				sa.push_back(encode[i]);
			} else {
				sb.push_back(encode[i]);
			}
		}
	}
	encode.clear();
	for (int i = 0; i < int(sb.size()); i++) {
		encode.push_back(sa[i]);
		encode.push_back(sb[i]);
	}
	if (sa.size() > sb.size()) {
		encode.push_back(*(sa.end() - 1));
	}

	return encode;
}

string tostring(int a) {
	string s;
	for (; a > 0; a /= 10) {
		s.push_back(char(a % 10 + 48));
	}
	reverse(s.begin(), s.end());

	return s;
}

int GMr(int a, int b) {
	//GMr: Get_Modeler��ȡģʽ
	char Model;
	while (1) {
		fflush(stdin);
		Model = getch();
		if (Model >= a && Model <= b)
			break;
	}
	return int(Model - 48);
}

void OE() {
	//OE: Over_Endִ�н���
	cout << "\n\n>>�س����з������˵�\n";
	while (1) {
		fflush(stdin);
		char a = getch();
		if (a == '\n' || a == '\r')
			break;
	}
}
