// Room: /d/putian/yuanzi2.c СԺ
// lklv 2001.7.21

inherit ROOM;
void create()
{
        set("short", "СԺ");
        set("long", @LONG
����һ���ľ�������СԺ���������������һ�����ʯ�������и������
�����ţ�������һ�����ȣ��·����һֱͨ����Ժ������ķ�����ǰԺ����ʱ
�����������ӵ�������
LONG
        );

        set("exits", ([
                "west" : __DIR__"qianyuan",
                "south" : __DIR__"celang2",

        ]));

        set("outdoors", "����");
        setup();
}
