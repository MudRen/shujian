// Room: /d/huashan/sheshen.c
// Date: Look 99/03/25
#include <ansi.h>
inherit ROOM;
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
        int time;
	 time = time() - me->query("quest/hama/time");

        if (arg!="up") 
        return notify_fail(HIG"�������û�취����\n"NOR);

        if (me->query_skill("dodge",1) < 200)
        return notify_fail(HIG"�����˰�����޽�չ�����ǻ�ȥ�����Ṧ�����ɡ�\n"NOR);
        
        
        if (me->query("oyf/hamagong") < 2)
        return notify_fail(HIG"�㻹�����������İɡ�\n"NOR);     

        if (me->query("oyf/hamagong") == 3)
        return notify_fail(HIG"���Ѿ��������常���һ���ˡ�\n"NOR);     

/*	 if (me->query("quest/jiebai/super") >=3 && me->query("registered") < 3)
        return notify_fail(HIG"���常�����˶����ˣ���Ҫ�������ĵ��ˡ�\n"NOR);  
*/
         if ( me->query("quest/hama/time") && time < 86400 ) 
        return notify_fail(HIG"������̫����Щ�ɡ�\n"NOR);  
        if ( me->query("combat_exp") < 6000000 ) 
        return notify_fail(HIG"�㾭�鲻������Ҳû���á�\n"NOR);  
        
        if (me->query("jingli") < 1500)
        return notify_fail(HIG"�㾫�񲻺ã�����ЪЪ�����ɣ�С������С����\n"NOR);

        me->add("jingli",-500);

        message_vision(HIG"$N�ֽŲ��ã�ʹ���˳��̵�������������������\n"NOR,me);
        me->move("/d/huashan/hamasuperquest/jueding1");
        return 1;
}

