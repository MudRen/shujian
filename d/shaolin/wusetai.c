// /d/mingjiao/bishui.c
// Jay 4/3/97 -qingyun
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIG"��ɫ̨"NOR);
       set("long", @LONG
��������ɫ��ʦ����̨�ڲ�������ʮ�ֿտ���������һ���鰸(lingan)��
���顰���Ӷ�Ӧ���ĸ����֣�������ɫ��ʦ��ǰ�������顣�����پ�������
��չ��ͬһ�׼�������ȭ������Ȼ�����ң���ȴ������̨һƬ����������
��â���ĵ׷�����
LONG
     );
    
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));             
        setup();
}
void init()
{
	add_action("do_study","study");
}
int do_study(string arg)
{
	object me;
	me=this_player();
	if (arg!="lingan") return 0;
	if (!living(me)) return 0;
        message("vision", me->name()+"����ר�ĵ�ѧϰ�鰸�ϵ��鷨��\n",
        environment(me), ({me}) );
      if ((int)me->query_skill("cuff",1)<30){
		write(HIR"�㿴�Ű��ϵ��鷨�������������򣬵��Ͼ�ȭ����Ϊ��ǳ��ʲôҲû���򵽡�\n"NOR);
 	return 1;
	}
	if ((int)me->query_skill("cuff",1)>100){
		      write("���Ѿ�������͸�˰����鷨�ĺ��塣\n");
	return 1;
	}
        if ((int)me->query_skill("cuff", 1) >= 30 
        && (int)me->query_skill("cuff", 1) <= 100&&arg=="lingan" ){
                 if ((int)me->query("jing")<30)
               {
                me->unconcious();     
                return 0;
                 }
  
                me->receive_damage("jing", 30);
                me->improve_skill("cuff", (me->query("int"))*3/2);
                write("�㿴�Ű����Ǳ������߰�Ĵ��֣����жԻ���ȭ����������\n");
	return 1;
	}
}

