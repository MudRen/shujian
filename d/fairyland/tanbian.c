// Room: tanbian.c
// By River@SJ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"���"NOR);
        set("long", @LONG
����ǰ�Ǹ����Ž��صĴ�ȣ��컨������������ӳ������̤�ŵ�������ϸ
�ݣ������ŵ��������Ļ��㣬���ݼ�أ��ʹ���֦�����ɵ��Ŀ������������
Ұ������Թ�������ӣ����㿴������ϣ�棬���±�����Ϊ�裬�̲�������
LONG    );
        set("no_fight", 1);
        set("sleep_room", 1);

        set("exits", ([                
                "northup" : __DIR__"pubu",
        ]));

        set("outdoors", "���ش��");
        set("no_clean_up", 0);
        setup();
}
