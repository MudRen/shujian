//Cracked by Kafei
//default data set

static int OPPOSE_DROP_EXP=200;//200;



static int MASTER_CALL_IN_EXP=300;
static int FINISH_JOB_EXP=100;//100;

static int MASTER_CALL_IN_CON=10;
static int OPPOSE_DROP_CON=5;
static int FINISH_JOB_CON=2;

//When assess meeting start, will dealy ASSESS_DELAY time do it.
static int ASSESS_DELAY=300;
int ASSESS_NUM=10000;
//���������Ļ���
//
int assess_wd=ASSESS_NUM*7/10;
int assess_xx=ASSESS_NUM*5/10;
int assess_hs=ASSESS_NUM*8/10;
int assess_th=ASSESS_NUM*7/10;
int assess_gb=ASSESS_NUM*8/10;
int assess_em=ASSESS_NUM*5/10;
int assess_bt=ASSESS_NUM*6/10;
int assess_qz=ASSESS_NUM*8/10;
int assess_xs=ASSESS_NUM*5/10;
int assess_dl=ASSESS_NUM*5/10;
int assess_sl=ASSESS_NUM*5/10;


//���ָ�����ȱʡ�������

//int add_orgdata(string family_name,mapping strategy,int luck,int money,mapping power)
/************************************************************************************/
//�����ɲ������Ϊ100,��ʾ%100����СΪ0,��ʾ%0.
//oppose_pker:��pk,ά���������壬����ɱpker����
//support_pker:֧��PK���ԣ�����Pk����

//protect:�������ԣ����������������ʵ�����
//plunder:������ԣ����������������ʵ�����

//destroy���ƻ����ԣ����������ƻ����ʵ�����
//develop:��չ���ԣ�����������չ���ʵ�����

//business:��ҵ��չ����
//generally��һ�����
//������Եĺ����Ϊ100,���ֲ��Ե���ֵ��ʾ��Եı��ʡ�

//�䵱��
mapping strategy_wd=([
				   //�����Բ���
				   "oppose_pker"		:30,
				   "support_pker"		:0,
				   
				   "protect"			:30,
				   "plunder"			:0,
				   
//     		       "develop"			:20,
//				   "destroy"			:-50,
			  
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:40,

]);
//������
mapping strategy_xx=([
				   //�����Բ���
				   "oppose_pker"		:0,
				   "support_pker"		:30,
				   
				   "protect"			:0,
				   "plunder"			:30,
				   
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:40,

]);
//��ɽ��
mapping strategy_hs=([
				   //�����Բ���
				   "oppose_pker"		:40,
				   "support_pker"		:0,
				   
				   "protect"			:20,
				   "plunder"			:0,
				   
			  
				   //��ͳ�Բ���
				   "business"			:10,
				   "generally"			:30,

]);
//�һ���
mapping strategy_th=([
				   //�����Բ���
				   "oppose_pker"		:15,
				   "support_pker"		:15,
				   
				   "protect"			:15,
				   "plunder"			:15,
				   
			  
				   //��ͳ�Բ���
				   "business"			:15,
				   "generally"			:25,

]);
//ؤ��
mapping strategy_gb=([
				   //�����Բ���
				   "oppose_pker"		:20,
				   "support_pker"		:20,
				   
				   "protect"			:20,
				   "plunder"			:20,
				   
			  
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:20,

]);
//������
mapping strategy_em=([
				   //�����Բ���
				   "oppose_pker"		:50,
				   "support_pker"		:0,
				   
				   "protect"			:10,
				   "plunder"			:0,
				   
			  
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:40,

]);
//����ɽ
mapping strategy_bt=([
				   //�����Բ���
				   "oppose_pker"		:0,
				   "support_pker"		:30,
				   
				   "protect"			:0,
				   "plunder"			:30,
				   
			  
				   //��ͳ�Բ���
				   "business"			:20,
				   "generally"			:20,

]);
//ȫ���
mapping strategy_qz=([
				   //�����Բ���
				   "oppose_pker"		:30,
				   "support_pker"		:0,
				   
				   "protect"			:50,
				   "plunder"			:0,
				   
			  
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:20,

]);
//ѩɽ��
mapping strategy_xs=([
				   //�����Բ���
				   "oppose_pker"		:0,
				   "support_pker"		:20,
				   
				   "protect"			:15,
				   "plunder"			:15,
				   
			  
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:50,

]);
//����
mapping strategy_dl=([
				   //�����Բ���
				   "oppose_pker"		:10,
				   "support_pker"		:0,
				   
				   "protect"			:15,
				   "plunder"			:0,
				   
			  
				   //��ͳ�Բ���
				   "business"			:40,
				   "generally"			:35,

]);
//������
mapping strategy_sl=([
				   //�����Բ���
				   "oppose_pker"		:0,
				   "support_pker"		:0,
				   
				   "protect"			:70,
				   "plunder"			:0,
				   
			  
				   //��ͳ�Բ���
				   "business"			:0,
				   "generally"			:30,

]);








/***********************************************************************************/
//�������ɵ������������
int luck_wd=1+random(3);
int luck_xx=2+random(3);
int luck_hs=1+random(1);
int luck_th=3+random(3);
int luck_gb=2+random(3);
int luck_em=1+random(3);
int luck_bt=1+random(3);
int luck_qz=1+random(3);
int luck_xs=2+random(3);
int luck_dl=1+random(1);
int luck_sl=1+random(2);
/***********************************************************************************/
//�������ɲ�������ı��ʳ�ʼ�趨
int luck_wdrate=30;
int luck_xxrate=20;
int luck_hsrate=30;
int luck_gbrate=40;
int luck_thrate=15;
int luck_qzrate=35;
int luck_dlrate=10;
int luck_slrate=40;
int luck_btrate=20;
int luck_emrate=10;
int luck_xsrate=5;

//���ɾ���
//��ȫ��������money���ó�100��ÿ�����ɰ��ձ���ӵ�С�
int money_wd=5;
int money_xx=15;
int money_hs=10;
int money_th=15;
int money_gb=5;
int money_em=5;
int money_bt=10;
int money_qz=5;
int money_xs=15;
int money_dl=10;
int money_sl=5;
/***********************************************************************************/
//��������
//��ȫ�����������������򻮷֣����100��ÿ�����ɰ��ձ���ӵ�С�
/*����ԭ
������Ҫ���У�������
������������ɽ����ɽ�������������ϡ����������ϡ�
�������еط�����ɽ���֡������䵱ɽ������ɽ��ɽ��̩ɽ���ƺӱߡ���ͥ����

������
������Ҫ���У����ݡ�
�����������򣺰��ա����ա��㽭��������������
�������еط������ݡ�̫��������Ȫ�ݡ����ˡ����ջ�ɽ��

���Ͻ�
������Ҫ���У�����
�������������Ĵ������ݡ����ϡ��㶫��������
�������еط����Ĵ����ҡ������置��

������
������Ҫ���У����ݡ�
���������������ġ����ࡢ�ຣ���½������ء�
�������еط�����ɽ������ɽ������ɽ���رߴ�ѩɽ������
  ����
������Ҫ���У�������
�����������򣺺ӱ������������֡������������ɹš�
�������еط�������ɽ���ɶ���������
*/
//wudang
mapping power_wd=([
				   //�����Բ���
				   "��ԭ"		:20,
				   "����"		:10,
				   "�Ͻ�"		:5,
				   "����"		:0,
				   "����"		:5,
				   

]);
//xingxiu
mapping power_xx=([
				   //�����Բ���
				   "��ԭ"		:0,
				   "����"		:5,
				   "�Ͻ�"		:0,
				   "����"		:30,
				   "����"		:5,
				   

]);
//huashan
mapping power_hs=([
				   //�����Բ���
				   "��ԭ"		:10,
				   "����"		:10,
				   "�Ͻ�"		:5,
				   "����"		:0,
				   "����"		:5,
				   

]);

//taohuadao
mapping power_th=([
				   //�����Բ���
				   "��ԭ"		:5,
				   "����"		:10,
				   "�Ͻ�"		:0,
				   "����"		:0,
				   "����"		:5,
				   

]);

//gaibang
mapping power_gb=([
				   //�����Բ���
				   "��ԭ"		:20,
				   "����"		:20,
				   "�Ͻ�"		:20,
				   "����"		:10,
				   "����"		:20,
]);

//emei
mapping power_em=([
				   //�����Բ���
				   "��ԭ"		:10,
				   "����"		:10,
				   "�Ͻ�"		:0,
				   "����"		:0,
				   "����"		:5,
]);
//baituo
mapping power_bt=([
				   //�����Բ���
				   "��ԭ"		:5,
				   "����"		:5,
				   "�Ͻ�"		:5,
				   "����"		:30,
				   "����"		:5,
]);
//quanzhen
mapping power_qz=([
				   //�����Բ���
				   "��ԭ"		:5,
				   "����"		:10,
				   "�Ͻ�"		:5,
				   "����"		:0,
				   "����"		:5,
]);

//xueshan
mapping power_xs=([
				   //�����Բ���
				   "��ԭ"		:0,
				   "����"		:5,
				   "�Ͻ�"		:5,
				   "����"		:30,
				   "����"		:5,
]);

//dali
mapping power_dl=([
				   //�����Բ���
				   "��ԭ"		:5,
				   "����"		:5,
				   "�Ͻ�"		:50,
				   "����"		:0,
				   "����"		:5,
]);
//shaolin
mapping power_sl=([
				   //�����Բ���
				   "��ԭ"		:20,
				   "����"		:10,
				   "�Ͻ�"		:5,
				   "����"		:0,
				   "����"		:5,
]);







