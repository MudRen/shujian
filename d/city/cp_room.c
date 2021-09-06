// Room: /d/city/cp_room.c
// Date: Lsxk 2007/9/25

#include <ansi.h>
inherit ROOM;
#define UPDATE_TIME 10800 //����ÿ3Сʱ����һ��.
#define DUIJIANG_TIME 3600 //����Խ�ʱ�䡣 by lsxk@hsbbs 2007/9/26
#define SIZE_OF_SOURCE 20 //����ѡ��س���
#define CREDIT_COST 5 //������ͨ������ļ۸� by lsxk@hsbbs 2007/9/26
#define GOLD_COST 100000 //�����ûƽ���ļ۸� by lsxk@hsbbs 2007/9/26

string *duijiang_char;
string strPriKaijiang;

string cp_kaijiang(int);
#include "buy_caipiao.h";
#include "duijiang_caipiao.h";

void create()
{
       set("short", HIY"��������"NOR);
       set("long", @LONG
����������ݳ��ﵽ����˵���������ģ�������е���һҹ
�����е���ȴ��ҵ�������Ϊ��ͷ��ؤ����֮�����˵��˳�����Ϊ
�˼����ã�������Щ��ȴ˵�������˼������
��������һ������(sign)�������ƺ�д��һЩ����
LONG);

    set("exits", ([
               "east"  :  __DIR__"dating1",
    ]));

    set("item_desc", ([
            "sign": @TEXT

����˵�������

����
1��ϵͳÿ�ν���26��Сд��ĸ��26����д��ĸ��0~9ʮ�������Լ���~!@#$%^&*��֮����
��ѡ��20���ַ���Ϊ���ʺ�ѡ�����Ի��Թ�����ʽ���͸�ÿ����ҡ�
2���������Ҫ����20���ַ������Լ���ϲ�����򣬲����仮��Ϊ2���ַ�һ�ԣ��ܹ�10��
�ַ���ϡ�
3��ϵͳ֮���������20���ַ������Զ���ϣ�Ҳ����2���ַ�һ�ԡ�
4�����ʵ������ѡ���10���ַ��У�����һ�Ժ�ϵͳ������е�һ����һ�£����ۼ���
�����֡������������ظ��н���ϣ������ۻ����֣����磺
ϵͳ�н����ΪAa-12-34-56-78-90-re-yt-iu-po 
ĳ���˹�����:po-po-po-as-fd-er-ge-hr-jh-vb
��po����ϻ���н����֣�����ֻ���1�֡���2�͵�3����po��������н����֡�
�����н����ַ�����ϵͳ�������ַ������ڵ�λ��һ�£��򱾴λ�û��ַ�����
5��ϵͳ����һ���㷨���㱾�ε��ۻ�����ת�����㹺��ʱ�Ļ��ҡ��㷨���£�
�н���� = ������ * �ۻ�����
(ע���ۻ����� = ��ϵͳ��һ�µ��ַ��ĸ����ļ�ȫֵ�����磺�������ܹ���4���ַ�����
��ϵͳ������������һ�£����ۻ�����Ϊ1+2+3+4 =10)
6���������Ϊ�ƽ�

���򷽷���
1��ʹ��buyָ��������¸�ʽ��
buy ����Ҫ�����к� with �ƽ�
���У����к����������20���ַ���ɣ�����ÿ2���ַ���Ҫ��"-"�������ӡ����磺
buy 12-34-56-78-90-09-87-65-43-21 with �ƽ�
2��ϵͳ�����������������Ƿ�ӹ涨��20���ַ���ѡ��ģ�ֻ���ж���������ַ���
���Ƿ�����Ҫ�󡣼�����������29���ַ���ϵͳ����Ϊ��������ȷ��
3��ϵͳ�������н��ַ�100%����һ��ʼ�����е�20���ַ�������ģ��Ҳ����ظ���
4��ÿ�ι���ϵͳ�Զ������������۳�100���ƽ���Ϊ������ã�����ʹ�������ϵĻƽ�
5��ÿ��ÿ�ڹ�������������ơ�����Թ�����������ϡ�
6�������ϵͳ�����һ�š���Ʊ��������Ʊ����������������ʱ�����ɴ���������ϡ�
7����������Ʊ�������������ζԽ����ᣬҲ���˷����㹺���Ǯ��
8��ϵͳÿ3Сʱ����һ�α�ѡ���룬������ѡ������2Сʱ�ڣ����������ɹ����Ʊ��
������ѡ��ź�ĵ�3��Сʱ׼ʱ�������������н���ţ������ȥ�������ĶԽ���
9��ϵͳÿ����һ���µı�ѡ�����ͬʱ��������ǰһ�ε����ʹ��ڣ��޷��ٽ��жԽ���
10���Խ�ָ�duijiang   ÿʹ��һ�Σ��Խ�һ�鹺������кš�

��ѯ������
����������ʹ��chakanָ�������ʾ��ǰ��ѡ���룬����Ѿ����ڶԽ��׶Σ��򻹻���
ʾ�н�������š�

TEXT
    ]) );
       set("indoors", "��������" );
       set("no_fight",1);
       set("no_sleep",1);

   setup();

    remove_call_out("update_source");
    remove_call_out("update_kaijiang");
    call_out("update_source",UPDATE_TIME);
    call_out("update_kaijiang",(UPDATE_TIME-DUIJIANG_TIME));
}

void init()
{
    add_action("do_chakan", "chakan");
    add_action("buy_caipiao","buy");
    add_action("do_duijiang","duijiang");
/*
    if(wizardp(this_player()) && this_player()->query("id")=="lsxk")
        add_action("do_zuobi","zuobi");
*/

}

void do_zuobi(string arg)
{
    //object me = this_player();

    set("zuobi",arg);
    duijiang_char = explode(arg, "-");

    return;
}

void update_source()
{
    This_Source = Random_Source(SIZE_OF_SOURCE);
    remove_call_out("update_source");
    call_out("update_source",UPDATE_TIME);
}

void update_kaijiang()
{
    string kj_result;

    set("no_buy",1);//�Խ�ʱ�䣬�޷������Ʊ. by lsxk@hsbbs 2007/9/26

    if(!query("zuobi")){
        delete("zuobi");
        kj_result = cp_kaijiang(0);
    }
    else kj_result = query("zuobi");
    message("system",HIY"\n\n���齣���ʡ���"+HIW+"�����齣�������Ϊ��"+HIR+kj_result+HIW+" �����н�����һСʱ֮��ǰȥ�������ĶԽ������ڲ���\n\n"NOR, users());

    //ɾ�����ݼ�¼��by lsxk@hsbbs 2007/9/28
    rm("/log/cpTag.c");

    remove_call_out("update_kaijiang");
    call_out("update_kaijiang",UPDATE_TIME);
}

int do_chakan(object me)
{
 //   string strResult;
    string strPriKaijiang;
    me = this_player();

    tell_object(me,HIY"���εĿ���ѡ�����Ϊ��\n"+HIR+This_Source+"\n"NOR);

    if(query("no_buy")){
        tell_object(me,HIC"���ε������н����к���Ϊ��\n"+HIW+strPriKaijiang+"\n"NOR);
    }
    return 1;
}

private string cp_kaijiang(int tag)
{
    string *strTemp, *strTemp2, strLast, strResult, p;
    int i, j, k;

    //���ַ����ֽ�ɵ����ַ��洢��strTemp2�����С� by lsxk@hsbbs 2007/9/25
    strLast = This_Source;
    for(i=0;i<SIZE_OF_SOURCE;i++){
        sscanf(strLast, "%s %s",p,strLast);
        if(!strTemp2) strTemp2 = ({p});
        else if((i+1)<SIZE_OF_SOURCE) strTemp2 += ({p});
        else strTemp2 += ({strLast});
    }

    //���ַ���������д洢��strTemp�����С� by lsxk@hsbbs 2007/9/25
    for(i=0;i<SIZE_OF_SOURCE;i++){
        p = strTemp2[random(sizeof(strTemp2))];
        if(!strTemp) strTemp = ({p});
        else strTemp += ({p});
        strTemp2 -= ({p});
    }

    if(tag==0)
    duijiang_char = strTemp;

    //��strTemp�е����鰴��XX-XX-XX-XX�ĸ�ʽ�����by lsxk@hsbbs 2007/9/25
    j = sizeof(strTemp);
    for(k=0;k<j;k++){
        if(!strResult)
            strResult = strTemp[k];
        else if((k)%2==0)
            strResult = strResult+"-"+strTemp[k];
        else
            strResult = strResult+strTemp[k];
    }
    if(tag==0)
    strPriKaijiang = strResult;

    return strResult;
}
