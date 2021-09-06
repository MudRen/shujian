// gsz.c ����ֹ
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_gu();
void kill_player(object me);
void die();
void kill_ob(object me);
int ask_jindaoheijian();
#define QUESTDIR "quest/jindaoheijian/"

void create()
{
	set_name("����ֹ", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","��ĿӢ����͸�������߾�֮�ţ�ֻ����ɫ���ƣ����տ��¡�\n");
        set("title",HIW"����ȹ���"NOR);
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
        set("per", 20);
        set("unique", 1);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
        set("eff_jingli", 2000);
	set("jiali", 80);
	set("combat_exp", 1000000);
 
        set_skill("force", 150);      
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("guiyuan-tunafa", 150);
        set_skill("literate", 120); 
        set_skill("shuishangpiao", 150);
        set_skill("tiezhang-zhangfa", 150);
        set_skill("strike",150);
        set_skill("sword", 150);
	      set_skill("jindao-heijian", 150);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "liangyi-jian");
	      map_skill("sword", "jindao-heijian");
	      map_skill("blade", "jindao-heijian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "���鵤": "��ҩ�޶࣬����Ҳ�������ƣ����򲻵��ѡ�����",
            "�����": (: ask_gu :),
            "�𵶺ڽ�": (: ask_jindaoheijian :)
        ]) );

	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/cloth")->wear();
}

string ask_gu()
{
       object me,ob;
       me=this_object();
       ob=this_player();
       if(ob->query("combat_exp") < 200000)
         return RANK_D->query_respect(ob)+"����̫�������������ΪΣ�գ����ǲ�Ҫ�ڴ˾����ˡ�";      
         ob->set_temp("gsz_agree", 1);
         return RANK_D->query_respect(ob)+"��Ȼ�Ծ����������Ȥ��������㿴���ɡ�";
}

int ask_jindaoheijian() 
{
	object me = this_player();
	object ob = this_object();

   if(!me->query("quest/jindaoheijian/ask") && me->query("combat_exp")<= 2000000)
   {
     command("@@ "+me->query("id"));
     command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
     return 1;
   } 
   
if(me->query("quest/jindaoheijian/pass"))
  {
	  command("disapp "+me->query("id"));
	  command("say �㲻ѧ�Ѿ�ѧ�˽𵶺ڽ�����˫������");
	  return 1;
  } 
    
 //�书ѧϰ֮����Ҫ���һ�죬������Ҫ���500K

	if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<86400)
	{
	  command("shake "+me->query("id"));
	  command("say �������д赽����ɣ�����ɡ�");
	  return 1;
  }
   if( me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000 && !me->query("cw_exp"))
{
	  command("look "+me->query("id"));
	  command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
	  return 1;
  }
  
  if(me->query("quest/jindaoheijian/ask") > 0)
    {
    command("pat "+me->query("id"));
    message_vision(HIC"\n\n$n΢Ц�Ŷ�$N˵��������Ҫ����ϸ��!��,˫��ˣ�����еĽ𵶺ͺڽ�!\n"NOR,me,ob); 
    me->set(QUESTDIR+"time",time());
    me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
    remove_call_out("thinking");
		call_out("thinking",5, me, ob);
    tell_object(me,YEL"��ƴ���ػ��乫��ֹ�𵶺ڽ������ƣ��㿪ʼ����˼����.........\n"NOR);
    me->start_busy(2);
	  return 1;
	  }
	  else
	 {  
	  command("? "+me->query("id"));
         command("say ���������ʲô?");
    return 1;
  }
}

int thinking(object me, object ob)
{
	int p;
	if(!me) return 0;
	
  if(me->query_temp("jdhj_thinking")<(3+random(3)))
	{
		me->add_temp("jdhj_thinking",1);
    if(random(2)) tell_object(me,HIG"\n��Ŭ���ػ���ղŹ���ֹ�𵶺ͺڽ�������,ֻ�����ۻ�����...\n"NOR);
    else tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô����Ŭ���ػ���ղ��Ź���ֹ��ʽ�����ƺ��о��������еı仯����...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"�ƺ���˼����ʲô��һ����ü��չ�����ӡ�\n"NOR, ({}));
	  remove_call_out("thinking");
		call_out("thinking",3+random(3), me, ob);
	}
	else
	{
    me->delete_temp("jdhj_thinking");

        p=random(40);

         if(p > 30 && random(me->query("kar"))>25)
    {
       tell_object(me,HIG"\n���ʱ���½��ղŵľ�����ʽ���ˣ��������Ź���ֹ��ʽ���������е��ͽ���\n"NOR);
       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
       tell_object(me,HIR"�����˹���ֹ��ָ��,���������˽𵶺ڽ��ľ������ڡ�\n"NOR);
       me->set("quest/jindaoheijian/pass",1);
       me->set("quest/jindaoheijian/ask",0);
       me->set_skill("jindao-heijian",1);
       message_vision(HIC"\n��ġ��𵶺ڽ��������ˣ���\n"NOR,me); 
	log_file("quest/jindaoheijian", sprintf("%s(%s) ʧ��%d�γɹ��⿪�𵶺ڽ�����˫�С���Դ��%d�����飺%d��", me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
       command("poor "+me->query("id"));
       me->add(QUESTDIR+"fail",1);
	log_file("quest/jindaoheijian", sprintf("%s(%s) ��𵶺ڽ�����˫��ʧ�ܣ�%d�Ρ���Դ��%d�����飺%d��", me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}
