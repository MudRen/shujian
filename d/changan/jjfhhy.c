// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfhhy.c

inherit ROOM;
#include <room.h>;

void create()
{
        set("short", "��԰");
        set("long", @LONG
һ��С��԰����Ȼ�Ȳ��ϸ�����Ժ�������ǧ�죬��Ҳ���õþ��¿��ˡ�
����������Ȼ��������֮ʿ���������һ�ʢ�������ճ�����ɻ����������
�ջ����ޣ���������һƬ��ѩ����
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                "west"   : __DIR__"jjflt",
                "north"  : __DIR__"jjfhm",
        ]));

        set("incity",1);
	setup();
        create_door("north","����","south",DOOR_CLOSED);
       
}
