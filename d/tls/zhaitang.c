#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������ի��");
        set("long", @LONG
���������µ�ի�á���������Ʈ������ζ��һЩ�����ڲ�ͣ��æ
�ţ�����һ�Ƿ��źö��ժ��������ˣ��㲻�ɵ�������ͣ�������
����Ķ��ӡ����������Ľ���������
LONG);
        set("exits", ([
		"east"  : __DIR__"dmg",
	]));
        setup();
}

