inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"�Ͻ���"NOR);
        set("long", @LONG
����һ�����ݳ������������֣������������ͼ�Ħ����ۣ��ƺ���ע��
ǰ�����֮�ˣ��ұ�һ��������������ָ����һ��������廨���Ǻͺ�ڹ�
������ͷ�ϵ�һ������ĵ�������Ϻ�ɫ���ǡ���ڵ�ÿ���޺���������������
���������������������˻������񳬺�����֮������������磬����̾Ϊ��
ֹ��
LONG
);
        set("exits", ([ 
	"east" : __DIR__"beidajie2",
	]));
        set("objects",([
        __DIR__"npc/nigu"  : 2,
 __DIR__"obj/box" : 1,
]));
        set("coor/x",100);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
//      ��������ֵ�˿����������ϣ�Ȼ���ͷ��Ӿ��飡(put silk on xxx)
}

