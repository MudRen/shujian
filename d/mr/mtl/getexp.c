// mr getexp.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIW"������-ʵս��"NOR);
	set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ�����
�����ƺ�����θ���Ļ�ȡʵս�����йء���������������(canwu)������ݡ�
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

     if(arg != "combat")
           return notify_fail("����ֻ�ܲ���ʵս(combat)����!\n");

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_exp") )
                  return notify_fail("����æ���ء�\n");


     if( me->query("combat_exp",1)<15000000)
                 return notify_fail("����ҵķ��˷�����ϵĲ��飬������������ݸ���Ī�⣬�޷���⣬���ɵ�ҡ��ҡͷ��\n");
       
     
     if ( me->query("relife/exp_ext",1) >=20 )
                 return notify_fail("���Ѿ���ȫ������ʵս���ֲ���ľ��裬�޷�����һ���ˡ���\n");

  if (me->query_temp("canwu_now") )
       return notify_fail("����æ���ء�\n");

        if (query_temp("canwu") )
        return notify_fail("�������ڲ����أ����һ��ѡ�\n");

       message_vision( HIW"$N��ϸ�ķ���������ϵĲ��飬��������θ��õĻ�ȡʵս��������ݺܸ���Ȥ��\n"NOR,me);
        message_vision( HIW"$Nһͷ���������.��ͣ�ķ����š��� \n"NOR, me);
       me->start_busy(100);               
     me->set_temp("canwu_now",1); 
     set_temp("canwu",1);         
     call_out("thinking",5, me );
         return 1;

 }


int thinking(object me)
{
  int i, exp;
  if(!me) return 0;
	
  if(me->query_temp("con_exp")<(3+random(3)))
       {  me->add_temp("con_exp",1);
          if(random(2)) tell_object(me,HIG"\n����ϸ���ж�������������ݣ�ֻ���ö�Ŀһ��...\n"NOR);
                   else tell_object(me,HIY"\n��������Լ�������ʵս���̣�������������...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"üͷ���壬�ƺ���˼����ʲô...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_exp");
         me->start_busy(1);     
  message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
  
     tell_object(me,HIR"\n��ͨ�������ж����ɹ��Ĳ����һ��ʵս���ϣ�\n"NOR);
me->add("cw_exp",1);
       me->add("relife/exp_ext",1);
       i = me->query("relife/exp_ext",1) * 5;
       exp = 2000000;
       if(me->query("registered") == 3) exp=1800000;
       if(me->query("y-card-vip"))         exp=1700000;
       if(me->query("buyvip") )             exp=1600000; 
       me->add("combat_exp",-exp);

    tell_object(me,HBYEL"\n�㱾�β��򹲺ķ���" + HIW + chinese_number( exp ) + HIR + "ʵս���飬�����㽫��ÿ��ʵս�ж��ȡ�ٷ�֮" + HIW + chinese_number( i ) + HIR + "�ľ��飡\n"NOR);

      log_file("canwu/getexp", sprintf("%s(%s) ��%d�β���ʵս���鲿�֣���ǰ���飺%d��\n",
       me->name(1),
       me->query("id"),
       me->query("relife/exp_ext",1),
       me->query("combat_exp")) );

   me->delete_temp("canwu_now");  
delete_temp("canwu");   
   }


}


