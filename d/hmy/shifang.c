// /d/hmy/shifang.c
// modified by Numa 19991108

inherit ROOM;

void create()
{
        set("short", "��ʳ��");
        set("long", @LONG
ֻ���Ծ���ʮ������ͽ�ֱ�Χ�ż��Ű������ڽ�ʳ��ǽ����һ�������ǿ�
�ŵģ���Χ���ż������ӣ�Ҫ���Ƥ�����������¡�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"changlang4",
        ]));
        set("objects",([
                FOOD_D("tang") : 2,
                FOOD_D("zongzi") : 1,
                __DIR__"npc/chuzi" : 1,
        ]));
        set("no_fight", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i;
        
        i = sizeof(ob);
        if((dir == "west")){
                while (i--)
                if(ob[i]->id("suanmei tang") || ob[i]->id("zongzi"))
                        return notify_fail("���Ӻ���һ����˵�����Ա������˻�Ҫ����ѽ��\n");
        }
        return ::valid_leave(me, dir);
}
