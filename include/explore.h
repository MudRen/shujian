//      File    :  /include/explore.h

// ���ɶ�Ӧ����ֵ
#ifndef __EXPLORE__
#define __EXPLORE__
#define EXPLORE_LEVEL 0
#endif
string *titlescolor = ({ HIY, HIR, HIW });

string *dietime = ({ "����", "����", "һ����", "����", "ʮ��", "��ʮ��" });

int Get_Family_Name(object ob, string family)
{
        switch(family){
                case "������" : return 1; break;
                case "�䵱��" : return 2; break;
                case "��ɽ��" : return 3; break;
                case "ؤ��"   : return 4; break;
                case "�һ���" : return 5; break;
                case "������" : return 6; break;
                case "����Ľ��":return 7; break;
                case "����"  :  return 8; break;
                case "��Ĺ��" : return 9; break;
                case "������" : return 10;break;
                case "ȫ����" : return 11;break;
        }
}

// Ŀ¼��Ӧ����������
mapping place = ([
"/d/bdao/" : "����",
"/d/chengdu/" : "�ɶ�",
"/d/city/"  :  "���ݳ�",
"/d/city2/" :  "������",
"/d/death/" :  "����",
"/d/diaoyu/" :  "���㵺",
"/d/emei/"  : "����ɽ",
"/d/gaibang/" : "ؤ��",
"/d/gaochang/" : "�߲�",
"/d/guiyun/"  : "����ׯ",
"/d/gumu/"  : "��Ĺ�ľ�",
"/d/hmy/" : "��Ĺ��",
"/d/huanggon/" : "�ʹ�",
"/d/huashan/" : "��ɽ",
"/d/jiaxing/" : "���˳�",
"/d/liaoguo/" : "�ɹ�",
"/d/mj/" : "���̹�����",
"/d/murong/" : "Ľ��ɽׯ",
"/d/npc/"  :  "��ֹĿ¼",
"/d/player/" : "��ֹĿ¼",
"/d/quanzhou/" : "Ȫ�ݳ�",
"/d/quest/" : "��ֹĿ¼",
"/d/qz/" : "����ɽ",
"/d/shaolin/" : "��ɽ������",
"/d/shenlong/" : "������",
"/d/taishan/" : "��ɽ",
"/d/thd/" : "�һ���",
"/d/village/" : "��ɽ��",
"/d/wizard/" : "��ֹĿ¼",
"/d/working/" : "��ֹĿ¼",
"/d/wudang/" : "�䵱ɽ",
"/d/xiangyang/" : "������",
"/d/xiangyang_old/" : "��ֹĿ¼",
"/d/xingxiu/" : "�������޺�",
"/d/xingxiu_old/"  : "��ֹĿ¼",
]);

string *damage_types = ({
  "����",
  "����",
  "����",
  "����",
  "����",
  "����",
  "����",
  "����",
  "����",
  "ץ��",
  "����",
  "����",
});

string *families = ({
  "������",
  "�䵱��",
  "ؤ��",
  "�һ�",
  "������",
  "����Ľ��",
  "����",
  "��Ĺ��",
  "������",
  "ȫ����",  
});

