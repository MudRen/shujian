// Room: /d/nanyang/dating.c
// Lklv Modify 2001.10.11
// Tangfeng@SJ 2004

#include <ansi.h>
inherit ROOM;

#define QUESTDIR3 "quest/�����˲�/��������ƪ/"

void xiaofeng1(object me);
void xiaofeng2(object me);
void xiaofeng3(object me);
int do_action(string arg);
int do_jiejiu(string arg);
void copy_person(object ob,int i);
void destruct_person(object ob);
void set_person(object obj1,object obj2,int i);

void create()
{
        set("short", "����ׯ����");
        set("long", @LONG
���Ǿ���ׯ�Ĵ����������ںܿ������ż�ʮ�����ӡ�������λ��������
�������Ѻ�ɫ��̫ʦ�Σ�����һ������������һ���������ӡ�������ǽ�Ϲ�
������Բ�ܡ�һ��������һ�˶�ǹ��
LONG
        );
		set("quest",1);
		set("exits", ([
		"south" : __DIR__"jxzhuang",
		"east" : __DIR__"houyuan",
	]));
	
	set("objects",([
		__DIR__"npc/youju" : 1,
		__DIR__"npc/youji" : 1,
        ]));
	
	setup();
}
void init()
{
  object me,obj;
  me = this_player();
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (me->query_temp(QUESTDIR3+"jxzhuang")) return;
  if (me->query_temp(QUESTDIR3+"help")) return;
  if (this_object()->query("busy")) 
  {
	  me->move("/d/nanyang/jxzhuang");
	  message_vision(HIR "\n$N���־���ׯ�ڴ�Խ��Խ���ң��������ۣ�������Ϊ�ϲߣ�\n" NOR, me);
	  return;
  }
  if (me->query_condition("killer")) 
  {
	  me->move("/d/nanyang/jxzhuang");
  	  message_vision(HIR "\n$N���־���ׯ�ڴ�Խ��Խ���ң��������ۣ�������Ϊ�ϲߣ�\n" NOR, me);
	  return;
  }
  me->start_busy(2);
  me->set_temp(QUESTDIR3+"jxzhuang",1);
  copy_person(this_object(),3);//����������3������������������ͨ����������npcֻ�о���  
  obj=present("xiao feng", this_object());
  tell_object(me,HIG"\n���߽������ڣ���ȻһƬ���ҡ������Ͼۼ����������ˣ���Ҽ���һ�ţ����ܰ���������ߵģ����������˶��ѣ�\n"
                      "��ǹ��������趯��һ����˵�Ҫ����Ϊ�Լ������ˡ�\n"NOR); 
  message_vision(HIR "\n$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������졣\n" NOR, obj);
  remove_call_out("xiaofeng1");
  remove_call_out("busy");
  //�������quest����
  this_object()->set("busy",1);
  call_out("busy", 1200);   
  call_out("xiaofeng1",10, me);  
  log_file("quest/TLBB", sprintf("%s(%s)����ׯ����ҿ�ʼ������%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
  add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "guard","steal","kill", "hit", "fight", "throw", "ansuan"}));  
  add_action("do_jiejiu", ({"help","bangzhu","jiejiu", "save"}));
}
void xiaofeng1(object me)
{
	object obj;
	if(!me) return;
	if (!me->query(QUESTDIR3+"start")) return;
	if (!me->query_temp(QUESTDIR3+"kill")) return;
	if (me->query(QUESTDIR3+"over")) return;
	if (me->query_temp(QUESTDIR3+"help")) return;
	if(!present(me,this_object())) 
	{
		tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
		me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
		me->delete_temp("quest/�����˲�");   
		me->delete(QUESTDIR3+"start");
		me->add("mana",-200);
		if(me->query("mana")<0) me->set("mana",0);
		destruct_person(this_object());//������������
		return;
	}
	copy_person(this_object(),1);//�����������  ,1����ҵ�ս��
	obj=present("xiao feng", this_object());
    message_vision(HIG"\n\n$N��Ȼ�˵ã������ﴦ����������������������������ȭ���أ����Ƴ�����Ⱥ����ײȭ�����������ߣ���ʱ���ִ����ˡ�\n\n"NOR, obj);
    message_vision(HIG"$N����$n��Цһ����\n\n"NOR, obj,me);
	remove_call_out("xiaofeng2");
	call_out("xiaofeng2",20, me);   
	return;
}
void xiaofeng2(object me)
{
  object obj1,obj2;
  if(!me) return;
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (me->query_temp(QUESTDIR3+"help")) return;
  if(!present(me,this_object())) 
  {
	  tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
	  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	  me->delete_temp("quest/�����˲�");   
	  me->delete(QUESTDIR3+"start");
	  me->add("mana",-200);
	  if(me->query("mana")<0) me->set("mana",0);
	  destruct_person(this_object());//������������
	  return;
  }
  copy_person(this_object(),0);//����������� ,0�����е�����ս��ֹͣ
  obj1=present("xiao feng", this_object());
  obj2=present("xuan nan", this_object());
  tell_object(me,HIY"\nһ�Ṥ�򣬴�����������仯��ȴ�������ó�һ��յأ�ֻ�����ָ�ɮ���ѻ�����ǰ����������ʮ��Χ����\n"
                      "��ľ��棬������һ���֣������Ծ����Լй��������ְ��ţ���Ȼ��Ȼ����һ���£���������Χס���Է���\n"
                      "�����ѣ�����ۿ����Ѻ�����ս��\n"NOR);                    
  message_vision(HIY"\n$NͻȻ����һ������Ŀ¶�ȹ⣬���΢Ц��������ת����ʹȫ�����±����������ǡ���ղ������񹦡���\n" NOR, obj2); 
  obj2->kill_ob(obj1);
  obj1->start_busy(3);
  obj2->start_busy(3);
  message_vision(HIR"\n$n��$N�ȵ�������������Ǭ������ֻ��$N������ӯ���������ȭ��ȴ��������׷������������־�����\n" NOR, obj1,obj2); 
  message_vision(HIW"\n$N���������������ȭ�������Σ�ʹ���޷�����ȭ����·�����������ֲ���������ȫ���ע�Ĳ���������\n"
                      "��ȭ�У�$Nʹ�������ѵ�ˮ����ǡ�ö����$n�Ĺ��ơ�\n" NOR, obj1,obj2); 
  message_vision(HIY"\n���ϣ�����֮��ȴҲ���м������������;�����$N�������һ������עһ������ȫ��������һ��֮�ڻӳ���\n" NOR,obj2);
  message_vision(HIW"\n$N������������ֻ��������ķ��ǰ������������˳��Ĵ��������Ʒ�ͬС�ɣ������ȵ���������Ǭ����\n"
                      "��Ȼ�˵ã�������һ�ƣ����������䡣$n�������㱻����$N��һ��ȴ�����۶�����ֻ�����������죬����\n"
                      "�����໥������ͻȻ�������������ʮֻ�ҵ����·��ɡ�\n" NOR, obj1,obj2); 
  tell_object(me,HIB"\n�㰵��һ�������书��������ֻ���һ�ƣ������˶��ѵĳ���������\n"NOR);  
  log_file("quest/TLBB", sprintf("%s(%s)����ׯ��������������嵥�ɡ�����%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
  remove_call_out("xiaofeng3");
  call_out("xiaofeng3",15, me);   
  return;
}
void xiaofeng3(object me)
{
  if(!me) return;
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (me->query_temp(QUESTDIR3+"help")) return;
  if(!present(me,this_object())) 
  {
	  tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
	  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	  me->delete_temp("quest/�����˲�");   
	  me->delete(QUESTDIR3+"start");
	  me->add("mana",-200);
	  if(me->query("mana")<0) me->set("mana",0);
	  destruct_person(this_object());//������������
	  return;
  }
  copy_person(this_object(),3);//����������� 
  message_vision(HIY"\n����ͻȻ����һ������Ŀ¶�ȹ⣬���΢Ц��������ת����ʹȫ�����±����������ǡ���ղ������񹦡���\n" NOR,me); 
  message_vision(HIR"\n�����ƺ��������Ƕ��֣�Ⱥ������ȫ��һӵ���ϣ�������ӻ��ң�ս��Խ��Խ�Ǽ��ң�\n" NOR,me); 
  remove_call_out("xiaofeng4");
  call_out("xiaofeng4",30, me);   
  return;
}
void xiaofeng4(object me)
{
  object obj;
  if(!me) return;
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (me->query_temp(QUESTDIR3+"help")) return;
  if(!present(me,this_object())) 
  {
	  tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
	  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	  me->delete_temp("quest/�����˲�");   
	  me->delete(QUESTDIR3+"start");
	  me->add("mana",-200);
	  if(me->query("mana")<0) me->set("mana",0);
	  destruct_person(this_object());//������������
	  return;
  }
  copy_person(this_object(),3);//����������� 
  obj=present("xiao feng", this_object());
  message_vision(HIW"\n˲��֮�ڣ�$N���������ƺ����ġ����ء��Ҽ�ͬʱ�е���������˼��������徹Ȼ����������������Ȼ����\n"
                      "��У�����ֱ�����޿��ȴ�������������ǰ���ٵ��������ؿڴ�ȥ��\n"NOR,me);
  tell_object(me,HIR"\n�㰵��һ�����������Ҫ��Ͽ�ȥ������壨jiejiu xiao feng����\n"NOR);
  log_file("quest/TLBB", sprintf("%s(%s)����ׯ�������Ҫ������塣����%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
  me->set_temp(QUESTDIR3+"can_be_help",1);
  remove_call_out("xiaofeng5");
  call_out("xiaofeng5",10, me); 
  remove_call_out("xiaofeng_over");
  call_out("xiaofeng_over",120, me);  
  return;
}
void xiaofeng5(object me)
{
  if(!me) return;
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (me->query_temp(QUESTDIR3+"help")) return;
  if (!me->query_temp(QUESTDIR3+"can_be_help")) return;
  if(!present(me,this_object())) 
  {
	  tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
	  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	  me->delete_temp("quest/�����˲�");   
	  me->delete(QUESTDIR3+"start");
	  me->add("mana",-200);
	  if(me->query("mana")<0) me->set("mana",0);
	  destruct_person(this_object());//������������
	  return;
  }
  copy_person(this_object(),3);//����������� 
  tell_object(me,HIR"\n��Ͽ�ȥ������壨jiejiu xiao feng�������𷢴��ˣ�\n"NOR);
  remove_call_out("xiaofeng5");
  call_out("xiaofeng5",10, me); 
  return;
}
void xiaofeng_over(object me)
{
  if(!me) return;
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (me->query_temp(QUESTDIR3+"help")) return;
  if (!me->query_temp(QUESTDIR3+"can_be_help")) return;
  if(!present(me,this_object())) 
  {
	  tell_object(me,HIG"\n�����������Ȼ�������ѣ�ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
	  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	  me->delete_temp("quest/�����˲�");   
	  me->delete(QUESTDIR3+"start");
	  me->add("mana",-200);
	  if(me->query("mana")<0) me->set("mana",0);
	  destruct_person(this_object());//������������
	  return;
  }
  tell_object(me,HIC"\nͻȻһ�������˴Է�����������һ������������ȥ���Ƶ��漱���������ڵ����ĸֵ�֮�ϡ��ֵ�˳����ء����е�ʱ��\n"
                      "�ң�Ⱥ�۾������¡�������˳�ּ������һ�ų���������һ˦����Ⱥ�۷׾ٱ��е���֮�ʣ���ͷ��ת������������һ����\n"
                      "�漴���𡣺��������ֵ�ת����������˾������һ�������һ����������̼�Խ������������������ں�Ժ��\n"NOR);
  tell_room(environment(me),HIC"\nͻȻһ����Ӱ������ȴ�������Ѿ��赹�ڵأ��������ڿն�������ϸ��ʱ�����Ѿ����ں�Ժ֮�С�\n"NOR, ({}));                       

  tell_object(me,HIG"\n�����������Ȼ���Ҿ�Ԯ��ʵ��Υ������֮�顣��Ľ�����������½���\n"NOR); 
  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
  me->delete_temp("quest/�����˲�");   
  me->delete(QUESTDIR3+"start");
  me->add("mana",-200);
  if(me->query("mana")<0) me->set("mana",0);
  log_file("quest/TLBB", sprintf("%s(%s)����ׯ�����û�н�����壬����ʧ�ܡ�����%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
  destruct_person(this_object());//������������
  return;
}

int do_jiejiu(string arg)
{
  object obj,room,me;
  me = this_player();
  if (!me->query(QUESTDIR3+"start")) return 0;
  if (!me->query_temp(QUESTDIR3+"kill")) return 0;
  if (me->query(QUESTDIR3+"over")) return 0;
  if (me->query_temp(QUESTDIR3+"help")) return 0;
  if(!arg) return 0;
  if(arg!="xiao feng" && arg!="xiao")
  {
      tell_object(me,HIR"\nû����������ȡ�\n"NOR);
	  return 1; 
  }
  if (!me->query_temp(QUESTDIR3+"can_be_help"))
  {
      tell_object(me,HIR"\n������ʱ�򣬲���Ҫ���ȣ����������Լ�Ӧ����\n"NOR);
	  return 1; 
  }
  if(!(obj=present("xiao feng", environment(me))))
  {
      copy_person(this_object(),3);
  }
  obj=present("xiao feng", environment(me));
  obj->set("qi", obj->query("max_qi")/3);
  obj->set("eff_qi", obj->query("max_qi")/3);
  obj->set("jing", obj->query("max_jing"));
  obj->set("eff_jing", obj->query("max_jing"));
  obj->add("neili", obj->query("max_neili")*2);
  obj->set("jingli", obj->query("max_jingli"));
  if(obj->is_busy()) obj->start_busy(-1);	  
 
  tell_object(me,HIC"\n�㰵��һ�������������һ���������Ƶ��漱���������ڵ����ĸֵ�֮�ϡ��ֵ�˳����ء����е�ʱ���ң�\n"
                      "Ⱥ�۾������¡���˳�ּ������һ�ų���������һ˦����Ⱥ�۷׾ٱ��е���֮�ʣ���ͷ��ת������������һ����\n"
                      "�漴���������ֵ�ת����������˾������һ�������һ����������̼�Խ������������������ں�Ժ��\n"NOR);
  tell_room(environment(me),HIC"\nͻȻһ����Ӱ������ȴ�������Ѿ��赹�ڵأ��������ڿն�������ϸ��ʱ�����Ѿ����ں�Ժ֮�С�\n"NOR, ({}));                       
  if (!(room = find_object("/d/nanyang/houyuan")))
      room = load_object("/d/nanyang/houyuan");
  if(room)
  {
  	me->move(room);  
  	obj->move(room);
    tell_object(me,HIR"\n�������˦����������Զ����������˼������䣬��Ȼ�ߵ���Ӱ���١�\n"NOR);
  }
  else 
  {
	  destruct_person(this_object());//������������
	  tell_object(me,HIR"\n�������˦����������Զ����������˼������䣬��������ԭ�أ���\n"NOR);
	  me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	  me->delete_temp("quest/�����˲�");   
	  log_file("quest/TLBB", sprintf("%s(%s)����ׯȱ��houyuan.c�ļ���\n", me->name(1),me->query("id")) );
	  return 1;
  }
  if (!(room = find_object("/d/nanyang/duanya2")))
      room = load_object("/d/nanyang/duanya2");
  if(room)
  {
    tell_room(environment(me),HIC"\n"+me->name()+"��һ˦����������Զ����������˼������䣬��Ȼ�ߵ���Ӱ���١�\n"NOR, ({}));                       
  	me->move(room);  
  	obj->move(room);
    tell_object(me,HIG"\n������׷��׷�ϣ������߹������ط���������һ�����±�ͣס��\n"NOR);
  }
  else 
  {
    destruct_person(this_object());//������������
	me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	me->delete_temp("quest/�����˲�");   
    tell_object(me,HIR"\n�������˦����������Զ����������˼������䣬��������ԭ�أ���\n"NOR);
	log_file("quest/TLBB", sprintf("%s(%s)����ׯȱ��duanya2.c�ļ���\n", me->name(1),me->query("id")) );
    return 1;
  }
  log_file("quest/TLBB", sprintf("%s(%s)����ׯ����ҳɹ�������塣����%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
  me->set_temp(QUESTDIR3+"help",1);
  destruct_person(this_object());//������������
  return 1;
}
void busy()
{
	this_object()->delete("busy");
	return;
}
int do_action(string arg)
{
	this_player()->start_busy(1);
   	tell_object(this_player(),HIR"\n����Ҫ����������ͻȻ�о�����̫�����ң����ǰ����úã�\n");
   	return 1;
}
int valid_leave(object me, string dir)
{
     if (present("xiao feng", environment(me)))
           return notify_fail(HIR"�������˴��е�Ŀ�ģ����ܲ��������ˣ����Ǿ�����䣡\n"NOR);
     return ::valid_leave(me, dir);
}
void copy_person(object ob,int i)
{
	object obj1,obj2;
	//�������
  if(!(obj1=present("xiao feng", ob))) 
  {
 	   obj1=new(__DIR__"npc/xiaofeng");
    obj1->set("no_death",1);
     obj1->move(ob); 
  }
    obj1->set("no_death",1);
  obj1->remove_all_killer(); 
  //���ؤ�����ɳ����
  if(!(obj2=present("wu zhanglao", ob))) 
  {
 	   obj2=new(__DIR__"npc/gbdizi");
		 obj2->set_name("�ⳤ��", ({ "wu zhanglao", "wu","zhanglao"}) );
		 obj2->set("title",HIB"ؤ�ﳤ��"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); //����ս������ֹͣս��,0 ֹͣս����1ս����2ս����ֻ��������3ս��ֻ��xiao feng ����ͨ��
  if(!(obj2=present("song zhanglao", ob))) 
  {
 	   obj2=new(__DIR__"npc/gbdizi");
		 obj2->set_name("�γ���", ({ "song zhanglao", "song","zhanglao"}) );
		 obj2->set("title",HIM"ؤ�ﳤ��"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("xi zhanglao", ob))) 
  {
 	   obj2=new(__DIR__"npc/gbdizi");
		 obj2->set_name("�ɳ���", ({ "xi zhanglao", "xi","zhanglao"}) );
		 obj2->set("title",HIC"ؤ�ﳤ��"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("chen zhanglao", ob))) 
  {
 	   obj2=new(__DIR__"npc/gbdizi");
		 obj2->set_name("�³���", ({ "chen zhanglao", "chen","zhanglao"}) );
		 obj2->set("title",HIY"ؤ�ﳤ��"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("bai shijing", ob))) 
  {
 	   obj2=new(__DIR__"npc/gbdizi");
		 obj2->set_name("������", ({ "bai shijing", "bai"}) );
		 obj2->set("title",HIC"ִ������"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  //����������ȡ�����
  if(!(obj2=present("xuan nan", ob))) 
  {
 	   obj2=new(__DIR__"npc/sldizi");
		 obj2->set_name("����", ({ "xuan nan", "xuan","nan"}) );
		 obj2->set("title",HIY"���ֳ���"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("xuan ji", ob))) 
  {
 	   obj2=new(__DIR__"npc/sldizi");
		 obj2->set_name("����", ({ "xuan ji", "xuan","ji"}) );
		 obj2->set("title",HIY"���ֳ���"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 

  //��ӵ���̷��̷����Ǯ��
  if(!(obj2=present("shan zheng", ob))) 
  {
 	   obj2=new(__DIR__"npc/otherdizi");
		 obj2->set_name("����", ({ "shan zheng", "shan","zheng"}) );
		 obj2->set("title",HIB"�����й�"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("tan po", ob))) 
  {
 	   obj2=new(__DIR__"npc/otherdizi");
		 obj2->set_name("̷��", ({ "tan po", "tan","po"}) );
		 obj2->set("title",HIY"̫��ɽ������"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("tan gong", ob))) 
  {
 	   obj2=new(__DIR__"npc/otherdizi");
		 obj2->set_name("̷��", ({ "tan gong", "tan","gong"}) );
		 obj2->set("title",HIY"̫��ɽ������"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  if(!(obj2=present("zhao qianli", ob))) 
  {
 	   obj2=new(__DIR__"npc/otherdizi");
		 obj2->set_name("��Ǯ��", ({ "zhao qianli", "zhao"}) );
		 obj2->set("title",HIG"��¿��"NOR);
     obj2->move(ob); 
  }
  set_person(obj1,obj2,i); 
  //������ӽ���  
  return;	
}
void set_person(object obj1,object obj2,int i)
{
  if(!obj1) return;
  if(!obj2) return;
  //obj1������
  if(i>0) obj2->kill_ob(obj1);
  else obj2->remove_all_killer(); 
  if(i==2) 
  {
	  obj1->set_temp("no_fight",1);
	  obj2->set_temp("no_fight",1);
  }
 if(i==3) 
  {
	  obj1->delete_temp("no_fight");
	  obj2->set_temp("no_fight",1);
  }
  if(i==4) 
  {
	  obj2->delete_temp("no_fight");
	  obj1->set_temp("no_fight",1);
  }
  return;
}
void destruct_person(object ob)
{
	object obj;
	if((obj=present("xuan nan", ob))) 
	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("xiao feng", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("xuan ji", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("wu zhanglao", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("xi zhanglao", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("song zhanglao", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("chen zhanglao", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("bai shijing", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("shan zheng", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("tan gong", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("tan po", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  if((obj=present("zhao qianli", ob))) 	{
    message_vision(HIR"$N���˸���������Ȼ�߿��ˡ�\n" NOR, obj);
		destruct(obj);
  }
  return;
}
