// chongling.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIG"����"NOR);
	set("long", @LONG
��һֱ�߳���ʮ�������һ��Ƭ�����ˡ�ԭ���˵���Բ���㣬������
������֪��ͷ�������������죬��ɭɭ��������գ�������ʲô�Ź֣�ȴ�ǲ�
�ö�֪�����к���֮�˿϶�Ҫ����һ̽�ġ�
LONG);
	set("outdoors","����");
	set("exits",([
		"south" : __DIR__"shishan",
                "north" : __DIR__"cling1",
	]));
	setup();
}
