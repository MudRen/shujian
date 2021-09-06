

#include <ansi.h>

inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "������");
         set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С�ģ�һ
ʧ�����ȥ��ֻ������ͷ���Ҳ�����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "eastdown" : __DIR__"canglong",
         ]));
        
        set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "��ɽ" );

        set("coor/x",60);
        set("coor/y",50);
        set("coor/z",70);
         setup();
}

void init()
{
        add_action("do_climb","climb");

}
int do_climb(string arg)
{
        object me = this_player();

        if (arg!="up") 
        return notify_fail(HIG"�������û�취����\n"NOR);
                
        if (me->query_skill("dodge",1) < 360)
        return notify_fail(HIG"�����˰�����޽�չ�����ǻ�ȥ�����Ṧ�����ɡ�\n"NOR);
        
        if (me->query_skill("hamagong",1) < 200)
        return notify_fail(HIG"�����˰���о����ĵ�����\n"NOR);
        
        if (me->query("oyf/hamagong") < 2)
        return notify_fail(HIG"�㻹�����������İɡ�\n"NOR);	

        if (me->query("oyf/hamagong") == 3)
        return notify_fail(HIG"���Ѿ��������常���һ���ˡ�\n"NOR);     

        if (me->query("quest/hama/super") > 3)
        return notify_fail(HIG"���常�����˶����ˣ���Ҫ�������ĵ��ˡ�\n"NOR);	
        
        if (me->query("jingli") < 1500)
        return notify_fail(HIG"�㾫�񲻺ã�����ЪЪ�����ɣ�С������С����\n"NOR);

        me->add("jingli",-500);

        message_vision(HIG"$N�ֽŲ��ã�ʹ���˳��̵�������������������\n"NOR,me);
        me->move("/d/huashan/hamasuperquest/jueding1");
}
                
