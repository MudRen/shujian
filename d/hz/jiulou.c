// /u/beyond/hz/jiulou.c ����¥
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",MAG"����¥"NOR);
        set("long", @LONG
����һ�����ݳ��������ľ�¥������¥��һ���Ϊ��ɫ��ש��ľ��
ʯ���߽�¥�ڣ�һ�۱㿴��һ����������ͼ�������˱��軭��Ω��ΩФ��
¥������ϱ��������ſ���������Ʒ�裬ֻ����С��æ�Ĳ����ֺ���
LONG
);
        set("exits", ([ 
	"east" : __DIR__"qsddao6",
	]));
        set("objects",([
__DIR__"npc/xiaoer1" : 1,
       
]));
        set("coor/x",90);
  set("coor/y",-320);
   set("coor/z",0);
   setup();
}

