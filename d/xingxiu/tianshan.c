// room: /d/xingxiu/tianshan
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long",@LONG
��������ɽ��´��ɽ���ɽ�ϴ������������ɪɪ���������������ɽ��
�����ԣ��������ѩˮ��ȣ����ط��֣��̳���һƬ��ԭ����ԭ�Ϸ����Ⱥ��
�ӣ�һ�Զ�������Ů�����˶������������Գ���
LONG );

        set("exits", ([
		"southeast" : "/d/hj/senlin1",
		"west" : "/d/tianshan/kongchang",
        ]));

        set("outdoors", "��ɽ");

        set("objects", ([
                __DIR__"npc/hkid" : 1,
                __DIR__"npc/hgirl" : 1,
                __DIR__"npc/yang" : 3,
        ]));

	setup();
}
