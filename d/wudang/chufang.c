// chufang.c (kunlun)
// copied from wudang, modify later.
// cck modified on 17/6/97
// Lklv Modify at 2001.10.19

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string arg);
int do_sit(string arg);
void delete_served(object me);

void create()
{
        set("short", "����");
        set("long", @LONG
�������䵱�ɵ����ò͵ĵط������ﲼ�úܼ�, ֻ���ż�������, ��λ
�䵱����һ������س��š������֮���������, ֻ�����н��Ǵֲ赭����
LONG
        );

        set("exits", ([
                "west" : __DIR__"donglang2",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
                FOOD_D("rice") : 2,
                FOOD_D("cha") : 2,
                FOOD_D("doufu") : 2,
                FOOD_D("dawancha") : 2,
        ]));
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir == "west")){
        while (i--)
        if(ob[i]->id("xiang cha")
         ||ob[i]->id("mi fan")
         ||ob[i]->id("doufu")
         ||ob[i]->id("da wan"))
           return notify_fail(CYN"��ͯ��ס������䵱ɽ�Ĺ��, ��ʳ���ô���������\n"NOR);
        }
        return ::valid_leave(me, dir);
}
