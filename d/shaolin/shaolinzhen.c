//add by tangfeng@SJ 2004

inherit ROOM;
#include <ansi.h>

int do_action(string arg);
int do_leave(string arg);
int do_stop(string arg);
int do_start(string arg);
int do_full(string arg);
void start(object me);
void rule(object me);
void copy_person(object me);
void destruct_person(object ob);
void destruct_book(object ob);
int do_eat(string arg);

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

string* anhao = ({"ά","��","Ħ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��",
                  "��","��","��","��","��","��","��","��","��","ɳ","��","��","��","��","��","��","˵","��","��","��","��","��","��",
                  "��","��","��","��","��","��","��","��","��","��","��","��","��","һ","��","��","��","��","��","��","��","��","��",});

void create()
{
	set("short",HIW "������" NOR);
	set("long", @LONG
����һƬ�ճ��أ��ĽǷֱ�վ���ĸ����ֵ��ӡ�һ�Ƿ��Ÿ������ܡ�
LONG);
  set("no_get_from", 1); 
  set("quest", 1);
  set("no_sleep_room", 1);
	setup();
}
void init()
{
  object me;
  me = this_player();
  if(me->query_condition("killer"))
  {
   message_vision(HIC"\nͻȻ$N�ƺ���Ѫ��Щ��˳������һ����������ȥ��\n"NOR,me); 
   tell_object(me,HIR"��ͻȻ�е�һ�������������㣬˲����ʧȥ֪����\n"NOR);
   tell_room(environment(me),HIR"\nֻ��������ͻȻ����һ���Ѷ���"+ me->name()+ "һͷ������ȥ��˲����ʧ��\n"NOR, ({ me }));
   if(me->query(QUESTDIR3+"bad"))  me->move("/d/shaolin/smdian");
   else if(me->query(QUESTDIR3+"good"))  me->move("/d/shaolin/fzjs2");
   else me->move("/d/xiangyang/damen"); 
   tell_room(environment(me), HIR"\n����У��ƺ�һ���˵����������㶨��һ����Ȼ��"+ me->name()+ "��\n"NOR, ({ me }));
   message_vision(HIC"$N�������۾��������ƺ���һ���Σ�����ʲô��û������\n"NOR,me); 
   return;
  }
	add_action("do_full", ({"full"}));
  add_action("do_eat",({"eat","drink"}) );
	add_action("do_leave", ({"leave"}));
	add_action("do_start", ({"start"}));
	add_action("do_stop", ({"stop"}));
  add_action("do_action", ({"lian", "learn", "tu", "steal","kill", "guard","beg", "hit", "steal", "fight", "throw", "ansuan"}));   
//remove_call_out("rule")
	call_out("rule",2,me);
}
int do_eat(string arg)
{
     object me = this_player();
     if (me->query("food") < me->query("str")*3+50){
          message_vision(HIC"$N��������Щ���Ӽ�����������һ��ɮ�ˣ��͸�$NһЩ���ˡ�\n"NOR, me);
          message_vision(HIC"$Nˬ��ش��һ�٣����ְ�ʣ��ķ��˶��˳�ȥ��\n"NOR, me);
          me->add("food", me->query("str")*10+100, me);
          return 1;
     }
     else
     if (me->query("water") < me->query("str")*3+50)
     {
          message_vision(HIC"$N��������Щ�����ʣ���������һ��ɮ�ˣ��͸�$Nһ��ˮ����\n"NOR, me);
          message_vision(HIC"$N���˹��˺���һ��ڣ����ְ�ˮ�����˳�ȥ��\n"NOR, me);
          me->add("water", me->query("str")*10+100, me);
          return 1;
     }
     else  return notify_fail("���̫���ˣ���̫���ˣ����³�����\n");
}

int do_leave(string arg)
{
		object ob,obj,me;
		ob=this_object();
		me = this_player();
		if(me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && !me->query_temp(QUESTDIR5+"shaolinzhen"))
		{
			message_vision(HIC"$N�����뿪���ȴ����һ���������������ӷ�ʩ��������\n"NOR, this_player());
			return 1;
	  }
		if(me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && me->query_temp(QUESTDIR5+"shaolinzhen"))
         message_vision(HIC"$N����ؿ��˿��Ľǵ�ɮ�ˣ�����һ���������뿪"+environment(me)->query("short")+"��\n"NOR, this_player());
    else message_vision(HIC"$N�Ҵ��뿪"+environment(me)->query("short")+"��\n"NOR, this_player());
    destruct_book(ob);
    destruct_person(ob);
    tell_room(environment(me),HIR"\nֻ��������ͻȻ����һ���Ѷ���"+ me->name()+ "һͷ������ȥ��˲����ʧ��\n"NOR, ({me}));
		if(me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && me->query_temp(QUESTDIR5+"shaolinzhen"))
        me->move("/d/shaolin/smdian");
    else if(me->query(QUESTDIR3+"good"))  me->move("/d/shaolin/fzjs2");
    else me->move("/d/xiangyang/damen"); 
    tell_room(environment(me),HIR"\nֻ��������ͻȻ����һ���Ѷ���"+ me->name()+ "�����ڷ���֮�С�\n"NOR, ({me}));
	message_vision(HIC"$N�Ҵҵ�����"+environment(me)->query("short")+"��\n"NOR, me);
    if(me->query(QUESTDIR3+"good") && me->query_temp(QUESTDIR4+"shaolinzhen") && me->query_temp(QUESTDIR4+"dagouzhen"))
		{
      if(!(obj=present("xuanci dashi", environment(me)))) 
	    {
        obj=new("/kungfu/class/shaolin/xuan-ci");
        obj->move(environment(me));
        message_vision(HIC"$N�Ҵҵ����˹�������ɫ��Щ���š�\n"NOR, obj);
      }
      me->set_temp(QUESTDIR4+"anhao",anhao[random(sizeof(anhao))]+anhao[random(sizeof(anhao))]+anhao[random(sizeof(anhao))]+
                                     anhao[random(sizeof(anhao))]+anhao[random(sizeof(anhao))]);
       message_vision(HIC"$N��$n���˵�ͷ����ϲ$n���������󷨡�\n"NOR, obj,me);
       tell_object(me,obj->name()+"����Ķ�������˵����������Ȼ��"+me->query("family/master_name")+"����"+me->query("family/family_name")+"���֣�ȷʵ�书�˵á�\n"NOR);
       tell_object(me,obj->name()+"����Ķ�������˵�������˵�������Ǿ���Ӫ��������Ϊ�ǡ���ҹ����������Ħ�½�ʱ����ؤ����ӽ�Ӧ��\n"NOR);
       tell_object(me,obj->name()+"����Ķ�������˵����ע��һ���ǰ�ҹʱ�̣����⣬������Ҫ���Ž�Ӧ�������ǡ�"+me->query_temp(QUESTDIR4+"anhao")+"����\n"NOR);
       message_vision(HIC"$N��$n����$n�����е���׳ʿ�����ͣ�\n"NOR, obj,me);
       me->set(QUESTDIR+"time",time());
	  }
	  return 1;
}
int do_stop(string arg)
{
		object me = this_player();
		if(!me->is_fighting()) return 0;
	  if(!me->query_temp(QUESTDIR4+"shaolinzhen")&& !me->query_temp(QUESTDIR5+"shaolinzhen"))  message_vision(HIC"\n$N�е��Լ���Щ�������ģ�������ʱ��ֹ�󷨡�\n"NOR, this_player());
    else   message_vision(HIC"\n$N��Щ�湻�ˣ������ֹͣս����\n"NOR, this_player());
    tell_object(me,HIR"\nͻȻ��е�һ����������ڷ���֮�У�˫����������ֹͣս����\n"NOR);
    tell_room(environment(me),HIR"\nͻȻ��о�һ����������ڷ���֮�У�˫����������ֹͣս����\n"NOR, ({ me }));
    me->remove_all_killer();   
    destruct_person(this_object());
    return 1;
}
int do_start(string arg)
{
		object me = this_player();
    if(me->is_fighting()) return 0;
	  if((present("shaolin dizi", this_object()))) 
	  {
	  	tell_object(me,HIR"���Ѿ�������\n"NOR);
	    return 1;
	  }
    if(this_object()->query("busy")) 
    {
      tell_object(me,HIR"��΢��Ϣһ�£�����������������\n"NOR);
      return 1;
    }
    destruct_book(this_object());
	  if(!me->query_temp(QUESTDIR4+"shaolinzhen")&& !me->query_temp(QUESTDIR5+"shaolinzhen"))  message_vision(HIC"$N�������Դ�һ���������󷨣������뿪���\n"NOR, this_player());
    else   message_vision(HIC"$N�����ٴδ�һ���������󷨡�\n"NOR, this_player());
    tell_object(me,HIR"ͻȻ��е�һ����������ڷ���֮�У��㾫����һ��\n"NOR);
    me->remove_all_killer();   
    destruct_person(this_object());
	  remove_call_out("start");
    remove_call_out("busy");
    call_out("busy",120);
    this_object()->set("busy",1);
	  call_out("start",4,me);
    return 1;
}
void busy()
{
  this_object()->delete("busy");
  return;
}
int do_full(string arg)
{
		object me = this_player();
    if(me->is_fighting()) return 0;
    if(me->is_busy()) return 0;
    if(me->query("eff_qi")>=me->query("max_qi") && me->query("eff_jing")>=me->query("max_jing")) return 0;
    
    //����
    if(me->query("eff_qi")<me->query("max_qi"))
    {
      me->set("eff_qi",me->query("max_qi"));
      tell_object(me,HIR"ͻȻ��е�һ����������ڷ���֮�У�������ƾ�Ȼ������롣\n"NOR);
    }
    //�ƾ�
    if(me->query("eff_jing")<me->query("max_jing"))
    {
      me->set("eff_jing",me->query("max_jing"));
      tell_object(me,HIR"ͻȻ��е�һ����������ڷ���֮�У���ľ�Ѫ��ȫ�ָ���\n"NOR);
    }
    me->remove_all_killer();   
    destruct_person(this_object());
    tell_room(environment(me),HIR"ͻȻ��о�һ����������ڷ���֮�У�ԭ��"+me->name()+"�����к��������ˣ�\n"NOR, ({ me }));
    return 1;
}
void start(object me)
{
  if(!me) return;
  if(!present(me,this_object())) 
  {
  	tell_object(me,HIR"���岻�������û�����Ӿ��߿�������Ҳ�ܵ�̫���˵㡣\n"NOR);
  	return;
  }	
  message_vision(HIC"$N��������\n"NOR, me);
  message_vision(HIC"һ�ᣬ�ӽ����ﻺ�����߳��ĸ�ɮ�ˣ����Ž�����ģ����ƶ�����ʮ���⣡\n"NOR, me);
  copy_person(me);
  return;
}
void rule(object me)
{
	object obj;
  if(!me) return;
  if(!present(me,this_object())) 
  {
  	tell_object(me,HIR"���岻�������û�����Ӿ��߿�������Ҳ�ܵ�̫���˵㡣\n"NOR);
  	return;
  }	
  if(me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && !me->query_temp(QUESTDIR5+"shaolinzhen"))
  {
    if(!(present("shu", this_object())))
    {
       obj=new("/d/shaolin/obj/fojing1");
       obj->move(environment(me)); 
       message_vision(YEL"\n��ž����һ����һ��"+obj->query("name")+"����$N��ǰ��\n"NOR,me);
         obj=new("/d/shaolin/obj/fojing2");
       obj->move(environment(me)); 
       message_vision(YEL"��ž����һ������һ��"+obj->query("name")+"����$N��ǰ��\n"NOR,me);
    }
   message_vision(HIC"\nֻ��һ�������Ե���ʩ��ɱ��̫�أ����߽���ֻ�µ�����һƬ�ȷ�Ѫ�꣬���Ǵ�������Ǳ�����ҷ�Ϊ�ϣ�\n"NOR,me);
   message_vision(HIC"�������𾭿����������ԣ�������������ʵ���ʩ���ܹ��������У�������书��Ϊ��ʵҲ�Ǵ��а����ģ�\n"NOR, me);
  }
    tell_object(me,HIY"\nҪ�뿪����ֻ��Ӳ�������������ʹ�ã�\n"
                       +"�����󷨣�start������ֹ�󷨣�stop�����뿪���䣨leave�����ָ��Լ���full����\n"
                  +HIR"\n��֮�У��������Ŀ��ܣ��뼰ʱ��ֹ�󷨣�\n\n"NOR);
  return;
}
int do_action(string arg)
{
	 if(wizardp(this_player())) return 0;
   tell_object(this_player(),HIR"����Ҫ����������ֻ��һ�������������Ҷ���\n");
   return 1;
}
void copy_person(object me)
{
	object obj1,obj2;
	int i;
  //teamleader
  if(!me) return;
  obj1=new(__DIR__"npc/dizi");
  obj1->set("teamleader",1);
  obj1->set("party","sl");
  obj1->set("fight_id",me->query("id"));
  obj1->move(environment(me)); 
  for( i = 0; i <3;i++)
  {
    obj2=new(__DIR__"npc/dizi");
    obj2->set("party","sl");
    obj2->set("fight_id",me->query("id"));
    obj2->move(environment(me)); 
  }
}
void destruct_person(object ob)
{
	object obj;
	int i;
  for( i = 0; i <4;i++)
  {
	  if(!(present("shaolin dizi", ob))) return;
    obj=present("shaolin dizi", ob);
    if(!random(3)) message_vision(HIR"$N���˵�ͷ��������ʧ�ڽ����\n" NOR, obj);
    else message_vision(HIR"$N��������ţ����������˳�ȥ��\n" NOR, obj);
		destruct(obj);
  }
}
void destruct_book(object ob)
{
	object obj;
	int i;
  for( i = 0; i <2;i++)
  {
	  if(!(present("shu", ob))) return;
    obj=present("shu", ob);
    if(random(2)) message_vision(HIR"һ������$NƮ�ڷ����ȥ�ˡ�\n" NOR, obj);
    else message_vision(HIR"һ�Σ�$N��ȻҲ������ʧ�ˡ�\n" NOR, obj);
		destruct(obj);
  }
}
