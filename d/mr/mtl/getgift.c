// mr getgift.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"������-�츳��"NOR);
	set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ�����
�����ƺ�������ζ����츳���(gift)�йء�
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}




void init()
 {
         add_action("do_canwu", "canwu"); 
         add_action("do_canwu", "yandu");
 }



int do_canwu(string arg)
 {
     object me = this_player();

     if(arg != "gift" )
           return notify_fail("����ֻ�ܲ����츳(gift)����!\n");

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_gift") )
                  return notify_fail("����æ���ء�\n");

if (me->query_temp("canwu_now") )
       return notify_fail("����æ���ء�\n");

        if (query_temp("canwu") )
        return notify_fail("�������ڲ����أ����һ��ѡ�\n");


     if( me->query("combat_exp",1)<20000000)
                 return notify_fail("����ҵķ��˷�����ϵĲ��飬������������ݸ���Ī�⣬�޷���⣬���ɵ�ҡ��ҡͷ��\n");
       

       message_vision( HIW"$N��ϸ�ķ���������ϵĲ��飬��������ν���ǿ���츳���ǵ����ݺܸ���Ȥ��\n"NOR,me);
        message_vision( HIW"$Nһͷ���������.��ͣ�ķ����š��� \n"NOR, me);
       me->start_busy(100);               
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
     call_out("thinking",5, me );
         return 1;

 }


int thinking(object me)
{
  int i,exp,j, total;
  
 
 if(!me) return 0;
total = me->query("relife/gifts/total");
 if(me->query_temp("con_gift")<(3+random(3)))
       {  me->add_temp("con_gift",1);
          if(random(2)) tell_object(me,HIG"\n����ϸ���ж�������������ݣ�ֻ���ö�Ŀһ��...\n"NOR);
                   else tell_object(me,HIY"\n���ж��������й�ǿ���츳���ǵķ��ţ�������������...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"üͷ���壬�ƺ���˼����ʲô...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_gift");
         me->start_busy(1);     
  message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
  tell_object(me,HIR"\n��ͨ�������ж����ɹ��Ļ��һ�������츳������\n"NOR);

if(me->query("relife/relifed")) total = total -10;

 CHANNEL_D->do_channel(this_object(), "rumor", HIC"��˵" + me->name(1) + "��"HIM"�ŋ���"HIC"�����˵�"HIR + chinese_number(total+1)+ HIC"���츳ǿ����\n"NOR);
       me->add("relife/gifts/total",1);
       me->add("relife/gifts/now",  1);        

       exp = 2000000;
       if(me->query("registered") == 3) exp=1800000;
       if(me->query("y-card-vip"))         exp=1700000;
       if(me->query("buyvip") )             exp=1600000; 
       me->add("combat_exp",-exp);

    
       i = me->query("relife/gifts/now",1); 
       j = me->query("relife/gifts/total",1);
   
    tell_object(me,HBYEL"\n�㱾�β��򹲺ķ���" + HIW + chinese_number( exp ) + HIR + "ʵս���飬�������ܹ���" + HIW + chinese_number( i ) + HIR + "�Ķ�����츳��\n"NOR);
    tell_object(me,HBRED"\n������ʹ��(addgift)���з��䣡\n"NOR);

      log_file("canwu/getexp", sprintf("%s(%s) ��%d�β����츳���֣���ǰ���飺%d��\n", 
       me->name(1),
       me->query("id"),
       me->query("relife/gifts/total",1),
       me->query("combat_exp")) );
  me->delete_temp("canwu_now");   
 delete_temp("canwu");   
   }

if(total < 0)
{
 CHANNEL_D->do_channel(this_object(), "rumor", HIM"��˵" + me->name(1) + "��Ϊ"HIR"�츳�쳣"NOR"�����⣬���뵽С���ݺȲ裡\n"NOR);
 me->move("d/wizard/xhw");
}

}

