// Room: /d/emei/guiyunge.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "���Ƹ�" NOR);
	set("long", @LONG
���Ƹ�ԭ���ƴ����������ʦ�ĵ������δ�������䣬ɮ��ʿ��������
�ؽ������Ƹ�������Ů�壬���Ͽɵִ���������ǹ����á�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
	  "southup" : __DIR__"yunvfeng",
	  "eastdown" : __DIR__"guanyintang",
	  "westup" : __DIR__"chunyangdian",
]));
	set("objects",([
		"/d/emei/npc/dizi2" : 2,
]));
	setup();
}
