// xiangfang.c �᷿
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"�᷿"NOR);
        set("long", @LONG
������ר�Ź������ı�����Ϣ�ĵط��������м��Ŵ���һЩ������Ʒ��ʮ
�ָɾ����ʡ�
LONG);
        set("exits", ([
                "west" : __DIR__"tingtang",
        ]));    
        set("no_fight", 1);
        set("sleep_room", 1);
        set("mj_xl", "yin2");
        setup();
}

void init()
{
	object me = this_player();
	string arg = this_object()->query("mj_xl");
	if(me->query_temp("mj/xunluo")
           && !me->query_temp(arg)
           && me->query_temp("tearoom")
           && me->query_temp("shanyao")
           && me->query_temp("mj/xunluo") == 7){
              me->add_temp(arg,1);
              me->delete_temp("tearoom");
              me->delete_temp("shanyao");
	}
	if ( userp(me))
	 	me->start_busy(1);
}
