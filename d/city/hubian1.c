// /d/city/hubian.c ��������

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",GRN"��������"NOR);
	set("long", @LONG
��������ɽ��ˮ�㣬�̲�����������ɽɫ����ӳ��Ȥ�����ۺ������羵��
�У������������续���Ρ�����֮�����������Թ����������ǳ����ޡ�����
�ġ��㡢�ᡢ������������
LONG
	);
	set("objects",([
		NPC_D("youke") : 2,
	]));
	set("exits", ([
		"west" : __DIR__"lxs",
		"south" : __DIR__"dhq",
	]));
	set("outdoors", "����");
	set("incity",1);
	setup();
}
