// /u/jpei/thd/kefang.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","�ͷ�");
        set("long",@LONG
�����д�����ס�޵ķ��䡣���ڳ��辫�ţ�������ԣ������Žࡣ
LONG
);
        set("exits",([
                "west" : __DIR__"jicui",
        ]) );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        setup();
}

void init()
{       
        object me = this_player();
        int lvl,lvl1,lvl2;
        lvl = me->query_skill("qimen-bagua", 1);
        lvl1 = me->query_skill("bihai-chaosheng", 1);
        if (lvl > 200 && !me->query("cut/thd")){
                lvl2 = (lvl - 200)/ 4;
                me->set_skill("qimen-bagua", 200);
                me->set_skill("bihai-chaosheng", lvl1 + lvl2);
                me->set("cut/thd", lvl2 * 4);
                write(HIG "ϵͳ�ѽ�������ġ����Ű��ԡ�ת��Ϊ���̺�����������\n" NOR);
        }
}
