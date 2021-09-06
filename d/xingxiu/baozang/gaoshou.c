// tangfeng@SJ 2004
//inherit NPC;

inherit FIGHTER;
inherit F_UNIQUE;
#include <ansi.h>


//string *str_menpai = ({ "wd","hs","ss","gm","gb","tz","dls","sld","xx","mj","thd","kl"});	
//#include "/d/city/npc/skills_pfm.h";
void create()
{
	mapping name;
  name = RNAME_D->get_random_name(random(3));
	set_name(name["name"], name["id"]);
        set_name(query("name"), ({ query("id"),"gao shou"}));

	set("long", "һλĳ���ɵ��ӡ�\n");
	set("title", HIY"��ͽ"NOR);
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 30000);
	set("max_jing", 6000);
	set("eff_jingli",6000);
	set("neili", 40000);
	set("max_neili", 30000);
	set("jiali", 200);
	set("combat_exp", 5000000+random(8000000));
	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
}
void init()
{
    object me,ob;  
    string good_skills;
    int i;     
    ::init();
    ob = this_object();
    if(ob->query("setok")) return;
	  if(!ob->query("party"))	ob->set("party",str_menpai[random(sizeof(str_menpai))]);  	 
    ob->copy_menpai(({ob->query("party")}),1,random(2),50+random(50));	//����npc�������书��			
	  ob->copy_state();				//�������ɸ���npc ��һЩ״̬
		if (ob->query("f_skill2")) 
				good_skills=to_chinese(ob->query("f_skill"))+"��"+to_chinese(ob->query("f_skill2"));
		else	
				good_skills=to_chinese(ob->query("f_skill"));
   	ob->set("long",HIW+ob->query("family/family_name")+"���֣�����������"+good_skills+"��"NOR);
    message_vision(HIG"$N����ؿ���$n����ɫ������š�\n"NOR,ob,this_player());
    if(!ob->query("fight_id"))
    {
		  ob->set_skills_level(350+random(200));
    	return;
    }
    me = present(ob->query("fight_id"),environment(ob));
	  if(!me) 
	  {
		  ob->set_skills_level(350+random(200));
    	return;
    }
        ob->set("long",HIW"�ڷ�կ���֡�\n"NOR);
 		ob->set("setok",1);
	  i=me->query("max_pot");
	  if(i<350) i=350;
	  i=i-100;	
		ob->set_skills_level(i);
	  ob->set("max_neili",me->query("max_neili"));
  	ob->set("max_jingli",me->query("max_jingli"));
  	ob->set("max_qi",me->query("max_qi"));
  	ob->set("max_jing",me->query("max_jing"));
		ob->set("neili",query("max_neili")*3/2);
		ob->set("jingli",query("max_jingli")*3/2);
		ob->set("eff_jingli",query("max_jingli")*3/2);
		ob->set("qi",query("max_qi"));
		ob->set("eff_qi",query("max_qi"));
		ob->set("jing",query("max_jing")*3/2);
		ob->set("eff_jing",query("max_jing")*3/2);
    ob->set("jiali",100);
    ob->set_skill("wuxing-zhen",200);
    ob->set("combat_exp",me->query("combat_exp"));
 		ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
    remove_call_out("do_kill");
    remove_call_out("dest");
    call_out("dest",600,ob);
    remove_call_out("zhen");
    call_out("zhen",1,ob);
    call_out("do_kill",2,me);
}
void zhen(object ob) 
{
  if( !ob ) return;                   
   command("lineup with gao shou 1");
   command("lineup with gao shou 2");
   command("lineup with gao shou 3");
   command("lineup with gao shou 4");
     command("lineup form wuxing-zhen");   
   command("lineup with gao shou 1");
   command("lineup with gao shou 2");
   command("lineup with gao shou 3");
   command("lineup with gao shou 4");
   call_out("zhen",1,ob);
}
int do_kill(object me)
{
	object ob = this_object();
	if(!me) return 0;
  if(random(2)) message_vision(HIG"����һ����Ӱ���˳�����$N��ݺݵص�����"+me->name()+"�����"+RANK_D->query_rude(ob)+ "����Ȼ���㷢�֣�����������\n"NOR,ob);
  else message_vision(HIY"$N��Цһ��������֪��ߵغ񣬾�Ȼ���谭"+RANK_D->query_self_rude(ob) +"��ȥ·�������Ҫ�������\n"NOR,ob);
  command("follow "+me->query("id"));
  ob->set_leader(me);
	remove_call_out("checking");
	call_out("checking", 2, me, ob);
	::do_kill(me);
}

//��飬quest���̲���������
int checking(object me, object ob)
{
	int ret =  ::checking(me,ob);
	if(!ret) return 0;
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
  if(!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0  ){
		remove_call_out("checking");
		me->set("qi",100);																		
        me->delete("quest/ѩɽ�ɺ�/����/start");
        me->delete_temp("quest/ѩɽ�ɺ�/����/search_ok");
        me->delete_temp("quest/ѩɽ�ɺ�/����/guanzhu_ok");
        me->delete_temp("quest/ѩɽ�ɺ�/����/yanjiu_ok");
        me->set("quest/ѩɽ�ɺ�/����/time",time());
        me->set("quest/ѩɽ�ɺ�/����/combat_exp",me->query("combat_exp"));
  log_file("quest/FEIHU", sprintf("%s��¼��%s(%s)Ѱ�ұ���ʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
                me->set("jing",100);
                me->set("jingli",100);
          if(!random(3)) tell_room(environment(ob), HIB"\n"+ob->name()+"����һ����ת��������Ͳ����ˡ�\n"NOR);
        else tell_room(environment(ob), HIB"\n"+ob->name()+"���µ��������������"+RANK_D->query_rude(me)+ "�����Ǿ�����취Ѱ�ұ��ء�\n"NOR);
		destruct(ob);
		return 1;
	}
  if(!me || environment(ob)!= environment(me)||me->query("eff_qi")<me->query("max_qi")/10||me->query("qi")<me->query("max_qi")/15){
		remove_call_out("checking");
		remove_call_out("do_lost");
		call_out("do_lost",0);
		return 1;
	}
   if(!me->is_fighting(ob))  call_out("do_kill",1,me);
}
void do_lost()
{
	object me,ob;
	ob = this_object();
	me = find_player(ob->query("fight_id"));
	if(!me) return;
        me->delete("quest/ѩɽ�ɺ�/����/start");
        me->delete_temp("quest/ѩɽ�ɺ�/����/search_ok");
        me->delete_temp("quest/ѩɽ�ɺ�/����/guanzhu_ok");
        me->delete_temp("quest/ѩɽ�ɺ�/����/yanjiu_ok");
        me->set("quest/ѩɽ�ɺ�/����/time",time());
        me->set("quest/ѩɽ�ɺ�/����/combat_exp",me->query("combat_exp"));
  log_file("quest/FEIHU", sprintf("%s��¼��%s(%s)Ѱ�ұ���ʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
        if(!random(3)) tell_room(environment(ob), HIB"\n"+ob->name()+"����һ����ת��������Ͳ����ˡ�\n"NOR);
        else tell_room(environment(ob), HIB"\n"+ob->name()+"���µ��������������"+RANK_D->query_rude(me)+ "�����Ǿ�����취Ѱ�ұ��ء�\n"NOR);
	destruct(ob);
}

void dest(object ob)
{
  if(!ob) return;
  tell_room(environment(ob), HIR+"\n"+ob->name()+"����һ���������ҵ�Ѱ�ұ��ذɡ�\n"NOR);
	destruct(ob);
}
