// emei ��ľ��

#include <room.h>
inherit ROOM;


void create()
{
        set("short", "��ľ��");
        set("long", @LONG
������һƬһ�˶�ߵĹ�ľ�ԣ������Ѿ������㼣��һ��紵������ľ��
����ɳɳ�������������������ǰ�����ľ������û��·��ÿ��һ������������
���̵��¿㣬����������塣
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"houshangm",
                "southwest" : __DIR__"houshangm",
                "eastdown" : __DIR__"houshangm",
                "westup" : __DIR__"houshangm",
        ]));

        set("outdoors", "��üɽ");
        setup();
}

int valid_leave(object me, string dir)
{
    me->set_temp("last_damage_from", "�ڹ�ľ�����ƣ������");
    me->receive_damage("jingli", random(200) );
    if (dir == "eastdown" && me->query("family/master_id") == "guhong zi") {
        me->delete_temp("steps");
        me->move(__DIR__"houshangm1");
        return notify_fail("�������߳��˹�ľ�ԡ�\n");
    }
    if ( dir == "eastdown" ) me->add_temp("steps", random(30));
    if ( dir == "westup" ) me->add_temp("steps", - random(20));
    if ( dir == "northeast" ) me->add_temp("steps", random(10));
    if ( dir == "southwest" ) me->add_temp("steps", -random(10));
    if ( (int)me->query_temp("steps") < 110 && (int)me->query_temp("steps") >100 ) {
        me->delete_temp("steps");
        me->move(__DIR__"houshangm1");
        return notify_fail("�������߳��˹�ľ�ԡ�\n");
    }
    return ::valid_leave(me, dir);

} 
