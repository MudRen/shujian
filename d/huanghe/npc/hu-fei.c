//hufei.c
//by tangfeng@SJ
//�����ͺ��ҵ������趨��Щ���ã������޸ģ�������̨���䣬������������
//���ҵ���skills��Ȼ��ɣ��书���������趨
// Update By lsxk@hsbbs addͨ����Ʒ��߽�quest���� 2007/7/20
// By Spideiri@ty �����츳ϵͳ
inherit F_MASTER;
inherit NPC;
//inherit FIGHTER;
#include <ansi.h>
//inherit F_SSERVER;

#define QUESTDIR "quest/ѩɽ�ɺ�/"
#define QUESTDIR1 "quest/ѩɽ�ɺ�/��ҳ����ƪ/"
#define QUESTDIR2 "quest/ѩɽ�ɺ�/����ƪ/"
#define QUESTDIR3 "quest/ѩɽ�ɺ�/��ҩƪ/"
#define QUESTDIR4 "quest/ѩɽ�ɺ�/�书/"

//int do_halt1(string arg);
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
int killing();
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
	    "�ɶ�������һ���Ķ��ӡ�\n"
	    "����������ף�����������һͷŨ����ȴ����裬���������������Ҳݡ�"NOR);
	set("str", 25+random(30));
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("per", 25);
	set("shen_type", 1);
	set("unique", 1); //ǧ�������Ⱒ������趨
    set(QUESTDIR4+"hujiadaofa",1);
    set(QUESTDIR4+"lengquanshengong_teach",1);
	set_skill("force", 300);
    set("no_get", 1);
    set("no_bark", 1);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("cuff",300); 
	set_skill("taxue-wuhen",300);
	set_skill("zhentian-quan",300);
  set_skill("lengquan-shengong",300);
	set_skill("hujia-daofa",300);
	map_skill("force","lengquan-shengong");
	map_skill("cuff","zhentian-quan");
	map_skill("dodge","taxue-wuhen");
	map_skill("blade","hujia-daofa");
	map_skill("parry","hujia-daofa");
	set("double_attack",1);
    prepare_skill("cuff", "zhentian-quan");
	set("combat_exp", 2000000);
	set("max_qi", 30000);
	set("max_jing", 30000);
	set("max_neili", 5000);
	set("eff_jingli",30000);
	set("qi",30000);
	set("jing",30000);
	set("jingli",30000);
	set("neili", 5000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       (: exert_function, "lengquan" :),
       (: perform_action, "blade.feidao" :),
       (: perform_action, "blade.luandao" :)
     }));
    set("inquiry", ([
    "��һ��" : (: ask_huyidao :),
    "hu yidao" : (: ask_huyidao :),
    "���ҵ���" : (: ask_hujiadaofa :),
    "hujia-daofa" : (: ask_hujiadaofa :),
    "��ҳ����" : (: ask_liangyedaofa :),
    "����" : (: ask_jiaoliang :),
    "�д�" : (: ask_jiaoliang :),
    "����" : (: ask_biwu :),
    "20��ǰ" : (: ask_biwu :),
    "����" : (: ask_biwu :),
    "����" : (: ask_biwu :),
    "����" : (: ask_zhiliao :),
    "��ҩ" : (: ask_zhiliao :),   
    "������" : (: ask_miaoruolan :),
    "���˷�" : (: ask_miaorenfeng :),
    "�ֻ�" : (: ask_yanji :),
    "������" : (: ask_cheng :),   
    "���ũ" : (: ask_tian :),
    "������" : (: ask_tian :),   
    "�ҳ�" : (: ask_jiachou :),
     "����" : (: ask_jiachou :),
    "���" : (: ask_jiachou :),
    "����" : (: ask_jiachou :),
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
  if (!this_object()->query_temp("biwu")&& interactive(ob = this_player()) ) {
       remove_call_out("greeting");
       call_out("greeting", 2, ob);
  }       
  add_action("do_answer","answer");
  add_action("do_hit", "hit");
}

void greeting(object me)
{
  int shen,i;
  if(!me) return;
  if(environment(me)!=environment(this_object())) return;
  shen = me->query("shen");
  if(me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"over")&&!me->query(QUESTDIR2+"over"))
  {
	me->start_busy(1);
	tell_object(me,CYN"\n�㼱æ�ں�쳵Ķ��������ؽ�������ߺ�쳣�������Ը�����������....\n\n"NOR);
    tell_room(environment(me),HIC"\nֻ��"+me->query("name")+"�����������ں�쳵Ķ���������˵��ʲô��\n\n"NOR, ({ me }));
  	command("chat* cry");
	tell_room(environment(me),HIC"\n���ͻȻ������������е��������ũ�������ƺ��в���֮��"NOR, ({}));
    tell_object(me,HIW"\n�����ũ����ֻ�����ɱ��֮����Ϊ�����ŵ�������ɢ����ζ�ԹҲֻ�ܲ�����֮��\n"NOR);
  	tell_object(me,HIG"�㲻֪����ϲ�Ǳ��������������Ժ����˵Ҳ��Ҳ�Ǹ��˽ᡣ\n\n"NOR);	
  	command("whisper "+me->query("id")+" ���������֪��������Σ�");
  	tell_object(me,HIC"���ͷ����������ȥ���ׯ�������鲻����������ЪϢΪ�\n"NOR);	
	tell_room(environment(me),HIC""+me->query("name")+"���쳵��˵�ͷ����ɫ�����ż���\n"NOR, ({}));
    //�趨���
    me->set(QUESTDIR2+"over",1);
    me->delete_temp(QUESTDIR2+"over");
    me->set(QUESTDIR+"time",time());
    me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));  
    //����
    me->add("combat_exp",me->query_skill("force")*3/2);
   	i=180+random(40);
   	me->add("mana",i);
    tell_object(me,YEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ�����ƪ�����"+(int)me->query_skill("force")*3/2+"�㾭�齱����"+i+"��������\n"NOR);   
    log_file("quest/FEIHU", sprintf("%s(%s) ����ƪ��ɡ�������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), me->query_skill("force")*3/2,i ) );
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
  	message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
	  command("say ��ĸ�л�̹��Ҫ�����������ұ���������");
	  command("think");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"getjieyao"))
  {
  	message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
	  command("suicide1");
	  command("say ��ĸ�л�̹�����ǻ��ǸϿ�ȥ����������ɡ�");
	  return 1;
  }
  if(me->query(QUESTDIR3+"start")&& (me->query_temp(QUESTDIR3+"jieyao2")||me->query_temp(QUESTDIR3+"qixinghaitang")))
  {
  	message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
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
    message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
	  command("blush");
	  command("say �̹��ﵱ���������й�һ��֮����ֻ���������ںδ����������......");
	  command("sigh");
	  return 1;
  } 
  message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
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
  message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
	command("say �����ҵ����ͺųơ���������޵��֡������˷��ڴ˱��䣬���˷��Զ���\n���ҵ�����������������ѳ�򡣴���������ɱ�����ˣ���������ʬ���......������\n"
          "�����˺�����ٰ���ྴ���أ����˷���ô������˺��֣�");
	command("consider");
	return 1;
}

int ask_hujiadaofa() 
{
	object me = this_player();
	object ob = this_object();
	int i,lv;
	if(me->query_condition("killer"))
	 {
	   command("fear "+me->query("id"));
     command("say С�Ĺٸ�ͨ����");
	   return 1;
   }
    if(!me->query(QUESTDIR4+"hujiadaofa") && me->query("combat_exp")<= 2000000)
   {
     command("@@ "+me->query("id"));
     command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
     return 1;
   } 
	if(me->query(QUESTDIR2+"start") && !me->query(QUESTDIR3+"over"))
  {
	  command("shake "+me->query("id"));
	  command("say ����ʱ��������⵶�������Ժ��д�ɡ�");
	  return 1;
  } 

  if(me->query(QUESTDIR4+"hujiadaofa"))
  {
   if(me->query("potential")<= 5)
   {
	  command("kick "+me->query("id"));
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
    me->improve_skill("hujia-daofa", 150+random(me->query_int()*2));
    me->improve_skill("blade", random(me->query_int())/2);
    //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        lv = me->query("max_pot")-100;
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������˺��ҵ����ľ������ڡ�\n"NOR);
            me->set_skill("hujia-daofa",lv);
            }

    return 1;
   }
  }   
  //600sec�д�һ�����
  if(ob->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ��Щ���ˣ��⵶�������Ժ��д�ɡ�");
	  return 1;   
  }
  //��vip��ң�ֻ��ʧ������
  if(me->query(QUESTDIR4+"hujiadaofa_fail")>=3 && me->query("registered")<3)
  {
	  command("shake "+me->query("id"));
	  command("say ����ʱ��������⵶�������Ժ��д�ɡ�");
	  return 1;
	}
	//�书ѧϰ֮����Ҫ���һ�죬������Ҫ���1M
	//ע�������Ǻ���ҽ���ʹ��ͬһ����ǡ�
	if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<86400)
	{
	  command("shake "+me->query("id"));
	  command("say �������д赽����ɣ�����ɡ�");
	  return 1;
  }
   if(me->query(QUESTDIR4+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"combat_exp")<500000 &&!me->query("cw_exp"))
	{
	  command("look "+me->query("id"));
	  command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
	  return 1;
  }
  if(me->query(QUESTDIR1+"over"))
  {
	command("nod "+me->query("id"));
    message_vision(HIB"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, ob);
    //���æµ
    ob->set_temp("busy",1);
    remove_call_out("busy_pass");
	call_out("busy_pass",600, ob);
    power_condition(me,ob,300+random(100));
	  for ( i = 0; i < 6+random(6);i++)
	  {
         if (!present(me,environment(ob)) || me->query("qi") <= me->query("max_qi")/20 ||me->query("eff_qi") <= me->query("max_qi")/20 || me->query("jing") <= 50 || me->query("jingli") <= 50) 
         {
            if(random(2))command("sneer");
            else if(random(2)) command("say ��λ"+RANK_D->query_respect(me) +"�书δ�ܷ�豹��棬ֻ������������ҵ����ľ�����");
         	  me->reincarnate();
            return 1;
         }
         else
         {
            if(random(2)) command("sneer "+me->query("id"));
            else command("say С���ˣ�����һ�С�");
            ob->delete_temp("quest/ѩɽ�ɺ�/�书/lengquan");
            COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
            ob->set_temp("quest/ѩɽ�ɺ�/�书/lengquan",1);
          }
    }
    ob->delete_temp("quest/ѩɽ�ɺ�/�书/lengquan");
    start_condition(ob);
    command("smile "+me->query("id"));
    message_vision(HIC"\n\n������������һ�������ѹ���$n΢Ц�Ŷ�$N˵�������ղ���ʹ�õ������ɿ�����ˣ���\n"NOR,me,ob); 
    //���ʱ��;���
    me->set(QUESTDIR4+"time",time());
    me->set(QUESTDIR4+"combat_exp",me->query("combat_exp"));
    tell_object(me,YEL"��ƴ���ػ���˲�佻�ֵ�һĻ�������Ÿղŵ��������㿪ʼ����˼����.........\n"NOR);
    remove_call_out("thinking");
		call_out("thinking",0, me, ob);
    me->start_busy(1);
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

int busy_pass(object ob)
{
	if(!ob) return 0;
	if(ob->query_temp("busy")) ob->delete_temp("busy");
	if(ob->query("busy")) ob->delete("busy");
   remove_call_out("busy_pass");
  message_vision(HIC"\n$N������������\n"NOR,ob); 
  return 1;
}

int thinking(object me, object ob)
{
	int i,p;
	if(!me) return 0;
  if(environment(me)!=environment(this_object())) 
  {
  	start_condition(ob);
    if(random(2)) message_vision(HIC"\n$N����������������$n��Ȼ�������ѣ�û�ϵô���һ����\n"NOR,ob,me); 
    else message_vision(HIC"\n$N�ɻ��ʵ�����~~~���أ�$n�����أ�\n"NOR,ob,me); 
  	return 1;
  }

  if(me->query_temp(QUESTDIR4+"thinking")<(3+random(3)))
	{
		me->add_temp(QUESTDIR4+"thinking",1);
    if(random(2)) tell_object(me,HIG"\n��Ŭ���ػ���ղŵ�ÿһ��ÿһʽ������������Ӱ���໥����ÿһ��ÿһʽ�㶼Ŭ��ȥ�����...\n"NOR);
    else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô����Ŭ���ػ���ղŵ�ÿһ��ÿһʽ�����ܳ�ָо������������ͼ���...\n"NOR);
          tell_room(environment(me),HIC""+me->query("name")+HIC"�ƺ���˼����ʲô��һ����ü��չ�����ӡ�\n"NOR, ({}));
	  remove_call_out("thinking");
		call_out("thinking",4+random(3), me, ob);
	}
	else
	{
	  //�ѶȽ��ͣ��Ͼ������ĺ��ҵ�������һ��
    //���������ͨ����Ʒ����΢��߳ɹ����ʡ�  by lsxk@hsbbs 2007/7/20
      if(me->query_temp("sj_credit/quest/public/hjdf"))
          p=random(me->query("kar")+10);
      else
		p=random(me->query("kar"));
      me->delete_temp("sj_credit/quest/public/hjdf");
          if(p> 27 && me->query("kar")<31 && QUEST_D->questing(me,1,0,1))
      {
       tell_object(me,HIG"\n���������У�ͻȻ��������һ�С�\n"NOR);
       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
       command("ah");
       command("congra "+me->query("id"));
       command("chat* congra "+me->query("id"));
       tell_object(me,HIR"�����˺�쳵�ָ�㣬�Ժ��ҵ����İ����ƺ���Щ�ĵá�\n"NOR);
       tell_object(me,HIR"ֻ���㷢������ҵ�������Ҫ��Ȫ�񹦲��ܷ���ȫЧ��\n"NOR);
       me->set(QUESTDIR4+"hujiadaofa",1);
       me->delete_temp(QUESTDIR4+"thinking");
   	   i=180+random(40);
   	   me->add("mana",i);
  	   tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ����ҵ���ƪ�������"+i+"��������\n\n"NOR);	
       log_file("quest/FEIHU", sprintf(HIR"%s(%s) ʧ��%d�κ�ҿ����ҵ��������%d����������Դ��%d;���ȡֵ��%d��\n"NOR, me->name(1),me->query("id"),me->query(QUESTDIR4+"hujiadaofa_fail"), i,me->query("kar"),p ) );
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       command("poor "+me->query("id"));
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
	   me->add(QUESTDIR4+"hujiadaofa_fail",1);
	   log_file("quest/FEIHU", sprintf(HIR"%s(%s) ���ҵ���ʧ�ܴ�����%d��,��Դ��%d�����ȡֵ%d��\n"NOR, me->name(1),me->query("id"),me->query(QUESTDIR4+"hujiadaofa_fail"),me->query("kar"),p) );
       if(me->query(QUESTDIR4+"hujiadaofa_fail")>=3 && me->query("registered")<3)
       {
      	tell_object(me,HBYEL"\n���ź�����"+NATURE_D->game_time()+"���һ�γ��Խҿ�ѩɽ�ɺ����ҵ�����ȴû�гɹ���\n\n"NOR);	
        log_file("quest/FEIHU", sprintf("%s(%s) ���һ�γ��Խҿ�ѩɽ�ɺ����ҵ�����ȴû�гɹ������� %d��\n", me->name(1),me->query("id"), me->query("combat_exp") ) );
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
	  command("say ��ν���𲻹����죬��Ȼ֪��ɱ���ҵ������֣������������书���ã�Ҳ����������");
	  if(!me->query_temp(QUESTDIR2+"answer")){
		  //ѯ�ʼҳ����漰quest�ĵ�һ����������ʱ�������죬������Ҫ���500K
		  if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<43200)
		  {
			  command("cry "+me->query("id"));
			  command("say �����������Ѿ����鷳��"+me->query("name")+"�ˣ����������Ҳ������һʱ��");
			  return 1;
		  }
                  if(me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000 && !me->query("cw_exp"))
		  {
			  command("look "+me->query("id"));
			  command("say ���������㵱ǰ�ľ�����»���������������������ץ��ȥ����ȥ�ɡ�");
			  return 1;
		  }
		  if(me->query(QUESTDIR4+"win_hu") || me->query(QUESTDIR4+"fight_hu")>=3)
		  {
			  command("look "+me->query("id"));
			  command("sigh");
			  if(!me->query(QUESTDIR4+"win_hu"))
				  command("whisper "+me->query("id")+" ��λ"+RANK_D->query_respect(me) +"�书Ҳ�㲻����֪���Ƿ�Ը���æ��");
			  else command("whisper "+me->query("id")+" ��λ"+RANK_D->query_respect(me) +"���书��������֪���Ƿ�Ը���æ��");
			  me->set(QUESTDIR+"time",time());
			  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
			  command("addoil "+me->query("id"));
			  tell_object(me,HIG"�ش�����answer yes ����answer no\n"NOR);
			  me->set_temp(QUESTDIR2+"answer_",1);
			  log_file("quest/FEIHU", sprintf("%s(%s) �����������ׯ�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
			  return 1;
		  }
		  else
		  {
			  command("look "+me->query("id"));
			  command("say �����Ҷ����Ƕ��֣���ΰ��Ҹ���");
			  return 1;
		  }
	  }
	  else
	  {
		  command("look "+me->query("id"));
		  command("thank "+me->query("id"));
		  command("say ֻҪ��λ"+RANK_D->query_respect(me) +"�ܹ���æ�����²�ʤ�м�����ʵ��Ҳ����ȷ��������ԭί��");
	  }
	  return 1;
  }  
  if(me->query(QUESTDIR1+"over"))
  {

	  command("say ��һֱ����������ɱ���ҵ������֣�ֻ������������������Բ���ȷ�ϣ���������ס�");
	  command("say ��ν���𲻹����죬��Ȼ֪��ɱ���ҵ������֣������������书���ã�Ҳ������͵���ˡ�");
	  command("sigh");
	    //ѯ�ʼҳ����漰quest�ĵ�һ����������ʱ�������죬������Ҫ���500K
       if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<43200)
	   {
		   command("cry "+me->query("id"));
		   command("say �����������Ѿ����鷳��"+me->query("name")+"�ˣ����������Ҳ������һʱ��");
		   return 1;
	   }
           if(me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000 && !me->query("cw_exp"))
	   {
		   command("look "+me->query("id"));
		   command("say ���������㵱ǰ�ľ�����»���������������������ץ��ȥ����ȥ�ɡ�");
		   return 1;
	   }
        //����ʤ��hu,���߱�������֮��
	   if(me->query(QUESTDIR4+"win_hu") || me->query(QUESTDIR4+"fight_hu")>=3)
       {
   		   command("look "+me->query("id"));
		   command("sigh");
		   if(!me->query(QUESTDIR4+"win_hu"))
			   command("whisper "+me->query("id")+" ��λ"+RANK_D->query_respect(me) +"�书Ҳ�㲻����֪���Ƿ�Ը���æ��");
		   else command("whisper "+me->query("id")+" ��λ"+RANK_D->query_respect(me) +"���书��������֪���Ƿ�Ը���æ��");
		   me->set(QUESTDIR+"time",time());
		   me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
		   
		   tell_object(me,HIG"�ش�����answer yes ����answer no\n"NOR);
		   command("addoil "+me->query("id"));
		   me->set_temp(QUESTDIR2+"answer_",1);
		   me->set(QUESTDIR2+"start",1);//?? ��ô�����û�гɹ�??
		   log_file("quest/FEIHU", sprintf("%s(%s) �����������ׯ�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
		   return 1;
	   }
	   else
	   {
		   command("look "+me->query("id"));
		   command("say �����Ҷ����Ƕ��֣���ΰ��Ҹ���");
		   return 1;
	   }
  }  
  if(me->query(QUESTDIR1+"start"))
  {
	  command("shout");
	  command("say ��һֱ�������˷����ɱ���ҵ������֣�ֻ�����������������Բ���ȷ�ϡ�");
	  return 1;
  }  
  if(me->query_temp(QUESTDIR1+"jiachou"))
  {
    message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object()); 
	  command("consider");
	  command("say ����Ĳ����ף��벻ͨ�����еı仯��ֻ��ϧ�ҵ������ò������ס�");
	  return 1;
  } 

  message_vision(YEL"$N����¶������֮�顣\n"NOR,this_object());   	 	 	 	 	 	 	
	command("say �����ҵ����ͺųơ���������޵��֡������˷��ڴ˱��䣬���˷��Զ���\n"
"  ���ҵ�����������������ѳ�򡣴���������ɱ�����ˣ���������ʬ���......������\n"
"  �����˺�����ٰ���ྴ���أ����˷���ô������˺��֣�");
	command("consider");
	me->set_temp(QUESTDIR1+"jiachou",1);
  me->set(QUESTDIR+"time",time());
  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
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
	  me->set_temp(QUESTDIR2+"answer",1);
	}
	else
	{
    tell_object(me,CYN"\n�㾪���˵������ȴ��Щ���ɣ��������ô�����������أ�������Ϊ�㣬��ҲҪȥһ�����ׯ�ɣ�\n"NOR);
	  me->set_temp(QUESTDIR2+"answer",1);
	}
	return 1;	
}

int ask_jiaoliang() 
{
	object me = this_player();
	object ob = this_object();
	object room;
	mapping mp;
	int i;
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
     command("say С�Ĺٸ�ͨ����");
	   return 1;
	}
  if( mapp(mp = me->query_conditions_by_type("poison")) && sizeof(mp)>0 )
	{
	   command("poor "+me->query("id"));
     command("say �㻹�����κ���Ĳ������д�ɣ�");
	   return 1;
	}  
  if( mapp(mp = me->query_conditions_by_type("killer")) && sizeof(mp)>0 )
	{
	   command("sigh "+me->query("id"));
     command("say �㻹���Ƚ������ĸ��˶�Թ�����д�ɣ�");
	   return 1;
	}    
  if(!me->query(QUESTDIR3+"over") && me->query(QUESTDIR2+"start"))
  {
	  command("shake "+me->query("id"));
	  command("say ����ʱ����������������������Ҫ����");
	  return 1;
  } 
  if(ob->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ���д��꣬�Ժ��д�ɡ�");
	  return 1;   
  }
  //��ͨ�������,
   if(me->query(QUESTDIR4+"fight_hu")>=3 && me->query("registered")<3)
  {
	  command("shrug "+me->query("id"));
	  command("say ��ɫ�����ˣ��⵶�������Ժ��д�ɡ�");
	  return 1;
	}

	//��������ʱ����3��Сʱ��
  if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<(3600*3))
	{
	  command("shake "+me->query("id"));
	  command("say �������д赽����ɣ��Ժ�ɡ�");
	  return 1;
  }
        if((me->query(QUESTDIR4+"fight_hu")>=3 && me->query(QUESTDIR4+"fight_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"fight_exp")<500000 && !me->query("cw_exp"))
                ||(me->query(QUESTDIR4+"fight_hu")<3 &&me->query(QUESTDIR4+"fight_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"fight_exp")<100000)&& !me->query("cw_exp"))
	{
		command("shake "+me->query("id"));
		command("say ���书ûʲô��ı仯������ץ������ȥ�ɡ�");
		return 1;
	}
  //����̫���ֱ�������赹���ٺ�
  if(random(me->query("combat_exp"))<random(ob->query("combat_exp")/2) && !wizardp(me))
  {
	  for ( i = 0; i < 1+random(3);i++)
	  {
	     COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
    }
    return 1;
  }
  if(me->query(QUESTDIR1+"over"))
  {
	  command("nod "+me->query("id"));
    message_vision(HIY"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, this_object());
    //�������书��400�ȼ����ϣ���Ȼ��˻��ǱȽ�Σ�ա�
    power_condition(me,ob,300+random(100));  
    //��쳺���ҽ���������һ������
    if (!(room = find_object("/d/huanghe/lianwuchang")))
       room = load_object("/d/huanghe/lianwuchang");
    if( !room )
 	  {
	     command("shake "+me->query("id"));
	     command("say ��ʱû�п���ĳ��ؽ������Ժ�ɣ�����֪ͨ��ʦһ�¡�");
	     return 1;
    }
    if(room->query_temp("biwu"))
 	  {
	     command("shake "+me->query("id"));
	     command("say ��ʱû�п���ĳ��ؽ������Ժ�ɣ�����֪ͨ��ʦһ�¡�");
	     return 1;
    } 
    //��־
    me->set(QUESTDIR4+"time",time());
	me->set(QUESTDIR4+"fight_exp",me->query("combat_exp"));
    me->set_temp(QUESTDIR4+"fight_id",ob->query("id"));
    me->add(QUESTDIR4+"fight_hu",1);
    ob->set_temp("busy",1);
    ob->set_temp("biwu",1);
	  ob->set_temp("quest/try_fight_id",me->query("id"));

    message_vision(HIY"$N��$nһ���ֵ�����������������$N��$n����ææ���뿪�صء�\n"NOR, ob,me);     
    ob->move(room);
    me->move(room);
    message_vision(YEL"$N����ææ���������䳡��\n"NOR, ob);    
    message_vision(YEL"$N����ææ���������䳡��\n"NOR, me);    
	  command("sneer");
    remove_call_out("busy_pass");
		call_out("busy_pass",600, ob);
    me->start_busy(1);
    ob->start_busy(1);
  log_file("quest/FEIHU", sprintf("%s(%s) �����ٴκͺ�쳽��������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
	  return 1;
  }
	command("say ����ұ��ԣ������ˣ�");
  power_condition(me,ob,250+random(200));
	for ( i = 0; i < 2+random(3);i++)
	{
	     COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
  }
	command("sneer");
	start_condition(ob);
	return 1;
}

int ask_liangyedaofa() 
{
	object me = this_player();
  if(me->query(QUESTDIR1+"over"))
  {
  	command("thank "+me->query("id"));
	  command("say ��л"+RANK_D->query_respect(me) +"�����ҵ�����ҳ�������Ҳ��ܽ����ҵ����ڻ��ͨ��");
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
    message_vision(HIC"$N������ҡ��ҡͷ��̾����������ԹԹ��ʱ�ˡ�\n"NOR, me);
	  return 1;
  } 
	command("say ��˵���������������ţ��ܾò�֪�����ˡ����������Ŵ�����ǰ�ˡ�");
	return 1;
}

int accept_object(object who, object ob,object me)
{
	if(who->query_condition("killer"))
	{
	   command("shake "+who->query("id"));
     command("say ��Ŀǰ���ٸ�ͨ��������θ���"+ob->name()+"��");
	   return 0;
	 }
	 if(ob->query("id")=="liangye daofa")
   {
   	 command("ah "+(string)who->query("id"));
     if(who->query_temp(QUESTDIR1+"liangye") && who->query(QUESTDIR1+"start"))
     {
     	command("jump "+(string)who->query("id"));
      tell_object(who,HIC"\n�����ҳ����������쳡������ϸ�ؿ������飬���ɾ�������������������ҳ���������Ǵ����δ���������\n"NOR);
      tell_object(who,HIC"���˵��һ����ȥ�置��ȴ�����ɵɵ�ض�������ҳ��������������������������ȫȻ������Ĵ��ڡ�\n"NOR);
	    tell_room(environment(who),HIC"\n����ƺ���"+who->query("name")+"�õ�һ���书�ؼ�����Ȼ��������������\n"NOR, ({ who }));
     	who->start_busy(1);
      remove_call_out("telltruth");
      call_out("telltruth",6, who);
     }
     else  command("thank "+(string)who->query("id"));
     call_out("destroying", 1, ob); 
     return 1;
   }
    else
   {
     command("? "+(string)who->query("id"));
     return 0;
   }
}
void destroying(object obj)
{
        if(!userp(obj)) destruct(obj);
        return;
}
void telltruth(object me)
{
	    int i;
	    if(!me) return;
	    if(environment(me)!=environment(this_object()))
	    {
   	    message_vision(HIB"\n$nͻȻ̧��ͷ�����ɻ��ʵ�����$N�Ѿ����ˣ��һ�û�кúø�л�ء���\n"NOR, me, this_object());
	    	return;
	    }
      if(!me->query_temp(QUESTDIR1+"liangye")) return;
     	command("haha");
     	command("say ����������������Һ��ҵ����޷�Բͨ��ȱ�����ڣ�");
     	tell_object(me,YEL"\n�㿴������ò�࣬ͬʱ�Ѵ��ֻ����������Ĺ���20��ǰ�����һЩ��Ϣ���ߺ�쳣��ӱ��䵽�����\n"NOR);
     	tell_object(me,YEL"����Ϊ��һ�������ƽ⡰���ý��׺���ᡱ������ж���ɱ��˵�˺�һ�ᣬ��˵�ꡣ\n\n"NOR);  
	    tell_room(environment(me),HIC"\n"+me->query("name")+"�ƺ����ĸ��ߺ��һЩ���顣\n"NOR, ({}));
     	command("bite");
     	command("say");
     	command("say ������Σ����������������˷�����ǧ����ȷ���ҵĺ��ҵ��������ܹ���豹��棬��Ȼ���˷�\n�������֣��������书���ã�Ҳ�ر��˳�");
      me->set(QUESTDIR1+"over",1);
   	  me->add("max_neili",me->query_skill("force")/3);
          me->add("combat_exp",me->query_skill("force")*2);
      i=random(40)+80;
      me->set(QUESTDIR+"time",time());
      me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
      me->add("mana",i);
          tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ���ҳ����ƪ�����"+(int)me->query_skill("force")/3+"�����������"+((int)me->query_skill("force")*2)+"�㾭�齱���Լ�"+i+"��������\n\n"NOR); 
      log_file("quest/FEIHU", sprintf("%s(%s) ��ҳ����ƪ��ɡ����%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), me->query_skill("force")/3,me->query_skill("force")*2 ,i) );
     	me->delete_temp(QUESTDIR1+"liangye");
      return;
}
void kill_ob(object me)
{       
	command("sneer " + me->query("id"));
  power_condition(me,this_object(),300+random(100));
  remove_call_out("killing");
	call_out("killing", 2);
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
	 ob->set("eff_qi", 30000);
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
          ob->set("max_qi", i*(6+random(3))/4);   
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
int killing()
{
	int i;
	object *enemy,ob,me;
	
	ob=this_object();
	enemy = ob->query_enemy();
	if( !enemy || !arrayp(enemy) ) 
	{
		 remove_call_out("killing");
	   start_condition(ob);
  	 return 0;
  }
	i = sizeof(enemy);
	if(i>4) i=4;
  if(i>0) me=enemy[random(i)];
  else
  {
		 remove_call_out("killing");
	   start_condition(ob);
  	 return 0;
  }
  if(!me || !ob->is_fighting(me) )	
	{
		 remove_call_out("killing");
	   start_condition(ob);
  	 return 0;
  }
  
  if (!present("blade",ob))
  {
	  message_vision(HIR"\n$N�������һԾ����֪�������ﾹȻ���ó�һ�Ѹֵ���\n"NOR,ob); 
  	carry_object(BINGQI_D("blade"))->wield();
  }
	else command("wield blade");
  i=ob->query_temp("pfm");

 //zongjue ����
 if(ob->query_skill_mapped("blade") != "hujia-daofa")
  {
	ob->map_skill("blade","hujia-daofa");
	ob->map_skill("parry","hujia-daofa");
	  message_vision(HIR"\n$N����һЦ����$n���ǵ�������������ȫ��Ч��ʲô���¾Ž��������ϵ����񹦰�����˫����\n"NOR,ob,me); 
  }
  //���Ӿ���
  if(i<(2+random(me->query("int")/5))) i++;
  else 
  {
    ob->delete_temp("quest/ѩɽ�ɺ�/�书/lengquan");
    i=0;
  	if(ob->query_busy())
  	{
  		if(ob->query_busy()>2) ob->start_busy(me->query_busy()/2);
  		else ob->start_busy(random(2));
      if(random(2)) message_vision(HIR"\n$N��ת��Ȫ�񹦣�˲�仯��ԭ������$N�ж����������ֽŶ�ʱ�������࣡\n"NOR, ob);
      else message_vision(HIC"\n$N������Ѩ����ת��Ȫ�񹦣�˲��ԭ������$N�ж��������ѻ�Ϊ���У���������������\n"NOR, ob);
    }
     switch(random(6))
     {
     	case 0:
            message_vision(HIW"\n$N����Գ�ۣ����еĸֵ��������£��仯Ī�⣬������$n����Ҫ����\n" NOR, this_object(),me);
            if(random(3) && !me->query_busy())
            {
            	message_vision(HIC"$n������ʵ���Ǳ��Ī�⣬���ɵ��������⣬��ʽ��ʱ����������\n" NOR, this_object(),me);
              me->add_busy(2+random(4));
            }
            break;
     	case 1:
     		    message_vision(HIR"\n$N���еĸֵ��ó����쵶�ƣ�����������Ļ���һ������$n��\n" NOR, this_object(),me);
	          ob->add_temp("apply/attack", ob->query_skill("blade"));	
	          ob->add_temp("apply/damage", ob->query_skill("blade"));
          	  COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 3);
	          ob->add_temp("apply/attack", -ob->query_skill("blade"));	
	          ob->add_temp("apply/damage", -ob->query_skill("blade"));
	          ob->start_busy(1);
            break;
     }  
    ob->set_temp("quest/ѩɽ�ɺ�/�书/lengquan",1);
  }
  ob->set_temp("pfm",i);
	call_out("killing",1);
  return 1;
}
/*
void die()
{
	object ob=this_object();
	
	if(ob->query_temp("biwu"))
	{
    start_condition(ob);
    if((string)file_name(environment(ob))!="/d/huanghe/lianwuchang")
        message_vision(HIR"\n$N������ͷ���ƺ���������\n"NOR,ob); 
    ob->set_temp("lost",1);
   	ob->remove_all_killer();  
  }
  else
  {
	::die();
  }
}

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
