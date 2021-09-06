//Mine Job Place.h
//Created By ChinaNet
//By 2004/1/11
//Modified 2004/2/1 By ChinaNet
//Modified 2004/3/10 by ChinaNet
//Modified 2004/4/27 By ChinaNet fixed address bug

#include <ansi.h>
#include <regions.h>

string *wheres_easy=({
"/d/emei/guanyinqiao", "/d/emei/basipan3","/d/emei/caopeng",
"/d/wudang/xiaolu2",    
"/d/songshan/suishilu3","/d/songshan/suishilu4","/d/songshan/suishilu1","/d/songshan/suishilu2",
"/d/songshan/shidao1","/d/songshan/shidao2","/d/songshan/shidao3",
"/d/songshan/shanlu5","/d/songshan/shanlu4","/d/songshan/shanlu3","/d/songshan/shanlu2","/d/songshan/shanlu1",
"/d/xiangyang/outeroad1","/d/xiangyang/zhuquemen", "/d/xiangyang/hanshui1",
"/d/chengdu/sroad1","/d/chengdu/tulu1","/d/chengdu/tulu2","/d/chengdu/tulu3","/d/chengdu/wroad1","/d/chengdu/wroad2","/d/chengdu/eroad1","/d/chengdu/eroad2",
"/d/hengshan/shandao1","/d/hengshan/shandao2","/d/hengshan/jijiaoshi","/d/hengshan/kutianjing",
"/d/city/eroad1","/d/city/eroad2",
"/d/tiezhang/hclu", "/d/tiezhang/shanmen",  
});
string *wheres_normal=({
"/d/jiaxing/nanhu","/d/jiaxing/tieqiang","/d/hz/longjing","/d/hz/huanglongdong","/d/hz/tianxianglou","/d/hz/longjing",
"/d/emei/basipan3","/d/emei/basipan2","/d/emei/basipan1",
"/d/emei/shierpan","/d/emei/shierpan2","/d/emei/shierpan3","/d/emei/shierpan4",
"/d/tiezhang/hclu-2","/d/tiezhang/hclu-3","/d/tiezhang/hclu-4","/d/tiezhang/hclu-5","/d/tiezhang/hclu-6",
"/d/xueshan/xuelu2","/d/xueshan/houzidong", "/d/xueshan/shanlu7",
"/d/huanghe/shulin1","/d/huanghe/shulin2","/d/huanghe/shulin3","/d/huanghe/shulin4","/d/huanghe/shulin5","/d/huanghe/shulin6",
});
string *wheres_hard=({
"/d/shaolin/stoneroad1","/d/shaolin/sblu-2","/d/shaolin/sblu-3","/d/mr/xiaojing1-2","/d/shaolin/stoneroad2",
"/d/shaolin/stoneroad4","/d/shaolin/sblu-1",
"/d/shaolin/stoneroad3",
"/d/shaolin/shijie1","/d/shaolin/shijie2","/d/shaolin/shijie3","/d/shaolin/shijie4","/d/shaolin/shijie5",
"/d/shaolin/shijie6","/d/shaolin/shijie7","/d/shaolin/shijie8","/d/shaolin/shijie9","/d/shaolin/shijie10",
"/d/city/wroad2","/d/city/wroad3","/d/city/wroad1",
"/d/dali/dalisouth/shanlu6","/d/dali/dalieast/shanlu7","/d/dali/wuliang/shanlu5",
"/d/dali/wuliang/shanlu8","/d/dali/wuliang/shanlu10",
"/d/dali/wuliang/shanlu11","/d/dali/wuliang/shanlu12","/d/dali/wuliang/shanlu13",
"/d/tiezhang/shanlu-2","/d/tiezhang/shanlu-3","/d/tiezhang/shanlu-4","/d/tiezhang/shanlu-5","/d/tiezhang/shanlu-6",
"/d/tiezhang/shanlu-7","/d/tiezhang/shanlu-8","/d/tiezhang/shanlu-9",
});
string *wheres_veryhard=({
"/d/huanghe/shamo",
"/d/xingxiu/shamo3",
"/d/emei/gudelin3",     
"/d/emei/lengshanlin2",
"/d/mr/xiaojing1-1","/d/mr/xiaojing1-2","/d/mr/xiaojing1-3","/d/mr/xiaojing1-4",
"/d/mr/xiaojing2","/d/mr/xiaojing3","/d/mr/xiaojing4","/d/mr/xiaojing5","/d/mr/xiaojing6","/d/mr/xiaojing7",
"/d/mingjiao/ljroad1","/d/mingjiao/ljroad2","/d/mingjiao/ljroad3",
"/d/mingjiao/didao/senlin-1","/d/mingjiao/didao/senlin-2","/d/mingjiao/didao/senlin-3","/d/mingjiao/didao/senlin-4",
"/d/mingjiao/didao/senlin-5","/d/mingjiao/didao/senlin-6","/d/mingjiao/didao/senlin-7","/d/mingjiao/didao/senlin-8",
"/d/xingxiu/xxh2",
"/d/fuzhou/road1","/d/fuzhou/road2","/d/fuzhou/road3","/d/fuzhou/road4","/d/fuzhou/road5",
"/d/hz/changlang2","/d/hz/changlang1",
"/d/foshan/road14",
});

//����ͭ��п����������Ǧ��þ���ף��̣���
string *NORMAL_B_NAME = ({
HIW"����ʯ"NOR,HIW"ͭ��ʯ"NOR,HIW"п��ʯ"NOR,HIW"����ʯ"NOR,HIW"����ʯ"NOR,HIW"þ��ʯ"NOR,HIW"Ǧ��ʯ"NOR,
HIW"�׿�ʯ"NOR,HIW"�̿�ʯ"NOR,HIW"����ʯ"NOR,HIW"�ٿ�ʯ"NOR,HIW"���ʯ"NOR,HIW"���ʯ"NOR,HIW"���ʯ"NOR,
});

string *NORMAL_B_LONG = ({
HIW"һ���ɫ������ʯ����������Щ���ô���\n"NOR,HIR"һ���ɫ��ͭ��ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ��п��ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ������ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ������ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ��þ��ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ��Ǧ��ʯ����������Щ���ô���\n"NOR,
HIW"һ���ɫ���׿�ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ���̿�ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ������ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ���ٿ�ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ�����ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ�����ʯ����������Щ���ô���\n"NOR,	HIW"һ���ɫ�����ʯ����������Щ���ô���\n"NOR,	
});

string *NORMAL_B_MATERIAL = ({
"��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ",
"��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ","��ͨʯͷ",
});

string* HARD_B_NAME = ({
//±����
HIW"өʯ"NOR,HIW"ʯ��"NOR,HIW"��ʯ��"NOR,
//��Ȼ����
HIW"���ʯ"NOR,HIW"ʯī"NOR,HIW"��Ȼ��"NOR,
//������
HIY"����"NOR,HIY"������"NOR,HIY"������"NOR,HIY"��ʯ"NOR,HIY"ʯӢ"NOR,
HIY"���̿�"NOR,HIY"���ʯ"NOR,HIY"�⾧ʯ"NOR,HIY"���ٿ�"NOR,HIY"������"NOR,
//����
HIC"��Ǧ��"NOR,HIC"��п��"NOR,HIC"��ɰ"NOR,HIC"��ͭ��"NOR,HIC"������"NOR, 
HIC"�����"NOR,HIC"�ƻ�"NOR,HIC"�ۻ�"NOR,HIC"�����"NOR,HIC"��ɰ"NOR, 
//������
HIW"���ʯ"NOR,HIW"����ʯ"NOR,HIW"����ʯ"NOR,HIW"��ȸʯ"NOR,HIW"��ͭ��"NOR, 
HIW"�ؾ�ʯ"NOR,HIW"ʯ��"NOR,HIW"���ٿ�"NOR,HIW"�׻�ʯ"NOR,HIW"����ʯ"NOR, 
HIW"����ʯ"NOR,HIW"����ʯ"NOR,HIW"����ʯ"NOR,HIW"ʯ��"NOR,HIW"����"NOR, 
HIW"����ʯ"NOR,HIW"����ʯ"NOR,HIW"б��ʯ"NOR,HIW"��ͨ��ʯ"NOR,HIW"��ͨ����ʯ"NOR, 
HIW"��ĸ"NOR,HIW"��ʯ"NOR,HIW"ʯ����ʯ"NOR,HIW"�ʯ"NOR,HIW"����ʯ"NOR, 
HIW"����ʯ"NOR,HIW"ʮ��ʯ"NOR,HIW"����ʯ"NOR,HIW"ϼʯ"NOR,HIW"��ʯ"NOR, 
});

string* HARD_B_LONG =({
//±����
HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,
//��Ȼ����
HIW"һ���ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIW"һ���ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIW"һ���ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,	
//������
HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,
HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸�ź�ɫ��ʯͷ����������ֵǮ�����ӡ�\n"NOR,
//����
HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,
HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,HIW"һ����������Ķ�������������ֵǮ�����ӡ�\n"NOR,
//������
HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,
HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,
HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,
HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,
HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,
HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,HIR"һ��͸������ɫ��â�Ŀ�ɰ����������ֵǮ�����ӡ�\n"NOR,
});

string* HARD_B_MATERIAL = ({
"±����","±����","±����",
"��Ȼ����","��Ȼ����","��Ȼ����",
"������","������","������","������","������",
"������","������","������","������","������",
"����","����","����","����","����",
"����","����","����","����","����",
"������","������","������","������","������",
"������","������","������","������","������",
"������","������","������","������","������",
"������","������","������","������","������",
"������","������","������","������","������",
"������","������","������","������","������",
});

string* VERYHARD_B_NAME = ({
//��ʯ
HIW"��ʯ"NOR,
//�̱�ʯ
HIG"��ĸ��"NOR,HIG"���̱�ʯ"NOR,HIG"è��ʯ"NOR,HIG"��ʯ"NOR,HIG"������ʯ"NOR,HIG"�̱�ʯ"NOR,
//��ʯ
HIG"���"NOR,HIG"����"NOR,HIG"ŷ��"NOR,HIG"����ʯ"NOR,HIG"���ʯ"NOR,
HIG"���ʯ"NOR,HIG"��ɽ��"NOR,HIG"��ȸʯ"NOR,HIG"ľ��ʯ"NOR,HIG"����ʯ"NOR,
//�챦ʯ
HIR"�챦ʯ"NOR,
//��ʯ
HIR"����"NOR,HIR"�⾧ʯ"NOR,HIR"ʯ��ʯ"NOR,HIR"����ʯ"NOR,
HIR"�ʯ"NOR,HIR"���ʯ"NOR,HIR"ˮ��ʯ"NOR,HIR"��ʯ"NOR,

});

string* VERYHARD_B_LONG = ({
//��ʯ
HIW"һ����ҫ�۹�â����ʯ����������ֵ���ǡ�\n"NOR,	
//�̱�ʯ
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,
//��ʯ	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIG"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
//�챦ʯ
HIR"һ����Լ¶������ɫ��â�ı�ʯ����������ֵ���ǡ�\n"NOR,	
//��ʯ
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
HIR"һ����ͨ�ı�ʯ����������ֵ���ǡ�\n"NOR,	
});

string* VERYHARD_B_MATERIAL = ({
"��ʯ",
"�̱�ʯ","�̱�ʯ","�̱�ʯ","�̱�ʯ","�̱�ʯ","�̱�ʯ",
"��ʯ","��ʯ","��ʯ","��ʯ","��ʯ",
"��ʯ","��ʯ","��ʯ","��ʯ","��ʯ",
"�챦ʯ",
"��ʯ","��ʯ","��ʯ","��ʯ","��ʯ","��ʯ","��ʯ","��ʯ",
});


string get_address(string level,object me)
{
        string str;
        switch(level)
        {
                case "easy":    
                        str=wheres_easy[random(sizeof(wheres_easy))];
                        break;
                case "normal":  
                        str=wheres_normal[random(sizeof(wheres_normal))];
                        break;
                case "hard":    
                        str=wheres_hard[random(sizeof(wheres_hard))];
                        break;
                case "veryhard":
                        str=wheres_veryhard[random(sizeof(wheres_veryhard))];
                        break;
                default :       
                	str="area error";
        }
        return str;
}

string get_place(string str)
{ 
        string *place = explode(str, "/");

        str = "";
        if(place[0] == "d")
        {
		str = sub_region_names[place[2]];
		if (!str)
			str = region_names[place[1]];
	}
       	return str;
}

int get_value(object me, object mine)
{
//	int value;
	
	if( !me || !mine)	return 0;
}

object settings_mine(string level,object mine)
{
	int i,value;
	string m_name,m_long,m_material;

        if(!mine) 
        	return 0;

//��ʼ��
        mine->set("level",level);
	mine->set("unit", "��");
	mine->set("weight", 800);
	mine->set("long", "����һ����ͨ�Ŀ�ʯ��\n");
	mine->set("no_get","����ʯ��ô�أ���᲻������\n");
	mine->set("no_drop","������ʯͷ���ҵ�����ô�죿\n");
	mine->set("material", "stone");
	mine->set("minejob",1);
	mine->set("value",5000);
	
        switch(level)
        {
                case "normal":  
			i = random(sizeof(NORMAL_B_NAME));
			m_name=NORMAL_B_NAME[i];
			m_long=NORMAL_B_LONG[i];
			m_material=NORMAL_B_MATERIAL[i];
			value=30000+random(30000);
                        break;
                case "hard":
			i = random(sizeof(HARD_B_NAME));
			m_name=HARD_B_NAME[i];
			m_long=HARD_B_LONG[i];
			m_material=HARD_B_MATERIAL[i];
			value=200000+random(30000);
                        break;
                case "veryhard":
			i = random(sizeof(VERYHARD_B_NAME));
			m_name=VERYHARD_B_NAME[i];
			m_long=VERYHARD_B_LONG[i];
			m_material=VERYHARD_B_MATERIAL[i];
			value=500000+random(50000);
                        mine->set("unique", 1);
			break;
        }
	mine->set("name",m_name);
	mine->set("long",m_long);
	mine->set("value",value);
	mine->set("material",m_material);

        return mine;
}

//���轱��������
string check_happy(object me, object mine, int i)
{
	int jiangli;
	string msg;
	
	if( !mine || !me) return 0;
	
	jiangli = mine->query("value") / 500;
	switch (i)
	{
		case 1:
			me->add("potential", jiangli);
			msg = "���������"+ CHINESE_D->chinese_number(jiangli) +"��Ǳ�ܵĽ�����\n";
			break;
		case 2:
			me->add("combat_exp", jiangli);
			msg = "���������"+ CHINESE_D->chinese_number(jiangli) +"�㾭��Ľ�����\n";
			break;
		case 3:
			me->add("balance",jiangli * 10000);
			msg = "��ϲ�����������"+ MONEY_D->price_str(jiangli * 10000) + "�Ľ������Ѿ����������ʻ���\n";
			break;
		case 4:
			jiangli = jiangli * 10 + random(jiangli * 10);
			me->improve_skill("mining", jiangli);
			msg = "���������"+ CHINESE_D->chinese_number(jiangli) +"�㼼�ܽ�����\n";
			break;
		case 5:
			me->set_skill("mining",me->query_skill("mining",1) + 1);
			msg = "��ϲ�����������һ���Ĳɿ��ܡ�\n";
			break;
		default:
			msg = "��˴������޶���Ľ�����\n";
			break;
	}	
	return msg;
}

//����������ֽ�����
int check_encour(object me)
{
	int times, failed_times, mine_skill, exp, encour;
	
	times = me->query("minejob");
	failed_times = me->query("minejob_failed");
	mine_skill = me->query_skill("mining",1);
	exp = me->query("combat_exp");
	
	if( 	times > 500 
		&& failed_times < 200
		&& mine_skill > 200
		&& mine_skill < 400
		&& random(5) == 1)
		encour = 5;
	else if(times > 300 
		&& failed_times < 200
		&& mine_skill > 150
		&& random(5) > 3)
		encour = 4;
	else if(times > 200 
		&& failed_times < 200
		&& mine_skill > 100
		&& random(5) > 3)
		encour = 3;
	else if(times > 100 
		&& failed_times < 200
		&& mine_skill > 50
		&& random(5) > 3)
		encour = 2;
	else encour = 1;

	return encour;
}
//check ��ʯ�ȼ�
string check_level(object me)
{
	string place_level;
	
	if (random(me->query("kar")) > 18 
	 && me->query_con() > 30
	 && me->query_str() > 30
	 && me->query_int() > 30
	 && random(me->query_con()) > 20
	 && random(me->query_str()) > 20
	 && random(20) > 17 )
     		place_level = "veryhard";

	else if (random(me->query("kar")) > 15
	 && me->query_con() > 35
	 && me->query_str() > 35
	 && me->query_int() > 25
	 && random(me->query_con()) > 18
	 && random(me->query_str()) > 18
	 && random(20) > 14)
     		place_level = "hard";

	else if (me->query_con() > 30
	 && me->query_str() > 30
	 && me->query_int() > 30
	 && random(me->query_con()) > 16
	 && random(me->query_str()) >16)
     		place_level = "normal";
	else 	
		place_level = "easy";
		
	return place_level;
}

//check �Ƿ��������
int check_killer(string place_level)
{
	int killer;
	switch (place_level)
	{
		case "veryhard":	killer = 1;break;
		case "hard":		
			if( random(20) > 5)
				killer = 1;
			break;
		case "normal":		
			if( random(20) > 10)
				killer = 1;
			break;
		case "easy":		
			if( random(20) > 15)	
				killer = 1;
			break;	
		default:		killer = 0;break;		
	}
	return killer;
}