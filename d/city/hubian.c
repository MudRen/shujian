// /d/city/hubian.c ����

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",GRN"����"NOR);
	set("long", @LONG
��������ɽ��ˮ�㣬�̲�����������ɽɫ����ӳ��Ȥ�����ۺ������羵��
�У������������续���Ρ�����֮�����������Թ����������ǳ����ޡ�����
�ġ��㡢�ᡢ������������
LONG
	);
	set("objects",([
		NPC_D("youke") : 1,
	]));
	set("exits", ([
		"north" : __DIR__"sxh",
		"south" : __DIR__"xidajie2",
	]));
	set("outdoors", "����");
	set("incity",1);
	setup();
}
