//miaorenfeng.c
//by tangfeng@SJ
//�޸���ͬhu-fei.c
//������Ȫ�񹦲���
// Update by lsxk@hsbbs addͨ����Ʒ���ӽ�mjjf quest�ɹ����� 2007/7/20
// By Spiderii@ty �����츳

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
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"

void greeting(object me);
void zhenxiang(object me);
void jieshuo1(object me);
void jieshuo2(object me);
void unconcious();
void kill_ob(object me);
int do_hit(string arg);
void do_halt(object me);
void die();
int ask_huyidao();
int ask_biwu();
int ask_zhiliao();
int ask_chuangwang();
int ask_hujiadaofa();
int ask_miaojiajianfa();
int ask_cheng();
int ask_liangyedaofa();
int ask_yanji();
int ask_miaoruolan();
int ask_tian();
int ask_hufei();
int ask_hunjia();
int ask_jiaoliang();
int miao_fight(object me, object ob);
int thinking(object me, object ob);
int killing();
int start_condition(object ob);
int power_condition(object me,object ob,int p);
int busy_pass(object ob);
int skill_check(object me);
int ask_lengquanshengong();

void create()
{
	set_name("���˷�", ({ "miao renfeng", "miao", "renfeng" }) );
	set("gender", "����" );
	set("title", HIY"�����"NOR);
	set("age", 56);
	set("long", 
	    HIR"���ׯׯ�����ųơ�"HIY"��������޵���"HIR"��\n"NOR);
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("per", 25);
	set("shen_type", 1);
	set("unique", 1);
    set(QUESTDIR4+"miaojiajianfa",1);
    set(QUESTDIR4+"lengquanshengong_teach",1);
    set("no_get", 1);
    set("no_bark", 1);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("cuff",300); 
	set_skill("taxue-wuhen",300);
	set_skill("zhentian-quan",300);
	set_skill("lengquan-shengong",300);
	set_skill("miaojia-jianfa",300);
	map_skill("force","lengquan-shengong");
	map_skill("cuff","zhentian-quan");
	map_skill("dodge","taxue-wuhen");
	map_skill("sword","miaojia-jianfa");
	map_skill("parry","miaojia-jianfa");
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
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       (: exert_function, "lengquan" :),
       (: perform_action, "sword.duoming" :),
       (: perform_action, "sword.ci" :),
     }));

  set("inquiry", ([
    "���" : (: ask_hunjia :),
    "���" : (: ask_hunjia :),
    "��ý" : (: ask_hunjia :),
    "��Ȫ��" : (: ask_lengquanshengong :),
    "lengquan-shengong" : (: ask_lengquanshengong :),
    "���" : (: ask_hufei :),
    "hu fei" : (: ask_hufei :),

    
    "��������" : (: ask_chuangwang :),
    "����" : (: ask_chuangwang :),
    "����" : (: ask_chuangwang :),
    
    "��ҽ���" : (: ask_miaojiajianfa :),
    "miaojia-jianfa" : (: ask_miaojiajianfa :),
   
    "��һ��" : (: ask_huyidao :),
    "���ҵ���" : (: ask_hujiadaofa :),
    "�����ں�" : (: ask_hujiadaofa :),

    "��ҳ����" : (: ask_liangyedaofa :),
    "����" : (: ask_jiaoliang :),
    "����" : (: ask_biwu :),
    "����" : (: ask_biwu :),
    "20��ǰ" : (: ask_biwu :),
    "20��ǰ�ı���" : (: ask_biwu :),
    "����" : (: ask_biwu :),
    "����" : (: ask_zhiliao :),
    "������" : (: ask_miaoruolan :),
    "��ҩ" : (: ask_zhiliao :),
    "�ֻ�" : (: ask_yanji :),
    "������" : (: ask_cheng :),
    "���ũ" : (: ask_tian :),
	]));
	setup();
	carry_object("/clone/weapon/sword/sword.c")->wield();
	carry_object("/clone/weapon/sword/sword.c");
	carry_object("/clone/armor/baihu-qiu.c")->wear();
} 

void init()
{
  object me;
	::init();
  if (!this_object()->query_temp("biwu")&& interactive(me = this_player()) ) {
  	   me->start_busy(1);
       call_out("greeting", 2, me);
  }       
  add_action("do_hit", "hit");
}

void greeting(object me)
{
  object jieyao;
  if(!me) return;
  if(environment(me)!=environment(this_object()))
  {
        if( random(2)) command("?");
        else if( random(2)) command("say");
        else if( random(2)) command("sing");
        else if( random(2)) command("love");
        else if( random(2)) command("addoil");
        else command("xixi");
  	return;
  }
	if(me->query_condition("killer"))
	{
	  command("fear "+me->query("id"));
    command("say С�Ĺٸ�ͨ����");
    me->move(__DIR__"lanzhou");
	  return;
	}
  if(me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"getjieyao"))
  {
  	tell_object(me,HIG"\n���߽�������ȴ�������˷��������һ�������Ʒ������㲻��һ��д������꼸�����ۣ�����Ҳ�������ס�\n"NOR);
    message_vision(HIC"$n�ƺ��������Ų�����תͷ��$N����"+RANK_D->query_respect(me) +"�����ˣ�\n"NOR,me,this_object()); 
  	jieyao= present("jie yao", me);
  	if(!jieyao)
  	{
     	tell_object(me,CYN"\n����ǰ׼������ҩ�͸������˷���£��ҷ���ҩ����ʧ�ˡ�\n"NOR);
     	tell_object(me,CYN"��ô�����أ������ǽ�����֣�����ֻ����ȥһ���嶾���ˡ�\n"NOR);
	    tell_room(environment(me),HIC"\n"+me->query("name")+"������ǰ��ʲô��ȴ������ʧ��ʲô��һ���Ļ��š�\n"NOR, ({}));
    log_file("quest/FEIHU", sprintf("%s(%s) ��Ȼ��ʧ��ҩ��ʧ�ܡ����飺%d��\n",me->name(1),me->query("id"),me->query("combat_exp")) );
     	me->set_temp(QUESTDIR3+"jieyao2",1);
     	me->delete_temp(QUESTDIR3+"getjiao");
      return;
    }
    else
    {
  	  tell_object(me,HIY"\n����ǰ���ڷ�ҩ�͸������˷���£������������ҩ�����۾��ϡ�\n"NOR);
  	  command("thank "+me->query("id"));
	  tell_room(environment(me),HIC"\n"+me->query("name")+"�ߵ����˷��ǰ�������ڸ�����ҩ��\n"NOR, ({}));
  	  tell_object(me,HIY"��˳������һ�����ӣ����������λ��ߣ�����ؿ���һ�����Ҳ�֪���Ӻ�˵��\n"NOR);
      destruct(jieyao);
      remove_call_out("zhenxiang");
      call_out("zhenxiang", 6, me);
      return;
    }
  }
  if(me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"kill") && !me->query_temp(QUESTDIR2+"huyidao") && !me->query(QUESTDIR2+"over") && !me->query_temp(QUESTDIR2+"ask_"))
  {
  	command("haha");
	me->start_busy(3);
  	tell_object(me,HIG"\n��ս�������������һ��ˬ�ʵ�Ц����������λ����ǰ��������ĳ���Ǹм��ˣ����㲻���ؿ�һ����\n"NOR);
  	tell_object(me,HIC"������һ�£�����ش��������"+me->query("name")+"������ǡ�������˵أ�������ɺã�\n"NOR);
  	remove_call_out("zhenxiang");
    call_out("zhenxiang", 3, me);
    return;
  }  	

}
void zhenxiang(object me)
{
	int i,p;
  if(!me) return;
  if(environment(me)!=environment(this_object())) 
  {
  	command("chat "+me->name()+"�����أ���ô���Ҳ���?");
  	return;
  }
  if(me->query(QUESTDIR3+"start") && me->query_temp(QUESTDIR3+"getjieyao"))
  {
 	  tell_object(me,HIW"\n���粻��Ϊ�������֣�һ�Ṥ�����������������۾�Ҳ�ͺ��ˡ�����Ҫ��л��ȴ�������˷�̾��������������\n"NOR);
  	tell_object(me,HIW"����һ��ʧ�֣���������Ϸ������������£���̰�ٶ����������޿ܣ��޲��ľ����䣬���ǺεȵĿ��£���\n"NOR);
  	tell_object(me,HIY"ȴ�����������Ц�����������޲����ᡣ��νӢ�ۺ��鲻����ˣ����ɺ�����컯��\n"NOR);
    me->delete_temp(QUESTDIR3+"getjieyao");
    me->set(QUESTDIR3+"over",1);
   	tell_object(me,HIR"������һ�ᣬҲ��Ī����̾��Ҳ�գ�����������һ�νڣ��㲻�ɳ�̾һ������\n"NOR);
	p=10+random(10);
        me->add("max_neili",p);
        me->add("combat_exp",me->query_skill("force")+500);
   	i=180+random(40);
   	me->add("mana",i);
    me->set(QUESTDIR+"time",time());
    me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));  
        tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ���ҩƪ�����"+p+"�����������"+((int)me->query_skill("force")+500)+"�㾭�齱����"+i+"��������\n\n"NOR); 
    log_file("quest/FEIHU", sprintf("%s(%s) ��ҩƪ��ɡ�������%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), p,(me->query_skill("force")+500),i ) );
   	return;
  }
  if(me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"kill")&& !me->query_temp(QUESTDIR2+"kill_")&& !me->query_temp(QUESTDIR2+"huyidao") && !me->query(QUESTDIR2+"over") )
  {
  	message_vision(HIY"ͻȻ$N����һ���Ʒ����������$N������֣�ȴ����Ӳ��Ӳ�ܣ�����ʹ��ʦ���书��ж���Է���������֪˫����$n\n"
  	                  "���Ƹ��ӣ���ʱ��ǰһ�ڣ��ؿ�������$N����������������$n������ֻжȥ��һ�룬��һ�뻹��Ӳ���˹�����\n"NOR,me,this_object()); 
    command("heng");
    if(!me->query("family"))
	{
  	message_vision(HIC"\n$N�е�������������Ұ�������������ȴ��$n������ԭ����"+me->query("name")+"����\n"NOR,me,this_object());
  	message_vision(HIC"$N�ش���������ã���л�ػ�����ȴ����$n˫ĿͻȻ���գ����Ƕ��Է�����$N�ʵ���������������ڸо���Σ���\n\n"NOR,me,this_object());
        message_vision(HIC"$N��ԥ��һ�£�����˵������������λ"+RANK_D->query_respect(me) +"�ײ������������������ׯ��������ʲô����ɣ���\n\n"NOR,me,this_object());
	}
	else
	{
  	message_vision(HIC"\n$N�е�������������Ұ�������������ȴ��$n������ԭ����"+me->query("family/family_name")+"���ӣ�"+me->query("family/master_name")+"ʦ������ɺã���\n"NOR,me,this_object());
  	message_vision(HIC"$N�ش���������ã���л�ػ�����ȴ����$n˫ĿͻȻ���գ����Ƕ��Է�����$N�ʵ���������������ڸо���Σ���\n\n"NOR,me,this_object());
        message_vision(HIC"$n��ԥ��һ�£�����˵����������"+me->query("family/master_name")+"�ײ���������λ"+RANK_D->query_respect(me) +"�Ҳ����ң��������ׯ��������ʲô����ɣ���\n\n"NOR,me,this_object());
	}
    me->set_temp(QUESTDIR2+"kill_",1);
	me->start_busy(3);
    call_out("zhenxiang",3, me);
    return;
  }  	
  if(me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"kill")&& !me->query_temp(QUESTDIR2+"huyidao") && !me->query(QUESTDIR2+"over") && me->query_temp(QUESTDIR2+"kill_"))
  {
  	command("say");
  	tell_object(me,HIG"���˷��Ȼ��˼���ݣ����Ĭ��һ�£�������һ����������ο���ѯ����20��ǰ�Ĺ���......\n"NOR);
	  tell_room(environment(me),HIC"\n"+me->query("name")+"���ǳ�������������˼����ʲô��\n"NOR, ({}));
    log_file("quest/FEIHU", sprintf("%s(%s) �ݼ����˷���飺%d��\n",me->name(1),me->query("id"),me->query("combat_exp")) );
    me->set_temp(QUESTDIR2+"ask_",1);
    me->delete_temp(QUESTDIR2+"kill_");
    remove_call_out("zhenxiang");
    return;
  }  	
}

void kill_ob(object me)
{       
	command("sneer " + me->query("id"));
  power_condition(me,this_object(),300+random(100));
  remove_call_out("killing");
	call_out("killing", 2);
	::kill_ob(me);
}

int do_hit(string arg)
{
         object me,ob;
         me=this_player();
         ob=this_object();
         if((arg==("miao"))||(arg==("miao renfeng"))){       
           	command("sneer");
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
           	return 1;
         }
         return 0;        
}

int ask_cheng() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("thank");
	  command("say ��ĸ�л�̴�ҽ����Ҫ�����������������Ȫ��");
	  return 1;
  } 
  command("say �̹��Ӧ�þ��ǵ���ҩ�����ӣ����ڿ��������嶾�̰ɡ�");
	return 1;
}

int ask_biwu() 
{
	object me = this_player();

  if(me->query(QUESTDIR2+"over"))
  {
	  command("sigh "+me->query("id"));
	  command("say 20��ǰ�ı��䣬�����Ѿ���ȫ���ˡ�ֻ�ǿɺ޺��־�Ȼ������С�������㡣");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"zhenxiang"))
  {
	  command("say ������ȷʵ�ͺ�һ���ȹ��䣬����Ҳȷʵ��������������ô�������������´˶��֣���20��������Ҳ��һֱ�������֡�");
	  command("consider");
	  return 1;
  }  
 if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"zhenxiang_"))
  {
	  command("say ������˵�������ż���");
	  return 1;
  }  
  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"huyidao") )
  {
	  command("nod "+me->query("id"));
	  command("say ������ȷʵ�ͺ�һ���ȹ��䣬���Ǵӳ�ʶ���ཻ����������ͬ�����ߣ���ҹ�д��书�����Ǻ����˻��");
	  command("say ֻ�ǵ��������ϣ�����ɩ�Ƴ��ұ����������һ�����ԣ���һ����Ȼʹ���˷��ص�ʽ���������������ס��");
	  tell_object(me,YEL"\n����������о����ֻ���˵��ͬ�������ʵ������Ǻ����أ��Ѳ��ɺ�һ��������ɱ����\n\n"NOR);
    message_vision(HIC"$N¶���ɻ����ɫ��\n"NOR,me); 
	  me->start_busy(3);
	  remove_call_out("jieshuo1");
	  me->set_temp(QUESTDIR2+"zhenxiang_",1);
    call_out("jieshuo1",6, me);
  	return 1;
  } 

	command("heng");
	command("say �Һųƴ�������޵��֣���֪��˵����ʲô���䣿");
	return 1;
}
void jieshuo1(object me)
{
  if(!me) return;
  if(environment(me)!=environment(this_object()))   {
  	command("chat "+me->name()+"�����أ������ڽ������ء�");
  	return;
  }  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"huyidao"))
  {
    command("consider");
	  command("say ����һ���ҵ�ʱ�õĺ��ҵ����������õ�����ҽ���������ʱ���У��´�һʽ��һ�����ֲ������������ˡ�");
	  message_vision(YEL"\n$N������ʵ�����������Ʋ��Ǻ����أ���ô���̱������أ���$n���Ե����������ж�����˵�ţ�̾�˿�����\n"NOR,me,this_object());
	  command("say ���Ҵ�ɩ��ȻҲ��ɱ��֮������ң�����֮��Ҳ�����п�����20������һֱ����׷�����ֻ࣬��û���κ�������");
	  remove_call_out("jieshuo2");
    call_out("jieshuo2",6, me);
    return;
  }
}
void jieshuo2(object me)
{
  if(!me) return;
  if(environment(me)!=environment(this_object()))   {
  	command("chat "+me->name()+"�����أ������ڽ������ء�");
  	return;
  }
  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"huyidao"))
  {
    command("sigh");
    tell_object(me,HIW"\n�������˵һ���Ĭ�����ɱ�������ĺ������ж���ֻ���������б��飡������һ�����ֻ���ֻ���������ˣ�\n"NOR);
    me->delete_temp(QUESTDIR2+"huyidao");
    me->delete_temp(QUESTDIR2+"zhenxiang_",1);
    me->set_temp(QUESTDIR2+"zhenxiang",1);
    return;
  }
}
int ask_miaojiajianfa() 
{
	object me = this_player();
	object ob = this_object();
	int i,lv;

  if(!me->query(QUESTDIR3+"over"))
  {
	  command("shake "+me->query("id"));
	  command("sigh");
	  command("say ���ִ���δ�ˣ�����Ҳû��ʲô��˼�д��书�ˡ�");
	  return 1;
  } 

  if(me->query(QUESTDIR4+"miaojiajianfa")&& me->query("potential")<= 5)
  {
	  command("? "+me->query("id"));
    return 1;
  }

  if(me->query(QUESTDIR4+"miaojiajianfa"))
  {
  	if(me->query("potential")>4)
  	{
      message_vision("$N��$n����й���ҽ����İ��\n", me, this_object());
      me->receive_damage("jing", 30);
      tell_object(me,"���������˷��ָ�㣬����ҽ����İ����ƺ���Щ�ĵá�\n");
      me->add("potential",-(random(3)+2));
      if( me->query("potential")<0)
        me->set("potential",0);
      me->improve_skill("miaojia-jianfa", 150+random(me->query_int()*2));
      me->improve_skill("sword", random(me->query_int())/2);
       //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        lv = me->query("max_pot")-100;
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲����������ҽ����ľ������ڡ�\n"NOR);
            me->set_skill("miaojia-jianfa",lv);
            }
    }
    else 
    {
      message_vision("$N��$n����й���ҽ����İ��\n", me, this_object());
      me->receive_damage("jing", 30);
      tell_object(me,"���������˷��ָ�㣬���ǻ��ǲ�����⡣\n");
    }
    return 1;
  }   

  if(ob->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ���Ǹ�ѧ���𣬻����Ժ��д�ɡ�");
	  return 1;   
  }
  //��vip��ң�ֻ��ʧ������
  if(me->query(QUESTDIR4+"miaojiajianfa_fail")>=3 && me->query("registered")<3)
  {
	  command("shake "+me->query("id"));
	  command("say ����ʱ��������⽣�������Ժ��д�ɡ�");
	  return 1;
	}
	//�书ѧϰ֮����Ҫ���һ�죬������Ҫ���1M
	//ע�������Ǻ͵���ʹ��ͬһ����ǡ�
	if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<86400)
	{
	  command("shake "+me->query("id"));
	  command("say �������д赽����ɣ�����ɡ�");
	  return 1;
  }
	if(me->query(QUESTDIR4+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"combat_exp")<500000)
	{
	  command("look "+me->query("id"));
	  command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
	  return 1;
  }
	  command("nod "+me->query("id"));
    message_vision(HIY"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, ob);
    ob->set_temp("busy",1);
    remove_call_out("busy_pass");
		call_out("busy_pass",600, ob);   
    //�Ѷ���΢���ڵ�����������ϵ����
    power_condition(me,ob,350+random(150));
    for ( i = 0; i < 6+random(6);i++)
    {
         if (!present(me,environment(ob)) || me->query("qi") <= me->query("max_qi")/20 ||me->query("eff_qi") <= me->query("max_qi")/20 || me->query("jing") <= 50 || me->query("jingli") <= 50) 
         {
            if(random(2))command("sneer");
            else if(random(2)) command("say ��λ"+RANK_D->query_respect(me) +"�书δ�ܷ�豹��棬ֻ������������ҽ����ľ�����");
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
    //���ʱ��;���
    me->set(QUESTDIR4+"time",time());
    me->set(QUESTDIR4+"combat_exp",me->query("combat_exp"));
    ob->delete_temp("quest/ѩɽ�ɺ�/�书/lengquan");
    start_condition(ob);
    command("haha "+me->query("id"));
    message_vision(HIC"\n\n������������һ�������ѹ���$n΢Ц�Ŷ�$N˵�������ղ���ʹ�õ������ɿ�����ˣ���\n"NOR,me,ob); 
    remove_call_out("thinking");
		call_out("thinking",0, me, ob);
    tell_object(me,YEL"��ƴ���ػ���˲�佻�ֵ�һĻ�������Ÿղŵ��������㿪ʼ����˼����.........\n"NOR);
    me->start_busy(2);
	  return 1;
}

int thinking(object me, object ob)
{
	int i,p;
	if(!me) return 0;
  if(environment(me)!=environment(ob)) 
  {
  	start_condition(ob);
    if(random(2)) message_vision(HIC"\n$N����������������$n��Ȼ�������ѣ�û�ϵô���һ����\n"NOR,ob,me); 
    else message_vision(HIC"\n$N�ɻ��ʵ�����~~~���أ�$n�����أ�\n"NOR,ob,me); 
  	return 1;
  }
  if(!living(me) ) 
  {
  	ob->revive();
  	ob->reincarnate();
  }
  if(me->query_temp(QUESTDIR4+"thinking")<(3+random(3)))
	{
		me->add_temp(QUESTDIR4+"thinking",1);
    if(random(2)) tell_object(me,HIG"\n��Ŭ���ػ���ղŵ�ÿһ��ÿһʽ������������Ӱ���໥����ÿһ��ÿһʽ�㶼Ŭ��ȥ�����...\n"NOR);
    else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô����Ŭ���ػ���ղŵ�ÿһ��ÿһʽ�����ܳ�ָо������������ͼ���...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��һ����ü��չ�����ӡ�\n"NOR, ({}));
	  remove_call_out("thinking");
		call_out("thinking",3+random(3), me, ob);
	}
	else
	{
    me->delete_temp(QUESTDIR4+"thinking");

	 //�ѶȽ��ͣ��Ͼ���������ҽ�������һ��
   //������ͨ����Ʒ,��߼���.
   if(me->query_temp("sj_credit/quest/public/mjjf"))
        p=random(58);
   else
	//û��ģ�����ҵ����
        p=random(40);
     me->delete_temp("sj_credit/quest/public/mjjf");

    if(!QUEST_D->questing(me, 1, 0, 1)) p = 0;

         if(p > 37&& me->query("kar")<31)
    {
       tell_object(me,HIG"\n���������У�ͻȻ��������һ�С�\n"NOR);
       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
       tell_object(me,HIR"���������˷��ָ�㣬����ҽ����İ����ƺ���Щ�ĵá�\n"NOR);
	   if(me->query(QUESTDIR4+"hujiadaofa"))
		    tell_object(me,HIR"�㷢����ҽ�������ܹ�����ҵ����໥�ںϣ��������ɼӱ���\n"NOR);
       tell_object(me,HIR"ֻ���㷢������ҽ�������Ҫ��Ȫ�񹦲��ܷ���ȫЧ��\n"NOR);
       me->set(QUESTDIR4+"miaojiajianfa",1);
       i=180+random(40);
   	   me->add("mana",i);
  	   tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ���ҽ���ƪ�������"+i+"��������\n\n"NOR);	
     log_file("quest/FEIHU", sprintf(HIR"%s(%s) ʧ��%d�κ�ҿ���ҽ���,���%d��������random��40��ȡֵ%d��"NOR, me->name(1),me->query("id"),me->query(QUESTDIR4+"miaojiajianfa_fail"),i,p) );
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
       command("poor "+me->query("id"));
       me->add(QUESTDIR4+"miaojiajianfa_fail",1);
	   log_file("quest/FEIHU", sprintf(HIR"%s(%s) ��ҽ���ʧ�ܴ�����%d��,random��30��ȡֵ%d��\n"NOR, me->name(1),me->query("id"),me->query(QUESTDIR4+"miaojiajianfa_fail"),p) );
       if(me->query(QUESTDIR4+"miaojiajianfa_fail")>=3 && me->query("registered")<3)
       {
      	tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"���һ�γ��Խҿ�ѩɽ�ɺ���ҽ�����ȴû�гɹ���\n\n"NOR);	
   		log_file("quest/FEIHU", sprintf("%s(%s) ���һ�γ��Խҿ�ѩɽ�ɺ���ҽ�����ȴû�гɹ���ʱ�� %s��\n", me->name(1),me->query("id"), ctime(time()) ) );
       }
    }
  }
  return 1;
}
int ask_hujiadaofa() 
{
	object me = this_player();
	int i;
  if(this_object()->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ���Ǹ�ѧ���𣬻����Ժ��д�ɡ�");
	  return 1;   
  }
  if(me->query(QUESTDIR4+"hujiadaofa") && me->query(QUESTDIR4+"miaojiajianfa") )
  {
  	  //��vip��ң�ֻ��ʧ������
     if(me->query(QUESTDIR4+"ronghe_fail")>=3 && me->query("registered")<3)
     {
	      command("shake "+me->query("id"));
	      command("say �������������򰢡�");
	      return 1;
	    }
	   //�书ѧϰ֮����Ҫ���һ�죬������Ҫ���1M
	   //ע�������Ǻ͵���ʹ��ͬһ����ǡ�
	   if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<86400)
	   {
	     command("shake "+me->query("id"));
	     command("say �������д赽����ɣ�����ɡ�");
	     return 1;
     }
     if(me->query(QUESTDIR4+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"combat_exp")<500000)
	   {
	     command("look "+me->query("id"));
	     command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
	     return 1;
     }
  	 command("nod "+me->query("id"));
  	 if(me->query(QUESTDIR4+"ronghe"))
  	 {
      	command("say ���Ѿ������ںϣ���ϧȱ���ڹ�֧�֡���˵����Ȫ�񹦿����ڴ��������");
	      return 1;
      }
      me->set(QUESTDIR4+"time",time());
      me->set(QUESTDIR4+"combat_exp",me->query("combat_exp"));
 	    command("say ���ҵ�����ȷ��������ҽ����ںϣ�������Ҫ��Ȫ��֧�֣������ҿ����Ƚ̸����ںϵĿھ���");
 	    
 	    //�Ѷ�Ҳ�ܴ���ʵ��Ҳ�������书�Ĺؼ�
		//���������ż�����ϣ��ÿ����Ҷ��ܹ�ѧ��
		//���踻Դrandom֮��ȡ28�Ļ���int���Ӧ�ô���22
		//int ����25 bili 20�Ļ���con��dex֮��35 400�ȼ�exp ��ô����75
      if((random(me->query("kar"))+random(me->query("int")))>50 
		  && (random(me->query_con())+random(me->query_dex()))>60 
		  && random(me->query("combat_exp"))>2000000
            &&me->query("kar")<31
            &&QUEST_D->questing(me, 1, 0, 1))
      {
           tell_object(me,HIR"���������˷��ָ�㣬����ҽ����ͺ��ҵ����İ����ƺ��������ס�\n"NOR);
           message_vision(HIC"\n$N�������ҽ��Ȼ�һ�У�������������Ц������˵������ԭ����ˡ���\n"NOR,me); 
           me->set(QUESTDIR4+"ronghe",1);
           i=180+random(40);
   	       me->add("mana",i);
  	       tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"�⿪ѩɽ�ɺ������ںϵİ��أ������"+i+"��������\n\n"NOR);	
		   log_file("quest/FEIHU", sprintf(HIR"%s(%s) ʧ��%d�κ󣬽ҿ������ںϣ����%d��������kar%d/int%d/����con%d/dex%d��\n"NOR, me->name(1),me->query("id"),me->query(QUESTDIR4+"ronghe_fail"),i ,me->query("kar"),me->query("int"),me->query_con(),me->query_dex()) );
       }
       else
       {
           tell_object(me,HIG"\n���������˷��ָ�㣬�Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
           message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
           command("poor "+me->query("id"));
           me->add(QUESTDIR4+"ronghe_fail",1);
           if(me->query(QUESTDIR4+"ronghe_fail")>=3 && me->query("registered")<3)
           {
          	tell_object(me,HBYEL"\n����"+NATURE_D->game_time()+"���һ�γ��Խҿ�ѩɽ�ɺ������ںϵİ��أ�ȴû�гɹ���\n\n"NOR);	
   		      log_file("quest/FEIHU", sprintf("%s(%s) ���һ�γ��Խҿ�ѩɽ�ɺ������ںϵİ��أ�ȴû�гɹ���\n", me->name(1),me->query("id")) );
           }
        }
	  return 1;
  } 
  command("nod "+me->query("id"));
  command("say ����Ĺض�������һ����ָ������·������ȷʵ�����ޱȣ�");
	return 1;
}
int ask_huyidao() 
{
	object me = this_player();
  if(me->query(QUESTDIR3+"start"))
  {
  	command("cry");
  	command("say ��һ�����ҵĺ��ֵܰ���");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"huyidao"))
  {
  	command("say ��һ�����ҵĺ��ֵܰ���");
  	return 1;
  } 
  if(me->query(QUESTDIR2+"start")&& me->query_temp(QUESTDIR2+"kill"))
  {
  	tell_object(me,YEL"���˷�ͻȻ�����������˺ܶ࣬��֪��Ĭ�˶�ã��Ż���̾�˿�����\n"NOR);
    command("nod "+me->query("id"));
    command("say �ض�������һ�������ҵ��������Ѱ�����֪����λ"+RANK_D->query_respect(me) +"Ϊʲô��������");
    me->set_temp(QUESTDIR2+"huyidao",1);
    me->delete_temp(QUESTDIR2+"kill_ren");
    me->delete_temp(QUESTDIR2+"kill_");
  	return 1;
  }   
  command("nod "+me->query("id"));
  command("say �ض�������һ�������ҵ��������ѣ�������ʲô���飡");
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
  if(!me->query(QUESTDIR3+"over"))
  {
	  command("shake "+me->query("id"));
	  command("sigh");
	  command("say ��������û��ʲô��˼�д��书�ˡ�");
	  return 1;
  } 
  if(ob->query_temp("busy"))
  {
	  command("shake "+me->query("id"));
	  command("say ��������û��ʲô��˼�д��书�ˡ�");
	  return 1;
  }
    //��ͨ�������,
   if(me->query(QUESTDIR4+"fight_miao")>=3 && me->query("registered")<3)
  {
	  command("shrug "+me->query("id"));
	  command("say ��ɫ�����ˣ��⽣�������Ժ��д�ɡ�");
	  return 1;
	}

	//��������ʱ����1��Сʱ��
    if(me->query(QUESTDIR4+"time") && time()-me->query(QUESTDIR4+"time")<(3600*3))
	{
	  command("shake "+me->query("id"));
	  command("say �������д赽����ɣ��Ժ�ɡ�");
	  return 1;
  }
	if((me->query(QUESTDIR4+"fight_miao")>=3 && me->query(QUESTDIR4+"fight_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"fight_exp")<500000)
		||(me->query(QUESTDIR4+"fight_miao")<3 && me->query(QUESTDIR4+"fight_exp") && me->query("combat_exp")-me->query(QUESTDIR4+"fight_exp")<100000))
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
	  command("nod "+me->query("id"));
    message_vision(HIY"\n$nͻȻ��������ڹ���Ȫ�񹦣�ֻ�о������޷�����\n"NOR, me, this_object());
    
    //�������书��400�ȼ����ϣ���Ȼ��˻��ǱȽ�Σ�ա�
    power_condition(me,ob,300+random(200));
    if (!(room = find_object("/d/lanzhou/lianwuchang")))
        room = load_object("/d/lanzhou/lianwuchang"); 
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
	me->add(QUESTDIR4+"fight_miao",1);
    ob->set_temp("busy",1);
    ob->set_temp("biwu",1);
	  ob->set_temp("quest/try_fight_id",me->query("id"));

    message_vision(HIY"$N��$nһ���ֵ�����"+RANK_D->query_respect(me) +"������������$N��$n����ææ���뿪�صء�\n"NOR, ob,me);     
    ob->move(room);
    me->move(room);
    message_vision(YEL"$N����ææ���������䳡��\n"NOR, ob);    
    message_vision(YEL"$N����ææ���������䳡��\n"NOR, me);    
	  command("sneer");
    remove_call_out("busy_pass");
		call_out("busy_pass",600, ob);
    log_file("quest/FEIHU", sprintf("%s(%s) �ٴ������˷���������飺%d��\n",me->name(1),me->query("id"),me->query("combat_exp")) );
    me->start_busy(1);
    ob->start_busy(1);
	  return 1;
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
  
  if (!present("changjian",ob))
  {
	  message_vision(HIR"\n$N�������һԾ����֪�������ﾹȻ���ó�һ�Ѹֽ���\n"NOR,ob); 
  	carry_object(BINGQI_D("sword"))->wield();
  }
	else command("wield changjian");
  i=ob->query_temp("pfm");

  //zongjue ����
  if(ob->query_skill_mapped("sword") != "miaojia-jianfa")
  {
	  ob->map_skill("sword","miaojia-jianfa");
	  ob->map_skill("parry","miaojia-jianfa");
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
            message_vision(HIW"\n$N"HIW"����Գ�ۣ����еĳ����������£��仯Ī�⣬������$n"HIW"����Ҫ����\n" NOR, this_object(),me);
            if(random(3) && !me->query_busy())
            {
            	message_vision(HIC"$n������ʵ���Ǳ��Ī�⣬���ɵ��������⣬��ʽ��ʱ����������\n" NOR, this_object(),me);
              me->add_busy(1+random(4));
            }
            break;
     	case 1:
     		  message_vision(HIR"\n$N���еĳ����ó����콣Ӱ������������Ļ���$n��\n" NOR, this_object(),me);
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
int ask_liangyedaofa() 
{
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
 	command("doubt"); 
	command("say ˭������ʶ��");
	command("consider");
	return 1;
}
int ask_zhiliao() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("say ��Ҫ���ƿ���Ѱ�ҳ̹��ȷʵ���֡���Ҳ��л���ˡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start"))
  {
	  command("sigh "+me->query("id"));
	  command("say ���˵�����������ⶾ������ֻ�г������ˡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR2+"over"))
  {
	  tell_object(me,HIW"��Ҳ������������˷��Ȼ���ڲ��Ǳ��˵�ʱ���ⶾ��Խ������������˵�����˷������ǰ��ϸ�۲��ж�֢״��\n\n"NOR);
	  tell_object(me,CYN"��˵�����������������Ⱦ�Ķ�ҩ�����Ƕϳ��ݵķ�ĩ��ֻ���ǴӶ���ҩ����������ġ���˵���ڼ䣬���˷��Ѿ�ʹ�����̡�\n"NOR);
	  tell_object(me,CYN"���˷����������������˵����Ҫ���ⶾֻ��ҩ���ȵ����ˡ�����˵�ͷ����ǰ֮�����ǸϿ�Ѱ�ҳ����أ��ⶾ���ƺ����͡�\n\n"NOR);
	  tell_object(me,CYN"���˷����ԣ�ͣ����һ�£�������ҩ���Ⱦ����置֮�ڣ��ǾͰ���"+RANK_D->query_respect(me) +"��һ���ˡ�ֻ����˵ҩ���ȵ���......��\n"NOR);
	  command("sigh");
	  tell_object(me,HIC"\n�㵱��˵���������Ǻô�Ҳ�ý����뵽����Ҫʲô�����ʲô�������ȥһ���置ҩ���ȡ���\n"NOR);
	  command("addoil "+me->query("id"));
	  me->set(QUESTDIR3+"start",1);
	  return 1;
  } 
  command("say ҩ����Ψһ�״����ӣ�ǰ��ʱ��ҩ�����ţ�����ҩ��һ��ֻ��������س̹��������ˡ�");
	return 1;
}
int ask_miaoruolan() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"marry"))
  {
	  command("say СŮ�������⹤��ֻ�ºͺ���Ǻ�����һ��ɡ�");
	  return 1;
  }
	command("? "+me->query("id"));
	command("say ����СŮ����֪�������к��£�");
	return 1;
}
int ask_hufei() 
{
	object me = this_player();
	
	if(me->query(QUESTDIR3+"marry"))
  {
	  command("say ����ֻ�º�СŮ��������һ��ɡ������������һ������");
	  return 1;
  }

  if(me->query(QUESTDIR3+"start"))
  {
	  command("say �����������һ���������־�Ȫ֮��Ҳ���Ŀ�ˡ�");
	  return 1;
  }
	command("say ����֮�ӵ������������쳣���ϧ����һ�����ң����ҵ������ˡ�");
	command("sigh");
	command("say �ú��δ���չ˺���Ψһ֮�Ӱ���");
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
  if(me->query(QUESTDIR3+"start"))
  {
	  command("heng");
	  command("say ȷʵû���뵽������˸��ӡ�����������һ�ž�����Ҳ���������ְֻ���");
	  return 1;
  } 
	command("say �������������ţ��ܾò�֪�����ˡ����������Ŵ�����ǰ�ˡ�");
	return 1;
}
int ask_hunjia() 
{
	object obj,me = this_player();
  if(me->query(QUESTDIR3+"marry"))
  {
	  command("haha");
	  command("say ������Ҷ�Թ�յ�Բ������");
	  return 1;
  }
  if(me->query(QUESTDIR3+"over"))
  {
  	tell_object(me,CYN"��˵��������������֪������������ѩɽ�ɺ������Ͷ������������飿\n"NOR);
	  command("say ��֪�����Ǽ٣�������ã�������������Ҷ�Թ�յ�Բ������");
	  command("haha");
	  command("say ��λ"+RANK_D->query_respect(me) +"Ϊ�������ҳ��������������м���������Ϊ����������һ�����⣬�������£�");
	  me->set(QUESTDIR3+"marry",1);
	  obj=new("/clone/medicine/renshen-guo");
	  command("give "+obj->query("id")+" to "+me->query("id"));

	  if(!present(obj,me)) obj->move(me);
	  return 1;
  } 
	command("say ���º���˵�����ã�СŮ�����Լ����š�");
	return 1;
}
int ask_chuangwang() 
{
        object me,obj;
        me = this_player();
  if(me->query(QUESTDIR3+"over")&& !present("baozang tu",me))
  {
	if(!me->query(QUESTDIR4+"win_miao") && (me->query(QUESTDIR4+"fight_miao")<3 || random(4)))
    {
	      command("look "+me->query("id"));
	      command("say �����Ҷ�Ӯ���ˣ���ζ���Ѱ�ұ��ء�����Ҳ����Ϊ����á�");
	      command("pat "+me->query("id"));
	      command("say �㻹��ץ��ʱ������ȥ�ɡ�");
	      return 1;
    }
	if(!me->query(QUESTDIR4+"win_hu") && (me->query(QUESTDIR4+"fight_hu")<3 || random(4)))
    {
	      command("look "+me->query("id"));
	      command("say ������쳶�Ӯ���ˣ���ζ���Ѱ�ұ��ء�����Ҳ����Ϊ����á�");
	      command("pat "+me->query("id"));
	      command("say �㻹��ץ��ʱ������ȥ�ɡ�");
	      return 1;
    }
	if(!random(10))
	{
	    if(random(2))
		{            
			command("consider");
			command("say ����ͼ�������ء�");
			if(random(2)) command("pat "+me->query("id"));
			else command("papaya");
			command("addoil");
			return 1;
		}
		else if(random(2))
		{
			command("consider");
			command("say �ղŻ������ﰡ���������ҿ���");
			command("papaya");
			return 1;
		}
		else if(random(2))
		{
			command("consider");
			command("say ����ͼ.....��ʲô���ţ������������ˡ�");
			command("pat "+me->query("id"));
			command("say �����ɣ��㻹��ץ��ʱ������ȥ�ɣ���һ�������ʰɣ���������ҿ���");
			command("addoil "+me->query("id"));
			return 1;
		}
		else
		{
			command("?");
			command("makeup");
			command("say ��ѽ����õ��ˣ���Ҫʲô���ţ�");
			command("say �����ɣ��㻹��ץ��ʱ������ȥ�ɣ���һ�������ʰɣ���������ҿ���");
			command("addoil "+me->query("id"));
			return 1;
		}
	}
	obj=unew("/d/lanzhou/obj/map");

	if(!clonep(obj)){
	      command("pat");
	      command("say ����ͼ����������������˺�Ϳ�ˡ�");
	      command("pat "+me->query("id"));
	      command("say �����ɣ��㻹��ץ��ʱ������ȥ�ɣ���һ�������ʰɣ���������ҿ���");
	      command("addoil "+me->query("id"));
		  return 1;
	}
    
	if(clonep(obj) && obj->violate_unique()){
	  	  if(objectp(environment(obj))) tell_object(environment(obj),HIC""+obj->query("name")+"��һ�������ˡ�\n"NOR, ({}));
		  destruct(obj);
	      command("pat");
	      command("say ����ͼ����������������˺�Ϳ�ˡ�");
	      command("pat "+me->query("id"));
	      command("say �����ɣ��㻹��ץ��ʱ������ȥ�ɣ���һ�������ʰɣ���������ҿ���");
	      command("addoil "+me->query("id"));
		  return 1;
	} 
  	tell_object(me,HIR"���˷�͵͵�����㣺"HIG"���괳�����˱���֮�������Ļ��׹��ݡ��󳼴󽫾���Ͷ������Щ���޲����ʺ������������µĽ���\n"NOR);
  	tell_object(me,HIG"����֮�䣬�Ʊ�ɽ���������������ˡ����������˳��������������Ž��죬�������׳������鱦������Ѻ���Ʊ�ȥ����һ����\n"NOR);
  	tell_object(me,HIG"���׵����ڣ��Ա㽫����������֮ʱ��Ϊ���á������ر������ڻ��һͼ������ͼѰ���Ĺؼ���ȴ���ھ���֮�С��Ź�ɽ����\n"NOR);
  	tell_object(me,HIG"����������������֮ͼ������������˷�����ꡣ����������걻ɱ��һͼһ��������λ������У��������ֱ��������Ķ�\n"NOR);
  	tell_object(me,HIG"�Ӷ�ȥ��������շת���ᣬ���ھ����������������ƹܣ��ر�֮ͼȴ������ҼҴ���ֻ���������Ҳ�֪����������һ�������ܣ�\n"NOR);
  	tell_object(me,HIG"����ûȥ���򱦲ء��������ɺ��������ഫ�������պ���û������ͼ����Ҳ�޷��ҵ����ء��Ǻ���罫���¸�֪�ҵģ�����ȥ\n"NOR);
  	tell_object(me,HIG"������أ��ȼ��������ˡ���ʵ������ܵ��������Ѿ�����������������㣬����ȥѰ��һ��������ء�����ǲر�ͼ����\n"NOR);
  	tell_object(me,HIG"�ڲر��������㻹��ȥ�Լ��ھ�ɡ�\n"NOR);
    tell_object(me,HIR"\n���˷�͵͵�����㣺"HIG"̽�յ�ʱ��һ��Ҫע�ⰲȫ������ҩ������������ӡ����۵ȳ������߲�Ҫ��©��\n"NOR);
    command("smile");
    tell_object(me,HIR"\n���˷ｻ����һ�ű���ͼ��\n"NOR);
    command("addoil");
    obj->set("owner",me->query("id"));
    obj->move(me);
    log_file("quest/FEIHU", sprintf("%s(%s) ��ñ���ͼ�����飺%d��\n",me->name(1),me->query("id"),me->query("combat_exp")) );
    me->set(QUESTDIR+"����/start",1);
	return 1;
  } 
	command("say �������ȷʵ����Ұ����ϧʱ����ʱ��Ҳ��˵����һ�󱦲أ���֪�������Ǽ١�");
	return 1;
}
int start_condition(object ob)
{
	 if(!ob) return 0;
   ob->set_skill("force", 300);
	 ob->set_skill("dodge", 300);
	 ob->set_skill("parry", 300);
	 ob->set_skill("sword", 300);
	 ob->set_skill("cuff",300); 
	 ob->set_skill("taxue-wuhen",300);
	 ob->set_skill("zhentian-quan",300);
	 ob->set_skill("lengquan-shengong",300);
	 ob->set_skill("miaojia-jianfa",300);
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
    if (!present("changjian",ob))
	    carry_object(BINGQI_D("sword"))->wield();
	  else command("wield changjian");
    ob->set_temp("quest/ѩɽ�ɺ�/�书/lengquan",1);
	  i=me->query("max_pot");
	  if(p<150) p=150;
	  if(i<p) i=p;
	  i=i-100;	  
	  ob->set_skill("force", i+random(50));
	  ob->set_skill("dodge", i+random(50));
	  ob->set_skill("parry", i+random(50));
	  ob->set_skill("sword", i+random(50));
	  ob->set_skill("cuff",i+random(50)); 
	  ob->set_skill("taxue-wuhen",i+random(50));
	  ob->set_skill("zhentian-quan",i+random(50));
	  ob->set_skill("lengquan-shengong",i+random(50));
	  ob->set_skill("miaojia-jianfa",i+random(50));
	  i=me->query("combat_exp");
	  ob->set("combat_exp",i);
	  i=me->query("neili");	  
	  if(i<15000) i=15000;
	  ob->set("neili", i);	  
	  i=me->query("max_neili");	  
	  if(i<8000) i=8000;
	  ob->set("max_neili", i);	  
	  ob->set("jiali",200);
  	i=me->query("max_qi");	  
          ob->set("max_qi", i*(6+random(3))/4);   
 	  ob->set("eff_qi", ob->query("max_qi"));	
 	  ob->set("qi", ob->query("max_qi"));	
    return 1;
}
int busy_pass(object ob)
{
	if(!ob) return 0;
	if(ob->query_temp("busy")) ob->delete_temp("busy");
	if(ob->query("busy")) ob->delete("busy");
  if(random(2)) message_vision(HIC"\n$N���˸�������\n"NOR,ob); 
  else if (random(2)) message_vision(HIC"\n$N������üͷ��\n"NOR,ob); 
  else message_vision(HIC"\n$N������������\n"NOR,ob); 
  return 1;
}

int accept_object(object who, object ob,object me)
{
	
	 if(ob->query("id")=="yu pei"&&ob->query("quest")&&ob->query("owner")==who->query("id"))
   {
     if(who->query(QUESTDIR4+"lengquanshengong") && !who->query(QUESTDIR4+"lengquanshengong_teach"))
     {
     	command("ah "+(string)who->query("id"));
     	command("whisper "+(string)who->query("id")+" �����ҵ����Ķ����������������ģ�");
        tell_object(who,CYN"\n�������˷�Ķ�������˵�����Ҹղ�ȥ���������أ�������񵽵ġ�\n"NOR);
     	who->set_temp(QUESTDIR4+"lengquanshengong_teach",1);
     	command("hehe");
     	command("say 30��ǰ���ﰲ�����ҵ������ͬȥ���⣬��ʱ���ǲ�֪Ϊ�˺��£������������˸߲��ң�����ϲϲ��ȥ�����ǴӴ˲���������");
     	command("say ���������Ѻ������ԣ�˵��������λΪ��һ������������������ʦ�ܲŴ�����һ��Ѱ����֪����һ��ȫ����ᣬȫ���ˣ�");
     	who->start_busy(1);
     }
     else  command("thank "+(string)who->query("id"));
     call_out("destroying", 1, ob);        
     return 1;
   }
    else
     command("? "+(string)who->query("id"));
   return 0;
}
void destroying(object obj)
{
        if(!userp(obj)) destruct(obj);
        return;
}
int ask_lengquanshengong() 
{      int lv;
	object me = this_player();
       lv = me->query("max_pot")-100;
  if(me->query(QUESTDIR4+"lengquanshengong_teach"))
  {
  	if(me->query("potential")>4)
  	{
      message_vision("$N��$n����й���Ȫ�񹦵İ��\n", me, this_object());
      me->receive_damage("jing", 30);
      if(skill_check(me))
      {
          tell_object(me,HIC"���������˷��ָ�㣬�������������ٶȼ�����\n"NOR);
          tell_object(me,HIC"Ҳ������Ϊ�����ڹ��ĸ��ţ��޷�ȫ��������Ȫ�񹦡�\n"NOR);
        me->add("potential",-(random(3)+3));
        if( me->query("potential")<0)
            me->set("potential",0);
        me->improve_skill("lengquan-shengong", 10+random(me->query_int()/2));
      }
      else
      {
        tell_object(me,"���������˷��ָ�㣬����Ȫ�񹦵İ����ƺ���Щ�ĵá�\n");
        me->add("potential",-(random(3)+2));
        if( me->query("potential")<0)
            me->set("potential",0);
        me->improve_skill("lengquan-shengong", 150+random(me->query_int()*2));
        me->improve_skill("force", random(me->query_int())/2);
      }
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲����������Ȫ�񹦵ľ������ڡ�\n"NOR);
            me->set_skill("lengquan-shengong",lv);
            }
    }
    else 
    {
      message_vision("$N��$n����й���Ȫ�񹦵İ��\n", me, this_object());
      tell_object(me,"���������˷��ָ�㣬���ǻ��ǲ�����⡣\n");
    }
    return 1;
  }
  if(me->query_temp(QUESTDIR4+"lengquanshengong_teach"))
  {
	  command("nod "+me->query("id"));
	  command("say ��λ"+RANK_D->query_respect(me) +"�����ж�δ����Ҳ�գ�������Ҳ������ɡ�");

    message_vision(HIR"$N��$n����й���Ȫ�񹦵İ��\n"NOR, me, this_object());
    me->receive_damage("jing", 30);
    if(skill_check(me))
    {
        tell_object(me,HIC"���������˷��ָ�㣬�����ܸо����������������ѡ�\n"NOR);
      tell_object(me,HIC"Ҳ������Ϊ�����ڹ��ĸ��ţ��޷�ȫ��������Ȫ�񹦡�\n"NOR);
      me->improve_skill("lengquan-shengong", random(me->query_int()*2/3));
      me->delete_temp(QUESTDIR4+"lengquanshengong_teach");
      me->set(QUESTDIR4+"lengquanshengong_teach",1);
    }
    else
    {
    	tell_object(me,"���������˷��ָ�㣬����Ȫ�񹦵İ����ƺ���Щ�ĵá�\n");
      me->improve_skill("lengquan-shengong", 10+random(me->query_int()));
      me->improve_skill("force", random(me->query_int())/2);
      me->delete_temp(QUESTDIR4+"lengquanshengong_teach");
      me->set(QUESTDIR4+"lengquanshengong_teach",1);
    }
    return 1;
  }
  if(me->query(QUESTDIR4+"hujiadaofa")||me->query(QUESTDIR4+"hujiadaofa"))
  {
	  command("nod "+me->query("id"));
	  command("say ��Ȫ���Ǻ��ҵ�����ҽ��Ļ����ڹ���Ҳֻ����Ȫ�񹦲�������޶ȷ��ӵ�����������");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"over"))
  {
	  command("nod "+me->query("id"));
	  command("say ��Ȫ���Ǵ���ʱ���Ĵ��������ƹ��������书Ҳ��������书�Ļ�����");
	  return 1;
  } 
	command("hehe");
	command("say �Һųƴ�������޵��֣����ľ��������书��");
	return 1;
}
int skill_check(object me)
{
	int i,p;
	mapping skill_status;
  string *sname;
  p=0;
  if(mapp(skill_status=me->query_skills()))
	{
		skill_status=me->query_skills();
    sname = keys(skill_status);
	  for(i=0; i < sizeof(skill_status); i++) 
   	  if(SKILL_D(sname[i])->valid_enable("force")&&sname[i]!="lengquan-shengong") p=1;
  }
	return p;		
}
