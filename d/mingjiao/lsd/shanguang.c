// /d/mingjiao/lsd/shanguang.c
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", GRN"ɽ��"NOR);
	set("long", @LONG
ֻ��ɽ����ϡϡ���䳤��һЩ���ݺͷ�ò�֪������ľ����ľ���ߣ���ȴ
���ôд䣬ɽ�ڵ���һ����һ��Сʯɽ�����������ǰ��ߣ�����������ɽ���
�¡��������������߹ȡ�
LONG);
	set("exits", ([ 
  		"westdown" : __DIR__"anbian",
		"northdown" : __DIR__"lsgu",
	]));
	set("outdoors","���ߵ�");
	setup();
}
