// ܽ�������.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
// amount: ��λ��gold

void create()
{
        set("short", HIY"�ƾɾ�¥"NOR);
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"zxlpath",
        ]));

        set("item_desc", ([
                "menu": @TEXT
�а��ʽ��ϯ, ��ӭ�ݹˣ�

        order birthday: ף����        (400���ƽ�)

        order marry:    ������        (800���ƽ�)

        order player:   Ⱥ����        (1000���ƽ�)

        order end:      ��  ��

TEXT
        ]) );

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }