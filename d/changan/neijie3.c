// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/neijie3.c

inherit ROOM;

void create()
{
        set("short", "�ڽ�");
        set("long", @LONG
�����ǳ����ǵľ�������ס�Ķ���ƽ�����գ����Ժ���Щ��ֱ���������
��Ͳ���ô�����ˡ�����Ҳ����СС���棬���ڶ�������������������������
Ϣ����ȻһƬ�����ľ���������һ�����ڵ�ľ�ţ����������ſ��������
͵����ʲô��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"neijie4",
                "south"  : __DIR__"tupiaoguan",
                "west"   : __DIR__"neijie2",
                "north"  : __DIR__"minju5",
        ]));

        set("objects", ([
                __DIR__"npc/child" : 3,
        ]));

        set("incity",1);
	setup();
}