
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"Сʯ��"NOR);
	set("long",@long
����һ��СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����Զ���ĺ����ϴ�
�������������Զ����ֻԧ����һ��Ϸˮ�����ߵ��������ź����ϴ�����΢��
ʱ��ʱ��ҡ���š�
long);
	set("outdoors","����");

	set("exits", ([
		"north" : __DIR__"jingxiushi",
		"east" : __DIR__"huayuan1",
		"west" : __DIR__"jiuqulang1",
	]));

	set("objects", ([
		CLASS_D("kunlun/suxizhi") : 1,
	]));

	setup();
}
