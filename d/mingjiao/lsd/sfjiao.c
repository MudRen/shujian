// /u/qingyun/lsd/sfjiao.c
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", GRN"ɽ�����"NOR);
	set("long", @LONG
�������ܳ�����೤�ݣ��˵���Ϊ�����ߵ��������϶�Ȼ�����ض࣬��ʱ
���ж���ܳ�����������ֻ�ܾ�����ͺ��ɽʯ����š����϶�����ɽ�嶥����
��ϡ�ɼ�һ��é���������С�
LONG);
	set("exits", ([ 
  		"south" : __DIR__"lsgu",
  		"northup" : __DIR__"shanfeng",
	]));
	set("objects",([
            "/d/xingxiu/npc/snake"  :       1,
	]));
	set("outdoors","���ߵ�");
	setup();
}
