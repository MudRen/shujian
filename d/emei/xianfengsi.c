// xianfengsi.c
// �ɷ���
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "�ɷ���" NOR);
	set("long",@long
�������ɷ��¡���ǰ��ľ���죬ï��Ũ�����º����Ҹ߲����ơ�ӭ�滪
�϶�����������磬ʱ�ж�����Ʈ�ƣ�ǡ��һ��ˬ����Ŀ��ɽˮ����
long);
	set("exits",([
		"westdown" : __DIR__"huayanding",
]));
	setup();
}
