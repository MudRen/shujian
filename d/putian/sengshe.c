// Room: /d/putian/sengshe.c
// Lklv 2001.9.11

inherit ROOM;

void create()
{
       set("short", "ɮ��");
       set("long", @LONG
������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ���������̵�����
ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����ʵ���ڹ�������������
������ķ��ż������ź�ľ�㡣
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits", ([
                 "south" : __DIR__"celang4",
        ]));

        setup();
}
