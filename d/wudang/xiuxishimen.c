// Room: xiuxishimen.c
// By shang

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
        ���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );
        set("exits", ([
               "north" : __DIR__"donglang2",
            ]));
        set("sleep_room", 1);
        setup();
}




