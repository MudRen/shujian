// tangfeng@SJ 2004
//inherit NPC;
// fy5_npc.c  �޸ĳ�fengyi5 quest��npc  by lsxk@hsbbs  2007/8/29

inherit FIGHTER;
inherit F_UNIQUE;
#include <ansi.h>


//string *str_menpai = ({ "wd","hs","ss","gm","gb","tz","dls","sld","xx","mj","thd","kl"});	
//#include "/d/city/npc/skills_pfm.h";
void create()
{
   set_name(HIB"�������"NOR, ({ "mengmian eren","eren","killer"}));
	set("long", "һλĳ���ɵ��ӡ�\n");
   set("title", BLU"�ڵ�����"NOR);
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
   set("shen", -4000000-random(1000000));

   set("str", 30);
   set("int", 30);
   set("con", 30);
   set("dex", 30);

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
    me = this_player();
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
     if(!me->query("quest/hsjf/fy5/meet_killers")) 
	  {
		  ob->set_skills_level(350+random(200));
    	return;
    }
        ob->set("long",HIY"����һλ�ڵ����֣��书�ѳ����뻯,���ж��֣�\n"NOR);
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
    ob->set("fy5_id",me->query("id"));
 		ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
    remove_call_out("do_kill");
    remove_call_out("dest");
    call_out("dest",600,ob);
    call_out("do_kill",2,me);
}
int do_kill(object me)
{
	object ob = this_object();
	if(!me) return 0;
    if(!me->query_temp("quest/huashan/fy5/killer_killed"))
        message_vision(HIY"$N��Цһ��������֪��ߵغ񣬾�Ȼ������"+RANK_D->query_self_rude(ob) +"�ң������Ҫ�������\n"NOR,ob);
    else
        message_vision(HIW"$N����$n��Хһ���������󱲣����һ��ҵȺ��£����㲻��!\n"NOR,ob,me);
  command("follow "+me->query("id"));
  ob->set_leader(me);
	remove_call_out("checking");
   if(!ob->query("fengyi5_boss"))
       call_out("checking", 2, me, ob);
    else me->set("quest/hsjf/fy5/yanlian","again");
    me->start_busy(2+random(2));
    ob->start_busy(3);
	::do_kill(me);
    return 1;
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
    log_file("quest/fengyi5", sprintf(HIY"�з�����5Quest��¼��%s(%s)"HIW"��ս"HIY"��%d���������ʧ�ܡ�����%d��"NOR, me->name(1),me->query("id"), (int)me->query_temp("quest/huashan/fy5/killer_killed")+1,me->query("combat_exp")) );
                me->set("jing",100);
                me->set("jingli",100);
                me->set("quest/hsjf/fy5/exp",me->query("combat_exp"));
                me->set("quest/hsjf/fy5/time",time());
                me->add("quest/hsjf/fy5/kill_killer_fail",1);
                me->set("quest/hsjf/fy5/yanlian","again");
                me->delete_temp("quest/huashan/fy5");
          if(!random(3)) tell_room(environment(ob), HIB"\n"+ob->name()+"����һ����ת��������Ͳ����ˡ�\n"NOR);
        else tell_room(environment(ob), HIB"\n"+ob->name()+"��������"+me->name()+"һ�۵��������ֱ��¾Ͳ�Ҫ�ٳ�������������!��\n"NOR);
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
   me = find_player(ob->query("fy5_id"));
	if(!me) return;
    log_file("quest/fengyi5", sprintf(HIY"�з�����5Quest��¼��%s(%s)"HIW"��ս"HIY"��%d���������ʧ�ܡ�����%d��"NOR, me->name(1),me->query("id"), (int)me->query_temp("quest/huashan/fy5/killer_killed")+1,me->query("combat_exp")) );
    me->set("quest/hsjf/fy5/exp",me->query("combat_exp"));
    me->set("quest/hsjf/fy5/time",time());
    me->add("quest/hsjf/fy5/kill_killer_fail",1);
    me->set("quest/hsjf/fy5/yanlian","again");
    me->delete_temp("quest/huashan/fy5");
        if(!random(3)) tell_room(environment(ob), HIB"\n"+ob->name()+"����һ����ת��������Ͳ����ˡ�\n"NOR);
        else tell_room(environment(ob), HIB"\n"+ob->name()+"��������"+me->name()+"һ�۵��������ֱ��¾Ͳ�Ҫ�ٳ�������������!��\n"NOR);
	destruct(ob);
}

void dest(object ob)
{
  if(!ob) return;
  tell_room(environment(ob), HIR+"\n"+ob->name()+"����һ����ת��������Ͳ����ˡ�\n"NOR);
	destruct(ob);
}

void die()
{
    object killer,ob,newob;
    mapping name;

    name = RNAME_D->get_random_name(random(3));

    ob = this_object();
    if(!objectp(killer = query_temp("last_damage_from"))){
        ::die();
        return;
    }

    if(!killer->query("quest/hsjf/fy5/meet_killers")){
        ::die();
        return;
    }

    if(!killer->query_condition("fy5_killers")&&(int)killer->query_temp("quest/huashan/fy5/killer_killed")>3){
        if(ob->query("fengyi5_boss")){
            tell_object(killer,HIM"��ֻ����"+ob->query("name")+"ʹ�û�ɽ���������ޱȣ���ʱ�����뵽��ʯ���ϵĽ��С�\n"+
            HIG+"ͻȻ�������������ٴδ�Ħ�£���������µķ��֣�\n"NOR);
            killer->delete("quest/hsjf/fy5/meet_killers");
            killer->delete("quest/hsjf/fy5/location");
            killer->set("quest/hsjf/fy5/chuaimo",1);
            killer->set("quest/hsjf/fy5/exp",killer->query("combat_exp"));
            killer->set("quest/hsjf/fy5/time",time());
            killer->set("quest/hsjf/fy5/kill_killer_pass",1);
            killer->set("quest/hsjf/fy5/yanlian","pass");
            killer->delete_temp("quest/huashan/fy5");
            log_file("quest/fengyi5", sprintf(HIG"�з�����5Quest��¼��%s(%s)"HIW"�ɹ�"HIG"��ս�������BOSS������%d��"NOR, killer->name(1),killer->query("id"),killer->query("combat_exp")) );
            ::die();
            return;
        }
    message_vision(HIW"\n��������������ͻȻ����һ����Ц������"+RANK_D->query_rude(killer) +"���书��������ϧ��Ҫȥ�������ˣ���\n"NOR,ob,killer);
    newob = new(__DIR__"fy5_npc");
    newob->set("party","hs");
    newob->set("fengyi5_boss",1);
    newob->set_name(name["name"], name["id"]);
    newob->set_name(newob->query("name"), ({ newob->query("id"),"killer"}));
    newob->move(environment(killer));
    killer->add_temp("quest/huashan/fy5/killer_killed",1);
    log_file("quest/fengyi5", sprintf(HIC"�з�����5Quest��¼��%s(%s)"HIW"���"HIC"��ս�������BOSS���ᡣ����%d��"NOR, killer->name(1),killer->query("id"),killer->query("combat_exp")) );
    destruct(ob);
    return;
    }

    message_vision(HIY"\nͻȻ�ִڳ�һ��"HIB"�������"HIY"����$N"HIY"�е������ߣ����ҳ��ˣ���������ѵ��ѵ���"+RANK_D->query_rude(killer) +"��\n"NOR,ob,killer);
    message_vision(HIR"$N"HIR"����:���ֵ�С�ģ����"+RANK_D->query_rude(killer) +"���ֲ�������˵���ת�������䲻���ˡ���\n\n"NOR,ob,killer);
    newob = new(__DIR__"fy5_npc");
    newob->move(environment(killer));
    killer->add_temp("quest/huashan/fy5/killer_killed",1);
    destruct(ob);
    return;
}
