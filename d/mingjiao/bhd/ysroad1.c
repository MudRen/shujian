// ysroad1.c ��ʯ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��ʯ·"NOR);
	set("long", @LONG
����һ��ʯ·���ɴ�ȥ��ɽ������ʮ����·�����ڴ��ѿ��Կ�������ɽ��
һ�ƺ��̳��������ʯ·���ɻ�ɽ�Ҷѳɣ���ʱ�ã�����ʮ�ּ�Ӳ�� 
LONG);	
	set("exits",([
		"east" : __DIR__"shishan",
		"west" : __DIR__"ysroad2",
	]));
	set("outdoors","����");
	setup();
}
