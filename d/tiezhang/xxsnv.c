// Room: /d/tiezhang/xxsnv.c

inherit ROOM;

void create()
{
        set("short", "Ů��Ϣ��");
        set("long", @LONG
����һ���ڰ��Ĵ󷿼䡣�����ú���������ס����¶˿��������������
���������ʮ����ľ���ɵĴ��̣�������������İ��ڼ�ʱ�õ���Ϣ������
�����ĵģ��ڰ���ż��������΢�����������ڵ�����Ʈ��һ�����ĵ�������
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
                "north" : __DIR__"zoulang-4.c",
        ]));

        set("coor/x",-310);
        set("coor/y",-260);
        set("coor/z",10);

        setup();
}

