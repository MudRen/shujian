// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIB"������"NOR);
       set("long", @LONG
ͨ�������ƽ���������ʦ��ǰ��������ң�������Ϊ�Ұ����ܲ�͸�⡣
�����а���һ����ͭ�ף�����ʢ����ˮ���������ԡ�Ϊ�������һ�����
��˵�����ʦ�����ܴ������ظ���֮����Ѱ�ž��������������£���
�����ڴ�����(strike)�����Ʒ������Ƿ��켫֮�ز�����һ����ѧ�ذ¾�
���ڴ˶���֮�С�
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));             
        setup();
}
void init()
{
	add_action("do_strike","strike");
}
int do_strike(string arg)
{
	object me;
	me=this_player();
	if (arg!="shui") return 0;
	if (!living(me)) return 0;
        message("vision", me->name()+"��׼ͭ���е�ˮ�淢�ƻ�����\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("strike",1)<30){
		write(HIR"�㹦��̫ǳ��ͭ������ˮ��Ҳû����һ�㡣\n"NOR);
 	return 1;
	}
	if ((int)me->query_skill("strike",1)>100){
		      write(HIR"���������ۣ�ͭ���ھ�ˮΪ�������������ѻ�Ӧ֮����\n"NOR);
	return 1;
	}
        if ((int)me->query_skill("strike", 1) >= 30 
        && (int)me->query_skill("strike", 1) <= 100&&arg=="shui" ){
                 if ((int)me->query("jing")<30)
               {
                me->unconcious();     
                return 0;
                 }
  
                me->receive_damage("jing", 30);
                me->improve_skill("strike", (me->query("int"))*3/2);
                write(HIB"�����ˮ��ңң���ƣ����ڼ���ƬƬˮ����������������о�����\n"NOR);
	return 1;
	}
}

