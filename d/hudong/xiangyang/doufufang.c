// Room: /d/xianyang/doufufang.c ������
// Lklv 2001.9.26

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ�Ҷ��������ſڵ�����˨��һͷë¿�����м���һ�̺ܴ��ƽ����
ʯĥ��ǽ���кü�����ף�������Ư����һ�㱡���Ķ�Ƥ�����׵ĵ��϶���һ
��������и����ڵ�¶��������Ļƶ���������������һ�ɶ�����ζ����
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"xcx2",
        ]));

        set("objects", ([
//                __DIR__"npc/laoban" : 1,
        ]));

        set("incity",1);
	setup();
}
