// Room: /d/tiezhang/xxsnan.c

inherit ROOM;

void create()
{
        set("short", "����Ϣ��");
        set("long", @LONG
����һ���ڰ��Ĵ󷿼䡣�����ú���������ס����¶˿��������������
���������ʮ����ľ���ɵĴ��̣�������������İ��ڼ�ʱ�õ���Ϣ������
�����ĵģ��ڰ���ż��������΢��������
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
                "south" : __DIR__"zoulang-4.c",
        ]));
        setup();
}

