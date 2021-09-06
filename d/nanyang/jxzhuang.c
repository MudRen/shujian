// Room: /d/nanyang/jxzhuang.c
// Lklv Modify 2001.10.10
// Tangfeng@SJ 2004

#include <ansi.h>
inherit ROOM;
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"

void create()
{
        set("short", "����ׯ����");
        set("long",
"���ߵ�һ����լ��Ժ���ſڣ����ſ��ţ���ǰ����������ʯʨ�ӣ����弶\n"
"��ʯ̨���������ȶ���ͭ���Ĵ��š����ó�������һ���˼ҵ�ס�����ſ���\n"
"���������һ��ڵ׽��ֵĴ��ң�����д���������֣�"YEL"������ׯ��"NOR"��\n"
        );
		set("quest",1);
		set("outdoors", "����");
		set("exits", ([
			"southwest" : __DIR__"xiaolu3",
				"north" : __DIR__"dating",
		]));

		set("objects",([
			__DIR__"npc/guanjia" : 1,
				__DIR__"npc/jiading" : 1,
		]));
        
		setup();
}
void init()
{
	object obj,me = this_player();
	if ( me->query(QUESTDIR3+"start")
		&& !me->query_temp(QUESTDIR3+"kill")
		&& !me->query(QUESTDIR3+"over")){
			me->start_busy(2);
			//����뿪����뿪��ʧ��
			obj=new(__DIR__"npc/guanjia");
			if(!present("guan jia",this_object()))
				obj->move(this_object());
			obj=new(__DIR__"npc/jiading");
			if(!present("guan jia",this_object()))
				obj->move(this_object());		
		}
}
int valid_leave(object me, string dir)
{
   object room;
   if (!(room = find_object(__DIR__"dating")))
       room = load_object(__DIR__"dating");

   if(room && room->query("busy")&& dir == "north" )
     return notify_fail(HIR"�㷢�־���ׯ���ƺ��������ҵĴ�֮����������Ϊ�ϲߣ�\n"NOR);
   
   if (me->query(QUESTDIR3+"start") 
         && !me->query(QUESTDIR3+"over") 
         && dir == "north" 
         && present("guan jia", environment(me)))
     return notify_fail(HIR"�ܼ���Цһ��������λ"+RANK_D->query_respect(me) +"��أ����ﲻ��ӭ�㣡\n"NOR);
     if (me->query(QUESTDIR3+"start") 
         && !me->query(QUESTDIR3+"over") 
         && dir == "north" 
         && present("jia ding", environment(me)))
     return notify_fail(HIG"�Ҷ���Цһ��������λ"+RANK_D->query_respect(me) +"��أ����ﲻ��ӭ�㣡\n"NOR);

     if(dir == "north" &&(me->query_condition("killer")||	sizeof(filter_array(deep_inventory(me), (: userp :)))))
		 return notify_fail(HIY"ͻȻ�����洫��һ����Ц������λ"+RANK_D->query_respect(me) +"��أ����ﲻ��ӭ�㣡\n"NOR);
     return ::valid_leave(me, dir);
}
