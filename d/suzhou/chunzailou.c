inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",RED"����¥"NOR);
        set("long", @LONG
����һ�����ݳ��������ľ�¥������¥���Ե��Ϊ��ɫ��ש��ľ��ʯ
���߽�¥�ڣ�һ�۱㿴��һ����������ͼ�������˱��軭��Ω��ΩФ��¥��
����ϱ��������ſ���������Ʒ�裬ֻ����С��æ�Ĳ����ֺ���
LONG
);
        set("exits", ([ 
	"west" : __DIR__"beidajie2",
	]));
        set("objects",([
	__DIR__"npc/xiaoer1" : 1,
       
]));
        set("coor/x",120);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}

