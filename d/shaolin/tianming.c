// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",CYN"������̨"NOR);
       set("long", @LONG
һ����տ���ʯ�ң�����ֻ��һ��ʯ�����ı����ء�̧ͷ��ȥ������
����һֻʯӥ��������ɡ�ӥצ�䴹�¼���������۵Ĵ�������ʦ����ɫ��
��ȵ�ʦ�塣ǰ����ɮ����ִ�����ַ�Ԩ��������¡�������ʦ������
Ϊ��Ϊ������Ϊ�����޶�����צ��(claw)�������ڴ�ʯ���ڱչؾ��꣬����
�ڴˡ�������书��û�ڿ���֮�С�
LONG
     );
    
	set("exits", ([
"out" : __DIR__"fota2",         
	]));             
        setup();
}
void init()
{
	add_action("do_claw","claw");
}
int do_claw(string arg)
{
	object me;
	me=this_player();
	if (arg!="sheng") return 0;
	if (!living(me)) return 0;
        if ( me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");
        message("vision", me->name()+"����Ʈ��һʽ���ӭ�磬�������ץȥ��\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("claw",1)<30){
		write(HIR"�����Ϸ�������Ȼץס�����������������æ�ſ���\n"NOR);
 	return 1;
	}
    if ((int)me->query_skill("claw",1)>100){
		      write(HIR"���������ͣ��������жϾ���\n"NOR);
	return 1;
	}
        if ((int)me->query_skill("claw", 1) >= 30 
        && (int)me->query_skill("claw", 1) <= 100&&arg=="sheng" ){
                 if ((int)me->query("jing")<30)
               {
                me->unconcious();     
                return 0;
                 }
  
                me->receive_damage("jing", 30);
                me->improve_skill("claw", (me->query("int"))*3/2);
                write(HIR"����ס��������צ��ʹ�����ϣ�ֱ��ӥ�£���������ӥ��̬��ֻ����צ����������\n"NOR);
	return 1;
	}
}

