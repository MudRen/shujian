// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����ɳĮ����Ȼ�γɵ�һ��ʯ�������й��߻谵����ȴʮ�ָ��������
�߼��ѵ��ݣ��ƺ��ǹ���˯��֮�ã��������������з·�������ˮ��������һ
�Ƿ���������ͷ��(skulls)��
LONG );
        set("exits", ([
                "out" : __DIR__"shamo1",
  //              "enter" : __DIR__"shidong2",
        ]));
        set("item_desc", ([
                "skulls" : "һ���������������ͷ����һ�������壬���಻�٣�ǡ�ǾſŰ׹�����ͷ��\n",
        ]));
        set("cant_hubiao", 1);
        set("objects", ([
                __DIR__"npc/mei" :1,
                __DIR__"npc/chen" :1,
        ]));

	setup();
}
