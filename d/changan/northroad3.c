// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad3.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����������Ĵ������·�ܿ�����ݵ���ʮ���ۡ�����������
���������������ǳ����֡��ϱ�ԶԶ����ȥ���Կ��õ�Ρ��ĳ�����ǽ��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
       "northeast"  : __DIR__"northroad4",
           "south"  : __DIR__"northroad2",
                        ]));
                        
        setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("id") == "yangcan popo" && dir != "south") return 0;
	return ::valid_leave(me, dir);
}
