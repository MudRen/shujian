//by tangfeng@SJ 8/2004


inherit F_MASTER;
inherit NPC;
#include <ansi.h>

#define QUESTDIR1 "quest/ѩɽ�ɺ�/��ҳ����ƪ/"
#define QUESTDIR2 "quest/ѩɽ�ɺ�/����ƪ/"
#define QUESTDIR3 "quest/ѩɽ�ɺ�/��ҩƪ/"

void kill_player(object me);
void unconcious();
void die();
void kill_ob(object me);
int do_hit(string arg);
int ask_hufei();
int ask_qixinghaitang();
int ask_liangyedaofa();
int ask_hujiadaofa();
int ask_biwu();
int ask_miaorenfeng();
int ask_huyidao();
int ask_tian();
int ask_xiadu();
int ask_cheng();
int power_condition(object me,object ob,int p);
int start_condition(object ob);

void create()
{
	set_name("�ֻ�", ({ "yan ji", "yan", "ji" }) );
	set("gender", "����" );
	set("title", RED"��������"NOR);
	set("age", 51);
	set("long", 
	    "���ҽ���������ö�������͸¶��һ˿��թ��\n");
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("per", 15);
	set("shen_type", -1);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("cuff",300); 
	set_skill("taxue-wuhen",300);
	set_skill("zhentian-quan",300);
	set_skill("blade",150); 
	set_skill("hujia-daofa",150); 
	set_skill("huagong-dafa",150); 
	map_skill("force","huagong-dafa");
	map_skill("blade","hujia-daofa");
	map_skill("parry","hujia-daofa");
	map_skill("cuff","zhentian-quan");
	map_skill("dodge","taxue-wuhen");
  prepare_skill("cuff", "zhentian-quan");
	set("combat_exp", 300000);
	set("max_qi", 30000);
	set("max_jing", 10000);
	set("eff_jingli",10000);
	set("max_neili", 21000);
	set("qi",30000);
	set("jing",10000);
	set("jingli",10000);	
	set("neili", 42000);
  set("no_get",1);
  set("no_bark",1);
	set("inquiry", ([
		"��һ��" : (: ask_huyidao :),
		"���˷�" : (: ask_miaorenfeng :),
		"���ũ" : (: ask_tian :),
		"������" : (: ask_tian :),
		"����" : (: ask_biwu :),
		"����" : (: ask_biwu :),
		"20��ǰ" : (: ask_biwu :),
		"����" : (: ask_biwu :),
		"���" : (: ask_hufei :),
		"���Ǻ���" : (: ask_qixinghaitang :),
		"��ҳ����" : (: ask_liangyedaofa :),
		"���ҵ���" : (: ask_hujiadaofa :),
		"����"   : (: ask_xiadu :),
		"�¶�"   : (: ask_xiadu :),
    "������" : (: ask_cheng :),
	]));
	setup();
	set("chat_chance", 2);
	set("chat_msg", ({
		"�ֻ���һ�����о޶����߷�����¨����ٺ١��ļ�Ц������\n",
		"�ֻ�������һ�ۣ�����˵��������Ƽ��ݣ���ˮ���գ��Ƿ񣮣������ȣ�\n",
	}) );
	carry_object("/clone/armor/cloth.c")->wear();
}
 
void init()
{
	::init();
	add_action("do_hit","hit");
}


int ask_biwu() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("sigh "+me->query("id"));
	  command("say �����ҵ��£������ҵ��°������ǡ����ũ��ָʹС�˸ɵ�......");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  command("sigh");
	  command("say 20��ǰ�ı��䣬��ʵ��Ҳ���Ǻ����ף����Ǻ������������˷����ϣ�ȷ����ʵ��");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"over"))
  {
	  command("consider");
	  command("say ��������͵�������ؼ���ֻ�ǵ�ʱһƬ���ң���ȫ�ұ��٣���Ҳ��Ϊ�����ƣ�����������");
  	command("say ���Ǻ���������������죬��ϧС�����˷ﾹȻʹ�ö�������ι�����������Ҫȥ���ġ�");
	  return 1;
  } 
	command("heng");
	command("say ����������������죬��ϧС�����˷ﾹȻʹ�ö�������ι�����������Ҫȥ���ġ�");
	return 1;
}

int ask_tian() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("fear "+me->query("id"));
	  command("say ���ǡ����ũ��ָʹС�˸ɵ�......����ɱ�ı���С�ˣ�");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  command("sigh");
	  command("say ���๫��ԭ�����������ţ�������������ڼ䣬��������һ�棬���һֱû����Ϣ��������Ҳ�ƺ��𼣽�����");
	  return 1;
  } 
	command("en");
	command("say ������������ڼ䣬�Һ������һ�棬��ʱ����úܡ��������������Ѷ�����Ǻ���Ϥ��");
	return 1;
}

int ask_miaorenfeng() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"start"))
  {
	  command("fear "+me->query("id"));
	  command("say �ң��ң����������ɺã�...���ǡ����ũ��ָʹС�˸ɵ�......����ɱ�ı���С�ˣ�");
	  return 1;
  } 
  command("sigh");
	command("say ��������ܾ�û�����������ټ��ˣ�20��ǰ�й�һ����ѡ�");
	return 1;

}
int ask_cheng() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("fear "+me->query("id"));
	  command("say �̹��ﻹ���嶾�̰ɣ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"qixinghaitang"))
  {
	  command("fear "+me->query("id"));
	  command("say �̹����ɱ�ң���ʲô������ȥ�ˣ���˵��Ҳ˵�ˣ������Ұɣ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"jieyao2"))
  {
	  command("fear "+me->query("id"));
	  command("say �̹����ɱ�ң���ʲô������ȥ�ˣ���˵��Ҳ˵�ˣ������Ұɣ�");
	  return 1;
  }
  if(me->query(QUESTDIR3+"start"))
  {
	  command("fear "+me->query("id"));
	  command("say ��Ѿͷ������ʲô��ϵ��");
	  return 1;
  }  
  command("nod");
	command("say ��˵ҩ�������Ĺ��ŵ��ӣ����ڲ�֪�������");
	return 1;
}
int ask_huyidao() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"start"))
  {
	  command("fear "+me->query("id"));
	  command("say ���Ҵ��ˣ������˺�������������������������ũ��");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  command("sigh");
	  command("say 20��ǰ�ı��䣬��ʵ��Ҳ���Ǻ����ף����Ǻ������������˷����ϣ�ȷ����ʵ��");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"over"))
  {
	  command("consider");
	  command("say ��������͵�������ؼ���ֻ�ǵ�ʱһƬ���ң���ȫ�ұ��٣���Ҳ��Ϊ�����ƣ�����������");
  	command("say ���Ǻ���������������죬��ϧС�����˷ﾹȻʹ�ö�������ι�����������Ҫȥ���ġ�");
	  return 1;
  } 
	command("heng");
	command("say ����������������죬��ϧС�����˷ﾹȻʹ�ö�������ι�����������Ҫȥ���ġ�");
	return 1;
}
int ask_xiadu() 
{
	object me = this_player();

  if(me->query(QUESTDIR2+"over"))
  {
	  command("fear "+me->query("id"));
          command("say ���Ҵ��ˣ������˺�����������������������ũָʹ���¶��ģ�");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"zhenxiang"))
  {
	  command("fear "+me->query("id"));
          command("say ���Ҵ��ˣ������˺�����������������������ũָʹ���¶��ģ�");
	  command("say ��һ�����ϣ�����ү�ͽ����ͬ齳�̸�����ڴ���͵����������������������һȭ��ֻ���������ף�������Ѫ��");
	  command("say �Ҿ���Щ�������ڶ��죬�������ũ����������һ����ҩ��˵���³�֮�����100���ƽ���Ҳ�Ǹ�����̰ͼ��Ǯ��");
	  command("say �������Ϻ���ү������ͬ����˯�����˹������䣬�ѱ��ж����ڴ���֮�С���ȡ���Ƕ�ҩ����ȥͿ�����˵���֮�ϡ�");
          command("say ���Ҵ��ˣ������˺�����������������������ũָʹ���¶��ģ�");
	  me->set_temp(QUESTDIR2+"over",1);
	  me->delete_temp(QUESTDIR2+"zhenxiang");
    me->start_busy(3);
    remove_call_out("move_fendi");
    call_out("move_fendi", 3, me);
	  return 1;
  } 
  if(me->query(QUESTDIR1+"over"))
  {
	  command("consider");
	  command("say 20��ǰ�ı��䣬��ʵ��Ҳ���Ǻ����ף����Ǻ������������˷�Ķ����ϣ�ȷ����ʵ��");
  	command("say ���Ǻ���������������죬��ϧС�����˷ﾹȻʹ�ö�������ι�����������Ҫȥ���ġ�");
	  return 1;
  } 
	command("heng");
  command("say 20��ǰ�ı��䣬��ʵ��Ҳ���Ǻ����ף����Ǻ������������˷�Ķ����ϣ�ȷ����ʵ��");
 	command("say ���Ǻ���������������죬��ϧС�����˷ﾹȻʹ�ö�������ι�����������Ҫȥ���ġ�");
	return 1;
}
void move_fendi(object me)
{
  if(!me) return;
  if(!me->query_temp(QUESTDIR2+"over")) return;
  if(!me->query_temp(QUESTDIR2+"move_fendi"))
  {
	  tell_object(me,HIC"��������Σ����Ǿ��Ķ��ǣ�����û���ϵ����õ��ɶ�������Ȼ��һ�������¶���������ָʹ���ƺ����Ѳ���������\n"NOR);
    tell_object(me,HIC"�㰵�룺�⵱��֮�����������ȸ��ߺ��������ľ�����ֻ�Ǻ�������ν���Ҳ���ղ�����֮����ȷ��������֮�⡣\n"NOR);
     tell_room(environment(me),HIC"\n�ֻ��ƺ�������"+me->query("name")+"һЩ���飬"+me->query("name")+"�Ե���Щ������\n"NOR, ({ me }));
     me->set_temp(QUESTDIR2+"move_fendi",1);
	 /*
     tell_room(environment(me),HIC""+me->query("name")+"�����뿪��ɽ��\n"NOR, ({}));
    me->move("/d/miaojiang/slu1");
    tell_object(me,HIR"�㻹�Ǽӿ��ٶȣ�����쳵ĵط���ȥ��\n"NOR);
          tell_room(environment(me),HIC"ͻȻһ����Ӱ�ӹ���ԭ����"+me->query("name")+"�����뿪��\n"NOR, ({ me }));
    me->move("/d/miaojiang/myp");
    tell_object(me,HIR"�㻹�Ǽӿ��ٶȣ�����쳵ĵط���ȥ��\n"NOR);
          tell_room(environment(me),HIC"ͻȻһ����Ӱ�ӹ���ԭ����"+me->query("name")+"�����뿪��\n"NOR, ({ me }));
    me->move("/d/xiangyang/damen");
    tell_object(me,HIR"����΢ЪϢһ�¡�\n"NOR);
          tell_room(environment(me),HIC"ͻȻһ����Ӱ�ӹ���ԭ����"+me->query("name")+"�����뿪��\n"NOR, ({ me }));
  	*/
    remove_call_out("move_fendi");
    call_out("move_fendi",5, me);
  }
  else
  {
    remove_call_out("move_fendi");
    tell_object(me,HIR"����΢Ъ��һ������\n"NOR);
	/*
    me->move("/d/huanghe/shulin2");
    tell_object(me,HIR"�㻹�Ǽӿ��ٶȣ�����쳵ĵط���ȥ��\n"NOR);
          tell_room(environment(me),HIC"ͻȻһ����Ӱ�ӹ���ԭ����"+me->query("name")+"�����뿪��\n"NOR, ({ me }));
    me->move("/d/huanghe/shulin6");
    tell_object(me,HIR"�㻹�Ǽӿ��ٶȣ�����쳵ĵط���ȥ��\n"NOR);
	  tell_room(environment(me),HIC"ͻȻһ����Ӱ�ӹ���ԭ����$N�����뿪��\n"NOR, ({ me }));
    me->move("/d/huanghe/fendi");
    tell_object(me,HIR"\n���ڵ��ˣ��㳤̾һ������\n"NOR);
          tell_room(environment(me),HIC"ͻȻһ����Ӱ�ӹ���ԭ����"+me->query("name")+"�����뿪��\n"NOR, ({ me }));
		  */
    me->delete_temp(QUESTDIR2+"move_fendi");
  }
  return;  	
}

int ask_hujiadaofa() 
{
	object me = this_player();
  if(me->query(QUESTDIR1+"over"))
  {
	  command("consider");
	  command("say ��������͵�������ؼ���ֻ�ǵ�ʱһƬ���ң���ȫ�ұ��٣���Ҳ��Ϊ�����ƣ�����������");
	  return 1;
  } 
	command("?");
  command("say ���ҵ��������´Ӳ�ʹ�õ�����");
	return 1;
}
int ask_hufei() 
{
	object me = this_player();
  if(me->query(QUESTDIR1+"over"))
  {
	  command("fear "+me->query("id"));
	  command("say ��Ȼ����һ�������£����������������ʣ�º��������ӡ������Ǻ�ڰ�......");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"start")&& !me->query_temp(QUESTDIR1+"hufei") && !me->query_temp(QUESTDIR1+"liangye"))
  {
	  command("consider");
	  command("say ����ԩ���ĺ������ĺ��Ӻ���к�쳣����Ѿ���Щ�����ˡ�");
	  command("?");
	  command("say ��λ������֪���Һ����������ʲô��");
	  me->set_temp(QUESTDIR1+"hufei",1);
	  return 1;
  } 
  if(me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"hufei"))
  {
	  command("?");
	  command("say ���������ˣ�ȷʵ�к�쳣���λ������֪���Һ����������ʲô��");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"liangye"))
  {
	  command("cry");
	  command("say ��������͵�������ؼ���ֻ�ǵ�ʱһƬ���ң���ȫ�ұ��٣���Ҳ��Ϊ�����ƣ�����������");
	  return 1;
  } 
	command("consider");
	command("say ����ԩ���ĺ������ĺ��Ӻ���к�쳣����Ѿ���Щ�����ˡ�");
	return 1;
}
int ask_liangyedaofa() 
{
	object me = this_player();
	if(me->query_condition("killer"))
	{
	  command("fear "+me->query("id"));
    command("say С�Ĺٸ�ͨ����");
	  return 1;
	}
  if(me->query(QUESTDIR1+"over"))
  {
	  command("fear "+me->query("id"));
	  command("say ��������͵�������ؼ���ֻ�ǵ�ʱһƬ���ң���ȫ�ұ��٣���Ҳ��Ϊ�����ƣ�����������");
	  command("say ��Ȼ����һ�������£����������������ʣ�º��������ӡ������Ǻ�ڰ�......");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"start")&& !me->query_temp(QUESTDIR1+"hufei") && !me->query_temp(QUESTDIR1+"liangye"))
  {
	  command("?");
	  command("say �Һ����õ��ġ�");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"hufei"))
  {
	  command("fear "+me->query("id"));
	  command("say �㣬������ô֪���ģ��ٺ٣�������ֻ����������Զ��ʧ�ˡ�");
	  me->set_temp(QUESTDIR1+"liangye",1);
	  me->delete_temp(QUESTDIR1+"hufei");
	  this_object()->kill_ob(me);
	  me->kill_ob(this_object());
	  this_object()->start_busy(1);
	  me->start_busy(1);
    power_condition(me,this_object(),200+random(100));
    remove_call_out("kill_player");
    call_out("kill_player", 1, me);
  	tell_object(me,RED"\n�㲻��̸�˿������α�һ���������......\n"NOR);
	  this_object()->set("quest/try_fight",1);
	  this_object()->set("quest/try_fight_id",me->query("id"));
	  return 1;
  } 
 	command("?");
	command("say �Һ����õ��ġ�");
	return 1;
}
int ask_qixinghaitang() 
{
	object obj,me = this_player();
  if(me->query(QUESTDIR3+"over"))
  {
	  command("? "+me->query("id"));
	  command("say �����������ˡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& (me->query_temp(QUESTDIR3+"qixinghaitang")||me->query_temp(QUESTDIR3+"jieyao2")))
  {
	  command("sigh "+me->query("id"));
	  command("say �����������ˡ�");
	  return 1;
  } 

  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"jieyao1"))
  {
	  command("fear");
	  command("say �ǳ�Ѿͷ�������ã��ߣ��ܲ����õ�Ҫ�����ʵ���ˡ�");
  	tell_object(me,RED"\n�㲻������üͷ�����˵���ɶ�......\n"NOR);
    power_condition(me,this_object(),300+random(50));
	  this_object()->kill_ob(me);
	  me->kill_ob(this_object());
	  this_object()->start_busy(1);
	  me->start_busy(1);
    remove_call_out("kill_player");
    call_out("kill_player", 1, me);
    obj=new(__DIR__"heiyiren");
    obj->set_name("ʯ����", ({ "shi wanchen", "shi" }));
    obj->set("title",HIR"����ҩ��"NOR);
    obj->set("kill_id",me->query("id"));
    obj->set("type_speical","xx");
    obj->move(environment(me));
  	message_vision(HIC"\nͻȻ�Ӻ�ɽ�ܳ�һ���������е������£����֣��������㣡��С�ӣ�����������\n"NOR,me); 
	  this_object()->set("quest/try_fight",1);
	  this_object()->set("quest/try_fight_id",me->query("id"));
	  return 1;
  } 

	command("?");
	command("say ��Ҳ��Ѱ�����Ǻ��ġ�");
	return 1;
}
void kill_player(object me)
{
	object ob=this_object();
  if(!me) return;
  if(environment(me)!=environment(this_object())) return;
  if(me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"liangyedaofa"))
  {
     if (!present("blade",ob))
	             carry_object(BINGQI_D("blade"))->wield();
	      else command("wield blade");
    return;
  }
  if(me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"getjieyao1"))
  {
    if (!present("blade",ob))
	             carry_object(BINGQI_D("blade"))->wield();
	      else command("wield blade");
    return;
  }  	
}

void kill_ob(object me)
{       
	 command("sneer " + me->query("id"));
   COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon") );
   COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon") );
   COMBAT_D->do_attack(this_object(), me, this_object()->query_temp("weapon") );
	::kill_ob(me);
}

int do_hit(string arg)
{
         object me,ob;
         me=this_player();
         ob=this_object();
         if((arg==("yan"))||(arg==("yan ji"))){       
           	command("sneer");
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	return 1;
         }
         return 0;        
}

void unconcious()
{
  die();
}

void die()
{
	object me,obj,ob=this_object();
	if(ob->query("quest/try_fight"))
	{
	  command("ah");
	  if(ob->query("quest/try_fight_id"))
	  {
      remove_call_out("kill_player");
      ob->remove_all_killer();
      start_condition(ob);
	  	me=find_player(ob->query("quest/try_fight_id"));
	    ob->delete("quest/try_fight");	 
	    ob->delete("quest/try_fight_id");
	  	if(!me) return;
      me->remove_all_killer();  
      if(environment(me)!=environment(this_object())) return;
      if(me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"liangye"))
      {

	         command("say �Ҵ��ˣ��Ҵ���......");
	         command("sorry");
        	 command("say ��������͵�������ؼ���ֻ�ǵ�ʱһƬ���ң���ȫ�ұ��٣���Ҳ��Ϊ�����ƣ�����������\n");
        	 tell_object(me,HIY"\n"+ob->query("name")+"��������ҳֽ����������ź��ҵ�����\n"NOR);
                 tell_room(environment(me),HIC"�ֻ����񽻸�"+me->query("name")+"ʲô�������ƺ�����ҳֽ�š�\n"NOR, ({ me }));
 	         obj=new(__DIR__"obj/paper");
           obj->set("owner",me->query("id"));
 	         obj->move(me);
           tell_object(me,HIC"\n����ѯ����һЩ��ʱ��������ֻ�������˵���˵�ʱ����ľ���......\n"NOR);
           tell_object(me,HIC"\n\nȴ˵�������ĵ����죬��һ��֮�޾�Ȼ�������˷�Ľ������������ǽ��������˷�����һ��б�̣������������׺׽�\n"       
        	                       "˫���˿���һ�㣬����һ���������������������˫�ָ�չ��֮ʱ���������������������������ϵ�����֪�������书��\n"
        	                       "�����ǳ����뻯��������Σ��֮�䣬��˫��һ�������⶷Ȼ�����Լ��ؿڡ���һ�����һ����ֻ�����������ˣ�������ɱ��\n"
        	                       "æ�е�����"HIR"���֣�����"HIC"����\n"NOR);
                 tell_room(environment(me),HIC"ֻ�����ֻ�����"+me->query("name")+"��ߣ�����˵��ʲô����ɫ��Щ��㱣��ƺ��ڻ��������£�˵����ʱһ��һ�ٵġ�\n"NOR, ({ me }));
        	 command("sigh");
        	 tell_object(me,HIC"\n�ⲻ֪�����Ľ����ڵ�һ�ձ���֮ʱ��������ָ�ֶ��˵ģ����Ȿ���Ƕ�ͷ�������ؿ�һ�������ǽ��������ϣ���Ȼ������\n"
        	                     "������������һ���������Ľ����������õ��ں�һ���ؿڵġ����Ѩ���ϣ���һ����ʱ����\n\n"NOR);
        	 tell_object(me,HIC"��������ַ�ס���е�����"HIR"����"HIC"����\n"NOR);
        	 tell_object(me,HIC"��һ��Ц������"HIR"���ֽ���������Ī�⣬��������"HIC"��\n"NOR);
        	 tell_object(me,HIC"����������"HIR"���Ǻ��ֺ�����ģ����к��ܵ��֣�"HIC"��\n\n"NOR);
        	 tell_object(me,HIC"������������һ����Ǭ�������վơ���һ������һЦ�����������Լ�����һĨ���ʺ��������Ѫ���������������˸���Ҳ��ɱ�ˡ�\n\n"NOR);
        	 tell_object(me,HIG"���������������һ�����ۣ���ȷʵû���ϵ�����������ۣ��������������ɱ�����벻���ס���ĬȻ��һ�ᣬ�ſ��ֻ���\n"NOR);      	 
        	 tell_object(me,HIG"�������̾�˿�����\n"NOR);
                 tell_room(environment(me),HIC""+me->query("name")+"�����̾�˿�����\n"NOR, ({ me }));
        }
        if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"jieyao1"))
        {
	         command("say �Ҵ��ˣ��Ҵ���......");
	         command("sorry");
        	 command("say �һ�����Ѿͷ���ǣ�������Ϊ��������֡�");
        	 tell_object(me,HIW"\n"+ob->query("name")+"������һ�����Ǻ��ġ�\n"NOR);
                 tell_room(environment(me),HIC"�ֻ�����"+ob->query("name")+"һ�����Ǻ��ġ�\n"NOR, ({ me }));
 	         obj=new(__DIR__"obj/qixinghaitang");
           obj->set("owner",me->query("id"));
 	         obj->move(me);
 	         tell_object(me,HIR"\n����ǰ�ȵ�����"+ob->query("name")+"����Ҳ�������㡣����������һ�ɣ�"+ob->query("name")+"��Ȼ���˹�ȥ����˳�Ƹ���һ�ơ�\n"NOR);
 	         me->delete_temp(QUESTDIR3+"jieyao1");
 	         me->set_temp(QUESTDIR3+"qixinghaitang",1);   
 	         tell_room(environment(me),HIC"ͻȻ�ֻ���Ѫ�ƺ���˳��˫��һ����ֱ̱�ڵ��ϡ�\n"NOR, ({ me }));
 	         command("inn "+me->query("id"));
 	         if(obj=present("shi wanchen",environment(me)))
 	         {
 	         	message_vision(HIC"\n$N��$n�е���������ţ�������ȥ�Ҿȱ�������ת��������Ͳ����ˡ�\n"NOR,obj,ob); 
 	         	command("why "+obj->query("id"));
 	         	destruct(obj); 
 	         }
 	         ob->unconcious();
        }
      }
	  }
  else
  {
	command("why");
	::die();
  }
}
int start_condition(object ob)
{
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("unarmed", 150);
	set_skill("blade",150); 
	set_skill("hujia-daofa",150); 
	set_skill("huagong-dafa",150); 
	map_skill("force","huagong-dafa");
	map_skill("blade","hujia-daofa");
	set("combat_exp", 300000);
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("eff_jingli",1000);
	set("max_neili", 2100);
	set("qi",30000);
	set("jing",1000);
	set("jingli",1000);	
	set("neili", 4200);
  return 1;
}
int power_condition(object me,object ob,int p)
{
	  int i;
    if(environment(me)!=environment(ob)) return 0;
    if (!present("blade",ob))
	    carry_object(BINGQI_D("blade"))->wield();
	  else command("wield blade");
	  i=me->query("max_pot");
	  if(p<150) p=150;
	  if(i<p) i=p;
	  i=i-100;	  
	  ob->set_skill("force", i+random(50));
	  ob->set_skill("dodge", i+random(50));
	  ob->set_skill("parry", i+random(50));
	  ob->set_skill("blade", i+random(50));
	  ob->set_skill("cuff",i+random(50)); 
	  ob->set_skill("taxue-wuhen",i+random(50));
	  ob->set_skill("zhentian-quan",i+random(50));
	  ob->set_skill("xuantian-wuji",i+random(50));
	  ob->set_skill("hujia-daofa",i+random(50));
	  i=me->query("combat_exp");
	  ob->set("combat_exp",i);
	  i=me->query("neili");	  
	  if(i<12000) i=12000;
	  ob->set("neili", i);	  
	  i=me->query("max_neili");	  
	  if(i<6000) i=6000;
	  ob->set("max_neili", i);	  
  	i=me->query("max_qi");	  
	  ob->set("max_qi", i*(1+random(2)));	  
 	  ob->set("eff_qi", ob->query("max_qi"));	
 	  ob->set("qi", ob->query("max_qi"));	
    return 1;
}
