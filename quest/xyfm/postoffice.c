// Room: /d/system_3/postoffice.c
inherit ROOM;
void create()
{
        set("short", "�ķ���վ");
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
        );
        
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"beimen",
        ]));

        setup();
}

//�Ǿ���
int is_mirror() { return 1; }