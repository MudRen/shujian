// Room: /d/xianyang/chayedian.c ��Ҷ��
// Lklv 2001.9.26

inherit ROOM;
void create()
{
        set("short", "��Ҷ��");
        set("long", @LONG
����һ��������¡�Ĳ�Ҷ�꣬���ǽ��������غ������֣���̨������ź�
�������������������ƽ����һ���Ҷ����ɹ����̨�������Ǽ�����ɫ��ľͷ
ϻ�ӣ�����Ʈ��һ�ɵ����Ĳ�Ҷ���㡣
LONG
        );

        set("exits", ([
                "east" : __DIR__"xcx1",
        ]));

        set("objects", ([
//                __DIR__"npc/laoban" : 1,
        ]));

        set("incity",1);
	setup();
}
