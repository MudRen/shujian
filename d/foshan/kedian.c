
#include <ansi.h>
inherit ROOM;

void create()
{
            set("short", HIC"Ӣ�ۿ�ջ"NOR);
        set("long", @LONG       
����һ��װ�޲���Ŀ�ջ�����Ϸ�����һ���ߵ�ľ�ң����顰Ӣ��
��ջ�������Ƿ����ϵĲ�ҵ֮һ��ƾ���ϰ������������������һֱ����
���ڴ˵��ҡ����������Ŀ����ڴ�ס��Ҳ�ȽϷ��ģ���С�����������ⲻ
ͣ��æ���š���ջ�����ǽ�Ϲ���һ����Ŀ������(paizi)��
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
         set("no_fight",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
        __DIR__"npc/xiaoer2" : 1,
        ]));

        set("exits", ([ /* sizeof() == 2 */
               "up" : __DIR__"kedian2",
               "east" : __DIR__"nanjie",
        ]));

        set("coor/x",-10);
  set("coor/y",-550);
   set("coor/z",0);
   setup();

}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��ô�ţ����ס����\n");

        if ( me->query_temp("rent_paid") && dir == "east" )
                return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

        return ::valid_leave(me, dir);
}
