// Room: /city/lichunyuan2.c
// Dec.12 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "����Ժ");
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG);
        set("exits", ([
            "down" : __DIR__"lichunyuan",
        ]));

        setup();
}

//�Ǿ���
int is_mirror() { return 1; }