#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"���۱���"NOR);
        set("long",@LONG
����һ�����Ĵ��������������ߵ�������������Ĳ���
���޽�ղ��������ޱ����������ͨ��ƽ𣬹�â���䡣����
����¯���������ƣ������������̴�㡣����ǰ��һ�������±��С�
����ȥͨ���زص������ҩʦ�
LONG);       
        set("exits", ([
            "southdown" : __DIR__"road1",
                "north" : __DIR__"gfd",
                "west" : __DIR__"dizangdian",
                "east" : __DIR__"yaoshidian",
	]));
        set("coor/x",-350);
  set("coor/y",-330);
   set("coor/z",30);
   setup();
}

void init()
{
       add_action("do_ketou", "ketou");
}

int do_ketou()
{
object me=this_player();
int i;
i=me->query_skill("buddhism",1);
       if (me->is_busy()) return notify_fail("����æ���ء�\n");
       if (i<20) return 0;
if (random(me->query("neili"))<i) {
   me->unconcious();
return 0;
}
       message_vision("$N�ϵع�������������������ǰ��ͷ��\n", me);
       
    if (me->query("shen") > i) 
    { me->add("shen", -i);     
   me->add("neili",-i/10);}
    if (me->query("shen") <-i ) 
    { me->add("shen", i);     
   me->add("neili",-i/10);}
   me->start_busy(random(2));
       return 1;
} 
