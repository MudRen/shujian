// Room: /d/putian/yuanzi3.c СԺ
// lklv 2001.7.21

inherit ROOM;
void create()
{
        set("short", "СԺ");
        set("long", @LONG
����һ���ž����ŵ�СԺ���������������һ��鷽ש�������и������
�����ţ�������һ�����ȣ��·����һֱͨ����Ժ������ķ�����ǰԺ����ʱ
�����������ӵ�������
LONG
        );

        set("exits", ([
                "east" : __DIR__"qianyuan",
                "south" : __DIR__"celang3",

        ]));

        set("outdoors", "����");
        setup();
}
