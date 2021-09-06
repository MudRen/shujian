// qqchi.c ��ǧ��
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_dan();
string ask_quest();
void create()
{
	set_name("��ǧ��", ({ "qiu qianchi", "qiu", "qianchi"}));
	set("nickname", HIY"��������"NOR);
	set("title",HIW"�����Ů����"NOR);
	set("long","һ����������ͺͷ������ϥ���ڵ��£�����ŭ�ݣ���Ȼ������\n"); 
	set("gender", "Ů��");
	set("age", 55);
	set("attitude", "friendly");

	set("unique", 1);
	set("shen_type", -20);

	set("str", 35);
	set("int", 30);
	set("con", 28);
	set("dex", 5);
	set("per", 8);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("eff_jingli",20000);
	set("jiali", 200);
	set("combat_exp", 7000000);
	set("score", 20000);

	set_skill("force", 130);
	set_skill("guiyuan-tunafa", 350);
	set_skill("dodge", 130);
	set_skill("shuishangpiao", 350);
	set_skill("strike", 350);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 350);
	set_skill("literate", 100);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	set("inquiry", ([ 
		"���鵤" : (: ask_dan :),
		"����ֹ" : (: ask_quest :)
	]));
	setup();
}

void kill_ob(object who)
{
	object me;
	object weapon;
	object ob;
	me=this_player();
	weapon = me->query_temp("weapon");
	ob=this_object();
	if (living(ob)) {
		command("sneer " + me->query("id"));
		if( weapon ){
			message_vision(HIW"$NͻȻ����һ�������зɳ�һ�� ���һ�죬����$n�������յ���"+weapon->query("unit")+weapon->name()+HIW"�ϡ�\n"NOR,ob,me);
			weapon->move(environment(ob));
			me->add_busy(2);
			message_vision(HIR"\n$Nֻ���ֱ۾�����ָ��Ȼ����ס������һ����"+weapon->name()+HIR"���ڵ��¡�\n"NOR,me);
		}
		else {
			message_vision(HIW"$N������˶��Ѽ���������ƿ�֮�������Х��ֱָ$nС����ȥ�Ƶ����Ǻ������ס�\n"NOR,ob,me);
			me->add_busy(2);
			message_vision(HIR"\n$N��������һ���߽У�����������������ȥ��\n"NOR,me);
			me->receive_damage("qi", me->query("eff_qi")/2);
			me->receive_wound("qi",  me->query("eff_qi") /2);
		}
	}
	::kill_ob(me);
}

string ask_dan()
{
	if(this_player()->query_temp("jqg/chi"))
		return "��λ"+RANK_D->query_respect(this_player())+"���Ҳ����Ѿ������㣬���鵤����֮����ô��";
	this_player()->set_temp("jqd/chi", 1);
		return "�����ڴ�����������Ե�������Ψһһ�ž��鵤�Ҳ��ڴ����������ש�¡�";
}

string ask_quest()
{
	object me = this_player();

	if(me->query_temp("quest/jindao"))
		return "��λ"+RANK_D->query_respect(this_player())+"���㻹��ȥ����ֹ���ұ������ǲ��ǲ����ַ����ˣ�";
		
  if( me->query("combat_exp") < 2000000 )
        	return "���㵱ǰ�ľ�����»��������ұ��𣬻���ץ��ȥ����ȥ�ɡ�\n";
 
	me->set_temp("quest/jindaoheijian/jueqingdan", 1);
		return "�ߣ���������ҵ���˵ز�����ɱ��������ǧ���Ĳ�Ϊ�ˣ�������ܽ����鵤�������Ҿͽ�������һ�����ܡ�";
}

int accept_object(object me, object ob)
{
	if( ob->query("id") == "jueqing dan" ) {
			command("sneer");
			tell_object(me,"20��ǰ�Ҵ����ǧ�ɱ����غ����ˣ�\n");
			tell_object(me,"������ܰ���ȥɱ�˻��صĻ���hehe��\n");
			call_out("destructing", 1, ob); 
			me->set_temp("quest/jindaoheijian/jueqingdan",0);
			me->set_temp("quest/jindaoheijian/huangrong",1);
			return 1;
		  }
		else {
			command("say ��Ȼ�üپ��鵤��ƭ��,������");
			me->fight_ob(this_object());
			this_object()->kill_ob(me);
			me->set_temp("quest/jindaoheijian/jueqingdan",0);
			call_out("destructing", 1, ob); 
			return 1;
		     }
	return 1;
}
void destructing(object ob)
{
	if (ob) destruct(ob);
}