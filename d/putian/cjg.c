// Room: /d/putian/cjg.c �ؾ���
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
���������������Ժ�Ĳؾ�����Ȼ������ɽ��Ժ�Ĳ��������࣬Ҳû��
��Ժ�ؾ�¥����������������Ҳ����Ϊ�Ϸ��𷨵ı��أ����������´˴��ؾ�
���Է𾭵伮Ϊ����������һЩ���ֲ���֮����ͼ�ס����ޱ�Ժ�㲩����ռ
�侫����Ҫ�����ﵽ�������������飬�߼�����Ĵ���ܡ�
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"mf-dian",
        ]));

        set("objects",([
                CLASS_D("putian") + "/da-chi" : 1,
                __DIR__"npc/shami" : 2,
		"/d/shaolin/obj/wuji1" : 1,
		"/d/shaolin/obj/wuji2" : 1,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
        object ob;

        if ((ob = present("dachi dashi", this_object())) && living(ob))
                if (dir == "northdown" ) {
                        foreach(ob in deep_inventory(me))
                                if (ob->id("shaolin wuji"))
                                        return notify_fail("��մ�ʦ˵�����书�ؼ�ֻ���ڲؾ�������ϰ������Я�������\n");
                }
        if ((ob = present("xiao shami", this_object())) && living(ob))
                if (dir == "northdown" ) {
                        foreach(ob in deep_inventory(me))
                                if (ob->id("shaolin wuji")){
                                	me->set_temp("target_putian",1);
                                	me->start_busy(1);
                                	message_vision(HIY"Сɳ�ִ󺰵��������˰�������͵����������\n"NOR,me);
                                	}
                }
        return ::valid_leave(me, dir);
}
