//hufei.c
//by tangfeng@SJ

inherit F_MASTER;
inherit NPC;
#include <ansi.h>

#define QUESTDIR "quest/ѩɽ�ɺ�/"
#define QUESTDIR1 "quest/ѩɽ�ɺ�/��ҳ����ƪ/"
#define QUESTDIR2 "quest/ѩɽ�ɺ�/����ƪ/"
#define QUESTDIR3 "quest/ѩɽ�ɺ�/��ҩƪ/"
#define QUESTDIR4 "quest/ѩɽ�ɺ�/�书/"
int do_halt1(string arg);
void greeting(object me);
void unconcious();
void kill_ob(object me);
int do_hit(string arg);
void do_halt(object me);
void die();
int ask_biwu();
int ask_cheng();
int ask_yaowu();
int ask_hujiadaofa();
int ask_huyidao();
int ask_jiachou();
int ask_liangyedaofa();
int ask_zhiliao();
int ask_yanji();
int ask_miaoruolan();
int ask_tian();
int ask_miaorenfeng();
int ask_jiaoliang();
int hufei_fight(object me, object ob);
int thinking(object me, object ob);
int try_fight(object me, object ob);
int start_condition(object ob);
int power_condition(object me,object ob,int p);
int busy_pass(object ob);

void create()
{
	set_name("���", ({ "hu fei", "hu", "fei" }) );
	set("gender", "����" );
	set("title", HIW"ѩɽ�ɺ�"NOR);
	set("age", 26);
	set("long", 
	    HIR"�ɶ�������һ���Ķ��ӡ�"NOR);
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("per", 25);
	set("shen_type", 1);
	set("unique", 1);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("cuff",300); 
	set_skill("taxue-wuhen",300);
	set_skill("zhentian-quan",300);
	set_skill("xuantian-wuji",300);
	set_skill("hujia-daofa",300);
	map_skill("force","lengquan-shengong");
	map_skill("cuff","zhentian-quan");
	map_skill("dodge","taxue-wuhen");
	map_skill("blade","hujia-daofa");
	map_skill("parry","hujia-daofa");
  prepare_skill("cuff", "zhentian-quan");
	set("combat_exp", 2000000);
	set("max_qi", 30000);
	set("max_jing", 3000);
	set("max_neili", 5000);
	set("eff_jingli",3000);
	set("qi",30000);
	set("jing",3000);
	set("jingli",3000);
	set("neili", 5000);

  set("inquiry", ([
    "��һ��" : (: ask_huyidao :),
    "���ҵ���" : (: ask_hujiadaofa :),
    "��ҳ����" : (: ask_liangyedaofa :),
    "����" : (: ask_jiaoliang :),
    "����" : (: ask_biwu :),
    "����" : (: ask_zhiliao :),
    "������" : (: ask_miaoruolan :),
//    "���˷�" : (: ask_miaorenfeng :),
    "���˷�" : (: ask_miaorenfeng :),
    "���˷�" : (: ask_miaorenfeng :),
    "�ֻ�" : (: ask_yanji :),
    "������" : (: ask_cheng :),
    "���ũ" : (: ask_tian :),
    "�ҳ�" : (: ask_jiachou :),
	]));
	setup();
	set("chat_chance", 1);
	set("chat_msg", ({
		"��쳹��ڷ�ǰ�����ְݡ�\n",
	}));
	carry_object("/clone/weapon/blade/blade.c")->wield();
	carry_object("/clone/weapon/blade/blade.c");
	carry_object("/clone/armor/baihu-qiu.c")->wear();
} 

void init()
{
  object ob;
	::init();
  ob = this_player();
  if (interactive(ob = this_player()) ) {
       remove_call_out("greeting");
       call_out("greeting", 1, ob);
  }       
	add_action("do_answer","answer");
	add_action("do_halt1","halt");
  add_action("do_hit", "hit");
}
int do_halt1(string arg)
{
         object me,ob;
         me=this_player();
         ob=this_object();
	       command("sneer");
         remove_call_out("do_halt");
         remove_call_out("try_fight");
  	     ob->reset_action();
	       ob->delete("quest/try_fight");
	       ob->delete("quest/try_fight_id");
	       me->delete_temp(QUESTDIR+"����/hu_fighting");
	       start_condition(ob);
	       command("halt");
         ob->remove_all_killer();   
         me->remove_all_killer(); 
         return 1;
      
}
void greeting(object me)
{
  int shen,i;
  if(!me) return;
  if(environment(me)!=environment(this_object())) return;
  shen = me->query("shen");
	if(me->query_temp(QUESTDIR2+"over"))
	{
/*
����쳴��˿��������������Լ���ƽ�����ǧ�����֮�ˣ�һʱ֮�侹��û�����⣺��������ɱ�����ˣ����������������ĸ��ס��� 
��������������һ���¿࣬����ƽ����˵�����������壬ʼ��û�Բ����ҵĵ��衱�� 
���������ųƴ�������޵��֣��书��ҵ��������˫������ƫ���ŷ�����Ҫ��������ǿ�ػ�����ǿ����
*/
	 if(me->query_condition("killer"))
	 {
	   command("fear "+me->query("id"));
     command("say С�Ĺٸ�ͨ����");
	   return;
	 }
		tell_object(me,CYN"\n�㼱æ��������ߺ�쳣�������Ը�����������....\n"NOR);
  	command("cry");
    me->delete_temp(QUESTDIR2+"over");
        tell_object(me,HIW"\n�����ũ������쳱�Ц����������ƺ����ǳ������������ң��������������ţ����ԹҲ�����˽⡣\n\n"NOR);
    me->set(QUESTDIR2+"over",1);
    me->delete_temp(QUESTDIR2+"over");
  	tell_object(me,HIG"�㲻֪����ϲ�Ǳ��������������Ժ����˵Ҳ��Ҳ�Ǹ�԰�ᡣ\n"NOR);	
  	command("say ���������֪��������Σ�");
  	tell_object(me,CYN"���ͷ����������ȥ���ׯ�������鲻����������ЪϢΪ�\n"NOR);	
   	me->add("max_neili",me->query_skill("force")/2);
   	me->add("combat_exp",me->query_skill("force"));
   	i=180+random(40);
   	me->add("mana",i);
  	tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ�����ƪ�����"+(int)me->query_skill("force")/2+"�����������"+(int)me->query_skill("force")+"�㾭�齱����"+i+"��������\n\n"NOR);	
          log_file("quest/FEIHU", sprintf("%s(%s) �ҿ�ѩɽ�ɺ�Quest����ƪ,ʱ�� %s�����%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), ctime(time()),me->query_skill("force")/2,me->query_skill("force"),i ) );
	}
	else
	{
	  if(shen <0 ) command("look "+me->query("id"));
	  else command("say");
  }
}

int ask_cheng() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("say ��ĸ�л�̹��Ҫ�����������ұ���������");
	  command("think");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"getjieyao"))
  {
	  command("suicide1");
	  command("say ��ĸ�л�̹�����ǻ��ǸϿ�ȥ����������ɡ�");
	  return 1;
  }
  if(me->query(QUESTDIR3+"start")&& (me->query_temp(QUESTDIR3+"jieyao2")||me->query_temp(QUESTDIR3+"qixinghaitang")))
  {
	  command("suicide1");
	  command("say ���ǿ��ϵ��̹������������Ķ�������ͣ�ֻ��......");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"jieyao1"))
  {
	  command("sigh");
	  command("say ���ǿ��ȥ�ҵ����Ǻ��ġ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start"))
  {
	  command("blush");
	  command("say �̹��ﵱ���������й�һ��֮����ֻ���������ںδ����������......");
	  command("sigh");
	  return 1;
  } 
  command("say ��Ҳ��ʶ�̹����Щ��������ʵ��һֱ��������");
	command("sigh");
	return 1;
}

int ask_biwu() 
{
	object me = this_player();
  if(me->query(QUESTDIR3+"marry"))
  {
	  command("say 20��ǰ�ı��䣬�����Ѿ���ȫ���ˣ��������ҽ����ܹ��ٴ��ع��ںã����������æ��");
  	command("thank "+me->query("id"));
	  command("say ��Ҫ��л�����ܹ���������������Ļ�����");
	  return 1;
  }
  if(me->query(QUESTDIR3+"over"))
  {
	  command("sigh "+me->query("id"));
	  command("say 20��ǰ�ı��䣬�����Ѿ���ȫ���ˡ����������������Ҿ�Ȼ�����������ö�Ҳ���ˣ�û�����ɴ��");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  command("sigh "+me->query("id"));
	  command("say ȷʵû���뵽������˸��ӡ������Լ������������������Ҿ�Ȼ���������ⶾ������ͣ�ֻ��......");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"over"))
  {
	  command("shout");
	  command("say 20��ǰ�ı��䣬��ȷ�����ɵ㣬���Ǽ�Ȼ֪��ɱ���ҵ������֣������������书���ã�Ҳ����������");
	  return 1;
  } 
  if(me->query(QUESTDIR1+"start"))
  {
	  command("say 20��ǰ�ı��䣬֪��������˶�������������Щ������һֱ��Ѱ��ɱ����������֡�");
	  command("shout");
	  command("say ���ң���ϧ���书δ��Բͨ������Ϊ����������ҵ������ǲ��ܷ�豹��档");
	  return 1;
  }  
	command("say �����ҵ����ͺųơ���������޵��֡������˷��ڴ˱��䣬���˷��Զ���\n���ҵ�����������������ѳ�򡣴���������ɱ�����ˣ���������ʬ���......������\n"
          "�����˺�����ٰ���ྴ���أ����˷���ô������˺��֣�");
	command("consider");
	command("doubt");
	return 1;
}

int ask_hujiadaofa() 
{
	object me = this_player();
	object ob = this_object();
	int i;
	if(me->query_condition("killer"))
	 {
	   command("fear "+me->query("id"));
     command("say С�Ĺٸ�ͨ����");
	   return 1;
	}
	if(me->query(QUESTDIR2+"start") && !me->query(QUESTDIR3+"over"))
  {
	  command("shake "+me->query("id"));
	  command("say ����ʱ��������⵶�������Ժ��д�ɡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR4+"hujiadaofa_fail")>=3 && me->query("registered")<3)
  {
	  command("shake "+me->query("id"));
	  command("say �⵶�������Ժ��д�ɡ�");
	  return 1;
	}
	
  if(me->query(QUESTDIR4+"hujiadaofa"))
  {
   if(me->query("potential")<= 5)
   {
	  command("? "+me->query("id"));
	  if(random(2)) command("say ��ʲô����ʲô������");
	  else command("say Ǳ�ܲ���ѧʲô������");
    return 1;
   }
   else 
   {
    message_vision("$N��$n����йغ��ҵ����İ��\n", me, this_object());
    me->receive_damage("jing", 30);
    tell_object(me,"�����˺�쳵�ָ�㣬�Ժ��ҵ����İ����ƺ���Щ�ĵá�\n");
    me->add("potential",-(random(3)+2));
    if( me->query("potential")<0)
        me->set("potential",0);
    me->improve_skill("hujia-daofa", 10+random(me->query_int()));
    me->improve_skill("blade", random(me->query_int())/2);
    return 1;
   }
  } 
	if(me->query(QUESTDIR4+"time") && (time() - me->query(QUESTDIR4+"time"))<86400)
	{
	  command("hehe "+me->query("id"));
	  command("say ����ʱ��������⵶���������������ɡ�");
	  return 1;
	}  
  if(ob->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ���Ǹ�ѧ�����⵶�������Ժ��д�ɡ�");
	  return 1;   
  }
  if(me->query(QUESTDIR1+"over"))
  {
	  command("nod "+me->query("id"));
	  if(me->query(QUESTDIR4+"combat_exp") && (me->query("combat_exp") - me->query(QUESTDIR4+"combat_exp"))<1000000)
	  {
	    command("shake "+me->query("id"));
	    command("say �㻹��ר������ȥ�ɣ����书δ�г�����ֻ�»�����������");
	    return 1;
	  }  
    message_vision(HIB"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, ob);
    ob->set_temp("quest/ѩɽ�ɺ�/�书/lengquan",1);
    ob->set_temp("busy",1);
    power_condition(me,ob,300+random(100));
	  for ( i = 0; i < 6+random(8);i++){
	     hufei_fight(me, ob);
    }
    ob->delete_temp("quest/ѩɽ�ɺ�/�书/lengquan");
    start_condition(ob);
    tell_object(me,CYN"\n\n\nһ�������ѹ������Ц˵�������ղ���ʹ�õ������ɿ�����ˣ���\n"NOR);
    command("smile "+me->query("id"));
    remove_call_out("busy_pass");
    remove_call_out("thinking");
    me->set(QUESTDIR4+"time",time());
    me->set(QUESTDIR4+"combat_exp",me->query("combat_exp"));
    ob->set_temp("busy",1);
		call_out("busy_pass",600, ob);
		call_out("thinking",3, me, ob);
    tell_object(me,CYN"�㿪ʼ���濼�ǡ�\n"NOR);
    me->start_busy(3+random(i));
	  return 1;
  }
  if(me->query(QUESTDIR1+"start"))
  {
	  command("shout");
	  if(random(2)) command("say ��ϧ���书δ��Բͨ������Ϊ����������ҵ������ǲ��ܷ�豹��档");
	  else command("say ���˷���˵�书�ųƴ�����£�������������ϧ�Һ��ҵ����ؼ����в�ȱ����������书��δ��ɡ�");
	  return 1;
  }  
  if(me->query_temp(QUESTDIR1+"jiachou"))
  {  	
 	  command("heng");
	  command("say �Һ��ҵ���ȷ��һ��һ���书��ֻ�ǵ����������ؼ���Ȼȱ����ҳ��ȱ�������������Ź���ȱ��ȭ���������ܾ���");
	  command("say ��Щ������������ô�ù������������ڻ��ͨ����˵���˷�ųƴ�������޵��֣���ϧ�Һ��ҵ����ؼ����в�ȱ�����Ƕ��֡�");
 	  command("sigh");
    command("say ����ƽ����˵������ҳ����һ���������ж�ȥ��ǰһ��ʱ������˵���置��������");
    me->set(QUESTDIR1+"start",1);
    me->delete_temp(QUESTDIR1+"jiachou");
	  return 1;
  }   
	command("sneer");	 	 	 	 	 	
	if(random(2)) command("say ����ұ��ԣ������ˣ�");
  power_condition(me,ob,250+random(200));
  COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  if(random(2)) COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  if(random(2)) COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  start_condition(ob);
	command("sneer");
	return 1;
}
int hufei_fight(object me, object ob)
{
  COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  if (!present(me,environment(ob)) || me->query("qi") <= me->query("max_qi")/50 || me->query("jing") <= 10 || me->query("jingli") <= 10)  {
	command("sneer");
	command("say ��λ�����书δ�ܷ�豹��棬ֻ������������ҵ����ľ�����");
	return 0;
  }
  return 1;
}
int busy_pass(object ob)
{
	if(!ob) return 0;
	if(ob->query_temp("busy")) ob->delete_temp("busy");
  return 1;
}

int thinking(object me, object ob)
{
	int i;
  if(environment(me)!=environment(this_object())) 
  {
  	start_condition(ob);
  	return 1;
  }
	if(!me->query_temp(QUESTDIR4+"thinking"))
	{
		me->set_temp(QUESTDIR4+"thinking",1);
    tell_object(me,HIG"��Ŭ���ػ���ղŵ�ÿһ��ÿһʽ......\n"NOR);
    tell_object(me,CYN"��Ŭ���ػ���ղŵ�ÿһ��ÿһʽ......\n"NOR);
		call_out("thinking",4, me, ob);
	}
	else
	{
	  if(random(me->query("pur"))>28 && random(me->query("int"))>28)
    {
       tell_object(me,HIG"\n���������У�ͻȻ��������һ�С�\n"NOR);
       tell_object(me,CYN"�㡸����������Ц������\n"NOR);
       tell_object(me,CYN"��˵������"NOR+HIR"�������ˡ�"NOR+CYN"��\n"NOR);
       command("nod");
       command("congra");
       tell_object(me,HIR"�����˺�쳵�ָ�㣬�Ժ��ҵ����İ����ƺ���Щ�ĵá�\n"NOR);
       tell_object(me,HIR"ֻ���㷢������ҵ�������Ҫ��Ȫ�񹦲��ܷ���ȫЧ��\n"NOR);
       me->set(QUESTDIR4+"hujiadaofa",1);
       me->delete(QUESTDIR4+"hujiadaofa_fail");
   	   i=180+random(40);
   	   me->add("mana",i);
  	   tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ����ҵ���ƪ�������"+i+"��������\n\n"NOR);	
	     log_file("quest/FEIHU", sprintf("%s(%s) �ҿ�ѩɽ�ɺ����ҵ���,ʱ�� %s�������%d��������\n", me->name(1),me->query("id"), ctime(time()),i ) );
    }
    else
    {
       tell_object(me,HIG"\n���ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       tell_object(me,CYN"��ҡ��ҡͷ�����������Ǻ����ѵġ�\n"NOR);
       tell_object(me,HIY"�������̾�˿�����\n"NOR);
       me->add(QUESTDIR4+"hujiadaofa_fail",1);
      if(me->query(QUESTDIR4+"hujiadaofa_fail")>=3 && me->query("registered")<3)
       {
      	tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"���һ�γ��Խҿ�ѩɽ�ɺ����ҵ�����ȴû�гɹ���\n\n"NOR);	
   		  log_file("quest/FEIHU", sprintf("%s(%s) ���һ�γ��Խҿ�ѩɽ�ɺ����ҵ�����ȴû�гɹ���ʱ�� %s��\n", me->name(1),me->query("id"), ctime(time()) ) );
       }
    }
    me->delete_temp(QUESTDIR4+"thinking");
  }
  return 1;
}

int ask_huyidao() 
{
	object me = this_player();
  if(me->query(QUESTDIR2+"over"))
  {
  	command("nod "+me->query("id"));
  	command("say ����������Ĺض�������һ�������Ҹ��ף�");
   	message_vision(HIB"$N˵����仰���������ǵ���֮ɫ��\n"NOR,this_object());
	  return 1;
  } 
  if(me->query(QUESTDIR2+"start"))
  {
  	command("heng");
  	command("say ����Ĺض�������һ�������Ҹ��ף�");
  	command("say �������������ȥ�����˷�����ȥ��");
  	return 1;
  }  
  command("nod "+me->query("id"));
  command("say ����Ĺض�������һ�������Ҹ��ף�");
  command("say ��ϧ�����ĳ𣬻�δ����");
	return 1;
}

int ask_jiachou() 
{
	object me = this_player();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
     command("say С�Ĺٸ�ͨ����");
	   return 1;
	}
  if(me->query(QUESTDIR3+"marry"))
  {
	  command("say �ҳ����ˣ��������ҽ����ܹ��ٴ��ع��ںã�Ҳ���������æ��");
  	command("thank "+me->query("id"));
	  command("say ��Ҫ��л�����ܹ���������������Ļ�����");
	  return 1;
  }
  if(me->query(QUESTDIR3+"over"))
  {
	  command("say �������ҽ����ܹ��ٴ��ع��ںã�Ҳ���������æ�����������������Ҿ�Ȼ�����������ö�Ҳ���ˣ�û�����ɴ��");
	  command("sigh "+me->query("id"));
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  command("sigh "+me->query("id"));
	  command("say ȷʵû���뵽������˸��ӡ������Լ������������������Ҿ�Ȼ���������ⶾ������ͣ�ֻ��......");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"start"))
  {
	  command("say ����ν������������Ȼ֪��ɱ���ҵ������֣������������书���ã�Ҳ����������");
	  if(!me->query(QUESTDIR2+"answer")){
	     command("look "+me->query("id"));
       command("sigh");
	     command("say ��λ�������书��������֪���Ƿ�Ը���æ��");
       tell_object(me,HIG"�ش�����answer yes ����answer no\n"NOR);
       me->set_temp(QUESTDIR2+"answer_",1);
    }
    else
    {
	     command("look "+me->query("id"));
       command("thank");  
	     command("say ֻҪ��λ�����ܹ���æ�����²�ʤ�м�����ʵ��Ҳ����ȷ��������ԭί��");
    }
  	return 1;
  }  
  if(me->query(QUESTDIR+"time") && (time() - me->query(QUESTDIR+"time"))<86400)
	{
	  command("shake "+me->query("id"));
	  command("say û�����Һ�æ������������");
	  return 1;
	}  
  if(me->query(QUESTDIR1+"over"))
  {
	  command("say ��һֱ����������ɱ���ҵ������֣�ֻ������������������Բ���ȷ�ϣ���������ס�");
	  command("say ����ν������������Ȼ֪��ɱ���ҵ������֣������������书���ã�Ҳ������͵���ˡ�");
    command("sigh");
    me->set(QUESTDIR+"time",time());
	  command("look "+me->query("id"));
	  command("say ��λ�������书��������֪���Ƿ�Ը���æ��");
    tell_object(me,HIG"�ش�����answer yes ����answer no\n"NOR);
    me->set_temp(QUESTDIR2+"answer_",1);
    me->set(QUESTDIR2+"start",1);
	  return 1;
  }  
  if(me->query(QUESTDIR1+"start"))
  {
	  command("shout");
	  command("say ��һֱ�������˷����ɱ���ҵ������֣�ֻ�����������������Բ���ȷ�ϡ�");
	  return 1;
  }  
  if(me->query_temp(QUESTDIR1+"jiachou"))
  {
	  command("shout");
	  command("consider");
	  command("say ����Ĳ����ף��벻ͨ�����еı仯��ֻ��ϧ�ҵ������ò������ס�");
	  return 1;
  }    	 	 	 	 	 	 	
	command("say �����ҵ����ͺųơ���������޵��֡������˷��ڴ˱��䣬���˷��Զ���\n"
"  ���ҵ�����������������ѳ�򡣴���������ɱ�����ˣ���������ʬ���......������\n"
"  �����˺�����ٰ���ྴ���أ����˷���ô������˺��֣�");
	command("consider");
	command("doubt");
  me->set(QUESTDIR+"time",time());
	me->set_temp(QUESTDIR1+"jiachou",1);
	return 1;
}

int do_answer(string arg)
{
	object me = this_player(); 
	if(!me->query_temp(QUESTDIR2+"answer_")) return 0;
	if(!arg ||(arg!="yes" && arg!="no")) return 0; 
	if(arg=="yes")
	{
    tell_object(me,CYN"\n�������̾�˿�����˵����������ι���ҲӦ���и�ˮ��ʯ�����ҾͰ���ȥһ�����ׯ�ɡ�\n"NOR);
	  me->set_temp(QUESTDIR2+"answer","yes");
	}
	else
	{
    tell_object(me,CYN"\n�㾪���˵������ȴ��Щ���ɣ��������ô�����������أ�������Ϊ�㣬��ҲҪȥһ�����ׯ�ɣ�\n"NOR);
	  me->set_temp(QUESTDIR2+"answer","no");
	}
	return 1;	
}

int ask_jiaoliang() 
{
	object me = this_player();
	object ob = this_object();
	if(me->query_condition("killer"))
	 {
	   command("fear "+me->query("id"));
     command("say С�Ĺٸ�ͨ����");
	   return 1;
	}
  if(!me->query(QUESTDIR3+"over") && me->query(QUESTDIR2+"start"))
  {
	  command("shake "+me->query("id"));
	  command("say ����ʱ������������Ժ��д�ɡ�");
	  return 1;
  } 
  if(ob->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ���д��꣬�Ժ��д�ɡ�");
	  return 1;   
  }
  if(random(me->query("combat_exp"))<random(ob->query("combat_exp")*2/3) && !wizardp(me))
  {
	  command("say Σ�գ�̫Σ���ˣ�");
    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	  command("fear "+me->query("id"));
    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	  command("say Σ�գ�̫Σ���ˣ�");
    COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	  command("fear "+me->query("id"));
    return 1;
  }
  if(me->query(QUESTDIR1+"over"))
  {
	  command("nod "+me->query("id"));
    message_vision(HIY"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, this_object());
    me->set_temp(QUESTDIR+"����/hu_fighting",1);
    power_condition(me,ob,300+random(100));
	  ob->set("quest/try_fight",1);
	  ob->set("quest/try_fight_id",me->query("id"));
    ob->kill_ob(me);
	  command("sneer");
    remove_call_out("busy_pass");
    remove_call_out("do_halt");
    remove_call_out("try_fight");
    ob->set_temp("busy",1);
		call_out("busy_pass",600, ob);
    call_out("do_halt", 150,me);
		call_out("try_fight", 2, me, ob);
    me->start_busy(1);
    ob->start_busy(1);
	  return 1;
  }
 	 	 	
	command("say ����ұ��ԣ������ˣ�");
	command("sneer");
  power_condition(me,ob,250+random(200));
  COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	command("sneer");
	start_condition(ob);
	return 1;
}

int try_fight(object me, object ob)
{
	int i;
	if (!me->is_fighting(ob)|| !ob->is_fighting(me)||!present(me,environment(ob)) || me->query("eff_qi") <= 1000|| me->query("qi") <= 0 || me->query("jing") <= 10 || me->query("jingli") <= 10)  {
	   command("sneer");
	   command("say ��λ�����书δ�ܷ�豹��棬ֻ�����Եֵ����ҵ����Ľ�����");
     remove_call_out("do_halt");
     remove_call_out("try_fight");
  	 ob->reset_action();
	   ob->delete("quest/try_fight");
	   ob->delete("quest/try_fight_id");
	   me->delete_temp(QUESTDIR+"����/hu_fighting");
	   start_condition(ob);
	   command("halt");
     ob->remove_all_killer();   
     me->remove_all_killer();   
  	 return 1;
  }
  if (!present("blade",ob))
	    carry_object(BINGQI_D("blade"))->wield();
	else command("wield blade");
	
  i=me->query_temp(QUESTDIR+"����/fight_times");
  
  if(i<(2+random(me->query("int")/20))) i++;
  else 
  {
  	if(ob->query_busy())
  	{
  		if(ob->query_busy()>2) ob->start_busy(me->query_busy()/2);
  		else ob->start_busy(random(2));
      message_vision(HIR"\n$N"MAG"��ת��Ȫ�񹦣�˲�仯��ԭ������$N�ж����������ֽŶ�ʱ�������࣡\n"NOR, ob);
      if(random(2))
      {
            message_vision(HIW"\n$N"HIW"����Գ�ۣ����еĸֵ��������£��仯Ī�⣬������$n"HIW"����Ҫ����\n" NOR, this_object(),me);
            ob->command("haha");
            if(random(3))
            {
            	message_vision(HIY"\n$n"HIY"������ʵ���Ǳ��Ī�⣬���ɵ��������⣬��ʽ��ʱ����������\n" NOR, this_object(),me);
              me->add_busy(3+random(4));
              COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            }
            else
            {
            	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            }
	    }
    }
    else
    {
     switch(random(6))
     {
     	case 0:
            message_vision(HIW"\n$N"HIW"����Գ�ۣ����еĸֵ��������£��仯Ī�⣬������$n"HIW"����Ҫ����\n" NOR, this_object(),me);
            ob->command("haha");
            if(random(3))
            {
            	message_vision(HIY"\n$n"HIY"������ʵ���Ǳ��Ī�⣬���ɵ��������⣬��ʽ��ʱ����������\n" NOR, this_object(),me);
              me->add_busy(3+random(4));
              COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            }
            else
            {
            	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            }
            break;
     	case 1:
     	case 2:
            message_vision(HIC"\nͻȻ֮�䣬���Ϳ�ݾ��׵ĵ�����Ȼ��ø���������������һ˲֮�䣬$N�������ߵ���\n"NOR, this_object(),me);
            ob->command("haha");
          	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
          	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
          	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
          	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            break;
     	case 3:
     	case 4:
     		    message_vision(HIR"\n$N���еĸֵ��ó����쵶�ƣ�����������Ļ���$n��\n" NOR, this_object(),me);
	          ob->add_temp("apply/attack", ob->query_skill("blade"));	
	          ob->add_temp("apply/damage", ob->query_skill("blade"));
          	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
	          ob->add_temp("apply/attack", -ob->query_skill("blade"));	
	          ob->add_temp("apply/damage", -ob->query_skill("blade"));
            ob->command("haha");
            break;
     	default:
      	    message_vision(HIB"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, this_object());
            ob->command("heng");
	          ob->add_temp("apply/attack", ob->query_skill("blade")/4);	
            break;
     }  
    }
     i=0;
  }
  me->set_temp(QUESTDIR+"����/fight_times",i);
	call_out("try_fight", 1, me, ob);
  return 1;
}
int ask_liangyedaofa() 
{
	object me = this_player();
  if(me->query(QUESTDIR1+"over"))
  {
  	command("thank "+me->query("id"));
	  command("say ��л���������ҵ�����ҳ�������Ҳ��ܽ����ҵ����ڻ��ͨ��");
	  return 1;
  }
	command("?");
  command("say ��ҳ���������Ǻ����ס�");
	return 1;
}
int ask_yanji()
{
	
	object me = this_player();
  if(me->query(QUESTDIR2+"over"))
  {
	  command("say һ�ж������ˣ�Ҳ�������������һ�ж���ԹԹ��");
	  command("zxx2 "+me->query("id"));
	  return 1;
  } 
  if(me->query(QUESTDIR1+"over"))
  {
	  command("heng");
	  command("say ��С�˾�Ȼ����͵���Ҽ��ؼ������Ҽ����ز����ģ�");
	  return 1;
  } 
 	command("?"); 
	command("say �Һ�����ʶ����ˡ�");
	command("consider");
	return 1;
}
int ask_zhiliao() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("?");
	  command("say �Ҳ���ҽ�����Ǻǣ�����ʲô���ƣ� ");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start"))
  {
	  command("sigh "+me->query("id"));
	  command("say �������������ֻ�г̹����ˣ��ô�Ҳ�������ˣ�ֻ�ǲ�֪�����ڳ̹����������");
	  return 1;
  } 
  command("?");
	command("say �Ҳ���ҽ�����Ǻǣ�����ʲô���ƣ�");
	return 1;
}
int ask_miaoruolan() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"marry"))
  {
  	command("blush");
  	command("thank "+me->query("id"));
	  command("say С������ܺá���Ҫ��л�����ܹ���������������Ļ�����");
	  return 1;
  }
  if(me->query(QUESTDIR3+"over"))
  {
	  command("say .............");
	  command("blush "+me->query("id"));
	  return 1;
  } 
	command("say .............");
	command("blush "+me->query("id"));
	if(random(2)) command("zxx2");
	else command("sigh");
	return 1;
}
int ask_miaorenfeng() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
  	command("thank "+me->query("id"));
	  command("say ���������ܺá���Ҫ��л�����ܹ�����������ҵĶ�Թ��");
  	command("thank "+me->query("id"));
	  return 1;
  }
  if(me->query(QUESTDIR2+"over"))
  {
	  command("blush "+me->query("id"));
	  command("say ����һ����������ϧ֮ǰ��һֱԩ��������");
	  return 1;
  } 
	command("say .............");
	command("consider");
	command("say �Ҳ�������������ҵ�����˽��ã�Ϊ��ʹ����˶��֣�����ƽ��Ϊ��ȴ�й������䣡");
	return 1;
}
int ask_tian() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("sigh "+me->query("id"));
	  command("say ����������һ�ž�����Ҳ���������ְֻ���");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  command("heng");
	  command("say ȷʵû���뵽������˸��ӡ���֪�������������ڻ�������......");
    tell_object(me,CYN"�㻺����ҡ��ҡͷ��̾����������ԹԹ��ʱ�ˡ�\n"NOR);
	  return 1;
  } 
	command("say ��˵���������������ţ��ܾò�֪�����ˡ����������Ŵ�����ǰ�ˡ�");
	return 1;
}

int accept_object(object who, object ob,object me)
{
	 if(ob->query("id")=="liangye daofa")
   {
   	 command("ah "+(string)who->query("id"));
     if(who->query_temp(QUESTDIR1+"liangye") && who->query(QUESTDIR1+"start"))
     {
     	/*
     	��Ϊ���������Ÿ������������־�ѧ��һ��ȭ�����ף��Ǳ��Ǻ���ȭ���͵����ľ��塣
     	�Ȿȭ�����ױ�������ͷ����ҳ��ȱ�������������Ź���ȱ��ȭ���������ܾ������ǲ�������ô�����ù������ǲ������š�
     	���»�Ե�ɺϣ����ֻ�͵ȥ���ܾ��һ����ˣ�����һ���ڻ��ͨ���书����һ��ǧ�
     	*/
     	command("jump "+(string)who->query("id"));
        tell_object(who,HIY"\n�����ҳ����������쳡������ϸ�ؿ������飬���ɾ�������������������ҳ���������Ǵ����δ���������\n"NOR);
        tell_object(who,HIG"���˵��һ����ȥ�置��ȴ�����ɵɵ�ض�������ҳ��������������������������ȫȻ������Ĵ��ڡ�\n\n"NOR);
     	who->start_busy(4);
      remove_call_out("telltruth");
      call_out("telltruth", 4, who);
     }
     else  command("thank "+(string)who->query("id"));
   }
    else
   {
     command("? "+(string)who->query("id"));
   }
   call_out("destroying", 1, ob);        
   return 1;
}
void destroying(object obj)
{
        if(obj) destruct(obj);
        return;
}
void telltruth(object me)
{
	    int i;
	    if(!me) return;
	    if(environment(me)!=environment(this_object()))   	return;
      if(!me->query_temp(QUESTDIR1+"liangye")) return;
      write("\n\n");
     	command("haha");
     	command("say ����������������Һ��ҵ����޷�Բͨ��ȱ�����ڣ�");
     	tell_object(me,YEL"\n�㿴������ò�࣬ͬʱ�Ѵ��ֻ����������Ĺ���20��ǰ�����һЩ��Ϣ���ߺ�쳣��ӱ��䵽�����\n"NOR);
     	tell_object(me,YEL"����Ϊ��һ�������ƽ⡰���ý��׺���ᡱ������ж���ɱ��˵�˺�һ�ᣬ��˵�ꡣ\n\n"NOR);  

     	command("bite");
     	command("say");
     	command("say ������Σ����������������˷�����ǧ����ȷ���ҵĺ��ҵ��������ܹ���豹��棬��Ȼ���˷�\n�������֣��������书���ã�Ҳ�ر��˳�");
      me->set(QUESTDIR1+"over",1);
   	  me->add("max_neili",me->query_skill("force")/2);
   	  me->add("combat_exp",me->query_skill("force"));
      i=random(40)+80;
      me->add("mana",i);
    	tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ���ҳ����ƪ�����"+(int)me->query_skill("force")/2+"�����������"+(int)me->query_skill("force")+"�㾭�齱����\n\n"NOR);	
	    log_file("quest/FEIHU", sprintf("%s(%s) �ҿ�ѩɽ�ɺ�Quest��ҳ����ƪ,ʱ�� %s�����%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), ctime(time()),me->query_skill("force")/2,me->query_skill("force") ,i) );
     	me->delete_temp(QUESTDIR1+"liangye");
      return;
}
void kill_ob(object me)
{       
	 command("sneer " + me->query("id"));
	::kill_ob(me);
}
int start_condition(object ob)
{
	 if(!ob) return 0;
   ob->set_skill("force", 300);
	 ob->set_skill("dodge", 300);
	 ob->set_skill("parry", 300);
	 ob->set_skill("blade", 300);
	 ob->set_skill("cuff",300); 
	 ob->set_skill("taxue-wuhen",300);
	 ob->set_skill("zhentian-quan",300);
	 ob->set_skill("lengquan-shengong",300);
	 ob->set_skill("hujia-daofa",300);
   ob->map_skill("force","lengquan-shengong");
	 ob->set("combat_exp", 2000000);
	 ob->set("max_qi", 30000);
	 ob->set("max_jing", 3000);
	 ob->set("max_neili", 5000);
	 ob->set("eff_jingli",3000);
	 ob->set("qi",30000);
	 ob->set("jing",3000);
	 ob->set("jingli",3000);
	 ob->set("neili", 5000);
   return 1;
}
int power_condition(object me,object ob,int p)
{
	  int i;
    if (!present("blade",ob))
	    carry_object(BINGQI_D("blade"))->wield();
	  else command("wield blade");
    ob->set_temp("quest/ѩɽ�ɺ�/�书/lengquan",1);
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
	  ob->set_skill("lengquan-shengong",i+random(50));
	  ob->set_skill("hujia-daofa",i+random(50));
	  ob->map_skill("force","lengquan-shengong");
 	  i=me->query("combat_exp");
	  ob->set("combat_exp",i);
	  i=me->query("neili");	  
	  if(i<15000) i=15000;
	  ob->set("neili", i);	  
	  i=me->query("max_neili");	  
	  if(i<6000) i=6000;
	  ob->set("jiali",200);
	  ob->set("max_neili", i);	  
  	i=me->query("max_qi");	  
	  ob->set("max_qi", i*(2+random(3)));	  
 	  ob->set("eff_qi", ob->query("max_qi"));	
 	  ob->set("qi", ob->query("max_qi"));	
    return 1;
}
int do_hit(string arg)
{
         object me,ob;
         me=this_player();
         ob=this_object();
         if((arg==("hu"))||(arg==("hu fei"))){       
           	command("sneer");
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	return 1;
         }
         return 0;        
}

void do_halt(object me)
{
	if(!this_object()->is_fighting() && !me->is_fighting()) return;
   command("say �ҿ�û�����ں���ȥ�ˣ��´��ٽ����ɡ�");
   remove_call_out("do_halt");
   remove_call_out("try_fight");
	 this_object()->delete("quest/try_fight");
	 this_object()->delete("quest/try_fight_id");
   start_condition(this_object());
	 command("halt");
   this_object()->remove_all_killer(); 
   me->remove_all_killer();  
   return;
}
void unconcious()
{
	object me,ob=this_object();
	
	if(this_object()->query("quest/try_fight"))
	{
	  command("ah");
    command("halt");
    start_condition(ob);
	  if(ob->query("quest/try_fight_id"))
	  {
	  	me=find_player(ob->query("quest/try_fight_id"));
	  	if(!me) return 0;
	  	if(!me->query_temp(QUESTDIR+"����/hu_fighting")) return 0;
	    if(environment(me)!=environment(this_object()))  return 0;
	  	me->delete_temp(QUESTDIR+"����/hu_fighting");
	  	me->add("combat_exp",me->query_skill("force")/2);
	    command("thumb "+me->query("id"));
	    command("admire "+me->query("id"));
	  	tell_object(me,HIR"\n����һ���භ���㷢���Լ����书���м���������"+me->query_skill("force")/2+"�㾭�顣\n"NOR);
	  }
	   ob->delete("quest/try_fight");
	   ob->delete("quest/try_fight_id");
     ob->remove_all_killer();   
     me->remove_all_killer();   
     remove_call_out("do_halt");
     remove_call_out("try_fight");
  }
  else
  {
	command("why");
	::unconcious();
  }
}
void die()
{
	object me,ob=this_object();
	
	if(this_object()->query("quest/try_fight"))
	{
	  command("ah");
    command("halt");
    start_condition(ob);
	  if(ob->query("quest/try_fight_id"))
	  {
	  	me=find_player(ob->query("quest/try_fight_id"));
	  	if(!me) return 0;
	  	if(!me->query_temp(QUESTDIR+"����/hu_fighting")) return 0;
	    if(environment(me)!=environment(this_object()))   	return 0;
	  	me->delete_temp(QUESTDIR+"����/hu_fighting");
	  	me->add("combat_exp",me->query_skill("force")/2);
	  	tell_object(me,HIR"\n����һ���භ���㷢���Լ����书���м���������"+me->query_skill("force")/2+"�㾭�顣\n"NOR);
	    command("thumb "+me->query("id"));
	    command("admire "+me->query("id"));
	  }
	   ob->delete("quest/try_fight");
	   ob->delete("quest/try_fight_id");
     ob->remove_all_killer();   
     remove_call_out("do_halt");
     remove_call_out("try_fight");
  }
  else
  {
	command("why");
	::die();
  }
}
/*
int ask_me1() 
{
	object me = this_player();
	{
	command("say �����ҵ����ͺųơ���������޵��֡������˷��ڴ˱��䣬���˷��Զ���\n"
"���ҵ�����������������ѳ�򡣴���������ɱ�����ˣ���������ʬ���......������\n"
"�����˺�����ٰ���ྴ���أ����˷���ô������˺��֣�");
	command("consider");
	me->set_temp("marks/ah1",1);
	return 1;
	}
}

int do_emote()
{
	object ob = this_object(); 
	if(this_player()->query("id")=="yan ji") {
	  command("say �ֻ���ԭ������������຦���ҵ�����ȥ���ɣ�");
	  message_vision("$Nһ����$n�����ڵء�\n", ob,present("yan ji"));
	  present("yan ji")->die();
	  command("say ��ȥɱ���Ǹ����ũ��Ϊ��������");
	  message_vision("$N����ææ�뿪�ˡ�\n",ob);
	  destruct(ob);
	  return 1;
	  }
}
*/
