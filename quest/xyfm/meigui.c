// õ�������.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
// amount: ��λ��gold

void create()
{
        set("short", HIG"�ݱ���"NOR);
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"zxlpath",
        ]));

        

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }