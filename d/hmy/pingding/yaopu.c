// yaopu.c

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"ҩ��"NOR);
        set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ�ҩ���ϰ����ڲ輸�ԣ����Ժ��Ų衣һ��С���վ�ڹ�̨
���к��Ź˿͡�
LONG
        );
        set("item_desc", ([
                "guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������ҩ���ϰ����顣\n",
        ]));

        set("objects", ([
                __DIR__"npc/laoban" : 1,
                __DIR__"npc/huoji" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"cj3",
        ]));

        setup();
}


