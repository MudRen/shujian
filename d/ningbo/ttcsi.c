// Room: /u/beyond/ningbo/ttcsi.c ��ͯ����
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"��ͯ����"NOR);
	set("long", @LONG
��ͯ�����С����Ϸ����֮�ơ��������ذ�ɽ����ģ������ƷǷ�����
��Ⱥɽ��������ľ���죬��ɫ�������ˡ������������������ʯ��ᾣ���ľ��
�ף�ɽ�����ۣ���ˮ���ȣ�����ʮ�����š�
LONG
	);
	set("outdoors", "����");
        set("objects",([
		__DIR__"npc/you" : 1,
        ]));

	set("exits", ([
		"north" : __DIR__"tianfengta",
        	"east" : __DIR__"ningbo",
        	"southwest" : "/d/fuzhou/road1",
        ]));
	setup();
}
