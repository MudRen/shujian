// jiading.c �Ҷ�
// tangfeng@SJ

//��һʹ��skills_pfm.h����лCampsun@SJ

//inherit NPC;
inherit FIGHTER;
#include <ansi.h>
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

//string *str_menpai = ({ "wd","hs","gm","gb","tz","mj","thd","kl"});       
//#include "/d/city/npc/skills_pfm.h";
void create()
{
	set_name("�Ҷ�", ({ "jia ding", "jiading", "jia", "ding" }));
	set("long", "һ����ʮ����ļҶ�����ò����ʮ�����͡�\n");
	set("gender", "����");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen", -100);

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 500);
	set("max_jing", 5000);
	set("eff_jingli",4000);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 20);
	set("combat_exp", 3000+random(500));

	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	set("inquiry", ([
		"ؤ��" : "ؤ�������µ�һ��\n",
		"����" : "�������ࡣ\n",
	]));
	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("cloth"))->wear();

}
void init()
{
    object me, ob;  
    string good_skills;
    int i;     
    ::init();
    ob = this_object();
    me = this_player();
	if(environment(me)!=environment(ob)) return;
	if(!me->query_temp(QUESTDIR3+"start")) return;
    if(!me->query(QUESTDIR3+"start")) return;
    if(me->query(QUESTDIR3+"over")) return;
    if(me->query_temp(QUESTDIR3+"kill")) return;
	if(me->query_condition("killer")) return;
    if(ob->query("setok")) return;
	i=me->query("max_pot");
	if(i<350) i=350;
	i=i-100;	 
    ob->set("setok",1);
	ob->set("kill_id",me->query("id"));
   	ob->set("party",str_menpai[random(sizeof(str_menpai))]);     
	ob->copy_menpai(({ob->query("party")}),1,random(2),50+random(50));	//����npc�������书��							
	ob->copy_state();				//�������ɸ���npc ��һЩ״̬
    ob->set_skills_level(i-random(100)+random(50));
	ob->set("max_neili",me->query("max_neili"));
  	ob->set("max_jingli",me->query("max_jingli"));
    ob->set("max_qi",me->query("max_qi")*(1+random(3))/3);
  	ob->set("max_jing",me->query("max_jing"));
    
	ob->set("neili",query("max_neili")*3/2);
	ob->set("jingli",query("max_jingli")*3/2);
	ob->set("eff_jingli",query("max_jingli")*3/2);
	ob->set("qi",query("max_qi"));
	ob->set("eff_qi",query("max_qi"));
	ob->set("jing",query("max_jing")*3/2);
	ob->set("eff_jing",query("max_jing")*3/2);

	if (ob->query("f_skill2")) 
		good_skills=to_chinese(ob->query("f_skill"))+"��"+to_chinese(ob->query("f_skill2"));
	else	
		good_skills=to_chinese(ob->query("f_skill"));

   	ob->set("long",
       	 	"\n���˾�Ȼ��"HIW+ob->query("family/family_name")+NOR"�ĸ��֣���֪��Ϊ���ڴ��������ա�\n"
       	 	"С�����ĳ��������ǣ�"HIC+good_skills+NOR"��\n"
       	 	);
    ob->set("jiali",50+random(100));
    ob->set("combat_exp",me->query("combat_exp"));
	ob->set_skill("literate",ob->query("int")*10); 	 											//full literate
	ob->set_skill("wuxing-zhen",ob->query("int")*10); 	 									
	remove_call_out("zhen");
	call_out("zhen",2,ob);
	remove_call_out("do_kill");
	call_out("do_kill",6, me);
}
void zhen(object ob) 
{
   if( !ob ) return;                   
   command("lineup with guan jia");
   command("lineup with jia ding");
   command("lineup form wuxing-zhen");   
   command("lineup with guan jia");
   command("lineup with jia ding");
   call_out("zhen",1,ob);
}
int do_kill(object me)
{
	object ob = this_object();
	string good_skills;
	if(!me) return 0;
	if(!me->query_condition("killer") && me->query_temp(QUESTDIR3+"start") && me->query(QUESTDIR3+"start") && !me->query(QUESTDIR3+"over") && !me->query_temp(QUESTDIR3+"kill"))
	{
		if (ob->query("f_skill2")) 
			good_skills=to_chinese(ob->query("f_skill"))+"��"+to_chinese(ob->query("f_skill2"));
		else	
			good_skills=to_chinese(ob->query("f_skill"));
		if(random(2)) message_vision(HIG"$NͻȻ��ɫһ�䣬��������������ֻ���ó��汾�����ˣ���$n����һ������һﾹȻ��"+ob->query("family/family_name")+"�ĸ��֣�\n"NOR,ob,me);
		else message_vision(HIY"\n$N�����شӽ��������˳�������Цһ����������֪��ߵغ񣬿��ҵľ���"+good_skills+"����"NOR,ob);
		log_file("quest/TLBB", sprintf("%s��¼��%s(%s)��׼��������ׯ������%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
		remove_call_out("checking");
		call_out("checking", 2, me, ob);
	}
	::do_kill(me);
}

//��飬quest���̲���������
int checking(object me, object ob)
{
	int ret =  ::checking(me,ob);
	//me=this_palyer(),ob=this_object()
	if(!ret) return 0;
	if(!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0  ){
		remove_call_out("checking");
		if(me->query(QUESTDIR3+"start")) 
			tell_object(me,HIB"\n����߾���ׯ������ʧ�ܡ�\n"NOR);
		me->delete(QUESTDIR3+"start");
		me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
		me->delete_temp("quest/�����˲�");   
		me->set("quest/�����˲�/time",time());
		me->set("quest/�����˲�/combat_exp",me->query("combat_exp"));
		me->set("qi",100);			
		me->set("jing",100);
		me->set("jingli",100);
		tell_room(environment(ob), HIB"\n"+ob->name()+"����һ������㱾��Ҳ�Ҵ��Ҿ���ׯ��\n"NOR);
		if(environment(ob)== environment(me))
		{
			tell_room(environment(me), HIY"\n"+me->name()+"��"+ob->name()+"һ�����˳�ȥ��\n"NOR); 
			me->move("/d/xiangyang/damen");
			tell_room(environment(me), HIY"\n����һ����������������ԭ����"+me->name()+"��"+ob->name()+"һ���ߵ����ſڡ�\n"NOR);
		}
		log_file("quest/TLBB", sprintf("%s��¼��%s(%s)������ׯʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
		ob->delete("setok");
		ob->remove_all_killer();
		me->remove_all_killer();
		return 1;
	}
	if(!me || environment(ob)!= environment(me)||me->query("eff_qi")<me->query("max_qi")/15||me->query("qi")<me->query("max_qi")/20){
		remove_call_out("checking");
		remove_call_out("do_lost");
		call_out("do_lost",0);
		return 1;
	}
	if(!ob->query("setok")) 
	{
		remove_call_out("checking");
		return 1;
	}
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
   if(!me->is_fighting(ob))
   {
	   remove_call_out("do_kill");  
	   call_out("do_kill",1,me);
   }
}
void do_lost()
{
	object ob,me;
	ob = this_object();
	me = find_player(ob->query("kill_id"));   
	ob->remove_all_killer();
	ob->delete("setok");
	if(!me) return;
	me->delete(QUESTDIR3+"start");
	me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
	me->delete_temp("quest/�����˲�");   
	me->set("quest/�����˲�/time",time());
	me->set("quest/�����˲�/combat_exp",me->query("combat_exp"));
	tell_room(environment(ob), HIB"\n"+ob->name()+"����һ������㱾��Ҳ�Ҵ��Ҿ���ׯ��\n"NOR);
	if(environment(ob)== environment(me)){
		tell_room(environment(me), HIY"\n"+me->name()+"��"+ob->name()+"һ�����˳�ȥ��\n"NOR);
		me->move("/d/xiangyang/damen");
		tell_room(environment(me), HIY"\n����һ����������������ԭ����"+me->name()+"��"+ob->name()+"һ���ߵ����ſڡ�\n"NOR);
	}
	log_file("quest/TLBB", sprintf("%s��¼��%s(%s)��������ƪ����ׯʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
	me->remove_all_killer();
}
