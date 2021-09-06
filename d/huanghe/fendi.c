inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIB"Ĺ��"NOR);
        set("long",@LONG
�ߵ�����Խ���е���������Ҷ������裬�Ĵ���������ľ���õ���ζ��û
ϥ���Ӳ�����һ�����أ�Ĺ��(bei) �������˳���������ϸ�������ѱ������
дЩʲô��Ĺǰ����ֽ�ң��������þ�û�����������ˡ�
LONG
        );
     set("no_fight", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1);
        set("dao_count",1);
        set("exits", ([
               "south"         : __DIR__"shulin6",
        ]) );
            set("quest",1);

        set("objects",([
            __DIR__"npc/hu-fei" : 1,  
        ])); 

        set("item_desc", ([ 
                "bei"||"Ĺ��"||"��":@LONG
             ________
            /        \
           /          \
          |        ��  |
          |            |
          |        ��  |
          |     ��     |
          |     һ ��  |
          |     ��     |
          |     �� ��  |
          | ��  ��     |
          | ��         |
          | ��  ֮     |
          | ��         |
          |     Ĺ     |
          |            |
LONG
        ]) );
    
       set("coor/x",70);
  set("coor/y",80);
   set("coor/z",0);
   setup(); 
}
 
void init()
{
	object me=this_player();
	if(me->query_condition("killer")||me->query_condition("job_busy"))
	{
  	 message_vision(HIC"\nͻȻ����֪�������ﴫ��һ�������������ﲻ��ӭ$N��\n"NOR,me); 
		 tell_object(me,HIR"���ţ���֪����������һֻ��ŷ���һ�ţ�����һ���߷ɳ�ȥ��\n"NOR);
		 tell_room(environment(me),HIR"\n��֪����������һֻ��ŷ���һ�ţ���"+ me->name()+ "�߷ɳ�ȥ��\n"NOR, ({ me }));
                 if(random(2)) me->move("/d/huanghe/shulin6");
		 else me->move("/d/xiangyang/damen");
		 tell_room(environment(me), HIR"\nֻ��"+ me->name()+ "���һ���ɹ�����ˤ�˸�����ʺ����˧Ŷ~~~~~~~~\n"NOR, ({ me }));
		 me->start_busy(1);
	   return;
	}
  add_action("do_wa", "wa");
}

int do_wa(string arg)
{
        object dao, me, ob;
        me = this_player();

        if( ! arg || arg != "di")
          return notify_fail("��Ҫ��ʲ�᣿\n");

        if( ob = present("hu fei",environment(me)) &&!me->query("quest/ѩɽ�ɺ�/����ƪ/over")) {
//           message_vision("$N��һ��������������$n��\n", ob,me);
           return notify_fail(CYN"��쳺ȵ�����Ҫ�����ҵ�����徲��\n"NOR"�㲻�����ж�����\n");
        }
 
        if ((int)me->query("jingli") < 500) 
           return notify_fail("��ľ�������������£�\n");  
 
        if(random(10)!=6) {
           me->add("jingli",-200);
           return notify_fail("�㿴׼��Ĺ������֮�����˾���ָ������������\n");
           }

       dao = unew("/d/huanghe/obj/lengyue-dao");

        if(!clonep(dao)){
             tell_room(environment(me), me->name() + "���˰��죬ֻŪ��һ���ࡣ\n", ({ me }));
             return notify_fail("�����˰��죬ֻŪ��һ���ࡣ\n");
        }

        if(clonep(dao) && dao->violate_unique()){
           destruct(dao);
           tell_room(environment(me), me->name() + "���˰��죬ֻŪ��һ���ࡣ\n", ({ me }));
           return notify_fail("�����˰��죬ֻŪ��һ���ࡣ\n");
        } 
        message_vision("�ڵ����ߣ�$N�е�˫����ָͬʱ����һ�������Ӳ֮�����������������һ�����ʵĵ�����\n"+
                       "$Nץס��������ѵ��������г�������г�������������⡣\n",me);
        me->add("jingli", -500);
        dao->move(me);
        return 1;
}
